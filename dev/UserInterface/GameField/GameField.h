#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <QPainter>

class GameField : public QWidget
{
    Q_OBJECT

public:
    explicit GameField(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

protected:



private:



signals:

};

#endif // GAMEFIELD_H
