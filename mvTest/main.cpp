/*
Question 1: 为什不能修改数据了？？
 2.Delagate 代理的实现
 3.

  */

#include <QStyledItemDelegate>

#include "mainwindow.h"
#include <QApplication>

#include <QTableView>
#include "mytablemodel.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();

    QTableView view;
    view.setEditTriggers(QAbstractItemView::SelectedClicked);
    Stu _stu1("yang","22");
    Stu _stu2("wu","2");
    StuList _StuList;
    _StuList.push_back(_stu1);
    _StuList.push_back(_stu2);
    //    MyTableModel model(_StuList);
    MyTableModel model;
    model.SetStuDateBase(_StuList);
  //  view.setModel(&model);
//    //添加过滤
      QSortFilterProxyModel proxyModel;
       proxyModel.setSourceModel(&model);
       proxyModel.setDynamicSortFilter(true);
       proxyModel.sort(0);
       view.setModel(&proxyModel);

    //    view.edit(index);
    view.show();
//    model.insertRows(0,1,QModelIndex());
    //  model.removeRows(2,1,QModelIndex());

    //设置一列的代理
    //   view.setItemDelegateForColumn();

    //   QModelIndex index =model.index(1,2);
    //   model.setData(index,QVariant("edit"));



    //        QTableView view;
    //      QStandardItemModel model(4, 2);
    //      view.setModel(&model);
    //        view.show();

    return a.exec();
}
