#include <QTableView>
#include <QDebug>
#include <QObject>
#include <QLineEdit>
#include <QRegExp>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QScrollBar>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QProgressDialog>
#include <QFont>
#include <QHeaderView>
#include <QHBoxLayout>

#include "contactwidget.h"
#include "ui_contactwidget.h"
#include "searchlineedit.h"
#include "../classes/models/contactmodel.h"

#include "global.h"
Contactwidget::Contactwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contactwidget)
{
    ui->setupUi(this);
    QApplication::processEvents();
    m_conImportThread=NULL;
    m_getContactObject=NULL;
    m_detailWidget=ui->detailWidget;
    m_tableView=ui->tableView;

    m_tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // m_contactModel= new Contactmodel;
    m_sortProxyModel =new ContactSortProxyModel;
    m_sortProxyModel->setSourceModel(g_contactModel);
    m_tableView->setModel(m_sortProxyModel);
    initUI();
    createConnect();

    //目前在构造函数中初始化的数据，实际中不是在这初始化的。
    //理由是我们在开始是只有UI界面，当点击以后才能初始化数据。
    //  iniData();

    qDebug()<<m_tableView->verticalScrollBar()->value();//0
    qDebug()<<m_tableView->verticalScrollBar()->maximum();//
    m_tableView->verticalScrollBar()->setSliderPosition(0);


    m_tableView->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    m_tableView->setColumnWidth(0,50);
    m_tableView->setColumnWidth(1,70);
    m_tableView->setColumnWidth(2,120);
    m_tableView->setColumnWidth(3,130);
    m_tableView->setColumnWidth(4,100);
    //自适应文件内容进行調整
    // m_tableView->resizeRowsToContents();
    //tableView设置默认行高
    m_tableView->verticalHeader()->setDefaultSectionSize(60);


    qRegisterMetaType<Contact>("Contact");

    getcontact = false ;
}
Contactwidget::~Contactwidget()
{
    delete ui;
}

/*函数名：initUI()
 *参数：无
 *作用：界面的初始化和布局的设置
 **/
void Contactwidget::initUI()
{
    m_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableView->setShowGrid(false);
    m_tableView->horizontalHeader()->setStretchLastSection(true);
    m_tableView->horizontalHeader()->setSortIndicatorShown(false);
    //m_tableView->horizontalHeader()->setSectionsClickable(false);
    m_tableView->verticalHeader()->setVisible(false);
    m_tableView->horizontalHeader()->setVisible(false);
    m_tableView->setColumnWidth(0,35);
    m_tableView->resizeColumnsToContents();
    m_tableView->resizeRowsToContents();
    m_tableView->setAlternatingRowColors(true);
    m_tableView->setStyleSheet(" QTableView::item:selected {background-color:rgb(228,217,206);}  ");

    m_tableView ->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {border-right:1px solid grey;""width: 4px;}"
                                                     " QScrollBar::handle:vertical {background-color: (189,187,187);height: 10px; min-height: 40px;}"
                                                     " QScrollBar::add-line:vertical { height: 0px; }"
                                                     " QScrollBar::sub-line:vertical { height: 0px; }"
                                                     "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background-color:rgb(255,255,255);}"
                                                     "QScrollBar::up-arrow:vertical { subcontrol-origin: margin; background-color: transparent; height:0px}"
                                                     "QScrollBar::down-arrow:vertical { background-color: transparent; }"
                                                     );


    //this->setLayout(ui->formLayout);
    m_searchLineEdit =new SearchlineEdit;
    m_searchLineEdit->setFixedWidth(400);
    m_searchLineEdit->setFixedHeight(40);
    m_searchLineEdit->addRefshButton();
    QHBoxLayout * _h=new QHBoxLayout;
    _h->addWidget(m_searchLineEdit,0,Qt::AlignLeft);
    _h->addSpacing(0);
    _h->setContentsMargins(20,0,50,0);
    _h->setMargin(0);
    ui->widget_2->setLayout(_h);

    ui->editLableIcon->setPixmap(QPixmap(":/contact/images/contactImages/edit.png"));
    ui->editButton->setFlat(true);
    ui->editButton->setFocusPolicy(Qt::NoFocus);
    m_contactDialog =NULL;
    mainVLayout=NULL;

}
/*函数名：createConnect()
 *参数：无
 *作用：建立信号槽的链接
 */
