#include <QCoreApplication>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QDebug>

#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess * _lsProcess=new QProcess;

  QString _cmd="/bin/ls -l ";
  _cmd +=" /crypt";
    _lsProcess->start(_cmd);//

    _lsProcess->waitForReadyRead();
    QString _output=_lsProcess->readAll();
     qDebug()<<_output;
    QStringList outputParts;
    outputParts = _output.split(QRegExp("\\s+"), QString::SkipEmptyParts);

        QString _name = outputParts.at(0);
        _name=_name.mid(7);
        _name.chop(1);
        if(_name.at(0)==QChar('r'))
        {
            qDebug()<<"read";
        }
        else if(_name.at(1)==QChar('w'))
        {
            qDebug()<<"write";
        }

        qDebug()<<_name;

//    struct stat buf;
//    stat("boot",&buf);
//    printf("the access? %s",buf.st_mode);
    return a.exec();
}
