#include <QCoreApplication>
#include "base.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*如果基类的 析构函数不是 virtual  ,
     *则当用一个基类的指针删除一个派生类的对象时，派生类的析构函数不会被调用。
     *
     Base construct!
     Devried construct!
     Devried dome Something!
     Base ~~~~construct!
     *
     如果基类的析构函数是virtual ,
     用一个基本的指针去删除子类的对象事,派生类的析构函数会被调用

    Base construct!
    Devried construct!
    Devried dome Something!
    Devried ~~~~construct!
    Base ~~~~construct!

     *
     *
     */

    //    //test sizeof
    //    std::string _tempName ="hello";
    //    std::cout<<sizeof(_tempName.c_str())<<"String _sizeof445" <<sizeof(_tempName)<<"\n"<<_tempName.size();
    //    char * _test="hello";
    //    std::cout<<strlen(_test)<<"char *_ sizeof" <<sizeof(_test)<<"\n";//预测:5 ,4

    //    //test
    //    std::string _name="x";
    //    if(_name[1]=='\0')
    //    {
    //        std::cout<<"string以\\0结尾"<<":"<<sizeof(_name)<<"\n";
    //    }
    //    else
    //    {
    //        std::cout<<"string不以\0结尾"<<"\n";
    //    }

    //    //test 1  基类的虚析构的使用  virtual
    //    Base * _base=new Devrived();
    //    _base->doSome();
    //    Devrived * _deriver=(Devrived*)_base;
    //    _deriver->doSome();
    //    delete _base;


    //        Base * _base2=new Base();
    //        _base2->doSome();
    //        _base2->hello();
    //        _base2->hide(0);
    //        delete _base2;


    //        Devrived * _dev=new Devrived();
    //        _dev->doSome();
    //        _dev->hello();
    //        _dev->hide(0);
    //        delete _dev;

    //  //隐藏
    //    Base * _ptFa=new Devrived;
    //    _ptFa->hide(0);
    //test overload virtual  hide

    /*
    *overload
    *范围:同一个类
    *相同的函数名  参数不同
    *有无关键字Virtual 无关重要


    *覆盖
    *范围 派生类 与基类之间
    *函数名相同 参数相同
    *基类必须有关键字 virtual

    *隐藏
   * *隐藏:是指派生类的函数屏蔽了与其同名的基类函数
   *(1)如果派生类的函数与基类的函数同名,但是参数不同。
   *此时,不论有无 virtual关键字,基类的函数将被隐藏(注意别与重载混淆)
   *(2)如果派生类的函数与基类的函数同名,并且参数也相同,
   *但是基类函数没有 virtual关键字。此时,基类的函数被隐藏(注意别与覆盖混淆)
   *
   *对隐藏的总结就是: 如果基类 和派生类有"相同的函数名"的时候,调用该函数的时候,是什么类型的指针 就调用那个函数.
  */
    std::cout<<"     Test 3"<<"\n";
    Base * _realBase=new Base();
    Devrived * _realDevried=new Devrived;
    Base * _base=new Devrived();


    _realBase->hide(0);
    _realDevried->hide(0);
    _base->hide(0);
    std::cout<<"-----hualifengexian  -----"<<"\n";
    _realBase->hide_2(0);
    _realDevried->hide_2(0);
    _base->hide_2(0);

    return a.exec();
}

