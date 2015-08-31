#include "audiowidget.h"
#include "ui_audiowidget.h"

#include <QLabel>
#include <QToolBar>
#include <QVBoxLayout>
#include <QTime>
#include <QMessageBox>
#include <QFileInfo>
#include <QFileDialog>
#include <QDesktopServices>
#include <QTextCodec>
#include <QMenu>
#include <QCloseEvent>
#include <QWidget>
#include <QSettings>
#include <QProcess>
#include <QTextStream>
 #include <unistd.h>

AudioWidget::AudioWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AudioWidget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout_2);

    QSettings settings;
    ip = settings.value("wlanIP").toString();
    port = settings.value("sPort").toInt();

    playingRow = -1;
    playlist_t = ui->tableWidget;
    //设置只能选择单行
    playlist_t->setSelectionMode(QAbstractItemView::SingleSelection);
    playlist_t->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置不显示网格
    playlist_t->setShowGrid(false);
    //禁止修改内容
    playlist_t->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(playlist_t,SIGNAL(clicked(QModelIndex)),this,SLOT(showAudioInfo(QModelIndex)));

    connect(ui->pushButton_in, SIGNAL(clicked()), this, SLOT(pushFile()));
    connect(ui->pushButton_out, SIGNAL(clicked()), this, SLOT(pullFile()));
    connect(ui->pushButton_delete,SIGNAL(clicked()),this,SLOT(deleteFile()));
    connect(ui->pushButton_refresh,SIGNAL(clicked()),this,SLOT(refresh()));


    android = new AndroidAPK();
    proces = new QProcess;

    //socket = new QTcpSocket();
    loadSize = 1024*1024;
    currentNum = -1;
    audioCount = 0;
    audioCount = getAudioCount();
    if(audioCount > 0)
    {
        currentNum = 0;
        ui->msg_label->setText(tr("All: %1").arg(QString::number(audioCount)));
        ui->progressBar->setMaximum(audioCount-1);
        ui->progressBar->setValue(currentNum);
        getAudioInfo(currentNum);
    }

}

AudioWidget::~AudioWidget()
{
    delete ui;
}

int AudioWidget::getAudioCount()
{
    QString mesg = "AUDIO:COUNT\n";
    int result = 0;
    socket = new QTcpSocket();
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
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
    socket->close();
    return result;
}

void AudioWidget::getAudioInfo(int num)
{
    QString mesg = "AUDIO:GET:"+QString::number(num)+"\n";
    bytesReceived = 0;
    totalBytes = 0;    
    if(num == 0)
    {
        socket = new QTcpSocket();
        connect(socket,SIGNAL(readyRead()),this,SLOT(readAudioInfo()));
    }
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {

        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}

void AudioWidget::readAudioInfo()
{
     int nn = socket->bytesAvailable();
     if(bytesReceived <= 0)
     {
         if(socket->bytesAvailable() > 0)
         {
            info = new AudioInfo();
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
            info->displayName = ColumnList.at(1);
            info->title = ColumnList.at(2);
            info->artist = ColumnList.at(3);
            info->size = ColumnList.at(4);
            info->path = ColumnList.at(5);
            info->duration = ColumnList.at(6);

            info->bm = tt;

            if(bytesReceived == totalBytes)
            {
               socket->disconnectFromHost();
               audioInfoList.append(*info);
               insertTableRow(*info);
               currentNum++;
               if(currentNum < audioCount)
               {
                   ui->progressBar->setValue(currentNum);
                   getAudioInfo(currentNum);
               }else{
                   disconnect(socket,SIGNAL(readyRead()),this,SLOT(readAudioInfo()));
                   connect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));
                   connect(playlist_t, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
                   //ui->progressBar->hide();
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
        audioInfoList.append(*info);
        insertTableRow(*info);
        currentNum++;
        if(currentNum < audioCount)
        {
            ui->progressBar->setValue(currentNum);
            getAudioInfo(currentNum);
        }else{
            disconnect(socket,SIGNAL(readyRead()),this,SLOT(readAudioInfo()));
            connect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));
            connect(playlist_t, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
            //ui->progressBar->hide();
        }
     }
}

void AudioWidget::insertTableRow(AudioInfo info)
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
        qicon->addFile(":/images/audio-default.png");
    }

    QTableWidgetItem *item_title = new QTableWidgetItem(*qicon,info.title);

    QTableWidgetItem *item_artist = new QTableWidgetItem(info.artist);

    float fsize = (float)info.size.toLongLong()/(1024*1024);
    QString ss = QString().setNum(fsize,'f',1);    
    QTableWidgetItem *item_size = new QTableWidgetItem(ss+"MB");

    qint64 total_time_value = info.duration.toLongLong();
    QTime total_time(0, (total_time_value/60000)%60, (total_time_value/1000)%60);
    QTableWidgetItem *item_duration = new QTableWidgetItem(total_time.toString("mm:ss"));

    QTableWidgetItem *item_file = new QTableWidgetItem(info.path);

    //返回列表中的行数
    int current_rows = playlist_t->rowCount();
    playlist_t->insertRow(current_rows);
    playlist_t->setItem(current_rows, 0, checkBox);
    playlist_t->setItem(current_rows, 1, item_title);
    playlist_t->setItem(current_rows, 2, item_artist);
    playlist_t->setItem(current_rows, 3, item_size);
    playlist_t->setItem(current_rows, 4, item_duration);
    playlist_t->setItem(current_rows, 5, item_file);
}


