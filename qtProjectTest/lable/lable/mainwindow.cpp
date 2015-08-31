#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <qcoreevent.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    offset = 0;
    myTimerId = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setText(const QString &newText)

{

     myText = newText;

     update();

     updateGeometry();

}


QSize MainWindow::sizeHint() const

{

     return fontMetrics().size(0, text());

}


void MainWindow::paintEvent(QPaintEvent * )

{

     QPainter painter(this);


     int textWidth = fontMetrics().width(text());

     if (textWidth < 1)

         return;

     int x = -offset;

     while (x < width()) {

         painter.drawText(x, 0, textWidth, height(),

                         Qt::AlignLeft | Qt::AlignVCenter, text());

         x += textWidth;

     }

}


void MainWindow::showEvent(QShowEvent * )

{

     myTimerId = startTimer(33);

}


void MainWindow::timerEvent(QTimerEvent *event)

{

     if (event->timerId() == myTimerId) {

         ++offset;

         if (offset >= fontMetrics().width(text()))

             offset = 0;

         scroll(-1, 0);

     } else {

         QMainWindow::timerEvent(event);

     }

}


void MainWindow::hideEvent(QHideEvent * )

{

     killTimer(myTimerId);

     myTimerId = 0;

}
