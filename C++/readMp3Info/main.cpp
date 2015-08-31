//读取mp3的信息: 演唱者. 年代.标题
#include <stdio.h>
#include <QCoreApplication>
#include <fstream>
#include <iostream>
#include <string.h>
#include <QDesktopServices>
#include <QUrl>
#include <unistd.h>
#include <sys/stat.h>
#include <QDebug>
//#include <mmsystem.h>   windows上系统自带的解码器 可以计算事件 以及播放
//Test 验证  env: wine: 没有那个文件或目录
char tag[3+1];
char title[30+1];
char year[4+1];
    char headTag[4]={0};
char tillEnd[999];
using namespace::std;


//得到ID3v2的开头的头文件信息
bool getMP3HeadInfo(char *fptr)
{

    FILE *fp;
    fp=fopen(fptr,"r");
    if(!fp)
    {
        cout<<"hello World!\n";
        return false;
    }

    //ID3
    fread(headTag,3,1,fp);
    std::cout<<"hello\n";
    std::cout<<"ID3: "<<headTag<<"\n";
    qDebug()<<headTag;
    if(!strcpy(headTag,"ID3"))
    {
        std::cout<<"the mp3 isn't ID3V2\n";
        return 0;
    }
    //获得整个大小


    fclose(fp);
}



 //得到 mp3文件的末尾的ID3V1信息
bool readMP3Info(char * fptr)
{
    FILE *fp;
    fp=fopen(fptr,"r");
    if(!fp)
    {
        cout<<"hello World!\n";
        return false;
    }



    fseek(fp,-128,SEEK_END);
    fread(tag,1,3,fp);
    if(strcmp(tag,"TAG"))
    {
        return false;
    }
    fread(title,1,30,fp);
    cout<<"标题:"<<title<<"\n";
    fread(title,1,30,fp);
    cout<<"演唱者:"<<title<<"\n";
    fread(title,1,30,fp);
    cout<<"专辑名称:"<<title<<"\n";
    fread(year,1,4,fp);
    cout<<"年代:"<<year<<"\n";
    //    fread(title,1,30,fp);
    //    cout<<"remake:"<<title<<"\n";

    fgets(tillEnd,100,fp);
    cout<<"end:"<<tillEnd<<"\n";
    if(feof(fp))
    {
        cout<<"endFile\n";
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char *ptr="/home/wuqiankun/3.mp3";
    //Size
    struct stat info;
    stat(ptr,&info);
   // cout<<"fileSize: "<<info.st_size<<"\n";
    //readMP3Info(ptr);
    // QDesktopServices::openUrl(QUrl("file:///" +QString("/tmp/File/adb.doc")));//如果其它文件的 可以直接打开啦

    //播放时间   解析前4个字节
    getMP3HeadInfo(ptr);

    return a.exec();
}
