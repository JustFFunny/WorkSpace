#include <QCoreApplication>
#include "singleton.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    //    Singleton * m=new Singleton();
    //    m->test();
    //  Singleton * m2=new Singleton();

    // 不用初始化类对象就可以访问了(在静态函数内部)
    int k=0;
    Singleton::getInstancePtr();
    while(k<10)
    {
        // Singleton::getInstancePtr()->test();
        Singleton::getInstance().test();
        Singleton::getInstance().getI();
        ++k;
    }
    //    Singleton::getInstancePtr()->test();
    //    Singleton::getInstancePtr()->test();
    //    Singleton::getInstancePtr()->test();
    qDebug()<<QString::number( Singleton::getInstance().getI());




    return a.exec();
}
