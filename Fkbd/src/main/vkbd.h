#ifndef VKBD_H
#define VKBD_H
#include <QDeclarativeView>
#include <QDeclarativeError>
#include <QList>
#include <QDesktopWidget>


class Vkbd : public QDeclarativeView
{
    Q_OBJECT
    Q_PROPERTY (int width READ width WRITE setWidth);
    Q_PROPERTY (int height READ height WRITE setHeight);
    Q_PROPERTY (int x READ x() WRITE setX)
    Q_PROPERTY (int y READ y() WRITE setY)
    Q_PROPERTY (int maxWidth READ maxWidth NOTIFY maxWidthChanged)
    Q_PROPERTY (int maxHeight READ maxHeight NOTIFY maxHeightChanged)
    Q_PROPERTY (bool moved READ moved) ;
    Q_PROPERTY (int state READ state WRITE setState);
    Q_PROPERTY (qreal opacity READ windowOpacity WRITE setWindowOpacity)
public:
    Vkbd(QWidget * parent = NULL);

    /** Return if window position has changed more than x pixels between clicks */
    bool moved() const;
    int state() const;
    int maxWidth() const;
    int maxHeight() const;


signals:
    void maxWidthChanged (int);
    void maxHeightChanged (int);
    void stateChanged(int);
    void currentTime(const QString & str);
    void textTyped(const QString & str);
    void timeOut();
    void closed();


public slots:
    void setWidth(int i);
    void setHeight(int i);
    void move(int x, int y);
    void setX(int x);
    void setY(int y);

    void setPressed(bool i);

    void keyDown(const QString &);
    void keyUp(const QString &);
    void typeText(const QString & msg);
    void setState(int state);


protected slots:
    void sizeInicjated(QSize size);
    void desktopResized(int);


protected:
    void mouseMoveEvent ( QMouseEvent * event );
    void closeEvent ( QCloseEvent * event );
    void init();
    bool m_pressed;
    bool m_moved;
    int  m_prevX, m_prevY;
    int m_state;
    QDesktopWidget * m_desktop;
};

#endif //VKBD_H
