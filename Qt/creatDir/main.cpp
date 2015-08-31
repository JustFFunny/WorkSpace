#include <QCoreApplication>
#include <QDir>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QDir * _dir=new QDir();
//   // _dir->mkdir("tmp//audio");
//    _dir->mkpath("tmp/audio");

  /**/
    QDir directory(this->getPath());
    qDebug()<<"getIOSFilePath,m    :"<<this->getPath();
    QFileInfoList fileInfoList;
    if (this->hiddenFiles)
    {
        fileInfoList = directory.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System);
    }
    else
    {
        fileInfoList = directory.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot);
    }
    QFileInfo fileInfo;
    File file;
    QList<File> *fileList = new QList<File>;
    QFileIconProvider *provider = new QFileIconProvider;
    while (!fileInfoList.isEmpty())
    {
        if (this->procesEvents)
            qApp->processEvents();
        fileInfo = fileInfoList.takeFirst();

        file.fileIcon = provider->icon(fileInfo);
        file.fileName = fileInfo.fileName();
        qDebug()<<"IOSFileName:"<<file.fileName;
        file.fileSize = QString::number(fileInfo.size());
        file.fileDate = fileInfo.lastModified().toString("MMM dd yyyy");
        file.filePath = fileInfo.absoluteFilePath();
        file.filePermissions = "";
        file.fileOwner = fileInfo.owner();
        if (fileInfo.isDir())
            file.fileType = "dir";
        else
            file.fileType = "file";

        fileList->append(file);
    }
    delete provider;
    return fileList;
    return a.exec();
}
