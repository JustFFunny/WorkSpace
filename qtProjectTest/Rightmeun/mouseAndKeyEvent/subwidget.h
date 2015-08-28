#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QMenu>

class subWidget : public QWidget
{
    Q_OBJECT
public:
    explicit subWidget(QWidget *parent = 0);
    
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
signals:
    
public slots:
    void showMenu(const QPoint &pos);
    void showName();
private:
    QMenu * m_menu;
};

#endif // SUBWIDGET_H
