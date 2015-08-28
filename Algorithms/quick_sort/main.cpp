/*
 *快速排序是通过一趟排序将要排序的数据分割成独立的两部分，
 *其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对
 *这两部分数据分别进行快速排序，整个排序过程可以递归进行，
 *以此达到整个数据变成有序序列
 **/
#include <assert.h>
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
//一次快速排序
int quick_sort(int *p,int low,int high)
{
    int var=p[low];
    while(low <high)
    {
        while(var<p[high] && (low<high))
        {
            high--;
        }
        //替换
        p[low]=p[high];
        while(var>=p[low] && (low<high))
        {
            low++;
        }
        //替换
        p[high]=p[low];
    }
    cout<<"高低wei:"<<low<<"  "<<high<<"  "<<var<<"\n";
    p[low]=var;
    cout<<"hello buddy!\n";
    return low;
}
void sort(int *p,int low,int high)
{
    if(low<high)
    {
        int _pos=quick_sort(p,low,high);
        cout<<"_pos:"<<_pos<<"\n";
        sort(p,low,_pos-1);
        sort(p,_pos+1,high);
    }

}


int main()
{
    int array[]={10,2,33,99,0,111,0,44};
    //int _fpos= quick_sort(array,0,7);
    sort(array,0,7);

    cout << "Hello World!"<<  endl;
    display(array,8);
    return 0;
}

