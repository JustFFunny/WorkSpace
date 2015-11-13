/**
*@概要：剪切板 QClipboard
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/

#include "mainwindow.h"
#include <QApplication>
#include <QClipboard>
#include <QDebug>

#include "mytextedit.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    myTextEdit mt;
//    mt.setFixedSize(200,500);
//    mt.show();
    
    QClipboard * _clipboard=QApplication::clipboard();
    qDebug()<<_clipboard->text(QClipboard::Clipboard);

    return a.exec();
}
