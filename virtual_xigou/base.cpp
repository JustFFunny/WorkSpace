#include "base.h"
#include <QDebug>

Base::Base()
{
    qDebug()<<"Base construct!";
}

Base::~Base()
{
    qDebug()<<"Base ~~~~construct!";
}

void Base::doSome()
{
    qDebug()<<"Base dome Something!";
}

void  Base::hello()
{
    qDebug()<<"virtual hello ";
}

void Base::hide(float x)
{
    qDebug()<<"........base_hide";
}

void Base::hide_2(int x)
{
    qDebug()<<"........base_hide_2";
}


Devrived::Devrived()
{
    qDebug()<<"Devried construct!";
}

Devrived::~Devrived()
{
    qDebug()<<"Devried ~~~~construct!";
}

void Devrived::doSome()
{
    qDebug()<<"Devried dome Something!";
}

void Devrived::get()
{
    qDebug()<<"Devried Get!";
}

void Devrived::hide(int y)
{
    qDebug()<<".............Devrid___hide";
}

void Devrived::hide_2(float y)
{
     qDebug()<<".............Devrid___hide_2";
}
