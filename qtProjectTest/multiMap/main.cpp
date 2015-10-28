#include "mainwindow.h"
#include <QApplication>

#include <QMultiMap>
#include <QDebug>
#include <QVector>
#include <QLabel>
#include "testwidget.h"

#include <QTreeWidget>
#include <QFontDatabase>

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
    fontTree.show();
    return a.exec();
}
