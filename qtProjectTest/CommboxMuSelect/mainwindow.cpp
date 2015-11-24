#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactmodel.h"
#include <QHBoxLayout>
#include <QCompleter>
#include <QStringList>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox;

    // initListWidget();
    initMV();

    QString _str("111;");
    QStringList _strList=_str.split(";");
    _strList.removeAll(QString(""));
    qDebug()<<_strList.count()<<_strList.at(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
*@function:初始化LIstWidget
*@author  :wuqiankun
*@mail    :qiankun@nfschina.com
*/
void MainWindow::initListWidget()
{
    m_listWidget=new QListWidget();

    QListWidgetItem * _item=new QListWidgetItem(m_listWidget);
    _item->setData(Qt::UserRole,"0001");
    QCheckBox * chekbox= new QCheckBox;
    chekbox->setText("test 0001");
    m_listWidget->setItemWidget(_item,chekbox);


    QListWidgetItem * _item2=new QListWidgetItem(m_listWidget);

    QCheckBox * chekbox2= new QCheckBox;
    chekbox2->setText("test 0002");
    m_listWidget->setItemWidget(_item2,chekbox2);

    connect(chekbox,SIGNAL(stateChanged(int)),this,SLOT(stateChangedslot(int)));
    connect(chekbox2,SIGNAL(stateChanged(int)),this,SLOT(stateChangedslot(int)));


    //布局
    m_lineEdit=new QLineEdit;
    m_pushButton =new QPushButton;

    //    QHBoxLayout * hboxlayout=new QHBoxLayout;
    //    hboxlayout->addWidget(m_lineEdit);
    //    hboxlayout->addLayout(m_pushButton);
    //    this->setLayout(hboxlayout);

    ui->comboBox->setModel(m_listWidget->model());
    ui->comboBox->setView(m_listWidget);
    ui->comboBox->setLineEdit(m_lineEdit);


    //    QCompleter * completer=new QCompleter(ui->comboBox);
    //    completer->setCompletionRole(Qt::DisplayRole);
    //    completer->setModel(m_listWidget->model());
    //    ui->comboBox->setCompleter(completer);

}
void MainWindow::stateChangedslot(int)
{

    QObject *object = QObject::sender();
    QCheckBox * senderCheckBox= qobject_cast<QCheckBox *>(object);
    if(senderCheckBox->checkState() == Qt::Checked)
    {

        QString _str= m_lineEdit->text();

        QString _seltectStr=_str+senderCheckBox->text()+";";


        m_lineEdit->setText(_seltectStr);
        m_lineEdit->setToolTip(_seltectStr);
    }
    else if(senderCheckBox->checkState() ==Qt::Unchecked)
    {
        QString _selectedStr=senderCheckBox->text()+";";
        m_lineEdit->setText(m_lineEdit->text().remove(_selectedStr));
    }




    /*
            bSelected = true;
            QString strSelectedData("");
            strSelectedText.clear();
            QObject *object = QObject::sender();
            QCheckBox *pSenderCheckBox = static_cast(object);
            int nCount = pListWidget->count();
            for (int i = 0; i < nCount; ++i)
            {
                QListWidgetItem *pItem = pListWidget->item(i);
                QWidget *pWidget = pListWidget->itemWidget(pItem);
                QCheckBox *pCheckBox = (QCheckBox *)pWidget;
                if (pCheckBox->isChecked())
                {
                    QString strText = pCheckBox->text();
                    strSelectedData.append(strText).append(";");
                }
                //所点击的复选框
                if (pSenderCheckBox == pCheckBox)
                {
                    int nData = pItem->data(Qt::UserRole).toInt();
                    qDebug() << QString("I am sender...id : %1").arg(nData);
                }
            }
            if (strSelectedData.endsWith(";"))
                strSelectedData.remove(strSelectedData.count() - 1, 1);
            if (!strSelectedData.isEmpty())
            {
                //ui.comboBox->setEditText(strSelectedData);
                strSelectedText = strSelectedData;
                pLineEdit->setText(strSelectedData);
                pLineEdit->setToolTip(strSelectedData);
            }
            else
            {
                pLineEdit->clear();
                //ui.comboBox->setEditText("");
            }
            bSelected = false;
          */
}

void MainWindow::initMV()
{
    m_contactModel =new Contactmodel;
    m_listView=new QListView;
    m_lineEdit=new QLineEdit;


    //Test
    Contact _contact("1");
    Contact _contact2("2");
    Contact _contact3("3");
    Contact _contact4("4");
    QList<Contact> _contactList;
    _contactList<<_contact<<_contact2<<_contact3<<_contact4;
    m_contactModel->insertContacts(0,_contactList);

    ui->comboBox->setModel(m_contactModel);
    ui->comboBox->setView(m_listView);
    ui->comboBox->setLineEdit(m_lineEdit);

    ui->comboBox->setEditable(true);

}
