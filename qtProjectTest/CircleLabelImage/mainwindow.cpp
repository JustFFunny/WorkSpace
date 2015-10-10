#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBitmap>
#include <QPainter>
/*方法1:对于地址有效
 *border-radius:50px;
 *border-image: url(:/image/1_qwer_boo.jpg.png);
 **/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap _pixmap("/home/wuqiankun/桌面/2.jpg");
    QPixmap tmpPixmap=PixmapToRound(_pixmap,50);
    ui->label->setPixmap(tmpPixmap);
}

/**
*@函数概要：把QPixmap变成半径为radius的圆形
*@作者：wuqiankun
*@mail:qiankun@nfs-china.com
*/
QPixmap MainWindow::PixmapToRound(const QPixmap &src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }

    QSize size(2*radius, 2*radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);

    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}
MainWindow::~MainWindow()
{
    delete ui;
}
