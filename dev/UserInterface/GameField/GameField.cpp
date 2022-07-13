#include "GameField.h"
#include <QDebug>

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{

}

void GameField::paintEvent(QPaintEvent *event) {
    setMinimumSize(500, 500);
    int dx;
    int dy;
    int sizeBoard = 0;
    int rectX;
    int rectY;
    int currentX;
    int currentY;

    if (width() > height()) {
        sizeBoard = height() / 10 * 8;
        rectX = (width() / 2) - (sizeBoard / 2);
        rectY = height() / 10;
    }
    else {
        sizeBoard = width() / 10 * 8;
        rectY = (height() / 2) - (sizeBoard / 2);
        rectX = width() / 10;
    }

    dx = sizeBoard / 8;
    dy = sizeBoard / 8;

    QVector<char> character = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    QVector<char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8'};


    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap));

    //painter.drawRect(rectX, rectY, sizeBoard, sizeBoard);

    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
        QPoint points[5] = {
            QPoint(rectX, rectY),
            QPoint(rectX + dx * i, rectY),
            QPoint(rectX + dx * i, rectY + dy * j),
            QPoint(rectX, rectY + dy * j),
            QPoint(rectX, rectY)
            };
        painter.drawPolyline(points, 5);

        }
    }



/*
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
