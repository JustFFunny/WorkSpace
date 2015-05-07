#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QFileInfo>
//删除 遍历文件夹
int k=0;
void recusion(QString path)
{
    QFileInfo lifeInfo(path);
    qDebug()<<"CurrentPath: "<<path<<"\n";
    if(lifeInfo.isDir())//目录
    {
        //遍历该目录下 所有的文件
        QDir _dir(path);
        QFileInfoList fileInfoList=_dir.entryInfoList(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot|QDir::Hidden);

        for(int i=0;i<fileInfoList.count();++i)
        {
                  k++;
            if(fileInfoList[i].isDir())//目录
            {
                qDebug()<<"dir: "<<fileInfoList[i].path()<<"\n";
                recusion( (fileInfoList[i].absoluteFilePath()));
            }
            else if(fileInfoList[i].isFile())//文件
            {
                qDebug()<<"file: "<<fileInfoList[i].absoluteFilePath();
                QFile _file(fileInfoList[i].absoluteFilePath());
//                bool _false=  _file.remove();
//                qDebug()<<"   "<<QString::number(_false)<<"\n";
            }
        }
        向上级目录切换,并删除切换到的目录
        _dir.cdUp();
        _dir.rmpath(path);
    }
    else if(lifeInfo.isFile())//文件
    {
         k++;
        qDebug()<<"file: "<<path;
        QFile _file(path);
        bool _false=  _file.remove();
        qDebug()<<"   "<<QString::number(_false)<<"\n";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path="Lphone_pc_bak";
    recusion(path);
    qDebug()<<"count:"<<k<<"\n";
    return a.exec();
}
