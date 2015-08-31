#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>
#include <QProcess>
#include <QSettings>
#include <QFileDialog>
#include <QDesktopServices>
#include <QtGui>
#include <QtNetwork>
#include "classes/androidapk.h"
#include "threads/imagethread.h"
#include "threads/socketthread.h"
#include "imagelistwidget.h"

namespace Ui {
class ImageWidget;
}

//class ImageInfo{
//   public:
//    QString id;
//    QString title;
//    QString displayName;
//    QString mimeType;
//    QString path;
//    QString size;
//    QString bitmap;

//    QString pc_path;
//    QByteArray bm;
//};


class ImageWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ImageWidget(QWidget *parent = 0);
    ~ImageWidget();
    
private:
    Ui::ImageWidget *ui;

public:
    QTableWidget *playlist;
    QList<ImageInfo> imageInfoList;
    QLabel *imageLabel;
    QImage *image;
    AndroidAPK *android;
    QList<int> checkList;

    QTcpSocket *socket;

    int imageCount;
    int currentNum;

    qint64 bytesReceived;
    qint64 totalBytes;
    ImageInfo *info;

    QByteArray byteArray;
    QFile *localFile;

    int checkCount;
    int currentCheckNum;
    QString fileSaveDir;

    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
    qint64 loadSize;   //每次发送数据的大小
    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据

    QTcpSocket *socket_push;
    QStringList pushlist;
    int pushCount;
    int currentPushNum;

    QString ip;
    qint16 port;

signals:
    void getFilePaths(QStringList list);

public slots:

    int getImagetCount();
    void GetImageInfo(int num);
    void readImageInfo();
    void GetImageFile(QString path);
    void readImageFile();
    void getFile(QString phonePath, QString pcDir);
    void readFile();
    void startTransfer(QString fileName);
    void updateTransferProgress(qint64 numBytes);

    void insertTableRow(ImageInfo);
    void ImageChange(QModelIndex index);

    void PushFile();
    void PullFile();
    void CheckBoxChanged(int row, int col);

};

#endif // IMAGEWIDGET_H