void Contactwidget::createConnect()
{
    connect(m_searchLineEdit->getLineEdit(),SIGNAL(textChanged(const QString &)),this,SLOT(searchfilter( const QString &)));
    // connect(m_searchLineEdit->getSearchButton(),SIGNAL(clicked()),this,SLOT(filter()));
    connect(m_searchLineEdit->getRefrshButton(),SIGNAL(clicked()),this,SLOT(refreshUI()));
    connect(m_tableView,SIGNAL(clicked(QModelIndex)),this,SLOT(showDetailedInfo(QModelIndex )));

    connect(ui->newCreatButton,SIGNAL(clicked()),this,SLOT( creatContactSlot()));
    connect(ui->importButton,SIGNAL(clicked()),this,SLOT(importContactSlot()));
    connect(ui->exportButton,SIGNAL(clicked()),this,SLOT(exportContactSlot()));
    connect(ui->deleteButton,SIGNAL(clicked()),this,SLOT(deleteContactSlot()));
    connect(ui->editButton,SIGNAL(clicked()),this,SLOT(editContactSlot()));
    connect(ui->allCheckBox,SIGNAL(clicked()),this,SLOT(selectAllRowOrNOSlot()));

    connect(g_contactModel,SIGNAL(checkboxChanged()),this,SLOT(checkBoxChangeState()));
    connect(g_contactModel,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(forShowSelectedRow(QModelIndex,QModelIndex)));
    connect(g_contactModel,SIGNAL(checkboxChanged()),this,SLOT(forShowSelectedRow()));
    createButtonConnect();
}
/*函数名：createButtonConnect()
 *参数：无
 *返回类型：无
 *作用：建立多个button的连接，使用QSignalMapper,使他们有形同的槽函数。
 *不足，如果是在函数内部创建button,这样的话，就不会看起来这样长了。
 **/
