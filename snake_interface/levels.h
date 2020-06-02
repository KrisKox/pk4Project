#ifndef LEVELS_H
#define LEVELS_H
#include <QMainWindow>

namespace Ui {
class Levels;
}

enum Level {EASY, MEDIUM, HARD};

class Levels : public QMainWindow
{
    Q_OBJECT

public:
    explicit Levels(QWidget *parent = nullptr);

    void returnToMainWindow();

    void setLevel(Level level);

    Level getLevel();

    ~Levels();

 signals:

    void setLevelInMainWindow();

private slots:

    void on_TRUDNY_clicked();

    void on_SREDNI_clicked();

    void on_LATWY_clicked();

private:
    Ui::Levels *ui;
    Level currentLevel;
};

#endif // LEVELS_H
