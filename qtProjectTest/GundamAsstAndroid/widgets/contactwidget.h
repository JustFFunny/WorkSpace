#ifndef CONTACTWIDGET_H
#define CONTACTWIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QListWidget>
#include <QSettings>
#include <QTableWidget>
#include "../dialogs/contactdialog.h"
#include "../classes/models/contactmodel.h"

namespace Ui {
class ContactWidget;
}

class ContactWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ContactWidget(QWidget *parent = 0);
    ~ContactWidget();

    QTcpSocket *socket;
    QMap<QString,Contact> *contactsMap;
   // QListWidget *listWidget;

    QTableWidget *tableWidget;

    ContactDialog *contactDialog;

    QString ip;
    qint16 port;

public slots:
    void getContactList();
    void readContactInfo();
    void showInfo(QString msg);
    void readContactInfoFished();
    void addContact();
    void delContact();
    
private:
    Ui::ContactWidget *ui;
};

#endif // CONTACTWIDGET_H
