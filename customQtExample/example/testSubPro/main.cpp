#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        MainWindow w;
        w.show();
//    int ret=  QMessageBox::information(NULL,"提示","是否重新发送?","SEND","CANCEL");

//    switch (ret)
//    {
//    case  0:
//        qDebug("0");
//        break;
//    case 1:
//        qDebug("1");
//        break;
//    default:
//        break;
//    }
    
    return a.exec();
}
