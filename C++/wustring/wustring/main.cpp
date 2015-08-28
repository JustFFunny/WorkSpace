#include <iostream>
#include "wustring.h"
using namespace std;

int main()
{
//    cout << "Hello World!" << endl;
    WuString t("hello");
    t.diaplay();
    t.size();
    cout<<"t2"<<"\n";
    WuString t2(t);

    cout<<"test 3........"<<"\n";
    WuString t3("!=");
    bool _status=(t3!=t);
    cout<<"!="<<_status<<"\n";
     _status=(t3!=WuString("!="));
    cout<<"=="<<_status<<"\n";


    cout<<"test 4 +++++"<<"\n";
    WuString _t("+++");
    _t+t;
    _t.diaplay();


    cout<<"test 5 +="<<"\n";
    WuString name("test ");
    name+=WuString("this is a test +=");
    name.diaplay();
    return 0;
}

