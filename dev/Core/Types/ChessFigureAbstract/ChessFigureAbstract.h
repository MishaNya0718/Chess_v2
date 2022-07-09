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
    virtual QVector <ChessCoordinate> validMoves(QVector<ChessFigureAbstract>* figuresArray) = 0;
    bool chessMove(ChessCoordinate moveCoordinate, QVector<ChessFigureAbstract>* figuresArray);

    ChessType type() const;
    void setType(ChessType newType);

    const ChessCoordinate &coordinate() const;
    void setCoordinate(const ChessCoordinate &newCoordinate);

    int pointValue() const;
    void setPointValue(int newPointValue);


protected:
    ChessColor m_color = ChessColor::White;
    ChessCoordinate m_coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterA);


private:
    ChessType m_type = ChessType::Pawn;
    int m_pointValue = 0;


signals:

};

#endif // CHESSFIGUREABSTRACT_H
