#include "testgui.h"
//#include "pingpong.h"
#include "topbat.h"
#include "bottombat.h"
#include "ball.h"

TestGui::TestGui() {

}

//******************* TOP BAT POSITION RELATED TEST FUNCTIONS **************************

// top bat position related test
void TestGui::ballPositionXLessThanTopBatPositionX() {

    PingPong* pingPong = new PingPong(0);
    pingPong->topBat->startX = 100;
    pingPong->ball-> ballX = 10;
    pingPong->ball->ballY = pingPong->TOP_BAT_Y;

    pingPong->checkBatPosition(pingPong->ball-> ballX);
    qDebug() << "Human score:" << pingPong->player2Score;
    QCOMPARE( pingPong->player2Score, 1);
}

// top bat position related test
void TestGui::ballPositionXEqualToTopBatPositionX() {

    PingPong* pingPong = new PingPong(0);

    pingPong->topBat->startX = 100;
    pingPong->ball-> ballX = pingPong->topBat->startX;
    pingPong->ball-> ballX -=  pingPong->ball->BALL_WIDTH;

    pingPong->ball->ballY = pingPong->TOP_BAT_Y;

    pingPong->checkBatPosition(pingPong->ball-> ballX);
    qDebug() << "Human score:" << pingPong->player2Score;
    QCOMPARE( pingPong->player2Score, 0);
}

// top bat position related test
void TestGui::ballPositionXGreaterThanTopBatPositionX() {

    PingPong* pingPong = new PingPong(0);
    pingPong->topBat->startX = 100;
    pingPong->ball-> ballX = pingPong->topBat->startX + pingPong->BAT_LENGTH + 1;
    pingPong->ball->ballY = pingPong->TOP_BAT_Y;

    pingPong->checkBatPosition(pingPong->ball-> ballX);
    qDebug() << "Human score:" << pingPong->player2Score;
    QCOMPARE( pingPong->player2Score, 1);
}

//******************* BOTTOM BAT POSITION RELATED TEST FUNCTIONS **************************

// bottom bat position related test
void TestGui::ballPositionXLessThanBottomBatPositionX() {

    PingPong* pingPong = new PingPong(0);
    //if(ball->getBallY() + ball->getBallHeight() >= this->BOTTOM_BAT_Y) {
    pingPong->ball->ballY = pingPong->BOTTOM_BAT_Y - pingPong->ball->BALL_HEIGHT;
    qDebug() << "pingPong->ballY: " <<  pingPong->ballY;

    pingPong->bottomBatX = 100;
    pingPong->ball-> ballX = 10;

    pingPong->checkBatPosition(pingPong->ball-> ballX);
    qDebug() << "Computer score:" << pingPong->player1Score;
    QCOMPARE( pingPong->player1Score, 1);
}

// bottom bat position related test
void TestGui::ballPositionXEqualToBottomBatPositionX() {

    PingPong* pingPong = new PingPong(0);
    //if(ball->getBallY() + ball->getBallHeight() >= this->BOTTOM_BAT_Y) {
    pingPong->ball->ballY = pingPong->BOTTOM_BAT_Y - pingPong->ball->BALL_HEIGHT;
    qDebug() << "pingPong->ballY: " <<  pingPong->ballY;

    pingPong->bottomBatX = 100;
    pingPong->ball->ballX = pingPong->bottomBatX;


    pingPong->checkBatPosition(pingPong->ball-> ballX);
    qDebug() << "Computer score:" << pingPong->player1Score;
    QCOMPARE( pingPong->player1Score, 0);
}

// bottom bat position related test
void TestGui::ballPositionXGreaterThanBottompBatPositionX() {

    PingPong* pingPong = new PingPong(0);
    //if(ball->getBallY() + ball->getBallHeight() >= this->BOTTOM_BAT_Y) {
    pingPong->ball->ballY = pingPong->BOTTOM_BAT_Y - pingPong->ball->BALL_HEIGHT;
    qDebug() << "pingPong->ballY: " <<  pingPong->ballY;

    pingPong->bottomBatX = 100;
    pingPong->ball->ballX = pingPong->bottomBatX + pingPong->BAT_LENGTH + 1;

    pingPong->checkBatPosition(pingPong->ball-> ballX);
    qDebug() << "Computer score:" << pingPong->player1Score;
    QCOMPARE( pingPong->player1Score, 1);
}

