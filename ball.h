#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QGraphicsItem>
#include "pingpong.h"

class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Ball(PingPong*);
    // QGraphicsItem related function
    QRectF boundingRect() const;
    // QGraphicsItem related function
    QPainterPath shape() const;
    // QGraphicsItem related function
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    // start ball movement at speed given by timeout
    void startMovement(int timeout);
    // stop ball movement
    void stopMovement();
    // return ball's current co-ordinates
    qreal getBallY();

    qreal getBallHeight();
    qreal getBallWidth();

    // set the factor with which ball's x and y co-ordinates are incremented
    // or decremented
    void setBallMovementFactorY(qreal factor);

    friend class TestGui;

protected:
     // update ball co-ordinates and graphics scene
     void timerEvent(QTimerEvent *event);

signals:
     void ballPositionX(qreal x);  

public slots:
     // check the position of bat relative to ball
     void checkBatPosition(qreal ballPosition);

private:
     PingPong* pingPong;

     qreal BALL_WIDTH;
     qreal BALL_HEIGHT;
     qreal ballX;
     qreal ballY;
     // boolean variables to turn the direction of ball
     bool rightBoundary;
     bool bottomBoundary;
     // required for stopping the timer
     int timerID;
     // determins how fast the ball is moving on the screen
     qreal ballMovementFactorY;

};

#endif // BALL_H
