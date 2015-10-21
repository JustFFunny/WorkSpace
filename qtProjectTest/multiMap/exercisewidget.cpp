/*
 *void setWordWrap ( bool on )
 *If this property is true then label text is wrapped
 *where necessary at word-breaks; otherwise it is not wrapped at all.
 *所以跟我们认为的自动换行 是不一样的.
 *
**/
#include "exercisewidget.h"
#include <QHBoxLayout>
ExerciseWidget::ExerciseWidget(QWidget *parent) :
    QWidget(parent)
{
    label =  new QLabel(QObject::tr("初始文本"));
    label->setMaximumWidth(100);
    /*自适应大小,可有可无*/
    label->adjustSize();
    /*自动换行*/
    label->setWordWrap(true);
   label-> setGeometry(QRect(328, 240, 329, 27*4));
    button = new QPushButton(tr("改变文本"));
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addStretch();
    layout->addWidget(button);
    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addWidget(label);
    mainlayout->addLayout(layout);
    this->setLayout(mainlayout);
    /*让对话框大小总是以最合适的大小显示*/
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    connect(button, SIGNAL(released()), this, SLOT(changeText()));
}

void ExerciseWidget::changeText()
{
    label->setText(getText());
    label->adjustSize();
    label->setWordWrap(true);

    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    return ;
}


QString getText()
{
    static int  i = 0;
    QString str;
    if(i%3 == 0)
        str = QObject::tr("好好学习！");
    else if(i%3 == 1)
        str = QObject::tr("生活是道菜，味道让人爱！");
    else
        str = QObject::tr("毕竟西湖六月中ggggggg，风光不与四时同ghhh。接天莲叶无穷碧，映日荷花别样红。 \大人你好啊,不好啊为什么呢谁值看开那再说也许是其他的与阿因得到额扽的嫩的嫩的嫩扽大呢的这");
    i++;
    return str;
}
