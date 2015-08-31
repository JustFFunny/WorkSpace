//在子层找不到 catch 语句,就向上一层找,
//一直找 到主函数,还是没有人catch的花,就termanite
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

template  <typename T>
T div( T front ,T back)
{
    if( (0==back) || (back>-0.0000001 && back<0.0000001))
    {
        throw  T(back);
    }
}



int main()
{
    int x=6,y=0;
    try
    {
        cout<<"除数:"<<x<<"被除数:"<<y<<"\n";
        div(x,y);

    }
    catch(...)
    {
        try
        {
            cout<<"总是抛出异常"<<"\n";
            throw;
        }
//        catch(int )
//        {
//              cout<<"int"<<"\n";
//        }
        catch(double )
        {
              cout<<"double"<<"\n";
        }
    }








    cout << "Hello World!" << endl;
    return 0;
}

