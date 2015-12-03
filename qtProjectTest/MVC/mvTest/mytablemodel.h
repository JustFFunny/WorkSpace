#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <qnamespace.h>
#include <QAbstractTableModel>
//#include <QStringList>
#include <QVector>
#include <QString>

class Stu
{
public:
    Stu()
    {
    }

    Stu(QString name,QString no)//:m_name(name),m_no(no)
    {
        m_name=name;
        m_no=no;
    }


    QString m_name;
    QString m_no;
    QString operator [](int i)const
    {
        switch (i) {
//        case 0:
//            return QString();
//            break;
        case 0:
            return m_name;
        case 1:
            return m_no;

        default:
            break;
        }
        return QString();
    }
};


typedef QVector<Stu>  StuList;
class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MyTableModel(QObject *parent = 0);
  //  MyTableModel(StuList  stuList,QObject *parent = 0);
    void SetStuDateBase(StuList  stuList);
    int rowCount(const QModelIndex &parent) const;
    int rowCount();
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    //可编辑Model
    Qt::ItemFlags flags(const QModelIndex &index,int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role= Qt::EditRole);
    bool removeRows(int row, int count, const QModelIndex &parent);
    bool insertRows(int row, int count, const QModelIndex &parent);
signals:
    
public slots:
private:
    // QStringList m_strList;
    StuList m_stuList;
    
};

#endif // MYTABLEMODEL_H
