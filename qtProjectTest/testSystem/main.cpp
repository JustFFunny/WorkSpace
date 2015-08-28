//linux 密码的验证  root   quanxian

#include <QDebug>

#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <shadow.h>
#include <netinet/in.h>
#define _XOPEN_SOURCE
//int main(int argc, char *argv[])
//{
//   // QApplication a(argc, argv);
//    char *username="root";
//    struct passwd * pw;
//    pw=getpwnam(username);//getpwnam函数功能是获取用户登录相关信息。
//    if(!pw)
//    {
//        qDebug()<<"this user isnot exist";

//    }
//    qDebug()<<"user"<<pw->pw_name;
//    qDebug()<<"user"<<pw->pw_passwd;//  x  加密啦
//   // return a.exec();
//    return 0;
//}
//#pragme comment (lib, "cryptlib");
int  main(int argc, char *argv[])

{

    //得到当前应用程序的UID
    uid_t uid,euid,guestuid;//运行程序的  / root程序的  普通用户的


    euid =geteuid();//获取此程序所有者的UID
    uid=getuid();//获得运行程序的当前账户的uid


    char user[40]="root";
    char password[40]="123456";
    const char *cpwd = NULL;
    struct passwd *pw;
    struct spwd *spw;
    char *crypt_pw;
    pw=getpwnam(user);
    //setreuid();
    if(pw)
    {
        if ((((pw->pw_passwd)[0] == 'x' && (pw->pw_passwd)[1] == 0) ||
             ((pw->pw_passwd)[0] == '#' && (pw->pw_passwd)[1] == '#' &&
              strcmp(pw->pw_passwd + 2, user) == 0)) &&
                (spw = getspnam(user)) != NULL && spw->sp_pwdp != NULL)
        {
            cpwd = spw->sp_pwdp[0] == '@' ? NULL : spw->sp_pwdp;
        }
        else
        {
            cpwd= pw->pw_passwd;
        }

        crypt_pw = crypt(password,cpwd);

       // qDebug()<<cpwd;
        qDebug()<<"hello world 2015\n";
        //qDebug()<<crypt_pw;
        if (strcmp(cpwd,crypt_pw)==0)
        {
            printf("Success!\n");
        }
        else
        {
            printf("Password is not correct!\n");
            return 0;
        }
    }
    else
    {
        printf("Unknown User!\n");
        return 0;
    }
}
