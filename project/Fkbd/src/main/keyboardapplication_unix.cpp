#include <QWidget>

#include "keyboardapplication.h"





KeyboardApplication::KeyboardApplication(int &argc, char **argv):QApplication(argc,argv)
{
    m_keyWidget = NULL;
    m_focusWindow = 0;
}


void KeyboardApplication::setKeyboardWidget(QWidget * widget)
{
    m_keyWidget = widget;
}


void KeyboardApplication::typeText( const QString & msg)
{
   qDebug("KeyboardApplication::typeText %s",qPrintable(msg));
}

void KeyboardApplication::keysDown(const QString & key)
{
  // qDebug("KeyboardApplication::keyDown %s",qPrintable(key));
}

void KeyboardApplication::keysUp(const QString & key)
{
   // qDebug("KeyboardApplication::keyUp %s",qPrintable(key) );
}
