#include "topbat.h"
#include <QDebug>


TopBat::TopBat(PingPong* pingPong)
{
    this->pingPong = pingPong;     
    startX = pingPong->topBatX;
    rightMarginBoundary = false;    
    timerID = 0;
    batMovement = 1;
}

QRectF TopBat:: boundingRect() const
{
    return QRectF(startX, 20, startX + pingPong->BAT_LENGTH, 10) ;
}

QPainterPath TopBat::shape() const
{
    QPainterPath p;
    return p;
}

void TopBat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawLine(startX, 20, startX + pingPong->BAT_LENGTH, 20);
}

void TopBat::timerEvent(QTimerEvent *event)
{
    timerID = event->timerId();
    qDebug() << "TopBat::timerEvent  startX: " << startX;

    if(startX >= pingPong->BAT_MAX_X)
    {
        qDebug() << "TopBat::timerEvent if 1";
        rightMarginBoundary = true;
    }
    else if(startX <= 0)
    {
        qDebug() << "TopBat::timerEvent if 2";
        rightMarginBoundary = false;
    }

    if(!rightMarginBoundary)
    {
        qDebug() << "TopBat::timerEvent if 3";
        startX = startX + batMovement;
    } else
    {
        qDebug() << "TopBat::timerEvent if 4";
        startX = startX - batMovement;
    }

    scene()->update(startX, pingPong->TOP_BAT_Y, startX + pingPong->BAT_LENGTH, pingPong->TOP_BAT_Y);
}

void TopBat::startMovement(int timeout)
{
    qDebug() << "TopBat::startMovement timeout:" << timeout;    
    startTimer(timeout);
}

void TopBat::stopMovement()
{
    killTimer(timerID);
}

qreal TopBat::getBatX()
{
    return startX;
}

void TopBat::setBatMovementFactorX(qreal factor)
{
    batMovement = factor;
}
