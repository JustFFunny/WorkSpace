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


#include "mainwindow.h"
#include "../classes/application.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int w, h;
    if (this->size().height() > qApp->desktop()->height())
        h = qApp->desktop()->height() - 150;
    else
        h = this->size().height();
    if (this->size().width() > qApp->desktop()->width())
        w = qApp->desktop()->width() - 150;
    else
        w = this->size().width();
    this->resize(w, h);
    this->setFixedSize(860,560);

    this->settingsWidget = new SettingsWidget;

    android = new AndroidAPK;

    this->shellWidget = NULL;
    this->screenshotWidget = NULL;
    this->phoneInfoWidget = NULL;
    this->messageWidget = NULL;
    this->appWidget = NULL;
    this->recoveryWidget = NULL;
    this->fastbootWidget = NULL;
    this->logcatDialog = NULL;

    this->imageListWidget = NULL;
    this->imageWidget = NULL;
    this->audioWidget = NULL;
    this->videoWidget = NULL;
    this->applicationWidget = NULL;
    this->contactWidget = NULL;
    this->fileWidget =NULL;

    this->systemTray=new QSystemTrayIcon();
    this->systemTray->setIcon(QIcon(":/icons/android.png"));
    this->systemTray->show();

    QMenu *menu = new QMenu;
    QAction *close,*logcat;
    logcat = menu->addAction(QIcon(":icons/logcat.png"),tr("Logcat", "action in system tray menu"),this,SLOT(showLogcat()));
    logcat->setData(QString("logcat"));
    close = menu->addAction(QIcon(":icons/remove.png"),tr("exit", "action in system tray menu"),this,SLOT(close()));
    close->setData(QString("exit"));
    this->systemTray->setContextMenu(menu);


    //ui->stackedWidget->addWidget(this->settingsWidget);
    //ui->stackedWidget->addWidget(this->fileWidget);
    ui->stackedWidget->setCurrentWidget(ui->pageDisconnected);
    ui->pageDisconnected->setLayout(ui->layoutDisconnected);
    this->currentWidget=ui->pageDisconnected;

    qDebug()<<QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
    qDebug()<<"App version - "<<QCoreApplication::applicationVersion();

    this->ui->centralWidget->setLayout(ui->gridLayout);

    if (this->settingsWidget->saveWindowPosition)
        this->restoreGeometry(this->settingsWidget->windowGeometry);

    this->ui->toolBar->setMovable(false);

    this->addButton(QIcon(":icons/info.png"), tr("welcome", "phone info button"), "welcome", SLOT(showPagePhoneInfo()), Action::Device | Action::Recovery | Action::Fastboot);
    this->addButton(QIcon(":icons/apps.png"), tr("Apps", "apps button"), "Apps", SLOT(showPageApplication()), Action::Device | Action::Recovery);
    //this->addButton(QIcon(":icons/apps.png"), tr("Apps", "apps button"), "Apps", SLOT(showPageApps()), Action::Device | Action::Recovery);
    this->addButton(QIcon(":icons/files.png"), tr("Files", "files button"), "Files" , SLOT(showPageFiles()), Action::Device | Action::Recovery);  
    this->addButton(QIcon(":icons/messages.png"), tr("Messages", "messages button"), "Messages", SLOT(showPageMessages()), Action::Device);
    //this->addButton(QIcon(":icons/recovery.png"), tr("Recovery", "recovery button"), "Recovery", SLOT(showPageRecovery()), Action::Recovery);
    //this->addButton(QIcon(":icons/fastboot.png"), tr("Fastboot", "fastbot button"), "Fastboot", SLOT(showPageFastboot()), Action::Fastboot);
    //this->addButton(QIcon(":icons/info.png"), tr("Phone info", "phone info button"), "Phone info", SLOT(showPagePhoneInfo()), Action::Device | Action::Recovery | Action::Disconnected | Action::Fastboot);
    //this->addButton(QIcon(":icons/screenshot.png"), tr("Screenshot", "screenshot button"), "Screenshot", SLOT(showPageScreenshot()), Action::Device | Action::Recovery);
    //this->addButton(QIcon(":icons/settings.png"), tr("Settings", "settings button"), "Settings", SLOT(showPageSettings()), Action::Disconnected | Action::Device | Action::Recovery | Action::Fastboot);

    //this->addButton(QIcon(":icons/shell.png"), tr("Shell", "shell button"), "Shell", SLOT(showPageShell()), Action::Device | Action::Recovery);
    this->addButton(QIcon(":icons/contacts.png"), tr("Contacts","Contacts button"), "Contact", SLOT(showPageContacts()), Action::Device| Action::Recovery);
    //this->addButton(QIcon(":icons/logcat.png"), tr("Logcat", "logcat button"), "Logcat", SLOT(showLogcat()), Action::Device | Action::Recovery);

    this->addButton(QIcon(":icons/image.png"), tr("Image", "Image button"), "Image", SLOT(showPageImage()), Action::Device | Action::Recovery);
    this->addButton(QIcon(":icons/audio.png"), tr("Audio", "Audio button"), "Audio", SLOT(showPageAudio()), Action::Device | Action::Recovery);
    this->addButton(QIcon(":icons/video.png"), tr("Video", "Video button"), "Video", SLOT(showPageVideo()), Action::Device | Action::Recovery);


    this->changeToolBar();

    connect(this->ui->actionUsb, SIGNAL(triggered()), this, SLOT(restartInUsb()));
    connect(this->ui->actionWifi, SIGNAL(triggered()), this, SLOT(restartInWifi()));

    connect(&this->animation.animation, SIGNAL(finished()), this, SLOT(animationFinished()));

    connect(this->systemTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(systemTrayActivated(QSystemTrayIcon::ActivationReason)));
    connect(this->systemTray, SIGNAL(messageClicked()), this, SLOT(showPageMessages()));
    connect(this->systemTray, SIGNAL(messageClicked()), this, SLOT(show()));

    connect(this->settingsWidget, SIGNAL(settingsChanged()), this, SLOT(changeToolBar()));
    this->settingsWidget->clearSettings = false;

    this->fillLanguages();

    currentState = -1;
    connectType = "usb";
    cThread = new ConThread();
    connect(this->cThread,SIGNAL(connectionChanged(int,QString)),this,SLOT(phoneConnectionChanged(int, QString)));
    testTimer = new QTimer(this);
    connect( testTimer, SIGNAL(timeout()), this, SLOT(connectFresh()) );
    //开始运行定时器，定时时间间隔为1000ms
    testTimer->start(10000);
    cThread->start();

}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    Q_UNUSED(event);

