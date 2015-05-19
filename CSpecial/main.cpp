*test one//
 *test two//
 **/
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include "ExternTest.h"
using namespace std;
//extern const double pi;

int main()
{
    int a=10;
    int& b=a;
    cout << &a << endl;
    cout << &b << endl;
    cout << pi << endl;
    cout << "Hello World!" << endl;

    return 0;
}

