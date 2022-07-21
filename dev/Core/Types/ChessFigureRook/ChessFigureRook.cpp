#include "ChessFigureRook.h"

ChessFigureRook::ChessFigureRook(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Rook, color, parent)
{

}

QVector<ChessCoordinate> ChessFigureRook::validMoves(QVector<ChessFigureAbstract>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    return std::move(validCoordinatesVector);
}
