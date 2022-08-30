#include "ChessFigureKing.h"

ChessFigureKing::ChessFigureKing(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::King, color, parent)
{

}

QVector<ChessCoordinate> ChessFigureKing::validMoves(const QVector<ChessFigureAbstract *>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH && m_coordinate.number() != ChessCoordinateNumber::Number8) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA && m_coordinate.number() != ChessCoordinateNumber::Number8) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA && m_coordinate.number() != ChessCoordinateNumber::Number1) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH && m_coordinate.number() != ChessCoordinateNumber::Number1) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1), m_coordinate.number());
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1), m_coordinate.number());
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.number() != ChessCoordinateNumber::Number8) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    if (m_coordinate.number() != ChessCoordinateNumber::Number1) {
        ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1));
        validCoordinatesVector.append(newValidCoordinate);
    }

    // Исключение белых фигур для белого короля
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

    // Исключение черных фигур для черного короля
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
