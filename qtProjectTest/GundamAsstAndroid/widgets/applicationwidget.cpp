#include "applicationwidget.h"
#include "ui_applicationwidget.h"
 #include <unistd.h>
ApplicationWidget::ApplicationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApplicationWidget)
{
    ui->setupUi(this);
    this->setLayout(ui->layoutApps);

    QSettings settings;
    ip = settings.value("wlanIP").toString();
    port = settings.value("sPort").toInt();

    appModel = new AppTableModel;
    appSortModel = new AppSortModel;

    this->appSortModel->setSourceModel(this->appModel);
    this->appSortModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    this->appSortModel->setDynamicSortFilter(true);

    ui->tableView->setModel(this->appSortModel);

    this->ui->tableView->setSelectionMode(QTableView::ExtendedSelection);
    this->ui->tableView->setSelectionBehavior(QTableView::SelectRows);
    connect(this->ui->tableView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)),this, SLOT(appsSelectedCount()));

    connect(this->ui->pushButton_uninstall, SIGNAL(clicked()),this, SLOT(appUninstall()));
    connect(this->ui->pushButton_install, SIGNAL(clicked()),this, SLOT(appInstall()));
    connect(this->ui->pushButton_refresh, SIGNAL(clicked()),this, SLOT(appRefresh()));
    connect(this->ui->pushButton_copy, SIGNAL(clicked()),this, SLOT(appCopy()));

    currentNum = -1;
    appsCount = 0;
    appsCount = getAppCount();
    if(appsCount > 0)
    {
        currentNum = 0;
        ui->progressApps->setMaximum(appsCount-1);
        ui->progressApps->setValue(currentNum);
        GetAppInfo(currentNum);
    }

}
ApplicationWidget::~ApplicationWidget()
{
    delete ui;
}

int ApplicationWidget::getAppCount()
{
    QString mesg = "APP:COUNT\n";
    int result = 0;
    socket = new QTcpSocket;
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
QByteArray bm;
void ApplicationWidget::GetAppInfo(int num)
{
    QString mesg = "APP:GET:"+QString::number(num)+"\n";
    bytesReceived = 0;
    totalBytes = 0;
    bm.clear();
    socket = new QTcpSocket;
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        connect(socket,SIGNAL(readyRead()),this,SLOT(readAppInfo()));
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}

void ApplicationWidget::readAppInfo()
{
     int nn = socket->bytesAvailable();
     if(bytesReceived <= 0)
     {
         if(socket->bytesAvailable() > 0)
         {
            info = new App();
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
            info->appName = ColumnList.at(0);
            info->appVersion = ColumnList.at(1);
            info->appSize = ColumnList.at(2);
            info->packageName = ColumnList.at(3);
            info->appFile = ColumnList.at(4);
            info->location = ColumnList.at(5);
            bm = tt;

            if(bytesReceived == totalBytes)
            {
               socket->disconnectFromHost();
               socket->close();
               QPixmap pix;
               pix.loadFromData(bm);
               QIcon icon(pix);
               info->appIcon = icon;
               appModel->insertApp(currentNum,*info);
               currentNum++;
               if(currentNum < appsCount)
               {
                   ui->progressApps->setValue(currentNum);
                   GetAppInfo(currentNum);
               }else{
                   disconnect(socket,SIGNAL(readyRead()),this,SLOT(readAppInfo()));

                   //ui->progressApps->hide();
               }
            }
         }
         return;
     }

     if(bytesReceived < totalBytes)
     {
         bytesReceived += socket->bytesAvailable();
         bm.append(socket->readAll());
     }

     if(bytesReceived == totalBytes)
     {
        socket->disconnectFromHost();
        socket->close();
        QPixmap pix;
        pix.loadFromData(bm);
        QIcon icon(pix);
        info->appIcon = icon;
        appModel->insertApp(currentNum,*info);
        currentNum++;
        if(currentNum < appsCount)
        {
            ui->progressApps->setValue(currentNum);
            GetAppInfo(currentNum);
        }else{
            disconnect(socket,SIGNAL(readyRead()),this,SLOT(readAppInfo()));           
            //ui->progressApps->hide();
        }
     }
}

void ApplicationWidget::appsSelectedCount()
{

    QModelIndexList indexList = this->ui->tableView->selectionModel()->selectedRows(1);

    if (indexList.isEmpty())
    {
        this->ui->tableView->selectRow(0);
    }
    else
    {
        App app = this->appModel->getApp(this->appSortModel->mapToSource(indexList.first()).row());

        this->ui->labelAppsIcon->setPixmap(app.appIcon.pixmap(100,100));
        this->ui->editAppsAppName->setText(app.appName);
        this->ui->editAppsVersion->setText(app.appVersion);
        this->ui->editAppsSize->setText(app.appSize);
        this->ui->editAppsFileName->setText(app.appFile);
        this->ui->editAppsPackageName->setText(app.packageName);
        this->ui->editAppsLocation->setText(app.location);

    }
}


void ApplicationWidget::appRefresh(){

    appModel->clear();
    currentNum = -1;
    appsCount = 0;
    appsCount = getAppCount();
    if(appsCount > 0)
    {
        currentNum = 0;
        ui->progressApps->setMaximum(appsCount-1);
        ui->progressApps->setValue(currentNum);
        GetAppInfo(currentNum);
    }

}


void ApplicationWidget::startTransfer(QString fileName)  //实现文件大小等信息的发送
{
    totalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;
    loadSize = 1024*1024;
    localFile = new QFile(fileName);
    if(!localFile->open(QFile::ReadOnly))
    {
        qDebug() << "open file error!";
        return;
    }
    totalBytes = localFile->size();
    QString fileSize = QString::number(totalBytes);
    QString currentFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    QString mesg = "APP:INSTALL:"+fileSize+":"+currentFileName+"\n";
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

}

void ApplicationWidget::updateTransferProgress(qint64 numBytes) //更新进度条，实现文件的传送
{
    bytesWritten += (int)numBytes;
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
//            if(readData.contains("SUCCESS"))
//            {
//                QMessageBox::information(this,"",tr("Install SUCCESS"),QMessageBox::Ok);
//                appRefresh();
//            }else{
//                QMessageBox::information(this,"",tr("Install FAILED"),QMessageBox::Ok);
//            }
            //sleep(1);
            socket_push->disconnectFromHost();
            socket_push->close();
        }
    }
}


