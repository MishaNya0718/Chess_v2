#include "ChessFigureQueen.h"

ChessFigureQueen::ChessFigureQueen(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Queen, color, parent)
{

}

QVector<ChessCoordinate> ChessFigureQueen::validMoves(QVector<ChessFigureAbstract>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    return std::move(validCoordinatesVector);
}
