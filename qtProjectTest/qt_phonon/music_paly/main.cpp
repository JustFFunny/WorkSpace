#include <QApplication>
#include <phonon>
#include <QUrl>
#include <QWidget>
#include <Phonon/VideoPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("play");
    QWidget * widget=new QWidget;
    Phonon::MediaObject * mediaObject=new Phonon::MediaObject(widget);

    mediaObject->setCurrentSource(Phonon::MediaObject("/home/wuqiankun/桌面/fire.mp3"));
    Phonon::AudioOutput * player= new Phonon::AudioOutput( Phonon::VideoCategory,widget);
   // player->load(Phonon::MediaSource("/home/wuqiankun/桌面/fire.mp3"));
    //player->play();
    Phonon::createPath(mediaObject,player);
    widget->show();
    return a.exec();
}
