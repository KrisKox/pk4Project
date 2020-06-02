#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTime>
#include <QDir>
#include "levels.h"
#include "soundPlayer.h"
#include "soundThread.h"

namespace Ui {
class Snake;
}


class Snake : public QWidget
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = nullptr);
    void initGame();
    ~Snake();
    void getInformationInSnakeWindow(Level level, QString nick);
    int DELAY = 150;

protected:
     void paintEvent(QPaintEvent *);
     void timerEvent(QTimerEvent *);
     void keyPressEvent(QKeyEvent *);

private:
    Ui::Snake *ui;
    QImage dot;
    QImage head;
    QImage apple;
    Level level;
    QString nick;

  static const int B_WIDTH = 500;
  static const int B_HEIGHT = 500;
  static const int DOT_SIZE = 10;
  static const int ALL_DOTS = 2500;
  static const int RAND_POS = 40;


  int timerId;
  int dots;
  int apple_x;
  int apple_y;

  int x[ALL_DOTS];
  int y[ALL_DOTS];

  bool leftDirection;
  bool rightDirection;
  bool upDirection;
  bool downDirection;
  bool inGame;

  void loadImages();
  void locateApple();
  void checkApple();
  void checkCollision();
  void move();
  void doDrawing();
  void gameOver();
  void showScore(QPainter &);


};

#endif // SNAKE_H
