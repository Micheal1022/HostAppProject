/********************************************************************************
** Form generated from reading UI file 'stateinfo.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEINFO_H
#define UI_STATEINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_StateInfo
{
public:
    QLabel *lbTimeValue;
    QLabel *label_3;
    QLabel *lbNodeAddr;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *lbAlarm;
    QLabel *label;
    QToolButton *tBtnNestStrip;
    QLabel *label_5;
    QLabel *lbTime;
    QToolButton *tBtnBack;
    QLabel *lbType;
    QLabel *lbTitle;
    QLabel *lbCount;
    QLabel *lbArea;
    QLabel *lbAlarmValue;
    QToolButton *tBtnLastStrip;
    QLabel *lbState;
    QLabel *label_11;
    QLabel *lbUnit;

    void setupUi(QDialog *StateInfo)
    {
        if (StateInfo->objectName().isEmpty())
            StateInfo->setObjectName(QString::fromUtf8("StateInfo"));
        StateInfo->resize(534, 350);
        StateInfo->setStyleSheet(QString::fromUtf8("QDialog{\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:0px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 18pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{\n"
"font: 12pt \"DejaVu Sans\";\n"
"color: rgb(0, 122, 165);\n"
"}\n"
"QLabel#lbArea{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"}"));
        lbTimeValue = new QLabel(StateInfo);
        lbTimeValue->setObjectName(QString::fromUtf8("lbTimeValue"));
        lbTimeValue->setGeometry(QRect(120, 145, 371, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lbTimeValue->setFont(font);
        lbTimeValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"}"));
        label_3 = new QLabel(StateInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(505, 5, 25, 30));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbNodeAddr = new QLabel(StateInfo);
        lbNodeAddr->setObjectName(QString::fromUtf8("lbNodeAddr"));
        lbNodeAddr->setGeometry(QRect(120, 45, 120, 40));
        lbNodeAddr->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"}"));
        lbNodeAddr->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(StateInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 45, 105, 40));
        label_7 = new QLabel(StateInfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 195, 91, 40));
        lbAlarm = new QLabel(StateInfo);
        lbAlarm->setObjectName(QString::fromUtf8("lbAlarm"));
        lbAlarm->setGeometry(QRect(270, 95, 105, 40));
        label = new QLabel(StateInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 5, 56, 30));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tBtnNestStrip = new QToolButton(StateInfo);
        tBtnNestStrip->setObjectName(QString::fromUtf8("tBtnNestStrip"));
        tBtnNestStrip->setEnabled(true);
        tBtnNestStrip->setGeometry(QRect(210, 280, 120, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        tBtnNestStrip->setFont(font1);
        tBtnNestStrip->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnNestStrip->setIcon(icon);
        tBtnNestStrip->setIconSize(QSize(30, 30));
        tBtnNestStrip->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label_5 = new QLabel(StateInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 45, 105, 40));
        lbTime = new QLabel(StateInfo);
        lbTime->setObjectName(QString::fromUtf8("lbTime"));
        lbTime->setGeometry(QRect(10, 145, 105, 40));
        tBtnBack = new QToolButton(StateInfo);
        tBtnBack->setObjectName(QString::fromUtf8("tBtnBack"));
        tBtnBack->setEnabled(true);
        tBtnBack->setGeometry(QRect(350, 280, 120, 60));
        tBtnBack->setFont(font1);
        tBtnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon1);
        tBtnBack->setIconSize(QSize(30, 30));
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbType = new QLabel(StateInfo);
        lbType->setObjectName(QString::fromUtf8("lbType"));
        lbType->setGeometry(QRect(120, 95, 120, 40));
        lbType->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"}"));
        lbType->setAlignment(Qt::AlignCenter);
        lbTitle = new QLabel(StateInfo);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setGeometry(QRect(0, 0, 534, 40));
        lbTitle->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 122, 165);"));
        lbCount = new QLabel(StateInfo);
        lbCount->setObjectName(QString::fromUtf8("lbCount"));
        lbCount->setGeometry(QRect(433, 5, 71, 30));
        lbCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbCount->setAlignment(Qt::AlignCenter);
        lbArea = new QLabel(StateInfo);
        lbArea->setObjectName(QString::fromUtf8("lbArea"));
        lbArea->setGeometry(QRect(120, 195, 371, 60));
        lbArea->setStyleSheet(QString::fromUtf8(""));
        lbArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lbArea->setWordWrap(true);
        lbAlarmValue = new QLabel(StateInfo);
        lbAlarmValue->setObjectName(QString::fromUtf8("lbAlarmValue"));
        lbAlarmValue->setGeometry(QRect(385, 95, 90, 40));
        lbAlarmValue->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"}"));
        lbAlarmValue->setAlignment(Qt::AlignCenter);
        tBtnLastStrip = new QToolButton(StateInfo);
        tBtnLastStrip->setObjectName(QString::fromUtf8("tBtnLastStrip"));
        tBtnLastStrip->setGeometry(QRect(70, 280, 120, 60));
        tBtnLastStrip->setFont(font1);
        tBtnLastStrip->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnLastStrip->setIcon(icon2);
        tBtnLastStrip->setIconSize(QSize(30, 30));
        tBtnLastStrip->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbState = new QLabel(StateInfo);
        lbState->setObjectName(QString::fromUtf8("lbState"));
        lbState->setGeometry(QRect(385, 45, 120, 40));
        lbState->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"}"));
        lbState->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(StateInfo);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 95, 105, 40));
        lbUnit = new QLabel(StateInfo);
        lbUnit->setObjectName(QString::fromUtf8("lbUnit"));
        lbUnit->setGeometry(QRect(475, 100, 35, 40));
        lbUnit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->raise();
        lbTimeValue->raise();
        lbNodeAddr->raise();
        label_4->raise();
        label_7->raise();
        lbAlarm->raise();
        tBtnNestStrip->raise();
        label_5->raise();
        lbTime->raise();
        tBtnBack->raise();
        lbType->raise();
        lbTitle->raise();
        lbArea->raise();
        lbAlarmValue->raise();
        tBtnLastStrip->raise();
        lbState->raise();
        label_11->raise();
        lbUnit->raise();
        label->raise();
        lbCount->raise();

        retranslateUi(StateInfo);

        QMetaObject::connectSlotsByName(StateInfo);
    } // setupUi

    void retranslateUi(QDialog *StateInfo)
    {
        StateInfo->setWindowTitle(QApplication::translate("StateInfo", "Dialog", 0, QApplication::UnicodeUTF8));
        lbTimeValue->setText(QString());
        label_3->setText(QApplication::translate("StateInfo", "\346\235\241", 0, QApplication::UnicodeUTF8));
        lbNodeAddr->setText(QString());
        label_4->setText(QApplication::translate("StateInfo", "\350\212\202\347\202\271\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("StateInfo", "\345\256\211\350\243\205\344\275\215\347\275\256:", 0, QApplication::UnicodeUTF8));
        lbAlarm->setText(QApplication::translate("StateInfo", "\346\212\245\350\255\246\346\225\260\345\200\274:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StateInfo", "\346\200\273\345\205\261:", 0, QApplication::UnicodeUTF8));
        tBtnNestStrip->setText(QApplication::translate("StateInfo", "\344\270\213\346\235\241", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StateInfo", "\350\212\202\347\202\271\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        lbTime->setText(QApplication::translate("StateInfo", "\346\212\245\350\255\246\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        tBtnBack->setText(QApplication::translate("StateInfo", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        lbType->setText(QString());
        lbTitle->setText(QApplication::translate("StateInfo", " \346\225\205\351\232\234\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        lbCount->setText(QString());
        lbArea->setText(QString());
        lbAlarmValue->setText(QString());
        tBtnLastStrip->setText(QApplication::translate("StateInfo", "\344\270\212\346\235\241", 0, QApplication::UnicodeUTF8));
        lbState->setText(QString());
        label_11->setText(QApplication::translate("StateInfo", "\350\212\202\347\202\271\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        lbUnit->setText(QApplication::translate("StateInfo", "mA", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StateInfo: public Ui_StateInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEINFO_H
