#include "ChessFigureKnight.h"

ChessFigureKnight::ChessFigureKnight(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Knight, color, parent)
{

}

QVector<ChessCoordinate> ChessFigureKnight::validMoves(QVector<ChessFigureAbstract>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    return std::move(validCoordinatesVector);
}
