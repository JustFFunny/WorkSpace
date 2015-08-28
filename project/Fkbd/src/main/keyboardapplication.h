#ifndef KEYBOARDAPPLICATION_H
#define KEYBOARDAPPLICATION_H

#include <QApplication>
#include <QHash>

class KeyboardApplication : public QApplication
{
 Q_OBJECT
 public:
    KeyboardApplication(int &argc, char **argv);

    void setKeyboardWidget(QWidget * widget);

public slots:
    void typeText( const QString & msg);
    void keysDown(const QString & keys);
    void keysUp(const QString & keys);

protected:

    void init();
    QString resolve(const QString & text );

#ifdef Q_WS_WIN
    bool winEventFilter(MSG * msg, long * result);
    void clearFocus();
   
#endif


    QHash<QString,QString> m_keys;
    QWidget * m_keyWidget;
    WId m_focusWindow;
};

#endif // WINAPPLICATION_H
