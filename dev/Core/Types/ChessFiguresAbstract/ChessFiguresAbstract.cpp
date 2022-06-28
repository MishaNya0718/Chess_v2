#include <ChessFiguresAbstract.h>

ChessFiguresAbstract::ChessFiguresAbstract(QObject *parent)
    : QObject{parent}
{

}

ChessColor ChessFiguresAbstract::color() const {
    return m_color;
}

void ChessFiguresAbstract::setColor(ChessColor newColor) {
    m_color = newColor;
}

bool ChessFiguresAbstract::chessMove(ChessCoordinate moveCoordinate) {
    bool validMove = false;
    QVector <ChessCoordinate> needValidMoves = validMoves();
    for (int i = 0; i < needValidMoves.count(); i++) {
        if ((needValidMoves[i].character() == moveCoordinate.character()) && (needValidMoves[i].number() == moveCoordinate.number())) {
            bool validMove = true;
            m_coordinate = moveCoordinate;
            break;
        }
    }
    return validMove;
}
