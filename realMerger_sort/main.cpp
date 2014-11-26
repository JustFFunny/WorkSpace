
#include <iostream>
#include <stdio.h>
#include <math.h>

#include <unistd.h>
#include <crypt.h>
using namespace std;


void display(int *p,int num)
{
    for(int k=0;k<num;++k)
    {
        cout << p[k]<<" ";
    }
    cout<<"\n";

}

void merger_sort(int *p,int num)//数组是偶数
{
    int ichildFNum= floor(num/2) ;//下取整
    int ichildSNum=num-ichildFNum;
    int ichildF[ichildFNum],ichildS[ichildSNum];
    //    for(int k=0;k<ichildNum;++k)
    //    {
    //        ichildF[k]=p[k];
    //        ichildS[k]=p[k+ichildNum];
    //    }
    for(int k=0;k<ichildFNum;++k)
    {
        ichildF[k]=p[k];
    }
    for(int k=0;k<ichildSNum;++k)
    {
        ichildS[k]=p[k+ichildFNum-1];
    }

    //排序 array
    int i=0,j=0,k=0;
    for(;(i<ichildFNum && j<ichildSNum);)
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
    for(;i<ichildFNum;++i)
    {
        p[k]=ichildF[i];
        ++k;
    }
    for(;j<ichildSNum;++j)
    {
        p[k]=ichildS[j];
        ++k;
    }
    return;
}
template <typename T>    //firNum 第一段起始位   secNUm 第二段结束位置
void newMerger_sort(T* array,size_t firNum,size_t midNum,size_t secNum)
{
    T fchildP[midNum-firNum+1];T schildP[secNum-midNum];
    cout<<"fir"<<"\n";
    int k=0;
    for(int i=firNum;i<=midNum;++i,++k)
    {
        cout<<array[i]<<"\n";
        fchildP[k]=array[i];
    }
    cout<<"\n";
    cout<<"sec"<<"\n";
    int l=0;
    for(int j=midNum+1;j<=secNum;++j,++l)
    {
        cout<<array[j]<<"\n";
        schildP[l]=array[j];
    }
    int m=0,n=0;size_t var=firNum;
    cout<<"three"<<"\n";
    for(;(m<(midNum-firNum+1)) &&(n< (secNum-midNum));var++)
    {
        if(fchildP[m]<schildP[n])
        {
            cout<<"one"<<fchildP[m]<<" ";
            array[var]=fchildP[m];
            m++;
        }
        else
        {
            cout<<"two"<<schildP[n]<<" ";
            array[var]=schildP[n];//我的问题出在这里, 都写成了Fchild
            n++;

        }
    }
    //如果有一个 已经排序完啦,
    for(;m< midNum-firNum+1;++m)
    {
        array[var]=fchildP[m];
        ++var;
    }
    for(;n< (secNum-midNum) ;++n)
    {
        cout<<"last"<<schildP[n]<<"\n";
        array[var]=schildP[n];
        ++var;
    }

}

void merger(int *array ,int firNum,int secNum)//递归
{

    for(int i=firNum;i<= secNum;++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    int  _tempVar;
    if(firNum<secNum)//递归退出条件
    {
        _tempVar=(firNum+secNum)/2;
        merger(array,firNum,_tempVar);//递归 分解前半序列
        merger(array,_tempVar+1,secNum);//递归 分解后半序列
        newMerger_sort(array,firNum,_tempVar,secNum); //对序列进行合并
    }
    else
    {
        cout<<"推出"<<"\n";
    }
}

int main()
{
    int array[]={1,4,90,100, 3,10,45,234};
    merger(array,0,7);
    // newMerger_sort(array,0,3,7);
    display(array,8);


    cout << "Hello World!" << endl;
    return 0;
}