//    this->setWindowTitle("QtADB " + QString::number(this->height()) + "x" + QString::number(this->width()));

}
MainWindow::~MainWindow()
{
    int w = this->width();
    int h = this->height();

    delete this->systemTray;

    delete this->fileWidget;
    if (!this->settingsWidget->clearSettings)
    {
        QSettings settings;
        settings.setValue("windowGeometry", saveGeometry());
        this->settingsWidget->saveSettings();
    }
    if (this->settingsWidget != NULL)
        delete this->settingsWidget;

    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        this->aboutDialog.retranslateUi(&(this->aboutDialog));
        if (this->logcatDialog != NULL)
            this->logcatDialog->retranslateUi(this->logcatDialog);
        for (int i=0; i < this->akcje.size(); i++)
        {
            akcje.at(i).actionMenu->setText(tr(akcje.at(i).text.toAscii()));
            akcje.at(i).button->setText(tr(akcje.at(i).text.toAscii()));
        }
        break;
    default:
        break;
    }
}

void MainWindow::connectFresh()
{
    if(cThread->isRunning())
    {
        return;
    }else{
        cThread->start();
    }
}


bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    Q_UNUSED(object);
    Q_UNUSED(event);

//    if (event->type() == QEvent::FocusIn)
//    {
//        if (object == ui->leftTableWidget)
//            rightTableWidgetActivated();

//        else if (object == ui->rightTableWidget)
//            leftTableWidgetActivated();
//    }
    return false;
}

