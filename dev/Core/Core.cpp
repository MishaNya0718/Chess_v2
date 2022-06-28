#include "Core.h"
#include <QDebug>
#include <ChessFigurePawn.h>
#include <ChessCoordinate.h>
#include <BaseTypes.h>

Core::Core(QObject *parent)
    : QObject{parent}
{

    qDebug() << "Older brother the best!!!!!!!!!!!";
    qDebug() << "Older brother2 the best!!!!!!!";

    ChessCoordinate coordinate = ChessCoordinate(ChessCoordinateNumber::Number4, ChessCoordinateCharacter::CharacterC);
    ChessFigurePawn Pawn(coordinate, ChessColor::White, this);
    qDebug() << Pawn.color();
    //ChessFigurePawn *pawn = new ChessFigurePawn(coordinate, ChessColor::Black, this);
}

Core::~Core()
{
    qDebug() << "Ядро удалено!!!";
}