void AudioWidget:: audioChange(QModelIndex index)
{
    QString currentPath = QDir::currentPath()+"/tmp/";

    int row = index.row();
    QString path = audioInfoList.at(row).path;

    QStringList tmplist = path.split("/");
    QString filepath = currentPath + tmplist.takeLast();
    localFile = new QFile(filepath);
    if(!localFile->open(QFile::WriteOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    playingPath = filepath;
    disconnect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));
    getAudioFile(path);
}

void AudioWidget::getAudioFile(QString path)
{
    QString mesg = "FILE:GET:"+path+"\n";
    bytesReceived = 0;
    totalBytes = 0;
    byteArray.clear();
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        connect(socket,SIGNAL(readyRead()),this,SLOT(readAudioFile()));
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }

}

void AudioWidget::readAudioFile()
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
          disconnect(socket,SIGNAL(readyRead()),this,SLOT(readAudioFile()));
          connect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));

          proces->close();
          //proces->start("vlc \"" + playingPath +"\"");
          proces->start("totem \"" + playingPath +"\"");
          //ui->progressBar->hide();
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
        localFile->close();
        socket->disconnectFromHost();
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(readAudioFile()));
        connect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));
        proces->close();
        //proces->start("vlc \"" + playingPath +"\"");
        proces->start("totem \"" + playingPath +"\"");
        //ui->progressBar->hide();
    }
}


void AudioWidget::checkBoxChanged(int row, int col)
{

    if(playlist_t ->item(row, col)->checkState() == Qt::Checked)
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


void AudioWidget::startTransfer(QString fileName)  //实现文件大小等信息的发送
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
    QString currentFileName = "Audio/"+fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
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

void AudioWidget::updateTransferProgress(qint64 numBytes) //更新进度条，实现文件的传送
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
                ui->progressBar->hide();

                playlist_t->clearContents();
                playlist_t->setRowCount(0);
                audioInfoList.empty();

                audioCount = 0;
                audioCount = getAudioCount();
                if(audioCount > 0)
                {
                    currentNum = 0;
                    ui->msg_label->setText(tr("All: %1").arg(QString::number(audioCount)));
                    ui->progressBar->setMaximum(audioCount-1);
                    ui->progressBar->setValue(currentNum);
                    getAudioInfo(currentNum);
                }
            }
        }
    }
}

