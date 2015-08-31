#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QDebug>
//汉化 翻译
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    bool _result=false;
    _result = translator.load(":/pro/language/mainwindow_cn");
    qDebug()<<"he"<<QString::number(_result);
    a.installTranslator(&translator);
    MainWindow w;
    w.show();
    
    return a.exec();
}
