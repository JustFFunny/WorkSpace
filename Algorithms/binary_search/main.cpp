/*二分查找
 *1.首先元素是有序的,且查找的关键字在待查找的内容中是唯一的.
 **/
#include <iostream>
#include <cmath>

using namespace std;
template <typename T>
int binary_search(T *p,int low,int high,int var)
{
    if(low<= high)
    {
        int mid=floor(low+high);
        //递归
        if(var==p[mid])
        {
            cout<<"find success:"<< mid<<"\n";
            return mid;
        }
        else if(var>p[mid])
        {
            binary_search(p,mid+1,high,var);
        }
        else if(var<p[mid])
        {
             binary_search(p,low,mid-1,var);
        }
    }
    else
    {
        cout<<"find failed:"<< "\n";
        return -1;
    }

}

int main()
{
    int array[]={2,4,5,8,9,14,266,546};
    binary_search(array,0,7,13);
    cout << "Hello World!" << endl;
    return 0;
}

