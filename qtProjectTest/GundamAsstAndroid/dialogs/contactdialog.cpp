#include "contactdialog.h"
#include "ui_contactdialog.h"

#include <QRegExp>

ContactDialog::ContactDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);

    //QRegExpValidator *pRevalidotor = new QRegExpValidator(regExp, this);
    //QRegExp regExp1("^[A-Za-z0-9_]+$");
    QRegExp regExp1("^[^:]*$");
    this->lineEdit_name->setValidator(new QRegExpValidator(regExp1, this));

    QRegExp regExp2("^[0-9]*$");
    this->lineEdit_number->setValidator(new QRegExpValidator(regExp2, this));

    this->pushButton_save->setDefault(true);
    connect(this->pushButton_save,SIGNAL(clicked()),this,SLOT(accept()));
    connect(this->pushButton_quit,SIGNAL(clicked()),this,SLOT(reject()));

}

ContactDialog::~ContactDialog()
{
}
