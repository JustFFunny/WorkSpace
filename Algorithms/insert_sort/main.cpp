/*
 *insert_sort
 **/
#include <iostream>
#include <stdio.h>
using namespace std;

void display(int *p,int num)
{
    for(int i=0;i<num;++i)
    {
        cout<<p[i]<<" ";
    }
    cout <<"\n";
}

int main()
{

    int array[]={1,100,33,21,88,20,67,33,87,48};
   size_t num= sizeof(array)/sizeof(int);
   cout << num<<"\n";
 /*
   //test 升序
   for(int j=1;j<num;++j)
    {
        int var=array[j];
        cout<<var<<"\n";
        int i=j-1;
        while(i>0 && var < array[i] )
        {
            array[i+1]=array[i];
            --i;
        }
        array[i+1]=var;
    }
    display(array,num);
  */
   //test2 降序
   for(int m=1;m<num;++m)
   {
       int var=array[m];
       int n=m-1;
       while(n>=0 && var > array[n])
       {
           array[n+1]=array[n];
           --n;
       }
       array[n+1]=var;
   }
    display(array,num);

    cout << "Hello World!" << endl;
    return 0;
}

