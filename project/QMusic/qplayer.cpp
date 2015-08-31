#include "qplayer.h"
#include <QtGui>
#include "ui_qplayer.h"
#include <ctime>
#include <QVariant>

QPlayer::QPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QPlayer)
{
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);//初始化系列变量
    mediaObject = new Phonon::MediaObject(this);
    metaInformationResolver = new Phonon::MediaObject(this);
    mediaObject->setTickInterval(1000);

    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State, Phonon::State)),
            this, SLOT(stateChanged(Phonon::State, Phonon::State)));
    connect(metaInformationResolver, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(metaStateChanged(Phonon::State, Phonon::State)));
    connect(mediaObject, SIGNAL(currentSourceChanged(const Phonon::MediaSource &)),
            this, SLOT(sourceChanged(const Phonon::MediaSource &)));
    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(aboutToFinish()));

    Phonon::createPath(mediaObject, audioOutput);
    setupActions();

    ui->setupUi(this);
    ui->seekSlider->setMediaObject(mediaObject);
    ui->volumeSlider->setAudioOutput(audioOutput);
    ui->volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    QPalette palette;
    palette.setBrush(QPalette::Light, Qt::darkGray);
    ui->lcdNumber->setPalette(palette);

    QStringList headers;
    headers << tr("标题") << tr("作者") << tr("唱片") << tr("年代");

    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->tableWidget, SIGNAL(cellPressed(int, int)),
            this, SLOT(tableClicked(int, int)));

    ui->lcdNumber->display("00:00");
    ui->PauseButton->hide();
}

QPlayer::~QPlayer()
{
    delete ui;
}

void QPlayer::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void QPlayer::setupActions()
{
    playAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("Play"), this);
    playAction->setShortcut(tr("Crl+P"));
    playAction->setDisabled(true);
    pauseAction = new QAction(style()->standardIcon(QStyle::SP_MediaPause), tr("Pause"), this);
    pauseAction->setShortcut(tr("Ctrl+A"));
    pauseAction->setDisabled(true);
    stopAction = new QAction(style()->standardIcon(QStyle::SP_MediaStop), tr("Stop"), this);
    stopAction->setShortcut(tr("Ctrl+S"));
    stopAction->setDisabled(true);
    nextAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipForward), tr("Next"), this);
    nextAction->setShortcut(tr("Ctrl+N"));
    previousAction = new QAction(style()->standardIcon(QStyle::SP_MediaSkipBackward), tr("Previous"), this);
    previousAction->setShortcut(tr("Ctrl+R"));
    addFilesAction = new QAction(tr("Add &Files"), this);
    addFilesAction->setShortcut(tr("Ctrl+F"));
    connect(playAction, SIGNAL(triggered()), mediaObject, SLOT(play()));
    connect(pauseAction, SIGNAL(triggered()), mediaObject, SLOT(pause()) );
    connect(stopAction, SIGNAL(triggered()), mediaObject, SLOT(stop()));
    connect(addFilesAction, SIGNAL(triggered()), this, SLOT(addFiles()));
}

void QPlayer::addFiles()
{
    QStringList files = QFileDialog::getOpenFileNames(this, tr("选择音乐文件"),
        QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    if (files.isEmpty())
        return;

    int index = sources.size();
    foreach (QString string, files) {
            Phonon::MediaSource source(string);

        sources.append(source);
    }
    if (!sources.isEmpty())
        metaInformationResolver->setCurrentSource(sources.at(index));

}

void QPlayer::tableClicked(int row, int)
{
    bool wasPlaying = mediaObject->state() == Phonon::PlayingState;

    mediaObject->stop();
    mediaObject->clearQueue();

    if (row >= sources.size())
        return;

    mediaObject->setCurrentSource(sources[row]);

    if (wasPlaying)
        mediaObject->play();
    else
        mediaObject->stop();
}

void QPlayer::tick(qint64 time)
{
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);

    ui->lcdNumber->display(displayTime.toString("mm:ss"));
}

void QPlayer::sourceChanged(const Phonon::MediaSource &source)
{
    ui->tableWidget->selectRow(sources.indexOf(source));
    ui->lcdNumber->display("00:00");
}

