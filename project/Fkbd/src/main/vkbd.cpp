#include <QUrl>
#include <QDeclarativeContext>
#include <QMouseEvent>
#include <QDeclarativeEngine>
#include <QDeclarativeComponent>
#include <QMessageBox>
#include <QFile>
#include "vkbd.h"
#include "keyboardapplication.h"

Vkbd::Vkbd(QWidget * parent): QDeclarativeView(parent)
{
  init();
}


bool Vkbd::moved() const
{
    return m_moved;
}


int Vkbd::state() const
{
    return m_state;
}


/*------------------------------------------------------------------------------------------------
                                 P U B L I C    S L O T S
------------------------------------------------------------------------------------------------*/
void Vkbd::keyDown(const QString & key)
{
  emit textTyped(key);
  KeyboardApplication * kApp = qobject_cast<KeyboardApplication *>(qApp);
      if (kApp)
         kApp->keysDown(key);
}


void Vkbd::keyUp(const QString & key)
{
    KeyboardApplication * kApp = qobject_cast<KeyboardApplication *>(qApp);
    if (kApp)
        kApp->keysUp(key);

}


void Vkbd::typeText(const QString & msg)
{
    emit textTyped(msg);
    KeyboardApplication * kApp = qobject_cast<KeyboardApplication *>(qApp);
    if (kApp)
        kApp->typeText(msg);
}


void Vkbd::setState(int state)
{
   if (m_state!=state)
   {
     m_state = state;
     stateChanged(state);
   }
}


int Vkbd::maxWidth() const
{
      QRect r = m_desktop->screenGeometry(this);
      return r.width();
}


int Vkbd::maxHeight() const
{
    QRect r = m_desktop->screenGeometry(this);
    return r.height();
}


void Vkbd::setWidth(int i)
{
  resize(i,height());
}


void Vkbd::setHeight(int i)
{
    resize (width(),i);
}


void Vkbd::move(int x, int y)
{
    QDeclarativeView::move(x,y);
}


void Vkbd::setX(int x)
{
    QDeclarativeView::move(x,y());
}


void Vkbd::setY(int y)
{
    QDeclarativeView::move(x(),y);
}


void Vkbd::setPressed(bool i)
{
    m_pressed = i;
}


/*------------------------------------------------------------------------------------------------
                                 P R O T E C T E D  S L O T S
------------------------------------------------------------------------------------------------*/
void Vkbd::sizeInicjated(QSize size)
{
  //qDebug("Size %d,%d",size.width(),size.height()) ;
  resize(size);
}


void Vkbd::desktopResized(int desktop)
{
  if( m_desktop->screenNumber(this) == desktop )
  {
          QRect r = m_desktop->screenGeometry(this);
          emit maxWidthChanged (r.width());
          emit maxHeightChanged (r.height());
  }
}


/*------------------------------------------------------------------------------------------------
                                        P R O T E C T E D
------------------------------------------------------------------------------------------------*/
void Vkbd::init()
{
  m_pressed = false;
  m_prevX = 0xffff;
  m_state = 0;

  setMouseTracking(true);
  connect(this,SIGNAL(sceneResized(QSize)),this,SLOT(sizeInicjated(QSize)));
  setAttribute(Qt::WA_TranslucentBackground);//窗体透明
  viewport()->setAttribute(Qt::WA_TranslucentBackground);
  setFocusPolicy(Qt::NoFocus) ;
  viewport()->setFocusPolicy(Qt::NoFocus);

  /* Recomended by http://doc.trolltech.com/4.7/qml-integration.html */
  QGraphicsView::setOptimizationFlags(QGraphicsView::DontSavePainterState);
  QGraphicsView::setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  scene()->setItemIndexMethod(QGraphicsScene::NoIndex);


  //setOptimizationFlags(QGraphicsView::DontSavePainterState);
  //setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

  setWindowTitle("Virtual Keyboard by 3electrons");

  m_desktop = new QDesktopWidget();
  connect(m_desktop,SIGNAL(resized(int)),this,SLOT(desktopResized(int)));
  connect(this,SIGNAL(destroyed()),m_desktop,SLOT(deleteLater()));

  QDeclarativeContext * context = rootContext(); // globalContext
  context->setContextProperty("keyboard",this);

  QString path = QString("file:///%1").arg(QCoreApplication::applicationDirPath()+"/keyboard");

  context->setContextProperty("programsUrl",path);

//qDebug("Path %s",qPrintable(path));
//engine()->addImportPath(path);
  engine()->addImportPath(":keyboard/resources/keyboard");
  engine()->addImportPath(":keyboard/pic/resources/keyboard/pic");
  engine()->addImportPath(":keyboard/pic/resources/keyboard/digits");


  setSource(QUrl("qrc:keyboard/resources/keyboard/Vkbd.qml"));
  //execute();

  QRect r = m_desktop->screenGeometry(this);

  context->setContextProperty("maxWidth",r.width());
  context->setContextProperty("maxHeight",r.height());
  context->setContextProperty("state","maximized");

}//init


void Vkbd::mouseMoveEvent ( QMouseEvent * event )
{

    if (m_state == 2 )
    {
      QDeclarativeView::mouseMoveEvent(event);
      return;
    }

  int x_m = 0, y_m = 0;
  QRect r = m_desktop->screenGeometry(this);

  if (m_pressed && m_prevX != 0xffff)
     //  && ( qAbs(m_prevX - event->x()) > 5 || qAbs(m_prevY - event->y())> 5 ))

    {
     x_m = event->x() - m_prevX, y_m = event->y() - m_prevY;
     int newX = this->x() + x_m, newY = this->y() + y_m ;

     if (0 == m_state )
       newX = r.width() - this->width(); // minimized stick to right
     else // do not move out of screen  in x-asis
     {
         if ((newX + width()) > r.width())
               newX = r.width() - width();
           if (newX < 0)
               newX = 0;
     }
     x_m = newX - this->x();
      //// do not move out of screen in y-axis
       if ( (newY + this->height()) > r.height())
             newY = r.height() - this->height();
       if (newY < r.y() )
           newY = r.y();
       y_m = newY - this->y();

     move(newX, newY);
     m_moved = true;

      //qDebug("Desktop %d,%d, Window %d,%d, newPos %d,%d",r.width(),r.height(),width(),height(),newX,newY);
  }
  else {
    m_moved = false;
  }
  m_prevX = event->x()- x_m;
  m_prevY = event->y()- y_m;
}

void Vkbd::closeEvent ( QCloseEvent * event )
{
    emit closed();
}
