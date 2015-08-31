#include "mainwindow.h"
#include <QApplication>

#include <QTableWidget>
#include <QCheckBox>
#include <QWidget>
#include <QHBoxLayout>
#include <QHeaderView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    QTableWidget tw(2,2);
//    tw.verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
  QCheckBox * c=new QCheckBox;
    c->setFixedSize(50,50);
    tw.setCellWidget(0,0,c);
  //方法2
  /*设置中心位置
    QWidget *w =new QWidget;
    QHBoxLayout * hboxlayout=new QHBoxLayout;
    hboxlayout->addWidget(c);
    hboxlayout->setAlignment(w,Qt::AlignCenter);
    hboxlayout->setMargin(0);
    hboxlayout->setContentsMargins(10,10,10,10);
    w->setLayout(hboxlayout);
    tw.setCellWidget(0,0,w);
   */
    tw.show();
    return a.exec();
}
