#include "imagewidget.h"
#include "ui_imagewidget.h"
#include "threads/socketthread.h"
 #include <unistd.h>
ImageWidget::ImageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageWidget)
{
    ui->setupUi(this);
    QSettings settings;
    ip = settings.value("wlanIP").toString();
    port = settings.value("sPort").toInt();

    playlist = ui->tableWidget;
    //设置只能选择单行
    playlist->setSelectionMode(QAbstractItemView::SingleSelection);
    playlist->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置不显示网格
    playlist->setShowGrid(false);
    //禁止修改内容
    playlist->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->pushButton_in, SIGNAL(clicked()), this, SLOT(PushFile()));
    connect(ui->pushButton_out, SIGNAL(clicked()), this, SLOT(PullFile()));

    android = new AndroidAPK();

    imageLabel  = ui->label;
    imageLabel->setAlignment(Qt::AlignCenter);
    image = new QImage();

    socket = new QTcpSocket();

    loadSize = 10*1024;

    currentNum = -1;
    imageCount = 0;
    imageCount = getImagetCount();
    if(imageCount > 0)
    {
        ui->msg_label->setText(tr("All: %1").arg(QString::number(imageCount)));
        currentNum = 0;
        ui->progressBar->setMaximum(imageCount-1);
        ui->progressBar->setValue(currentNum);
        GetImageInfo(currentNum);
    }
}

ImageWidget::~ImageWidget()
{
    delete ui;
}

int ImageWidget::getImagetCount()
{
    QString mesg = "IMAGE:COUNT\n";
    int result = 0;
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        //socket->waitForBytesWritten();
    }
    if(socket->waitForReadyRead(-1))
    {
        QString readData = QString::fromUtf8(socket->readAll());
        result = readData.split("\n")[0].toInt();
    }
    socket->disconnectFromHost();
    return result;
}

void ImageWidget::GetImageInfo(int num)
{
    QString mesg = "IMAGE:GET:"+QString::number(num)+"\n";
    bytesReceived = 0;
    totalBytes = 0;
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))        
    {
        if(num == 0)
        {
            connect(socket,SIGNAL(readyRead()),this,SLOT(readImageInfo()));
        }
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        //socket->waitForBytesWritten();
    }
}

void ImageWidget::readImageInfo()
{
     int nn = socket->bytesAvailable();
     if(bytesReceived <= 0)
     {
         if(socket->bytesAvailable() > 0)
         {
            info = new ImageInfo();
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
            info->size = ColumnList.at(2);
            info->path = ColumnList.at(3);
            info->bm = tt;

            if(bytesReceived == totalBytes)
            {
               socket->disconnectFromHost();
               imageInfoList.append(*info);
               insertTableRow(*info);
               currentNum++;
               if(currentNum < imageCount)
               {
                   ui->progressBar->setValue(currentNum);
                   GetImageInfo(currentNum);
               }else{
                   disconnect(socket,SIGNAL(readyRead()),this,SLOT(readImageInfo()));
                   connect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));
                   connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(CheckBoxChanged(int, int)));
                   ui->progressBar->hide();
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
        imageInfoList.append(*info);
        insertTableRow(*info);
        currentNum++;
        if(currentNum < imageCount)
        {
            ui->progressBar->setValue(currentNum);
            GetImageInfo(currentNum);
        }else{
            disconnect(socket,SIGNAL(readyRead()),this,SLOT(readImageInfo()));
            connect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));
            connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(CheckBoxChanged(int, int)));
            ui->progressBar->hide();
        }
     }
}



void ImageWidget::insertTableRow(ImageInfo info)
{
    QTableWidgetItem *checkBox = new QTableWidgetItem();
    checkBox->setCheckState(Qt::Unchecked);

    QImage* img=new QImage;
    img->loadFromData(info.bm);
    QPixmap pixmap = QPixmap::fromImage(*img);
    QIcon *qicon = new QIcon();
    qicon->addPixmap(pixmap);

    QTableWidgetItem *item_title = new QTableWidgetItem(*qicon,info.title);

    float fsize = (float)info.size.toLongLong()/1024;
    QString ss = QString().setNum(fsize,'f',1);
    QTableWidgetItem *item_size = new QTableWidgetItem(ss+"KB");

    int current_rows = playlist->rowCount();
    playlist->insertRow(current_rows);
    playlist->setItem(current_rows, 0, checkBox);
    playlist->setItem(current_rows, 1, item_title);
    playlist->setItem(current_rows, 2, item_size);
}

void ImageWidget:: ImageChange(QModelIndex index)
{
    QString currentPath = QDir::currentPath()+"/tmp/";
    int row = index.row();
    QString path = imageInfoList.at(row).path;

    QStringList tmplist = path.split("/");
    QString filepath = currentPath + tmplist.takeLast();

    localFile = new QFile(filepath);
    if(!localFile->open(QFile::WriteOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    disconnect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));
    GetImageFile(path);

}


