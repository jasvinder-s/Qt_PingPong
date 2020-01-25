#include "ball.h"
#include <QDebug>

Ball::Ball(PingPong *pingPong)
{
    this->pingPong = pingPong;
    ballX = this->pingPong->SCENE_WIDTH/2;
    ballY = this->pingPong->SCENE_HEIGHT/2;
    BALL_WIDTH = 20;
    BALL_HEIGHT = 20;
    rightBoundary = false;
    bottomBoundary = false;

    timerID = 0;
    ballMovementFactorY = 1;

    // signal check's bat position relative to ball when ball reaches either end.
    QObject::connect(this, SIGNAL(ballPositionX(qreal)), this, SLOT(checkBatPosition(qreal)));
}
// QGraphicsItem related function
QRectF Ball:: boundingRect() const
{
    // return value not significant here
    return QRectF(0, 0, 0, 0) ;
}

// QGraphicsItem related function
QPainterPath Ball::shape() const
{
    QPainterPath p;
    return p;
}

// QGraphicsItem related function
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(ballX, ballY, BALL_WIDTH, BALL_HEIGHT);
}

void Ball::timerEvent(QTimerEvent *event)
{    
    qDebug("Ball::timerEvent");
    timerID = event->timerId();
    // check for horizontal movement
    if(ballX + BALL_WIDTH == pingPong->BAT_MAX_X + pingPong->BAT_LENGTH)
    {
        rightBoundary = true;
    }
    else if(ballX == 0)
    {
        rightBoundary = false;
    }

    if(!rightBoundary)
    {
        ballX++;
    } else
    {
        ballX--;
    }

    // check for vertical movement
    if(ballY + BALL_HEIGHT >= pingPong->BOTTOM_BAT_Y)
    {
        bottomBoundary = true;
        qDebug("test 1");
        emit ballPositionX(ballX);
    }
    else if(ballY <= pingPong->TOP_BAT_Y) {
        bottomBoundary = false;
        qDebug("test 2");
        emit ballPositionX(ballX);
    }

    if(!bottomBoundary)
        ballY = ballY + ballMovementFactorY;
    else
        ballY = ballY - ballMovementFactorY;

    //qDebug() << " " << this->ballX;
    scene()->update();
}

void Ball::startMovement(int timeout)
{
    qDebug() << "Ball::startMovement timeout:" << timeout;
    startTimer(timeout);
    qDebug() << "Ball::startMovement after start timer";
}

void Ball::stopMovement()
{
    killTimer(timerID);
}

qreal Ball::getBallY()
{
    return ballY;
}

qreal Ball::getBallHeight()
{
    return BALL_HEIGHT;
}

qreal Ball::getBallWidth()
{
    return BALL_WIDTH;
}

void Ball::checkBatPosition(qreal ballPosition)
{
    pingPong->checkBatPosition(ballPosition);
}

void Ball::setBallMovementFactorY(qreal factor)
{
    ballMovementFactorY = factor;
}


