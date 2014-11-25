//只是一个 两个数组的比较而已(不是归并排序),
//且两个数组已经排序
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

//第一测试  比较两个已经 数组个数相同  且 已经排序
void merger_sort(int *p,int num)//数组是偶数
{
    display(p,num);
    int ichildNum=num/2;
    int ichildF[ichildNum],ichildS[ichildNum];
    for(int k=0;k<ichildNum;++k)
    {
        ichildF[k]=p[k];
        ichildS[k]=p[k+ichildNum];
    }
    cout<<"first array:"<<"\n";
    display(ichildF,ichildNum);

    cout<<"second array:"<<"\n";
    display(ichildS,ichildNum);

    //排序 array
    int i=0,j=0,k=0;
    for(;(i<ichildNum && j<ichildNum);)
    {
        if(ichildF[i]>ichildS[j])
        {
            p[k]=ichildS[j];
            ++j;
            ++k;
        }
        else
        {
            p[k]=ichildF[i];
            ++i;
            ++k;
        }
    }
    //其中一个已经输出完
    for(;i<ichildNum;++i)
    {
        p[k]=ichildF[i];
        ++k;
    }
    for(;j<ichildNum;++j)
    {
        p[k]=ichildS[j];
        ++k;
    }
    return;
}

int main()
{
     int array[]={2,8,10,200,1,10,99,400};

    size_t num=sizeof(array)/sizeof(int);
    merger_sort(array,num);
    display(array,num);
    cout << "Hello World!" << endl;
    return 0;
}

