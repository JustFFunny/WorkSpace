#ifndef EXTENSION_H
#define EXTENSION_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include "form.h"
#include "mainwindow.h"

class Extension : public QWidget
{
    Q_OBJECT
public:
    explicit Extension(QWidget *parent = 0);
    
    void createBaseInfo();
    void createDetailInfo();
    void createFormInfo();
    void createMainWindowInfo();
public slots:
    void slotExtension();
private:
    QWidget *baseWidget;
    QWidget *detailWidget;
    Form * m_form;
    QMainWindow * m_mainwindows;
};

#endif // EXTENSION_H
