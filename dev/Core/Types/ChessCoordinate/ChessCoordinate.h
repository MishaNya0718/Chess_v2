#ifndef CHESSCOORDINATE_H
#define CHESSCOORDINATE_H

#include <BaseTypes.h>
#include <QDataStream>

class ChessCoordinate {

public:
    explicit ChessCoordinate();
    explicit ChessCoordinate(ChessCoordinateNumber _number, ChessCoordinateCharacter _character);
    bool operator== (const ChessCoordinate &chessCoordinate1);

    ChessCoordinateNumber number() const;
    void setNumber(ChessCoordinateNumber newNumber);

    ChessCoordinateCharacter character() const;
    void setCharacter(ChessCoordinateCharacter newCharacter);

private:
    ChessCoordinateNumber m_number = ChessCoordinateNumber::Number1;
    ChessCoordinateCharacter m_character = ChessCoordinateCharacter::CharacterA;
};

#endif // CHESSCOORDINATE_H
