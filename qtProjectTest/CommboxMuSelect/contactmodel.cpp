#include "contactmodel.h"

#include <QDebug>
#include <QFont>
Contact::Contact()
{
}

Contact::Contact(const QString id)
{
    this->id = id;

    //qDebug()<<alphabetGroup;
}

QString Contact::getId() const
{
    return this->id;
}



/*函数名：QString Contact::operator [](int i)const
 *参数：int i  取Contact第i个属性
 *返回值：QString 取Contact第i个属性的信息
 **/
QString Contact::operator [](int i)const
{
    switch (i) {
    case 0:
        return id;
    case 1://照片
        return id;

    default:
        break;
    }
}

/**
*@函数概要：操作符号()重载
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
QString Contact::operator ()(int i)const
{
    switch (i)
    {
    case 0:
        return id;
    case 1:
        return id;

    default:
        break;
    }
}



Contactmodel::Contactmodel(bool _show,QObject *parent) :
    QAbstractTableModel(parent),m_show(_show)
{
    m_rowCheckStateMap.clear();
    m_contactList.clear();
    m_selectBool=false;
}

/**
*@函数概要：设置数据是否全部显示,默认构造函数中是全部显示,
*如果想设置不是全部显示,设置该函数的参数为false;
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
void Contactmodel::setShow(bool _show)
{
    m_show=_show;
}


/*函数名：clear()
 *函数参数：无
 *函数功能：清空Contactmodel的数据
 **/
bool Contactmodel::clear()
{
    if(!this->m_contactList.isEmpty())
    {
        beginRemoveRows(QModelIndex(),0,this->m_contactList.count()-1);
        m_contactList.clear();
        m_rowCheckStateMap.clear();
        endRemoveRows();
        return true;
    }
    return false;
}

int Contactmodel::rowCount(const QModelIndex &parent) const
{
    return m_contactList.count();
}

int Contactmodel::columnCount(const QModelIndex &parent) const
{
    return 1;
}
QVariant Contactmodel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(m_show)
        {
            return m_contactList[index.row()][index.column()];
        }
        else
        {
            return m_contactList[index.row()](index.column());
        }

    }
    if(role == Qt::CheckStateRole)
    {

        //if(index.column() == 0)
        {
            if (m_rowCheckStateMap.contains(index.row()))
                return m_rowCheckStateMap[index.row()] == Qt::Checked ? Qt::Checked : Qt::Unchecked; return Qt::Unchecked;
        }
    }
    return QVariant();
}

QVariant Contactmodel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }
    if(orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0:
            return QVariant("");
        case 1:
            return QVariant("");
        case 2:
            return QVariant("Name");
        case 3:
            return "Phone";
        case 4:
            return "Group";
        default:
            return QVariant();
        }
    }
    else if(orientation == Qt::Vertical)
    {
        //return QString("%1").arg(section);
        return  QVariant();
    }

}

Contact Contactmodel::getContactInfo(QModelIndex & _index)
{
    return this->m_contactList.at(_index.row());
}

/*功能：得到该行的 checkBox的状态
 **/
Qt::CheckState Contactmodel::getCurrentState(QModelIndex  _index)
{
    // return m_rowCheckStateMap.find(_index.row());
    return m_rowCheckStateMap.value(_index.row());
}

/*函数名：setCheckboxAllSelect
 *作用： 设置所有MVC 视图中的checkBox的状态，并显示。
 **/
void  Contactmodel::setCheckboxAllSelect()
{
    m_selectBool=true;
    for(int i=0 ;i< m_contactList.count();++i)
    {
        this->setData( this->index(i,0),QVariant(),Qt::CheckStateRole);
    }
    m_selectBool=false;
}

/*函数名：setAllCheckBoxState
 *作用：设置全选按钮的状态。
 */
void Contactmodel::setAllCheckBoxState(Qt::CheckState _state)
{
    m_allCheckboxState=_state;
}

/*函数名：getAllCheckBoxState
 *作用：得到全线按钮的状态，这里只设置了两种状态，
 *全选和全不选，没有设置中间状态
 **/
Qt::CheckState Contactmodel::getAllCheckBoxState()const
{
    return m_allCheckboxState;
}

/*函数名：getSeclectedCount
 *作用：返回选中的行的总数
 **/
int Contactmodel::getSeclectedCount() const
{
    return m_rowCheckStateMap.keys(Qt::Checked).count();
}

/*函数名：getSelectedRow
 *参数：无
 *返回值：当前列表中选中的行号
 *会出现序列混乱，所以应该从尾部向前删。
 *是升序排列的
 **/
QList<int> Contactmodel::getSelectedRow()
{
    return m_rowCheckStateMap.keys(Qt::Checked);
}


