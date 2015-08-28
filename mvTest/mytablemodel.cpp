#include "mytablemodel.h"
#include <QDebug>
MyTableModel::MyTableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}
//MyTableModel::MyTableModel(StuList  stuList,QObject *parent )
//{
//    m_stuList=stuList;
//}
void MyTableModel::SetStuDateBase(StuList  stuList)
{
    m_stuList=stuList;
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    qDebug()<< m_stuList.count();
     return m_stuList.count();
}
int MyTableModel::rowCount()
{
    return  m_stuList.count();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

//设置视图的头部信息    标题
QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role!=Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case 0:
            return QString("stu");
        case 1:
            return QString("num");
        default:
            return QVariant();

        }
    }
    else if(orientation == Qt::Vertical)
        return QString("%1").arg(section);
    return QVariant();
}
Qt::ItemFlags MyTableModel::flags(const QModelIndex &index,int role) const
{  //索引无效
    //    if(!index.isValid())
    //    {
    //        return Qt::ItemIsEnabled; //The user can interact with the item.
    //    }
    //    //索引有效
    //  return QAbstractTableModel::flags(index)|Qt::ItemIsEditable;//
    //    //  return Qt::ItemIsEditable;

    //    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    //    if (index.row() != index.column()) {
    //            flags |= Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable;
    //    }
    //    return flags;

    return Qt::ItemIsEnabled |Qt::ItemIsSelectable|Qt::ItemIsEditable;
}
//显示数据中用到
QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    //index从0开始的
    if(index.row()>=m_stuList.count())
    {
        return QVariant();
    }

    if(role==Qt::DisplayRole)//显示
        // if(role==Qt::EditRole) //表是空的
    {
        return m_stuList[index.row()][index.column()];
        // return "a";
    }
    else if(role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    //    else if(role==Qt::EditRole)
    //    {
    //    }
    return QVariant();

}
bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug()<<"setData Fuction";
    if(index.isValid() && role ==Qt::EditRole)
    {
        int row = index.row();
        Stu _stu =m_stuList[row];
        int col = index.column();
        switch(col)
        {
        case 0:
            break;
        case 1:
            _stu.m_name=value.toString();
            break;
        case 2:
            _stu.m_no=value.toString();
            break;
        default:
            return false;
            break;
        }
        m_stuList.replace(row,_stu);
        emit (dataChanged(index, index));
        return true;
    }
    return false;
}
//删除行
bool MyTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(QModelIndex(),row,row);
    m_stuList.remove(row);
    endRemoveRows();
}
//添加行
bool MyTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    //beginInsertRows()通知其他组件行数将会改变。
    //endInsertRows()对操作进行确认与通知。返回true表示成功。
    beginInsertRows(QModelIndex(),row,row);
    Stu _stu("WU","insert");
    m_stuList.insert(row,_stu);
    endInsertRows();
}
