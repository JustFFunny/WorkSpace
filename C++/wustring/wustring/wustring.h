#ifndef WUSTRING_H
#define WUSTRING_H
#include <stdio.h>
#include <iostream>
using namespace std;
//拷贝构造函数是在对象被创建时调用的,而赋值函数只能被已经存在了的对象调用。
/* string a("hello");//拷贝构造函数
 * string b("world);
 * string c=a;//调用拷贝构造函数  写c(a);比较好
 *        c=b;//调用赋值函数
 *
 */
class WuString
{
public:
    //    WuString();
    WuString(const char * str=NULL);
    ~WuString();
    WuString(const WuString & other);//拷贝构造函数
    WuString & operator +(const WuString &other);
    bool operator !=(const WuString & str);
    bool operator ==(const WuString & str);
    WuString operator +=(const WuString & str);

    WuString & operator =(const WuString & str);//赋值函数
    size_t size();

    //==  += 赋值构造 !=    []  +  size  =
    int Wu_strlen(const char * str);
    char * Wu_strCopy(char * des,const char * source);
    //    void Wu_memcopy(void * pto,const void * pfrom,size_t size);
    void diaplay();
private:
    char * m_date;
};
#endif // WUSTRING_H
