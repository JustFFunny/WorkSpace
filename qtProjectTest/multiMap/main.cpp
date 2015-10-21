#include "mainwindow.h"
#include <QApplication>

#include <QMultiMap>
#include <QDebug>
#include <QVector>
#include <QLabel>
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

    ExerciseWidget ew;
    ew.show();

    return a.exec();
}
