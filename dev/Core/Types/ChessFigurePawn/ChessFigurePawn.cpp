#include <ChessFigurePawn.h>


ChessFigurePawn::ChessFigurePawn(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Pawn, color, parent)
{

}

QVector<ChessCoordinate> ChessFigurePawn::validMoves() {

}
