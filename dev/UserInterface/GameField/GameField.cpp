#include "GameField.h"

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{

}

void GameField::paintEvent(QPaintEvent *event) {
    setMinimumSize(500, 500);
    int dx;
    int dy;
    int rectSideWidth = 0;

    if (width() > height())
        rectSideWidth = height();
    else
        rectSideWidth = width();

    dx = rectSideWidth / 10;
    dy = rectSideWidth / 10;

    QVector<char> character = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    QVector<char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8'};


    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap));

    painter.drawRect(dx, dy, dx * 8, dy * 8);




    /*
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
        QPoint points[4] = {
            QPoint(x + 0 * i, y + 0 * j),
            QPoint(x + 0 * i, y + y * j),
            QPoint(x + x * i, y + y * j),
            QPoint(x + x * i, y + 0 * j)
            };
        painter.drawPolyline(points, 4);
        }
    }



    for (int i = 0; i < 8; i++) {
        painter.setPen(Qt::green);
        QRect rect2(0, y, x, y * i);
        painter.drawRect(rect2);
        painter.drawText(rect2, Qt::AlignCenter, QString(numbers[i]));

        painter.setPen(Qt::blue);
        QRect rect1(x * i, y * 10, x, -y) ;
        painter.drawRect(rect1);
        painter.drawText(rect1, Qt::AlignCenter, QString(character[i]));
    }


*/
    /*
    for (int i = 0; i <= 7; i++) {
    painter.drawText(rect, Qt::AlignCenter, QString(QChar(character[i+1])), &boundingRect);
    //painter.drawText(x * 2 + 100 * i, y / 2, QString(QChar(character[i])));
    }
*/
    /*
    for (int i = 0; i <= 7; i++) {
        painter.drawText(17 * x + 20, (y * 2) + (100 * (7 - i)), QString(QChar(numbers[i])));
        painter.drawText(x * 2 + 100 * i, y / 2, QString(QChar(character[i])));
    }
*/
/*
    for (int i = 0; i <= 7; i++){
        painter.drawText(x / 2, 25 + y + y * i, QString(QChar(numbers[7 - i])));
        //painter.drawText(x * 2 + x * i, 8 * y + 20, QString(QChar(character[i])));
        painter.drawText()

        painter.drawText(9 * x + 25, 25 + y + y * i, QString(QChar(numbers[7 - i])));
        //painter.drawText(x * 2 + x * i, 8 * y + 20, QString(QChar(character[i])));
    }
*/
}
