#include "soundThread.h"
#include <QMediaPlayer>
#include "QMutex"

SoundThread::SoundThread()
{
    soundPlayer = new SoundPlayer();
}

void SoundThread::run()
{
    QMutex myMutex;
    qDebug() << "Thread started";
    myMutex.lock();
    soundPlayer->play();
    myMutex.unlock();
    qDebug() << "audio thread" << QThread::currentThread();
}

void SoundThread::playAppleSound(QString audioPath)
{
    soundPlayer->setPath(audioPath);
    run();
}
