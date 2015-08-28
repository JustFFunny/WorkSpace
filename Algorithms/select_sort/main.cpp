/*
 *选择排序  一趟就是选择一个最大的数
 **/
#include <iostream>

using namespace std;
template <typename T>
void display(T *p,int num)
{
    for(int k=0;k<num;++k)
    {
        cout << p[k]<<" ";
    }
    cout<<"\n";
}
template <typename T>
void select_sort(T * p,int num )
{
    for(int i=0;i<num;++i)
    {
        int var;
        T maxvar=p[0];//找到最大值,放到后面
        for(int j=0;j<num-i;++j)
        {
            if(p[j]>=maxvar)
            {
                maxvar=p[j];
                var=j;
            }
        }
        //最大值
        cout<< maxvar<<"\n";
        T temp=p[var];
        p[var]=p[num-i-1];
        p[num-i-1]=temp;
    }
}

int main()
{
    int array[]={20,2,10,3,8,23};
    select_sort(array,6);
    display(array,6);
    cout << "Hello World!" << endl;
    return 0;
}

