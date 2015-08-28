#include <iostream>
//隐式类型转化操作符   以及  单变量构造函数
//允许编译器 执行隐式类型转换
using namespace std;

class Ration
{
public:
    Ration(int a,int b):m_font(a),m_back(b)
    {
    }

    operator double() const
    {
        return m_font*m_back*1.000;
    }
private:
    int m_font;
    int m_back;

};

class Name
{
public:
    Name(const string& str)//可以把str转换成Name
    {
        m_str=str;
    }
private:
    string m_str;
};

int main()
{
    Ration r(2.0,3.0);//隐式类型转换 基本类型
    cout<< 6*r<<"\n";//   自动调用 operator double()函数
    cout << "Hello World!" << endl;
    Name _name("abd");//隐士转换 string  -> Name
    return 0;
}

