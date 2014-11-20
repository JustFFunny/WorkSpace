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

    cout << "Hello World!" << endl;
    return 0;
}

