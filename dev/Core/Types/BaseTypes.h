#ifndef BASETYPES_H
#define BASETYPES_H

enum ChessColor : int {
    White = 0,
    Black = 1
};

enum ChessType : int {
    Pawn = 0,
    Knight = 1,
    Bishop = 2,
    Rook = 3,
    Queen = 4,
    King = 5
};

enum ChessCoordinateCharacter : int {
    CharacterA = 0,
    CharacterB = 1,
    CharacterC = 2,
    CharacterD = 3,
    CharacterE = 4,
    CharacterF = 5,
    CharacterG = 6,
    CharacterH = 7
};

enum ChessCoordinateNumber : int {
    Number1 = 0,
    Number2 = 1,
    Number3 = 2,
    Number4 = 3,
    Number5 = 4,
    Number6 = 5,
    Number7 = 6,
    Number8 = 7
};
/*
class ChessCoordinate {

    ChessCoordinate(ChessCoordinateNumber _number, ChessCoordinateCharacter _character){
        number = _number;
        character = _character;
    }

    bool operator== (const ChessCoordinate &chessCoordinate1) {
        if (character == chessCoordinate1.character && number == chessCoordinate1.number) {
            return true;
        }
        else {
            return false;
        }
    }

    ChessCoordinate(){}


    ChessCoordinate(ChessCoordinateNumber number, ChessCoordinateCharacter character){
        this -> number = number;
        this -> character = character;
    }

    ChessCoordinateNumber number = ChessCoordinateNumber::Number1;
    ChessCoordinateCharacter character = ChessCoordinateCharacter::CharacterA;
};
*/
#endif // BASETYPES_H
