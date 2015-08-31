#include <QCoreApplication>
#include <QSemaphore>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSemaphore sem(5);
    qDebug()<<"cout: "<<sem.available();
    sem.release(5);//// "create" 5 new resources
    qDebug()<<"cout: "<<sem.available();
    return a.exec();
}
