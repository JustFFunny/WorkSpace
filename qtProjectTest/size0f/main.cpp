#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char * ptr="abcdefghjklm";
    qDebug()<<sizeof(char *)<<"_________"<<sizeof(ptr)\
           <<"_________"<<sizeof(*ptr)<<"\n";  // 8  8 1
    qDebug()<<strlen(ptr); //12


    char array[20]="123456789";
    qDebug()<<sizeof(array)<<"_________"<<strlen(array)<<"\n";// 20  10
    return a.exec();
}
