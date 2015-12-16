#include <QCoreApplication>
#include <QString>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString _str=QString();
    QString().isEmpty();            // returns true
    QString("").isEmpty();          // returns true
    QString("x").isEmpty();         // returns false
    QString("abc").isEmpty();       // returns false


    QString().isNull();             // returns true
    QString("").isNull();           // returns false
    QString("abc").isNull();        // returns false

    return a.exec();
}
