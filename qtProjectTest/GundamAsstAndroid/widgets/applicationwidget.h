#ifndef APPLICATIONWIDGET_H
#define APPLICATIONWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include "classes/models/apptablemodel.h"

namespace Ui {
class ApplicationWidget;
}

class ApplicationWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ApplicationWidget(QWidget *parent = 0);
    ~ApplicationWidget();

     AppTableModel *appModel;
     AppSortModel *appSortModel;
     QTcpSocket *socket;

     App *info;
     int currentNum;
     int appsCount;

     qint64 bytesReceived;
     qint64 totalBytes;

     QTcpSocket *socket_push;
     QFile *localFile;
     qint64 bytesWritten;  //已经发送数据大小
     qint64 bytesToWrite;   //剩余数据大小
     qint64 loadSize;   //每次发送数据的大小
     QByteArray outBlock;  //数据缓冲区，即存放每次要发送的数据

     QString ip;
     qint16 port;


public slots:
     int getAppCount();
     void GetAppInfo(int num);
     void readAppInfo();
     void appsSelectedCount();

     void appRefresh();
     void appInstall();
     void appUninstall();
     void startTransfer(QString fileName);
     void updateTransferProgress(qint64 numBytes);
     void appCopy();
     void readFile();
    
private:
    Ui::ApplicationWidget *ui;
};

#endif // APPLICATIONWIDGET_H
