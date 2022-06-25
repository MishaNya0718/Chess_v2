#include "ChessFiguresAbstract.h"

ChessFiguresAbstract::ChessFiguresAbstract(QObject *parent)
    : QObject{parent}
{

}

ChessColor ChessFiguresAbstract::color() const
{
    return m_color;
}

void ChessFiguresAbstract::setColor(ChessColor newColor)
{
    m_color = newColor;
}
