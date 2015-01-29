#include <QApplication>
#include <QDebug>
#include <QtSql>
#include <QVariant>
#include <unistd.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");//

    database.setDatabaseName(".././dbConnect/sms.db");
    //    database.setUserName("root");
    //    database.setPassword("123456");

    //打开数据库
    if(!database.open())
    {
        qDebug()<<database.lastError();
        qFatal("failed to connect.") ;
    }
    else
    {

        //插入表


        QSqlQuery insertQuery;
        //        insertQuery.prepare("INSERT INTO handle (ROWID,id, country,service,uncannonicalized_id) VALUES (:ROWID,:id, :country,:service,:uncannonicalized_id)"); //准备执行SQL查询
        //        insertQuery.bindValue(":ROWID", "100");
        //        insertQuery.bindValue(":id", "111111111111111111111");   //在绑定要插入的值
        //        insertQuery.bindValue(":country", "english");
        //        insertQuery.bindValue(":service", "SMS");
        //        insertQuery.bindValue(":uncannonicalized_id", "1111111111");
        //        insertQuery.exec();uncanonicalized_id

        bool _h=  insertQuery.exec("insert into handle(ROWID,id, country,service,uncanonicalized_id)"  "values(9999999,9999999, 'WU','sms ','1111111111' )");
       // qDebug()<<insertQuery.lastError()<<"\n";//QSqlError(-1, "", "")

        qDebug()<<"hello";

        //查找message表
        QSqlQuery query;
       // bool _false= query.exec("SELECT * FROM message"); // 查询的结果可能不止一条记录，所以我们称之为结果集
        query.exec("SELECT m.rowid as RowID,  c.rowid as ThreadID, DATETIME(date + 978307200, 'unixepoch', 'localtime') as Date,h.id as \"Phone Number\" ,   CASE is_from_me      WHEN 0 THEN \"in\"    WHEN 1 THEN \"out\"     ELSE \"Unknown\"   END as Type, CASE WHEN date_read > 0 then DATETIME(date_read + 978307200, 'unixepoch', 'utc') WHEN date_delivered > 0 THEN DATETIME(date_delivered + 978307200, 'unixepoch', 'utc') ELSE NULL END as \"Date Read/Sent\",text as Text  FROM message m, handle h ,chat c  WHERE   h.rowid = m.handle_id   AND c.rowid=m.handle_id ORDER BY m.rowid ASC; ");
        qDebug()<<query.lastError()<<"Hello WOrld\n";
        while (query.next())
        {

                        QString name = query.value(0).toString(); //取第i条记录第1个字段(从0开始计数)的结果
                        qDebug()<<name.remove("\n")<<" lineNum\n";
                        name = query.value(1).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(2).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(3).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(4).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(5).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(6).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(7).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(8).toString().toAscii();
                        qDebug()<<name.remove("\n")<<"   ";
                        name = query.value(9).toString();
                        qDebug()<<name.remove("\n")<<"   ";
                        //            QString name = query.value(1).toString();
                        //            QString name = query.value(1).toString();
                        //            QString name = query.value(1).toString();

                        qDebug()<<"\n"<<"another:\n\n\n\n";
            //            // ... 处理name,age变量数据
        }
//        //查找表chat
//        query.exec("SELECT * FROM chat");
//        while (query.next())
        {
            QString name = query.value(0).toString(); //取第i条记录第1个字段(从0开始计数)的结果
            name = query.value(1).toString();
            qDebug()<<name.remove("\n")<<"   ";
            name = query.value(2).toString();
            qDebug()<<name.remove("\n")<<"   ";
        }

    }

    //修改表
    database.close();
    return a.exec();
}
