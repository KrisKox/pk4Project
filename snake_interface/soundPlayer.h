#ifndef APPLESOUND_H
#define APPLESOUND_H
#include "QString"

class SoundPlayer
{
public:
    SoundPlayer();
    void play();
    void setPath(QString path);
private:
    QString path;
};

#endif // APPLESOUND_H
