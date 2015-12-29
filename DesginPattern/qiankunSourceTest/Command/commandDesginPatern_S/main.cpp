//请求者和 执行者两个之间无耦合关系，(没有关联关系),我们把命令作为一个中间部分来连接，请求者和执行者。
//耦合是指两个或两个以上的电路元件或电网络等的输入与输出之间存在紧密配合与相互影响.

#include <iostream>
#include <list>

using namespace std;
class Command;
class Exector;


//执行者抽象类

//执行者1类

/*
//执行者1类
class Exector1
{
public:
    Exector1() {}
    void exeMethod1()
    {
        std::cout<<"exeMethod1";
    }

    void exeMethod2()
    {
        std::cout<<"exeMethod2";
    }
};

*/

class Exector
{
public:
    Exector() {}
   virtual void exeMethod()
    {
        std::cout<<"\n Exector exeMethod\n";
    }

};


class ExectorSub:public Exector
{
public:
    ExectorSub() {}
    virtual void exeMethod()
    {
        std::cout<<"\nExectorSub exeMethod\n";
    }


};

//命令抽象类 ，那么命令者需要 有请求者 和 执行者。
class Command
{
public:
    Command( Exector* _exector)//:m_exector(_exector){}       //
    {m_exector=_exector;}
    virtual void execute()
    {
        //cout<<"execute Command \n";
        m_exector->exeMethod();
    }

private:
    Exector *m_exector;
};

class conCreateCommand :public Command
{
public:
    conCreateCommand(Exector *_exector):Command( _exector) {}
//    virtual void execute()
//    {
//       cout<<"execute conCreateCommand \n";
//    }



private:
};


//请求者类
class Invoker
{
public:
    Invoker() {}
    void addCommand(Command *_tmp)
    {
        m_commandList.push_back(_tmp);
    }


    void notify()
    {
        list<Command *>::iterator _it=m_commandList.begin();
        for(;_it!=m_commandList.end();_it++)
        {
            (*_it)->execute();
        }
    }

private:
    list<Command *> m_commandList;
};

int main()
{
    cout << "Hello World!" << endl;
    //
    Invoker * _waiter=new Invoker;

    Exector * _exector=new Exector();
    Command * _newCom= new conCreateCommand(_exector);

    _waiter->addCommand(_newCom);
    _waiter->notify();

    cout<<"\n************************\n";
    Exector * _exector2=new ExectorSub();
    Command * _newCom2= new conCreateCommand(_exector2);
    _waiter->addCommand(_newCom2);
     _waiter->notify();


    return 0;
}

