#include "ChessFigureRook.h"

ChessFigureRook::ChessFigureRook(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Rook, color, parent)
{

}

QVector<ChessCoordinate> ChessFigureRook::validMoves(const QVector<ChessFigureAbstract *>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;

    // Добавление доступных ходов для всех ладей
    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH) {
        for (int i = 1; i <= ChessCoordinateCharacter::CharacterH - m_coordinate.character(); i++) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + i), m_coordinate.number());
            validCoordinatesVector.append(newValidCoordinate);
        }
    }

    if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA) {
        for (int i = 1; i <= ChessCoordinateCharacter::CharacterA + m_coordinate.character(); i++) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - i), m_coordinate.number());
            validCoordinatesVector.append(newValidCoordinate);
        }
    }

    if (m_coordinate.number() != ChessCoordinateNumber::Number1) {
        for (int i = 1; i <= ChessCoordinateNumber::Number1 + m_coordinate.number(); i++) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), static_cast<ChessCoordinateNumber>(m_coordinate.number() - i));
            validCoordinatesVector.append(newValidCoordinate);
        }
    }

    if (m_coordinate.number() != ChessCoordinateNumber::Number8) {
        for (int i = 1; i <= ChessCoordinateNumber::Number8 - m_coordinate.number(); i++) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), static_cast<ChessCoordinateNumber>(m_coordinate.number() + i));
            validCoordinatesVector.append(newValidCoordinate);
        }
    }

    // Исключение белых фигур для белой ладьи
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

    // Исключение черных фигур для черной ладьи
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
