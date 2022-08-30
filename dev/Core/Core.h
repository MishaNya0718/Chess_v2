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

    void removeFigures(int i);


    const QVector<ChessFigureAbstract *> *figures() const;

private:
    QVector<ChessFigureAbstract *> m_figures;



signals:

};

#endif // CORE_H
