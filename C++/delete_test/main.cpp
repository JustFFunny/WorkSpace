//#include <iostream>
//#include <string>
//using namespace std;


//int main()
//{
////    string * str=new string("helloWorld");
////    string * strArray=new string[10];
////    delete str;
//    return 0;
//}

#include <stdio.h>
#include <iostream>
#if 0
所以写的时候,要注意清晰的表达;
#else if 1
#endif
int main()
{
int b = 3;
int arr[] = {6, 7, 8, 9, 10};
int *ptr = arr;
*(ptr++) += 123;
printf("%d\n", *ptr);
printf("%d, %d\n", *ptr, *(++ptr));
printf("***************" );
for(int k=0;k<4;++k)
{
    printf("%d\n",arr[k]);
}
}
