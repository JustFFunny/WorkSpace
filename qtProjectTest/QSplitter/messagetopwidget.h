/*
 *类名：MessagetopWidget
 *作用：短信界面的顶层widget,主要是为了解决 中间分割线。
 **/
#ifndef MESSAGETOPWIDGET_H
#define MESSAGETOPWIDGET_H

#include <QWidget>
#include "searchlineedit.h"
class QLabel;
class QPushButton;
class QSplitter;
class QSpacerItem;
class QToolButton;
class QHBoxLayout;
class QLineEdit;

class MessagetopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MessagetopWidget(QWidget *parent = 0);
    ~MessagetopWidget();
    void setLableName(QString &);
    
signals:
    
public slots:

private:
    //分割器
    QSplitter * m_splitter;
    QLabel * m_nameLable;
    SearchlineEdit * m_searchLineEdit;
    QHBoxLayout * m_mainLayout;

};

#endif // MESSAGETOPWIDGET_H
