#include "filetablemodel.h"

FileTableMOdel::FileTableMOdel(QObject *parent) :
    QAbstractTableModel(parent)
{
}
FileTableMOdel::FileTableMOdel(QList<shujuStruct> stuList,QObject *parent = 0)
{
    m_stuList=stuList;
}

int FileTableMOdel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_stuList.size();
}
int FileTableMOdel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}


QVariant FileTableMOdel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(index.row()>=this->m_stuList.size()||index.row()<0)
    {
        return QVariant();
    }
//    int col=index.column();
//    shujuStruct _tempStu=m_stuList.at(index.row());
    switch(col)
    {
    case 0:

        return ;
    case 1:
        return ;


    }
}
