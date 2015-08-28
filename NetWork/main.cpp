#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QString>
#include <iostream>
#include <string>
using namespace std;

//www.tripcam.com
//string to QString
QString s2q(const string &s)
{
return QString(QString::fromLocal8Bit(s.c_str()));
}
//http://192.168.8.78/Lphone/Lphone_windows/Lphone_exe/
//QString to string
string q2s(const QString &s)
{
return string((const char *)s.toLocal8Bit());
}


//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    QNetworkAccessManager *netManager = new QNetworkAccessManager();
//    //QNetwork发包
//    QNetworkRequest request;
//    request.setUrl(QUrl("http://www.baidu.com/"));
//    request.setRawHeader("User-Agent", "FireFox 5.0");
//    QNetworkReply *reply = netManager->get(request);
//    QTextCodec *codec = QTextCodec::codecForName("utf8");
//    //输出
//    QString all = codec->toUnicode(reply->readAll());
//    string disp = q2s(all);
//    cout << disp;
//    return a.exec();
//}
#include <QTextBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QNetworkAccessManager *netManager = new QNetworkAccessManager();
    //QNetwork发包
    QNetworkRequest request;
    request.setUrl(QUrl("http://159.226.5.150"));
  //  request.setRawHeader("User-Agent", "FireFox 5.0");
    QNetworkReply *reply = netManager->get(request);
    //得带的数据是网页的HTML网页的代码。

    //方法1：
    QEventLoop eventLoop;
    QObject::connect(netManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish

    QTextCodec *codec = QTextCodec::codecForName("utf8");
    //输出   
    QString all = codec->toUnicode(reply->readAll());
    string disp = q2s(all);
    cout << disp;

  QTextBrowser _b;
  _b.setHtml(all);
  _b.show();
    //方法2

    //  QObject::connect(netManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    //通过槽函数来接受数据。
    return a.exec();

}


