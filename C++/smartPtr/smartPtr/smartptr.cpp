#include "smartptr.h"
#include <iostream>
using namespace std;

template<class T>
SmartPtr<T>::SmartPtr(T *p ):
     m_p(new Ptr<T>(p)) //m_p(p)
{
    cout<<"SmartPtr constructor:   "<<m_p->m_count<<"\n";
}

template<class T>
SmartPtr<T>::~SmartPtr()
{
    if(--m_p->m_count == 0)
    {
        delete m_p;
    }
    cout<<"SmartPtr desconstructor:   "<<m_p->m_count<<"\n";
}

//拷贝构造函数
template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> & sp):
    m_p(sp.m_p)
{
    ++m_p->m_count;
    cout<<"SmartPtr copyConstructor:   "<<m_p->m_count<<"\n";
}

//赋值函数
//先对 外面引用的资源+1,再自减自身资源的引用来判断是否为0,
//是则释放资源，否则不释放。这样也就实现类自身赋值的情况。
template<class T>
SmartPtr<T> & SmartPtr<T>::operator=(const SmartPtr<T>& sp)
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



/*
 //////OK
SmartPtr::SmartPtr(string *p ):
     m_p(new Ptr(p)) //m_p(p)
{
    cout<<"SmartPtr constructor:   "<<m_p->m_count<<"\n";
}


SmartPtr::~SmartPtr()
{
    if(--m_p->m_count == 0)
    {
        delete m_p;
    }
    cout<<"SmartPtr desconstructor:   "<<m_p->m_count<<"\n";
}

//拷贝构造函数

SmartPtr::SmartPtr(const SmartPtr & sp):
    m_p(sp.m_p)
{
    ++m_p->m_count;
    cout<<"SmartPtr copyConstructor:   "<<m_p->m_count<<"\n";
}

//赋值函数
//先对 外面引用的资源+1,再自减自身资源的引用来判断是否为0,
//是则释放资源，否则不释放。这样也就实现类自身赋值的情况。

//我感觉有点 删除减少所占自身资源。

SmartPtr & SmartPtr::operator=(const SmartPtr& sp)
{
    ++sp.m_p->m_count;
    if(--m_p->m_count ==0)
    {

        cout<<"SmartPtr === 0"<<m_p->m_count<<"\n";
        delete m_p;
    }
    m_p=sp.m_p;
    cout<<"SmartPtr ====:   "<<m_p->m_count<<"\n";
    return *this;
}

*/
