//downLoad  file下载文件

Download::Download(QObject *parent) :
QObject(parent)
{
}

void Download::initialiseDownload()
{
    QNetworkAccessManager manager;
    QNetworkRequest request;

    request.setUrl(QUrl("http://www.mylink.com/setup.exe"));
    reply = manager.get(request);

    QObject::connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(downloadError(QNetworkReply::NetworkError)));
    QObject::connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(updateProgress(qint64, qint64)));
    QObject::connect(reply, SIGNAL(finished()), this, SLOT(downloadFinished()));
}

void Download::downloadError(QNetworkReply::NetworkError err)
{
    qDebug() << reply->errorString();
    reply->deleteLater();
}

void Download::updateProgress(qint64 read, qint64 total)
{
    qDebug() << "Progress...";
    qint64 percent = (read / total) * 100;
    qDebug() << percent;
}

void Download::downloadFinished()
{
    qDebug() << "Finished !";
    QByteArray b = reply->readAll();
    QFile file("./sdk/setup.exe");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << b;
    reply->deleteLater();
}
