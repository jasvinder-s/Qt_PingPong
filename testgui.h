#ifndef TESTGUI_H
#define TESTGUI_H

#include <QtGui>
#include <QtTest/QtTest>
#include "pingpong.h"
 class TestGui: public QObject
 {
     Q_OBJECT
 public:
     TestGui();     
 private slots:

     //******************* TOP BAT POSITION RELATED TEST FUNCTIONS **************************
     void ballPositionXLessThanTopBatPositionX();
     void ballPositionXEqualToTopBatPositionX();
     void ballPositionXGreaterThanTopBatPositionX();

     //******************* BOTTOM BAT POSITION RELATED TEST FUNCTIONS **************************
     void ballPositionXLessThanBottomBatPositionX();
     void ballPositionXEqualToBottomBatPositionX();
     void ballPositionXGreaterThanBottompBatPositionX();

     //******************* BALL POSITION RELATED TEST FUNCTIONS **************************

     // check Y co-ordinate of ball
     void ballYLessThanTopBatY();
     void ballYEqualToTopBatY();
     void ballYGreaterThanTopBatY();
     void ballYEqualToBottomBatY();
     void ballYGreaterThanBottomBatY();     

 private:
    PingPong* pingPong;
 };


#endif // TESTGUI_H
