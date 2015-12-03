#ifndef CLASS_H
#define CLASS_H
#include <stdio.h>
#include <iostream>
using namespace std;
class A
{

   public:

    void output()
    {
       std::cout << "I am class A :D" << std::endl;
    };

};

class B
{

   public:

    bool methodB(A a)
    {
       a.output();
       return true;
    }

};


#endif // CLASS_H
