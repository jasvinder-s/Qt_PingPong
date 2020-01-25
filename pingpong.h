#ifndef PINGPONG_H
#define PINGPONG_H

#include <QWidget>
#include "ui_pingpong.h"

class TopBat;
class Ball;
class GameScene;
class BottomBat;
class QPushButton;

namespace Ui {
    class PingPong;
}

class PingPong : public QWidget, public Ui::PingPong
{
    Q_OBJECT

public:
    PingPong(QWidget *parent = 0);
    ~PingPong();

    friend class TopBat;
    friend class BottomBat;
    friend class Ball;
    friend class GameScene;
    friend class TestGui;

    // check bat position relative to ball
    void checkBatPosition(qreal ballPosition);
protected:     

public slots:
    void beginGame();
    // pause game when a player with playerID wins
    void pauseGame(int playerID);
    // increment player score and display as LCDNumber
    void updateScore(int PlayerWhoWin);    

signals:
    void pause(int playerID);
    void updatePlayerScore(int PlayerWhoWin);

private:

    GameScene* scene;    
    int SCENE_WIDTH;
    int SCENE_HEIGHT;

    // Maximum x coordinate till which either top or bottom bat can be dragged.
    qreal BAT_MAX_X;
    qreal BAT_LENGTH;

    // top bat co-ordinates
    qreal topBatX;
    TopBat* topBat;
    qreal TOP_BAT_Y;

    // ball co-ordinates
    qreal ballX;
    qreal ballY;
    Ball* ball;

    // lower bat co-ordinates
    qreal bottomBatX;
    qreal BOTTOM_BAT_Y;
    BottomBat* bottomBat;

    //QPushButton* startGame;
    int PLAYER_ID_COMPUTER;
    int PLAYER_ID_HUMAN;
    int playerID;

    int player1Score;
    int player2Score;

    /* sets how quickly scene should be update and top bat and ball should
       should be re-drawn */
    int timeout;
    // determines in what increments bat should move in horiz. direction
    qreal topBatMovementFactor;
    // determines in what increments ball should move in vertical direction
    qreal ballMovementFactorY;
};

#endif // PINGPONG_H
