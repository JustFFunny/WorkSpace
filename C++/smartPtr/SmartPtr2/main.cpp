#include <iostream>
#include "test_smartptr.h"
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    try
    {
        SmartPtr<Stub>t;
        t->print();
    }
    catch(const exception &err)
    {
        cout<<err.what()<<endl;
    }
    cout<<"\n......................\n";

    SmartPtr<Stub>t1(new Stub);
    SmartPtr<Stub>t2(t1);
    SmartPtr<Stub>t3(new Stub);
    t3=t2;
    t1->print();
    (*t3).print();
    return 0;

}

