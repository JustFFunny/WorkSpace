#include "mainwindow.h"
#include <QApplication>

#include <QMultiMap>
#include <QDebug>
#include <QVector>
#include <QLabel>
#include "testwidget.h"

#include <QTreeWidget>
#include <QFontDatabase>

#include <QElapsedTimer>
#include <QSplashScreen>

#include <QTableView>
#include <QDirModel>

#include <QFile>
#include <QIcon>


#include <stdio.h>
#include <iostream>

#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

typedef QString II;
class Stu
{
public:
    Stu(int num,QString name):m_name(name),m_num(num)
    {
    }
    QString getStr()
    {
        return m_name+"____________"+QString::number(m_num);
    }

private:
    QString m_name;
    int m_num;
};

#include "exercisewidget.h"

void sleep(int secs)
{
    QTime dieTime = QTime::currentTime().addMSecs(secs);

    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 20);
}

void swap(int& a,int& b);

void autoAdjustHeight(QTextEdit *_edit)
{
    _edit->setFixedHeight(_edit->document()->size().rheight() + _edit->frameWidth() * 2);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*
    QMultiMap<QString,Stu> map;
    Stu _stu(1,"n");
    Stu _stu1(11,"m");
    Stu _stu2(12,"j");

    //    map.insert("b",_stu);
    //    map.insert("b",_stu1);
    //    map.insert("b",_stu2);
    map.insertMulti("b",_stu);
    map.insertMulti("a",_stu1);
    map.insertMulti("b",_stu2);

    QMultiMap<QString, Stu>::iterator i = map.begin();
    for(;i!=map.end();++i)
    {
        qDebug()<<i.value().getStr();
    }
*/
    qDebug()<<int('Z')<<"_______"<<int('A')<<int('B');
    QVector<int> alphabetPositionVec(26,-1);
    alphabetPositionVec[0]=2;
    qDebug()<< alphabetPositionVec[0];
    char c='C';
    if('C'==c)
    {
        qDebug()<< "equal";
    }
    //计算数
    typedef unsigned int UInt;
    qDebug()<<QString::number( int (~(UInt(-1)/2)) )<<"_________"<< QString::number( int (UInt(-1)/2) );

    //    QLabel *label =new QLabel;
    //    QString _str("qqqqqqqqqqqqqqqqqqqqqqqqp");
    //    label->setText(_str);

    //    label->setMaximumWidth(100);
    //    label->adjustSize();
    //    label->setWordWrap(true);

    //    label->show();

    //    ExerciseWidget ew;
    //    ew.show();
    QString str("你好");
    QString str2("nihao");
    qDebug()<<str.length()<<"___"<<str2.length();//2 ____5

    TestWidget *tw = new TestWidget;
    // tw->show();

    //    tw->testEdit->setText("one line");
    //    tw->autoAdjustHeight();
    //    sleep(1000);
    //    tw->testEdit->setText("two line\r\ntwo line");
    //    tw->autoAdjustHeight();
    //    sleep(1000);
    tw->testEdit->setText("threelinethreelinethreelinegddddddddddddddddfffffffffffffffffffffffffffffffffffffffffffffffffb");
    tw->autoAdjustHeight();

    QTextEdit * _edit=new QTextEdit;
    _edit->setMaximumWidth(100);
    _edit->show();
    _edit->setText("threelinethreelinethreelinegddddddddddddddddfffffffffffffffffffffffffffffffffffffffffffffffffb");
    autoAdjustHeight(_edit);

    qDebug()<<    isalpha('2');

    QMap<QString ,QString> _mapTest;
    _mapTest.insert("1","1111");
    _mapTest.insert("2","2222");

    QMap<QString ,QString>::iterator it=_mapTest.find("3");

    if(it!=_mapTest.end())
    {
        qDebug()<<"key:"<<it.key();
    }
    else
    {
        qDebug()<<"Nokey";
    }






    QFontDatabase database;
    QTreeWidget fontTree;
    fontTree.setColumnCount(2);
    fontTree.setHeaderLabels(QStringList() << "Font" << "Smooth Sizes");

    foreach (const QString &family, database.families()) {
        QTreeWidgetItem *familyItem = new QTreeWidgetItem(&fontTree);
        familyItem->setText(0, family);

        foreach (const QString &style, database.styles(family)) {
            QTreeWidgetItem *styleItem = new QTreeWidgetItem(familyItem);
            styleItem->setText(0, style);

            QString sizes;
            foreach (int points, database.smoothSizes(family, style))
                sizes += QString::number(points) + " ";

            styleItem->setText(1, sizes.trimmed());
        }
    }

    // QSplashScreen
    QPixmap pixmap(":/res/sishen.gif");
    QSplashScreen screen(pixmap);

    screen.show();
    screen.showMessage("I love the world!!", Qt::AlignCenter, Qt::blue);
#if 1
    int delayTime = 5;
    QElapsedTimer timer;
    timer.start();
    while(timer.elapsed() < (delayTime * 1000))
    {
        a.processEvents();
    }
#endif

#if 0
    QDateTime n=QDateTime::currentDateTime();
    QDateTime now;
    do{
        now=QDateTime::currentDateTime();
        app.processEvents();
    } while (n.secsTo(now)<=5);//5为需要延时的秒数
#endif


    // fontTree.show();
    //  screen.finish(&fontTree);


    QString _str("wqiankun<10086>");
    QStringList _phoneNumList=_str.split(";");
    qDebug()<<"联系人出现的次数:"<<_phoneNumList.count()<<_phoneNumList.at(0);//1  _str

    int _pos=_str.lastIndexOf("<");
    int _posEnd=_str.lastIndexOf(">");
    _str.mid(_pos+1,_posEnd-_pos);
    qDebug()<<_str.mid(_pos+1,_posEnd-1-_pos);
    int m=32 ;int b=90;
    swap(m,b);
    qDebug()<<m<<b;

    QList<int> _listInt;
    _listInt<<1<<2<<3;
    foreach (int a, _listInt)
    {//正序 123
        qDebug()<<a;
    }


    QTableView *v=new QTableView;
    QDirModel *_dirModel =new QDirModel;
    v->setModel(_dirModel);
    v->setRootIndex(_dirModel->index(QDir::currentPath()));
    v->show();
    QDirModel *_dirModel2 =new QDirModel;
    v->setModel(_dirModel2);
    v->setRootIndex(_dirModel2->index("/home/wuqiankun"));




    //    QList<QString> list;
    //    list << "sun" << "cloud" << "sun" << "rain";
    //    list.removeOne("sun");
    //    foreach (QString var, list)
    //    {
    //        qDebug()<<var;
    //    }

    QString _path("/sc/d/");
    QStringList list=_path.split("/");
    list.removeAll("");
    foreach (QString var, list)
    {
        qDebug()<<var;
    }


    QString filepath("/home/wuqiankun/桌面/test.txt");

    QFile *localFile = new QFile(filepath);
    if(!localFile->open(QFile::ReadWrite))
    {
        qDebug()<<"文件没有读权限.";

    }
    qint64 totalBytes = localFile->size();

    QString fileSize = QString::number(totalBytes);
    qDebug()<<fileSize<<"totalBytes:"<<totalBytes;



    //    FILE* file = fopen(filepath.toStdString().c_str(), "rb");
    //    if (file)
    //    {
    //        int size = std::filelength(fileno(file));
    //        qDebug()<<"FILE:"<<size;
    //        fclose(file);
    //    }
    //if(argc==2)
    //{
       const char * _filePath(argv[0]);
        qDebug()<<_filePath;
   // }
    struct  stat buf;
    int fd;
    fd = open (_filePath, O_RDWR);
    fstat (fd, &buf);
    qDebug()<<(int)(buf.st_size);

    QIcon _icon(":/res/application_layout1.png");
    qDebug()<<"isNULL:"<<_icon.isNull();



    return a.exec();
}

void swap(int& a,int& b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
