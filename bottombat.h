#ifndef BOTTOMBAT_H
#define BOTTOMBAT_H

#include <QObject>
#include <QGraphicsItem>
#include "pingpong.h"


class BottomBat : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    BottomBat(PingPong* pingPong);
    // QGraphicsItem related functions
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget *widget);

public slots:

private:
    PingPong* pingPong;     
    // variable to check if bat has reached right boundary
    bool rightMarginBoundary;
};

#endif // BOTTOMBAT_H
