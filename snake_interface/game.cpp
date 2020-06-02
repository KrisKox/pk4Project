#include "game.h"
#include "ui_game.h"
#include <string>
#include "QDebug"

Game* Game::instance = NULL;

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    levels = new Levels(this);
    snake = new Snake();
    showLevel();
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
}



void Game::showLevel()
{
    Level currentLevel = levels->getLevel();
    std::string levelName;
    switch(currentLevel){
    case EASY:
        levelName = "latwy";
        break;
    case MEDIUM:
        levelName = "sredni";
        break;
    case HARD:
        levelName = "trudny";
        break;
    default:
        levelName = "Boski xd";
        break;
    }
    ui->poziomLabel->setText(QString::fromStdString("Poziom: " + levelName));
}

Game::~Game()
{
    delete ui;
}

void Game::getLevel()
{
    showLevel();
}

void Game::on_WYJSCIE_clicked()
{
    QApplication::quit();
}

void Game::on_POZIOM_clicked()
{
    this->hide();
    levels->show();
}

void Game::on_START_clicked()
{
    try {
         QString userName = getUserName();
         this->hide();
         snake = new Snake();
         snake->getInformationInSnakeWindow(levels->getLevel(), userName);
         snake->show();
    } catch (MyException msg) {
        qDebug() << "Exception thrown: " << msg.what();
    }
}


QString Game::getUserName()
{
    QString userName = ui->userName->text().toLower();
    if(userName.isEmpty() || userName.contains("przeklenstwo")){
        throw MyException();
    }
    return userName;
}


