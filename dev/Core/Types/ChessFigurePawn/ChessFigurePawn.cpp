#include <ChessFigurePawn.h>

ChessFigurePawn::ChessFigurePawn(ChessCoordinate coordinate, ChessColor color, QObject *parent)
    : ChessFigureAbstract(coordinate, ChessType::Pawn, color, parent)
{

}

QVector<ChessCoordinate> ChessFigurePawn::validMoves(const QVector<ChessFigureAbstract *>* figuresArray) {
    QVector<ChessCoordinate> validCoordinatesVector;
    // Описание доступных ходов для белых пешек
    if (m_color == ChessColor::White) {
        // Первый ход белых пешек на одну или две клетки вперед
        if (m_coordinate.number() == ChessCoordinateNumber::Number2) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), ChessCoordinateNumber::Number3);
            validCoordinatesVector.append(newValidCoordinate);
            newValidCoordinate = ChessCoordinate(m_coordinate.character(), ChessCoordinateNumber::Number4);
            validCoordinatesVector.append(newValidCoordinate);
        }
        // Не первый ход белых пешек на одку клетку вперед
        else {
            if (m_coordinate.number() == ChessCoordinateNumber::Number8)
                return std::move(validCoordinatesVector);

            ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1));
            validCoordinatesVector.append(newValidCoordinate);
        }

        // Исключение из доступных ходов те, перед которыми стоит фигура
        for (int i = 0; i < figuresArray->count(); i++) {

            ChessCoordinate figureCoordinate = figuresArray->at(i)->coordinate();

            for (int j = 0; j < validCoordinatesVector.count(); j++) {                
                if (figureCoordinate == validCoordinatesVector.at(j)) {
                    if (m_coordinate.number() == ChessCoordinateNumber::Number2 && figureCoordinate.number() == ChessCoordinateNumber::Number3) {
                        for (int k = 0; k < validCoordinatesVector.count(); k++) {
                            ChessCoordinate needValidCoordinate = validCoordinatesVector.at(k);
                            if (needValidCoordinate.number() == ChessCoordinateNumber::Number4 && needValidCoordinate.character() == m_coordinate.character()) {
                                validCoordinatesVector.remove(k);
                                break;
                            }
                        }
                    }
                    validCoordinatesVector.remove(j);
                    j--;
                }
            }

        }

        // Добавление в доступные ходы те клетки, на которые можно рубить
        for (int i = 0; i < figuresArray->count(); i++) {

            ChessCoordinate newValidCoordinate = figuresArray->at(i)->coordinate();

            if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH &&
                    newValidCoordinate == ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1),
                                                          static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1)))
               validCoordinatesVector.append(newValidCoordinate);

            if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA  &&
                    newValidCoordinate == ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1),
                                                          static_cast<ChessCoordinateNumber>(m_coordinate.number() + 1)))
               validCoordinatesVector.append(newValidCoordinate);
        }
    }

    // Описание доступных ходов для черных пешек
    else {
        // Первый ход черных пешек на одну или две клетки вперед
        if (m_coordinate.number() == ChessCoordinateNumber::Number7) {
            ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), ChessCoordinateNumber::Number6);
            validCoordinatesVector.append(newValidCoordinate);
            newValidCoordinate = ChessCoordinate(m_coordinate.character(), ChessCoordinateNumber::Number5);
            validCoordinatesVector.append(newValidCoordinate);
        }
        else {
            if (m_coordinate.number() == ChessCoordinateNumber::Number1)
                return std::move(validCoordinatesVector);

            ChessCoordinate newValidCoordinate = ChessCoordinate(m_coordinate.character(), static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1));
            validCoordinatesVector.append(newValidCoordinate);
        }

        // Исключение из доступных ходов те, перед которыми стоит фигура
        for (int i = 0; i < figuresArray->count(); i++) {

            ChessCoordinate figureCoordinate = figuresArray->at(i)->coordinate();

            for (int j = 0; j < validCoordinatesVector.count(); j++) {
                if (figureCoordinate == validCoordinatesVector.at(j)) {
                    if (m_coordinate.number() == ChessCoordinateNumber::Number7 && figureCoordinate.number() == ChessCoordinateNumber::Number6) {
                        for (int k = 0; k < validCoordinatesVector.count(); k++) {
                            ChessCoordinate needValidCoordinate = validCoordinatesVector.at(k);
                            if (needValidCoordinate.number() == ChessCoordinateNumber::Number5 && needValidCoordinate.character() == m_coordinate.character()) {
                                validCoordinatesVector.remove(k);
                                break;
                            }
                        }
                    }
                    validCoordinatesVector.remove(j);
                    j--;
                }
            }
        }

        // Добавление в доступные ходы те клетки, на которые можно рубить
        for (int i = 0; i < figuresArray->count(); i++) {

            ChessCoordinate newValidCoordinate = figuresArray->at(i)->coordinate();

            if (m_coordinate.character() != ChessCoordinateCharacter::CharacterH &&
                    newValidCoordinate == ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() + 1),
                                                          static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1)))
               validCoordinatesVector.append(newValidCoordinate);

            if (m_coordinate.character() != ChessCoordinateCharacter::CharacterA  &&
                    newValidCoordinate == ChessCoordinate(static_cast<ChessCoordinateCharacter>(m_coordinate.character() - 1),
                                                          static_cast<ChessCoordinateNumber>(m_coordinate.number() - 1)))
               validCoordinatesVector.append(newValidCoordinate);
        }
    }

    return std::move(validCoordinatesVector);
}
