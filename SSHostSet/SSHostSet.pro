#-------------------------------------------------
#
# Project created by QtCreator 2020-04-27T11:58:45
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TRANSLATIONS = TS/SET_ZH_US.ts

DESTDIR = ./SSApp/

#DEFINES += RUN_ON_ARM

TARGET = ssSet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    SystemSet/confdevice.cpp \
    SystemSet/confloop.cpp \
    SystemSet/confnetwork.cpp \
    SystemSet/confnode.cpp \
    SystemSet/confpwd.cpp \
    SystemSet/conftime.cpp \
    MsgBox/infobox.cpp \
    MsgBox/msgbox.cpp \
    MsgBox/questbox.cpp \
    SQLite/mysqlite.cpp \
    SystemSet/confaddr.cpp \
    CanDataMgm/candatamgm.cpp \
    CanDataMgm/canrecvthread.cpp \
    CanDataMgm/initcanport.cpp \
    UserLogin/userlogin.cpp \
    SystemSet/infodlg.cpp \
    MsgBox/recvfile.cpp

HEADERS  += mainwindow.h \
    SystemSet/confdevice.h \
    SystemSet/confloop.h \
    SystemSet/confnetwork.h \
    SystemSet/confnode.h \
    SystemSet/confpwd.h \
    SystemSet/conftime.h \
    MsgBox/infobox.h \
    MsgBox/msgbox.h \
    MsgBox/questbox.h \
    SQLite/mysqlite.h \
    SQLite/nodesqlite.h \
    SystemSet/confaddr.h \
    CanDataMgm/candatamgm.h \
    CanDataMgm/canrecvthread.h \
    CanDataMgm/initcanport.h \
    UserLogin/userlogin.h \
    SystemSet/infodlg.h \
    MsgBox/recvfile.h


FORMS    += mainwindow.ui \
    SystemSet/confdevice.ui \
    SystemSet/confloop.ui \
    SystemSet/confnetwork.ui \
    SystemSet/confnode.ui \
    SystemSet/confpwd.ui \
    SystemSet/conftime.ui \
    MsgBox/infobox.ui \
    MsgBox/questbox.ui \
    SystemSet/confaddr.ui \
    UserLogin/userlogin.ui \
    SystemSet/infodlg.ui \
    MsgBox/recvfile.ui

RESOURCES += \
    image.qrc \
    language.qrc
