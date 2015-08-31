#include <QApplication>
#include "ballonwidget.h"
#include "mypainterwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    BallonWidget * b=new BallonWidget();
//    b->show();
    MyPainterWidget * p=new MyPainterWidget;
    p->show();
    return a.exec();
}
