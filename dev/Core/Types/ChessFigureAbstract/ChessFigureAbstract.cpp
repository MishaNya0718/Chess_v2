#include <ChessFigureAbstract.h>
#include <QDebug>

ChessFigureAbstract::ChessFigureAbstract(ChessCoordinate coordinate, ChessType type, ChessColor color, QObject *parent)
    : QObject{parent}
{
    m_coordinate = coordinate;
    m_type = type;
    m_color = color;
    qDebug() << "type is" << type;
    qDebug() << "color is" << color;
}

ChessColor ChessFigureAbstract::color() const {
    return m_color;
}

void ChessFigureAbstract::setColor(ChessColor newColor) {
    m_color = newColor;
}

ChessType ChessFigureAbstract::type() const {
    return m_type;
}

void ChessFigureAbstract::setType(ChessType newType) {
    m_type = newType;
}

const ChessCoordinate &ChessFigureAbstract::coordinate() const {
    return m_coordinate;
}

void ChessFigureAbstract::setCoordinate(const ChessCoordinate &newCoordinate) {
    m_coordinate = newCoordinate;
}

int ChessFigureAbstract::pointValue() const {
    return m_pointValue;
}

void ChessFigureAbstract::setPointValue(int newPointValue) {
    m_pointValue = newPointValue;
}


bool ChessFigureAbstract::chessMove(ChessCoordinate moveCoordinate) {
    bool validMove = false;
    QVector <ChessCoordinate> needValidMoves = validMoves();
    for (int i = 0; i < needValidMoves.count(); i++) {
        if ((needValidMoves[i].character() == moveCoordinate.character()) && (needValidMoves[i].number() == moveCoordinate.number())) {
            bool validMove = true;
            m_coordinate = moveCoordinate;
            break;
        }
    }
    return validMove;
}