void MainWindow::fillLanguages()
{

    // make a group of language actions
    QActionGroup* actionsDir = new QActionGroup(this);
    QActionGroup* actionsRes = new QActionGroup(this);
    QSettings settings;
    QString locale = QLocale::system().name().left(2);

    QString lang = settings.value("Language", locale).toString();
    if (!Application::availableLanguagesRes().contains(lang))
        lang = "en";
    bool langSet = false;

    this->ui->menu_Pomoc->addSeparator();
    connect(actionsRes, SIGNAL(triggered(QAction*)), this, SLOT(setLanguageRes(QAction*)));
    connect(actionsDir, SIGNAL(triggered(QAction*)), this, SLOT(setLanguageDir(QAction*)));

    foreach (QString avail, Application::availableLanguagesRes())
    {
        // figure out nice names for locales
        QLocale locale(avail);
        QString name = QLocale::languageToString(locale.language());

        // construct an action
        QAction* action = this->ui->menu_Pomoc->addAction(name);
        action->setData(avail);
        action->setCheckable(true);
        actionsRes->addAction(action);
        if (action->data().toString() == lang)
        {
            langSet = true;
            action->setChecked(true);
            Application::setLanguage(lang, "res");
        }
    }
    if (!Application::availableLanguagesDir().isEmpty())
        this->ui->menu_Pomoc->addSeparator();
    foreach (QString avail, Application::availableLanguagesDir())
    {
        // figure out nice names for locales
        QLocale locale(avail);
        QString name = QLocale::languageToString(locale.language());

        // construct an action
        QAction* action = this->ui->menu_Pomoc->addAction(name);
        action->setData(avail);
        action->setCheckable(true);
        actionsDir->addAction(action);
        if ((action->data().toString() == lang) && (langSet == false))
        {
            action->setChecked(true);
            Application::setLanguage(lang, "dir");
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

}



void MainWindow::mousePressEvent(QMouseEvent *event)
{

}

void MainWindow::on_actionO_programie_triggered()
{
    this->aboutDialog.show();
}


void MainWindow::phoneConnectionChanged(int state, QString serialNumber)
{
    if(currentState == state)
    {
        return;
    }else
    {
        currentState = state;
    }
    if (state == DISCONNECTED) //0
    {
        if (ui->stackedWidget->currentWidget()!=ui->pageDisconnected)
            this->showPageDisconnected();
        this->disableActions(Action::Disconnected);
    }
    else if (state == DEVICE) //1
    {
        if (this->logcatDialog != NULL && this->logcatDialog->isVisible())
            this->logcatDialog->startLogcat();

        serialNum = serialNumber;
        if(connectType == "usb")
        {
//        if(android->startMainActivity() != 0)
//        {
            android->installApk();
//            android->startMainActivity();
//        }       
            android->init();
            android->forward();
        }

        this->disableActions(Action::Device);
        this->showPagePhoneInfo();
    }
}

void MainWindow::restartInWifi()
{
    testTimer->stop();
    while(cThread->isRunning()){}

    int result;
    this->connectWifiDialog = new ConnectWifi;
    this->connectWifiDialog->portEdit->setText("7101");
    result = this->connectWifiDialog->exec();
    if (result == 1)
    {
        this->ipAddress = this->connectWifiDialog->adresEdit->text();
        this->portNumber = this->connectWifiDialog->portEdit->text();
        QSettings settings;
        settings.setValue("wlanIP",this->ipAddress);
        settings.setValue("connectType","wifi");
        settings.setValue("cPort","7101");
        settings.setValue("sPort","7100");

        this->ui->actionUsb->setEnabled(true);
        this->ui->actionWifi->setDisabled(true);
        connectType = "wifi";
    }
    testTimer->start(10000);
    cThread->start();
    delete this->connectWifiDialog;
}

void MainWindow::restartInUsb()
{    
    testTimer->stop();
    while(cThread->isRunning()){}

    QSettings settings;
    settings.setValue("wlanIP","127.0.0.1");
    settings.setValue("connectType","usb");
    settings.setValue("cPort","6101");
    settings.setValue("sPort","6100");

    this->ui->actionUsb->setDisabled(true);
    this->ui->actionWifi->setEnabled(true);

    connectType = "usb";
    testTimer->start(10000);
    cThread->start();


}

void MainWindow::setLanguageRes(QAction *action)
{
    Application::setLanguage(action->data().toString(), "res");
    foreach (QAction *act, this->ui->menu_Pomoc->actions())
    {
        if (action != act)
            act->setChecked(false);
    }
    QSettings settings;
    settings.setValue("Language", action->data().toString());
}

void MainWindow::setLanguageDir(QAction *action)
{
    Application::setLanguage(action->data().toString(), "dir");
    foreach (QAction *act, this->ui->menu_Pomoc->actions())
    {
        if (action != act)
            act->setChecked(false);
    }
    QSettings settings;
    settings.setValue("Language", action->data().toString());
}

void MainWindow::showLogcat()
{
    if (this->logcatDialog != NULL)
    {
        this->logcatDialog->close();
        this->logcatDialog = NULL;
    }

    this->logcatDialog = new LogcatDialog;
    this->logcatDialog->show();
}

void MainWindow::showPageDisconnected()
{
    this->ui->actionUsb->setDisabled(true);
    this->ui->actionWifi->setEnabled(true);
    this->setButtonDown(0);
    this->startAnimation(ui->pageDisconnected);
}

void MainWindow::showPageApps()
{
    if (this->appWidget == NULL)
    {
        this->appWidget = new AppWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->appWidget);
    }
    this->setButtonDown(1);
    this->startAnimation(this->appWidget);
}

void MainWindow::showPageFastboot()
{

    if (this->fastbootWidget == NULL)
    {
        this->fastbootWidget = new FastbootWidget(this,this->fileWidget->phone);
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->fastbootWidget);
    }

    this->setButtonDown(3);

    this->startAnimation(this->fastbootWidget);
}

