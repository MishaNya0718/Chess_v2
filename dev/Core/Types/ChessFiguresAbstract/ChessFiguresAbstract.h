#ifndef CHESSFIGURESABSTRACT_H
#define CHESSFIGURESABSTRACT_H

#include <QObject>
#include <BaseTypes.h>

class ChessFiguresAbstract : public QObject
{
    Q_OBJECT

public:
    explicit ChessFiguresAbstract(QObject *parent = nullptr);

    ChessColor color() const; //getter
    void setColor(ChessColor newColor); //setter
    virtual QVector <ChessCoordinate> validMoves() = 0;
    bool chessMove(ChessCoordinate moveCoordinate);


signals:


private:
    ChessColor m_color = ChessColor::White;
    ChessType m_type = ChessType::Pawn;
    ChessCoordinate m_coordinate = ChessCoordinate();
    int m_pointValue = 0;

};

#endif // CHESSFIGURESABSTRACT_H
