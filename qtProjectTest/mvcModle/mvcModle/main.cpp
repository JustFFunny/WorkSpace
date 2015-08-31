//自定义Modle
#include <QApplication>
#include <QDebug>
#include <QStringList>
#include "stringlistmodel.h"
#include <QListView>

int main(int argc, char *argv[])
{  //只读的modle
    QApplication a(argc, argv);
     QStringList _strList;
     _strList<<"wo"<<"are"<<"brothers"<<"!";
     StringListModel * modle=new StringListModel(_strList);
     QListView * listview =new QListView;
     listview->setModel(modle);
     listview->show();
    return a.exec();
}
