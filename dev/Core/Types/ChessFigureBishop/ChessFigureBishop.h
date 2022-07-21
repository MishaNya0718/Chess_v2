#ifndef CHESSFIGUREBISHOP_H
#define CHESSFIGUREBISHOP_H

#include <QObject>
#include <ChessFigureAbstract.h>

class ChessFigureBishop final : public ChessFigureAbstract
{

public:
    explicit ChessFigureBishop(ChessCoordinate coordinate, ChessColor color, QObject *parent = nullptr);

    QVector <ChessCoordinate> validMoves(QVector<ChessFigureAbstract>* figuresArray);

signals:

};

#endif // CHESSFIGUREBISHOP_H
