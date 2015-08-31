#include <QApplication>
//#include <QCoreApplication>
#include <unistd.h>
#include <stdio.h>
#include <QDebug>
#include <sys/types.h>
#include <pwd.h>
// linux   获得用户名 获得主机名hostName
int main(int argc, char *argv[])
{
    //  QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    //获得用户名
    //    char *login;
    //    login=getlogin();
    //    printf("%s\n",login);

    //获得主机名
    char name[60];
    gethostname(name,sizeof(name));
    printf("%s\n",name);
printf("****************hhhh********\n");
    QString _name(getlogin());
    qDebug()<<_name;



 printf("***********************************");

    uid_t userid;
   struct passwd* pwd;
   userid=getuid();
   printf("userid is %d\n",userid);
   pwd=getpwuid(userid);
   printf("username is %s\nuserdir i %s\n",pwd->pw_name,pwd->pw_dir);
   printf("***********************************");
   qDebug()<<QString(pwd->pw_name);
    return a.exec();
}


/*
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
int main()
{
 uid_t userid;
 struct passwd* pwd;
 userid=getuid();
 printf("userid is %d\n",userid);
 pwd=getpwuid(userid);
 printf("username is %s\nuserdir i %s\n",pwd->pw_name,pwd->pw_dir);
}
*/
