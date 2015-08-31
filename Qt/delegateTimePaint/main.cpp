#include "mainwindow.h"
#include <QApplication>
#include "timeeditdelegate.h"
#include <QTableView>
#include <QStandardItemModel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
    QTableView v;
    QStandardItemModel m(4,2);
    v.setItemDelegateForColumn(1, new TimeEditDelegate("yyyy-dd-MM"));

    v.setModel(&m);
    v.show();

    return a.exec();
}
