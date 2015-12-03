#include "studentinfomodel.h"
#include <QPixmap>
int StudentInfoModel::rowCount(const QModelIndex &parent ) const
{
    return studentInfos.count();

}
int StudentInfoModel::columnCount(const QModelIndex &parent ) const
{
    return 8;
}

QVariant StudentInfoModel::headerData(int section, Qt::Orientation orientation, int role ) const
{

}


QVariant StudentInfoModel::data( const QModelIndex &index, int role ) const
{


    //add the pixmap
    if(role == Qt::DecorationRole)
    {
        int col =index.column();
        if(1 == col)
        {
            return QVariant(QPixmap(":/res/play.png"));
        }
        else if(0 == col)
        {
            return QColor(Qt::red);
        }

        else
        {
            return QVariant();
        }
    }

    if(role == Qt::TextAlignmentRole)
    {
        if(index.column() == 0)
        {
            return QVariant(Qt::AlignRight | Qt::AlignVCenter);
        }
    }
  //ToolTipRole
    if(role == Qt::ToolTipRole)
    {
        if(index.column() == 0)
        {
            return QVariant("This is a colume 0!!");
        }
    }
    //BackgroundColorRole
    if(role == Qt::BackgroundColorRole)
    {
        if(index.column() == 0)
        {
            return QColor(Qt::green);
        }
    }
    //EditRole 编辑的时候显示的颜色
    if(role == Qt::EditRole)
    {
        if(index.column() == 2)
        {

            return QVariant("TestEdit");
        }
    }
    if(role == Qt::DisplayRole)
    {
        if (index.column() == 0)
            return QString::number(index.row()+1);
        // return "";
        if (index.column() == 1)
            //return studentInfos[index.row()].stuNumber;
            return "";
        if (index.column() == 2)
            return studentInfos[index.row()].stuName;
        if (index.column() == 3)
            return studentInfos[index.row()].stuID;
        if (index.column() == 4)
            //返回的类型 近似于html，使文本有一定的格式
         return studentInfos[index.row()].stuPhoneNumber;

          //  return QVariant();

        if (index.column() == 5)
            return studentInfos[index.row()].department;
        if (index.column() == 6)
            return studentInfos[index.row()].stuDescription;
    }

    if (role == Qt::CheckStateRole)
    {
        if (index.column() == colNumberWithCheckBox)
        {
            if (rowCheckStateMap.contains(index.row()))
                return rowCheckStateMap[index.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked; return Qt::Unchecked;
        }
    }

    return QVariant();
}


Qt::ItemFlags StudentInfoModel::flags( const QModelIndex &index ) const
{
    if (!index.isValid())
        return 0;


    if (index.column() == colNumberWithCheckBox)
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
   //设定第三列可编辑
    if(index.column() == 2)
    {
        return  Qt::ItemIsEnabled | Qt::ItemIsSelectable|Qt::ItemIsEditable;
    }

    //return  Qt::ItemIsEnabled | Qt::ItemIsSelectable|Qt::ItemIsEditable;
     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}


bool StudentInfoModel::setData( const QModelIndex &index, const QVariant &value, int role )
{
    if(!index.isValid())
        return false;
    if (role == Qt::CheckStateRole && index.column() == colNumberWithCheckBox)
    {
        if (value == Qt::Checked) //
        {
            rowCheckStateMap[index.row()] = Qt::Checked;
            if(studentInfos.size() > index.row())
                emit StudentInfoIsChecked(studentInfos[index.row()]);
        }
        else
        {
            rowCheckStateMap[index.row()] = Qt::Unchecked;
        }
    }
    return true;
}
void StudentInfoModel::AddStudentInfo( StudentInfo studentInfo)
{
    studentInfos.append(studentInfo);
}
//void StudentInfoModel::insertRows(int row, int count, const QModelIndex &parent)
//{
//    beginInsertRows(QModelIndex(),row,row);

//    endInsertRows();
//    return;
//}
