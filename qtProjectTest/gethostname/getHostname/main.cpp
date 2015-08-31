/* 返回本地主机的标准主机名。   */
#include <QCoreApplication>
#include <QDebug>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString _str="10 01    0 1 ";
    if(_str.contains(" "));
    {

        _str.remove(" ");
        qDebug()<<"this str contain kongge:"<<_str;
    }

    QString _num="+++10068";
    //_num=_num.left(3);
    _num=_num.mid(3);
    qDebug()<<_num;
    char name[65];
   if(gethostname(name,sizeof(name))==0)
   {
    QString _name=QString(name);
     qDebug()<<"this is a computer Name:"<<_name;

    // printf("hostname = %s\n", name);
   }
   else
   {
       qDebug("SOcket error!");

   }
    return a.exec();
}
