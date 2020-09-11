#-------------------------------------------------
#
# Project created by QtCreator 2020-09-02T11:49:55
#
#-------------------------------------------------

QT       += core gui sql serialport

DEFINES += RUN_ON_ARM


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = ./APP/
TARGET = app
TEMPLATE = app

CONFIG += serialport

SOURCES += main.cpp\
        mainwindow.cpp \
    SystemConf/systemconf.cpp \
    UserLogin/userlogin.cpp \
    MsgBox/infobox.cpp \
    MsgBox/msgbox.cpp \
    MsgBox/questbox.cpp \
    UartCom/uartcom.cpp

HEADERS  += mainwindow.h \
    SystemConf/systemconf.h \
    UserLogin/userlogin.h \
    MsgBox/infobox.h \
    MsgBox/msgbox.h \
    MsgBox/questbox.h \
    includes.h \
    UartCom/uartcom.h

FORMS    += mainwindow.ui \
    SystemConf/systemconf.ui \
    UserLogin/userlogin.ui \
    MsgBox/infobox.ui \
    MsgBox/questbox.ui

RESOURCES += \
    image.qrc
