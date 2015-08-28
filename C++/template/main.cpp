//#include <iostream>
//#include <string>
////1. 覆盖
////2.成员初始化列表   要比在构造函数赋值 里面 好, 对于 内置的数据成员一样,所以主要是要求格式一直性;
////            对于用户自定义类型, 赋值操作 会自动调用 自定义类型的default构造函数;开销大,还是无用工作.
////3. 防止调用 编译器自己生成的 默认构造函数 copy函数 assign函数 ,可以把他们呢设为 private 且只有声明 没有实现
////                          方法2:创建基类 ,且把基类 设置的coPy assign函数 设为private的,当创建子类的时候,调用基类的copY函数,编译报错
//using namespace std;
//class Con
//{
//public:
//    Con(){cout<<"Construct1 \n";}
//    Con(const string & name,int  num){m_name=name;m_num=num; cout<<"Construct 2\n";}
//    //    Con( const Con & name)
//    //    {myMessageHandle
//    //    }

//private:
//    Con( const Con & );


//    string m_name;
//    int m_num;
//};

////class  Parent
////{
////public:
////    Parent() {}
////    //Parent() {cout<<"construct Fun\n";}
////    // Parent( const Con & name ) {  cout<<"Fun\n";}
////    Parent( const Con & name )
////        :m_com(name)
////    {  cout<<"Fun\n";}
////    void fell()
////    {
////        cout<<"parent\n";
////    }
////private:
////    Con m_com;

////};
////class Devid:public Parent
////{
////public:
////    Devid(){};
////    void fell()
////    {
////        cout<<"Devid\n";
////    }
////};




//int main()
//{
//    //    Parent * p;
//    //    p=new Devid;
//    //    p->fell();

//    // Parent _parent(Con(string("nn"),10));
//    Con con("name",1);
//    Con bcon(con);// error: Con::Con(const Con&)' is private
//    cout << "Hello World!" << endl;
//    return 0;
//}

/*
 *QQ群里解决的
 **/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

//int a[100],L;
//char s[100];

//void print(int *a)
//{
//     int tmp=a[0]%2,i;
//     a[0]-=tmp;
//     for (i=L-1; i>=0; i--)
//     {
//         if (a[i]%2==1)
//         {
//                       a[i]--; a[i-1]+=10;
//         }
//         a[i]/=2;
//     }
//     while (a[L-1]==0 && L>1) L--;
//     if (L>1 || a[L-1]>0) print(a);
//     printf("%d",tmp);
//}

//void change(char *s,int *a)
//{
//     L=strlen(s);
//     int i;
//     for (i=0; i<L; i++) a[i]=s[L-1-i]-'0';
//}

//int main()
//{
//    printf("Input a Number(<=10^100:");
//    gets(s);    //读入
//    change(s,a);   // 把s中的字符转化为数字存进数组a里
//    print(a);
//    printf("\n");

//    system("pause");
//    return 0;
//}

#include <iostream>
#include <stdlib.h>
#include <new>
using namespace std;
// 内存分配不足的情况下,会调用 函数std::set_new_handler(outofMempry);
void outofMempry()
{
    std::cerr<<"out of mempry\n";
    abort();
}

int main()
{
    std::set_new_handler(outofMempry);
    while(1)
    {
        int *p =new int[100000000000000];

    }
}
