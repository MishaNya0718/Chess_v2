#include "ChessCoordinate.h"

ChessCoordinate::ChessCoordinate()
{

}

ChessCoordinate::ChessCoordinate(ChessCoordinateCharacter _character, ChessCoordinateNumber _number){
    m_number = _number;
    m_character = _character;
}

bool ChessCoordinate::operator== (const ChessCoordinate &chessCoordinate1) {
    if (m_character == chessCoordinate1.m_character && m_number == chessCoordinate1.m_number)
        return true;
    else
        return false;
}

bool operator== (const ChessCoordinate &chessCoordinate1, const ChessCoordinate &chessCoordinate2) {
    if (chessCoordinate1.m_character == chessCoordinate2.m_character && chessCoordinate1.m_number == chessCoordinate2.m_number)
        return true;
    else
        return false;
}

ChessCoordinate ChessCoordinate::operator=(const ChessCoordinate &chessCoordinate2) {
    m_character = chessCoordinate2.m_character;
    m_number = chessCoordinate2.m_number;
    ChessCoordinate coordinate(m_character, m_number);
    return coordinate;
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
