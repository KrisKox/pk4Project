#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "filehandler.h"
#include <QWidget>

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT
    int score = 0;
    QString nick;

public:
    explicit GameOver(QWidget *parent = nullptr);
    GameOver(int receivedScore, QString nick);
    ~GameOver();
    FileHandler* fileHandler;

private slots:
    void on_BackToGame_clicked();

private:
    Ui::GameOver *ui;
    void saveToFile(int score, QString nick);
    void showBestResults();
};

#endif // GAMEOVER_H
