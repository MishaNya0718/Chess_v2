#ifndef CHESSFIGUREKNIGHT_H
#define CHESSFIGUREKNIGHT_H

#include <QObject>
#include <ChessFigureAbstract.h>

class ChessFigureKnight final : public ChessFigureAbstract
{

public:
    explicit ChessFigureKnight(ChessCoordinate coordinate, ChessColor color, QObject *parent = nullptr);

    QVector <ChessCoordinate> validMoves(QVector<ChessFigureAbstract>* figuresArray);

signals:

};

#endif // CHESSFIGUREKNIGHT_H
