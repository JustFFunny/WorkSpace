#include "videowidget.h"
#include "ui_videowidget.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>
#include <QProcess>
#include <QSettings>
#include <QToolBar>
#include <QVBoxLayout>
#include <QTime>
#include <QMessageBox>
#include <QFileDialog>
#include <QDesktopServices>
 #include <unistd.h>
VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout_2);

    QSettings settings;
    ip = settings.value("wlanIP").toString();
    port = settings.value("sPort").toInt();

    playlist = ui->tableWidget;
    //设置只能选择单行
    playlist->setSelectionMode(QAbstractItemView::SingleSelection);
    playlist->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置不显示网格
    playlist->setShowGrid(false);
    connect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(showVideoInfo(QModelIndex)));

    //禁止修改内容,
    playlist->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->pushButton_in, SIGNAL(clicked()), this, SLOT(pushFile()));
    connect(ui->pushButton_out, SIGNAL(clicked()), this, SLOT(pullFile()));
    connect(ui->pushButton_delete,SIGNAL(clicked()),this,SLOT(deleteFile()));
    connect(ui->pushButton_refresh,SIGNAL(clicked()),this,SLOT(refresh()));

    loadSize = 1024*1024;

    android = new AndroidAPK();
    proces = new QProcess;
    //socket = new QTcpSocket();
    currentNum = -1;
    videoCount = 0;
    videoCount = getVideoCount();
    if(videoCount > 0)
    {
        currentNum = 0;
        ui->msg_label->setText(tr("All: %1").arg(QString::number(videoCount)));
        ui->progressBar->setMaximum(videoCount-1);
        ui->progressBar->setValue(currentNum);
        getVideoInfo(currentNum);
    }
}

VideoWidget::~VideoWidget()
{
    delete ui;
}

int VideoWidget::getVideoCount()
{
    QString mesg = "VIDEO:COUNT\n";
    int result = 0;
    socket = new QTcpSocket();
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
    if(socket->waitForReadyRead(-1))
    {
        QString readData = QString::fromUtf8(socket->readAll());
        result = readData.split("\n")[0].toInt();
    }
    socket->disconnectFromHost();
    return result;
}

void VideoWidget::getVideoInfo(int num)
{
    QString mesg = "VIDEO:GET:"+QString::number(num)+"\n";
    bytesReceived = 0;
    totalBytes = 0;
    if(num == 0)
    {
        socket = new QTcpSocket();
        connect(socket,SIGNAL(readyRead()),this,SLOT(readVideoInfo()));
    }

    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {

        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}

void VideoWidget::readVideoInfo()
{
     int nn = socket->bytesAvailable();
     if(bytesReceived <= 0)
     {
         if(socket->bytesAvailable() > 0)
         {
            info = new VideoInfo();
            bytesReceived = socket->bytesAvailable();
            QByteArray tt = socket->readAll();

            QByteArray bt = tt.left(8);
            QDataStream stream1(bt);
            qint64 infosize;
            stream1 >>infosize;
            tt.remove(0,8);

            QByteArray ct = tt.left(8);
            QDataStream stream2(ct);
            stream2 >>totalBytes;
            tt.remove(0,8);

            QByteArray infoData = tt.left((int)infosize);
            tt.remove(0,(int)infosize);

            QString readData = QString::fromUtf8(infoData);
            QStringList ColumnList  = readData.split(":");
            info->id = ColumnList.at(0);
            info->title = ColumnList.at(1);
            info->displayName = ColumnList.at(2);
            info->size = ColumnList.at(3);
            info->path = ColumnList.at(4);
            info->duration = ColumnList.at(5);
            info->bm = tt;

            if(bytesReceived == totalBytes)
            {
               socket->disconnectFromHost();
               videoInfoList.append(*info);
               insertTableRow(*info);
               currentNum++;
               if(currentNum < videoCount)
               {
                   ui->progressBar->setValue(currentNum);
                   getVideoInfo(currentNum);
               }else{
                   disconnect(socket,SIGNAL(readyRead()),this,SLOT(readVideoInfo()));
                   connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
                   connect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));
                  // ui->progressBar->hide();
               }
            }
         }
         return;
     }

     if(bytesReceived < totalBytes)
     {
         bytesReceived += socket->bytesAvailable();
         info->bm.append(socket->readAll());
     }

     if(bytesReceived == totalBytes)
     {
        socket->disconnectFromHost();
        videoInfoList.append(*info);
        insertTableRow(*info);
        currentNum++;
        if(currentNum < videoCount)
        {
            ui->progressBar->setValue(currentNum);
            getVideoInfo(currentNum);
        }else{
            disconnect(socket,SIGNAL(readyRead()),this,SLOT(readVideoInfo()));
            connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
            connect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));
           // ui->progressBar->hide();
        }
     }
}

