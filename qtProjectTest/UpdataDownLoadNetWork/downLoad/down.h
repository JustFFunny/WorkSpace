#include "launcher.h"
#include <QObject>
#include <QtNetwork>

class Download : public QObject, public Launcher
{
    Q_OBJECT
public:
    explicit Download(QObject *parent = 0);
    void Download::initialiseDownload();

private slots:
    void downloadError(QNetworkReply::NetworkError err);
    void updateProgress(qint64 read, qint64 total);
    void downloadFinished();

private:
    QNetworkReply *reply;
};