QList<Contact> Contactmodel::getSeclectedContactS()
{
    QList<Contact> _contactList;
    QList<int> _selectedRows=this->getSelectedRow();
    for(int i=0;i< _selectedRows.count(); ++i)
    {
        _contactList.push_back(m_contactList.at(_selectedRows.at(i)));
    }
    return _contactList;
}


/*函数作用：返回短信列表信息
 **/
QList<Contact> Contactmodel::getContactsList()
{
    return m_contactList;
}


/**  不对
*@函数概要：返回插入到List列表的位置,
*      插入的位置是第一个 出现字母的位置,
*      如果不是以字母开头,则插入到列表的前端.
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/




Qt::ItemFlags Contactmodel::flags(const QModelIndex &index) const
{
    //if (!index.isValid())
       // return 0;
    //    //行号超过一定范围的 返回空
    //    if(index.column() == 0)
    //    {
    //        return Qt::ItemIsEnabled | Qt::ItemIsSelectable|Qt::ItemIsUserCheckable;
    //    }

    return Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsUserCheckable;

}
bool Contactmodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug()<<"enter"<<index.row();
    if(!index.isValid())
        return false;


    if(role == Qt::CheckStateRole )
    {
        if(value ==Qt::Checked)
        {
            m_rowCheckStateMap[index.row()] = Qt::Checked;
            // if(m_contactList.count() > index.row())
            {
                //发送信号，，某一行被点击了
                emit dataChanged(index,index);
            }
        }
        else
        {
            m_rowCheckStateMap[index.row()] = Qt::Unchecked;
            emit checkboxChanged();
        }

    }
    return true;
}

/*
 *函数名：insertContacts()
 *参数： int position 插入位置的起点;
 *     QList<Contact> contactList 插入的联系人列表
 **/
bool Contactmodel::insertContacts(int position,QList<Contact> contactList)
{
    beginInsertRows(QModelIndex(),position,position+contactList.count()-1);
    while(!contactList.isEmpty())
    {
        this->m_contactList.insert(position,contactList.takeFirst());
    }
    endInsertRows();
    return true;
}

/**
*@函数概要：和上面的函数插入的顺序不同.
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
bool Contactmodel::insertReContacts(int position,QList<Contact> contactList)
{
    beginInsertRows(QModelIndex(),position,position+contactList.count()-1);
    while(!contactList.isEmpty())
    {
        this->m_contactList.insert(position,contactList.takeLast());
        m_rowCheckStateMap.insert(position,Qt::Unchecked);
    }
    endInsertRows();
    return true;
}

/*
 *函数名：insertContact()
 *参数： int position 插入位置的起点;
 *     Contact cont 插入的联系人
 **/
bool Contactmodel::insertContact(int position,const Contact & con)
{
    beginInsertRows(QModelIndex(),position,position);
    m_contactList.insert(position,con);
    m_rowCheckStateMap.insert(position,Qt::Unchecked);
    endInsertRows();
    return true;
}

/*
 *函数名： removeContacts()
 *参数： int position 删除位置的起点;
 *      int count    删除的总数
 * 作用：删除行号，并发送信号已选中的checkBox的个数。
 **/
bool Contactmodel::removeContacts(int position,int count)
{
    beginRemoveRows(QModelIndex(),position,position+count-1);
    for (int row=0;row < count;++row)
    {
        m_contactList.removeAt(position);
        m_rowCheckStateMap.remove(position);
    }
    endRemoveRows();
    emit checkboxChanged();
    return true;
}
bool Contactmodel::removeContact(int position)
{
    beginRemoveRows(QModelIndex(),position,position);
    m_contactList.removeAt(position);
    m_rowCheckStateMap.remove(position);
    endRemoveRows();
    emit checkboxChanged();
    return true;
}

//bool Contactmodel::addContact(const Contact & _contact)
//{
//    beginInsertRows(QModelIndex(),0,0);

//    this->m_contactList.insert(0,_contact);

//    endInsertRows();
//    return true;
//}




ContactSortProxyModel::ContactSortProxyModel(QObject *parent )
{
}

/*函数名：  bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
 *函数功能：过滤接受的行 ，即过滤出要显示的行
 *   return true，则接受该行，反之则不
 *函数参数：int sourceRow    const QModelIndex &sourceParent
*/
//bool ContactSortProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
//{
//    QModelIndex _index=sourceModel()->index(sourceRow,3,sourceParent);
//    return sourceModel()->data(_index).toString().contains(filterRegExp());
//}

/*
 *函数名：bool ContactSortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
 *函数功能：排序，如果left的关键字 < right的关键字 返回true,否则返回flase;left right是两行的索引
 *函数参数：const QModelIndex &left ，const QModelIndex &right
 **/
bool ContactSortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QString leftName=sourceModel()->data(left).toString();

}
