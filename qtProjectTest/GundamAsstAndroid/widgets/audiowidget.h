#ifndef AUDIOWIDGET_H
#define AUDIOWIDGET_H

#include <QWidget>
#include <QLabel>

#include "threads/audiothread.h"
#include "classes/androidapk.h"
#include <QTableWidget>
#include <QTcpSocket>

namespace Ui {
class AudioWidget;
}

class AudioInfo{
    public:
        QString id;
        QString title;
        QString album;
        QString album_id;
        QString artist;
        QString path;
        QString displayName;
        QString mimeType;
        QString duration;
        QString size;

        QString albumImage;
        QString pc_path;

        QByteArray bm;

};

class AudioWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit AudioWidget(QWidget *parent = 0);
    ~AudioWidget();
    
private:
    Ui::AudioWidget *ui;

    QTableWidget *playlist_t;
    AudioThread audioThread;
    QList<AudioInfo> audioInfoList;
    int playingRow;

    AndroidAPK *android;
    QList<int> checkList;

    QProcess *proces;

    QTcpSocket *socket;

    int audioCount;
    int currentNum;

    qint64 bytesReceived;
    qint64 totalBytes;
    AudioInfo *info;

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

private slots:

    int getAudioCount();
    void getAudioInfo(int num);
    void readAudioInfo();
    void getAudioFile(QString path);
    void readAudioFile();
    void getFile(QString phonePath, QString pcDir);
    void readFile();
    void startTransfer(QString fileName);
    void updateTransferProgress(qint64 numBytes);

    void insertTableRow(AudioInfo info);
    void audioChange(QModelIndex index);

    void pushFile();
    void pullFile();
    void deleteFile();
    void refresh();
    void checkBoxChanged(int row, int col);

    void showAudioInfo(QModelIndex index);


protected:
//    void closeEvent(QCloseEvent *);
};

#endif // AUDIOWIDGET_H
