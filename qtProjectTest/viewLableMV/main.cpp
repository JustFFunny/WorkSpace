#include <QApplication>
#include <QStandardItemModel>
#include "labledelegate.h"
#include <QListView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel model(7,2);
    QListView * listview =new QListView;
    listview->setModel(&model);
    LableDelegate * _lableDelegate=new LableDelegate;
    listview->setItemDelegate(_lableDelegate);
    for (int row = 0; row < 7; ++row)
    {
        QModelIndex index = model.index(row, 0, QModelIndex());
        model.setData(index, QVariant((row) ));
    }
    //for (int row = 0; row < 7; ++row) {
    //    for (int column = 0; column < 2; ++column) {
    //        QModelIndex index = model.index(row, column, QModelIndex());
    //        model.setData(index, QVariant((row+1) * (column+1)));
    //    }

    //}
    listview->show();


    return a.exec();
}
