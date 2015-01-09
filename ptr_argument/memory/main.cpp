//内存 test
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//cout<<" 栈内存 不能返回,在函数返回的时候已经清空\
//      且在指针传入函数的时候,复制一个新的指针"<<"\n";
// test1
//C语言参数传递采用传值方式，传递给函数体的实际上是实参的副本，
//因此，在函数中修改函数参数是没有用的，这个修改没办法带回到调用者中。
void getMemory1(char *ptr)
{
    ptr=(char*)malloc(100);//堆区
}

void Test1()
{
    char *_mem=NULL;
    getMemory1(_mem);

    if(_mem==NULL)
    {
        cout<<"book said:不能传递动态内存"<<"\n";
        cout<<"函数是按值传递,拷贝一个份:在指针传入函数的时候,复制一个新的指针"<<"\n";
        return ;
    }
    strcpy(_mem,"hello world");
    cout<<_mem<<"\n";

}

//test2   对test1的修改,使能传递
void getMemory1_modify(char **ptr)
{
    *ptr= (char*)malloc(15);
}

void test2()
{
    char * ptr=NULL;

}





int main()
{
    //Test1();
    char *ptr=NULL;
    ptr=new char();
    strcpy(ptr,"aaa");
    cout<<ptr;
    delete ptr;
    return 0;
}

