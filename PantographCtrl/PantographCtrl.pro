#-------------------------------------------------
#
# Project created by QtCreator 2020-09-02T11:49:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PantographCtrl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SystemConf/systemconf.cpp \
    UserLogin/userlogin.cpp \
    MsgBox/infobox.cpp \
    MsgBox/msgbox.cpp \
    MsgBox/questbox.cpp \
    SQLite/mysqlite.cpp

HEADERS  += mainwindow.h \
    SystemConf/systemconf.h \
    UserLogin/userlogin.h \
    MsgBox/infobox.h \
    MsgBox/msgbox.h \
    MsgBox/questbox.h \
    SQLite/mysqlite.h \
    SQLite/nodesqlite.h \
    includes.h

FORMS    += mainwindow.ui \
    SystemConf/systemconf.ui \
    UserLogin/userlogin.ui \
    MsgBox/infobox.ui \
    MsgBox/questbox.ui

RESOURCES += \
    image.qrc
