#include "GameField.h"
#include <QDebug>
#include <QPainter>
#include <QMoveEvent>

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{

}

void GameField::getParameters(float *dx, float *dy, float *sizeBoard, float *rectX, float *rectY, QVector<char> *character, QVector<char> *numbers) {

    if (width() > height()) {
        *sizeBoard = height() / 10 * 8;
        *rectX = (width() / 2) - (*sizeBoard / 2);
        *rectY = height() / 10;
    }
    else {
        *sizeBoard = width() / 10 * 8;
        *rectY = (height() / 2) - (*sizeBoard / 2);
        *rectX = width() / 10;
    }

    *dx = *sizeBoard / 8;
    *dy = *sizeBoard / 8;

    *character = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    *numbers = {'1', '2', '3', '4', '5', '6', '7', '8'};
}


void GameField::paintEvent(QPaintEvent *event) {

    float dx;
    float dy;
    float sizeBoard;
    float rectX;
    float rectY;
    QVector<char> character;
    QVector<char> numbers;

    getParameters(&dx, &dy, &sizeBoard, &rectX, &rectY, &character, &numbers);

    setMinimumSize(400, 400);

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
        QRect rect1(rectX + dx * i, rectY, dx, -dy);
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
/*
    QVector<ChessType> types = {ChessType::Rook, ChessType::Knight, ChessType::Bishop, ChessType::Queen, ChessType::King, ChessType::Bishop, ChessType::Knight, ChessType::Rook};

    for (int i = 0; i < 8; i++) {
        paintImage(static_cast<ChessCoordinateCharacter>(CharacterA + i), ChessCoordinateNumber::Number2, ChessType::Pawn, ChessColor::White);
        paintImage(static_cast<ChessCoordinateCharacter>(CharacterA + i), ChessCoordinateNumber::Number7, ChessType::Pawn, ChessColor::Black);
        paintImage(static_cast<ChessCoordinateCharacter>(CharacterA + i), ChessCoordinateNumber::Number1, types[i], ChessColor::White);
        paintImage(static_cast<ChessCoordinateCharacter>(CharacterA + i), ChessCoordinateNumber::Number8, types[i], ChessColor::Black);
    }
    */
    for (int i = 0; i < m_core->figures().count(); i++) {
        ChessFigureAbstract* needFigure = m_core->figures().at(i);
        paintImage(needFigure->coordinate().character(), needFigure->coordinate().number(), needFigure->type(), needFigure->color());
    }
}

void GameField::mousePressEvent(QMouseEvent *event) {

    float dx;
    float dy;
    float sizeBoard;
    float rectX;
    float rectY;
    QVector<char> character;
    QVector<char> numbers;

    getParameters(&dx, &dy, &sizeBoard, &rectX, &rectY, &character, &numbers);

    float posX = (event->pos().x() - rectX) / dx;
    float posY = (event->pos().y() - rectY) / dy;

    if (0 <= posX && posX < 8 && 0 <= posY && posY < 8) {
        qDebug() << QString(character[posX]) + " " + QString(numbers[8 - posY]);
    }
    else
        qDebug() << "Out of size game board";

}

void GameField::paintImage(ChessCoordinateCharacter character, ChessCoordinateNumber number, ChessType type, ChessColor color) {
    float dx;
    float dy;
    float sizeBoard;
    float rectX;
    float rectY;
    QVector<char> characters;
    QVector<char> numbers;

    getParameters(&dx, &dy, &sizeBoard, &rectX, &rectY, &characters, &numbers);

    QPainter painter(this);
    painter.setPen(QPen(Qt::transparent, 1, Qt::SolidLine, Qt::RoundCap));

    QImage figureImage;
    if (color == ChessColor::White) {
        switch (type) {
            case ChessType::Pawn: figureImage = QImage(":/Chess/Pictures/White_Pawn.png"); break;
            case ChessType::Knight: figureImage = QImage(":/Chess/Pictures/White_Knight.png"); break;
            case ChessType::Bishop: figureImage = QImage(":/Chess/Pictures/White_Bishop.png"); break;
            case ChessType::Rook: figureImage = QImage(":/Chess/Pictures/White_Rook.png"); break;
            case ChessType::Queen: figureImage = QImage(":/Chess/Pictures/White_Queen.png"); break;
            case ChessType::King: figureImage = QImage(":/Chess/Pictures/White_King.png"); break;

            default: return;
        }
    }
    else {
        switch (type) {
            case ChessType::Pawn: figureImage = QImage(":/Chess/Pictures/Black_Pawn.png"); break;
            case ChessType::Knight: figureImage = QImage(":/Chess/Pictures/Black_Knight.png"); break;
            case ChessType::Bishop: figureImage = QImage(":/Chess/Pictures/Black_Bishop.png"); break;
            case ChessType::Rook: figureImage = QImage(":/Chess/Pictures/Black_Rook.png"); break;
            case ChessType::Queen: figureImage = QImage(":/Chess/Pictures/Black_Queen.png"); break;
            case ChessType::King: figureImage = QImage(":/Chess/Pictures/Black_King.png"); break;

            default: return;
        }
    }

    //QImage(":/Chess/Pictures/White_Pawn.png");
    QRect rect1(rectX + (dx * character), rectY + (7 * dy - dy * number), dx, dy);
    painter.drawImage(rect1, figureImage);
}

void GameField::setCore(Core* newCore) {
    m_core = newCore;
}

