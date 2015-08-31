#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Qt::WindowFlags flags = 0;
    flags |= Qt::FramelessWindowHint;
    w.setWindowFlags(flags);

    w.show();
    
    return a.exec();
}