void VideoWidget::insertTableRow(VideoInfo info)
{

    QTableWidgetItem *checkBox = new QTableWidgetItem();
    checkBox->setCheckState(Qt::Unchecked);

    QIcon *qicon = new QIcon();
    if(!info.bm.isEmpty())
    {
        QImage* img=new QImage;
        img->loadFromData(info.bm);
        QPixmap pixmap = QPixmap::fromImage(*img);
        qicon->addPixmap(pixmap);
    }else
    {
        qicon->addFile(":/images/video-default.png");
    }
    QTableWidgetItem *item_title = new QTableWidgetItem(*qicon,info.title);

    float fsize = (float)info.size.toLongLong()/(1024*1024);
    QString ss = QString().setNum(fsize,'f',1);
    QTableWidgetItem *item_size = new QTableWidgetItem(ss+"MB");

    qint64 total_time_value = info.duration.toLongLong();
    QTime total_time(0, (total_time_value/60000)%60, (total_time_value/1000)%60);
    QTableWidgetItem *item_duration = new QTableWidgetItem(total_time.toString("mm:ss"));

     QTableWidgetItem *item_file = new QTableWidgetItem(info.path);
    //返回列表中的行数
    int current_rows = playlist->rowCount();
    playlist->insertRow(current_rows);
    playlist->setItem(current_rows, 0, checkBox);
    playlist->setItem(current_rows, 1, item_title);
    playlist->setItem(current_rows, 2, item_size);
    playlist->setItem(current_rows, 3, item_duration);
    playlist->setItem(current_rows, 4, item_file);
}


void VideoWidget:: videoChange(QModelIndex index)
{
    QString currentPath = QDir::currentPath()+"/tmp/";

    int row = index.row();
    QString path = videoInfoList.at(row).path;

    QStringList tmplist = path.split("/");
    QString filepath = currentPath + tmplist.takeLast();
    localFile = new QFile(filepath);
    if(!localFile->open(QFile::WriteOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    playingPath = filepath;
    disconnect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));
    getVideoFile(path);
}


void VideoWidget::getVideoFile(QString path)
{
    QString mesg = "FILE:GET:"+path+"\n";
    bytesReceived = 0;
    totalBytes = 0;
    byteArray.clear();
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        connect(socket,SIGNAL(readyRead()),this,SLOT(readVideoFile()));
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }

}

void VideoWidget::readVideoFile()
{
    int nn = socket->bytesAvailable();
    if(socket->bytesAvailable() <= 0)
        return;
    if(bytesReceived <= 0)
    {
       bytesReceived = socket->bytesAvailable();
       QByteArray tt = socket->readAll();

       QByteArray ct = tt.left(8);
       QDataStream stream2(ct);
       stream2 >>totalBytes;

       ui->progressBar->setMaximum(totalBytes);
       ui->progressBar->setValue(bytesReceived);
       ui->progressBar->show();

       tt.remove(0,8);
       localFile->write(tt);

       if(bytesReceived == totalBytes)
       {
          localFile->close();
          socket->disconnectFromHost();
          disconnect(socket,SIGNAL(readyRead()),this,SLOT(readVideoFile()));
          connect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));

          proces->close();
          //proces->start("vlc \"" + playingPath +"\"");
          proces->start("totem \"" + playingPath +"\"");
         // ui->progressBar->hide();
       }
       return;
    }

    if(bytesReceived < totalBytes)
    {
        bytesReceived += socket->bytesAvailable();
        QByteArray tt = socket->readAll();
        localFile->write(tt);
        ui->progressBar->setValue(bytesReceived);
    }

    if(bytesReceived == totalBytes)
    {
        ui->progressBar->setValue(bytesReceived);
        localFile->close();
        socket->disconnectFromHost();
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(readVideoFile()));
        connect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));
        proces->close();
        //proces->start("vlc \"" + playingPath +"\"");
        proces->start("totem \"" + playingPath +"\"");
       // ui->progressBar->hide();
    }

}


void VideoWidget::checkBoxChanged(int row, int col)
{

    if(playlist ->item(row, col)->checkState() == Qt::Checked)
    {
       checkList.append(row);
    }
    else
    {
        for(int n = 0; n < checkList.size(); n++)
        {
            if(checkList[n] = row)
            {
                checkList.removeAt(n);
            }
        }
    }
}



