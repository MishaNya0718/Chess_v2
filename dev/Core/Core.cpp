#include "Core.h"
#include <QDebug>
#include <ChessFiguresAbstract.h>

Core::Core(QObject *parent)
    : QObject{parent}
{

    qDebug() << "Older brother the best!!!!!!!!!!!";
    qDebug() << "Older brother2 the best!!!!!!!";
    ChessFiguresAbstract newFigure = ChessFiguresAbstract();
    qDebug() << newFigure.color();
}

Core::~Core()
{
    qDebug() << "Ядро удалено!!!";
}
