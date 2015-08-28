#include <iostream>
#include <stdio.h>
using namespace std;
#if 0
char *p="adb";  @1//"abd"被存取到静态数据区,而且是全局变量
char *pp="adb"; @2 //  所以输出@1.@2中指针的地址是一样的.

2.在函数执行以后对栈区进行清除操作,对静态数据区和堆区则不清除.
所以get_str2(),执行完就释放了栈区的内存,不存在有"efgooooooooooooooooooooooooo"的声明了.
                                                                #endif

                                                                char * get_str(void)
{
                                                                char *ptr="abd";
                                                                return ptr;
                                                                }
                                                                char * get_str2()
{
                                                                char ptr[]="efgooooooooooooooooooooooooo";
                                                                return ptr;//返回 以后,ptr指向的栈分配 回收了,所以ptr指向的内容是不确定的.
                                                                }


                                                                int main()
{
                                                                #if 0
                                                                char * p=get_str();
                                                                printf("%s\n",p);
                                                                char * pp=get_str2();
                                                                printf("%s\n",pp);
                                                                //cout << "Hello World!" << endl;


                                                                char *pi="abd";
                                                                char *ppi="abd";
                                                                printf("%x,%x",pi,ppi);

                                                                #endif
                                                                #if 0
                                                                野指针
                                                                      #endif

                                                                      printf("***************\n");


                                                                char * sptr=new char('abcdefg');
                                                                printf("%s\n",sptr);
                                                                delete sptr;
                                                                sptr=0;
                                                                printf("%s\n",sptr);
                                                                return 0;
                                                                }

