#ifndef TEST_H
#define TEST_H
#include <QString>
class Test
{

public:
    Test(){j=0;i=0;};
    Test(int m,int n){j=1;i=1;};
    Test getJ();\
    void get();
private:
    int j;
    int i;

};

#endif // TEST_H
