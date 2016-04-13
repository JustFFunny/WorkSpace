/*
#include <QCoreApplication>
#include <QDebug>
#include <QProcess>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString _rootKeyStr("123456");
    QProcess _process;
    QString _argument(" echo ");
    _argument+=_rootKeyStr;
    _argument.append(" | sudo -S dpkg -i ");
    _argument.append("/tmp/nfs-phone-manager_2.0.0028-1nfs1_i386.deb");
//     _process.setProcessChannelMode(QProcess::MergedChannels);
//    qDebug()<<_argument;
//    _process.start(_argument);
//    _process.waitForFinished(-1);
//    QString _result=_process.readAll();
    //system(_argument.toStdString().c_str());
    system("~/testDpkg/test.sh");
    return a.exec();
}
*/

//get system's  ioBuffer
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <QDebug>
int main( void )
{
    FILE   *stream;
    FILE    *wstream;
    char   buf[1024];

    memset( buf, '/0', sizeof(buf) );//初始化buf,以免后面写如乱码到文件中
    //stream = popen( "ls -l", "r" ); //将“ls －l”命令的输出 通过管道读取（“r”参数）到FILE* stream
    stream = popen( "echo 123456 |  sudo -S dpkg -i /tmp/nfs-phone-manager_2.0.0028-1nfs1_i386.deb", "r" ); //将“ls －l”命令的输出 通过管道读取（“r”参数）到FILE* stream
    wstream = fopen( "test_popen.txt", "w+"); //新建一个可写的文件

    //fgets
    char lineStr[100];
    while( fgets( lineStr, 100, stream ) != NULL)
    {
        qDebug()<<lineStr;   //outFileInfo
    }
    fread( buf, sizeof(char), sizeof(buf),  stream);  //将刚刚FILE* stream的数据流读取到buf中
    qDebug()<<"End----------"<<buf;// 1024's 0000000 initList
    fwrite( buf, 1, sizeof(buf), wstream );//将buf中的数据写到FILE    *wstream对应的流中，也是写到文件中

    pclose( stream );
    fclose( wstream );

    return 0;
}
