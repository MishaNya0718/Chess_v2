#include "ChessFigureBishop.h"

ChessFigureBishop::ChessFigureBishop(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract{coordinate, ChessType::Bishop, color, parent}
{

}

QVector<ChessCoordinate> ChessFigureBishop::validMoves(QVector<ChessFigureAbstract>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    return std::move(validCoordinatesVector);
}
