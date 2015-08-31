/*高质量c/c++编程  7 内存管理
 *To:ptr &&数组
 *1.C++/C 语言没有办法知道  指针所指的内存容量,除非在申请内存时记住它
 *
 *
 *
 *用运算符 sizeof 可以计算出数组的容量(字节数)(注意’\0’结尾)
。指针 p 指向 a,但是 sizeof(p)的值却是 4。这是因为
sizeof(p)得到的是一个指针变量的字节数,相当于 sizeof(char*),而不是 p 所指的内
存容量。C++/C 语言没有办法知道指针所指的内存容量,除非在申请内存时记住它。
注意当数组作为函数的参数进行 传递时 ,该数组自动退化为同类型的 指针。

2.如果函数的参数是一个指针,不要指望用该指针去申请动态内存。
Test 函数的语句 GetMemory(str, 200)并没有使 str 获得期望的内存,
str 依旧是 NULL,

3. 尤其是 delete)它们只是把指针所指的内存给释放掉,但并没有把指针本身干掉。
 *
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;



void test(char* c[100])
{
    cout <<"数组做为行参传递的时候,传递的指针"<<sizeof(c)<<"\n";//4
}

char * getString()
{
    char  p[]="hello";
    return p;
}

char *  getMemory()
{
    char * a="hello world";//字符串常量位于静态存储区
    return a;
}

int getNum()
{
    int num=11110;
    return num;
}


void testPtrcanshu(char * ptr)
{
    cout<<"得到传如以后指针地址:"<<&ptr;
}

int main(int argc, char *argv[])
{

    //数组 ptr
    char b[]="2hello world";
    char * ptr=b;
    cout <<" 数组的大小"<<sizeof(b)<<"\n";//12
    cout <<"指针的大小"<<sizeof(ptr)<<":"<< sizeof(char*)<<"\n";//4 4



    /*
    //test  如果函数的参数是一个指针,不要指望用该指针去申请动态内存。
    //指针做行参 传入以后 会创建一个新指针,地址不同
    char * _canshu="hello";
    cout<<"传入前指针地址:"<<&_canshu<<"\n";
    testPtrcanshu(_canshu);
    */



    /*  如果在函数内部创建的 指针指向静态存储区 ,函数结束 内存不会自动释放,正确
    char * p=getMemory();
    cout<<p<<"\n";
    */


    /*野指针
     *如果在函数内部创建的是 栈内存 不正确,已经释放了
    char * ptrS=getString();//得到的结果指向的值 不确定(垃圾内容)
    cout<<ptrS<<"\n";
    */

    /*
 * //delete
    char * ptrV=new char[100];
    strcpy(ptrV,"abc");
    delete ptrV;//删掉指针 ptrV所指向的 内存被释放,但是ptrV所指向的地址没变
    cout<<ptrV<<"\n";
    */



    char * ptv=new char[10];
    if(ptv==NULL)
    {
        cout<<"empty";
        return 0;
    }
    // ptv="HELLO";//内容复制 不能用=    内容比较 不能用!=
    strcpy(ptv,"Hello");//应该用strcopy     strcmp
    cout<<ptv<<"\n";
    delete ptv;
    ptv=NULL;

    return 0;
}
