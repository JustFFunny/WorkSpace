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
   // qDebug()<<"CurrentPath: "<<path<<"\n";
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

                recusion( (fileInfoList[i].absoluteFilePath()));
            }
            else if(fileInfoList[i].isFile())//文件
            {


                if(fileInfoList[i].suffix().contains("db"))
                {
                     qDebug()<<"file: "<<fileInfoList[i].absoluteFilePath();
                }
            }
        }
        //向上级目录切换,并删除切换到的目录
        _dir.cdUp();
    }
    else if(lifeInfo.isFile())//文件
    {
         k++;
         if(lifeInfo.suffix().contains("db"))
         {
              qDebug()<<"file: "<<path;
         }


    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path="/run/user/wuqiankun/gvfs/afc:host=8c9ba784da5bcac6f22be5740bdc7e643bc9f683";
    recusion(path);
    qDebug()<<"count:"<<k<<"\n";
    return a.exec();
}
