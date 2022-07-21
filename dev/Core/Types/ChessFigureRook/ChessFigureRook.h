#ifndef CHESSFIGUREROOK_H
#define CHESSFIGUREROOK_H

#include <QObject>
#include <ChessFigureAbstract.h>

class ChessFigureRook final : public ChessFigureAbstract
{

public:
    explicit ChessFigureRook(ChessCoordinate coordinate, ChessColor color, QObject *parent = nullptr);

    QVector <ChessCoordinate> validMoves(QVector<ChessFigureAbstract>* figuresArray);

signals:

};

#endif // CHESSFIGUREROOK_H
