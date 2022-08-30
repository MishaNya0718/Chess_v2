#include "ChessFigureKnight.h"

ChessFigureKnight::ChessFigureKnight(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Knight, color, parent)
{

}

QVector<ChessCoordinate> ChessFigureKnight::validMoves(const QVector<ChessFigureAbstract *>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;

    // Добавление доступных ходов для всех коней
    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH && m_coordinate.number() < ChessCoordinateNumber::Number7) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 2));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA && m_coordinate.number() < ChessCoordinateNumber::Number7) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 2));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() > ChessCoordinateCharacter::CharacterB && m_coordinate.number() != ChessCoordinateNumber::Number8) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 2), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() > ChessCoordinateCharacter::CharacterB && m_coordinate.number() != ChessCoordinateNumber::Number1) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 2), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA && m_coordinate.number() > ChessCoordinateNumber::Number2) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 2));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH && m_coordinate.number() > ChessCoordinateNumber::Number2) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 2));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() < ChessCoordinateCharacter::CharacterG && m_coordinate.number() != ChessCoordinateNumber::Number1) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 2), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() < ChessCoordinateCharacter::CharacterG && m_coordinate.number() != ChessCoordinateNumber::Number8) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 2), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    // Исключение белых фигур для белых коней
    if (color() == ChessColor::White) {
        for (int i = 0; i < figuresArray->count(); i++) {
            if (figuresArray->at(i)->color() == ChessColor::White) {
                ChessCoordinate figureCoordinate = figuresArray->at(i)->coordinate();
                for (int j = 0; j < validCoordinatesVector.count(); j++) {
                    if (figureCoordinate == validCoordinatesVector.at(j)) {
                        validCoordinatesVector.remove(j);
                    }
                }
            }
        }
    }

    // Исключение черных фигур для черных коней
    if (color() == ChessColor::Black) {
        for (int i = 0; i < figuresArray->count(); i++) {
            if (figuresArray->at(i)->color() == ChessColor::Black) {
                ChessCoordinate figureCoordinate = figuresArray->at(i)->coordinate();
                for (int j = 0; j < validCoordinatesVector.count(); j++) {
                    if (figureCoordinate == validCoordinatesVector.at(j)) {
                        validCoordinatesVector.remove(j);
                    }
                }
            }
        }
    }

    return std::move(validCoordinatesVector);
}
