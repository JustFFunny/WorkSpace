#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>

#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
    QTextEdit * _e=new QTextEdit;
    _e->setText("hello");
    MainWindow w;
    w.show();
    
    return a.exec();
}
