#ifndef TEST_SMARTPTR_H
#define TEST_SMARTPTR_H

#include<iostream>
#include<stdexcept>
using namespace std;
class Stub
{
public:
    void print()
    {
        cout<<"Stub:print"<<endl;
    }
    ~Stub()
    {
        cout<<"Stub:Destructor"<<endl;
    }
};

template<typename T>
class SmartPtr
{
public:
    SmartPtr(T*p=0):
        ptr(p),pUse(new size_t(1))
    {
      cout<<"smartptr construct \n";
    }

    SmartPtr(const SmartPtr & src):
        ptr(src.ptr),pUse(src.pUse)
    {
        ++*pUse;
        cout<<"copy count  "<<*pUse<<"\n";
    }

    SmartPtr&operator=(const SmartPtr &rhs)
    {
        //self-assigningisalsoright
        //可能是赋值给已经创建的 ，应该原来的count-1
        ++*rhs.pUse;
        decrUse();
        ptr=rhs.ptr;
        pUse=rhs.pUse;

         cout<<"==== count   "<<*pUse<<"\n";
        return *this;
    }
    T* operator->()
    {
        if(ptr)
            return ptr;
        throw std::runtime_error("NULLpointer");
    }
    const T* operator->()const
    {
        if(ptr)
            return ptr;
        throw std::runtime_error("NULLpointer");
    }
    T &operator*()
    {
        if(ptr)
            return *ptr;
        throw std::runtime_error("dereferenceof NULLpointer");
    }
    const T &operator*()const
    {
        if(ptr)
            return *ptr;
        throw std::runtime_error("dereferenceof NULLpointer");
    }
    ~SmartPtr()
    {
        decrUse();
        std::cout<<"SmartPtr:Destructor"<<std::endl;//fortesting
    }
private:
    void decrUse()
    {
        if(--*pUse==0)
        {
            delete ptr;
            delete pUse;
        }
    }
    T* ptr;
    size_t* pUse;
};
#endif // TEST_SMARTPTR_H
