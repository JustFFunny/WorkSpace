#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QSharedMemory>
#include <QBuffer>
//Remember to lock the shared memory with lock() before reading from or writing to the shared memory,
//and remember to release the lock with unlock() after you are done.
static QTextStream cin(stdin,QIODevice::ReadOnly);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSharedMemory sharemem;
    QObject zh;
    QString key,readstring;
    qDebug() << "Please input the shared memory key:";
    cin >> key;

    sharemem.setKey(key);
    sharemem.attach();

    QBuffer buffer;
    sharemem.lock();
    QDataStream in(&buffer);
    buffer.setData((char *)sharemem.constData(),sharemem.size());
    buffer.open(QBuffer::ReadOnly);
    in >> readstring;
    sharemem.unlock();
    sharemem.detach();
    qDebug() << "The string of the shared memory is : "<< readstring;
    return a.exec();
}
