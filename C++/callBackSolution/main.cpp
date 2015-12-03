/*
*@Title:
*回调函数就是一个通过函数指针调用的函数。
*如果你把函数的指针(地址)作为参数传递给另一个函数，
*当这个指针被用为调用它所指向的函数时，
*我们就说这是回调函数。
*回调函数不是由该函数的实现方直接调用，
*而是在特定的事件或条件发生时由另外的一方调用的，
*用于对该事件或条件进行响应。
*@author  :wuqiankun
*@mail    :qiankun@nfschina.com
*/

#include <iostream>

#include "Class.h"
#include "SingularCallBack.h"
using namespace std;



/*
class AClass
{
   public:

     AClass(unsigned int _id): id(_id){};
    ~AClass(){};

     bool AMethod(std::string str)
     {
        std::cout << "AClass[" << id << "]: " << str << std::endl;
        return true;
     };

   private:

    unsigned int id;

};


typedef SingularCallBack < AClass, bool, std::string > ACallBack;


int main()
{

   std::vector < ACallBack > callback_list;

   AClass a1(1);
   AClass a2(2);
   AClass a3(3);

   callback_list.push_back(ACallBack(&a1, &AClass::AMethod));
   callback_list.push_back(ACallBack(&a2, &AClass::AMethod));
   callback_list.push_back(ACallBack(&a3, &AClass::AMethod));

   for (unsigned int i = 0; i < callback_list.size(); i++)
   {
      callback_list[i]("abc");
   }

   for (unsigned int i = 0; i < callback_list.size(); i++)
   {
      callback_list[i].execute("abc");
   }

   return true;

}
*/
int main()
{
    cout << "Hello World!" << endl;

  //test 1
//    A a;
//    B b;

//    SingularCallBack< B,bool,A >* cb;
//    cb = new SingularCallBack< B,bool,A >(&b,&B::methodB);

//    if((*cb)(a))
//    {
//       std::cout << "CallBack Fired Successfully!" << std::endl;
//    }
//    else
//    {
//       std::cout << "CallBack Fired Unsuccessfully!" << std::endl;
//    }

//    //test2
    cout<<"test2\n";
    A a;
    B b;

    SingularCallBack< B,bool,A >* cb;
    cb = new SingularCallBack< B,bool,A >(&b,&B::methodB);

    if(cb->execute(a))
    {
       std::cout << "CallBack Fired Successfully!" << std::endl;
    }
    else
    {
       std::cout << "CallBack Fired Unsuccessfully!" << std::endl;
    }


////test 3

//    A a;
//    B b;
//    SingularCallBack< B,bool,A >cb(&b,&B::methodB);

//    if(cb(a))
//    {
//       std::cout << "CallBack Fired Successfully!" << std::endl;
//    }
//    else
//    {
//       std::cout << "CallBack Fired Unsuccessfully!" << std::endl;
//    }


    return 0;
}

