#ifndef CONTACTMODEL_H
#define CONTACTMODEL_H

#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QIcon>
/*
 *类名：Contact
 *Attenton:联系人多个电话或者邮箱的话,用":"分开
 *eg:phone   110:120:130
 **/
//class Contact
//{
//public:
//    Contact();
//    Contact(const QString id, const QString number, const QString name, QString,QString mial=QString(),char alphabetGroup='A',QIcon icon=QIcon());
//    QString getId() const;
//    QString getNumber() const;
//    QString getName() const;
//    QString getGroup() const;
//    QIcon   getIcon() const;
//    QString operator [](int i)const;
//    QString operator ()(int i)const;
//    char getAlphabetGroup() const;
//    QString getMailName()const;

//    void setID(const QString &  id);
//public:
//    QString id;
//    QString number;
//    QString name;
//    QIcon  conIcon;
//    bool  concatcIcon ;
//    QString group;//群组

//    //new add
//    char  alphabetGroup;
//    QString mailName;
//};


class Contact
{
public:
    Contact();
    Contact(const QString id);
    QString getId() const;
    QString operator [](int i)const;
    QString operator ()(int i)const;

public:
    QString id;

};
/*类名：Contactmodel
 *MVC中存放联系人的model类
 *m_rowCheckStateMap来存放每行的checkBox的状态
 *m_contactList 来存放contact的信息
 *Qt::CheckState m_allCheckboxState 记录全选按钮的状态
 *bool m_selectBool  记录是否点击了全选按钮。
 **/
class Contactmodel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit Contactmodel(bool _show=true,QObject *parent = 0);
    void setShow(bool _show);
    bool clear();
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Contact getContactInfo(QModelIndex &);
    Qt::CheckState getCurrentState(QModelIndex );
    void    setCheckboxAllSelect();
    void    setAllCheckBoxState(Qt::CheckState _state);
    Qt::CheckState getAllCheckBoxState()const;
    int getSeclectedCount() const;
    QList<int> getSelectedRow();

    QList<Contact> getSeclectedContactS();
    QList<Contact> getContactsList();




    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool insertContacts(int position,QList<Contact> contactList);

    bool insertContact(int position,const Contact & con);
    bool removeContacts(int position,int count);
    bool removeContact(int position);

    //
    bool insertReContacts(int position,QList<Contact> contactList);
public:
    //  bool addContact(const Contact & _contact);
    
signals:
    void checkboxChanged();
    
public slots:
private:
    QList<Contact> m_contactList;
    QMap<int,Qt::CheckState> m_rowCheckStateMap;
    bool m_selectBool;
    Qt::CheckState m_allCheckboxState;

    bool m_show;//控制显示的列
};

/*ContactSortProxyModel  联系人排序代理类
 *作用： 主要是用来进行数据model的排序
 **/
class ContactSortProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    ContactSortProxyModel(QObject *parent = 0);
protected:
    //  bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const;
};


#endif // CONTACTMODEL_H
