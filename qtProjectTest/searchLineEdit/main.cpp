#include "mainwindow.h"
#include <QApplication>
#include "searchedit.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    searchEdit s;
    s.show();
    return a.exec();
}
