/*
 *more effect C++ 避免无用的缺省构造函数(默认构造函数)
 *1.数组的创建方法
 *2.没有 默认构造函数的类,不能在基于 模板的 容器中使用.
 *3.类的虚继承
 **/
#include <iostream>
#include "companydevice.h"

using namespace std;
 typedef CompanyDevice*  CDP;//指针重命名
int main()
{
  //没有默认构造函数 不能 不传参数eg:
  // CompanyDevice _compamy;编译错误 没有匹配的函数 没有默认构造函数

    //传递参数 right;
    CompanyDevice _company("01");

    //没有默认构造函数想 创建对象数组 ,eg:这种方法不能在堆(new)上创建 对象数组
    CompanyDevice CDArray[]={CompanyDevice("02"),CompanyDevice("03")};

    //想在堆上创建数组的 方法eg:  1. 先创建类类型的指针,指针的指向是未知的; 2.然后
    CDP _cdp[2];
    //for
    _cdp[0]=new CompanyDevice("04");
    _cdp[1]=new CompanyDevice("05");

    CDP* _cdp2=new CDP[2];
    delete []_cdp2;
    delete _cdp[0];
    delete _cdp[1];

    cout << "Hello World!" << endl;
    return 0;
}

