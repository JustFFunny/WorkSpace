#include "test.h"
#include <QString>
#include <QDebug>
Test Test::getJ()
{
    qDebug()<<QString::number(j);
    return Test(1,1);
}

void Test::get()
{
    qDebug()<<QString::number(i);
}
