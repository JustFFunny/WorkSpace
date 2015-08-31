#include "imagelistwidget.h"
#include "ui_imagelistwidget.h"


QString humanReadableSize(QString size)
{
    long double sizeTmp = 0.0;
    QString strTmp = " B";
    sizeTmp = size.toLongLong();
    if (sizeTmp <= 1024)
    {
        strTmp.prepend(QString::number(sizeTmp, 'f', 0));
        return strTmp;
    }
    if (sizeTmp > 1024)
    {
        sizeTmp = sizeTmp / 1024;
        strTmp = " KiB";
    }
    if (sizeTmp > 1024)
    {
        sizeTmp = sizeTmp / 1024;
        strTmp = " MiB";
    }
    if (sizeTmp > 1024)
    {
        sizeTmp = sizeTmp / 1024;
        strTmp = " GiB";
    }
    strTmp.prepend(QString::number(sizeTmp, 'f', 2));
    return strTmp;
}

ImageListWidget::ImageListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageListWidget)
{
    ui->setupUi(this);
    ui->label_image->hide();
    QSettings settings;
    ip = settings.value("wlanIP").toString();
    port = settings.value("sPort").toInt();
    imageLabel = ui->label_image;
    imageLabel->setAlignment(Qt::AlignCenter);
    //imageLabel->setScaledContents(true);

    rightContMenu = NULL;

    m_pListWidget = ui->listWidget;
    //设置QListWidget中的单元项的图片大小
    m_pListWidget->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
    //设置QListWidget的显示模式
    m_pListWidget->setViewMode(QListView::IconMode);
    //设置QListWidget中的单元项不可被拖动
    m_pListWidget->setMovement(QListView::Static);
    //设置QListWidget中的单元项的间距
    m_pListWidget->setSpacing(5);
    //#设置选择模式
    m_pListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    m_pListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_pListWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(imageChange(QModelIndex)));
    //connect(m_pListWidget,SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(rightContextMenu(QPoint)));
    currentNum = -1;
    imageCount = 0;
    imageCount = getImagetCount();
    if(imageCount > 0)
    {
        ui->label_num->setText(tr("All: %1").arg(QString::number(imageCount)));
        currentNum = 0;
        ui->progressBar->setMaximum(imageCount-1);
        ui->progressBar->setValue(currentNum);
        getImageInfo(currentNum);
    }
}

ImageListWidget::~ImageListWidget()
{
    delete ui;
}
int ImageListWidget::getImagetCount()
{
    QString mesg = "IMAGE:COUNT\n";
    int result = 0;
    socket = new QTcpSocket();
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
    socket->close();
    return result;
}

void ImageListWidget::getImageInfo(int num)
{
    QString mesg = "IMAGE:GET2:"+QString::number(num)+"\n";
    bytesReceived = 0;
    totalBytes = 0;
    socket = new QTcpSocket();
    connect(socket,SIGNAL(readyRead()),this,SLOT(readImageInfo()));
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}

void ImageListWidget::readImageInfo()
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
            info->displayName = ColumnList.at(2);
            //info->size = ColumnList.at(3);
            info->size = humanReadableSize(ColumnList.at(3));

            info->path = ColumnList.at(4);
            QStringList tmplist = info->path.split("/");
            QString filepath = QDir::currentPath()+"/tmp/" + tmplist.takeLast();
            info->pc_path = filepath;
            localFile = new QFile(filepath);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "open file error!";
                socket->disconnectFromHost();
                socket->close();
            }

            localFile->write(tt);

            if(bytesReceived == totalBytes)
            {
               disconnect(socket,SIGNAL(readyRead()),this,SLOT(readImageInfo()));
               socket->disconnectFromHost();
               socket->close();
               localFile->close();
               imageInfoList.append(*info);
               insertListWidget(*info);
               currentNum++;
               if(currentNum < imageCount)
               {
                   ui->progressBar->setValue(currentNum);
                   getImageInfo(currentNum);
               }else{
                   connect(m_pListWidget,SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(rightContextMenu(QPoint)));
               }
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
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(readImageInfo()));
        socket->disconnectFromHost();
        socket->close();
        localFile->close();
        imageInfoList.append(*info);
        insertListWidget(*info);
        currentNum++;
        if(currentNum < imageCount)
        {
            ui->progressBar->setValue(currentNum);
            getImageInfo(currentNum);
        }else{
            connect(m_pListWidget,SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(rightContextMenu(QPoint)));
        }
     }
}


