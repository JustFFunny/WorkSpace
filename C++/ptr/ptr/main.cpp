#include <iostream>
#include <string>
#include <string.h>
//return 语句不可返回指向“栈内存”的“指针”或者“引用”,因为该内存在函数体结束时被自动销毁
using namespace std;

string getString()
{
    string _name="hello";
    return _name;
}
char * getmemory()
{
    char str[]="hello";
    return str;//此处出错  函数不能返回 栈分配的内存(栈分配的内存在函数返回时,自动消亡)
}

int main()
{

    char * pb=new char[10];
    strcpy(pb,"aa");
    cout<<sizeof(pb)<<"\n";//4指针  sizeof(char*)
    char pd[20];
    // strcpy(pd,"aaa");
    cout<<sizeof(pd)<<"\n";//数组大小20*(char*)

    char pm[2];
    strcpy(pm,"abcdefg");
    cout<<sizeof(pm)<<"\n";//2
    cout<<pm;//abcdefg   输出直到 '\0'




    char* name="hello world";
    size_t length=0;
    char * ptr2=name;
    while(*name++!='\0')
    {
        length++;
    }
    length++;
    cout<<sizeof(*ptr2)*length<<"\n";

    return 0;
}
