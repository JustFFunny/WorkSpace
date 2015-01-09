//该app接受 拖放操作
#include <QApplication>
#include "tableview.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TableView * tableview=new TableView;
    tableview->show();
    return a.exec();
}
