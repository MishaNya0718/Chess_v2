#ifndef CHESSFIGUREQUEEN_H
#define CHESSFIGUREQUEEN_H

#include <QObject>
#include <ChessFigureAbstract.h>

class ChessFigureQueen final : public ChessFigureAbstract
{

public:
    explicit ChessFigureQueen(ChessCoordinate coordinate, ChessColor color, QObject *parent = nullptr);

    QVector <ChessCoordinate> validMoves(QVector<ChessFigureAbstract>* figuresArray);

signals:

};

#endif // CHESSFIGUREQUEEN_H
