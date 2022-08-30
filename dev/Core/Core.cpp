#include "Core.h"
#include <QDebug>
#include <ChessFigurePawn.h>
#include <ChessFigureRook.h>
#include <ChessFigureKnight.h>
#include <ChessFigureBishop.h>
#include <ChessFigureKing.h>
#include <ChessFigureQueen.h>
#include <ChessCoordinate.h>
#include <BaseTypes.h>

Core::Core(QObject *parent)
    : QObject{parent}
{
        for (int i = 0; i < 8; i++) {
        ChessCoordinate coordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(CharacterA + i), ChessCoordinateNumber::Number2);
        ChessFigurePawn* pawn = new ChessFigurePawn(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(pawn));

        coordinate = ChessCoordinate(static_cast<ChessCoordinateCharacter>(CharacterA + i), ChessCoordinateNumber::Number7);
        pawn = new ChessFigurePawn(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(pawn));
    }

        ChessCoordinate coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterA, ChessCoordinateNumber::Number1);
        ChessFigureRook* rook = new ChessFigureRook(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterH, ChessCoordinateNumber::Number1);
        rook = new ChessFigureRook(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterA, ChessCoordinateNumber::Number8);
        rook = new ChessFigureRook(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterH, ChessCoordinateNumber::Number8);
        rook = new ChessFigureRook(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterB, ChessCoordinateNumber::Number1);
        ChessFigureKnight* knight = new ChessFigureKnight(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterG, ChessCoordinateNumber::Number1);
        knight = new ChessFigureKnight(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterB, ChessCoordinateNumber::Number8);
        knight = new ChessFigureKnight(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterG, ChessCoordinateNumber::Number8);
        knight = new ChessFigureKnight(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterC, ChessCoordinateNumber::Number1);
        ChessFigureBishop* bishop = new ChessFigureBishop(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterF, ChessCoordinateNumber::Number1);
        bishop = new ChessFigureBishop(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterC, ChessCoordinateNumber::Number8);
        bishop = new ChessFigureBishop(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterF, ChessCoordinateNumber::Number8);
        bishop = new ChessFigureBishop(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterD, ChessCoordinateNumber::Number1);
        ChessFigureQueen* queen = new ChessFigureQueen(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(queen));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterD, ChessCoordinateNumber::Number8);
        queen = new ChessFigureQueen(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(queen));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterE, ChessCoordinateNumber::Number1);
        ChessFigureKing* king = new ChessFigureKing(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(king));

        coordinate = ChessCoordinate(ChessCoordinateCharacter::CharacterE, ChessCoordinateNumber::Number8);
        king = new ChessFigureKing(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(king));

}

const QVector<ChessFigureAbstract *> *Core::figures() const
{
    return &m_figures;
}

void Core::removeFigures(int i)
{
    delete figures()->at(i);
}

Core::~Core()
{
    qDebug() << "Ядро удалено!!!";
}
