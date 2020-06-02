#include "game.h"
#include "snake.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game* w = Game::getInstance();
    w->show();
    return a.exec();
}
