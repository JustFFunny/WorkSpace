#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QString>
#include <iostream>
#include <string>
#include <QDebug>
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

/*函数名：int scanNetWork(const QString & _address)
 *参数：const QString & _address 获得网络地址的html格式
 *返回值：如果返回0是含有关键字，反之没有关键字
 **/
const QString keyWord="驱动中心";
int scanNetWork(const QString & _address)
{
    QNetworkAccessManager *netManager = new QNetworkAccessManager();
    //QNetwork发包
    QNetworkRequest request;
    request.setUrl(QUrl(_address));
    QNetworkReply *reply = netManager->get(request);
    QEventLoop eventLoop;
    QObject::connect(netManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish
    QString _next=reply->readAll();

    qDebug()<<_next;
    if(_next.contains(keyWord))
    {
        return 0;
    }
    else
    {
        return -1;
    }
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
/*
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
*/
    QString _address("http://159.226.5.140:8013/dc_web/index.jsp");
    qDebug()<<scanNetWork(_address);
    //  QObject::connect(netManager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    //通过槽函数来接受数据。
    return a.exec();

}


