#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include "pingpong.h"

class GameScene : public QGraphicsScene
{
public:
    GameScene();
    GameScene(QGraphicsScene* parent = 0);
    GameScene(PingPong* pingPong);

    // ensure that bat is not drawn outside valid limits
    void updateBatX(qreal newX);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    PingPong* pingPong;
};

#endif // GAMESCENE_H
