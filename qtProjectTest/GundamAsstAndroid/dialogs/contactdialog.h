#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>
#include "ui_contactdialog.h"

//namespace Ui {
//class ContactDialog;
//}

class ContactDialog : public QDialog, public Ui::ContactDialog
{
    Q_OBJECT
    
public:
    explicit ContactDialog(QWidget *parent = 0);
    ~ContactDialog();
    

};

#endif // CONTACTDIALOG_H
