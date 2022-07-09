#include "GameField.h"

#include <QPainter>

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{

}

void GameField::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));
    painter.drawEllipse(100, 50, 150, 150);
}