void Contactwidget::createButtonConnect()
{
    m_signalMapper=new QSignalMapper;
    connect(ui->pushButton_A,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_B,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_C,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_D,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_E,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_F,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_G,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_H,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_I,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_J,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_K,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_L,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_M,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_N,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_O,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_P,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_Q,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_R,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_S,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_T,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_U,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_V,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_W,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_X,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_Y,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_Z,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    connect(ui->pushButton_end,SIGNAL(clicked()),m_signalMapper,SLOT(map()));
    m_signalMapper->setMapping(ui->pushButton_A,ui->pushButton_A->text());
    m_signalMapper->setMapping(ui->pushButton_B,ui->pushButton_B->text());
    m_signalMapper->setMapping(ui->pushButton_C,ui->pushButton_C->text());
    m_signalMapper->setMapping(ui->pushButton_D,ui->pushButton_D->text());
    m_signalMapper->setMapping(ui->pushButton_E,ui->pushButton_E->text());
    m_signalMapper->setMapping(ui->pushButton_F,ui->pushButton_F->text());
    m_signalMapper->setMapping(ui->pushButton_G,ui->pushButton_G->text());
    m_signalMapper->setMapping(ui->pushButton_H,ui->pushButton_H->text());
    m_signalMapper->setMapping(ui->pushButton_I,ui->pushButton_I->text());
    m_signalMapper->setMapping(ui->pushButton_J,ui->pushButton_J->text());
    m_signalMapper->setMapping(ui->pushButton_K,ui->pushButton_K->text());
    m_signalMapper->setMapping(ui->pushButton_L,ui->pushButton_L->text());
    m_signalMapper->setMapping(ui->pushButton_M,ui->pushButton_M->text());
    m_signalMapper->setMapping(ui->pushButton_N,ui->pushButton_N->text());
    m_signalMapper->setMapping(ui->pushButton_O,ui->pushButton_O->text());
    m_signalMapper->setMapping(ui->pushButton_P,ui->pushButton_P->text());
    m_signalMapper->setMapping(ui->pushButton_Q,ui->pushButton_Q->text());
    m_signalMapper->setMapping(ui->pushButton_R,ui->pushButton_R->text());
    m_signalMapper->setMapping(ui->pushButton_S,ui->pushButton_S->text());
    m_signalMapper->setMapping(ui->pushButton_T,ui->pushButton_T->text());
    m_signalMapper->setMapping(ui->pushButton_U,ui->pushButton_U->text());
    m_signalMapper->setMapping(ui->pushButton_V,ui->pushButton_V->text());
    m_signalMapper->setMapping(ui->pushButton_W,ui->pushButton_W->text());
    m_signalMapper->setMapping(ui->pushButton_X,ui->pushButton_X->text());
    m_signalMapper->setMapping(ui->pushButton_Y,ui->pushButton_Y->text());
    m_signalMapper->setMapping(ui->pushButton_Z,ui->pushButton_Z->text());
    m_signalMapper->setMapping(ui->pushButton_end,"#");

    connect(m_signalMapper,SIGNAL(mapped(QString)),this,SLOT(buttonsSlot(QString)));


}

/*函数名：buttonsSlot();
 *参数：QString _alphabetStr 字母表的字母
 *作用：查找当前字母_alphabetStr，在model中首次出现的行号，
 *并将该行号显示在可视窗口中。
 **/
void Contactwidget::buttonsSlot(QString _alphabetStr)
{
    int _curRow=0;
    if(_alphabetStr== "#")
    {
        //        qDebug()<<"hello";
        //        qDebug()<<"min"<<m_tableView->verticalScrollBar()->minimum();
        //        qDebug()<<"max"<<m_tableView->verticalScrollBar()->maximum();
        _curRow=m_tableView->verticalScrollBar()->minimum();
    }
    else
    {
        _curRow=g_contactModel->findTheFirstRow(* (_alphabetStr.toStdString().c_str()));
    }
    //    qDebug()<<"row"<<_curRow;
    if(_curRow != -1)
    {
        m_tableView->verticalScrollBar()->setValue(_curRow);
    }
}

/*函数名：iniData()
 *参数： 无
 *作用：初始化必要数据
 **/
void Contactwidget::iniData()
{
    //    v->setFrameShape(QFrame::NoFrame);
    //    v->setFocusPolicy(Qt::NoFocus);
    //    v->setShowGrid(false);
    Contact _con(QString("1"),QString("ww"),QString("1593024"),QString("Fm"),"C");
    g_contactModel->insertContact(0,_con);

    QList<Contact> _tmpConList;
    Contact _con1(QString("1"),QString("wu"),QString("1234"),QString("Fm"));
    _tmpConList.push_back(_con1);
    Contact _con2(QString("1"),QString("yang"),QString("3456"),QString("Fm"));
    _tmpConList.push_back(_con2);
    Contact _con3(QString("1"),QString("ru"),QString("7wrasf89"),QString("Fm"));
    _tmpConList.push_back(_con3);
    Contact _con4(QString("1"),QString("ru"),QString("789"),QString("Fm"));
    _tmpConList.push_back(_con4);
    Contact _con5(QString("1"),QString("ru"),QString("7n,.89"),QString("Fm"));
    _tmpConList.push_back(_con5);
    Contact _con6(QString("1"),QString("ru"),QString("7n89"),QString("Fm"));
    _tmpConList.push_back(_con6);
    Contact _con7(QString("1"),QString("ru"),QString("7z89"),QString("Fm"));
    _tmpConList.push_back(_con7);
    Contact _con8(QString("1"),QString("ru"),QString("7zx89"),QString("Fm"));
    _tmpConList.push_back(_con8);
    Contact _con9(QString("1"),QString("ru"),QString("7ktd89"),QString("Fm"));
    _tmpConList.push_back(_con9);
    Contact _con10(QString("1"),QString("ru"),QString("7kkkkkkkk89"),QString("Fm"));
    _tmpConList.push_back(_con10);
    Contact _con11(QString("1"),QString("ru"),QString("7hhh89"),QString("Fm"));
    _tmpConList.push_back(_con11);
    Contact _con112(QString("1"),QString("ru"),QString("v"),QString("Fm"));
    _tmpConList.push_back(_con112);
    Contact _con23(QString("1"),QString("ru"),QString("78vv9"),QString("Fm"));
    _tmpConList.push_back(_con23);
    Contact _con33(QString("1"),QString("ru"),QString("78ww9"),QString("Fm"));
    _tmpConList.push_back(_con33);
    Contact _con333(QString("1"),QString("ru"),QString("7er89"),QString("Fm"));
    _tmpConList.push_back(_con333);
    Contact _con311(QString("1"),QString("ru"),QString("7re89"),QString("Fm"));
    _tmpConList.push_back(_con311);
    Contact _con322(QString("1"),QString("ru"),QString("7809"),QString("Fm"));
    _tmpConList.push_back(_con322);
    Contact _con344(QString("1"),QString("ru"),QString("7089"),QString("Fm"),"C");
    _tmpConList.push_back(_con344);
    Contact _con390(QString("1"),QString("ru"),QString("709"),QString("Fm"));
    _tmpConList.push_back(_con390);
    //插入联系人
    g_contactModel->insertContacts(0,_tmpConList);
}

/*函数名：addContactData(const Contact& _tmpCon)
 *参数： const Contact& _tmpCon 联系人的信息
 *函数作用：插入数据到数据Model中。
 **/
void Contactwidget::addContactData(const Contact& _tmpCon)
{
    g_contactModel->insertContact(0,_tmpCon);
}

/**
*@函数概要：搜索
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*@Time:2015.10.13 11:00
*/
void Contactwidget::filter()
{
    if(m_searchLineEdit->getLineEditText().isEmpty())
    {
        QMessageBox::information(this,"提示","过滤条件不能为空.","确定");
        return;
    }
    else
    {
        searchfilter(m_searchLineEdit->getLineEditText());
    }
}

/*函数名：void searchfilter(QString & pattern)。
 *参数：QString & patterrn 过滤的关键字。
 *作用：通过信号槽，对model内部的值进行过滤，显示含有关键字的内容。
 **/
void Contactwidget::searchfilter(const QString & pattern)
{
    m_sortProxyModel->setFilterKeyColumn(-1);
    QRegExp _regExp(pattern,Qt::CaseInsensitive,QRegExp::Wildcard);
    m_sortProxyModel->setFilterRegExp(_regExp);
    //m_tableView->resizeColumnsToContents();
    //m_tableView->resizeRowsToContents();
}

/*函数名：refreshUI
 *参数：无
 *作用：清空model数据,重新获取联系人数据
 **/
void Contactwidget::refreshUI()
{
    getcontact = true;

    g_contactModel->clear();
    //获取联系人的信息
    //    if(m_getContactObject!=NULL)
    //    {
    //        delete m_getContactObject;
    //        m_getContactObject=NULL;
    //    }

    m_getContactObject=new ContactObject();
    QThread * thread=new QThread;
    m_getContactObject->moveToThread(thread);
    connect(thread,SIGNAL(started()),m_getContactObject,SLOT(socketStart()));
    connect(m_getContactObject,SIGNAL(sendContactSignal(Contact)),this,SLOT(addModel(Contact)));
    thread->start();
}




/*函数名：showDetailedInfo()
 *参数：QModelIndex
 *功能：点击tableview，显示当前的详细信息
 **/
void Contactwidget::showDetailedInfo(QModelIndex  _index)
{
    if(!_index.isValid())
    {
        return;
    }
    qDebug()<<g_contactModel->getContactInfo(_index).getName();
    creatorDetailWidgte(g_contactModel->getContactInfo(_index));

    //当前选中的联系人信息
    m_curContact=g_contactModel->getContactInfo(_index);
}

/*函数名：creatContactSlot()
 *参数：无
 *功能：创建对框，新建联系人必要信息，
 *并保存在g_contactModel中，并在列表中显示。
 **/
void Contactwidget::creatContactSlot()
{

    //    QDialog *_dialog= new QDialog;
    //    _dialog->show();
    if(m_contactDialog==NULL)
    {
        m_contactDialog  =new ContactDialog(this);
        m_contactDialog->show();
    }
    else if(m_contactDialog!=NULL)
    {
        delete m_contactDialog;
        m_contactDialog=NULL;
        m_contactDialog  =new ContactDialog(this);
        m_contactDialog->show();
    }

    connect(m_contactDialog->getSaveButtonPtr(),SIGNAL(clicked()),this,SLOT(saveCreateContactSlot()));
    connect(m_contactDialog->getCancelButtonPtr(),SIGNAL(clicked()),this,SLOT(cancelContactDialogSlot()));

}

/*函数名：saveContactSlot()
 *作用： 新建联系人 ,并把数据传送到 phone端，
 *如果phone端反馈这个联系人信息，则保存到model中，反之则提示信息失败。
 *Attention:手机端反馈的信息 id 字母表字符 ,
 *反馈的字符串可以是这种形式:  id:字母表字符\n;
 **/
void Contactwidget::saveCreateContactSlot()
{
    qDebug()<<"saveCreateContactSlot";
    QString mesg("CONTACT:ADD:");

    QString name=m_contactDialog->getName();
    if(name.isNull() || name.isEmpty())
    {
        //警告信息
        QMessageBox::warning(0,"警告","联系人名字不能为空","确定");
        return ;
    }

    QString phoneStr;
    QStringList phoneList=m_contactDialog->getPhoneNums();
    if(phoneList.count() < 0)
    {
        QMessageBox::warning(0,"警告","联系人电话不能为空","确定");
        return ;
    }
    /**
*@注释:修改apk关键字段以后需要更改.
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
    foreach (QString var, phoneList)
    {
        phoneStr+=var;

        //phoneStr+="_";
    }
    QString mailStr;
    QStringList mailList=m_contactDialog->getMails();
    foreach (QString var, mailList)
    {
        mailStr+=var;
        mailStr+=":";
    }
    QString groupName=m_contactDialog->getGroup();

    mesg+=name;
    mesg+=":";
    mesg+=phoneStr;
    //    mesg+=":";
    //    mesg+=mailStr;
    //    mesg+=":";
    //    mesg+=groupName;
    mesg+=":::";
    mesg+="\n";
    qDebug()<<"sendMess:"<<mesg;
    //建立通讯发送联系人信息
    QTcpSocket *tcpsocket=new QTcpSocket;
    tcpsocket->connectToHost(g_ip,g_port,QTcpSocket::ReadWrite);
    if(tcpsocket->waitForConnected())
    {
        tcpsocket->write(mesg.toStdString().c_str(),strlen(mesg.toStdString().c_str()));
        tcpsocket->waitForBytesWritten();
    }

    if(tcpsocket->waitForReadyRead(2000))
    {
        QString readData = QString::fromUtf8(tcpsocket->readAll());
        qDebug()<<"addContact reback Infos:"<<readData;
        readData=readData.trimmed();
        //反馈信息只有联系人的ID,  另外还需要名字的首字母
        //查找位置
        QString _id=readData;
        Contact _contact;
        _contact.alphabetGroup='1';
        _contact.getId()=_id;
        _contact.name=name;
        _contact.number=phoneStr;

        if(groupName.isEmpty())
        {
            _contact.group="无";
        }
        _contact.group=groupName;

        int _pos=g_contactModel->findTheFirstRow(_contact.getAlphabetGroup());
        g_contactModel->insertContact(_pos,_contact);
        m_contactDialog->accept();
    }
    else
    {
        QMessageBox::information(this,"提示"," 新建联系人失败.","确定");
        return;
    }
    m_contactDialog->accept();
    tcpsocket->disconnectFromHost();
    delete tcpsocket;
    tcpsocket=NULL;


}

/*函数名：cancelContactDialogSlot()
 *作用：点击取消按钮的槽函数
 **/
void Contactwidget::cancelContactDialogSlot()
{
    m_contactDialog->accept();
}


/*函数名：importContactSlot()
 *参数：无
 *功能：1.创建线程，在线程中导入联系人信息到g_contactModel中，
 *并逐条显示。2.用模态对话框显示进导入进度。
 *且:导入的信息是中不包含头像,只包含文字信息.
 *目前导出信息只含有 联系人名字和电话,群组,首字母
 **/
void Contactwidget::importContactSlot()
{
    QFileDialog  * _filedialog=new QFileDialog(0,Qt::Widget);
    QString m_fileName ;
    m_fileName= _filedialog->getOpenFileName(this, tr("Open File"),
                                             ".", "*.csv");
    QString     _f(m_fileName);
    if(m_fileName.isEmpty())
    {
        return;
    }
    else
    {
        QFile f(m_fileName);
        if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<< "Open failed." ;
            return ;
        }

        QList<Contact> _tmpContactList;
        //从文本中读取联系人信息
        QTextStream txtInput(&f);
        QString lineStr;
        int lineNum=0;//行数
        while(!txtInput.atEnd())
        {
            lineStr = txtInput.readLine();
            int _numTmp=lineStr.count(',');

            /**
*@注释:目前只有三个导入信息,id,name,phoneNum,字母表
*后续会在导出的时候添加 分组和邮箱等信息.
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
            //  if(_numTmp == 4)//字符导出错误的容错处理
            {
                //分解
                int i=0;
                QString id,name,phoneNum;
                QString alpStr;
                QString groupName("无");
                i = lineStr.indexOf(",");
                id = lineStr.left(i);
                lineStr.remove(0,i+1);

                i = lineStr.indexOf(",");
                name = lineStr.left(i);
                lineStr.remove(0,i+1);

                i = lineStr.indexOf(",");
                phoneNum = lineStr.left(i);
                lineStr.remove(0,i+1);

                i = lineStr.indexOf(",");
                alpStr = lineStr.left(i);
                lineStr.remove(0,i+1);

                //i = lineStr.indexOf(",");
                //groupName = lineStr.left(i);
                // lineStr.remove(0,i+1);


                // i = lineStr.indexOf(",");
                // toa = lineStr.left(i);
                // lineStr.remove(0,i+1);

                // i = lineStr.indexOf(",");
                // body = lineStr;
                char * _ch=alpStr.toLatin1().data();

                Contact _contact(id,name,phoneNum,groupName,_ch);
                _tmpContactList.push_back(_contact);
                lineNum++;
            }
        }
        f.flush();
        f.close();

        //        //进度条
        //        QProgressDialog  pd("正在导入...","取消",0,lineNum,this);//
        //        pd.setWindowModality(Qt::WindowModal);
        //        pd.setMinimumDuration(1);
        //        pd.setFixedSize(500,80);
        //        pd.autoClose();
        //导入手机
        if (m_conImportThread!=NULL)
        {
            if(m_conImportThread->isRunning())
            {
                m_conImportThread->terminate();
            }
            delete m_conImportThread;
            m_conImportThread=NULL;
        }
        m_conImportThread=new ContactImportThread(_tmpContactList,this);
        QObject::connect(m_conImportThread,SIGNAL(contactImportFailure()),this,SLOT(importFailureSlot()));
        QObject::connect(m_conImportThread,SIGNAL(contactImportFinshed()),this,SLOT(refreshUI()));
        m_conImportThread->start();

    }

}

/*函数名：exportContactSlot
 *参数：无
 *功能：创建线程，显示导出进度。
 **/
//Attention: 联系人的ID信息也是必要的信息.
void Contactwidget::exportContactSlot()
{

    QString dir = QFileDialog::getSaveFileName(this, tr("Save FileName"),"./contactsBackup.csv",
                                               "csv(*csv)");
    if(dir.isEmpty())
        return;
    QFile f(dir);
    if(!f.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "Open failed." << endl;
        QMessageBox::information(0,"权限提示信息","该路径没有写权限\n,请选择合适的路径.",QString::fromLocal8Bit("关闭"));
        return ;
    }

    QTextStream txtOutput(&f);
    QList<Contact> _list=g_contactModel->getSeclectedContactS();
    QProgressDialog  pd("正在导出...","取消",0,_list.count(),this);//
    pd.setWindowModality(Qt::WindowModal);
    pd.setModal(true);
    pd.setMinimumDuration(1);
    pd.setFixedSize(500,80);
    pd.autoClose();

    QList<Contact>::iterator _it=_list.begin();
    int i=0;
    for(;_it != _list.end(); _it++)
    {
        txtOutput<<(*_it).getId()<<","<<((*_it).getName())<<","<<(*_it).getNumber()<<","<<QString((*_it).getAlphabetGroup());
        qDebug()<<"exportInfo:"<<(*_it).getName();
        i++;
        if(pd.wasCanceled())
        {
            break;
        }
        pd.setValue(i);
        txtOutput<<"\n";
    }
    f.close();

}

/*函数名：deleteContactSlot
 *参数：无
 *功能：删除g_contactModel中的数据，并在显示列表中删除显示信息。
 *其中total控制删除的次数，真正的删除在
 **/
void Contactwidget::deleteContactSlot()
{
    int _total=g_contactModel->getSeclectedCount();
    if(0 >=_total)
    {
        QMessageBox _box;
        _box.setFixedSize(100,200);
        _box.information(this,"提示","选择的列表为空.","关闭");
        _box.show();
    }

    //发送信息到手机
    QString mesg="CONTACT:DELETE:";
   // QList<int> selectedRowList= g_contactModel->getSelectedRow();
    QList<Contact> _contactList= g_contactModel->getSeclectedContactS();

//    for(int i=0; i < selectedRowList.count() ;++i )
//    {
//        mesg+=selectedRowList.at(i);
//    }
    for(int i=0; i<_contactList.count(); ++i )
    {
        mesg+=_contactList.at(i).getId();
        mesg+=":";
    }
    qDebug()<<_contactList.count()<<"deleteContactSlot:"<<mesg;
    mesg+="\n";

    QTcpSocket *tcpsocket=new QTcpSocket;
    tcpsocket->connectToHost(g_ip,g_port,QTcpSocket::ReadWrite);
    if(tcpsocket->waitForConnected())
    {
        tcpsocket->write(mesg.toStdString().c_str(),strlen(mesg.toStdString().c_str()));
        tcpsocket->waitForBytesWritten();
    }

    if(tcpsocket->waitForReadyRead())
    {
        QString readData = QString::fromUtf8(tcpsocket->readAll());
        QString result = readData.split("\n")[0];
        qDebug()<<"rebackInfo:"<<readData;
        if(result.contains("ContactDeleteSuccess"))
        {
            //删除model中的数据
            for(int i=0; i<_total;++i)
            {
                g_contactModel->removeContact(g_contactModel->getSelectedRow().takeLast());
            }
        }
        else if(result.contains("ContactDeleteFalse"))
        {

            QMessageBox::warning(0,"删除失败","无法删除联系人","确定");
            return ;
        }
    }
    tcpsocket->disconnectFromHost();
    delete tcpsocket;
    tcpsocket=NULL;
}

/*函数名：editContactSlot
 *参数：无
 *功能：编辑联系人信息，并保存到g_contactModel中，更新显示列表。
 **/
void Contactwidget::editContactSlot()
{
    //如果没有显示,则不编辑
    if(0 == g_contactModel->getContactsList().count())
    {
        QMessageBox::information(this,"提示:","没有联系人可编辑","确定");
        return;
    }

    //根据显示的字符串,创建对应的UI;
    if(m_contactDialog !=NULL)
    {
        delete m_contactDialog;
        m_contactDialog=NULL;
    }
    m_contactDialog= new ContactDialog;
    m_contactDialog->setDialogTitleName("编辑联系人");
    m_contactDialog->show();
    //根据联系人信息创建窗口
    if(m_curContact.getIcon().isNull()  )
    {
        //默认联系人的头像
        m_contactDialog->setimage();
        qDebug()<<"set default Icon here";
    }
    else
    {
        m_contactDialog->setimage(m_curContact.getIcon());
    }
    m_contactDialog->setName(m_curContact.getName());
    m_contactDialog->setPhone(m_curContact.getNumber());
    m_contactDialog->setmail(m_curContact.getMailName());
    m_contactDialog->setGroup(m_curContact.getGroup());



    connect(m_contactDialog->getSaveButtonPtr(),SIGNAL(clicked()),this,SLOT(saveEditContactSlot()));
    connect(m_contactDialog->getCancelButtonPtr(),SIGNAL(clicked()),this,SLOT(cancelContactDialogSlot()));



}

/*函数名：selectAllRowSlot
 *参数：无
 *功能：点击以后，列表中所有的行都选中状态/或者全不选。
 *改变g_contactModel数据中纪律checkBox的状态
 **/
void Contactwidget::selectAllRowOrNOSlot()
{
    g_contactModel->setAllCheckBoxState(ui->allCheckBox->checkState());
    g_contactModel->setCheckboxAllSelect();
    qDebug()<<g_contactModel->getSeclectedCount();
}

/*函数名：checkBoxChangeState
 *参数：无
 *作用：当取消列表中的checkBox的选中状态时，
 *全选按钮改变选中状态为为选中状态。
 **/
void Contactwidget::checkBoxChangeState()
{
    if(Qt::Checked== ui->allCheckBox->checkState())
    {
        ui->allCheckBox->setCheckState(Qt::Unchecked);
    }
}



void Contactwidget::forShowSelectedRow(QModelIndex,QModelIndex)
{
    QString _tmp(g_contactModel->getSeclectedCount());
    ui->selectedCountLabel->setText(QString("%1").arg(g_contactModel->getSeclectedCount()));

}
void Contactwidget::forShowSelectedRow()
{
    qDebug()<<"selected:"<<g_contactModel->getSeclectedCount();
    ui->selectedCountLabel->setText(QString("%1").arg(g_contactModel->getSeclectedCount()));
}

/*初步实现，需要细化
 *
 *函数名：creatorDetailWidgte
 *参数：const Contact & _tmpCon联系人信息
 *作用：根据联系人的信息，动态创建联系信息的窗体。
 *必须要的信息：联系人头像，联系人名字，联系人电话，可以是多个等
 **/
void Contactwidget::creatorDetailWidgte(const Contact & _tmpCon)
{
    qDebug()<<"id:"<<_tmpCon.getId();

    if(mainVLayout!=NULL)
    {
        delete mainVLayout;
        mainVLayout=NULL;
    }
    mainVLayout=new QVBoxLayout;
    m_detailWidget->setLayout(mainVLayout);
    mainVLayout->setContentsMargins(120,50,0,50);
    mainVLayout->setSpacing(0);

    //图片

    QLabel *iconLable=new QLabel();
    iconLable->setText(_tmpCon.getName());
    //  iconLable->setStyleSheet("QLabel{/*background-color: rgb(0, 255, 255);*/ color: #FFFFFF;  border-radius: 78.5px 78.5px 78.5px 78.5px; padding:44px 50px;}");
    iconLable->setFixedSize(100,100);
    //图片的放大缩小
    QPixmap pix(":/contact/images/contactImages/head_portrait.png");
    // QPixmap pix(_tmpCon.getIcon().pixmap(50,50));
    QPixmap newpix;
    newpix= pix.scaled(100,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    // newpix= pix.scaled(40,40,Qt::KeepAspectRatio);
    iconLable->setPixmap(newpix);
    mainVLayout->addWidget(iconLable);
    //名字

    QLabel * nameLable=new QLabel;
    QFont ft;
    ft.setPointSize(16);
    nameLable->setFont(ft);
    nameLable->setText(_tmpCon.getName());
    nameLable->setAlignment(Qt::AlignLeft);
    // nameLable->setStyleSheet("QLabel{background-color: rgb(0, 255, 255)}");
    //nameLable->setFixedSize(100,30);
    // mainVLayout->addWidget(nameLable);


    //电话
    QLabel * phoneLable=new QLabel;
    QFont ft2;
    ft.setPointSize(14);
    phoneLable->setFont(ft);
    phoneLable->setText(_tmpCon.getNumber());
    phoneLable->setAlignment(Qt::AlignLeft);
    //phoneLable->setFixedSize(100,30);
    //phoneLable->setStyleSheet("QLabel{background-color: rgb(0, 0, 255)}");
    //  mainVLayout->addWidget(phoneLable);

    m_vboxlayout=new QVBoxLayout;
    m_vboxlayout->addWidget(nameLable);
    m_vboxlayout->addWidget(phoneLable);
    m_vboxlayout->setContentsMargins(0,10,0,0);
    mainVLayout->addLayout(m_vboxlayout);



    //群组
    QFont ft3;
    ft3.setPointSize(12);
    QHBoxLayout * _fourHLayout=new QHBoxLayout;
    QLabel * grouplable=new QLabel("群组");
    grouplable->setFont(ft3);
    QLabel * contactGroupLabel=new QLabel();

    contactGroupLabel->setFont(ft3);
    contactGroupLabel->setText(_tmpCon.getGroup());
    // contactGroupLabel->setStyleSheet("QLabel{background-color: rgb(58, 0, 255)}");
    //grouplable->setStyleSheet("QLabel{background-color: rgb(250, 0, 255)}");
    grouplable->setFixedSize(100,30);
    contactGroupLabel->setFixedSize(100,30);
    _fourHLayout->addWidget(grouplable,Qt::AlignLeft);
    _fourHLayout->addWidget(contactGroupLabel);
    _fourHLayout->setSpacing(0);
    _fourHLayout->setMargin(0);
    QSpacerItem * _hspaceItem=new QSpacerItem(20,40,QSizePolicy::Expanding,QSizePolicy::Minimum);
    _fourHLayout->setContentsMargins(0,0,0,0);
    _fourHLayout->addSpacerItem(_hspaceItem);

    mainVLayout->addLayout(_fourHLayout);

    QSpacerItem * _spaceItem=new QSpacerItem(20,40,QSizePolicy::Minimum,QSizePolicy::Expanding);
    mainVLayout->addSpacerItem(_spaceItem);
}

/**
*@函数概要：导入联系人失败的提示信息
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
void Contactwidget::importFailureSlot()
{
    QMessageBox::information(0,"提示","联系人导入操作失败.","关闭");
    return;
}

/**
*@函数概要：添加数据,新数据总是在顶部显示
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
void Contactwidget::addModel( const Contact & _contact)
{
    // g_contactModel->insertContact(0,_contact);
    qDebug()<<_contact.getName()<<"position:"<<g_contactModel->getInsertPosition(_contact.getAlphabetGroup());
    //m_contactModel->insertContact(m_contactModel->rowCount(),_contact);
    g_contactModel->insertContact(g_contactModel->getInsertPosition(_contact.getAlphabetGroup()),_contact);

}


/**
*@函数概要：保存dilog中修改的联系人信息,并发送数据到手机端
*Attention: 图片不能进行修改
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
void Contactwidget::saveEditContactSlot()
{
    QString mesg("CONTACT:MODIFY:");

    QString name=m_contactDialog->getName();
    QString _nameStr=m_contactDialog->getNamePlaceholderText();
    if(name.isEmpty())
    {
        name=_nameStr;
    }

    if(name.isNull() && name.isEmpty() &&_nameStr.isEmpty())
    {
        //警告信息
        QMessageBox::warning(0,"警告","联系人名字不能为空","确定");
        return ;
    }

    QString phoneStr;
    QStringList phoneList=m_contactDialog->getPhoneNums();
    if(phoneList.count() < 0)
    {
        QMessageBox::warning(0,"警告","联系人电话不能为空","确定");
        return ;
    }
    /**
*@注释:修改apk关键字段以后需要更改.
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
    foreach (QString var, phoneList)
    {
        phoneStr+=var;
        // phoneStr+=":";
    }
    QString mailStr;
    QStringList mailList=m_contactDialog->getMails();


    foreach (QString var, mailList)
    {
        mailStr+=var;

        mailStr+=":";
    }

    QString groupName=m_contactDialog->getGroup();
    //id
    mesg+=m_curContact.getId();
    mesg+=":";
    mesg+=name;
    mesg+=":";
    mesg+=phoneStr;
    //    mesg+=":";
    //    mesg+=mailStr;
    //    mesg+=":";
    //    mesg+=groupName;
    mesg+="\n";
    qDebug()<<"mesg:"<<mesg;
    //建立通讯发送联系人信息
    QTcpSocket *tcpsocket=new QTcpSocket;
    tcpsocket->connectToHost(g_ip,g_port,QTcpSocket::ReadWrite);
    if(tcpsocket->waitForConnected(2000))
    {
        tcpsocket->write(mesg.toStdString().c_str(),strlen(mesg.toStdString().c_str()));
        tcpsocket->waitForBytesWritten();
    }

    if(tcpsocket->waitForReadyRead(2000))
    {
        QString readData = QString::fromUtf8(tcpsocket->readAll());

        /**
*@注释:修改apk关键字段以后需要更改,注意apk发送来的字段.
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
        qDebug()<<"EditContact reback Infos:"<<readData;
        //EditContact reback Infos: "4185  或者是Modify::SUccess
        // readData=readData.trimmed();

        QString _id=m_curContact.getId();
        Contact _contact;
        _contact.alphabetGroup='1';
        _contact.getId()=_id;
        _contact.name=name;
        _contact.number=phoneStr;

        _contact.group="无";

        //当前行
        int pos= m_tableView->currentIndex().row();
        //可以删掉再插入,也可以直接修改
        g_contactModel->removeContact(pos);
        g_contactModel->insertContact(pos,_contact);

    }

    m_contactDialog->accept();
    tcpsocket->disconnectFromHost();
    delete tcpsocket;
    tcpsocket=NULL;
}
