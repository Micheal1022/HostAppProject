/********************************************************************************
** Form generated from reading UI file 'node_ef.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODE_EF_H
#define UI_NODE_EF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Node_EF
{
public:
    QGroupBox *groupBox_4;
    QToolButton *tBtnReset;
    QToolButton *tBtnClear;
    QToolButton *tBtnBack;
    QToolButton *tBtnCheck;
    QGroupBox *gBox_2;
    QGroupBox *gBoxType;
    QToolButton *tBtnSet;
    QToolButton *tBtn_T4;
    QToolButton *tBtn_L8T4;
    QToolButton *tBtn_L12;
    QGroupBox *gBox_1;

    void setupUi(QWidget *Node_EF)
    {
        if (Node_EF->objectName().isEmpty())
            Node_EF->setObjectName(QStringLiteral("Node_EF"));
        Node_EF->resize(1020, 560);
        Node_EF->setStyleSheet(QString::fromUtf8("QWidget#Node_EF{\n"
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
        groupBox_4 = new QGroupBox(Node_EF);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(515, 455, 500, 100));
        tBtnReset = new QToolButton(groupBox_4);
        tBtnReset->setObjectName(QStringLiteral("tBtnReset"));
        tBtnReset->setGeometry(QRect(215, 40, 90, 50));
        tBtnClear = new QToolButton(groupBox_4);
        tBtnClear->setObjectName(QStringLiteral("tBtnClear"));
        tBtnClear->setGeometry(QRect(25, 40, 90, 50));
        tBtnBack = new QToolButton(groupBox_4);
        tBtnBack->setObjectName(QStringLiteral("tBtnBack"));
        tBtnBack->setGeometry(QRect(385, 40, 90, 50));
        tBtnCheck = new QToolButton(groupBox_4);
        tBtnCheck->setObjectName(QStringLiteral("tBtnCheck"));
        tBtnCheck->setGeometry(QRect(25, 40, 90, 50));
        gBox_2 = new QGroupBox(Node_EF);
        gBox_2->setObjectName(QStringLiteral("gBox_2"));
        gBox_2->setGeometry(QRect(515, -10, 500, 480));
        gBox_2->setAlignment(Qt::AlignCenter);
        gBoxType = new QGroupBox(Node_EF);
        gBoxType->setObjectName(QStringLiteral("gBoxType"));
        gBoxType->setGeometry(QRect(5, 455, 500, 100));
        tBtnSet = new QToolButton(gBoxType);
        tBtnSet->setObjectName(QStringLiteral("tBtnSet"));
        tBtnSet->setGeometry(QRect(385, 40, 90, 50));
        tBtn_T4 = new QToolButton(gBoxType);
        tBtn_T4->setObjectName(QStringLiteral("tBtn_T4"));
        tBtn_T4->setGeometry(QRect(265, 40, 90, 50));
        tBtn_L8T4 = new QToolButton(gBoxType);
        tBtn_L8T4->setObjectName(QStringLiteral("tBtn_L8T4"));
        tBtn_L8T4->setGeometry(QRect(145, 40, 90, 50));
        tBtn_L12 = new QToolButton(gBoxType);
        tBtn_L12->setObjectName(QStringLiteral("tBtn_L12"));
        tBtn_L12->setGeometry(QRect(25, 40, 90, 50));
        gBox_1 = new QGroupBox(Node_EF);
        gBox_1->setObjectName(QStringLiteral("gBox_1"));
        gBox_1->setGeometry(QRect(5, -10, 500, 480));
        gBox_1->setAlignment(Qt::AlignCenter);

        retranslateUi(Node_EF);

        QMetaObject::connectSlotsByName(Node_EF);
    } // setupUi

    void retranslateUi(QWidget *Node_EF)
    {
        Node_EF->setWindowTitle(QApplication::translate("Node_EF", "Form", 0));
        groupBox_4->setTitle(QApplication::translate("Node_EF", "\345\212\237\350\203\275\346\223\215\344\275\234", 0));
        tBtnReset->setText(QApplication::translate("Node_EF", "\345\244\215\344\275\215", 0));
        tBtnClear->setText(QApplication::translate("Node_EF", "\346\270\205\347\251\272", 0));
        tBtnBack->setText(QApplication::translate("Node_EF", "\350\277\224\345\233\236", 0));
        tBtnCheck->setText(QApplication::translate("Node_EF", "\346\240\241\345\207\206", 0));
        gBox_2->setTitle(QApplication::translate("Node_EF", "\345\267\245\344\275\215-2", 0));
        gBoxType->setTitle(QApplication::translate("Node_EF", "\344\277\256\346\224\271\345\236\213\345\217\267", 0));
        tBtnSet->setText(QApplication::translate("Node_EF", "\350\256\276\345\256\232", 0));
        tBtn_T4->setText(QApplication::translate("Node_EF", "T4", 0));
        tBtn_L8T4->setText(QApplication::translate("Node_EF", "L8T4", 0));
        tBtn_L12->setText(QApplication::translate("Node_EF", " L12", 0));
        gBox_1->setTitle(QApplication::translate("Node_EF", "\345\267\245\344\275\215-1", 0));
    } // retranslateUi

};

namespace Ui {
    class Node_EF: public Ui_Node_EF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODE_EF_H