void ImageListWidget::insertListWidget(ImageInfo info)
{
    //获得图片路径
    QString strPath=info.pc_path;
    //生成图像objPixmap
    QPixmap objPixmap(strPath);
    //生成QListWidgetItem对象(注意：其Icon图像进行了伸缩[96*96])---scaled函数
    QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(W_ICONSIZE,H_ICONSIZE))),info.displayName);
    //设置单元项的宽度和高度
    pItem->setSizeHint(QSize(W_ICONSIZE+10,H_ICONSIZE+20));
//    pItem->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
//    pItem->setCheckState(Qt::Unchecked);
    m_pListWidget->insertItem(currentNum, pItem);
}

void ImageListWidget:: imageChange(QModelIndex index)
{
    int row = index.row();
    QString path = imageInfoList.at(row).pc_path;

    QPixmap sealPixmap(path);
    int lw = imageLabel->width();
    int lh = imageLabel->height();
    int iw = sealPixmap.width();
    int ih = sealPixmap.height();
    if(lw < iw || lh < ih)
    {
       sealPixmap= sealPixmap.scaled(lw,lh,Qt::KeepAspectRatio);
    }
    imageLabel->setPixmap(sealPixmap);
    ui->label_Title->setText(imageInfoList.at(row).displayName);
    QString tmp = QString("%1x%2 (%3) ").arg(iw).arg(ih).arg(imageInfoList.at(row).size);
    //tmp.append(imageInfoList.at(row).path);
    ui->label_info->setText(tmp);
}

//void ImageListWidget::contextMenuEvent ( QContextMenuEvent * event )
//{
//    if (this->rightContMenu == NULL)
//    {
//        this->rightContMenu = new QMenu;
//        QAction *usun;
//        usun = this->rightContMenu->addAction(QIcon(":icons/remove.png"),tr("delete", "right click menu"),this,SLOT(deleteFile()));
//        usun->setData(QString("delete"));
//    }
//    this->rightContMenu->exec(QCursor::pos());
//}


void ImageListWidget::rightContextMenu(QPoint pos)
{
    if (this->rightContMenu == NULL)
    {
        this->rightContMenu = new QMenu;
        QAction *usun;
        usun = this->rightContMenu->addAction(QIcon(":icons/remove.png"),tr("delete", "right click menu"),this,SLOT(deleteFile()));
        usun->setData(QString("delete"));
    }
    QPoint pos2;
    pos2.setX(pos.x());
    pos2.setY(pos.y()+10);
    this->rightContMenu->exec(m_pListWidget->mapToGlobal(pos2));
}

void ImageListWidget::deleteFile()
{
    QList<QListWidgetItem* > items = m_pListWidget->selectedItems();
    int checkCount = items.size() ;
    if(checkCount <= 0)
    {
        return;
    }
    for(int i = 0; i<checkCount; i++)
    {
        QListWidgetItem* it = items.at(i);
        int row = m_pListWidget->row(it);
        QString path = imageInfoList.at(row).path;

        QString mesg = "IMAGE:DELETE:"+path+"\n";
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
            if(readData.contains("SUCCESS"))
            {
                imageInfoList.removeAt(row);
                m_pListWidget->takeItem(row);
                m_pListWidget->removeItemWidget(it);
                imageCount--;

            }else{
                QMessageBox::information(this,tr("error"),tr("Delete failed.\nMake sure that you are allowed to do this"),QMessageBox::Ok);
            }
        }
        socket->disconnectFromHost();
        socket->close();
    }
    ui->label_num->setText(tr("All: %1").arg(QString::number(imageCount)));
    //refresh();
}

