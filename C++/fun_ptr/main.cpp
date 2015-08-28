/*
 *函数指针的用法
 *void (*fun)(int x);
1. 函数的调用
 *typede int (*PF) (int * ,int);
 *PF是别名，类型是int (*)(int*,int)
 int (*)(int*,int) ---- 一个指针，这个指针指向一个函数，
 这个函数有两个类型为int*,int的参数，返回值类型为int。
 所以，PF就是这样一个指针类型
 PF ff;
 .ff是一个函数，有一个类型为int的参数，返回值类型为PF

2. 函数指针作为参数 可以调用 函数
    void test( PF pf);
 **/
#include <iostream>

using namespace std;
void (*Fun)(int x);
void myfun(int x)
{
    cout<<"hello "<<x<<"\n";
}
typedef void(* Funtype )(int x);

int main()
{
    myfun(1);
    Fun=myfun;
    Fun(2);

    Funtype funtype;
    funtype=myfun;
    funtype(10);

    cout << "Hello World!" << endl;
    return 0;
}
