/*环境变量是: 是为程序运行设置的环境,为程序提供配置信息,
 *同时具有继承性,继承调用该函数的环境变量
 *eg: linux shell 中运行程序
 *直接表现为:
 *   环境变量,就是在CMD DOS 或者shell 中可以不切换到路径直接运行的
 *用来表示标识的一种形式；主要表在  "变量=值",环境变量的变量都是大写
 *eg:QTDIR=C:\qt_4.0\;
 *
 *另注意在Windows 中 环境变量之间 是以 "分号 "为分割的;
 *设置环境变量重启电脑,如果在dos中设置 值,当dos结束的时候,环境只是局部的
 *
 *
 *在linux中是 以 "冒号"进行分割  getenv  setenv  unsetenv
 访问所有的 环境变量 可以用
 **/
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

extern  char ** environ;//包含了整个环境变量
//extern 是指明 这个变量在其他地方已经定义了,在这里引用(一般为全局变量)
int main()
{
    /*
    //test1 遍历所有的 环境变量值
    char **var(environ);
    for(; *var!=NULL; var++ )
    {
        cout<< *var <<"\n";
    }
    */

    //test2 设置
    setenv("SERVER_EMAIL","Hello ENV",0);

    // test3 环境变量的获取
    char * server_env=getenv("SERVER_EMAIL");
    if(!server_env)
    {
        server_env="wqiankun89@163.com";
        cout << "SERVER_email don't exist" << endl;
    }
    else
    {
         cout << "SERVER_email  exist" << endl;
         cout <<   server_env <<"\n";
    }


    return 0;
}

