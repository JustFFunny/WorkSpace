/*
*@function:创建空文件
*@author  :wuqiankun
*@mail    :qiankun@nfschina.com
*/
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QDebug>

#include <QAction>
#include <QMenu>
#include <QTableView>
#include <QObject>
#include "testobject.h"
int makeFile(QString firStr)
{
    QString _string(firStr);
    QString _dirPath;
    _dirPath=_string.left(  _string.lastIndexOf("/"));

    if(_string.contains("/"))
    {

        QDir _dir;
        if(_dir.exists(_dirPath))
        {
            qDebug()<<"dir is exists!";
        }
        else
        {
            bool _ff= _dir.mkpath(_dirPath);
            qDebug()<<_ff;
        }
    }

    //目录不存在不能创建
    //QString _str(argv[2]);
    QFile _file(_string);//_string
    if(_file.exists())
    {
        qDebug()<<"file is exists!";
        return 1;
    }
    _file.open(QFile::ReadWrite);
    _file.close();
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    QMenu * _menu=new QMenu();
    //    _menu->show();

    QTableView * tableView=new QTableView;

    TestObject _testOBject(NULL);

    tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(tableView,SIGNAL(customContextMenuRequested(const QPoint &)),&_testOBject,SLOT(output(const QPoint &)));
    tableView->show();

    return a.exec();
}
