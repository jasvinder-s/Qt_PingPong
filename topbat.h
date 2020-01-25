#ifndef TOPBAT_H
#define TOPBAT_H

#include <QObject>
#include <QGraphicsItem>
#include "pingpong.h"

class TopBat : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    TopBat(PingPong* pingPong);
     // QGraphicsItem related function
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget);
    // return bat's x co-ordinate
    qreal getBatX();
    void startMovement(int timeout);
    void setBatMovementFactorX(qreal factor);
    void stopMovement();
    friend class TestGui;
    protected:
     void timerEvent(QTimerEvent *event);


signals:

public slots:

private:
     PingPong* pingPong;
     // bat's X co-ordinate
     qreal startX;
     qreal batMovement;
     bool rightMarginBoundary;
     int timerID;
};

#endif // TOPBAT_H
