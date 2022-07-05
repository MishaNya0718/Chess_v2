#include <ChessFigurePawn.h>


ChessFigurePawn::ChessFigurePawn(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Pawn, color, parent)
{

}

QVector<ChessCoordinate> ChessFigurePawn::validMoves(QVector<ChessFigureAbstract>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    if (m_color == ChessColor::White) {
        if (m_coordinate.number() == ChessCoordinateNumber::Number2) {
            ChessCoordinate coordinate = ChessCoordinate(ChessCoordinateNumber::Number3, m_coordinate.character());
            validCoordinatesVector.append(coordinate);
            coordinate = ChessCoordinate(ChessCoordinateNumber::Number4, m_coordinate.character());
            validCoordinatesVector.append(coordinate);
        }
        else {
            if (m_coordinate.number() == ChessCoordinateNumber::Number8)
                return std::move(validCoordinatesVector);

            ChessCoordinate coordinate = ChessCoordinate(static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1), m_coordinate.character());
            validCoordinatesVector.append(coordinate);
        }

        for (int i = 0; i < figuresArray->count(); i++) {

            ChessCoordinate coordinate = figuresArray->at(i).coordinate();

            for (int j = 0; j < validCoordinatesVector.count(); j++) {
                if (coordinate == validCoordinatesVector.at(j)) {
                    validCoordinatesVector.remove(j);
                    j--;
                }
            }
        }

        for (int i = 0; i < figuresArray->count(); i++) {

            ChessCoordinate coordinate = figuresArray->at(i).coordinate();

            if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH &&
                    coordinate == ChessCoordinate(static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1),
                                                  static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1)))
               validCoordinatesVector.append(coordinate);

            if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA  &&
                    coordinate == ChessCoordinate(static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1),
                                                  static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1)))
               validCoordinatesVector.append(coordinate);
        }
    }
    else {

    }
    return std::move(validCoordinatesVector);
}
