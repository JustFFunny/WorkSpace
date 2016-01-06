#include <iostream>

using namespace std;
template <typename T1,typename T2>
T1 Sum(T1 _t1,T2 _t2)
{
    return _t1+_t2;
}

//C++0x,该该版本不支持
//template <typename T1,typename T2>
// auto dec(T1 _t1,T2 _t2) -> decltype(_t1 -_t2)
//{
//    return _t1-_t2;
//}

int main()
{
    cout << "Hello World!" << endl;
    cout<<Sum<int,double>(1,1.2)<<endl;
    cout<<Sum<double,int>(1.2,1)<<endl;
    return 0;
}

