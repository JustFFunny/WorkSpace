#ifndef PTR_H
#define PTR_H
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T> class SmartPtr;
template <class T>
class Ptr
{
public:
    friend class SmartPtr<T>;
    Ptr(T *p=NULL):\
        m_ptr(p),m_count(1)
    {
        cout<<"Ptr constructor\n";
    }

    ~Ptr()
    {
        delete m_ptr;
        cout<<"Ptr desconstructor\n";
    }

private:
    T * m_ptr;//保存指针
    size_t m_count;//计数
};


/*
 //可以使用模板的特例化
class Ptr
{
public:
    friend class SmartPtr;
    Ptr(string *p=NULL):\
        m_ptr(p),m_count(1)
    {
        cout<<"Ptr constructor\n";
    }

    ~Ptr()
    {
        delete m_ptr;
        cout<<"Ptr desconstructor\n";
    }

private:
    string * m_ptr;//保存指针
    size_t m_count;//计数
};

*/
#endif // PTR_H