void ImageWidget::GetImageFile(QString path)
{
    QString mesg = "FILE:GET:"+path+"\n";
    bytesReceived = 0;
    totalBytes = 0;
    byteArray.clear();
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        connect(socket,SIGNAL(readyRead()),this,SLOT(readImageFile()));
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }

}

void ImageWidget::readImageFile()
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

       tt.remove(0,8);
       byteArray.append(tt);
       localFile->write(tt);

       if(bytesReceived == totalBytes)
       {
          socket->disconnectFromHost();
          disconnect(socket,SIGNAL(readyRead()),this,SLOT(readImageFile()));
          connect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));
          localFile->close();
          image->loadFromData(byteArray);
          int lw = imageLabel->width();
          int lh = imageLabel->height();
          int iw = image->width();
          int ih = image->height();
          if(lw < iw || lh < ih)
              image->scaled(lw,lh,Qt::KeepAspectRatio);
          imageLabel->setPixmap(QPixmap::fromImage(*image));
       }
       return;
    }

    if(bytesReceived < totalBytes)
    {
        bytesReceived += socket->bytesAvailable();
        QByteArray tt = socket->readAll();
        byteArray.append(tt);
        localFile->write(tt);
    }

    if(bytesReceived == totalBytes)
    {
        localFile->close();
        socket->disconnectFromHost();
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(readImageFile()));
        connect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));

        image->loadFromData(byteArray);
        int lw = imageLabel->width();
        int lh = imageLabel->height();
        int iw = image->width();
        int ih = image->height();
        if(lw < iw || lh < ih)
            image->scaled(lw,lh,Qt::KeepAspectRatio);
        imageLabel->setPixmap(QPixmap::fromImage(*image));
    }

}


 void ImageWidget::CheckBoxChanged(int row, int col)
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


 void ImageWidget::startTransfer(QString fileName)  //实现文件大小等信息的发送
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
     QString currentFileName = "Image/"+fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
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

 void ImageWidget::updateTransferProgress(qint64 numBytes) //更新进度条，实现文件的传送
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
                 playlist->clearContents();
                 playlist->setRowCount(0);
                 imageInfoList.clear();

                 imageCount = 0;
                 imageCount = getImagetCount();
                 if(imageCount > 0)
                 {
                     currentNum = 0;
                     ui->msg_label->setText(tr("All: %1").arg(QString::number(imageCount)));
                     ui->progressBar->setMaximum(imageCount-1);
                     ui->progressBar->setValue(currentNum);
                     ui->progressBar->show();
                     GetImageInfo(currentNum);
                 }
             }
         }
     }
 }

void ImageWidget::PushFile()
{
    pushlist = QFileDialog::getOpenFileNames(
                this,
                tr("Select Files"),
                QDesktopServices::storageLocation(QDesktopServices::PicturesLocation),
                tr("images (*.png *.gif *.jpg);;png(*png);;jpg(*jpg);;gif(*gif)")
                );
    if(pushlist.isEmpty())
    {
        return;
    }else
    {
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

void ImageWidget::getFile(QString phonePath, QString pcDir)
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

void ImageWidget::readFile()
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

       tt.remove(0,8);
       localFile->write(tt);

       if(bytesReceived == totalBytes)
       {
          socket->disconnectFromHost();
          localFile->close();
          currentCheckNum++;
          if(currentCheckNum < checkCount)
          {
              ui->progressBar->setValue(currentCheckNum);
              getFile(imageInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
          }else{
              ui->progressBar->hide();
              disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
              connect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));
              connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(CheckBoxChanged(int, int)));
          }
       }
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
        ui->msg_label->setText(tr("Export %1 / %2").arg(QString::number(currentCheckNum), QString::number(checkCount)));
        if(currentCheckNum < checkCount)
        {
            ui->progressBar->setValue(currentCheckNum);
            getFile(imageInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
        }else{
            ui->progressBar->hide();
            disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
            connect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));
            connect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(CheckBoxChanged(int, int)));
        }
    }
}

void ImageWidget::PullFile()
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

    if(QMessageBox::information(NULL, tr("export"), tr("Sure?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::No)
    {
        return;
    }
    ui->progressBar->show();
    ui->progressBar->setMaximum(checkCount-1);
    ui->progressBar->setValue(currentCheckNum);

    disconnect(playlist,SIGNAL(clicked(QModelIndex)),this,SLOT(ImageChange(QModelIndex)));
    disconnect(playlist, SIGNAL(cellChanged(int,int)), this, SLOT(CheckBoxChanged(int, int)));
    getFile(imageInfoList.at(checkList.at(currentCheckNum)).path, fileSaveDir);
}

