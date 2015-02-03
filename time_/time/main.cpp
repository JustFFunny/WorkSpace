#include <QApplication>
#include <QTime>
#include <QString>
#include <QDebug>
#include <time.h>
#include <QDateTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //    //qDebug()<< QString("%1").arg(QTime::currentTime().secsTo(QTime(1970,1,1)) );
    //    qint64 sec= QTime::currentTime().secsTo(QTime(1970,1,1));

    //    qDebug()<<sec<<"\n";
    //    time_t t;
    //    t=time(NULL);//默认1970-1-1
    //    qDebug()<<t<<"      "<<QString("%1").arg(QTime::currentTime().secsTo(QTime(1970,1,1)));
    //    QString date= QDateTime::fromMSecsSinceEpoch(t).toString("yyyy,MM,dd, hh:mm ");
    //    qDebug()<<"time"<<date;


    //    QDateTime dateTime;
    //    qint64 mmmmsecs=  dateTime.toMSecsSinceEpoch();
    //    qDebug()<<QString("%1").arg( mmmmsecs) ;


    //Qt获得 当前时间距离1970.1.1-0:0:0的总秒数   然后计算出当前时间
    qDebug()<< QDateTime::currentDateTimeUtc().toString("yyyy,MM,dd, hh:mm ");
    QString t=QString("%1").arg(QDateTime::currentDateTimeUtc().toMSecsSinceEpoch());
    qDebug()<<t<<"    "<<t.toLongLong();
    qDebug()<<QDateTime::fromMSecsSinceEpoch(t.toLongLong()).toString("yyyy,MM,dd, hh:mm ");


    //test    秒数+ sql函数dateTime() 978307200
    //某个时间转换为 距离UTC的M    Iphone是手机中时间的计算方法
    qint64 result=((qint64)978307200+(qint64)424234136)*1000;
    qDebug()<<result<<"\n";
    QString time=QString("%1").arg(result);//"1092941000000"
    qDebug()<<QDateTime::fromMSecsSinceEpoch(time.toLongLong()).toString("yyyy,MM,dd, hh:mm ");
    return a.exec();

}
