#include "faceform.h"
#include "ui_faceform.h"

faceForm::faceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::faceForm)
{
    ui->setupUi(this);
}

faceForm::~faceForm()
{
    delete ui;
}

void faceForm::on_pushButton_clicked()
{
    this->close();
    emit faceClicked("[smail.png]");
}

void faceForm::on_pushButton_2_clicked()
{
    this->close();
    emit faceClicked("[ali.gif]");
}
