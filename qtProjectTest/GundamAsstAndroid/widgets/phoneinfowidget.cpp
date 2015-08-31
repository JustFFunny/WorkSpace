/***********************************************************************
*Copyright 2010-20XX by 7ymekk
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
*   @author 7ymekk (7ymekk@gmail.com)
*
************************************************************************/


#include "phoneinfowidget.h"
#include "ui_phoneinfowidget.h"
#include <QSettings>

QString PhoneInfoWidget::humanReadableSize(long double size)
{
    long double sizeTmp = 0.0;
    QString strTmp = " B";
    //sizeTmp = size.toLongLong();
    sizeTmp = size;
    if (sizeTmp <= 1024)
    {
        strTmp.prepend(QString::number(sizeTmp, 'f', 0));
        return strTmp;
    }
    if (sizeTmp > 1024)
    {
        sizeTmp = sizeTmp / 1024;
        strTmp = " KiB";
    }
    if (sizeTmp > 1024)
    {
        sizeTmp = sizeTmp / 1024;
        strTmp = " MiB";
    }
    if (sizeTmp > 1024)
    {
        sizeTmp = sizeTmp / 1024;
        strTmp = " GiB";
    }
    strTmp.prepend(QString::number(sizeTmp, 'f', 2));
    return strTmp;
}

PhoneInfoWidget::PhoneInfoWidget(QWidget *parent, QString serialNumber) :
    QWidget(parent),
    ui(new Ui::PhoneInfoWidget)
{
    ui->setupUi(this);
    //this->setLayout(ui->gridLayout);

    this->rotation = 0;
    this->widthScreen = 320;
    this->heightScreen = 480;
    this->screenshot = QPixmap::fromImage(noScreenshotImage(this->widthScreen, this->heightScreen), Qt::AutoColor);
    this->ui->labelRgb565->setPixmap(this->screenshot);

    //this->setLayout(ui->layoutPhoneInfo);
    ui->lineEditSerialNumber->setText(serialNumber);

    QSettings settings;
    this->sdk=settings.value("sdkPath").toString();
    ip = settings.value("wlanIP").toString();
    port = settings.value("sPort").toInt();

    //this->timer.start(60000);
    //connect(&this->timer, SIGNAL(timeout()), this , SLOT(showPhoneInfo()));

    connect(this->ui->buttonSaveScreenshot, SIGNAL(clicked()), this, SLOT(saveScreenshot()));
    connect(this->ui->buttonRefreshScreenshot, SIGNAL(clicked()), this, SLOT(refreshScreenshot()));
    showPhoneInfo();
    refreshScreenshot();
}

PhoneInfoWidget::~PhoneInfoWidget()
{
    delete ui;
}

void PhoneInfoWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PhoneInfoWidget::showPhoneInfo()
{
        socket = new QTcpSocket();
        QString mesg = "PHONEINFO:GET\n";
        socket->connectToHost(ip,port,QTcpSocket::ReadWrite);
        if (socket->waitForConnected(2000))
        {
            socket->write(mesg.toStdString().c_str(), strlen(mesg.toStdString().c_str()));
            socket->waitForBytesWritten();
        }
        if(socket->waitForReadyRead(-1))
        {
            QString readData = QString::fromUtf8(socket->readLine());
            QStringList info = readData.split("/n")[0].split(":");

            QString mode = info.at(0);
            QString oper = info.at(1);
            QString numb = info.at(2);
            QString mac  = info.at(3);
            QString Imei = info.at(4);
            QString dt   = info.at(5);
            QString da   = info.at(6);
            QString it   = info.at(7);
            QString ia   = info.at(8);
            QString st   = info.at(9);
            QString sa   = info.at(10);
            QString bn   = info.at(11);

            ui->lineEditModel->setText(mode);
            ui->lineEditOperator->setText(oper);
            ui->lineEditNumber->setText(numb);
            ui->lineEditMac->setText(mac);
            ui->lineEditImei->setText(Imei);

            long double datat = dt.toLongLong();
            long double dataa = da.toLongLong();
            long double datal = datat-dataa;
            int datav = (int)(datal/datat*100);
            ui->lineEditDataAvailable->setText(PhoneInfoWidget::humanReadableSize(dataa));
            ui->lineEditDataUsed->setText(PhoneInfoWidget::humanReadableSize(datal));
            ui->lineEditDataSize->setText(PhoneInfoWidget::humanReadableSize(datat));
            ui->progressBarData->setMaximum(100);
            ui->progressBarData->setValue(datav);

            long double isdt = it.toLongLong();
            long double isda = ia.toLongLong();
            long double isdl = isdt-isda;
            int isdv = (int)(isdl/isdt*100);
            ui->lineEditSdcardAvailable->setText(PhoneInfoWidget::humanReadableSize(isda));
            ui->lineEditSdcardUsed->setText(PhoneInfoWidget::humanReadableSize(isdl));
            ui->lineEditSdcardSize->setText(PhoneInfoWidget::humanReadableSize(isdt));
            ui->progressBarSdcard->setMaximum(100);
            ui->progressBarSdcard->setValue(isdv);


            long double esdt = st.toLongLong();
            long double esda = sa.toLongLong();
            long double esdl = esdt-esda;
            int esdv = (int)(esdl/esdt*100);
            ui->lineEditSdcardAvailable_2->setText(PhoneInfoWidget::humanReadableSize(esda));
            ui->lineEditSdcardUsed_2->setText(PhoneInfoWidget::humanReadableSize(esdl));
            ui->lineEditSdcardSize_2->setText(PhoneInfoWidget::humanReadableSize(esdt));
            ui->progressBarSdcard_2->setMaximum(100);
            ui->progressBarSdcard_2->setValue(esdv);

            ui->progressBarBatteryLevel->setValue(bn.toInt());
        }
        socket->disconnectFromHost();
        socket->close();
}

