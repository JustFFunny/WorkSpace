#include <QProcess>
#include <QDebug>
#include <QString>
#include <QStringList>
#include   <QCoreApplication>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList environment=QProcess::systemEnvironment();
    QString _str;
    foreach(_str,environment)
    {
        if(_str.startsWith("TMP="))
        {
           qDebug()<<_str<<"\n";
          _str=_str.mid(4);
           qDebug()<<"result: "<<_str<<"\n";
            break;
        }

    }

    return a.exec();
}
