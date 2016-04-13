#include <QCoreApplication>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QFile _file("/home/qiankun64/version_windows.json");
    if ( !_file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        return 1;
    }

    QByteArray _byteArray(_file.readAll());

    QJsonParseError json_error;
    QJsonDocument _jsonDocument=QJsonDocument::fromJson(_byteArray, &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(_jsonDocument.isArray())
        {
            QJsonArray _jsonArray=_jsonDocument.array();
            foreach (QVariant _var, _jsonDocument.toVariant().toList())
            {
                QMap<QString, QVariant> _varMap= _var.toMap();
                if(_varMap.contains("version"))
                {
                    qDebug()<<_varMap.value("version").toString();
                }
                if(_varMap.contains("swname"))
                {
                    qDebug()<<_varMap.value("swname").toString();
                }
                if(_varMap.contains("downloadurl"))
                {
                    qDebug()<<_varMap.value("downloadurl").toString();
                }
            }

        }
        if(_jsonDocument.isObject())
        {
            qDebug()<<_jsonDocument;
        }
        if(_jsonDocument.isEmpty())
        {
            qDebug()<<"empty";
        }
    }
    else
    {
        //error
    }


    return a.exec();
}
