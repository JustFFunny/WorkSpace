#include "mainwindow.h"
#include <QApplication>

#include <QDebug>
#include <string.h>
int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
    //const



    int const  a=5;//const int a=5;等价a 的值是5,不能改变
    //a=6;  error: assignment of read-only variable 'a'
    
    char const * ptr="abc";//*ptr 指向的内容不恩那个改变
    //*ptr="nmv";//error: assignment of read-only location '* ptr'
    ptr="mmml";
    qDebug()<<ptr<<"\n";

    char  str[]="qiankun";
    char* const pStr=str;//pStr指向地址不会改变,指向的内容可以改变.
    //pStr="aaaa";//error: assignment of read-only variable 'pStr'
    pStr[0]='W';

    qDebug()<<pStr;

    char * pptr="abv";//近似于const char *ptr;
    pptr="abbbbbaaa";
    qDebug()<<pptr;
    char * ptr2;
    ptr2=pptr;
    qDebug()<<"ptr2: "<<ptr2;


    const char * ptr3="wqiankun";//non-const 可以赋值于const
   // ptr3=ptr2;
    qDebug()<<"ptr3: "<<ptr3;

    //const 不可以赋值于 non-const
    //  pptr=ptr3;//error: invalid conversion from 'const char*' to 'char*'
    //去壳
    char pmstr[]="kkkkkklkkkkk";
    strcpy(pmstr,ptr3);
    pptr=const_cast<char*>(ptr3);
    qDebug()<<pptr;
#if 0
    const char *p1 = "Hello world"; // p1 指向的地址可更改
    // 但是不可更改p指向的内容，比如*p1='c'是错误的
    p1 = "New Hello world";          // ok
    p1[0] = 'c';                     // Compile ERROR !!!

    char const *p2 = "Hello world"; // 同p1
    p2 = "New Hello world";          // ok
    p2[0] = 'c';                     // Compile ERROR !!!

    char str[] = "Hello world";
    char * const p3 = str;           // p3指向地址不可更改，但是可以更改所指向地址内容
    p3 = "New Hello world";          // Compile ERROR !!!
    p3[0] = 'c';                     // ok
    p3[1] = 'p';                     // ok
    p3[2] = 'p';                     // ok

    char const * const p4 = "Hello world"; // p4指向地址和内容均不可更改
    p4 = "New Hello world"           // ERROR !!!
            p4[0] = 'c'                      // ERROR !!!

            const char * const p5 = "Hello world"; // 同p4
#endif
    // return a.exec();
}