//******************* BALL POSITION RELATED TEST FUNCTIONS **************************

void TestGui::ballYLessThanTopBatY() {

    PingPong* pingPong = new PingPong(0);
    pingPong->topBat->startX = 100;
    // keep ball in the legal X co-ordinate limit
    pingPong->ball->ballX = pingPong->topBat->startX;

    pingPong->ball->ballY = pingPong->TOP_BAT_Y - 1;

    pingPong->ball->bottomBoundary = true;
    // TEST DOES NOT CALL TIMER EVENT FUNCTION - ERROR?
    //QTest::mouseClick(pingPong->startGame, Qt::LeftButton, 0);
    pingPong->ball->timerEvent(new QTimerEvent(10));
    QCOMPARE(pingPong->ball->bottomBoundary, false);
}

void TestGui::ballYEqualToTopBatY() {

    PingPong* pingPong = new PingPong(0);
    pingPong->topBat->startX = 100;
    // keep ball in the legal X co-ordinate limit
    pingPong->ball->ballX = pingPong->topBat->startX;

    pingPong->ball->ballY = pingPong->TOP_BAT_Y;

    pingPong->ball->bottomBoundary = true;
    // TEST DOES NOT CALL TIMER EVENT FUNCTION -ERROR?
    //QTest::mouseClick(pingPong->startGame, Qt::LeftButton, 0);
    pingPong->ball->timerEvent(new QTimerEvent(10));
    QCOMPARE(pingPong->ball->bottomBoundary, false);
}

void TestGui::ballYGreaterThanTopBatY() {

    PingPong* pingPong = new PingPong(0);
    pingPong->topBat->startX = 100;
    // keep ball in the legal X co-ordinate limit
    pingPong->ball->ballX = pingPong->topBat->startX;

    pingPong->ball->ballY = pingPong->TOP_BAT_Y + 1;

    // boolean value for boundary should not change here
    pingPong->ball->bottomBoundary = false;
    // TEST DOES NOT CALL TIMER EVENT FUNCTION -ERROR?
    //QTest::mouseClick(pingPong->startGame, Qt::LeftButton, 0);
    pingPong->ball->timerEvent(new QTimerEvent(10));
    QCOMPARE(pingPong->ball->bottomBoundary, false);
}

void TestGui::ballYEqualToBottomBatY() {

    PingPong* pingPong = new PingPong(0);
    pingPong->topBat->startX = 100;
    // keep ball in the legal X co-ordinate limit
    pingPong->ball->ballX = pingPong->topBat->startX;

    pingPong->ball->ballY = pingPong->BOTTOM_BAT_Y;

    // boolean value for boundary should change here
    pingPong->ball->bottomBoundary = false;
    // TEST DOES NOT CALL TIMER EVENT FUNCTION -ERROR?
    //QTest::mouseClick(pingPong->startGame, Qt::LeftButton, 0);
    pingPong->ball->timerEvent(new QTimerEvent(10));
    QCOMPARE(pingPong->ball->bottomBoundary, true);
}

void TestGui::ballYGreaterThanBottomBatY() {
        PingPong* pingPong = new PingPong(0);
        pingPong->topBat->startX = 100;
        // keep ball in the legal X co-ordinate limit
        pingPong->ball->ballX = pingPong->topBat->startX;

        pingPong->ball->ballY = pingPong->BOTTOM_BAT_Y + 1;

        // boolean value for boundary should change here
        pingPong->ball->bottomBoundary = false;
        // TEST DOES NOT CALL TIMER EVENT FUNCTION -ERROR?
        //QTest::mouseClick(pingPong->startGame, Qt::LeftButton, 0);
        pingPong->ball->timerEvent(new QTimerEvent(10));
        QCOMPARE(pingPong->ball->bottomBoundary, true);
}

