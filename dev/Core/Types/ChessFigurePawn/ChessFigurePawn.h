#ifndef CHESSFIGUREPAWN_H
#define CHESSFIGUREPAWN_H

#include <QObject>
#include <ChessFigureAbstract.h>

class ChessFigurePawn final : public ChessFigureAbstract
{

public:
    explicit ChessFigurePawn(ChessCoordinate coordinate, ChessColor color, QObject *parent = nullptr);

    QVector <ChessCoordinate> validMoves();

signals:

};

#endif // CHESSFIGUREPAWN_H
