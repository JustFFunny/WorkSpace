#include <QApplication>
#include <QtGui/QStringListModel>
#include <QCoreApplication>
#include <QDebug>
#include <QAbstractItemModel>
#include <QDir>
#include <QStringList>
#include <QtGui/qabstractitemview.h>
#include <QtGui/QListView>
#include <QSplitter>
#include <QTreeView>
#include <QDirModel>
#include <QTableView>
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//     QSplitter * splitter=new QSplitter;
//    QStringList _strlist;
//    _strlist<<"one"<<"two"<<"three";
//    QAbstractItemModel *model = new QStringListModel(_strlist);
//    QListView *view = new QListView(splitter);
//    view->setModel(model);

//    QListView *view2 = new QListView(splitter);
//    view2->setModel(model);
//    splitter->show();

//    view->setSelectionModel(view2->selectionModel());//把两个view相关，选中其中的一个项，另一个也选中
//    return a.exec();
//}

//QModleindex().可以获得modle的顶级项，作为父项
int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     QSplitter * splitter=new QSplitter;
     QDirModel * dirmodle=new QDirModel;

     QTreeView * treeView=new QTreeView(splitter);
     treeView->setModel(dirmodle);
//     treeView->setRootIndex(dirmodle->index("/"));

     treeView->setRootIndex(dirmodle->index(QDir::currentPath()));

     QListView * listView=new QListView(splitter);
     listView->setModel(dirmodle);
     listView->setRootIndex(dirmodle->index(QDir::currentPath()));

     QTableView * tabview=new QTableView(splitter);
     tabview->setModel(dirmodle);
//     tabview->setRootIndex(dirmodle->index("/"));
      tabview->setRootIndex(dirmodle->index(QDir::currentPath()));

    listView->setSelectionModel( treeView->selectionModel());
   listView->setSelectionModel(tabview->selectionModel());

     splitter->show();
    return a.exec();
}

