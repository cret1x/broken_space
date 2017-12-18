#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QPainter>

#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
}

void Widget::SwitchButton(QKeyEvent *key)
{
    if(IsScoreboardSelected)
    {
        if(key->key()==Qt::Key_E)
        {
            //BackToMainScreen();
        }
    }
    else
         {
            switch (key->key()) {
            case Qt::Key_W:
                ChosenButton--;
                break;
            case Qt::Key_S:
                ChosenButton++;
                break;
            case Qt::Key_Space:
                qDebug()<<ChosenButton;
                switch (ChosenButton) {
                case 1:
                   // on_NewGameButton_clicked();
                    qDebug()<<"a";
                    break;
                case 2:
                   // on_BestScoreButton_clicked();
                    qDebug()<<"b";
                    break;
                case 3:
                   // on_ExitButton_clicked();
                    qDebug()<<"c";
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            if(ChosenButton>3) ChosenButton = 1;
            if(ChosenButton<1) ChosenButton = 3;
            qDebug()<<ChosenButton;
        }
    PaintSwitchedButton();
}

void Widget::Gameloop()
{
    this->repaint();
}

void Widget::keyPressEvent(QKeyEvent *k)
{
   // if(!GameIsStarted)
       // SwitchButton(key);
    if(k->key()==Qt::Key_Space)
        qDebug()<<"Пробел :"<<k->key();
    qDebug()<<(int)(Qt::Key_Space);
}

void Widget::PaintSwitchedButton()
{
    ui->NewGameButton->setStyleSheet("color:black");
    ui->BestScoreButton->setStyleSheet("color:black");
    ui->ExitButton->setStyleSheet("color:black");
    switch (ChosenButton) {
    case 1:
        ui->NewGameButton->setStyleSheet("color:red");
        break;
    case 2:
        ui->BestScoreButton->setStyleSheet("color:red");
        break;
    case 3:
        ui->ExitButton->setStyleSheet("color:red");
        break;
    default:
        break;
    }
}

void Widget::on_NewGameButton_clicked()
{
    GameIsStarted = true;
}

void Widget::on_BestScoreButton_clicked()
{
    IsScoreboardSelected = true;
}

void Widget::on_ExitButton_clicked()
{
    this->close();
}
