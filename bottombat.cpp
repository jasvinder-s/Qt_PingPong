#include "bottombat.h"
#include <QDebug>


BottomBat::BottomBat(PingPong* pingPong)
{
    this->pingPong = pingPong;

}

QRectF BottomBat::boundingRect() const
{     
    // return value not significant here
    return QRectF(0, 0, 0, 0) ;
}

QPainterPath BottomBat::shape() const
{
    QPainterPath p;
    return p;
}

void BottomBat::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
    painter->setBrush(Qt::black);     
    painter->drawLine(pingPong->bottomBatX, pingPong->BOTTOM_BAT_Y, pingPong->bottomBatX + pingPong->BAT_LENGTH, pingPong->BOTTOM_BAT_Y);
}
