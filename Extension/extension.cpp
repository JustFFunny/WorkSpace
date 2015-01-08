#include "extension.h"

Extension::Extension(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle(tr("Extension Dialog"));
    createMainWindowInfo();
    createBaseInfo();
    // createDetailInfo();
   createFormInfo();

    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(m_mainwindows);
    layout->addWidget(baseWidget);
    // layout->addWidget(detailWidget);

     layout->addWidget(m_form);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    layout->setSpacing(10);
    setLayout(layout);

}
void Extension::createFormInfo()
{
    m_form =new Form;
    m_form->setFixedSize(200,100);
    m_form->setAutoFillBackground(true);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(106,116,128));
    m_form->setPalette(palette);
    m_form->hide();
}
void Extension::createMainWindowInfo()
{
    m_mainwindows=new QMainWindow;
    m_mainwindows->setFixedSize(200,300);
    m_mainwindows->setAutoFillBackground(true);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(110,0,201));
    m_mainwindows->setPalette(palette);


}

void Extension::createBaseInfo()
{
    baseWidget=new QWidget;

    QLabel *nameLabel = new QLabel(tr("Name:"));
    QLineEdit *nameEdit = new QLineEdit;
    QLabel *sexLabel = new QLabel(tr("Sex:"));
    QComboBox *sexComboBox = new QComboBox;
    sexComboBox->addItem("male");
    sexComboBox->addItem("female");


    QPushButton *okButton = new QPushButton(tr("OK"));
    QPushButton *detailButton = new QPushButton(tr("Detail"));
    connect(detailButton,SIGNAL(clicked()),this,SLOT(slotExtension()));


    QDialogButtonBox *btnBox = new QDialogButtonBox(Qt::Vertical);
    btnBox->addButton(okButton,QDialogButtonBox::ActionRole);
    btnBox->addButton(detailButton,QDialogButtonBox::ActionRole);


    QGridLayout *gride = new QGridLayout;
    gride->addWidget(nameLabel,0,0);
    gride->addWidget(nameEdit,0,1);
    gride->addWidget(sexLabel,1,0);
    gride->addWidget(sexComboBox,1,1);


    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addLayout(gride);
    hbox->addStretch();
    hbox->addWidget(btnBox);
    baseWidget->setLayout(hbox);


}

void Extension::createDetailInfo()
{
    detailWidget = new QWidget;
    detailWidget->setAutoFillBackground(true);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(106,116,128));
    detailWidget->setPalette(palette);
    QLabel *label1 = new QLabel(tr("Age"));
    QLineEdit *ageEdit = new QLineEdit;
    ageEdit->setText("30");
    QLabel *label2 = new QLabel(tr("Department"));
    QComboBox *deptComboBox = new QComboBox;
    deptComboBox->addItem(tr("dept 1"));
    deptComboBox->addItem(tr("dept 2"));
    deptComboBox->addItem(tr("dept 3"));
    deptComboBox->addItem(tr("dept 4"));
    QLabel *label3 = new QLabel(tr("email:"));
    QLineEdit *edit = new QLineEdit;


    QGridLayout *grid = new QGridLayout;
    grid->addWidget(label1,0,0);
    grid->addWidget(ageEdit,0,1);
    grid->addWidget(label2,1,0);
    grid->addWidget(deptComboBox,1,1);
    grid->addWidget(label3,2,0);
    grid->addWidget(edit,2,1);

    detailWidget->setLayout(grid);

    detailWidget->hide();

}


void Extension::slotExtension()
{
    //    if(detailWidget->isHidden())
    //    {
    //        detailWidget->show();
    //    }
    //    else
    //    {
    //        detailWidget->hide();
    //    }
//    if(m_mainwindows->isHidden())
//    {
//        m_mainwindows->show();
//    }
//    else
//    {
//        m_mainwindows->hide();
//    }
    if(m_form->isHidden())
    {
        m_form->show();
    }
    else
    {
        m_form->hide();
    }
}