void MainWindow::showPageFiles()
{
    qDebug()<<"showPageFiles";
    if(this->fileWidget ==NULL)
    {
        this->fileWidget = new FileWidget(this, this->settingsWidget);
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->fileWidget);
    }
    this->setButtonDown(2);
    this->startAnimation(this->fileWidget);
}




bool MainWindow::verifyKey(QString email,QString key)
{
    QCryptographicHash md5(QCryptographicHash::Md5);
    QCryptographicHash sha1(QCryptographicHash::Sha1);

    md5.addData(email.toAscii());
    sha1.addData(md5.result());

    QString tmp = sha1.result().toHex();
    if (key == sha1.result().toHex())
    {
        return true;
    }
    return false;
}//c7ce7f4aa19b7753c63771cc6014d9bdb090a124

bool MainWindow::verifyRegistered(QString email)
{
    email.append("qtadb");
    email.prepend("QtADB");

    QSettings settings;
    QStringList keyList(settings.value("registerKey").toStringList());

    foreach(QString key,keyList)
    {
        if (verifyKey(email,key))
            return true;
    }

    return false;
}

void MainWindow::showPageMessages()
{
    qDebug()<<"showPageMessages";
    if (this->messageWidget == NULL)
    {
        this->messageWidget = new MessageWidget(this);
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->messageWidget);
        connect(this->messageWidget, SIGNAL(smsReceived(QString,QString)), this, SLOT(smsReceived(QString, QString)));
        connect(this->messageWidget, SIGNAL(smsResultSignal(QString)), this, SLOT(smsResult(QString)));
    }else{

        if(!this->messageWidget->ts->isRunning())
        {
            this->messageWidget->ts->start();
        }
    }
    this->setButtonDown(3);
    this->startAnimation(this->messageWidget);
}

void MainWindow::showPagePhoneInfo()
{
    if (this->phoneInfoWidget == NULL)
    {
        this->phoneInfoWidget = new PhoneInfoWidget(this,this->serialNum);
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->phoneInfoWidget);
    }

    this->setButtonDown(0);
    this->startAnimation(this->phoneInfoWidget);
}

void MainWindow::showPageRecovery()
{
    if (this->recoveryWidget == NULL)
    {
        this->recoveryWidget = new RecoveryWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->recoveryWidget);
    }

    this->setButtonDown(2);

    this->startAnimation(this->recoveryWidget);
}

void MainWindow::showPageScreenshot()
{
    if (this->screenshotWidget == NULL)
    {
        this->screenshotWidget = new ScreenshotWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->screenshotWidget);
    }

    this->setButtonDown(3);

    this->startAnimation(this->screenshotWidget);
}

