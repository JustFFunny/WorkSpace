#include "mainwindow.h"
#include <QApplication>

#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QStringList strlist;
    strlist<<"1"<<"2"<<"3"<<"4"<<"5";
    qDebug()<<" before count:"<<strlist.count()<<"\n";
    for(int i=0; i<strlist.count();++i)
    {
        qDebug()<<i<<"count:"<<strlist.count()<<"\n";
        strlist.removeAt(i);
    }
    qDebug()<<" Lastcount:"<<strlist.count()<<"\n";
    for(int i=0; i<strlist.count();++i)
    {
        qDebug()<<strlist[i]<<"\n";

    }
    return a.exec();
}
