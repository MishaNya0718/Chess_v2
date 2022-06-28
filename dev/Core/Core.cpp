#include "Core.h"
#include <QDebug>
#include <ChessFiguresAbstract.h>
#include <iostream>

Core::Core(QObject *parent)
    : QObject{parent}
{

    qDebug() << "Older brother the best!!!!!!!!!!!";
    qDebug() << "Older brother2 the best!!!!!!!";
    //ChessFiguresAbstract newFigure = ChessFiguresAbstract();
    //qDebug() << "Figure has color" << newFigure.color();
}

Core::~Core()
{
    qDebug() << "Ядро удалено!!!";
}
