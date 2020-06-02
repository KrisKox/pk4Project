#include "snake.h"
#include "ui_snake.h"
#include "QIcon"
#include "gameover.h"

Snake::Snake(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Snake)
{
    ui->setupUi(this);
    setStyleSheet("background-color:black;");
    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;
    resize(B_WIDTH, B_HEIGHT);
    loadImages();
    initGame();
    SoundThread soundThread;
    soundThread.playAppleSound("qrc:/zasoby/sounds/music.mp3");
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

void Snake::loadImages() {

    dot.load(":/zasoby/img/red.png");
    head.load(":/zasoby/img/green.png");
    apple.load(":/zasoby/img/apple.png");
}

void Snake::initGame() {

    dots = 5;

    for (int z = 0; z < dots; z++) {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }

    locateApple();

    timerId = startTimer(DELAY);
}

void Snake::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    doDrawing();

}

void Snake::doDrawing() {

    QPainter qp(this);

    if (inGame) {
        showScore(qp);
        qp.drawImage(apple_x, apple_y, apple);

        for (int z = 0; z < dots; z++) {
            if (z == 0) {
                qp.drawImage(x[z], y[z], head);
            } else {
                qp.drawImage(x[z], y[z], dot);
            }
        }
    } else {
        gameOver();
    }
}

void Snake::gameOver() {

    int score = (dots-5)*10;
    this->hide();
    GameOver *gameOver = new GameOver(score, nick);
    gameOver->show();
}


void Snake::showScore(QPainter &qp) {
    QString lvl;
    switch(level){
    case EASY:
        lvl = " latwy";
        break;
    case MEDIUM:
        lvl = " sredni";
        break;
    case HARD:
        lvl = " trudny";
        break;
    }
    QString message = "Delay: " + QString::number(DELAY) + ", Score: "+ QString::number((dots-5)*10) + ", Poziom:" + lvl + ", Nick: " + nick;
    QFont font("Courier", 7, QFont::DemiBold);
    QFontMetrics fm(font);
    int textHeight = fm.height();
    QColor red(Qt::red);
    qp.setFont(font);

    qp.translate(QPoint(7, textHeight));
    qp.setPen(red);
    qp.drawText(0, 0, message);
}

void Snake::checkApple() {

    if ((x[0] == apple_x) && (y[0] == apple_y)) {

        dots++;
        locateApple();
        DELAY-=4;
        SoundThread soundThread;
        soundThread.playAppleSound("qrc:/zasoby/sounds/appleSound.mp3");
    }
}

void Snake::move() {

    for (int z = dots; z > 0; z--) {
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }

    if (leftDirection) {
        x[0] -= DOT_SIZE;
    }

    if (rightDirection) {
        x[0] += DOT_SIZE;
    }

    if (upDirection) {
        y[0] -= DOT_SIZE;
    }

    if (downDirection) {
        y[0] += DOT_SIZE;
    }
}

void Snake::checkCollision() {

    for (int z = dots; z > 0; z--) {

        if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z])) {
            inGame = false;
        }
    }

    if (y[0] >= B_HEIGHT) {
        inGame = false;
    }

    if (y[0] < 0) {
        inGame = false;
    }

    if (x[0] >= B_WIDTH) {
        inGame = false;
    }

    if (x[0] < 0) {
        inGame = false;
    }

    if(!inGame) {
        killTimer(timerId);
    }
}

void Snake::locateApple() {

    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % RAND_POS;
    apple_x = (r * DOT_SIZE);

    r = qrand() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void Snake::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (inGame) {
        checkApple();
        checkCollision();
        move();
    }

    repaint();
}

void Snake::keyPressEvent(QKeyEvent *e) {

    int key = e->key();

    if ((key == Qt::Key_Left) && (!rightDirection)) {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Right) && (!leftDirection)) {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Up) && (!downDirection)) {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    if ((key == Qt::Key_Down) && (!upDirection)) {
        downDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    QWidget::keyPressEvent(e);
}

Snake::~Snake()
{
    delete ui;
}

void Snake::getInformationInSnakeWindow(Level newLevel, QString newNick)
{
    this->level = newLevel;
    this->nick = newNick;
    if(newLevel == HARD){
        DELAY -=50;
    }
    else if(newLevel == MEDIUM){
        DELAY -=30;
    }
    else if(newLevel == EASY){
        DELAY -=10;
    }
}
