/********************************************************************************
** Form generated from reading UI file 'nodevalue_ef.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEVALUE_EF_H
#define UI_NODEVALUE_EF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodeValue_EF
{
public:
    QLCDNumber *lcd_Leak11;
    QLabel *lb_Pass02;
    QLabel *lbState;
    QLabel *lbStateValue;
    QLabel *lb_result09;
    QLabel *lb_LeakUnit05;
    QLCDNumber *lcd_Leak10;
    QLabel *lb_Pass07;
    QLabel *lb_Pass03;
    QLCDNumber *lcd_Leak05;
    QLabel *lb_Pass01;
    QLabel *lbAddr;
    QLabel *lb_LeakUnit01;
    QLabel *lb_LeakUnit07;
    QLCDNumber *lcd_Leak03;
    QLabel *lb_LeakUnit09;
    QLabel *lb_LeakUnit06;
    QLCDNumber *lcd_Leak02;
    QLabel *lb_result03;
    QLabel *lb_Pass09;
    QLabel *lbTypeValue;
    QLCDNumber *lcd_Leak06;
    QLabel *lb_result07;
    QLabel *lb_result04;
    QLabel *lb_Pass05;
    QLabel *lb_result01;
    QLabel *lb_result05;
    QLCDNumber *lcd_Leak04;
    QLCDNumber *lcd_Leak12;
    QLabel *lb_Pass04;
    QLabel *lb_result06;
    QLabel *lb_LeakUnit02;
    QLabel *lb_result08;
    QLabel *lb_result02;
    QLabel *lb_Pass06;
    QLabel *lb_Pass08;
    QLabel *lbType;
    QLabel *lbAddrValue;
    QLabel *lb_LeakUnit03;
    QLCDNumber *lcd_Leak01;
    QLabel *lb_LeakUnit04;
    QLabel *lb_LeakUnit08;
    QLabel *lb_Pass10;
    QLabel *lb_Pass12;
    QLabel *lb_Pass11;
    QLCDNumber *lcd_Alarm01;
    QLCDNumber *lcd_Leak09;
    QLCDNumber *lcd_Leak07;
    QLCDNumber *lcd_Leak08;
    QLabel *lb_Leak01;
    QLabel *lb_Alarm01;
    QLabel *lb_AlarmUnit01;
    QLabel *lb_Leak02;
    QLabel *lb_Leak03;
    QLabel *lb_Leak04;
    QLabel *lb_Leak08;
    QLabel *lb_Leak06;
    QLabel *lb_Leak05;
    QLabel *lb_Leak07;
    QLabel *lb_Leak11;
    QLabel *lb_Leak10;
    QLabel *lb_Leak12;
    QLabel *lb_Leak09;
    QLabel *lb_LeakUnit10;
    QLabel *lb_LeakUnit12;
    QLabel *lb_LeakUnit11;
    QLabel *lb_Alarm02;
    QLabel *lb_AlarmUnit02;
    QLCDNumber *lcd_Alarm02;
    QLCDNumber *lcd_Alarm04;
    QLabel *lb_Alarm04;
    QLabel *lb_AlarmUnit04;
    QLabel *lb_Alarm03;
    QLabel *lb_AlarmUnit03;
    QLCDNumber *lcd_Alarm03;
    QLCDNumber *lcd_Alarm07;
    QLabel *lb_AlarmUnit08;
    QLabel *lb_Alarm06;
    QLabel *lb_Alarm07;
    QLCDNumber *lcd_Alarm08;
    QLabel *lb_AlarmUnit06;
    QLabel *lb_AlarmUnit07;
    QLabel *lb_Alarm05;
    QLCDNumber *lcd_Alarm06;
    QLabel *lb_AlarmUnit05;
    QLabel *lb_Alarm08;
    QLCDNumber *lcd_Alarm05;
    QLCDNumber *lcd_Alarm09;
    QLabel *lb_AlarmUnit11;
    QLabel *lb_Alarm12;
    QLabel *lb_AlarmUnit12;
    QLCDNumber *lcd_Alarm10;
    QLCDNumber *lcd_Alarm12;
    QLabel *lb_Alarm10;
    QLabel *lb_Alarm09;
    QLabel *lb_Alarm11;
    QLCDNumber *lcd_Alarm11;
    QLabel *lb_AlarmUnit10;
    QLabel *lb_AlarmUnit09;
    QLabel *lb_result10;
    QLabel *lb_result11;
    QLabel *lb_result12;

    void setupUi(QWidget *NodeValue_EF)
    {
        if (NodeValue_EF->objectName().isEmpty())
            NodeValue_EF->setObjectName(QStringLiteral("NodeValue_EF"));
        NodeValue_EF->resize(490, 490);
        NodeValue_EF->setStyleSheet(QString::fromUtf8("QWidget#NodeValue_EF{\n"
"background-color: rgb(0, 85, 127);\n"
"}\n"
"QToolButton{\n"
"font: 20pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 101, 150);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 19pt \"\345\256\213\344\275\223\";\n"
"color: rgb(180, 180, 180);\n"
"border-color: rgb(180, 180, 180);\n"
"}\n"
"QGroupBox{\n"
"font: 20pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:8px;\n"
"margin-top:22px;\n"
"}\n"
"QGroupBox:title{\n"
"subcontrol-origin: margin;\n"
"top:10px;\n"
"left: 10px;\n"
"}\n"
"QLabel{\n"
"font:10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 122, 165);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QLCDNumber{\n"
"font: 10pt \"\345\256\213\344\275\223\";\n"
"border:1px solid rgb(0, 122, 165);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
"\n"
"}"));
        lcd_Leak11 = new QLCDNumber(NodeValue_EF);
        lcd_Leak11->setObjectName(QStringLiteral("lcd_Leak11"));
        lcd_Leak11->setGeometry(QRect(140, 415, 75, 25));
        lcd_Leak11->setProperty("value", QVariant(0));
        lcd_Leak11->setProperty("intValue", QVariant(0));
        lb_Pass02 = new QLabel(NodeValue_EF);
        lb_Pass02->setObjectName(QStringLiteral("lb_Pass02"));
        lb_Pass02->setGeometry(QRect(15, 100, 70, 25));
        lbState = new QLabel(NodeValue_EF);
        lbState->setObjectName(QStringLiteral("lbState"));
        lbState->setGeometry(QRect(330, 35, 60, 25));
        lbState->setAlignment(Qt::AlignCenter);
        lbStateValue = new QLabel(NodeValue_EF);
        lbStateValue->setObjectName(QStringLiteral("lbStateValue"));
        lbStateValue->setGeometry(QRect(390, 35, 60, 25));
        lbStateValue->setAlignment(Qt::AlignCenter);
        lb_result09 = new QLabel(NodeValue_EF);
        lb_result09->setObjectName(QStringLiteral("lb_result09"));
        lb_result09->setGeometry(QRect(420, 345, 60, 25));
        lb_result09->setAlignment(Qt::AlignCenter);
        lb_LeakUnit05 = new QLabel(NodeValue_EF);
        lb_LeakUnit05->setObjectName(QStringLiteral("lb_LeakUnit05"));
        lb_LeakUnit05->setGeometry(QRect(220, 205, 25, 25));
        lb_LeakUnit05->setAlignment(Qt::AlignCenter);
        lcd_Leak10 = new QLCDNumber(NodeValue_EF);
        lcd_Leak10->setObjectName(QStringLiteral("lcd_Leak10"));
        lcd_Leak10->setGeometry(QRect(140, 380, 75, 25));
        lcd_Leak10->setProperty("value", QVariant(0));
        lcd_Leak10->setProperty("intValue", QVariant(0));
        lb_Pass07 = new QLabel(NodeValue_EF);
        lb_Pass07->setObjectName(QStringLiteral("lb_Pass07"));
        lb_Pass07->setGeometry(QRect(15, 275, 70, 25));
        lb_Pass03 = new QLabel(NodeValue_EF);
        lb_Pass03->setObjectName(QStringLiteral("lb_Pass03"));
        lb_Pass03->setGeometry(QRect(15, 135, 70, 25));
        lcd_Leak05 = new QLCDNumber(NodeValue_EF);
        lcd_Leak05->setObjectName(QStringLiteral("lcd_Leak05"));
        lcd_Leak05->setGeometry(QRect(140, 205, 75, 25));
        lcd_Leak05->setProperty("intValue", QVariant(0));
        lb_Pass01 = new QLabel(NodeValue_EF);
        lb_Pass01->setObjectName(QStringLiteral("lb_Pass01"));
        lb_Pass01->setGeometry(QRect(15, 65, 70, 25));
        lbAddr = new QLabel(NodeValue_EF);
        lbAddr->setObjectName(QStringLiteral("lbAddr"));
        lbAddr->setGeometry(QRect(30, 35, 60, 25));
        lbAddr->setAlignment(Qt::AlignCenter);
        lb_LeakUnit01 = new QLabel(NodeValue_EF);
        lb_LeakUnit01->setObjectName(QStringLiteral("lb_LeakUnit01"));
        lb_LeakUnit01->setGeometry(QRect(220, 65, 25, 25));
        lb_LeakUnit01->setAlignment(Qt::AlignCenter);
        lb_LeakUnit07 = new QLabel(NodeValue_EF);
        lb_LeakUnit07->setObjectName(QStringLiteral("lb_LeakUnit07"));
        lb_LeakUnit07->setGeometry(QRect(220, 275, 25, 25));
        lb_LeakUnit07->setAlignment(Qt::AlignCenter);
        lcd_Leak03 = new QLCDNumber(NodeValue_EF);
        lcd_Leak03->setObjectName(QStringLiteral("lcd_Leak03"));
        lcd_Leak03->setGeometry(QRect(140, 135, 75, 25));
        lcd_Leak03->setProperty("intValue", QVariant(0));
        lb_LeakUnit09 = new QLabel(NodeValue_EF);
        lb_LeakUnit09->setObjectName(QStringLiteral("lb_LeakUnit09"));
        lb_LeakUnit09->setGeometry(QRect(220, 345, 25, 25));
        lb_LeakUnit09->setAlignment(Qt::AlignCenter);
        lb_LeakUnit06 = new QLabel(NodeValue_EF);
        lb_LeakUnit06->setObjectName(QStringLiteral("lb_LeakUnit06"));
        lb_LeakUnit06->setGeometry(QRect(220, 240, 25, 25));
        lb_LeakUnit06->setAlignment(Qt::AlignCenter);
        lcd_Leak02 = new QLCDNumber(NodeValue_EF);
        lcd_Leak02->setObjectName(QStringLiteral("lcd_Leak02"));
        lcd_Leak02->setGeometry(QRect(140, 100, 75, 25));
        lcd_Leak02->setProperty("intValue", QVariant(0));
        lb_result03 = new QLabel(NodeValue_EF);
        lb_result03->setObjectName(QStringLiteral("lb_result03"));
        lb_result03->setGeometry(QRect(420, 135, 60, 25));
        lb_result03->setAlignment(Qt::AlignCenter);
        lb_Pass09 = new QLabel(NodeValue_EF);
        lb_Pass09->setObjectName(QStringLiteral("lb_Pass09"));
        lb_Pass09->setGeometry(QRect(15, 345, 70, 25));
        lbTypeValue = new QLabel(NodeValue_EF);
        lbTypeValue->setObjectName(QStringLiteral("lbTypeValue"));
        lbTypeValue->setGeometry(QRect(240, 35, 60, 25));
        lbTypeValue->setAlignment(Qt::AlignCenter);
        lcd_Leak06 = new QLCDNumber(NodeValue_EF);
        lcd_Leak06->setObjectName(QStringLiteral("lcd_Leak06"));
        lcd_Leak06->setGeometry(QRect(140, 240, 75, 25));
        lcd_Leak06->setProperty("intValue", QVariant(0));
        lb_result07 = new QLabel(NodeValue_EF);
        lb_result07->setObjectName(QStringLiteral("lb_result07"));
        lb_result07->setGeometry(QRect(420, 275, 60, 25));
        lb_result07->setAlignment(Qt::AlignCenter);
        lb_result04 = new QLabel(NodeValue_EF);
        lb_result04->setObjectName(QStringLiteral("lb_result04"));
        lb_result04->setGeometry(QRect(420, 170, 60, 25));
        lb_result04->setAlignment(Qt::AlignCenter);
        lb_Pass05 = new QLabel(NodeValue_EF);
        lb_Pass05->setObjectName(QStringLiteral("lb_Pass05"));
        lb_Pass05->setGeometry(QRect(15, 205, 70, 25));
        lb_result01 = new QLabel(NodeValue_EF);
        lb_result01->setObjectName(QStringLiteral("lb_result01"));
        lb_result01->setGeometry(QRect(420, 65, 60, 25));
        lb_result01->setStyleSheet(QStringLiteral(""));
        lb_result01->setAlignment(Qt::AlignCenter);
        lb_result05 = new QLabel(NodeValue_EF);
        lb_result05->setObjectName(QStringLiteral("lb_result05"));
        lb_result05->setGeometry(QRect(420, 205, 60, 25));
        lb_result05->setAlignment(Qt::AlignCenter);
        lcd_Leak04 = new QLCDNumber(NodeValue_EF);
        lcd_Leak04->setObjectName(QStringLiteral("lcd_Leak04"));
        lcd_Leak04->setGeometry(QRect(140, 170, 75, 25));
        lcd_Leak04->setProperty("intValue", QVariant(0));
        lcd_Leak12 = new QLCDNumber(NodeValue_EF);
        lcd_Leak12->setObjectName(QStringLiteral("lcd_Leak12"));
        lcd_Leak12->setGeometry(QRect(140, 450, 75, 25));
        lcd_Leak12->setProperty("value", QVariant(0));
        lcd_Leak12->setProperty("intValue", QVariant(0));
        lb_Pass04 = new QLabel(NodeValue_EF);
        lb_Pass04->setObjectName(QStringLiteral("lb_Pass04"));
        lb_Pass04->setGeometry(QRect(15, 170, 70, 25));
        lb_result06 = new QLabel(NodeValue_EF);
        lb_result06->setObjectName(QStringLiteral("lb_result06"));
        lb_result06->setGeometry(QRect(420, 240, 60, 25));
        lb_result06->setAlignment(Qt::AlignCenter);
        lb_LeakUnit02 = new QLabel(NodeValue_EF);
        lb_LeakUnit02->setObjectName(QStringLiteral("lb_LeakUnit02"));
        lb_LeakUnit02->setGeometry(QRect(220, 100, 25, 25));
        lb_LeakUnit02->setAlignment(Qt::AlignCenter);
        lb_result08 = new QLabel(NodeValue_EF);
        lb_result08->setObjectName(QStringLiteral("lb_result08"));
        lb_result08->setGeometry(QRect(420, 310, 60, 25));
        lb_result08->setAlignment(Qt::AlignCenter);
        lb_result02 = new QLabel(NodeValue_EF);
        lb_result02->setObjectName(QStringLiteral("lb_result02"));
        lb_result02->setGeometry(QRect(420, 100, 60, 25));
        lb_result02->setAlignment(Qt::AlignCenter);
        lb_Pass06 = new QLabel(NodeValue_EF);
        lb_Pass06->setObjectName(QStringLiteral("lb_Pass06"));
        lb_Pass06->setGeometry(QRect(15, 240, 70, 25));
        lb_Pass08 = new QLabel(NodeValue_EF);
        lb_Pass08->setObjectName(QStringLiteral("lb_Pass08"));
        lb_Pass08->setGeometry(QRect(15, 310, 70, 25));
        lbType = new QLabel(NodeValue_EF);
        lbType->setObjectName(QStringLiteral("lbType"));
        lbType->setGeometry(QRect(180, 35, 60, 25));
        lbType->setAlignment(Qt::AlignCenter);
        lbAddrValue = new QLabel(NodeValue_EF);
        lbAddrValue->setObjectName(QStringLiteral("lbAddrValue"));
        lbAddrValue->setGeometry(QRect(90, 35, 60, 25));
        lbAddrValue->setAlignment(Qt::AlignCenter);
        lb_LeakUnit03 = new QLabel(NodeValue_EF);
        lb_LeakUnit03->setObjectName(QStringLiteral("lb_LeakUnit03"));
        lb_LeakUnit03->setGeometry(QRect(220, 135, 25, 25));
        lb_LeakUnit03->setAlignment(Qt::AlignCenter);
        lcd_Leak01 = new QLCDNumber(NodeValue_EF);
        lcd_Leak01->setObjectName(QStringLiteral("lcd_Leak01"));
        lcd_Leak01->setGeometry(QRect(140, 65, 75, 25));
        lcd_Leak01->setProperty("intValue", QVariant(0));
        lb_LeakUnit04 = new QLabel(NodeValue_EF);
        lb_LeakUnit04->setObjectName(QStringLiteral("lb_LeakUnit04"));
        lb_LeakUnit04->setGeometry(QRect(220, 170, 25, 25));
        lb_LeakUnit04->setAlignment(Qt::AlignCenter);
        lb_LeakUnit08 = new QLabel(NodeValue_EF);
        lb_LeakUnit08->setObjectName(QStringLiteral("lb_LeakUnit08"));
        lb_LeakUnit08->setGeometry(QRect(220, 310, 25, 25));
        lb_LeakUnit08->setAlignment(Qt::AlignCenter);
        lb_Pass10 = new QLabel(NodeValue_EF);
        lb_Pass10->setObjectName(QStringLiteral("lb_Pass10"));
        lb_Pass10->setGeometry(QRect(15, 380, 70, 25));
        lb_Pass12 = new QLabel(NodeValue_EF);
        lb_Pass12->setObjectName(QStringLiteral("lb_Pass12"));
        lb_Pass12->setGeometry(QRect(15, 450, 70, 25));
        lb_Pass11 = new QLabel(NodeValue_EF);
        lb_Pass11->setObjectName(QStringLiteral("lb_Pass11"));
        lb_Pass11->setGeometry(QRect(15, 415, 70, 25));
        lcd_Alarm01 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm01->setObjectName(QStringLiteral("lcd_Alarm01"));
        lcd_Alarm01->setGeometry(QRect(310, 65, 75, 25));
        lcd_Alarm01->setProperty("intValue", QVariant(0));
        lcd_Leak09 = new QLCDNumber(NodeValue_EF);
        lcd_Leak09->setObjectName(QStringLiteral("lcd_Leak09"));
        lcd_Leak09->setGeometry(QRect(140, 345, 75, 25));
        lcd_Leak09->setProperty("value", QVariant(0));
        lcd_Leak09->setProperty("intValue", QVariant(0));
        lcd_Leak07 = new QLCDNumber(NodeValue_EF);
        lcd_Leak07->setObjectName(QStringLiteral("lcd_Leak07"));
        lcd_Leak07->setGeometry(QRect(140, 275, 75, 25));
        lcd_Leak07->setProperty("value", QVariant(0));
        lcd_Leak07->setProperty("intValue", QVariant(0));
        lcd_Leak08 = new QLCDNumber(NodeValue_EF);
        lcd_Leak08->setObjectName(QStringLiteral("lcd_Leak08"));
        lcd_Leak08->setGeometry(QRect(140, 310, 75, 25));
        lcd_Leak08->setProperty("value", QVariant(0));
        lcd_Leak08->setProperty("intValue", QVariant(0));
        lb_Leak01 = new QLabel(NodeValue_EF);
        lb_Leak01->setObjectName(QStringLiteral("lb_Leak01"));
        lb_Leak01->setGeometry(QRect(90, 65, 50, 25));
        lb_Leak01->setAlignment(Qt::AlignCenter);
        lb_Alarm01 = new QLabel(NodeValue_EF);
        lb_Alarm01->setObjectName(QStringLiteral("lb_Alarm01"));
        lb_Alarm01->setGeometry(QRect(255, 65, 50, 25));
        lb_Alarm01->setAlignment(Qt::AlignCenter);
        lb_AlarmUnit01 = new QLabel(NodeValue_EF);
        lb_AlarmUnit01->setObjectName(QStringLiteral("lb_AlarmUnit01"));
        lb_AlarmUnit01->setGeometry(QRect(385, 65, 25, 25));
        lb_AlarmUnit01->setAlignment(Qt::AlignCenter);
        lb_Leak02 = new QLabel(NodeValue_EF);
        lb_Leak02->setObjectName(QStringLiteral("lb_Leak02"));
        lb_Leak02->setGeometry(QRect(90, 100, 50, 25));
        lb_Leak02->setAlignment(Qt::AlignCenter);
        lb_Leak03 = new QLabel(NodeValue_EF);
        lb_Leak03->setObjectName(QStringLiteral("lb_Leak03"));
        lb_Leak03->setGeometry(QRect(90, 135, 50, 25));
        lb_Leak03->setAlignment(Qt::AlignCenter);
        lb_Leak04 = new QLabel(NodeValue_EF);
        lb_Leak04->setObjectName(QStringLiteral("lb_Leak04"));
        lb_Leak04->setGeometry(QRect(90, 170, 50, 25));
        lb_Leak04->setAlignment(Qt::AlignCenter);
        lb_Leak08 = new QLabel(NodeValue_EF);
        lb_Leak08->setObjectName(QStringLiteral("lb_Leak08"));
        lb_Leak08->setGeometry(QRect(90, 310, 50, 25));
        lb_Leak08->setAlignment(Qt::AlignCenter);
        lb_Leak06 = new QLabel(NodeValue_EF);
        lb_Leak06->setObjectName(QStringLiteral("lb_Leak06"));
        lb_Leak06->setGeometry(QRect(90, 240, 50, 25));
        lb_Leak06->setAlignment(Qt::AlignCenter);
        lb_Leak05 = new QLabel(NodeValue_EF);
        lb_Leak05->setObjectName(QStringLiteral("lb_Leak05"));
        lb_Leak05->setGeometry(QRect(90, 205, 50, 25));
        lb_Leak05->setAlignment(Qt::AlignCenter);
        lb_Leak07 = new QLabel(NodeValue_EF);
        lb_Leak07->setObjectName(QStringLiteral("lb_Leak07"));
        lb_Leak07->setGeometry(QRect(90, 275, 50, 25));
        lb_Leak07->setAlignment(Qt::AlignCenter);
        lb_Leak11 = new QLabel(NodeValue_EF);
        lb_Leak11->setObjectName(QStringLiteral("lb_Leak11"));
        lb_Leak11->setGeometry(QRect(90, 415, 50, 25));
        lb_Leak11->setAlignment(Qt::AlignCenter);
        lb_Leak10 = new QLabel(NodeValue_EF);
        lb_Leak10->setObjectName(QStringLiteral("lb_Leak10"));
        lb_Leak10->setGeometry(QRect(90, 380, 50, 25));
        lb_Leak10->setAlignment(Qt::AlignCenter);
        lb_Leak12 = new QLabel(NodeValue_EF);
        lb_Leak12->setObjectName(QStringLiteral("lb_Leak12"));
        lb_Leak12->setGeometry(QRect(90, 450, 50, 25));
        lb_Leak12->setAlignment(Qt::AlignCenter);
        lb_Leak09 = new QLabel(NodeValue_EF);
        lb_Leak09->setObjectName(QStringLiteral("lb_Leak09"));
        lb_Leak09->setGeometry(QRect(90, 345, 50, 25));
        lb_Leak09->setAlignment(Qt::AlignCenter);
        lb_LeakUnit10 = new QLabel(NodeValue_EF);
        lb_LeakUnit10->setObjectName(QStringLiteral("lb_LeakUnit10"));
        lb_LeakUnit10->setGeometry(QRect(220, 380, 25, 25));
        lb_LeakUnit10->setAlignment(Qt::AlignCenter);
        lb_LeakUnit12 = new QLabel(NodeValue_EF);
        lb_LeakUnit12->setObjectName(QStringLiteral("lb_LeakUnit12"));
        lb_LeakUnit12->setGeometry(QRect(220, 450, 25, 25));
        lb_LeakUnit12->setAlignment(Qt::AlignCenter);
        lb_LeakUnit11 = new QLabel(NodeValue_EF);
        lb_LeakUnit11->setObjectName(QStringLiteral("lb_LeakUnit11"));
        lb_LeakUnit11->setGeometry(QRect(220, 415, 25, 25));
        lb_LeakUnit11->setAlignment(Qt::AlignCenter);
        lb_Alarm02 = new QLabel(NodeValue_EF);
        lb_Alarm02->setObjectName(QStringLiteral("lb_Alarm02"));
        lb_Alarm02->setGeometry(QRect(255, 100, 50, 25));
        lb_Alarm02->setAlignment(Qt::AlignCenter);
        lb_AlarmUnit02 = new QLabel(NodeValue_EF);
        lb_AlarmUnit02->setObjectName(QStringLiteral("lb_AlarmUnit02"));
        lb_AlarmUnit02->setGeometry(QRect(385, 100, 25, 25));
        lb_AlarmUnit02->setAlignment(Qt::AlignCenter);
        lcd_Alarm02 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm02->setObjectName(QStringLiteral("lcd_Alarm02"));
        lcd_Alarm02->setGeometry(QRect(310, 100, 75, 25));
        lcd_Alarm02->setProperty("intValue", QVariant(0));
        lcd_Alarm04 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm04->setObjectName(QStringLiteral("lcd_Alarm04"));
        lcd_Alarm04->setGeometry(QRect(310, 170, 75, 25));
        lcd_Alarm04->setProperty("intValue", QVariant(0));
        lb_Alarm04 = new QLabel(NodeValue_EF);
        lb_Alarm04->setObjectName(QStringLiteral("lb_Alarm04"));
        lb_Alarm04->setGeometry(QRect(255, 170, 50, 25));
        lb_Alarm04->setAlignment(Qt::AlignCenter);
        lb_AlarmUnit04 = new QLabel(NodeValue_EF);
        lb_AlarmUnit04->setObjectName(QStringLiteral("lb_AlarmUnit04"));
        lb_AlarmUnit04->setGeometry(QRect(385, 170, 25, 25));
        lb_AlarmUnit04->setAlignment(Qt::AlignCenter);
        lb_Alarm03 = new QLabel(NodeValue_EF);
        lb_Alarm03->setObjectName(QStringLiteral("lb_Alarm03"));
        lb_Alarm03->setGeometry(QRect(255, 135, 50, 25));
        lb_Alarm03->setAlignment(Qt::AlignCenter);
        lb_AlarmUnit03 = new QLabel(NodeValue_EF);
        lb_AlarmUnit03->setObjectName(QStringLiteral("lb_AlarmUnit03"));
        lb_AlarmUnit03->setGeometry(QRect(385, 135, 25, 25));
        lb_AlarmUnit03->setAlignment(Qt::AlignCenter);
        lcd_Alarm03 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm03->setObjectName(QStringLiteral("lcd_Alarm03"));
        lcd_Alarm03->setGeometry(QRect(310, 135, 75, 25));
        lcd_Alarm03->setProperty("intValue", QVariant(0));
        lcd_Alarm07 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm07->setObjectName(QStringLiteral("lcd_Alarm07"));
        lcd_Alarm07->setGeometry(QRect(310, 275, 75, 25));
        lcd_Alarm07->setProperty("intValue", QVariant(0));
        lb_AlarmUnit08 = new QLabel(NodeValue_EF);
        lb_AlarmUnit08->setObjectName(QStringLiteral("lb_AlarmUnit08"));
        lb_AlarmUnit08->setGeometry(QRect(385, 310, 25, 25));
        lb_AlarmUnit08->setAlignment(Qt::AlignCenter);
        lb_Alarm06 = new QLabel(NodeValue_EF);
        lb_Alarm06->setObjectName(QStringLiteral("lb_Alarm06"));
        lb_Alarm06->setGeometry(QRect(255, 240, 50, 25));
        lb_Alarm06->setAlignment(Qt::AlignCenter);
        lb_Alarm07 = new QLabel(NodeValue_EF);
        lb_Alarm07->setObjectName(QStringLiteral("lb_Alarm07"));
        lb_Alarm07->setGeometry(QRect(255, 275, 50, 25));
        lb_Alarm07->setAlignment(Qt::AlignCenter);
        lcd_Alarm08 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm08->setObjectName(QStringLiteral("lcd_Alarm08"));
        lcd_Alarm08->setGeometry(QRect(310, 310, 75, 25));
        lcd_Alarm08->setProperty("intValue", QVariant(0));
        lb_AlarmUnit06 = new QLabel(NodeValue_EF);
        lb_AlarmUnit06->setObjectName(QStringLiteral("lb_AlarmUnit06"));
        lb_AlarmUnit06->setGeometry(QRect(385, 240, 25, 25));
        lb_AlarmUnit06->setAlignment(Qt::AlignCenter);
        lb_AlarmUnit07 = new QLabel(NodeValue_EF);
        lb_AlarmUnit07->setObjectName(QStringLiteral("lb_AlarmUnit07"));
        lb_AlarmUnit07->setGeometry(QRect(385, 275, 25, 25));
        lb_AlarmUnit07->setAlignment(Qt::AlignCenter);
        lb_Alarm05 = new QLabel(NodeValue_EF);
        lb_Alarm05->setObjectName(QStringLiteral("lb_Alarm05"));
        lb_Alarm05->setGeometry(QRect(255, 205, 50, 25));
        lb_Alarm05->setAlignment(Qt::AlignCenter);
        lcd_Alarm06 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm06->setObjectName(QStringLiteral("lcd_Alarm06"));
        lcd_Alarm06->setGeometry(QRect(310, 240, 75, 25));
        lcd_Alarm06->setProperty("intValue", QVariant(0));
        lb_AlarmUnit05 = new QLabel(NodeValue_EF);
        lb_AlarmUnit05->setObjectName(QStringLiteral("lb_AlarmUnit05"));
        lb_AlarmUnit05->setGeometry(QRect(385, 205, 25, 25));
        lb_AlarmUnit05->setAlignment(Qt::AlignCenter);
        lb_Alarm08 = new QLabel(NodeValue_EF);
        lb_Alarm08->setObjectName(QStringLiteral("lb_Alarm08"));
        lb_Alarm08->setGeometry(QRect(255, 310, 50, 25));
        lb_Alarm08->setAlignment(Qt::AlignCenter);
        lcd_Alarm05 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm05->setObjectName(QStringLiteral("lcd_Alarm05"));
        lcd_Alarm05->setGeometry(QRect(310, 205, 75, 25));
        lcd_Alarm05->setProperty("intValue", QVariant(0));
        lcd_Alarm09 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm09->setObjectName(QStringLiteral("lcd_Alarm09"));
        lcd_Alarm09->setGeometry(QRect(310, 345, 75, 25));
        lcd_Alarm09->setProperty("intValue", QVariant(0));
        lb_AlarmUnit11 = new QLabel(NodeValue_EF);
        lb_AlarmUnit11->setObjectName(QStringLiteral("lb_AlarmUnit11"));
        lb_AlarmUnit11->setGeometry(QRect(385, 415, 25, 25));
        lb_AlarmUnit11->setAlignment(Qt::AlignCenter);
        lb_Alarm12 = new QLabel(NodeValue_EF);
        lb_Alarm12->setObjectName(QStringLiteral("lb_Alarm12"));
        lb_Alarm12->setGeometry(QRect(255, 450, 50, 25));
        lb_Alarm12->setAlignment(Qt::AlignCenter);
        lb_AlarmUnit12 = new QLabel(NodeValue_EF);
        lb_AlarmUnit12->setObjectName(QStringLiteral("lb_AlarmUnit12"));
        lb_AlarmUnit12->setGeometry(QRect(385, 450, 25, 25));
        lb_AlarmUnit12->setAlignment(Qt::AlignCenter);
        lcd_Alarm10 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm10->setObjectName(QStringLiteral("lcd_Alarm10"));
        lcd_Alarm10->setGeometry(QRect(310, 380, 75, 25));
        lcd_Alarm10->setProperty("intValue", QVariant(0));
        lcd_Alarm12 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm12->setObjectName(QStringLiteral("lcd_Alarm12"));
        lcd_Alarm12->setGeometry(QRect(310, 450, 75, 25));
        lcd_Alarm12->setProperty("intValue", QVariant(0));
        lb_Alarm10 = new QLabel(NodeValue_EF);
        lb_Alarm10->setObjectName(QStringLiteral("lb_Alarm10"));
        lb_Alarm10->setGeometry(QRect(255, 380, 50, 25));
        lb_Alarm10->setAlignment(Qt::AlignCenter);
        lb_Alarm09 = new QLabel(NodeValue_EF);
        lb_Alarm09->setObjectName(QStringLiteral("lb_Alarm09"));
        lb_Alarm09->setGeometry(QRect(255, 345, 50, 25));
        lb_Alarm09->setAlignment(Qt::AlignCenter);
        lb_Alarm11 = new QLabel(NodeValue_EF);
        lb_Alarm11->setObjectName(QStringLiteral("lb_Alarm11"));
        lb_Alarm11->setGeometry(QRect(255, 415, 50, 25));
        lb_Alarm11->setAlignment(Qt::AlignCenter);
        lcd_Alarm11 = new QLCDNumber(NodeValue_EF);
        lcd_Alarm11->setObjectName(QStringLiteral("lcd_Alarm11"));
        lcd_Alarm11->setGeometry(QRect(310, 415, 75, 25));
        lcd_Alarm11->setProperty("intValue", QVariant(0));
        lb_AlarmUnit10 = new QLabel(NodeValue_EF);
        lb_AlarmUnit10->setObjectName(QStringLiteral("lb_AlarmUnit10"));
        lb_AlarmUnit10->setGeometry(QRect(385, 380, 25, 25));
        lb_AlarmUnit10->setAlignment(Qt::AlignCenter);
        lb_AlarmUnit09 = new QLabel(NodeValue_EF);
        lb_AlarmUnit09->setObjectName(QStringLiteral("lb_AlarmUnit09"));
        lb_AlarmUnit09->setGeometry(QRect(385, 345, 25, 25));
        lb_AlarmUnit09->setAlignment(Qt::AlignCenter);
        lb_result10 = new QLabel(NodeValue_EF);
        lb_result10->setObjectName(QStringLiteral("lb_result10"));
        lb_result10->setGeometry(QRect(420, 380, 60, 25));
        lb_result10->setAlignment(Qt::AlignCenter);
        lb_result11 = new QLabel(NodeValue_EF);
        lb_result11->setObjectName(QStringLiteral("lb_result11"));
        lb_result11->setGeometry(QRect(420, 415, 60, 25));
        lb_result11->setAlignment(Qt::AlignCenter);
        lb_result12 = new QLabel(NodeValue_EF);
        lb_result12->setObjectName(QStringLiteral("lb_result12"));
        lb_result12->setGeometry(QRect(420, 450, 60, 25));
        lb_result12->setAlignment(Qt::AlignCenter);

        retranslateUi(NodeValue_EF);

        QMetaObject::connectSlotsByName(NodeValue_EF);
    } // setupUi

    void retranslateUi(QWidget *NodeValue_EF)
    {
        NodeValue_EF->setWindowTitle(QApplication::translate("NodeValue_EF", "Form", 0));
        lb_Pass02->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-02", 0));
        lbState->setText(QApplication::translate("NodeValue_EF", "\347\212\266\346\200\201:", 0));
        lbStateValue->setText(QApplication::translate("NodeValue_EF", "\346\255\243\345\270\270", 0));
        lb_result09->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_LeakUnit05->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Pass07->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-07", 0));
        lb_Pass03->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-03", 0));
        lb_Pass01->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-01", 0));
        lbAddr->setText(QApplication::translate("NodeValue_EF", "\345\234\260\345\235\200:", 0));
        lb_LeakUnit01->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_LeakUnit07->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_LeakUnit09->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_LeakUnit06->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_result03->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_Pass09->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-09", 0));
        lbTypeValue->setText(QApplication::translate("NodeValue_EF", "2VA", 0));
        lb_result07->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_result04->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_Pass05->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-05", 0));
        lb_result01->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_result05->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_Pass04->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-04", 0));
        lb_result06->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_LeakUnit02->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_result08->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_result02->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_Pass06->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-06", 0));
        lb_Pass08->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-08", 0));
        lbType->setText(QApplication::translate("NodeValue_EF", "\345\236\213\345\217\267:", 0));
        lbAddrValue->setText(QApplication::translate("NodeValue_EF", "1", 0));
        lb_LeakUnit03->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_LeakUnit04->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_LeakUnit08->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Pass10->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-10", 0));
        lb_Pass12->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-12", 0));
        lb_Pass11->setText(QApplication::translate("NodeValue_EF", "\351\200\232\351\201\223-11", 0));
        lb_Leak01->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Alarm01->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit01->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Leak02->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak03->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak04->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak08->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak06->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak05->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak07->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak11->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak10->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak12->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_Leak09->setText(QApplication::translate("NodeValue_EF", "\346\274\217\347\224\265:", 0));
        lb_LeakUnit10->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_LeakUnit12->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_LeakUnit11->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm02->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit02->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm04->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit04->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm03->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit03->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_AlarmUnit08->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm06->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_Alarm07->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit06->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_AlarmUnit07->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm05->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit05->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm08->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit11->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm12->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit12->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_Alarm10->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_Alarm09->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_Alarm11->setText(QApplication::translate("NodeValue_EF", "\346\212\245\350\255\246:", 0));
        lb_AlarmUnit10->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_AlarmUnit09->setText(QApplication::translate("NodeValue_EF", "mA", 0));
        lb_result10->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_result11->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
        lb_result12->setText(QApplication::translate("NodeValue_EF", "\345\276\205\346\265\213", 0));
    } // retranslateUi

};

namespace Ui {
    class NodeValue_EF: public Ui_NodeValue_EF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEVALUE_EF_H
