#include "stringlistmodel.h"

StringListModel::StringListModel(const QStringList &stringList,QObject *parent) :
    QAbstractListModel(parent),m_strList(stringList)
{
}
int StringListModel::rowCount(const QModelIndex &parent) const
{
    return m_strList.count();

}
QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    else if(index.row()>=m_strList.count())
    {
        return QVariant();
    }
    else if(role==Qt::DisplayRole)
    {
        return m_strList.at(index.row());

    }
    else
    {
        return QVariant();
    }


    // return index.data();error

}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
    {
        return QVariant();
    }
    if(orientation==Qt::Horizontal)
    {
        return QString("Row %1").arg(section);
    }
    else if(orientation==Qt::Vertical)
    {
        return QString("Column %1").arg(section);
    }


}



Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;//The user can interact with the item.
    }
    else
    {
        //可编辑 和 前面这个两种可能
     return QAbstractItemModel::flags(index)|Qt::ItemIsEditable ;//位运算有1为1
    }

}
bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid()&& role==Qt::EditRole)
    {
        m_strList.replace(index.row(),value.toString());
        emit dataChanged(index,index);
        return true;
    }
    return false;


}

bool StringListModel::insertRows(int position,int rows,const QModelIndex & index)
{
    beginInsertRows(QModelIndex(),position,position+rows-1);//会统治其他组建行数将会改变
    for(int row=0;row<rows;++row)
    {
        m_strList.insert(position,"");
    }
    endInsertRows();//对操作进行更正和通知;
    return true;

}

bool StringListModel::removeRows(int position,int rows,const QModelIndex & index)
{
    beginRemoveRows(QModelIndex(),position,position+rows-1);
    for(int row=0;row<rows;++row)
    {
        m_strList.removeAt(position);
    }
    endRemoveRows();
    return true;
}