void MainWindow::showPageSettings()
{
    qDebug()<<"showPageSettings";

    this->setButtonDown(6);

    this->settingsWidget->setSettings();

    this->startAnimation(this->settingsWidget);
}

void MainWindow::showPageShell()
{
    if (this->shellWidget == NULL)
    {
        this->shellWidget = new ShellWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->shellWidget);
        this->shellWidget->move(-ui->stackedWidget->currentWidget()->width(),0);
    }

    this->setButtonDown(4);

    this->startAnimation(this->shellWidget);
}

void MainWindow::smsReceived(QString number, QString body)
{
    this->systemTray->showMessage(tr("Sms from ", "system tray bubble") + number, body, QSystemTrayIcon::NoIcon);
}

void MainWindow::smsResult(QString result)
{
    this->systemTray->showMessage(tr("Sms result", "system tray bubble"), result, QSystemTrayIcon::NoIcon);
}

void MainWindow::startAnimation(QWidget *target)
{
    QWidget *current=this->currentWidget;
    if (this->settingsWidget->enableAnimations)
        this->animation.setPrameters(this->settingsWidget->animationDuration,this->settingsWidget->animationDirection,this->settingsWidget->animationCurve);
    else
        this->animation.setPrameters(0,this->settingsWidget->animationDirection,this->settingsWidget->animationCurve);
    this->currentWidget=target;
    this->animation.start(target,current);
}

void MainWindow::systemTrayActivated(QSystemTrayIcon::ActivationReason activationReason)
{
    switch(activationReason)
    {
    case QSystemTrayIcon::Unknown:
        break;
    case QSystemTrayIcon::Context: //right click
        break;
    case QSystemTrayIcon::DoubleClick:
        break;
    case QSystemTrayIcon::Trigger: //left click
        if (this->isVisible())
            this->hide();
        else
            this->show();
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    }
}

void MainWindow::animationFinished()
{
//    ui->stackedWidget->currentWidget()->move(ui->stackedWidget->currentWidget()->width(),0);
    ui->stackedWidget->setCurrentWidget(this->currentWidget);
}



void MainWindow::updatesCheck()
{
    this->win7.setOverlayIcon(QIcon(":icons/info.png"), "desc");
    this->showNoUpdates = true;
    this->updateApp.checkUpdates();
}

void MainWindow::updatesCheckFinished(bool gotUpdate, QString oldVersion, QString newVersion)
{
    if (gotUpdate)
    {
        QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, tr("New updates"), tr("New update is available\n")
                                              + tr("Your version: ") + oldVersion + tr("\nLatest version: ") + newVersion);
        QPushButton *getUpdatesMsg = msgBox->addButton(tr("Download"), QMessageBox::AcceptRole);
        QPushButton *closeMsg = msgBox->addButton(tr("Close"), QMessageBox::RejectRole);

        msgBox->exec();

        if (msgBox->clickedButton() == getUpdatesMsg)
        {
            QDesktopServices::openUrl ( QUrl("http://qtadb.wordpress.com/download/") );
        }
        delete getUpdatesMsg;
        delete closeMsg;
        delete msgBox;
    }
    else
    {
        if (oldVersion == "failed")
        {
            QMessageBox::critical(this, tr("error"), tr("There was problem while checking for updates"), QMessageBox::Ok);
        }
        else if (this->showNoUpdates)
        {
            QMessageBox::information(this, tr("No updates"), tr("Your version is up to date\n")
                                 + tr("Your version: ") + oldVersion + tr("\nLatest version: ") + newVersion, QMessageBox::Ok);
        }
        this->showNoUpdates = true;
    }
}

void MainWindow::addButton(QIcon icon, QString textTr, QString text, const char * method, int flags)
{
    QAction *act = new QAction(icon, textTr, this);
    this->ui->menu->addAction(act);
    connect(act, SIGNAL(triggered()), this, method);
    act->setEnabled(false);
    QToolButton *button = new QToolButton;
    button->hide();
    button->setIcon(icon);
    button->setText(textTr);
    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    connect(button, SIGNAL(clicked()), this, method);
    QAction *action = this->ui->toolBar->addWidget(button);
    action->setVisible(false);
    Action akcja;
    akcja.actionMenu = act;
    akcja.actionToolBar = action;
    akcja.button = button;
    akcja.flags = flags;
    akcja.text = text;
    if (this->akcje.size() == 0)
    {
        this->buttonPageInfo = button;
        this->actionPageInfo = act;
    }
    this->akcje.append(akcja);
}

