#ifndef CHESSFIGUREABSTRACT_H
#define CHESSFIGUREABSTRACT_H

#include <QObject>
#include <BaseTypes.h>
#include <ChessCoordinate.h>

class ChessFigureAbstract : public QObject
{
    Q_OBJECT

public:
    explicit ChessFigureAbstract(ChessCoordinate coordinate, ChessType type, ChessColor color, QObject *parent = nullptr);

    ChessColor color() const; //getter
    void setColor(ChessColor newColor); //setter
    virtual QVector <ChessCoordinate> validMoves() = 0;
    bool chessMove(ChessCoordinate moveCoordinate);


    ChessType type() const;
    void setType(ChessType newType);

    const ChessCoordinate &coordinate() const;
    void setCoordinate(const ChessCoordinate &newCoordinate);

    int pointValue() const;
    void setPointValue(int newPointValue);

signals:


private:
    ChessColor m_color = ChessColor::White;
    ChessType m_type = ChessType::Pawn;
    ChessCoordinate m_coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterA);
    int m_pointValue = 0;

};

#endif // CHESSFIGUREABSTRACT_H
