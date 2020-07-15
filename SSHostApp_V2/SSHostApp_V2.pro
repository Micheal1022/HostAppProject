#-------------------------------------------------
#
# Project created by QtCreator 2019-01-12T10:18:06
#
#-------------------------------------------------



DEFINES += BEVONE
#DEFINES += SENSOR

DEFINES += RUN_ON_ARM

QT += core gui sql network
#QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TRANSLATIONS = TS/APP_ZH_US.ts

DESTDIR = ./SSAPP/BEVONE
#DESTDIR = ./SSAPP/SENSOR

TARGET = ssApp
TEMPLATE = app

CONFIG += serialport

SOURCES += main.cpp\
        mainwindow.cpp \
    Monitor/monitor.cpp \
    UserLogin/userlogin.cpp \
    Record/record.cpp \
    Record/datafilter.cpp \
    Monitor/nodeview.cpp \
    CanDataMgm/candatamgm.cpp \
    CanDataMgm/initcanport.cpp \
    CanDataMgm/canrecvthread.cpp \
    SQLite/mysqlite.cpp \
    Monitor/stateinfo.cpp \
    Monitor/dbthead.cpp \
    Record/myprint.cpp \
    Screen/screen.cpp \
    GPIOControl/gpiocontrol.cpp \
    MsgBox/infobox.cpp \
    MsgBox/msgbox.cpp \
    MsgBox/questbox.cpp \
    UDPServer/udpserver.cpp \
    RS485/rs485.cpp \
    RS485/slavemachine.cpp \
    Monitor/nodestate.cpp

HEADERS  += mainwindow.h \
    Monitor/monitor.h \
    UserLogin/userlogin.h \
    Record/record.h \
    Record/datafilter.h \
    Monitor/nodeview.h \
    CanDataMgm/candatamgm.h \
    CanDataMgm/initcanport.h \
    CanDataMgm/canrecvthread.h \
    SQLite/mysqlite.h \
    Monitor/stateinfo.h \
    Monitor/dbthead.h \
    Record/myprint.h \
    Screen/screen.h \
    GPIOControl/gpiocontrol.h \
    MsgBox/infobox.h \
    MsgBox/msgbox.h \
    MsgBox/questbox.h \
    UDPServer/udpserver.h \
    RS485/rs485.h \
    RS485/slavemachine.h \
    Monitor/nodestate.h \
    includes.h

FORMS    += mainwindow.ui \
    Monitor/monitor.ui \
    UserLogin/userlogin.ui \
    Record/record.ui \
    Record/datafilter.ui \
    Monitor/nodeview.ui \
    Monitor/stateinfo.ui \
    Screen/screen.ui \
    MsgBox/infobox.ui \
    MsgBox/questbox.ui \
    Monitor/nodestate.ui

RESOURCES += \
    image.qrc \
    language.qrc \
    qss.qrc
