#include "singleton.h"
#include <QDebug>
// 类的静态成员变量要在类体外进行定义
Singleton *Singleton::m_pStatic=0;
int Singleton::i=0;
Singleton *Singleton::getInstancePtr()
{
    if(m_pStatic==0)
    {
        //qDebug()<<"construct";
        m_pStatic=new Singleton();
    }
    return m_pStatic;

}
Singleton  Singleton::getInstance()
{
//    qDebug()<<"ptrBegin";
//    getInstancePtr()->test();
//    qDebug()<<"ptrEnd";
    qDebug()<<"address1."<<getInstancePtr();
    return *getInstancePtr();
}
void Singleton::test()
{
    ++i;
   qDebug()<<QString::number(j);
    ++j;
    qDebug()<<QString::number(j)<<"test"<<QString::number(i);
}
 int Singleton::getI()
 {
     //return i;
      qDebug()<<"return"<<QString::number(j);
     return j;
 }
