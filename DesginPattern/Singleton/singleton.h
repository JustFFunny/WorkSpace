#ifndef SINGLETON_H
#define SINGLETON_H
// 只有一个实例   单件模式 创建型
//让类自身负责保存它的唯一实例(静态变量)
#include <QDebug>
class Singleton
{
private:
    //私有构造函数，保证不能被外部访问

    Singleton(){
        j=0;
        qDebug()<<"constuct";
               };
   // ~Singleton(){};
public:
    //静态成员函数 提供全局访问借口 保证只有一个实例被创建
    static Singleton * getInstancePtr();
    static Singleton  getInstance();
    void test();
    int getI();
private:
    //静态成员变量,提供全局唯一的实例
    static Singleton *m_pStatic;
    static int i;
    int j;
};

#endif // SINGLETON_H
