#ifndef CHESSFIGUREKING_H
#define CHESSFIGUREKING_H

#include <QObject>
#include <ChessFigureAbstract.h>

class ChessFigureKing final : public ChessFigureAbstract
{

public:
    explicit ChessFigureKing(ChessCoordinate coordinate, ChessColor color, QObject *parent = nullptr);

    QVector <ChessCoordinate> validMoves(const QVector<ChessFigureAbstract *>* figuresArray);

signals:

};

#endif // CHESSFIGUREKING_H
