#include "levels.h"
#include "ui_levels.h"

Levels::Levels(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Levels)

{
    ui->setupUi(this);
    currentLevel = Level::EASY;
    connect(this, SIGNAL(setLevelInMainWindow()), parent, SLOT(getLevel()));
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
}

Levels::~Levels()
{
    delete ui;
}

void Levels::returnToMainWindow(){
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void Levels::setLevel(Level level)
{
    this->currentLevel = level;
}

Level Levels::getLevel()
{
    return currentLevel;
}

void Levels::on_TRUDNY_clicked()
{
    setLevel(Level::HARD);
    returnToMainWindow();
    emit setLevelInMainWindow();
}

void Levels::on_SREDNI_clicked()
{
    setLevel(Level::MEDIUM);
    returnToMainWindow();
    emit setLevelInMainWindow();
}

void Levels::on_LATWY_clicked()
{
    setLevel(Level::EASY);
    returnToMainWindow();
    emit setLevelInMainWindow();
}