void ImageListWidget::refresh()
{
    imageInfoList.clear();
    m_pListWidget->clear();
    currentNum = -1;
    imageCount = 0;
    imageCount = getImagetCount();
    if(imageCount > 0)
    {
        ui->label_num->setText(tr("All: %1").arg(QString::number(imageCount)));
        currentNum = 0;
        ui->progressBar->setMaximum(imageCount-1);
        ui->progressBar->setValue(currentNum);
        getImageInfo(currentNum);
    }
}



void ImageListWidget::on_pushButton_show_pressed()
{
    if(ui->label_image->isHidden())
    {
        ui->label_image->show();
    }else{
       ui->label_image->hide();
    }
}


//void ImageListWidget::startTransfer(QString fileName)  //实现文件大小等信息的发送
//{
//    totalBytes = 0;
//    bytesWritten = 0;
//    bytesToWrite = 0;

//    localFile = new QFile(fileName);
//    if(!localFile->open(QFile::ReadOnly))
//    {
//        qDebug() << "open file error!";
//        return;
//    }
//    totalBytes = localFile->size();
//    QString fileSize = QString::number(totalBytes);
//    QString currentFileName = "Image/"+fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
//    QString mesg = "MEDIA:SAVE:"+fileSize+":"+currentFileName+"\n";
//    int ss = strlen(mesg.toStdString().c_str());
//    totalBytes += strlen(mesg.toStdString().c_str());

//    socket_push = new QTcpSocket();
//    //socket_push->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
//    socket_push->connectToHost(ip,port,QTcpSocket::ReadWrite);
//    if (socket_push->waitForConnected(2000))
//    {
//        connect(socket_push,SIGNAL(bytesWritten(qint64)),this,SLOT(updateTransferProgress(qint64)));
//        int w = socket_push->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
//        bytesToWrite = totalBytes - w;
//        //socket->waitForBytesWritten();
//    }
//    ui->progressBar->setMaximum(totalBytes);
//}

//void ImageListWidget::updateTransferProgress(qint64 numBytes) //更新进度条，实现文件的传送
//{
//    bytesWritten += (int)numBytes;
//    ui->progressBar->setValue(bytesWritten);
//    //已经发送数据的大小
//    if(bytesToWrite > 0) //如果已经发送了数据
//    {
//        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
//      //每次发送loadSize大小的数据，这里设置为4KB，如果剩余的数据不足4KB，
//      //就发送剩余数据的大小
//        bytesToWrite -= (int)socket_push->write(outBlock);
//        sleep(1);
//       //发送完一次数据后还剩余数据的大小
//        outBlock.resize(0);
//        //清空发送缓冲区
//    }

//    if(bytesWritten == totalBytes) //发送完毕
//    {
//        localFile->close();
//        disconnect(socket_push,SIGNAL(bytesWritten(qint64)),this,SLOT(updateTransferProgress(qint64)));
//        while(socket_push->waitForReadyRead(-1))
//        {
//            QString readData = QString::fromUtf8(socket_push->readLine());
//            sleep(1);
//            socket_push->disconnectFromHost();
//            socket_push->close();

//            currentPushNum++;
//            ui->msg_label->setText(tr("Import %1 / %2").arg(QString::number(currentPushNum), QString::number(pushCount)));
//            if(currentPushNum < pushCount)
//            {
//               startTransfer(pushlist.at(currentPushNum));
//            }else {
//                ui->progressBar->hide();
//                playlist->clearContents();
//                playlist->setRowCount(0);
//                imageInfoList.clear();

//                imageCount = 0;
//                imageCount = getImagetCount();
//                if(imageCount > 0)
//                {
//                    currentNum = 0;
//                    ui->msg_label->setText(tr("All: %1").arg(QString::number(imageCount)));
//                    ui->progressBar->setMaximum(imageCount-1);
//                    ui->progressBar->setValue(currentNum);
//                    ui->progressBar->show();
//                    GetImageInfo(currentNum);
//                }
//            }
//        }
//    }
//}

void ImageListWidget::on_pushButton_import_pressed()
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

    if (QMessageBox::question(this,tr("import"),tr("are you sure???"),QMessageBox::Ok | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }
    ui->label_num->setText(tr("Import %1 / %2").arg(QString::number(currentPushNum), QString::number(pushCount)));
    //startTransfer(pushlist.at(currentPushNum));
}
