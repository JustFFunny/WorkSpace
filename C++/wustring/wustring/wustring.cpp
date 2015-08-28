#include "wustring.h"
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <byteswap.h>
using namespace   std;

WuString::WuString(const char * str)
{
    if(!str)
    {
//        m_date=0;
        m_date=new char[1];
        *m_date='\0';
    }
    else {
        m_date= new char[Wu_strlen(str)+1];
        Wu_strCopy(m_date,str);
        //strcpy(m_date,str);
        cout<<"construct"<<*m_date<<"\n";
        diaplay();
    }
}
  WuString::~WuString()
{
      delete m_date;
}

WuString::WuString(const WuString & other)
{
    if(!other.m_date)
    {
        m_date=0;
    }
    else
    {//在类的成员函数内可以访问同种对象的私有成员（同种类肯定是友元关系）
        delete m_date;
        m_date= new char[Wu_strlen(other.m_date)+1];
        Wu_strCopy(m_date,other.m_date);
       // diaplay();
    }

}

size_t WuString::size()
{
    cout<<"length:"<<Wu_strlen(m_date)<<"\n";
    return Wu_strlen(m_date);
}

int WuString::Wu_strlen(const char * str)
{
    if(str==0)
    {
        return -1;
    }
    else
    {
        size_t length=0;
        while(*str!='\0')
        {
            //cout<<*str<<"\n";
            ++str;
            ++length;
        }
        cout<<length<<"\n";
        return length;
    }

}

char * WuString::Wu_strCopy(char * des,const char * source)
{
    assert(des!=0);//当des==0 断言错误
    assert(source!=0);
    char * _temp=des;
    memcpy(des,source,Wu_strlen(source)+1);
    return  _temp;
}
void WuString::diaplay()
{
    cout<<"显示开始"<<"\n";
    char *temp=new char[strlen(m_date)+1];
    strcpy(temp,m_date);
    while((*temp)!='\0')
    {
        cout<<*temp;
        ++temp;
    }
    cout<<"\n";
    cout<<"显示jieshu"<<"\n";
    delete temp;
}


bool WuString::operator !=(const WuString & str)
{
    if(Wu_strlen(str.m_date)!=Wu_strlen(this->m_date))
    {
        return true;
    }
    return strcmp(str.m_date,this->m_date)?true:false;
}

bool WuString::operator ==(const WuString & str)
{
    if(Wu_strlen(m_date)!=Wu_strlen(str.m_date))
    {
        return false;
    }
    return  strcmp(m_date,str.m_date)?false:true;
}
WuString & WuString::operator +(const WuString &other)
{
    char* temp= strcat(this->m_date,other.m_date);
    delete m_date;
    m_date=new char[Wu_strlen(temp)+1];
    strcpy(m_date,temp);
    delete temp;
    return *this;
}
WuString WuString::operator +=(const WuString & str)
{
    strcat(m_date,str.m_date);
    return *this;
}

//void WuString::Wu_memcopy(void * pto,const void * pfrom,size_t size)
//{
//    assert(pto!=NULL);
//    assert(pfrom!=NULL);
//    byte *pbto= (byte *)pto;
//    byte *pbfrom=(byte *)pfrom;
//    while(size-->0)
//    {
//        *pbto++=*pbfrom;

//    }
//   return pto;
//}


WuString & WuString::operator =(const WuString & str)//赋值构造函数
{
    //自检测
    if(this==&str)
    {
        return *this;
    }
    //释放资源
    delete []m_date;

    strcpy(this->m_date,str.m_date);
    return *this;
}
