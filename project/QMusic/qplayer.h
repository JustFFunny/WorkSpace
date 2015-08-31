#ifndef QPLAYER_H
#define QPLAYER_H

#include <QMainWindow>
#include <Phonon>
#include <QMainWindow>
#include <QList>

namespace Ui {
    class QPlayer;
}

class QPlayer : public QMainWindow {
    Q_OBJECT
public:
    QPlayer(QWidget *parent = 0);
    ~QPlayer();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::QPlayer *ui;

    Phonon::SeekSlider *seekSlider;
    Phonon::MediaObject *mediaObject;
    Phonon::MediaObject *metaInformationResolver;
    Phonon::AudioOutput *audioOutput;
    Phonon::VolumeSlider *volumeSlider;
    QList<Phonon::MediaSource> sources;

    QAction *playAction;
    QAction *pauseAction;
    QAction *stopAction;
    QAction *nextAction;
    QAction *previousAction;
    QAction *addFilesAction;

private slots:
    void on_MuButton_clicked();
    void on_RemoveButton_clicked();
    void on_pushButton_clicked();
    void on_StyleButton_clicked();
    void on_PrevButton_clicked();
    void on_NextButton_clicked();
    void on_PauseButton_clicked();
    void on_StopButton_clicked();
    void on_PlayButton_clicked();
    void on_AddButton_clicked();
    void addFiles();
    void nextFile();
    void prevFile();
    void aboutToFinish();
    void finished();
    void tick(qint64);
    void rndFile();
    void stateChanged(Phonon::State newState, Phonon::State);
    void metaStateChanged(Phonon::State newState, Phonon::State);
    void sourceChanged(const Phonon::MediaSource &source);
    void tableClicked(int row, int);
    void setupActions();
    void removeFiles();

};

#endif // QPLAYER_H
