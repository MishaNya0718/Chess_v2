#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <ChessFigureAbstract.h>

class Core : public QObject
{
    Q_OBJECT
public:
    explicit Core(QObject *parent = nullptr);
    ~Core();

    const QList<ChessFigureAbstract *> &figures() const;

private:
    QList<ChessFigureAbstract *> m_figures;



signals:

};

#endif // CORE_H
