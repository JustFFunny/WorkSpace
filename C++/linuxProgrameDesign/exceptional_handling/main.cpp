/*异常处理:try catch  throw
 *
 *
try-catch语句形式如下 ：
try
{
包含可能抛出异常的语句；
}
catch(类型名 [形参名]) // 捕获特定类型的异常
{
}
catch(类型名 [形参名]) // 捕获特定类型的异常
{
}
catch(...)    // 三个点则表示捕获所有类型的异常
{
}
 *
 *
 *
 *异常存在于程序的正常功能之外，并要求程序立即处理。
 *不能不处理异常，异常是足够重要的，使程序不能继续正常执行的事件。
 *如果找不到匹配的catch，程序就调用库函数terminate
 *
 *
 *在查找匹配的catch期间，找到的catch不必是与异常最匹配的那个catch，
 *相反，将选中第一个找到的可以处理该异常的catch。
 *因此，在catch子句列表中，最特殊的catch必须最先出现，否则没有执行的机会
 **/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
// a/b 分母不为 0
double div(double front,double back)
{
    if(back==0)
    {
        throw  back;    //检测异常
    }
    return front/back;
}


int main()
{
    //    char * str= "a";
    //    int istatus=atoi(str);
    //     cout << "Hello World:"<<istatus << endl;
    //    //assert(istatus !=0);
    double _res;
    try
    {   _res=div(8.0,4.0);
        cout<<_res<<"\n";
        _res=div(8.8,0.0);
    }
    //    catch (double _num)//捕获并处理异常
    //    {
    //        cout<<"the fenmu is zero!"<<_num<<"\n";
    //    }
    //    catch(...)  //捕获所有的异常
    //    {
    //        cout<<"catch all execption!"<<"\n";
    //    }
    //test 没有异常捕获时  terminate called after throwing an instance of 'double'

    catch( int n)
    {
        cout<<"catch int"<<"\n";
    }
    catch(double )
    {
    }

    cout <<"hello world!"<<"\n";
               return 0;
    }

