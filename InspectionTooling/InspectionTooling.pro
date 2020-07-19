#-------------------------------------------------
#
# Project created by QtCreator 2020-06-23T08:10:53
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ./APP/InspectionTooling

TEMPLATE = app

CONFIG += serialport

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        Modbus/modbus.cpp \
        Node_EF/node_ef.cpp \
        Node_PM/node_pm.cpp \
        NodeValue_PM/nodevalue_pm.cpp \
        NodeValue_EF/nodevalue_ef.cpp \
#        CanMgm/canmgm.cpp \
#        CanMgm/thread.cpp
        CanDataMgm/candatamgm.cpp \
        CanDataMgm/canrecvthread.cpp \
        CanDataMgm/initcanport.cpp

HEADERS += \
        includes.h \
        mainwindow.h \
        Node_EF/node_ef.h \
        Node_PM/node_pm.h \
        NodeValue_PM/nodevalue_pm.h \
        NodeValue_EF/nodevalue_ef.h \
        Modbus/modbus.h \
#        CanMgm/canmgm.h \
#        CanMgm/thread.h \
#        CanMgm/ThirdLib/ECanVci.h
        CanDataMgm/candatamgm.h \
        CanDataMgm/canrecvthread.h \
        CanDataMgm/initcanport.h

FORMS += \
        mainwindow.ui \
        Node_EF/node_ef.ui \
        Node_PM/node_pm.ui \
        NodeValue_PM/nodevalue_pm.ui \
        NodeValue_EF/nodevalue_ef.ui


