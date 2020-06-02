#ifndef SOUNDTHREAD_H
#define SOUNDTHREAD_H
#include "QThread"
#include "soundPlayer.h"


class SoundThread : public QThread
{

public:
    SoundThread();
    void run();
    void playAppleSound(QString audioPath);
private:
    SoundPlayer* soundPlayer;
};

#endif // SOUNDTHREAD_H
