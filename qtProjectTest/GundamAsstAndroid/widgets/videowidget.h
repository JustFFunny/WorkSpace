#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "threads/videothread.h"
#include <QTableWidget>
#include <QLabel>
#include "classes/androidapk.h"
#include <QTcpSocket>

namespace Ui {
class VideoWidget;
}

class VideoInfo{
    public:
         QString id;
         QString title;
         QString album;
         QString artist;
         QString displayName;
         QString mimeType;
         QString path;
         QString size;
         QString duration;

         QString bitmap;
         QString pc_path;
         QByteArray bm;
};

class VideoWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit VideoWidget(QWidget *parent = 0);
    ~VideoWidget();   
    
private:
    Ui::VideoWidget *ui;

    QTableWidget *playlist;
    VideoThread videoThread;
    QList<VideoInfo> videoInfoList;

    int playingRow;
    AndroidAPK *android;
    QList<int> checkList;
    QProcess *proces;

    QTcpSocket *socket;
    int videoCount;
    int currentNum;

    qint64 bytesReceived;
    qint64 totalBytes;
    VideoInfo *info;

    QByteArray byteArray;
    QFile *localFile;
    QString playingPath;

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

public slots:

    int  getVideoCount();
    void getVideoInfo(int num);
    void readVideoInfo();
    void getVideoFile(QString path);
    void readVideoFile();
    void getFile(QString phonePath, QString pcDir);
    void readFile();
    void startTransfer(QString fileName);
    void updateTransferProgress(qint64 numBytes);

    void insertTableRow(VideoInfo info);
    void videoChange(QModelIndex index);

    void pushFile();
    void pullFile();
    void deleteFile();
    void refresh();
    void checkBoxChanged(int row, int col);
    void showVideoInfo(QModelIndex index);

};

#endif // VIDEOWIDGET_H