void VideoWidget::startTransfer(QString fileName)  //实现文件大小等信息的发送
{
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;

    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    totalBytes = localFile->size();
    QString fileSize = QString::number(totalBytes);
    QString currentFileName = "Video/"+fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    QString mesg = "MEDIA:SAVE:"+fileSize+":"+currentFileName+"\n";
    int ss = strlen(mesg.toStdString().c_str());
    totalBytes += strlen(mesg.toStdString().c_str());

    socket_push = new QTcpSocket();
    //socket_push->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket_push->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket_push->waitForConnected(2000))
    {
        connect(socket_push,SIGNAL(bytesWritten(qint64)),this,SLOT(updateTransferProgress(qint64)));
        int w = socket_push->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        bytesToWrite = totalBytes - w;
        //socket->waitForBytesWritten();
    }
    ui->progressBar->setMaximum(totalBytes);
}

void VideoWidget::updateTransferProgress(qint64 numBytes) //更新进度条，实现文件的传送
{
    bytesWritten += (int)numBytes;
    ui->progressBar->setValue(bytesWritten);
    //已经发送数据的大小
    if(bytesToWrite > 0) //如果已经发送了数据
    {
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
      //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，
      //就发送剩余数据的大小
        bytesToWrite -= (int)socket_push->write(outBlock);
        sleep(1);
       //发送完一次数据后还剩余数据的大小
        outBlock.resize(0);
        //清空发送缓冲区
    }

    if(bytesWritten == totalBytes) //发送完毕
    {
        localFile->close();
        disconnect(socket_push,SIGNAL(bytesWritten(qint64)),this,SLOT(updateTransferProgress(qint64)));
        while(socket_push->waitForReadyRead(-1))
        {
            QString readData = QString::fromUtf8(socket_push->readLine());
            sleep(1);
            socket_push->disconnectFromHost();
            socket_push->close();

            currentPushNum++;
            ui->msg_label->setText(tr("Import %1 / %2").arg(QString::number(currentPushNum), QString::number(pushCount)));
            if(currentPushNum < pushCount)
            {
               startTransfer(pushlist.at(currentPushNum));
            }else {
                //ui->progressBar->hide();
                playlist->clearContents();
                playlist->setRowCount(0);
                videoInfoList.empty();

                videoCount = 0;
                videoCount = getVideoCount();
                if(videoCount > 0)
                {
                    currentNum = 0;
                    ui->msg_label->setText(tr("All: %1").arg(QString::number(videoCount)));
                    ui->progressBar->setMaximum(videoCount-1);
                    ui->progressBar->setValue(currentNum);
                    getVideoInfo(currentNum);
                }
            }
        }
    }
}

