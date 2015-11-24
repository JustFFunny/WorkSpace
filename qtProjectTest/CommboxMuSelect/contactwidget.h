#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QWidget>
#include <QModelIndex>
#include <QSignalMapper>
#include <QTcpSocket>
#include "../dialogs/contactdialog.h"
#include "../threads/contactimportthread.h"
#include "../objects/contactobject.h"
class Contact;
class Contactmodel;
class QTableView;
class QSortFilterProxyModel;
class ContactSortProxyModel;
class QTableView;
class SearchlineEdit;
        namespace Ui {
    class Contactwidget;
}

/*
 *类名：Contactwidget
 *私有成员：
 *
 *ContactSortProxyModel * m_sortProxyModel 排序代理类
 *Contactmodel          * m_contactModel   联系人数据类
 *SearchlineEdit        * m_searchLineEdit  搜索框和刷新按钮的组合
 **/
class Contactwidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Contactwidget(QWidget *parent = 0);
    ~Contactwidget();
    void initUI();
    void createConnect();
    void createButtonConnect();
    void iniData();
    void addContactData(const Contact& _tmpCon);
    void creatorDetailWidgte(const Contact & _tmpCon);

    bool getcontact ;

private:
    ContactSortProxyModel * m_sortProxyModel;
    Contactmodel          * m_contactModel;
    SearchlineEdit        * m_searchLineEdit;
    QTableView            * m_tableView;
    ContactDialog         * m_contactDialog;
public slots:
    void filter();
    void searchfilter(const QString & pattern);
    void showDetailedInfo(QModelIndex  );
    void refreshUI();

    void creatContactSlot();
    void saveCreateContactSlot();
    void cancelContactDialogSlot();

    void importContactSlot();
    void exportContactSlot();
    void deleteContactSlot();
    void editContactSlot();
    void selectAllRowOrNOSlot();

    void checkBoxChangeState();
    void forShowSelectedRow(QModelIndex,QModelIndex);
    void forShowSelectedRow();

    void buttonsSlot(QString );


    void importFailureSlot();
    void addModel(const Contact & _contact);

    void saveEditContactSlot();

    //Test

private:
    Ui::Contactwidget *ui;
    QWidget * m_detailWidget;//描述详细信息的Widget
    QVBoxLayout  *mainVLayout;//描述详细信息的HBoxLayout
    QVBoxLayout * m_vboxlayout;//
    QSignalMapper * m_signalMapper;//信号转发器
    ContactImportThread * m_conImportThread;//导入的线程
    ContactObject * m_getContactObject;//获取联系人的Object对象
    Contact  m_curContact;//当前显示的联系人信息
};

#endif // CONTACTWIDGET_H
