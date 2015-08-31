//获得音乐信息
//eg:音乐的路径 演唱者   演唱时间 存取路径
// QString id;
//QString title;
//QString album;
//QString album_id;
//QString artist;
//QString path;
//QString displayName;
//QString mimeType;
//QString duration;
//QString size;
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>


#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   // QString audioPath("");
 printf("The login name is %s\n", getlogin());
    
    return a.exec();
}
