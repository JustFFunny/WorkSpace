/*
 *catch块的参数推荐采用地址传递而不是值传递，
 *不仅可以提高效率，还可以利用对象的多态性。另外，
 *派生类的异常扑获要放到父类异常扑获的前面，
 *否则，派生类的异常无法被扑获。
 *
 */

#include <iostream>
#include "myexception.h"
using namespace std;

void getexception(int num)
{
    if(num==1)
    {
        throw Myexception("error","paragae is apply");
    }

}


int main()
{
    try
    {
         getexception(1);
    }
//    catch(Myexception & my)
//    {
//        cout <<"myexception:"<<my.what()<<"\n";
//    }
    catch(logic_error & error)//多态在 异常处理中的使用
    {
        cout<<"logic_error:"<<error.what()<<"\n";
    }
    catch(...)
    {
        cout<<"eee";
    }


    cout << "Hello World!" << endl;
    return 0;
}

