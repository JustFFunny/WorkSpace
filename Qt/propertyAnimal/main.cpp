#include <QApplication>

#include "animalwidget.h"
#include <QDialogButtonBox>
#include <QDebug>
#include <QImage>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnimalWidget * w=new AnimalWidget;
    w->show();
    QDialogButtonBox * b=new QDialogButtonBox;
    b->resize(600,600);
    b->show();
    int f;
#ifdef SLOW
    f =10;   // 摒弃的代码
#else
    f=11;    //正在使用的代码
#endif

    qDebug()<<f<<"\n";

    return a.exec();
}
