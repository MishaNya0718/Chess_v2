#include "GameField.h"
#include <QDebug>
#include <QPainter>
#include <QMoveEvent>
#include <QVector>

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

    // Отрисовка игрового поля
    QPainter painter(this);
    painter.setPen(QPen(Qt::transparent, 1, Qt::SolidLine, Qt::RoundCap));

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
    //---------------------------------------------------------------------------

    // Отрисовка букв и цифр по периметру поля
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
    //---------------------------------------------------------------------------

    // Отрисовка валидных ходов для фигур

    if (chessSelectedFlag) {
        painter.setBrush(QColor(120, 120, 120));
        painter.setPen(Qt::red);
        for (int i = 0; i < m_core->figures()->count(); i++) {
            if (m_core->figures()->at(i)->coordinate().character() == currentChessCoordinate.character() && m_core->figures()->at(i)->coordinate().number() == currentChessCoordinate.number()) {
                QVector <ChessCoordinate> hodi = m_core->figures()->at(i)->validMoves(m_core->figures());
                // Подсветить выбранную фигуру
                painter.drawRect(rectX + currentChessCoordinate.character() * dx, rectY + (7 - currentChessCoordinate.number()) * dy, dx, dy);
                for (int j = 0; j < hodi.count(); j++) {
                    painter.drawRect(rectX + hodi.at(j).character() * dx, rectY + (7 - hodi.at(j).number()) * dy, dx, dy);
                }
                break;
            }
        }
    }
    // Отрисовка стандартного поля, если флаг опущен
    else {

    }
    //---------------------------------------------------------------------------

    // Отрисовка фигур на поле
    for (int i = 0; i < m_core->figures()->count(); i++) {
        ChessFigureAbstract* needFigure = m_core->figures()->at(i);
        paintImage(needFigure->coordinate().character(), needFigure->coordinate().number(), needFigure->type(), needFigure->color());
    }
    //---------------------------------------------------------------------------
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
    ChessCoordinate choiceCoordinate(static_cast<ChessCoordinateCharacter>((int) posX), static_cast<ChessCoordinateNumber>((int) (8 - posY)));
    int removedFigureIndex = -1;

    if (event->button() == Qt::LeftButton) {
        if (0 <= posX && posX < 8 && 0 <= posY && posY < 8) {
            if (!chessSelectedFlag) {
                for (int i = 0; i < m_core->figures()->count(); i++) {
                    if (m_core->figures()->at(i)->coordinate().character() == (int) posX && m_core->figures()->at(i)->coordinate().number() == (int) (8 - posY)) {

                        QVector <ChessCoordinate> validMoves = m_core->figures()->at(i)->validMoves(m_core->figures());
                        currentChessCoordinate = m_core->figures()->at(i)->coordinate();

                        qDebug() << "Текущая позиция:" << QString(character[currentChessCoordinate.character()]) + " " + QString(numbers[currentChessCoordinate.number()]);

                        for (int i = 0; i < validMoves.count(); i++) {
                            qDebug() << "Доступный ход:" << QString(character[(validMoves.at(i).character())]) << validMoves.at(i).number() + 1;
                        }

                        qDebug() << "Flag = true";
                        chessSelectedFlag = true;
                        break;
                    }
                }
            }
            else {
                for (int i = 0; i < m_core->figures()->count(); i++) {
                    if (currentChessCoordinate == m_core->figures()->at(i)->coordinate()) {
                        QVector <ChessCoordinate> validMoves = m_core->figures()->at(i)->validMoves(m_core->figures());
                        for (int j = 0; j < validMoves.count(); j++) {
                            if (validMoves.at(j).character() == (int)posX && validMoves.at(j).number() == 7 - (int)posY) {
                                for (int k = 0; k < m_core->figures()->count(); k++) {
                                    if (m_core->figures()->at(k)->coordinate() == choiceCoordinate) {
                                        //m_core->removeFigures(k);
                                        removedFigureIndex = k;
                                        qDebug() << "Вывод координат фигуры, которую надо удалить" << m_core->figures()->at(k)->coordinate().character() << m_core->figures()->at(k)->coordinate().number();
                                        break;
                                    }
                                }
                                 m_core->figures()->at(i)->setCoordinate(validMoves.at(j));

                                 if (removedFigureIndex > -1)
                                    m_core->removeFigures(removedFigureIndex);

                                 break;
                            }
                        }
                        chessSelectedFlag = false;
                        qDebug() << "Flag = false";
                        break;
                    }
                }
            }

            /*
            else {
                for (int i = 0; i < m_core->figures()->count(); i++) {
                    if (currentChessCoordinate == m_core->figures()->at(i)->coordinate()) {
                        for (int j = 0; j < hodi.count(); j++) {
                            if (hodi.at(j).character() == (int)posX && hodi.at(j).number() == 7 - (int)posY) {
                                for (int k = 0; k < m_core->figures()->count(); k++) {
                                    if (m_core->figures()->at(k)->coordinate().character() == hodi.at(j).character() &&
                                            m_core->figures()->at(k)->coordinate().number() == hodi.at(j).number()) {
                                        //m_core->removeFigures(k);
                                        qDebug() << "Вывод координат фигуры, которую надо удалить" << m_core->figures()->at(k)->coordinate().character() << m_core->figures()->at(k)->coordinate().number();
                                        break;
                                    }
                                }
                                m_core->figures()->at(i)->setCoordinate(hodi.at(j));
                            }
                        }
                        chessSelectedFlag = false;
                        qDebug() << "Flag = false";
                        break;
                    }
                }
            }
            */
        }
    }
    update();
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

    QRect rect1(rectX + (dx * character), rectY + (7 * dy - dy * number), dx, dy);
    painter.drawImage(rect1, figureImage);
}

void GameField::setCore(Core* newCore) {
    m_core = newCore;
}

