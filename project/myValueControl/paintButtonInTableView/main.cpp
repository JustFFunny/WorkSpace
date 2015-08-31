#include "mainwindow.h"
#include <QApplication>

#include "tableview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    TableView  v;
    v.show();
    return a.exec();
}
