#include "gameover.h"
#include "ui_gameover.h"
#include "QTextStream"
#include <cstdlib>
#include "QFile"
#include "game.h"

GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}

GameOver::GameOver(int receivedScore, QString nick): score(receivedScore), nick(nick),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    setStyleSheet("background-color:yellow;");
    fileHandler = new FileHandler();
    saveToFile(score, nick);
    showBestResults();
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
}


void GameOver::saveToFile(int score, QString nick)
{

    fileHandler->saveToFile(score,nick);
}

void GameOver::showBestResults()
{
    QString scores = fileHandler->getNicksFromFile();
    ui->Wynik->setText(scores);
}


GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_BackToGame_clicked()
{
   this->hide();
   Game::getInstance()->show();
}
