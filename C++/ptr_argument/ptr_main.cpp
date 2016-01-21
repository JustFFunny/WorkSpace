/*test
 * int *p;
 * int *p[10];//指针数组
 *
 *
 * int (*p)[10];//数组指针  p是一个指针，指向一个数组。
 * eg:
 * {
 *   int a[4][5];
 *   int (*p)[5]=a;
 * }
 * 这里a是个二维数组的数组名，相当于一个二级指针常量；
 * p是一个指针变量，它指向包含5个int元素的一维数组，此时p的增量以它所指向的一维数组长度为单位；
 * *p+i是二维数组a[0][i]的地址;
 * *(p+2)+3表示a[2][3]地址（第一行为0行，第一列为0列），*（*(p+2)+3）表示a[2][3]的值。
 *
*/
#include <iostream>

using namespace std;

int main()
{
    //int(*p)[10] 数组指针  p是一个指针，指向一个数组。
    int a[2][3]={1,2,3, 11,22,33};
    int (*p)[3]=a;
    cout<<(*p)[2]<<endl;
    cout << "Hello World!" << endl;
    int (*ptr)[3]=&(a[1]);
    cout<<(*ptr)[2]<<endl;

    cout<<"another userMothed";
    int *pp;
    pp= & (a[0][0]);
    for(int row=0;row<2;++row)
    {
        for(int column=0; column<3;++column )
        {
            cout<<*(*(p+row)+column)<<endl;
        }
    }

    cout<<"\n\n*************\n\n";
    // int *p[10]指针数组 且［］的优先级大于 *，表示p是一个指针，指向含有10个指针的数组
    //定义 指针 p[0],p[1].....p[10]
    int var=100;
    int *pa[2];
    pa[0]=&var;//指向同一个地址
    pa[1]=&var;
    cout<<*pa[0]<<endl;
    cout<<*pa[1]<<endl;

    *pa[0]=*pa[0]+1;
    cout<<*pa[0]<<endl;
    cout<<*pa[1]<<endl;

    int *prta[2];
    prta[0]=a[0];
    prta[1]=a[1];

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<3;++j)
        {
            cout<<prta[i][j]<<endl;//right
            cout<<*(*(prta+i)+j)<<endl;//right
            cout<<*(prta[i]+j)<<endl;//right

            cout<<"\n";
        }
    }


    return 0;
}

