#include <QCoreApplication>

#include "timeeventobject.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    TimeEventObject t;

    return a.exec();
}
