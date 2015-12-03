#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>
#include<QStringList>

//具有良好行为的modle也会实现headerData(),返回标题中显示的数据
//具有层级结构，也应该实现index(),parent()  QModelIndex index=modle->index(row,colum,parent);,
//当然具有层级结构的，也应该实现 columCount()
//一个数据项可以有很多的角色，根据角色不同输出不同的数据\



//delegate会在创建编辑器之前检查数据项是否可编辑，model 必须让delegate知道他的数据项是可编辑的;
//这可以 通过为 每一个数据项返回一个正确的标记得到
//delegeate会使用setData(),对model中的数据进行设置

//既然model中的每行对应与一个string，那么插入函数在stringlist中制定位置插入一个空的string
//父index通常用于决定model中行列的位置

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StringListModel(const QStringList & strlist,QObject *parent = 0);
    //重新实现的函数
        int rowCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;

        QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;

        //可编辑的model 改变数据内容
        Qt::ItemFlags flags(const QModelIndex &index) const;
        bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);

        //插入 删除行
        bool insertRows(int position,int rows,const QModelIndex & index=QModelIndex());
        bool removeRows(int position,int rows,const QModelIndex & index=QModelIndex());
signals:
    
public slots:
private:
        QStringList m_strList;
};

#endif // STRINGLISTMODEL_H
