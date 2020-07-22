/********************************************************************************
** Form generated from reading UI file 'node_pm.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODE_PM_H
#define UI_NODE_PM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Node_PM
{
public:
    QGroupBox *gBox_2;
    QGroupBox *gBox_1;
    QGroupBox *gBoxType;
    QToolButton *tBtnSet;
    QToolButton *tBtn_2VA;
    QToolButton *tBtn_1V;
    QToolButton *tBtn_1VA;
    QToolButton *tBtn_2V;
    QToolButton *tBtn_3V;
    QGroupBox *groupBox_4;
    QToolButton *tBtnReset;
    QToolButton *tBtnClear;
    QToolButton *tBtnBack;
    QToolButton *tBtnCheck;

    void setupUi(QWidget *Node_PM)
    {
        if (Node_PM->objectName().isEmpty())
            Node_PM->setObjectName(QStringLiteral("Node_PM"));
        Node_PM->resize(1020, 560);
        Node_PM->setStyleSheet(QString::fromUtf8("QWidget#Node_PM{\n"
"background-color: rgb(255, 255, 255);\n"
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
"font: 15pt \"\345\256\213\344\275\223\";\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid rgb(255, 255, 255);\n"
"border-radius:8px;\n"
"margin-top:20px;\n"
"}\n"
"QGroupBox:title{\n"
"subcontrol-origin: margin;\n"
"top:10px;\n"
"left: 10px;\n"
"}\n"
"QLabel{\n"
"font: 20pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 122, 165);\n"
"}\n"
""));
        gBox_2 = new QGroupBox(Node_PM);
        gBox_2->setObjectName(QStringLiteral("gBox_2"));
        gBox_2->setGeometry(QRect(515, -10, 500, 480));
        gBox_2->setAlignment(Qt::AlignCenter);
        gBox_1 = new QGroupBox(Node_PM);
        gBox_1->setObjectName(QStringLiteral("gBox_1"));
        gBox_1->setGeometry(QRect(5, -10, 500, 480));
        gBox_1->setAlignment(Qt::AlignCenter);
        gBoxType = new QGroupBox(Node_PM);
        gBoxType->setObjectName(QStringLiteral("gBoxType"));
        gBoxType->setGeometry(QRect(5, 460, 500, 100));
        tBtnSet = new QToolButton(gBoxType);
        tBtnSet->setObjectName(QStringLiteral("tBtnSet"));
        tBtnSet->setGeometry(QRect(385, 40, 90, 50));
        tBtn_2VA = new QToolButton(gBoxType);
        tBtn_2VA->setObjectName(QStringLiteral("tBtn_2VA"));
        tBtn_2VA->setGeometry(QRect(30, 45, 80, 40));
        tBtn_1V = new QToolButton(gBoxType);
        tBtn_1V->setObjectName(QStringLiteral("tBtn_1V"));
        tBtn_1V->setGeometry(QRect(265, 40, 90, 50));
        tBtn_1VA = new QToolButton(gBoxType);
        tBtn_1VA->setObjectName(QStringLiteral("tBtn_1VA"));
        tBtn_1VA->setGeometry(QRect(150, 45, 80, 40));
        tBtn_2V = new QToolButton(gBoxType);
        tBtn_2V->setObjectName(QStringLiteral("tBtn_2V"));
        tBtn_2V->setGeometry(QRect(145, 40, 90, 50));
        tBtn_3V = new QToolButton(gBoxType);
        tBtn_3V->setObjectName(QStringLiteral("tBtn_3V"));
        tBtn_3V->setGeometry(QRect(25, 40, 90, 50));
        groupBox_4 = new QGroupBox(Node_PM);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(515, 460, 500, 100));
        tBtnReset = new QToolButton(groupBox_4);
        tBtnReset->setObjectName(QStringLiteral("tBtnReset"));
        tBtnReset->setGeometry(QRect(210, 40, 90, 50));
        tBtnClear = new QToolButton(groupBox_4);
        tBtnClear->setObjectName(QStringLiteral("tBtnClear"));
        tBtnClear->setGeometry(QRect(30, 140, 80, 60));
        tBtnBack = new QToolButton(groupBox_4);
        tBtnBack->setObjectName(QStringLiteral("tBtnBack"));
        tBtnBack->setGeometry(QRect(385, 40, 90, 50));
        tBtnCheck = new QToolButton(groupBox_4);
        tBtnCheck->setObjectName(QStringLiteral("tBtnCheck"));
        tBtnCheck->setGeometry(QRect(40, 40, 90, 50));

        retranslateUi(Node_PM);

        QMetaObject::connectSlotsByName(Node_PM);
    } // setupUi

    void retranslateUi(QWidget *Node_PM)
    {
        Node_PM->setWindowTitle(QApplication::translate("Node_PM", "Form", 0));
        gBox_2->setTitle(QApplication::translate("Node_PM", "\345\267\245\344\275\215-2", 0));
        gBox_1->setTitle(QApplication::translate("Node_PM", "\345\267\245\344\275\215-1", 0));
        gBoxType->setTitle(QApplication::translate("Node_PM", "\344\277\256\346\224\271\345\236\213\345\217\267", 0));
        tBtnSet->setText(QApplication::translate("Node_PM", "\350\256\276\345\256\232", 0));
        tBtn_2VA->setText(QApplication::translate("Node_PM", "2VA", 0));
        tBtn_1V->setText(QApplication::translate("Node_PM", "V", 0));
        tBtn_1VA->setText(QApplication::translate("Node_PM", "VA", 0));
        tBtn_2V->setText(QApplication::translate("Node_PM", "2V", 0));
        tBtn_3V->setText(QApplication::translate("Node_PM", "3V", 0));
        groupBox_4->setTitle(QApplication::translate("Node_PM", "\345\212\237\350\203\275\346\223\215\344\275\234", 0));
        tBtnReset->setText(QApplication::translate("Node_PM", "\345\244\215\344\275\215", 0));
        tBtnClear->setText(QApplication::translate("Node_PM", "\346\270\205\347\251\272", 0));
        tBtnBack->setText(QApplication::translate("Node_PM", "\350\277\224\345\233\236", 0));
        tBtnCheck->setText(QApplication::translate("Node_PM", "\346\240\241\345\207\206", 0));
    } // retranslateUi

};

namespace Ui {
    class Node_PM: public Ui_Node_PM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODE_PM_H
