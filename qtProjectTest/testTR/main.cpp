#include "mainwindow.h"
#include <QApplication>

#include <QLabel>
#include <QObject>
#include <QTranslator>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QTranslator t;
    t.load(":/res/testTR.qm");
    a.installTranslator(&t);
    QLabel l;
    l.setWindowTitle(QObject::tr("testTR"));
    l.show();

    
    return a.exec();
}
