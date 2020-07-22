/********************************************************************************
** Form generated from reading UI file 'nodevalue_pm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEVALUE_PM_H
#define UI_NODEVALUE_PM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodeValue_PM
{
public:
    QLabel *lb_2UbUnit;
    QLCDNumber *lcd_1Ua;
    QLabel *lb_1IaUnit;
    QLabel *lb_1Ib;
    QLabel *lb_2UcUnit;
    QLCDNumber *lcd_1Ib;
    QLabel *lb_1IcUnit;
    QLabel *lb_1UcUnit;
    QLabel *lb_2Uc;
    QLabel *lb_1Ic;
    QLabel *lbTypeValue;
    QLabel *lb_1IbUnit;
    QLCDNumber *lcd_1Ic;
    QLabel *lbStateValue;
    QLCDNumber *lcd_1Uc;
    QLabel *lb_1Ub;
    QLabel *lbState;
    QLabel *lb_1UaUnit;
    QLabel *lb_2Ua;
    QLCDNumber *lcd_2Ub;
    QLCDNumber *lcd_1Ia;
    QLabel *lb_2UaUnit;
    QLabel *lbType;
    QLCDNumber *lcd_2Uc;
    QLabel *lb_1Ua;
    QLCDNumber *lcd_1Ub;
    QLabel *lb_1Ia;
    QLabel *lb_1UbUnit;
    QLabel *lb_1Uc;
    QLabel *lb_2Ub;
    QLCDNumber *lcd_2Ua;
    QLabel *lb_result_1;
    QLabel *lb_result_2;
    QLabel *lb_result_3;
    QLabel *lb_result_4;
    QLabel *lb_result_5;
    QLabel *lb_result_6;
    QLabel *lb_result_7;
    QLabel *lb_result_8;
    QLabel *lb_result_9;
    QLabel *lbType_2;
    QLabel *lbAddr;

    void setupUi(QWidget *NodeValue_PM)
    {
        if (NodeValue_PM->objectName().isEmpty())
            NodeValue_PM->setObjectName(QStringLiteral("NodeValue_PM"));
        NodeValue_PM->resize(490, 490);
        NodeValue_PM->setStyleSheet(QString::fromUtf8("QWidget#NodeValue_PM{\n"
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
"font: 18pt \"\345\256\213\344\275\223\";\n"
"font: 18pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"color: rgb(255, 255, 255);\n"
"}\n"
"QLCDNumber{\n"
"font: 12pt \"\345\256\213\344\275\223\";\n"
"border:1px solid rgb(0, 122, 165);\n"
""
                        "color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
"}"));
        lb_2UbUnit = new QLabel(NodeValue_PM);
        lb_2UbUnit->setObjectName(QStringLiteral("lb_2UbUnit"));
        lb_2UbUnit->setGeometry(QRect(315, 235, 25, 30));
        lb_2UbUnit->setAlignment(Qt::AlignCenter);
        lcd_1Ua = new QLCDNumber(NodeValue_PM);
        lcd_1Ua->setObjectName(QStringLiteral("lcd_1Ua"));
        lcd_1Ua->setGeometry(QRect(200, 35, 110, 30));
        lcd_1Ua->setProperty("intValue", QVariant(220));
        lb_1IaUnit = new QLabel(NodeValue_PM);
        lb_1IaUnit->setObjectName(QStringLiteral("lb_1IaUnit"));
        lb_1IaUnit->setGeometry(QRect(315, 335, 25, 30));
        lb_1IaUnit->setAlignment(Qt::AlignCenter);
        lb_1Ib = new QLabel(NodeValue_PM);
        lb_1Ib->setObjectName(QStringLiteral("lb_1Ib"));
        lb_1Ib->setGeometry(QRect(110, 385, 85, 30));
        lb_2UcUnit = new QLabel(NodeValue_PM);
        lb_2UcUnit->setObjectName(QStringLiteral("lb_2UcUnit"));
        lb_2UcUnit->setGeometry(QRect(315, 285, 25, 30));
        lb_2UcUnit->setAlignment(Qt::AlignCenter);
        lcd_1Ib = new QLCDNumber(NodeValue_PM);
        lcd_1Ib->setObjectName(QStringLiteral("lcd_1Ib"));
        lcd_1Ib->setGeometry(QRect(200, 385, 110, 30));
        lcd_1Ib->setProperty("value", QVariant(12.8));
        lb_1IcUnit = new QLabel(NodeValue_PM);
        lb_1IcUnit->setObjectName(QStringLiteral("lb_1IcUnit"));
        lb_1IcUnit->setGeometry(QRect(315, 435, 25, 30));
        lb_1IcUnit->setAlignment(Qt::AlignCenter);
        lb_1UcUnit = new QLabel(NodeValue_PM);
        lb_1UcUnit->setObjectName(QStringLiteral("lb_1UcUnit"));
        lb_1UcUnit->setGeometry(QRect(315, 135, 25, 30));
        lb_1UcUnit->setAlignment(Qt::AlignCenter);
        lb_2Uc = new QLabel(NodeValue_PM);
        lb_2Uc->setObjectName(QStringLiteral("lb_2Uc"));
        lb_2Uc->setGeometry(QRect(110, 285, 85, 30));
        lb_1Ic = new QLabel(NodeValue_PM);
        lb_1Ic->setObjectName(QStringLiteral("lb_1Ic"));
        lb_1Ic->setGeometry(QRect(110, 435, 85, 30));
        lbTypeValue = new QLabel(NodeValue_PM);
        lbTypeValue->setObjectName(QStringLiteral("lbTypeValue"));
        lbTypeValue->setGeometry(QRect(10, 235, 80, 30));
        lbTypeValue->setAlignment(Qt::AlignCenter);
        lb_1IbUnit = new QLabel(NodeValue_PM);
        lb_1IbUnit->setObjectName(QStringLiteral("lb_1IbUnit"));
        lb_1IbUnit->setGeometry(QRect(315, 385, 25, 30));
        lb_1IbUnit->setAlignment(Qt::AlignCenter);
        lcd_1Ic = new QLCDNumber(NodeValue_PM);
        lcd_1Ic->setObjectName(QStringLiteral("lcd_1Ic"));
        lcd_1Ic->setGeometry(QRect(200, 435, 111, 30));
        lcd_1Ic->setProperty("value", QVariant(22.2));
        lbStateValue = new QLabel(NodeValue_PM);
        lbStateValue->setObjectName(QStringLiteral("lbStateValue"));
        lbStateValue->setGeometry(QRect(10, 385, 80, 30));
        lbStateValue->setAlignment(Qt::AlignCenter);
        lcd_1Uc = new QLCDNumber(NodeValue_PM);
        lcd_1Uc->setObjectName(QStringLiteral("lcd_1Uc"));
        lcd_1Uc->setGeometry(QRect(200, 135, 110, 30));
        lcd_1Uc->setProperty("intValue", QVariant(220));
        lb_1Ub = new QLabel(NodeValue_PM);
        lb_1Ub->setObjectName(QStringLiteral("lb_1Ub"));
        lb_1Ub->setGeometry(QRect(110, 85, 85, 30));
        lbState = new QLabel(NodeValue_PM);
        lbState->setObjectName(QStringLiteral("lbState"));
        lbState->setGeometry(QRect(10, 335, 80, 30));
        lbState->setAlignment(Qt::AlignCenter);
        lb_1UaUnit = new QLabel(NodeValue_PM);
        lb_1UaUnit->setObjectName(QStringLiteral("lb_1UaUnit"));
        lb_1UaUnit->setGeometry(QRect(315, 35, 25, 30));
        lb_1UaUnit->setAlignment(Qt::AlignCenter);
        lb_2Ua = new QLabel(NodeValue_PM);
        lb_2Ua->setObjectName(QStringLiteral("lb_2Ua"));
        lb_2Ua->setGeometry(QRect(110, 185, 85, 30));
        lcd_2Ub = new QLCDNumber(NodeValue_PM);
        lcd_2Ub->setObjectName(QStringLiteral("lcd_2Ub"));
        lcd_2Ub->setGeometry(QRect(200, 235, 110, 30));
        lcd_2Ub->setProperty("intValue", QVariant(220));
        lcd_1Ia = new QLCDNumber(NodeValue_PM);
        lcd_1Ia->setObjectName(QStringLiteral("lcd_1Ia"));
        lcd_1Ia->setGeometry(QRect(200, 335, 110, 30));
        lcd_1Ia->setProperty("value", QVariant(16.5));
        lb_2UaUnit = new QLabel(NodeValue_PM);
        lb_2UaUnit->setObjectName(QStringLiteral("lb_2UaUnit"));
        lb_2UaUnit->setGeometry(QRect(315, 185, 25, 30));
        lb_2UaUnit->setAlignment(Qt::AlignCenter);
        lbType = new QLabel(NodeValue_PM);
        lbType->setObjectName(QStringLiteral("lbType"));
        lbType->setGeometry(QRect(10, 185, 80, 30));
        lbType->setAlignment(Qt::AlignCenter);
        lcd_2Uc = new QLCDNumber(NodeValue_PM);
        lcd_2Uc->setObjectName(QStringLiteral("lcd_2Uc"));
        lcd_2Uc->setGeometry(QRect(200, 285, 110, 30));
        lcd_2Uc->setProperty("intValue", QVariant(220));
        lb_1Ua = new QLabel(NodeValue_PM);
        lb_1Ua->setObjectName(QStringLiteral("lb_1Ua"));
        lb_1Ua->setGeometry(QRect(110, 35, 85, 30));
        lcd_1Ub = new QLCDNumber(NodeValue_PM);
        lcd_1Ub->setObjectName(QStringLiteral("lcd_1Ub"));
        lcd_1Ub->setGeometry(QRect(200, 85, 110, 30));
        lcd_1Ub->setProperty("intValue", QVariant(220));
        lb_1Ia = new QLabel(NodeValue_PM);
        lb_1Ia->setObjectName(QStringLiteral("lb_1Ia"));
        lb_1Ia->setGeometry(QRect(110, 335, 85, 30));
        lb_1UbUnit = new QLabel(NodeValue_PM);
        lb_1UbUnit->setObjectName(QStringLiteral("lb_1UbUnit"));
        lb_1UbUnit->setGeometry(QRect(315, 85, 25, 30));
        lb_1UbUnit->setAlignment(Qt::AlignCenter);
        lb_1Uc = new QLabel(NodeValue_PM);
        lb_1Uc->setObjectName(QStringLiteral("lb_1Uc"));
        lb_1Uc->setGeometry(QRect(110, 135, 85, 30));
        lb_2Ub = new QLabel(NodeValue_PM);
        lb_2Ub->setObjectName(QStringLiteral("lb_2Ub"));
        lb_2Ub->setGeometry(QRect(110, 235, 85, 30));
        lcd_2Ua = new QLCDNumber(NodeValue_PM);
        lcd_2Ua->setObjectName(QStringLiteral("lcd_2Ua"));
        lcd_2Ua->setGeometry(QRect(200, 185, 110, 30));
        lcd_2Ua->setProperty("intValue", QVariant(220));
        lb_result_1 = new QLabel(NodeValue_PM);
        lb_result_1->setObjectName(QStringLiteral("lb_result_1"));
        lb_result_1->setGeometry(QRect(370, 35, 90, 30));
        lb_result_1->setAlignment(Qt::AlignCenter);
        lb_result_2 = new QLabel(NodeValue_PM);
        lb_result_2->setObjectName(QStringLiteral("lb_result_2"));
        lb_result_2->setGeometry(QRect(370, 85, 90, 30));
        lb_result_2->setAlignment(Qt::AlignCenter);
        lb_result_3 = new QLabel(NodeValue_PM);
        lb_result_3->setObjectName(QStringLiteral("lb_result_3"));
        lb_result_3->setGeometry(QRect(370, 135, 90, 30));
        lb_result_3->setAlignment(Qt::AlignCenter);
        lb_result_4 = new QLabel(NodeValue_PM);
        lb_result_4->setObjectName(QStringLiteral("lb_result_4"));
        lb_result_4->setGeometry(QRect(370, 185, 90, 30));
        lb_result_4->setAlignment(Qt::AlignCenter);
        lb_result_5 = new QLabel(NodeValue_PM);
        lb_result_5->setObjectName(QStringLiteral("lb_result_5"));
        lb_result_5->setGeometry(QRect(370, 235, 90, 30));
        lb_result_5->setAlignment(Qt::AlignCenter);
        lb_result_6 = new QLabel(NodeValue_PM);
        lb_result_6->setObjectName(QStringLiteral("lb_result_6"));
        lb_result_6->setGeometry(QRect(370, 285, 90, 30));
        lb_result_6->setAlignment(Qt::AlignCenter);
        lb_result_7 = new QLabel(NodeValue_PM);
        lb_result_7->setObjectName(QStringLiteral("lb_result_7"));
        lb_result_7->setGeometry(QRect(370, 335, 90, 30));
        lb_result_7->setAlignment(Qt::AlignCenter);
        lb_result_8 = new QLabel(NodeValue_PM);
        lb_result_8->setObjectName(QStringLiteral("lb_result_8"));
        lb_result_8->setGeometry(QRect(370, 385, 90, 30));
        lb_result_8->setAlignment(Qt::AlignCenter);
        lb_result_9 = new QLabel(NodeValue_PM);
        lb_result_9->setObjectName(QStringLiteral("lb_result_9"));
        lb_result_9->setGeometry(QRect(370, 435, 90, 30));
        lb_result_9->setAlignment(Qt::AlignCenter);
        lbType_2 = new QLabel(NodeValue_PM);
        lbType_2->setObjectName(QStringLiteral("lbType_2"));
        lbType_2->setGeometry(QRect(15, 35, 80, 30));
        lbType_2->setAlignment(Qt::AlignCenter);
        lbAddr = new QLabel(NodeValue_PM);
        lbAddr->setObjectName(QStringLiteral("lbAddr"));
        lbAddr->setGeometry(QRect(15, 85, 80, 30));
        lbAddr->setAlignment(Qt::AlignCenter);

        retranslateUi(NodeValue_PM);

        QMetaObject::connectSlotsByName(NodeValue_PM);
    } // setupUi

    void retranslateUi(QWidget *NodeValue_PM)
    {
        NodeValue_PM->setWindowTitle(QApplication::translate("NodeValue_PM", "Form", 0));
        lb_2UbUnit->setText(QApplication::translate("NodeValue_PM", "V", 0));
        lb_1IaUnit->setText(QApplication::translate("NodeValue_PM", "A", 0));
        lb_1Ib->setText(QApplication::translate("NodeValue_PM", "1-Ib:", 0));
        lb_2UcUnit->setText(QApplication::translate("NodeValue_PM", "V", 0));
        lb_1IcUnit->setText(QApplication::translate("NodeValue_PM", "A", 0));
        lb_1UcUnit->setText(QApplication::translate("NodeValue_PM", "V", 0));
        lb_2Uc->setText(QApplication::translate("NodeValue_PM", "2-Uc:", 0));
        lb_1Ic->setText(QApplication::translate("NodeValue_PM", "1-Ic:", 0));
        lbTypeValue->setText(QApplication::translate("NodeValue_PM", "2VA", 0));
        lb_1IbUnit->setText(QApplication::translate("NodeValue_PM", "A", 0));
        lbStateValue->setText(QApplication::translate("NodeValue_PM", "\346\255\243\345\270\270", 0));
        lb_1Ub->setText(QApplication::translate("NodeValue_PM", "1-Ub:", 0));
        lbState->setText(QApplication::translate("NodeValue_PM", "\347\212\266\346\200\201", 0));
        lb_1UaUnit->setText(QApplication::translate("NodeValue_PM", "V", 0));
        lb_2Ua->setText(QApplication::translate("NodeValue_PM", "2-Ua:", 0));
        lb_2UaUnit->setText(QApplication::translate("NodeValue_PM", "V", 0));
        lbType->setText(QApplication::translate("NodeValue_PM", "\345\236\213\345\217\267", 0));
        lb_1Ua->setText(QApplication::translate("NodeValue_PM", "1-Ua:", 0));
        lb_1Ia->setText(QApplication::translate("NodeValue_PM", "1-Ia:", 0));
        lb_1UbUnit->setText(QApplication::translate("NodeValue_PM", "V", 0));
        lb_1Uc->setText(QApplication::translate("NodeValue_PM", "1-Uc:", 0));
        lb_2Ub->setText(QApplication::translate("NodeValue_PM", "2-Ub:", 0));
        lb_result_1->setText(QApplication::translate("NodeValue_PM", "\344\270\215\345\220\210\346\240\274", 0));
        lb_result_2->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lb_result_3->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lb_result_4->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lb_result_5->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lb_result_6->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lb_result_7->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lb_result_8->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lb_result_9->setText(QApplication::translate("NodeValue_PM", "\345\276\205\346\265\213", 0));
        lbType_2->setText(QApplication::translate("NodeValue_PM", "\345\234\260\345\235\200", 0));
        lbAddr->setText(QApplication::translate("NodeValue_PM", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class NodeValue_PM: public Ui_NodeValue_PM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEVALUE_PM_H
