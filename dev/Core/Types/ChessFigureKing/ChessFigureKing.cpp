#include "ChessFigureKing.h"

ChessFigureKing::ChessFigureKing(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::King, color, parent)
{

}

QVector<ChessCoordinate> ChessFigureKing::validMoves(QVector<ChessFigureAbstract>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    return std::move(validCoordinatesVector);
}
