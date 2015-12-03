#include "searchedit.h"

#include <QLabel>
#include <QToolButton>
#include <QSplitter>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QtWidgets>
searchEdit::searchEdit(QWidget *parent) :
    QWidget(parent)
{
 /*
    QLineEdit * searchBox=new QLineEdit;

    QHBoxLayout * h=new QHBoxLayout;
    QLabel * _lable= new QLabel(QPixmap(":/icon/path"));


    searchBox->setLayout(h);
    QHBoxLayout * mainLayout=new QHBoxLayout;
    mainLayout->addWidget(searchBox);
    setLayout(mainLayout);
  */

    QLabel *forward_path = new QLabel();
    QLineEdit *forward_line_edit = new QLineEdit();
    QLineEdit *search_line_edit = new QLineEdit();
    QToolButton *forward_button = new QToolButton(this);
    QToolButton *search_button = new QToolButton(this);



    forward_button->setToolTip("forward");
    search_button->setToolTip("search");
    // 占位符 ，就是当焦点不在当前位置的时候，设置的内容
    forward_line_edit->setPlaceholderText("computer");
    search_line_edit->setPlaceholderText("search");

    forward_path->setPixmap(QPixmap(":/res/1"));
    forward_path->setAlignment(Qt::AlignRight | Qt::AlignVCenter);


    QIcon forward_icon = QIcon(":/res/2");
    forward_button->setFixedSize(25, 24);
    forward_button->setIcon(forward_icon );
    forward_button->setIconSize(QSize(16, 16));
    forward_button->setAutoRaise(true);
    forward_button->setCursor(Qt::ArrowCursor);
    forward_button->setStyleSheet("background:transparent;");

    QIcon search_icon = QIcon(":/res/3");
    search_button ->setFixedSize(25, 24);
    search_button ->setIcon(search_icon );
    search_button ->setIconSize(QSize(16, 16));
    search_button ->setAutoRaise(true);
    search_button ->setCursor(Qt::ArrowCursor);
    search_button ->setStyleSheet("background:transparent;");


    forward_path->setFixedSize(20, 24);
    forward_line_edit->setMinimumSize(100, 25);
    search_line_edit->setMinimumSize(50, 25);



    QSplitter *search_splitter = new QSplitter();
    search_splitter->setFrameShape(QFrame::NoFrame);
    search_splitter->setHandleWidth(1);

    //forward_line_edit内设置布局
    QHBoxLayout *forward_layout = new QHBoxLayout();
    forward_layout->addWidget(forward_path);
    forward_layout->addStretch();
    forward_layout->addWidget(forward_button);
    forward_layout->setSpacing(0);
    forward_layout->setContentsMargins(0, 0, 0, 0);
    forward_line_edit->setLayout(forward_layout);

    //防止文本框输入内容位于按钮之下
    forward_line_edit->setTextMargins(forward_path->width(), 0, forward_button->width(), 0);



    QHBoxLayout *search_layout = new QHBoxLayout();
    search_layout->addStretch();
    search_layout->addWidget(search_button);
    search_layout->setSpacing(0);
    search_layout->setContentsMargins(0, 0, 0, 0);
    search_line_edit->setLayout(search_layout);
    search_line_edit->setTextMargins(0, 0, search_button->width(), 0);


   //分割器 添加子控件
    search_splitter->addWidget(forward_line_edit);
    search_splitter->addWidget(search_line_edit);
    search_splitter->setStretchFactor(0, 8);
    search_splitter->setStretchFactor(1, 2);
    //不能被设置（折叠）为0
    search_splitter->setChildrenCollapsible(false);


    forward_line_edit->setStyleSheet("QLineEdit{border-style:outset; border-top-width:1px; border-left-width:1px; border-bottom-width:1px;border-top-color:gray; border-left-color:gray; border-bottom-color:gray; background:white;}");
    search_line_edit->setStyleSheet("QLineEdit{border-style:outset; border-top-width:1px; border-right-width:1px; border-bottom-width:1px;border-top-color:gray; border-right-color:gray; border-bottom-color:gray; background:white;}");
    search_splitter->setStyleSheet("QSplitter::handle{background:lightgray;}");

    QHBoxLayout * mainLayout=new QHBoxLayout;
//    mainLayout->addWidget(forward_line_edit);
//     mainLayout->addWidget(forward_line_edit);
     mainLayout->addWidget(search_splitter);
     setLayout(mainLayout);

}
