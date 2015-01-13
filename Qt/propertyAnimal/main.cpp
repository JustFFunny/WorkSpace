#include <QApplication>

#include "animalwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnimalWidget * w=new AnimalWidget;
    w->show();
    
    return a.exec();
}
