#include "base.h"

Base::Base(int x)
{
    cout<<"base"<<"\n";
}


Derived::Derived(int m,int n)
     :Base(m)                    //初始化表里调用基类的构造函数
 {

 }
