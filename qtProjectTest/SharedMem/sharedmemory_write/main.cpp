#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QSharedMemory>
#include <QBuffer>
static QTextStream cin(stdin,QIODevice::ReadOnly);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSharedMemory smem;
    QString key,sharedstring;
    QBuffer buffer;                                 //将字符串转换为字节的介质
    QDataStream qdsm(&buffer);                      //数据流
    qDebug() << "Please input the shared memory key:";
    cin >> key;
    smem.setKey(key);                               //设置访问标识
    if(smem.isAttached()) smem.detach();            //判断是否已经连接到共享内存块 如果是的话 就先分离
    qDebug() << "Please input the string to share:";
    cin >> sharedstring;
    buffer.open(QBuffer::ReadWrite);                //设置读取模式
    qdsm << sharedstring;                           //输入共享字符串到数据流
    int size = buffer.size();                       //获得字节大小
    if(!smem.create(size))                          //检测共享内存段是否创建成功
    {
        qDebug() << "Could not create sharing memory";
        return a.exec();
    }
    smem.lock();                                    //锁定共享内存
    char * to = (char *)smem.data();                //共享内存的数据
    const char * from = buffer.data().data();       //被共享内存的数据
    memcpy(to,from,qMin(smem.size(),size));         //把要共享的内存拷贝到被共享的内存
    smem.unlock();                                  //把共享内存解锁
    qDebug() << "Sharing memory was successful! The key of shared memory is: "<<
                key <<" ,The string of the shared memory is： "<< sharedstring <<endl;
    return a.exec();
}
