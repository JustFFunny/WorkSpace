//内存 test
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#if 0
//cout<<" 栈内存 不能返回,在函数返回的时候已经清空\
//      且在指针传入函数的时候,复制一个新的指针"<<"\n";
// test1
//C语言参数传递采用传值方式，传递给函数体的实际上是实参的副本，
//因此，在函数中修改函数参数是没有用的，这个修改没办法带回到调用者中。

解决办法就是 传指针的指针
#endif
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



void testArrayASPtr(char *ptr)
{
    printf("address,%x\t",ptr);
    printf("AsPtr%d\n",sizeof(ptr));
}

void Testargument(char c)
{
    printf("after: %x\n",&c);
}
void TestargumentPtr(char *c)
{//传递的是一个指针的副本,但是他们指向的空间是一样的.所以取的地址是一样的.
    c="abc";
    printf("after: %x\n",c);
}

int main()
{
    Test1();
    char *ptr=NULL;
    ptr=new char();
    strcpy(ptr,"aaa");
    cout<<ptr;
    delete ptr;

    printf("*******数组作为参数传递时,数组退化为指针*(sizeof())*******\n");
    char array[]="abcdefghjklmn";
    printf("%d\n",sizeof(array));
    printf("before:%x\n",array);
    testArrayASPtr(array);

    printf("*******\n");
    char c='a';
    printf("before: %x\n",&c);
    Testargument(c);
    printf("***********************8\n");

    char *cptr=new char('acv');
    printf("before: %x\n",cptr);
    TestargumentPtr(cptr);
    printf("after after:%x/n",cptr);

    return 0;
}

