#include "GameField.h"
#include <QDebug>

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{

}

void GameField::paintEvent(QPaintEvent *event) {
    setMinimumSize(400, 400);
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

    painter.drawRect(rectX, rectY, sizeBoard, sizeBoard);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            QPoint points[5] = {
                QPoint(rectX + dx * i, rectY + dy * j),
                QPoint(rectX + dx * (i + 1), rectY + dy * j),
                QPoint(rectX + dx * (i + 1), rectY + dy * (j + 1)),
                QPoint(rectX + dx * i, rectY + dy * (j + 1)),
                QPoint(rectX + dx * i, rectY + dy * j)

            };
        painter.drawPolyline(points, 5);
        }
    }
    for (int i = 0; i < 8; i++) {
        // Верх
        painter.setPen(Qt::blue);
        QRect rect1(rectX + dx * i, rectY, dx, -rectY + (rectY - dy)) ;
        painter.drawRect(rect1);
        painter.drawText(rect1, Qt::AlignCenter, QString(character[i]));

        // Низ
        QRect rect2(rectX + dx * i, rectY + sizeBoard + dy, dx, -rectY + (rectY - dy));
        painter.drawRect(rect2);
        painter.drawText(rect2, Qt::AlignCenter, QString(character[i]));

        // Лево
        QRect rect3(rectX - dx, rectY + dy + dy * i, dx, rectY - (rectY + dy));
        painter.drawRect(rect3);
        painter.drawText(rect3, Qt::AlignCenter, QString(numbers[7 - i]));

        // Право
        QRect rect4(rectX + sizeBoard, rectY + dy + dy * i, dx, rectY - (rectY + dy));
        painter.drawRect(rect4);
        painter.drawText(rect4, Qt::AlignCenter, QString(numbers[7 - i]));
    }
}



