//linux 密码的验证
#define _XOPEN_SOURCE
#include <pwd.h>
#include <sys/types.h>

#include <crypt.h>
#include <shadow.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <unistd.h>

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
int  main()

{

    char user[40]="root";
    char password[40]="123456";
    const char *cpwd = NULL;
    struct passwd *pw;
    struct spwd *spw;
    char *crypt_pw;


    pw=getpwnam(user);

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