void MainWindow::changeToolBar()
{
    this->addToolBar(this->settingsWidget->toolBarArea, this->ui->toolBar);
    this->ui->toolBar->setIconSize(this->settingsWidget->toolBarIconSize);
    for (int i=0; i < this->akcje.size(); i++)
    {
        this->akcje.at(i).button->setToolButtonStyle(this->settingsWidget->toolBarStyle);
        this->akcje.at(i).button->update();
    }
    this->ui->toolBar->update();
    this->ui->toolBar->updateGeometry();
}

void MainWindow::setButtonDown(int number)
{
    for (int i = 0; i < this->akcje.size(); i++)
    {
        if (i == number)
            this->akcje.at(i).button->setDown(true);
        else
            this->akcje.at(i).button->setDown(false);
    }
}

void MainWindow::disableActions(Action::Flags flag)
{
    if (flag == Action::Disconnected || flag == Action::Fastboot)
    {
        disconnect(this->buttonPageInfo, SIGNAL(clicked()), this, SLOT(showPagePhoneInfo()));
        disconnect(this->actionPageInfo, SIGNAL(triggered()), this, SLOT(showPagePhoneInfo()));
        connect(this->buttonPageInfo, SIGNAL(clicked()), this, SLOT(showPageDisconnected()));
        connect(this->actionPageInfo, SIGNAL(triggered()), this, SLOT(showPageDisconnected()));
    }
    else if (flag == Action::Device || flag == Action::Recovery)
    {
        disconnect(this->buttonPageInfo, SIGNAL(clicked()), this, SLOT(showPageDisconnected()));
        disconnect(this->actionPageInfo, SIGNAL(triggered()), this, SLOT(showPagePhoneInfo()));
        connect(this->buttonPageInfo, SIGNAL(clicked()), this, SLOT(showPagePhoneInfo()));
        connect(this->actionPageInfo, SIGNAL(triggered()), this, SLOT(showPagePhoneInfo()));
    }
    for (int i=0; i < this->akcje.size(); i++)
    {
        if (akcje.at(i).flags & flag)
        {
            akcje.at(i).actionMenu->setEnabled(true);
            akcje.at(i).actionToolBar->setVisible(true);
            akcje.at(i).button->setEnabled(true);
        }
        else
        {
            akcje.at(i).actionMenu->setEnabled(false);
            if (this->settingsWidget->toolBarHideButton)
                akcje.at(i).actionToolBar->setVisible(false);
            else
                akcje.at(i).actionToolBar->setVisible(true);
            akcje.at(i).button->setEnabled(false);
        }
        akcje.at(i).button->show();
    }
}

void MainWindow::setProgressValue(int value, int max)
{
    this->win7.setProgressValue(value, max);
    this->win7.setProgressState(win7.Normal);
}

void MainWindow::setProgressDisable()
{
        this->win7.setProgressState(win7.NoProgress);
}

