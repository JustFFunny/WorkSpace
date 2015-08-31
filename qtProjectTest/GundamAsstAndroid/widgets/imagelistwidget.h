#ifndef IMAGELISTWIDGET_H
#define IMAGELISTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QSettings>
#include <QTcpSocket>
#include <QFile>
#include <QDir>
#include <QLabel>
#include <QMenu>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>

namespace Ui {
class ImageListWidget;
}
class ImageInfo{
   public:
    QString id;
    QString title;
    QString displayName;
    QString mimeType;
    QString path;
    QString size;
    QString bitmap;

    QString pc_path;
    QByteArray bm;

};

#define W_ICONSIZE  56
#define H_ICONSIZE  56


class ImageListWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ImageListWidget(QWidget *parent = 0);
    ~ImageListWidget();

    QListWidget* m_pListWidget;
    QMenu *rightContMenu;
    QList<ImageInfo> imageInfoList;
    QLabel *imageLabel;
    QImage *image;

    QTcpSocket *socket;
    QString ip;
    qint16 port;

    int imageCount;
    int currentNum;
    qint64 bytesReceived;
    qint64 totalBytes;
    ImageInfo *info;
    QByteArray byteArray;
    QFile *localFile;

//    int checkCount;
//    int currentCheckNum;
//    QString fileSaveDir;

    qint64 bytesWritten;  //已经发送数据大小
    qint64 bytesToWrite;   //剩余数据大小
//    qint64 loadSize;   //每次发送数据的大小
//    QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据

    QStringList pushlist;
    int pushCount;
    int currentPushNum;

public slots:
    int getImagetCount();
    void getImageInfo(int num);
    void readImageInfo();
    void insertListWidget(ImageInfo info);
    void imageChange(QModelIndex index);
    void rightContextMenu(QPoint pos);
    void deleteFile();
    void refresh();
    
private slots:

    void on_pushButton_show_pressed();

    void on_pushButton_import_pressed();

protected:
    //void contextMenuEvent ( QContextMenuEvent * event );

private:
    Ui::ImageListWidget *ui;
};

#endif // IMAGELISTWIDGET_H
