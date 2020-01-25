#include "pingpong.h"
#include "ui_pingpong.h"
#include <QDebug>

#include "topbat.h"
#include "ball.h"
#include "bottombat.h"
#include "gamescene.h"
#include <QPushButton>

PingPong::PingPong(QWidget *parent) :
        QWidget(parent)
{
    setupUi(this);

    int width = this->graphicsView->width();
    int height = this->graphicsView->height();

    SCENE_HEIGHT = this->graphicsView->height();
    SCENE_WIDTH = this->graphicsView->width();
    // scene appears out of the visible view on the actual device.
    int SCENE_OFFSET = 20;
    SCENE_WIDTH = SCENE_WIDTH - SCENE_OFFSET;
    SCENE_HEIGHT = SCENE_HEIGHT - SCENE_OFFSET;

    qDebug() << width << "" << height;
    qDebug() << SCENE_WIDTH << SCENE_HEIGHT;

    scene = new GameScene(this);
    scene->setSceneRect(QRectF(0, 0, SCENE_WIDTH,SCENE_HEIGHT));
    graphicsView->setScene(scene);

    BAT_LENGTH = 100;
    // max. x co-ordinate till which bat can be dragged
    BAT_MAX_X = SCENE_WIDTH - BAT_LENGTH;

    // offset so that bat appears in middle initially.
    qreal X_OFFSET = 50;
    topBatX = SCENE_WIDTH/2 - X_OFFSET;

    TOP_BAT_Y = 20;
    topBat = new TopBat(this);
    scene->addItem(topBat);

    ball = new Ball(this);
    scene->addItem(ball);

    BOTTOM_BAT_Y = SCENE_HEIGHT - 20;
    bottomBat = new BottomBat(this);
    bottomBatX = SCENE_WIDTH/2 - X_OFFSET;
    scene->addItem(bottomBat);

    playerID = -1;
    PLAYER_ID_COMPUTER = 1;
    PLAYER_ID_HUMAN = 2;

    player1Score = 0;
    player2Score = 0;

    timeout = 10;
    topBatMovementFactor = 1;
    ballMovementFactorY = 1;

    QObject::connect(startGame, SIGNAL(clicked()), this, SLOT(beginGame()));

    QObject::connect(this, SIGNAL(pause(int)), this, SLOT(pauseGame(int)));

    QObject::connect(this, SIGNAL(updatePlayerScore(int)), this, SLOT(updateScore(int)));

    qDebug("***********************exiting constructor*****************");
}

PingPong::~PingPong()
{
    delete topBat;
    delete ball;
    delete bottomBat;
}

void PingPong::beginGame()
{
    qDebug("PingPong::beginGame()");
    ball->startMovement(timeout);
    topBat->startMovement(timeout);
}

void PingPong::pauseGame(int playerID)
{
    ball->stopMovement();
    topBat->stopMovement();
    if(playerID == PLAYER_ID_COMPUTER)
    {
        qDebug() << "Computer won";
        emit updatePlayerScore(PLAYER_ID_COMPUTER);
    }
    else
    {
        // whenever player wons the complexity of game i.e speed of ball and computer bat
        //should increase.
        topBat->setBatMovementFactorX(++topBatMovementFactor);
        // ball should be moving only till the specified limit, otherwise game is impossible to play
        if(ballMovementFactorY <= 9)
              ball->setBallMovementFactorY(++ballMovementFactorY);
        qDebug() << "Human won";
        qDebug() << "PingPong::pauseGame timeout: " << timeout;
        emit updatePlayerScore(PLAYER_ID_HUMAN);
    }
}

void PingPong::checkBatPosition(qreal ballPositionX)
{ 
    //qDebug() << "PingPong::checkBatPosition  ballPositionX: " << ballPositionX;
    qDebug() << "this->BOTTOM_BAT_Y: " << this->BOTTOM_BAT_Y;
    qDebug() << "PingPong::checkBatPosition  ballPositionY" << ball->getBallY();
    qDebug() << "ball->getBallY() + ball->getBallHeight(): " << ball->getBallY() + ball->getBallHeight();


    //qDebug() << "bottomBatX" << bottomBatX;
    //qDebug() << "bottomBatX + BAT_LENGTH" << bottomBatX + BAT_LENGTH;
    //qDebug() << "PingPong::checkBatPosition  topBatX + BAT_LENGTH" << topBat->getBatX() + BAT_LENGTH;

    // check top bat
    if(ball->getBallY() <= this->TOP_BAT_Y)
    {
        qDebug("Checking top bat position");
        if(ballPositionX+ ball->getBallWidth() >= topBat->getBatX() && ballPositionX <= topBat->getBatX() + BAT_LENGTH) {
            qDebug("Top bat position ok");
        } else {
            qDebug("Top bat position not ok");
            emit pause(PLAYER_ID_HUMAN);
        }
    // check bottom bat
    } else if(ball->getBallY() + ball->getBallHeight() >= this->BOTTOM_BAT_Y) {
        qDebug("Checking bottom bat position");
        if(ballPositionX + ball->getBallWidth() >= bottomBatX && ballPositionX <= bottomBatX + BAT_LENGTH) {
            //qDebug("Bottom bat position ok");
        } else {
            //qDebug("Bottom bat position not ok");
            emit pause(PLAYER_ID_COMPUTER);
        }

    }
}

void PingPong::updateScore(int PlayerWhoWin) {

    if(PlayerWhoWin == PLAYER_ID_COMPUTER) {
        player1Score++;
        this->computerScore->display((int)player1Score);
    }
    else{
        player2Score++;
        playerScore->display((int)player2Score);
    }
}