void QPlayer::metaStateChanged(Phonon::State newState, Phonon::State)
{
    if (newState == Phonon::ErrorState) {
        QMessageBox::warning(this, tr("文件格式错误"),
            metaInformationResolver->errorString());
        while (!sources.isEmpty() &&
               !(sources.takeLast() == metaInformationResolver->currentSource())) {};
        return;
    }

    if (newState != Phonon::StoppedState && newState != Phonon::PausedState)
        return;

    if (metaInformationResolver->currentSource().type() == Phonon::MediaSource::Invalid)
            return;

    QMap<QString, QString> metaData = metaInformationResolver->metaData();

    QString title = metaData.value("TITLE");
    if (title == "")
        title = metaInformationResolver->currentSource().fileName();

    QTableWidgetItem *titleItem = new QTableWidgetItem(title);
    titleItem->setFlags(titleItem->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem *artistItem = new QTableWidgetItem(metaData.value("ARTIST"));
    artistItem->setFlags(artistItem->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem *albumItem = new QTableWidgetItem(metaData.value("ALBUM"));
    albumItem->setFlags(albumItem->flags() ^ Qt::ItemIsEditable);
    QTableWidgetItem *yearItem = new QTableWidgetItem(metaData.value("DATE"));
    yearItem->setFlags(yearItem->flags() ^ Qt::ItemIsEditable);
    int currentRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(currentRow);
    ui->tableWidget->setItem(currentRow, 0, titleItem);
    ui->tableWidget->setItem(currentRow, 1, artistItem);
    ui->tableWidget->setItem(currentRow, 2, albumItem);
    ui->tableWidget->setItem(currentRow, 3, yearItem);
    if (ui->tableWidget->selectedItems().isEmpty()) {
        ui->tableWidget->selectRow(0);
        mediaObject->setCurrentSource(metaInformationResolver->currentSource());
    }

    Phonon::MediaSource source = metaInformationResolver->currentSource();
    int index = sources.indexOf(metaInformationResolver->currentSource()) + 1;
    if (sources.size() > index) {
        metaInformationResolver->setCurrentSource(sources.at(index));
    }
    else {
        ui->tableWidget->resizeColumnsToContents();
        if (ui->tableWidget->columnWidth(0) > 300)
            ui->tableWidget->setColumnWidth(0, 300);
    }
}

void QPlayer::stateChanged(Phonon::State newState, Phonon::State)
{
    switch (newState) {
        case Phonon::ErrorState:
            if (mediaObject->errorType() == Phonon::FatalError) {
                QMessageBox::warning(this, tr("致命错误"),
                mediaObject->errorString());
            } else {
                QMessageBox::warning(this, tr("错误"),
                mediaObject->errorString());
            }
            break;
        case Phonon::PlayingState:
                playAction->setEnabled(false);
                pauseAction->setEnabled(true);
                stopAction->setEnabled(true);
                ui->PauseButton->show();
                ui->PlayButton->hide();
                break;
        case Phonon::StoppedState:
                stopAction->setEnabled(false);
                playAction->setEnabled(true);
                pauseAction->setEnabled(false);
                ui->lcdNumber->display("00:00");
                ui->PlayButton->show();
                ui->PauseButton->hide();
                break;
        case Phonon::PausedState:
                pauseAction->setEnabled(false);
                stopAction->setEnabled(true);
                playAction->setEnabled(true);
                ui->PlayButton->show();
                ui->PauseButton->hide();
                break;
        case Phonon::BufferingState:
                break;
        default:
            ;
    }
}


void QPlayer::nextFile()
{

    int index = sources.indexOf(mediaObject->currentSource()) + 1;

    if (sources.size() > index) {
         mediaObject->stop();
         mediaObject->setCurrentSource(sources.at(index));
         mediaObject->play();
     }
}

void QPlayer::prevFile()
{

    int index = sources.indexOf(mediaObject->currentSource()) - 1;

    if (sources.size() > index && index >= 0) {
         mediaObject->stop();
         mediaObject->setCurrentSource(sources.at(index));
         mediaObject->play();
     }
}

void QPlayer::rndFile()
{
    int index=sources.indexOf(mediaObject->currentSource());
    int max = sources.size();
    bool isWhile=true;
    if(index>0){
        while(isWhile){
            srand((unsigned)time(0));
            int rndex=rand()%max;
            if(!rndex==index){
                isWhile=false;
                mediaObject->stop();
                mediaObject->setCurrentSource(sources.at(rndex));
                mediaObject->play();
            }
        }
    }
}

void QPlayer::aboutToFinish()
{

    nextFile();

}

void QPlayer::finished()
{

         ui->PlayButton->setChecked(false);

}

void QPlayer::removeFiles()
{
    int index=sources.indexOf(mediaObject->currentSource());
    int p=ui->tableWidget->currentRow();
    if (p==index){
        nextFile();
    }
        sources.removeAt(p);   
    ui->tableWidget->removeRow(p);
}

void QPlayer::on_AddButton_clicked()
{
    addFilesAction->trigger();
}

void QPlayer::on_PlayButton_clicked()
{
    playAction->trigger();
}

void QPlayer::on_StopButton_clicked()
{
    stopAction->trigger();
}

void QPlayer::on_PauseButton_clicked()
{
    pauseAction->trigger();
}

void QPlayer::on_NextButton_clicked()
{
    nextFile();
}

void QPlayer::on_PrevButton_clicked()
{
    prevFile();
}

void QPlayer::on_StyleButton_clicked()
{
    rndFile();
}

void QPlayer::on_pushButton_clicked()
{
    QMessageBox::about(this,tr("版本信息"),tr("版本:QT音乐_V 1.0.10版.\n\n作者:_HeyKite(EN)独男(CN)  "));
}

void QPlayer::on_RemoveButton_clicked()
{
    removeFiles();
}

void QPlayer::on_MuButton_clicked()
{
    addFilesAction->trigger();
}
