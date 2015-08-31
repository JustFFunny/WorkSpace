#include <QCoreApplication>
#define NDEBUG
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <QDebug>
#include <string>
#include <iostream>
#include <QString>
//strlen(...)是函数，要在运行时才能计算。参数必须是字符型指针（char*）。当数组名作为参数传入时，实际上数组就退化成指针了。
//它的功能是：返回字符串的长度。该字符串可能是自己定义的，也可能是内存中随机的，该函数实际完成的功能是从代表该字符串的第一个地址开始遍历，直到遇到结束符NULL。返回的长度大小不包括NULL。
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString _name="b";
    QString _command=QString("\"") +QString("\"") ;
    QString _file=QString("%1").arg("1111");
    qDebug()<<_file<<"this"<<_command;
// "adb push /home/wuqiankun/文档/adb介绍和使用.wps /sdcard/""
    //char str[]="Hello";
     string strH="hello";
     cout<<"niiiiii"<<strlen(strH.c_str())<<":"<<strH.size()<<":"<<sizeof(strH)<<"\n";
    char *str=const_cast<char *>(strH.c_str());
    cout<<"NICE:"<<sizeof(str)<<"\n";
    int i=0;
    while(i<sizeof(str))
    {
        cout<<str[i]<<"\n";
        if(!str[i])
        {
            cout<<"空";
        }
        i++;
    }

    cout <<"分割线";
    int j=0;
    assert(j!=0);
    //string  转换 char *    char*  转换qstring
    std::string str1 = "this is a string";
    char* str2 = const_cast<char*>(str1.c_str());//const_cast去掉const
    qDebug()<<"1:"<<QString(str2);
    //string 转 char*  转 qstring
    std::string str3="this is a string 2";
    qDebug()<<"2:"<<QString(str3.c_str());

    //char * 转String        const char * 转string
    char * str4="this is a test 3";
    std::string str5(str4);
    const char * str6 ="this is a test 4f";
    std::string str7 (str6);
    //QString 转 const char *转char *
    QString str8="this is a test 5";
    char * str9=const_cast<char *>(str8.toStdString().c_str());
    //char * 转const char *
    char * str10="thisischar*";
    const char * str11(str10);//11个字符  字符的个数
    cout<<"hello"<< strlen(str11) ;
    bool _status=-1;
    qDebug()<<QString::number(_status);


    //test last
    cout << "------华丽丽的分隔符----------" << endl;
    char *p = "Test";

    cout << &p << endl;
    cout << p << endl;
    cout << *p << endl;
    cout << p[0] << endl;
    /*结果为:
     指针p的地址
     Test
     T
     T
     */



    //    void *q =const_cast<char *>("Test");
    //    cout << &q << endl;
    //    cout << q << endl;




    return a.exec();
}

/*

                command = "adb push "+ QString("\"")+ file.filePath +QString("\"") +" " +\
                        codec->toUnicode(this->targetPath.toUtf8());
                if(file.fileName.contains(":"))
                {
                    QString _tempfile(file.fileName);
                    _tempfile.replace(":","_");
                    command +=_tempfile;
                }
  */
