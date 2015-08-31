#include "mainwindow.h"
#include <QApplication>

#include "studentinfomodel.h"
#include <QTableView>
#include "widgetdelegate.h"
#include  <QDebug>
#include <QHeaderView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
    QTableView v;
    v.horizontalHeader()->setStretchLastSection(true);
     //v.horizontalHeader()->setBaseSize(200,50);

     v.setColumnWidth(7,500);
     v.setRowHeight(0,500);
    //    v.setRowHeight(0,50);
    //    v.setColumnWidth(7,200);
    StudentInfoModel * m=new StudentInfoModel(8,0);
    StudentInfo s1("1","ww","1","11111111","ff","fffff");
    m->AddStudentInfo(s1);
    v.setModel(m);

    //    //设置代理   但是呢需要双击以后才能显示，这不符合我们的条件，
    //    WidgetDelegate  wd;
    //    v.setItemDelegateForColumn(7,&wd);
    DeWidget * w =new DeWidget;
    v.setIndexWidget(m->index(0,7,QModelIndex()),w);
    qDebug()<<( m->index(0,7,QModelIndex()).row() )<<"  "<<m->index(0,7,QModelIndex()).column();
    v.show();

    return a.exec();
}