void PhoneInfoWidget::on_pushButton_clicked()
{
    showPhoneInfo();
}


void PhoneInfoWidget::showScreenshot(QImage image, int width, int height)
{
    this->rotation = 0;
    QSize scaledSize = QSize(width, height);
    scaledSize.scale(this->size(), Qt::KeepAspectRatio);
    this->screenshot = QPixmap::fromImage(image, Qt::AutoColor);
    this->ui->labelRgb565->setPixmap(this->screenshot.scaled(this->ui->labelRgb565->size(),
                                                             Qt::KeepAspectRatio,
                                                             Qt::SmoothTransformation));
    disconnect(this, SLOT(showScreenshot(QImage,int,int)));
}

void PhoneInfoWidget::takeScreenshot()
{
    threadScreenshot.widthScreen = this->ui->labelRgb565->width();
    threadScreenshot.heightScreen = this->ui->labelRgb565->height();
    threadScreenshot.start();
    connect(&threadScreenshot, SIGNAL(gotScreenshot(QImage, int, int)), this, SLOT(showScreenshot(QImage, int, int)));
}

void PhoneInfoWidget::refreshScreenshot()
{
    this->rotation = 0;

    QSize scaledSize = QSize(this->widthScreen, this->heightScreen);
    scaledSize.scale(this->ui->labelRgb565->size(), Qt::KeepAspectRatio);
    QPixmap pix = QPixmap::fromImage(noScreenshotImage(scaledSize.width(), scaledSize.height()), Qt::AutoColor);
    this->ui->labelRgb565->setPixmap(pix);
    takeScreenshot();
}

void PhoneInfoWidget::updateScreenshotLabel()
 {
    QMatrix matrix;
    matrix.rotate(this->rotation);
    QImage image;
    image = this->screenshot.toImage();
    image = image.transformed(matrix);

    QSize scaledSize = image.size();
    scaledSize.scale(this->ui->labelRgb565->size(), Qt::KeepAspectRatio);

    this->ui->labelRgb565->setPixmap(QPixmap::fromImage(image.scaled(this->ui->labelRgb565->size(),
                                                             Qt::KeepAspectRatio,
                                                             Qt::SmoothTransformation), Qt::AutoColor));
 }

void PhoneInfoWidget::resizeEvent(QResizeEvent * event)
{
    Q_UNUSED(event);

    QSize scaledSize = this->screenshot.size();
    scaledSize.scale(this->ui->labelRgb565->size(), Qt::KeepAspectRatio);
    if (!this->ui->labelRgb565->pixmap() || scaledSize != this->ui->labelRgb565->pixmap()->size())
        updateScreenshotLabel();
}

void PhoneInfoWidget::saveScreenshot()
{
    QFile plik;
    plik.setFileName(QFileDialog::getSaveFileName(this, tr("Save File..."), "./screenshot.png", tr("Png file")+" (*.png)"));
    if (plik.fileName().isEmpty())
        return;
    if (plik.open(QFile::WriteOnly))
    {
        QMatrix matrix;
        matrix.rotate(this->rotation);
        QImage image;
        image = this->screenshot.toImage();
        image = image.transformed(matrix);
        image.save(&plik, "PNG");
        plik.close();
    }
}


