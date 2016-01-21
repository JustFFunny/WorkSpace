#include <stdio.h>
#include <iostream>
#include "smartptr.h"
//#include "ptr.h"
int main()
{
    //////////////befor Test////////////////
    cout << "Hello World!" << endl;
//非模板类通过
//    //SmartPtr _p(NULL);
//    string *_ptr =new string();
//    SmartPtr _testPtr(_ptr);
//    cout<<"\n---------------next-----------"<<endl;
//    SmartPtr _testPtr2;
//    _testPtr2=_testPtr;
//    cout<<"\n---------------析构-----------\n";

//模板类
    string *_p=new string();
    SmartPtr<string> _s(_p);

    return 0;
}

