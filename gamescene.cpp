#include "gamescene.h"
#include <QDebug>
//#include "pingpong.h"

GameScene::GameScene()
{

}

GameScene::GameScene(PingPong* pingPong)
{
    this->pingPong = pingPong;     
}


GameScene::GameScene(QGraphicsScene* parent)
    :QGraphicsScene(parent)
{

} 

void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{    
    QPointF lastPosition = mouseEvent->scenePos();
    qreal x = lastPosition.rx();
    this->updateBatX(x);
    qDebug() << "x:" << lastPosition.rx(); 
}

void GameScene::updateBatX(qreal newX)
{    
    // bat should be drawn only till the maximum scene width
    if(newX > pingPong->BAT_MAX_X)
        newX = pingPong->BAT_MAX_X;
    else if(newX < 0)
        newX = 0;
    pingPong->bottomBatX = newX;
    this->update();
}
