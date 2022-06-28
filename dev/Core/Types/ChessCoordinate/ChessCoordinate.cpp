#include "ChessCoordinate.h"

ChessCoordinate::ChessCoordinate(ChessCoordinateNumber _number, ChessCoordinateCharacter _character){
    m_number = _number;
    m_character = _character;
}

bool ChessCoordinate::operator== (const ChessCoordinate &chessCoordinate1) {
    if (m_character == chessCoordinate1.m_character && m_number == chessCoordinate1.m_number)
        return true;
    else
        return false;
}

ChessCoordinateNumber ChessCoordinate::number() const {
    return m_number;
}

void ChessCoordinate::setNumber(ChessCoordinateNumber newNumber) {
    m_number = newNumber;
}

ChessCoordinateCharacter ChessCoordinate::character() const {
    return m_character;
}

void ChessCoordinate::setCharacter(ChessCoordinateCharacter newCharacter) {
    m_character = newCharacter;
}
