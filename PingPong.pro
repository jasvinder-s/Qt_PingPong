#-------------------------------------------------
#
# Project created by QtCreator 2010-05-13T21:44:59
#
#-------------------------------------------------

QT       += core gui

TARGET = PingPong
TEMPLATE = app


SOURCES += main.cpp\
        pingpong.cpp \
    gamescene.cpp \
    topbat.cpp \
    ball.cpp \
    bottombat.cpp \
    testgui.cpp

HEADERS  += pingpong.h \
    gamescene.h \
    topbat.h \
    ball.h \
    bottombat.h \
    testgui.h


FORMS    += pingpong.ui

CONFIG += mobility \
        += qtestlib\
    += console \

MOBILITY = 

symbian {
    TARGET.UID3 = 0xe8a9b521
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
