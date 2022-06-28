#include "Core.h"
#include <QDebug>
#include <ChessFigureAbstract.h>

Core::Core(QObject *parent)
    : QObject{parent}
{

    qDebug() << "Older brother the best!!!!!!!!!!!";
    qDebug() << "Older brother2 the best!!!!!!!";
}

Core::~Core()
{
    qDebug() << "Ядро удалено!!!";
}
