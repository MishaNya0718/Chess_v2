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
        ChessCoordinate coordinate = ChessCoordinate(ChessCoordinateNumber::Number2, static_cast<ChessCoordinateCharacter>(CharacterA + i));
        ChessFigurePawn* pawn = new ChessFigurePawn(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(pawn));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number7, static_cast<ChessCoordinateCharacter>(CharacterA + i));
        pawn = new ChessFigurePawn(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(pawn));
    }

        ChessCoordinate coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterA);
        ChessFigureRook* rook = new ChessFigureRook(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterH);
        rook = new ChessFigureRook(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterA);
        rook = new ChessFigureRook(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterH);
        rook = new ChessFigureRook(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(rook));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterB);
        ChessFigureKnight* knight = new ChessFigureKnight(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterG);
        knight = new ChessFigureKnight(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterB);
        knight = new ChessFigureKnight(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterG);
        knight = new ChessFigureKnight(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(knight));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterC);
        ChessFigureBishop* bishop = new ChessFigureBishop(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterF);
        bishop = new ChessFigureBishop(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterC);
        bishop = new ChessFigureBishop(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterF);
        bishop = new ChessFigureBishop(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(bishop));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterD);
        ChessFigureQueen* queen = new ChessFigureQueen(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(queen));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterD);
        queen = new ChessFigureQueen(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(queen));

        //-------------------------------------------------------------------------------------------------

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number1, ChessCoordinateCharacter::CharacterE);
        ChessFigureKing* king = new ChessFigureKing(coordinate, ChessColor::White, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(king));

        coordinate = ChessCoordinate(ChessCoordinateNumber::Number8, ChessCoordinateCharacter::CharacterE);
        king = new ChessFigureKing(coordinate, ChessColor::Black, this);
        m_figures.append(dynamic_cast<ChessFigureAbstract *>(king));

}

const QList<ChessFigureAbstract *> &Core::figures() const
{
    return m_figures;
}

Core::~Core()
{
    qDebug() << "Ядро удалено!!!";
}
