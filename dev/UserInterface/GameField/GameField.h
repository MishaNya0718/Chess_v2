#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QWidget>

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



signals:

};

#endif // GAMEFIELD_H
