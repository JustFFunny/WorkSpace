//初始化列表
#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <stdio.h>
using namespace std;

class Base
{
public:
    Base(int x);
};
class Derived:public Base
{
public:
    Derived(int m,int n);
};

#endif // BASE_H
