#include <iostream>
#include "base.h"
#include <strings.h>   //c 字符串比较函数
#include <cstring>   //c++  字符串比较函数  其实还是string.h  只是新的标准
using namespace std;
/*
**如果输入参数采用“值传递”,由于函数将自动产生临时变量用于复制该参数,该
  输入参数本来就无需保护,所以不要加 const 修饰。

**对于非内部数据类型的输入参数,应该将“值传递”的方式改为“const 引用传
递”,目的是提高效率。例如将 void Func(A a) 改为 void Func(const A &a)
*/
int main()
{
    cout << "Hello World!" << endl;
    //test 初始化列表中 对基类的构造函数进行 拷贝赋值
    Derived * a=new Derived(2,3);

    const char *name="hello world";
    strcmp("aaa","bb");


    return 0;
}

