/*http://bbs.csdn.net/topics/390462484
 *似乎模板的声明和实现分开在某些情况下是允许的,不过基本上生么作用也不起，浪费时间多写一些代码而已。
因为，对于模板类，声明和实现，必须同时可见，才可以编译不出错。
对于单纯的模板函数，则一点作用也没有。
曾经有人，为了版权，为了实现代码的保密。
为了把使用和模板分开编译，设法把模板类的声明和实现进行分离，
结果，这种违背客观规律的行为，丝毫作用也起不到。
最终也没有那个编译器，能够达到他的目的。

因为模板，只有使用的时候才知道，具体的数据类型，必须编译为使用该类型的模板参数的实现。
在用户没有使用模板的时候，任何人，任何编译器，都不能预测模板函数，和模板类的模板参数类型。

分离编译，唯一可以实现的是，接口和实现分离，声明处实现接口定义，实现处编写模板的实现代码。
接口看起来更清晰，但这是以实现代码，更复杂，更难写，更难懂为代价的，是得不偿失的。

所以标准库里的代码，大部分还是，实现和声明在一起的。真正分离实现的很少。
实际上，大家编写模板，也多半不会把声明和实现分离。

而且模板的代码必须，是实例化处（即引用处）可见的，这要求实现处，也要包含到应用处（#include“*.cpp”），这和大家的习惯严重不符。

所以分离实现的模板，好处不大，害处不小，这个很没有必要学，知道有这么回事就行了。
 *
*/
#ifndef SMARTPTR_H
#define SMARTPTR_H
#include <stdio.h>
#include "ptr.h"
#include <string>
#include <iostream>
using namespace std;

//模板类的定义和声明不能进行分离，因为模板类是在编译期间决定类型的
template <class T>
class SmartPtr
{
public:
    SmartPtr(T *p =NULL):
        m_p(new Ptr<T>(p))
    {
        cout<<"SmartPtr constructor:   "<<m_p->m_count<<"\n";
    }

    ~SmartPtr()
    {
        if(--m_p->m_count == 0)
        {
            delete m_p;
        }
        cout<<"SmartPtr desconstructor:   "<<m_p->m_count<<"\n";
    }

    //    //拷贝构造函数
    SmartPtr(const SmartPtr<T> & sp):
        m_p(sp.m_p)
    {
        ++m_p->m_count;
        cout<<"SmartPtr copyConstructor:   "<<m_p->m_count<<"\n";

    }

    //    //赋值函数
    SmartPtr<T>& operator=(const SmartPtr<T> & sp)
    {
        ++sp.m_p->m_count;
        if(--m_p->m_count ==0)
        {
            delete m_p;
        }
        m_p=sp.m_p;
        cout<<"SmartPtr ====:   "<<m_p->m_count<<"\n";
        return *this;
    }

private:
    Ptr<T> *m_p;//T类型的指针

};

/*
class SmartPtr
{
public:
    SmartPtr(string *p =NULL);
    ~SmartPtr();
    //拷贝构造函数
      SmartPtr(const SmartPtr & sp);
    //赋值函数
      SmartPtr& operator=(const SmartPtr & sp);
private:
    Ptr *m_p;//T类型的指针
};

*/
#endif // SMARTPTR_H
