/********************************************************************************
** Form generated from reading UI file 'monitor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Monitor
{
public:
    QLabel *lbTitle;
    QStackedWidget *stackedWgtPass;
    QLabel *label_19;
    QLabel *lbSystemTime;
    QFrame *line;
    QWidget *widget;
    QLabel *lbNormalTotal;
    QLabel *lbErrorTotal;
    QLabel *lbTotalPass;
    QLabel *label_9;
    QLabel *lbOffLineTotal;
    QToolButton *tBtnMute;
    QLabel *label_24;
    QLabel *lbAlarmTotal;
    QLabel *label_20;
    QToolButton *tBtnBackHome;
    QLabel *label_12;
    QLabel *label_25;
    QToolButton *tBtnReset;
    QLabel *lbAlarm;
    QLabel *label_16;
    QLabel *label_17;
    QToolButton *tBtnLoopSwitch;
    QLabel *label_14;
    QLabel *label_18;
    QLabel *label_21;
    QLabel *lbPowerLost;
    QLabel *lbPowerLostTotal;

    void setupUi(QWidget *Monitor)
    {
        if (Monitor->objectName().isEmpty())
            Monitor->setObjectName(QString::fromUtf8("Monitor"));
        Monitor->setEnabled(true);
        Monitor->resize(1024, 600);
        Monitor->setStyleSheet(QString::fromUtf8("QWidget#Monitor{\n"
"background-color: rgb(245, 245, 220);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{\n"
"font: 18pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(80, 175, 185);\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QDialog{\n"
"font: 18pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton{\n"
"width:80px;\n"
"height:35px;\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"}\n"
""));
        lbTitle = new QLabel(Monitor);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setGeometry(QRect(0, 0, 1024, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lbTitle->setFont(font);
        lbTitle->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 122, 165);"));
        stackedWgtPass = new QStackedWidget(Monitor);
        stackedWgtPass->setObjectName(QString::fromUtf8("stackedWgtPass"));
        stackedWgtPass->setGeometry(QRect(0, 40, 850, 560));
        stackedWgtPass->setStyleSheet(QString::fromUtf8("QWidget{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(15, 41, 68);\n"
"background-color: rgb(245, 245, 220);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLCDNumber{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(80, 175, 185);\n"
"border:1px solid white;\n"
"border-color: rgb(79, 229, 219);\n"
"border-radius:8px;\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid rgb(28, 183, 200);\n"
"border-radius:10px;\n"
"background-color: rgb(43, 79, 102);\n"
"background-color: rgb(15, 41, 68);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 18pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277"
                        "\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"font: 16pt \"Noto Sans [monotype]\";\n"
"color: rgb(80, 175, 185);\n"
"color: rgb(0, 0, 0);\n"
"}\n"
""));
        label_19 = new QLabel(Monitor);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(0, 38, 800, 2));
        label_19->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(28, 183, 200, 255), stop:1 rgba(0, 85, 127, 255));"));
        lbSystemTime = new QLabel(Monitor);
        lbSystemTime->setObjectName(QString::fromUtf8("lbSystemTime"));
        lbSystemTime->setGeometry(QRect(750, 5, 270, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lbSystemTime->setFont(font1);
        lbSystemTime->setFocusPolicy(Qt::TabFocus);
        lbSystemTime->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        lbSystemTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        line = new QFrame(Monitor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(850, 40, 3, 560));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(Monitor);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(855, 40, 168, 560));
        widget->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"font: 15pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 101, 150);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 15pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(180, 180, 180);\n"
"border-color: rgb(180, 180, 180);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(80, 175, 185);\n"
"color: rgb(0, 0, 0);\n"
"}"));
        lbNormalTotal = new QLabel(widget);
        lbNormalTotal->setObjectName(QString::fromUtf8("lbNormalTotal"));
        lbNormalTotal->setGeometry(QRect(80, 80, 70, 35));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font2.setPointSize(16);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        lbNormalTotal->setFont(font2);
        lbNormalTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbErrorTotal = new QLabel(widget);
        lbErrorTotal->setObjectName(QString::fromUtf8("lbErrorTotal"));
        lbErrorTotal->setGeometry(QRect(80, 125, 70, 35));
        lbErrorTotal->setFont(font2);
        lbErrorTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbTotalPass = new QLabel(widget);
        lbTotalPass->setObjectName(QString::fromUtf8("lbTotalPass"));
        lbTotalPass->setGeometry(QRect(105, 15, 41, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        lbTotalPass->setFont(font3);
        lbTotalPass->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"}"));
        lbTotalPass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 125, 150, 35));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:1px solid;\n"
"border-radius:5px;\n"
"background-color: rgb(255, 233, 32);\n"
""));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbOffLineTotal = new QLabel(widget);
        lbOffLineTotal->setObjectName(QString::fromUtf8("lbOffLineTotal"));
        lbOffLineTotal->setGeometry(QRect(80, 215, 70, 35));
        lbOffLineTotal->setFont(font2);
        lbOffLineTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tBtnMute = new QToolButton(widget);
        tBtnMute->setObjectName(QString::fromUtf8("tBtnMute"));
        tBtnMute->setGeometry(QRect(10, 260, 150, 70));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/speaker.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMute->setIcon(icon);
        tBtnMute->setIconSize(QSize(35, 35));
        tBtnMute->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label_24 = new QLabel(widget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(0, 5, 106, 60));
        label_24->setFont(font3);
        label_24->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"}"));
        label_24->setAlignment(Qt::AlignCenter);
        lbAlarmTotal = new QLabel(widget);
        lbAlarmTotal->setObjectName(QString::fromUtf8("lbAlarmTotal"));
        lbAlarmTotal->setGeometry(QRect(80, 170, 70, 35));
        lbAlarmTotal->setFont(font2);
        lbAlarmTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_20 = new QLabel(widget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(135, 215, 25, 35));
        label_20->setAlignment(Qt::AlignCenter);
        tBtnBackHome = new QToolButton(widget);
        tBtnBackHome->setObjectName(QString::fromUtf8("tBtnBackHome"));
        tBtnBackHome->setEnabled(true);
        tBtnBackHome->setGeometry(QRect(10, 485, 150, 70));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font4.setPointSize(15);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        tBtnBackHome->setFont(font4);
        tBtnBackHome->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBackHome->setIcon(icon1);
        tBtnBackHome->setIconSize(QSize(35, 35));
        tBtnBackHome->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 80, 150, 35));
        label_12->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:1px solid;\n"
"border-radius:5px;\n"
"background-color: rgb(71, 167, 96);\n"
"background-color: rgb(14, 221, 111);\n"
"\n"
""));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_25 = new QLabel(widget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(175, 15, 25, 35));
        label_25->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"}"));
        label_25->setAlignment(Qt::AlignCenter);
        tBtnReset = new QToolButton(widget);
        tBtnReset->setObjectName(QString::fromUtf8("tBtnReset"));
        tBtnReset->setGeometry(QRect(10, 335, 150, 70));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnReset->setIcon(icon2);
        tBtnReset->setIconSize(QSize(35, 35));
        tBtnReset->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbAlarm = new QLabel(widget);
        lbAlarm->setObjectName(QString::fromUtf8("lbAlarm"));
        lbAlarm->setGeometry(QRect(10, 170, 150, 35));
        lbAlarm->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:1px solid;\n"
"border-radius:5px;\n"
"background-color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 77, 70);"));
        lbAlarm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_16 = new QLabel(widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(135, 170, 25, 35));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(135, 125, 25, 35));
        label_17->setAlignment(Qt::AlignCenter);
        tBtnLoopSwitch = new QToolButton(widget);
        tBtnLoopSwitch->setObjectName(QString::fromUtf8("tBtnLoopSwitch"));
        tBtnLoopSwitch->setEnabled(true);
        tBtnLoopSwitch->setGeometry(QRect(10, 410, 150, 70));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnLoopSwitch->setIcon(icon3);
        tBtnLoopSwitch->setIconSize(QSize(35, 35));
        tBtnLoopSwitch->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label_14 = new QLabel(widget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 215, 150, 35));
        label_14->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:1px solid;\n"
"border-radius:5px;\n"
"background-color: rgb(171, 171, 171);"));
        label_14->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_18 = new QLabel(widget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(135, 80, 25, 35));
        label_18->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(widget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 70, 168, 2));
        label_21->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"background-color:rgb(0, 122, 165);"));
        lbPowerLost = new QLabel(widget);
        lbPowerLost->setObjectName(QString::fromUtf8("lbPowerLost"));
        lbPowerLost->setGeometry(QRect(10, 170, 150, 35));
        lbPowerLost->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:1px solid;\n"
"border-radius:5px;\n"
"background-color: rgb(255, 0, 0);\n"
"background-color: rgb(255, 77, 70);"));
        lbPowerLost->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbPowerLostTotal = new QLabel(widget);
        lbPowerLostTotal->setObjectName(QString::fromUtf8("lbPowerLostTotal"));
        lbPowerLostTotal->setGeometry(QRect(80, 170, 70, 35));
        lbPowerLostTotal->setFont(font2);
        lbPowerLostTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_20->raise();
        label_16->raise();
        label_18->raise();
        label_17->raise();
        lbAlarm->raise();
        lbPowerLost->raise();
        label_9->raise();
        label_14->raise();
        label_12->raise();
        lbNormalTotal->raise();
        lbErrorTotal->raise();
        lbTotalPass->raise();
        lbOffLineTotal->raise();
        tBtnMute->raise();
        label_24->raise();
        tBtnBackHome->raise();
        label_25->raise();
        tBtnReset->raise();
        tBtnLoopSwitch->raise();
        label_21->raise();
        lbAlarmTotal->raise();
        lbPowerLostTotal->raise();
        stackedWgtPass->raise();
        label_19->raise();
        lbTitle->raise();
        lbSystemTime->raise();
        line->raise();
        widget->raise();

        retranslateUi(Monitor);

        QMetaObject::connectSlotsByName(Monitor);
    } // setupUi

    void retranslateUi(QWidget *Monitor)
    {
        Monitor->setWindowTitle(QApplication::translate("Monitor", "Form", 0, QApplication::UnicodeUTF8));
        lbTitle->setText(QApplication::translate("Monitor", " \347\233\221\346\216\247\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_19->setText(QString());
        lbSystemTime->setText(QApplication::translate("Monitor", "2019\345\271\26401\346\234\21031\346\227\245 13:23:40", 0, QApplication::UnicodeUTF8));
        lbNormalTotal->setText(QApplication::translate("Monitor", "0", 0, QApplication::UnicodeUTF8));
        lbErrorTotal->setText(QApplication::translate("Monitor", "0", 0, QApplication::UnicodeUTF8));
        lbTotalPass->setText(QApplication::translate("Monitor", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Monitor", "\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        lbOffLineTotal->setText(QApplication::translate("Monitor", "0", 0, QApplication::UnicodeUTF8));
        tBtnMute->setText(QApplication::translate("Monitor", "\351\235\231\351\237\263\346\214\211\351\222\256", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Monitor", "\345\233\236\350\267\257\346\200\273\346\225\260", 0, QApplication::UnicodeUTF8));
        lbAlarmTotal->setText(QApplication::translate("Monitor", "0", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Monitor", "\344\270\252", 0, QApplication::UnicodeUTF8));
        tBtnBackHome->setText(QApplication::translate("Monitor", "\350\277\224\345\233\236\346\214\211\351\222\256", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Monitor", "\346\255\243\345\270\270", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Monitor", "\346\235\241", 0, QApplication::UnicodeUTF8));
        tBtnReset->setText(QApplication::translate("Monitor", "\345\244\215\344\275\215\346\214\211\351\222\256", 0, QApplication::UnicodeUTF8));
        lbAlarm->setText(QApplication::translate("Monitor", "\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Monitor", "\344\270\252", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Monitor", "\344\270\252", 0, QApplication::UnicodeUTF8));
        tBtnLoopSwitch->setText(QApplication::translate("Monitor", "\345\233\236\350\267\257-1", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Monitor", "\347\246\273\347\272\277", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Monitor", "\344\270\252", 0, QApplication::UnicodeUTF8));
        label_21->setText(QString());
        lbPowerLost->setText(QApplication::translate("Monitor", "\347\224\265\346\272\220", 0, QApplication::UnicodeUTF8));
        lbPowerLostTotal->setText(QApplication::translate("Monitor", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Monitor: public Ui_Monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONITOR_H
