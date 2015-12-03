//test break

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int sum=10;

    for(int i=0; i<sum ;i++)
    {
        qDebug()<<i;
        int _count=0;
        while(_count < sum)
        {
            qDebug()<<"_count:"<<_count;
            if(_count==5)
            {
                break;//break while
            }
            _count++;
        }

    }
    
    return a.exec();
}
