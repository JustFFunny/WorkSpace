#include <QApplication>
#include <QLineEdit>
#include <QObject>
#include <QDebug>
#include <mylineedit.h>
#include <QWidget>
#include <QHBoxLayout>


#include <newlineedit.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  //test1
    //mylineEdit * m=new mylineEdit;
 //test 2
    NewlINeEdit * _new =new NewlINeEdit;
    _new->show();
    //test3
// QWidget * _w =new QWidget;
// QHBoxLayout * _hbox=new QHBoxLayout;
// _hbox->addLayout(_hbox);
// NewlINeEdit * _new =new NewlINeEdit;
// _new->show();
// _hbox->addWidget(_new);
// _w->setLayout(_hbox);
// _w->show();
    
    return a.exec();
}
