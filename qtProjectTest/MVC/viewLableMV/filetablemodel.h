#ifndef FILETABLEMODEL_H
#define FILETABLEMODEL_H

#include <QAbstractTableModel>
#include <QString>
// zhu zhi yi xia shuju
class shujuStruct
{
public:

    shujuStruct(const shujuStruct &);
     shujuStruct& operator =(const shujuStruct&);
private:
    QString  name;
    QString  age;
    QString  minzu;
    QString  familyAddress;
    QString  workAddress;

};

class FileTableMOdel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit FileTableMOdel(QObject *parent = 0);
    FileTableMOdel(QList<shujuStruct> stuList,QObject *parent = 0);
    //
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    // 获得对应index项的数据
    QVariant data(const QModelIndex &index, int role) const;
    //biao tou
    QVariant setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role);
    //dan yuan ge shuxing
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertRow(int row, const QModelIndex &parent);
    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRow(int row, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    bool  clear();
    Qt::DropActions supportedDropActions()const;
   bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
private:
   QList< shujuStruct > m_stuList;


signals:
    
public slots:
    
};

#endif // FILETABLEMODEL_H
