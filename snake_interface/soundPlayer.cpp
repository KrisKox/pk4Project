#include "soundPlayer.h"
#include <QMediaPlayer>

SoundPlayer::SoundPlayer()
{

}

void SoundPlayer::play()
{
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl(path));
    music->play();
}

void SoundPlayer::setPath(QString path)
{
    this->path = path;
}
