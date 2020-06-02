#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include "levels.h"
#include "snake.h"
#include "myException.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT
    Levels* levels;
    Snake* snake;

public:
    void showLevel();
    ~Game();
    static Game* getInstance()
       {
         if(!instance)
         {
           instance = new Game();
         }
         return instance;
       }
    QString getUserName();
public slots:

      void getLevel();


private slots:

    void on_WYJSCIE_clicked();

    void on_POZIOM_clicked();

    void on_START_clicked();

private:
    Ui::Interface *ui;
    Game(QWidget *parent = nullptr);
    static Game* instance;

};
#endif // INTERFACE_H
