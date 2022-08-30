#include "ChessFigureBishop.h"

ChessFigureBishop::ChessFigureBishop(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract{coordinate, ChessType::Bishop, color, parent}
{

}

QVector<ChessCoordinate> ChessFigureBishop::validMoves(const QVector<ChessFigureAbstract *>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    int l;

    if (m_coordinate.character() > m_coordinate.number()) {
        l = m_coordinate.character();
    }
    else {
        l = m_coordinate.number();
    }

    // Добавление доступных ходов для всех слонов
    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH && m_coordinate.number() != ChessCoordinateNumber::Number8) {
        for (int i = 1; i <= l; i++) {
                ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + i), static_cast<ChessCoordinateNumber>(m_coordinate.number() + i));
                validCoordinatesVector.append(newValidCoordinate);
        }
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA && m_coordinate.number() != ChessCoordinateNumber::Number8) {
        for (int i = 1; i <= l; i++) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - i), static_cast<ChessCoordinateNumber>(m_coordinate.number() + i));
            validCoordinatesVector.append(newValidCoordinate);
        }
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA && m_coordinate.number() != ChessCoordinateNumber::Number1) {
        for (int i = 1; i <= l; i++) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - i), static_cast<ChessCoordinateNumber>(m_coordinate.number() - i));
            validCoordinatesVector.append(newValidCoordinate);
        }
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH && m_coordinate.number() != ChessCoordinateNumber::Number1) {
        for (int i = 1; i <= l; i++) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + i), static_cast<ChessCoordinateNumber>(m_coordinate.number() - i));
            validCoordinatesVector.append(newValidCoordinate);
        }
    }

    return std::move(validCoordinatesVector);
}
