#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>
#include <BaseTypes.h>

class GameField : public QWidget
{
    Q_OBJECT

public:
    explicit GameField(QWidget *parent = nullptr);

    void getParameters(float *dx, float *dy, float *sizeBoard, float *rectX, float *rectY, QVector<char> *character, QVector<char> *numbers);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;



protected:



private:
    void paintImage(ChessCoordinateCharacter x, ChessCoordinateNumber y, ChessType type);


signals:

};

#endif // GAMEFIELD_H
