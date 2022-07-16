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
    painter.setPen(QPen(Qt::transparent, 1, Qt::SolidLine, Qt::RoundCap));

    //painter.drawRect(rectX, rectY, sizeBoard, sizeBoard);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (i % 2 == 0) {
                if (j % 2 == 0)
                    painter.setBrush(QColor(255, 218, 185));
                else
                    painter.setBrush(QColor(160, 82, 45));
            }
            else {
                if (j % 2 == 0)
                    painter.setBrush(QColor(160, 82, 45));
                else
                    painter.setBrush(QColor(255, 218, 185));
            }

            QRect rect0(rectX + dx * i, rectY + dy * j, dx, dy);

            painter.setPen(Qt::transparent);
            painter.drawRect(rect0);

            //painter.setPen(Qt::black);
            //painter.drawText(rect0, Qt::AlignCenter, QString(character[i]));
        }
    }

    painter.setBrush(QColor(154,205,50));
    for (int i = 0; i < 8; i++) {
        // Верх
        painter.setPen(Qt::blue);
        QRect rect1(rectX + dx * i, rectY, dx, -dy) ;
        painter.drawRect(rect1);
        painter.drawText(rect1, Qt::AlignCenter, QString(character[i]));

        // Низ
        QRect rect2(rectX + dx * i, rectY + sizeBoard + dy, dx, -dy);
        painter.drawRect(rect2);
        painter.drawText(rect2, Qt::AlignCenter, QString(character[i]));

        // Лево
        QRect rect3(rectX - dx, rectY + dy * i, dx, dy);
        painter.drawRect(rect3);
        painter.drawText(rect3, Qt::AlignCenter, QString(numbers[7 - i]));

        // Право
        QRect rect4(rectX + sizeBoard, rectY + dy * i, dx, dy);
        painter.drawRect(rect4);
        painter.drawText(rect4, Qt::AlignCenter, QString(numbers[7 - i]));
    }
}