void AudioWidget::pushFile()
{
    pushlist = QFileDialog::getOpenFileNames(
               this,
               tr("Select Files"),
               QDesktopServices::storageLocation(QDesktopServices::MusicLocation),
               tr("audio (*.mp3);;mp3(*.mp3)")
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

   switch(QMessageBox::information(NULL, tr("import"), tr("Sure?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
   {
       case QMessageBox::No:
               return;
       default: break;
   }
   ui->progressBar->show();
   ui->msg_label->setText(tr("Import %1 / %2").arg(QString::number(currentPushNum), QString::number(pushCount)));
   startTransfer(pushlist.at(currentPushNum));
}

void AudioWidget::getFile(QString phonePath, QString pcDir)
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

    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        if(currentCheckNum == 0)
        {
            connect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
        }
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}


void AudioWidget::readFile()
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

       tt.remove(0,8);
       localFile->write(tt);

       if(bytesReceived == totalBytes)
       {
          socket->disconnectFromHost();
          localFile->close();
          currentCheckNum++;
          if(currentCheckNum < checkCount)
          {
              ui->progressBar->setValue(0);
              getFile(audioInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
          }else{
              ui->progressBar->hide();
              disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
              connect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));
              connect(playlist_t, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
          }
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
        socket->disconnectFromHost();
        localFile->close();
        currentCheckNum++;
        ui->msg_label->setText(tr("Export %1 / %2").arg(QString::number(currentCheckNum), QString::number(checkCount)));
        if(currentCheckNum < checkCount)
        {
            ui->progressBar->setValue(0);
            getFile(audioInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
        }else{
            ui->progressBar->hide();
            disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
            connect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));
            connect(playlist_t, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
        }
    }
}

void AudioWidget::pullFile()
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

//    switch(QMessageBox::information(NULL, tr("export"), tr("Sure?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
//    {
//        case QMessageBox::No:
//                return;
//    }
    if(QMessageBox::information(NULL, tr("export"), tr("Sure?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::No)
    {
         return;
    }

    disconnect(playlist_t,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(audioChange(QModelIndex)));
    disconnect(playlist_t, SIGNAL(cellChanged(int,int)), this, SLOT(checkBoxChanged(int, int)));
    ui->progressBar->show();
    ui->msg_label->setText(tr("Export %1 / %2").arg(QString::number(currentCheckNum), QString::number(checkCount)));
    getFile(audioInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);

}

void AudioWidget::showAudioInfo(QModelIndex index)
{
    int row = index.row();
    AudioInfo info = audioInfoList.at(row);

    QIcon *qicon = new QIcon();
    if(!info.bm.isEmpty())
    {
        QImage* img=new QImage;
        img->loadFromData(info.bm);
        QPixmap pixmap = QPixmap::fromImage(*img);
        qicon->addPixmap(pixmap);
    }else
    {
        qicon->addFile(":/images/audio-default.png");
    }

    ui->labelIcon->setPixmap(qicon->pixmap(100,100));
    ui->editName->setText(info.displayName);
    ui->editTitle->setText(info.title);
    ui->editAtist->setText(info.artist);
    ui->editFilePath->setText(info.path);
    float fsize = (float)info.size.toLongLong()/(1024*1024);
    QString ss = QString().setNum(fsize,'f',1);
    ui->editSize->setText(ss+"MB");

    qint64 total_time_value = info.duration.toLongLong();
    QTime total_time(0, (total_time_value/60000)%60, (total_time_value/1000)%60);

    ui->editDuration->setText(total_time.toString("mm:ss"));
}


void AudioWidget::deleteFile(){

    if(checkList.size() <= 0)
    {
        return;
    }else
    {
        checkCount = checkList.size();
    }
    for(int i = 0; i<checkCount; i++)
    {
        QString path = audioInfoList.at(checkList.at(i)).path;
        QString id = audioInfoList.at(checkList.at(i)).id;
        QString mesg = "AUDIO:DELETE:"+path+"\n";
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
    }
    refresh();

}

void AudioWidget::refresh(){

    playlist_t->clearContents();
    playlist_t->setRowCount(0);
    audioInfoList.empty();

    audioCount = 0;
    audioCount = getAudioCount();
    if(audioCount > 0)
    {
        currentNum = 0;
        ui->msg_label->setText(tr("All: %1").arg(QString::number(audioCount)));
        ui->progressBar->setMaximum(audioCount-1);
        ui->progressBar->setValue(currentNum);
        getAudioInfo(currentNum);
    }
}