void MainWindow::donateMessage()
{
    QSettings settings;
    QDate firstRun = settings.value("firstRun", QDate::currentDate()).toDate();
    int runCount = settings.value("runCount", 0).toInt();
    runCount++;
    bool showMessage = settings.value("donateMessageShow", true).toBool();
    if (showMessage)
    {
        if (firstRun.addDays(14) <= QDate::currentDate() && runCount >= 10)
        {
            QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, tr("Donate"),
                                                  tr("It seems that you are using QtADB for a while now. Maybe consider a donation to a project..."));
            QPushButton *donate = msgBox->addButton(tr("Yes, I want to donate"), QMessageBox::AcceptRole);
            QPushButton *remaindLater = msgBox->addButton(tr("Remaind me later"), QMessageBox::RejectRole);
            QPushButton *dontRemaind = msgBox->addButton(tr("Do not bother me again"), QMessageBox::RejectRole);

            msgBox->exec();

            if (msgBox->clickedButton() == donate)
            {
                QDesktopServices::openUrl ( QUrl("https://www.paypal.com/us/cgi-bin/webscr?cmd=_flow&SESSION=qkFI7Wr4c4cMf9vb8ngyD1Gb9Uu98cGpQOfPO9CTb2UyBdeYMb9NZC6MlHq&dispatch=5885d80a13c0db1f8e263663d3faee8d9384d85353843a619606282818e091d0") );
                settings.setValue("donateMessageShow", false);
            }
            else if (msgBox->clickedButton() == remaindLater)
            {
                settings.setValue("firstRun", QDate::currentDate());
                settings.setValue("runCount", 0);
            }
            else if(msgBox->clickedButton() == dontRemaind)
            {
                settings.setValue("donateMessageShow", false);
            }
            delete donate;
            delete remaindLater;
            delete dontRemaind;
            delete msgBox;
        }
        else
        {
            if (firstRun == QDate::currentDate())
                settings.setValue("firstRun", QDate::currentDate());
            settings.setValue("runCount", runCount);
        }
    }
}

void MainWindow::on_actionEnter_register_key_triggered()
{
    RegisterDialog *registerDialog = new RegisterDialog(this,Phone::getGoogleAccounts());
    registerDialog->exec();
}

//void MainWindow::showPageImage()
//{
//    qDebug()<<"showPageImages";

//    if(this->messageWidget != NULL)
//    {
//        if(this->messageWidget->ts->isRunning())
//           this->messageWidget->ts->exit();
//    }

//    if (this->imageWidget == NULL)
//    {
//        this->imageWidget = new ImageWidget;
//        this->settingsWidget->changeFont();
//        ui->stackedWidget->addWidget(this->imageWidget);
//    }
//    this->setButtonDown(5);
//    this->startAnimation(this->imageWidget);
//}
void MainWindow::showPageImage()
{
    qDebug()<<"showPageImages";

    if(this->messageWidget != NULL)
    {
        if(this->messageWidget->ts->isRunning())
           this->messageWidget->ts->exit();
    }

    if (this->imageListWidget == NULL)
    {
        this->imageListWidget = new ImageListWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->imageListWidget);
    }
    this->setButtonDown(5);
    this->startAnimation(this->imageListWidget);
}
void MainWindow::showPageAudio()
{
    qDebug()<<"showPageAudio";

    if(this->messageWidget != NULL)
    {
        if(this->messageWidget->ts->isRunning())
           this->messageWidget->ts->exit();
    }

    if (this->audioWidget == NULL)
    {
        this->audioWidget = new AudioWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->audioWidget);
    }
    this->setButtonDown(6);
    this->startAnimation(this->audioWidget);
}

void MainWindow::showPageVideo()
{
    qDebug()<<"showPageVideo";

    if(this->messageWidget != NULL)
    {
        if(this->messageWidget->ts->isRunning())
             this->messageWidget->ts->exit();
    }

    if (this->videoWidget == NULL)
    {
        this->videoWidget = new VideoWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->videoWidget);
    }
    this->setButtonDown(7);
    this->startAnimation(this->videoWidget);
}

void MainWindow::showPageApplication()
{
    qDebug()<<"showPageApplication";

    if(this->messageWidget != NULL)
    {
        if(this->messageWidget->ts->isRunning())
             this->messageWidget->ts->exit();
    }

    if (this->applicationWidget == NULL)
    {
        this->applicationWidget = new ApplicationWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->applicationWidget);
    }
    this->setButtonDown(1);
    this->startAnimation(this->applicationWidget);
}

void MainWindow::showPageContacts()
{
    qDebug()<<"showPageContacts";
    if(this->messageWidget != NULL)
    {
        if(this->messageWidget->ts->isRunning())
             this->messageWidget->ts->exit();
    }

    if (this->contactWidget == NULL)
    {
        this->contactWidget = new ContactWidget;
        this->settingsWidget->changeFont();
        ui->stackedWidget->addWidget(this->contactWidget);
    }
    this->setButtonDown(4);
    this->startAnimation(this->contactWidget);

}

