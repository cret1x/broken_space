#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include <player.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
   // Player *player;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *e);
    void SwitchButton(QKeyEvent *key);
    void keyPressEvent(QKeyEvent *k);
    void BackToMainScreen();
    void PaintSwitchedButton();

private slots:
    void Gameloop();
    void on_NewGameButton_clicked();

    void on_BestScoreButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::Widget *ui;
    bool GameIsStarted = false;
    bool IsScoreboardSelected = false;
   // QTimer MainGameLoopTimer;
    int ChosenButton = 1;
};

#endif // WIDGET_H