void VideoWidget::pushFile()
{
   pushlist = QFileDialog::getOpenFileNames(
               this,
               tr("Select Files"),
               QDesktopServices::storageLocation(QDesktopServices::MoviesLocation),
               tr("video (*.3gp *.mp4 *.avi);;3gp(*.3gp);;mp4(*mp4);;avi(*avi)")
               );

   if(pushlist.isEmpty())
   {
       return;
   }else{
       pushCount = pushlist.size();
       currentPushNum = 0;
       ui->progressBar->setMaximum(pushCount-1);
       ui->progressBar->setValue(currentPushNum);
   }

   switch(QMessageBox::information(NULL, tr("import"), tr("Are you sure???"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
   {
       case QMessageBox::No:
               return;
       default: break;
   }
   ui->progressBar->show();
   ui->msg_label->setText(tr("Import %1 / %2").arg(QString::number(currentPushNum), QString::number(pushCount)));
   startTransfer(pushlist.at(currentPushNum));
}



void VideoWidget::getFile(QString phonePath, QString pcDir)
{
    bytesReceived = 0;
    totalBytes = 0;

    QString mesg = "FILE:GET:"+phonePath+"\n";

    QString saveDir = pcDir;
    if(saveDir == NULL)
    {
        saveDir = QDir::currentPath()+"/tmp/";
    }

    QStringList tmplist = phonePath.split("/");
    QString filepath = saveDir + tmplist.takeLast();

    localFile = new QFile(filepath);
    if(!localFile->open(QFile::WriteOnly))
    {
        qDebug() << "open file error!";
        return;
    }

    if(currentCheckNum == 0)
    {
        socket = new QTcpSocket;
        connect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
    }
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}

void VideoWidget::readFile()
{
    int nn = socket->bytesAvailable();
    if(socket->bytesAvailable() <= 0)
        return;
    if(bytesReceived <= 0)
    {
       bytesReceived = socket->bytesAvailable();
       QByteArray tt = socket->readAll();

       QByteArray ct = tt.left(8);
       QDataStream stream2(ct);
       stream2 >>totalBytes;

       ui->progressBar->setMaximum(totalBytes);

       tt.remove(0,8);
       localFile->write(tt);
       if(bytesReceived == totalBytes)
       {
          socket->disconnectFromHost();
          localFile->close();
          currentCheckNum++;
          if(currentCheckNum < checkCount)
          {
              getFile(videoInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
          }else{
              disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
              connect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));
              connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
          }
       }
       ui->progressBar->setValue(bytesReceived);
       return;
    }

    if(bytesReceived < totalBytes)
    {
        bytesReceived += socket->bytesAvailable();
        QByteArray tt = socket->readAll();
        localFile->write(tt);
    }

    if(bytesReceived == totalBytes)
    {
        socket->disconnectFromHost();
        localFile->close();
        currentCheckNum++;
        if(currentCheckNum < checkCount)
        {
            getFile(videoInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
        }else{
            disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
            connect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));
            connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
        }
    }

    ui->progressBar->setValue(bytesReceived);
}

void VideoWidget::pullFile()
{
    if(checkList.size() <= 0)
    {
        return;
    }else
    {
        checkCount = checkList.size();
        currentCheckNum = 0;
    }

    fileSaveDir =QFileDialog::getExistingDirectory(this,QObject::tr("Choose dir to save the files"),"/");

    if(fileSaveDir == NULL)
    {
        return;
    }else{
        fileSaveDir.append("/");
    }

    if(QMessageBox::information(NULL, tr("export"), tr("Are you sure???"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::No )
    {
         return;
    }

    disconnect(playlist,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(videoChange(QModelIndex)));
    disconnect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
    //ui->progressBar->show();
    getFile(videoInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
}

void VideoWidget::showVideoInfo(QModelIndex index)
{
    int row = index.row();
    VideoInfo info = videoInfoList.at(row);
    QIcon *qicon = new QIcon();
    if(!info.bm.isEmpty())
    {
        QImage* img=new QImage;
        img->loadFromData(info.bm);
        QPixmap pixmap = QPixmap::fromImage(*img);
        qicon->addPixmap(pixmap);
    }else
    {
        qicon->addFile(":/images/video-default.png");
    }

    ui->labelIcon->setPixmap(qicon->pixmap(100,100));

    ui->editName->setText(info.displayName);
    ui->editTitle->setText(info.title);
    ui->editFilePath->setText(info.path);
    float fsize = (float)info.size.toLongLong()/(1024*1024);
    QString ss = QString().setNum(fsize,'f',1);
    ui->editSize->setText(ss+"MB");

    qint64 total_time_value = info.duration.toLongLong();
    QTime total_time(0, (total_time_value/60000)%60, (total_time_value/1000)%60);

    ui->editDuration->setText(total_time.toString("mm:ss"));
}



void VideoWidget::deleteFile()
{
    if(checkList.size() <= 0)
    {
        return;
    }else
    {
        checkCount = checkList.size();
    }
    for(int i = 0; i<checkCount; i++)
    {
        QString path = videoInfoList.at(checkList.at(i)).path;
        QString mesg = "VIDEO:DELETE:"+path+"\n";
        socket = new QTcpSocket();
        socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
        if (socket->waitForConnected(2000))
        {
            socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
            socket->waitForBytesWritten();
        }
        if(socket->waitForReadyRead(-1))
        {
            QString readData = QString::fromUtf8(socket->readAll());
            QString re = readData.split("\n")[0];
        }
        socket->disconnectFromHost();
        socket->close();
    }
    refresh();
}

void VideoWidget::refresh(){

    playlist->clearContents();
    playlist->setRowCount(0);
    videoInfoList.empty();

    videoCount = 0;
    videoCount = getVideoCount();
    if(videoCount > 0)
    {
        currentNum = 0;
        ui->msg_label->setText(tr("All: %1").arg(QString::number(videoCount)));
        ui->progressBar->setMaximum(videoCount-1);
        ui->progressBar->setValue(currentNum);
        getVideoInfo(currentNum);
    }
}