void ApplicationWidget::appInstall(){

    QString pushFile = QFileDialog::getOpenFileName(
               this,
               tr("Select Files"),
               QDesktopServices::storageLocation(QDesktopServices::MusicLocation),
               tr("APK (*.apk);;APK(*.apk)")
               );

   if(pushFile.isEmpty())
   {
       return;
   }

//   switch(QMessageBox::information(NULL, tr("Install"), tr("Sure?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
//   {
//       case QMessageBox::No:
//               return;
//       default: break;
//   }

   startTransfer(pushFile);

}

void ApplicationWidget::appUninstall(){

    QModelIndexList indexList = this->ui->tableView->selectionModel()->selectedRows(1);

    if (indexList.isEmpty())
    {
        this->ui->tableView->selectRow(0);
    }
    else
    {
        int row =  this->appSortModel->mapToSource(indexList.first()).row();
        App app = this->appModel->getApp(row);

        QString packname = app.packageName;
        QString mesg = "APP:UNINSTALL:";
        mesg.append(packname);
        mesg.append("\n");
        socket = new QTcpSocket;
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
            QString result = readData.split("\n")[0];
        }
        socket->disconnectFromHost();
        this->appModel->removeRow(row);
        this->ui->tableView->selectRow(row);
    }
}


void ApplicationWidget::readFile()
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
          disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
          socket->disconnectFromHost();
          localFile->close();
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
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
    }
}


void ApplicationWidget::appCopy(){


    QModelIndexList indexList = this->ui->tableView->selectionModel()->selectedRows(1);

    if (indexList.isEmpty())
    {
        this->ui->tableView->selectRow(0);
    }

    int row =  this->appSortModel->mapToSource(indexList.first()).row();
    App app = this->appModel->getApp(row);

    QString appFile = app.appFile;
    QString mesg = "FILE:GET:"+appFile+"\n";


    QString fileSaveDir =QFileDialog::getExistingDirectory(this,QObject::tr("Choose dir to save the files"),"/");

    if(fileSaveDir == NULL)
    {
        return;
    }else{
        fileSaveDir.append("/");
    }

//    switch(QMessageBox::information(NULL, tr("Copy"), tr("Sure?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
//    {
//        case QMessageBox::No:
//                return;
//    }

    bytesReceived = 0;
    totalBytes = 0;

    QStringList tmplist = appFile.split("/");
    QString filepath = fileSaveDir + tmplist.takeLast();

    localFile = new QFile(filepath);
    if(!localFile->open(QFile::WriteOnly))
    {
        qDebug() << "open file error!";
        return;
    }

    socket = new QTcpSocket;
    //socket->connectToHost("127.0.0.1",6100,QTcpSocket::ReadWrite);
    socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
    if (socket->waitForConnected(2000))
    {
        connect(socket,SIGNAL(readyRead()),this,SLOT(readFile()));
        socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
        socket->waitForBytesWritten();
    }
}
