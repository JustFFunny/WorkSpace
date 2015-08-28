/*
 *冒泡排序
 *每趟得到一个 最大的数
 **/
#include <iostream>

using namespace std;
void display(int *p,int num)
{
    for(int k=0;k<num;++k)
    {
        cout << p[k]<<" ";
    }
    cout<<"\n";
}
void bubble_sort(int *p ,size_t num)
{
    for(int i=0;i<num;++i)
    {
        cout<<" 趟数:"<<i<<"\n";
        int var=num-i-1;
        for(int j=0;j<var;++j)
        {
            cout <<p[j]<<":"<<p[j+1]<<"\n";
            if(p[j] >p[j+1] )
            {
                int temp =p[j+1];
                p[j+1]= p[j];
                p[j]=temp;
            }
        }

    }
}

int main()
{
    int array[]={10,9,3,78,33,55,2,44,100,22,31,34,25};
    size_t num=sizeof(array)/sizeof(int);
    bubble_sort(array,num);
    cout << "Hello World!" << endl;
    display(array,num);
    return 0;
}

