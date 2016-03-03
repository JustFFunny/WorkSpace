#include <QCoreApplication>
#include <boost/timer.hpp>

#include <QDebug>
#include <iostream>
#include <memory>
using namespace::std;
//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);
//    boost::timer tmr;

//     qDebug() << tmr.elapsed() << "S" << endl;

//    return a.exec();
//}






//test2    scoped_ptr
//当一个指针离开其作用域时候，释放相关资源。
//特别注意的一定就是scoped_ptr 不能共享指针的所有权也不能转移所有权。
//也就是说这个内存地址就只能给的声明的变量用，不能给其他使用。
/*
下面是scoped_ptr的几个特点：
1.scoped_ptr的效率和空间的消耗内置的指针差不多。
2.scoped_ptr不能用在标准库的容器上。(用shared_ptr代替)
3.scoped_ptr不能指向一块能够动态增长的内存区域(用scoped_array代替)
*/
/*
#include <boost/scoped_ptr.hpp>

class test
{
public:
    ~test(){cout<<"destructor\n"<<;}
    void print()
    {
        cout << " test print now" <<endl;
    }
};

int main(int argc, char *argv[])
{
    {
        boost::scoped_ptr<test> x(new test);
        x->print();
    }      // 指针离开其作用域时候，释放相关资源
    cout<<"end\n";
    return 0;
}
*/

/*
//test3 shared_ptr
指针指向同一个内存
 *  shared_ptr 具有如下几个特点：
    1.在内部维护一个引用计数器， 当有一个指针指向这块内存区域是引用计数+1， 反之-1，
    如果没有任何指针指向这块区域， 引用计数器为0，释放内存区域。
    2.可以共享和转移所有权。
    3.可以被标准库的容器所使用
    4.不能指向一块动态增长的内存(用share_array代替)
    //打印数字只是为了验证：是不是指向同一个对象

class test
{
public:
    test():i(1){}
    ~test(){cout<<"destructor\n";}
    void print()
    {
        cout<<i;
        cout << " test print now" <<endl;
    }
    void add()
    {
        cout<<++i<<"\n";
    }

private:
    int i;
};
#include <boost/shared_ptr.hpp>
int main(int argc, char *argv[])
{
    {
        boost::shared_ptr<test> ptr1(new test);
        ptr1->print();
        ptr1->add();
        boost::shared_ptr<test> ptr2=ptr1;
        ptr2->print();
    }   // 指针离开其作用域时候，释放相关资源
    cout<<"end\n";
    return 0;
}

*/

//test4
//weak_ptr被设计为与shared_ptr共同工作，可以从一个shared_ptr或者另一个weak_ptr对象构造，获得资源的观测权。
//但weak_ptr没有共享资源，它的构造不会引起指针引用计数的增加。即
//weak_ptr在使用中不会修改对应shared_ptr指针的引用计数值，也没有对“*”和“->”进行重载.
//weak_ptr::expired() ：返回当前引用计数是否为0的Bool值（use_count() == 0），即当前weak_ptr所指向的shared_ptr是否可用。
//weak_ptr::lock() ：若weak_ptr所指向的shared_ptr指针可用则将其返回，否则返回一个指向NULL的shared_ptr。
/*（
   expired()? shared_ptr<T>(): shared_ptr<T>(*this)
）
*/


//weak_ptr 就是一个弱指针。weak_ptr 被shared_ptr控制，
//它可以通过share_ptr的构造函数或者lock成员函数转化为share_ptr。
//weak_ptr的一个最大特点就是它共享一个share_ptr的内存，
//但是无论是构造还是析构一个weak_ptr 都不会影响引用计数器
/*
solve the question:
1.(解决循环引用问题) slove the each other refer's question.
2.保存对象的this指针
*/
#include <boost/weak_ptr.hpp>
class test
{
public:
    void print()
    {
        cout << "test print now" <<endl;
    }

};
int main(int argc, char *argv[])
{
    /*
    boost::shared_ptr<test> sharePtr(new test);
    qDebug()<< (sharePtr.use_count())<<"\n";
    boost::weak_ptr<test> weakPtr(sharePtr);//
    qDebug()<< (sharePtr.use_count())<<"\n";
    //weakPtr 就是用來保存指向這塊內存區域的指針的
    //干了一大堆其他事情
    boost::shared_ptr<test> sharePtr_2 = weakPtr.lock();//lock成员函数转化为share_ptr
     qDebug()<< (sharePtr.use_count())<<"   "<<(sharePtr_2.use_count())<<"\n";
    if (sharePtr_2)
        sharePtr_2->print();
    return 0;
    */

    boost::shared_ptr<test> po(new test);
    cout<<po.use_count()<<"\n";//1
    boost::shared_ptr<test> po2(po);
    cout<<po.use_count()<<po2.use_count()<<"\n";//2  2
    boost::shared_ptr<test> po3(po);
    cout<<po.use_count()<<po2.use_count()<<po3.use_count()<<"\n";//3  3 3
    boost::shared_ptr<test> po4(po);
    cout<<po.use_count()<<po2.use_count()<<po3.use_count()<<po4.use_count()<<"\n";//4  4 4 4
    //new
    boost::shared_ptr<test> newPtr(new test);
    cout<<newPtr.use_count()<<"\n";//1

    //assigen  share_ptr被复制"新值"时，原引用对象将被减一1.out of sope -1&& destructor -1;
    po=newPtr;
    cout<<po.use_count()<<po2.use_count()<<po3.use_count()<<po4.use_count()<<newPtr.use_count()<<"\n";//23332
    //

    po.reset();//丢弃掉原来所指的对象（或者让其引用计数减 1）
    cout<<po.use_count()<<newPtr.use_count()<<"\n";//0 1

}





