/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *tBtnMonitor;
    QToolButton *tBtnMonitor_2;
    QToolButton *tBtnMonitor_3;
    QToolButton *tBtnMonitor_4;
    QToolButton *tBtnMonitor_5;
    QLabel *lbBack;
    QToolButton *tBtnMonitor_6;
    QLabel *label;
    QLabel *lbCompany;
    QLabel *lbTime;
    QToolButton *tBtnMonitor_7;
    QToolButton *tBtnMonitor_8;
    QFrame *line;
    QToolButton *tBtnMonitor_9;
    QGroupBox *gBox_1;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QGroupBox *gBox_2;
    QLabel *label_15;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_9;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QLCDNumber *lcdNumber_5;
    QLCDNumber *lcdNumber_6;
    QLCDNumber *lcdNumber_9;
    QLCDNumber *lcdNumber_10;
    QLCDNumber *lcdNumber_11;
    QLabel *label_39;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLabel *label_57;
    QGroupBox *gBox_3;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
    QLabel *label_61;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_65;
    QLabel *label_66;
    QLabel *label_67;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 101, 150);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(180, 180, 180);\n"
"border-color: rgb(180, 180, 180);\n"
"}\n"
"QGroupBox{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:8px;\n"
"margin-top:22px;\n"
"}\n"
"QGroupBox:title{\n"
"subcontrol-origin: margin;\n"
"left: 5px;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tBtnMonitor = new QToolButton(centralWidget);
        tBtnMonitor->setObjectName(QStringLiteral("tBtnMonitor"));
        tBtnMonitor->setEnabled(true);
        tBtnMonitor->setGeometry(QRect(265, 495, 120, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tBtnMonitor->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/selfCheck.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor->setIcon(icon);
        tBtnMonitor->setIconSize(QSize(60, 60));
        tBtnMonitor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnMonitor_2 = new QToolButton(centralWidget);
        tBtnMonitor_2->setObjectName(QStringLiteral("tBtnMonitor_2"));
        tBtnMonitor_2->setEnabled(true);
        tBtnMonitor_2->setGeometry(QRect(390, 495, 120, 100));
        tBtnMonitor_2->setFont(font);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_2->setIcon(icon1);
        tBtnMonitor_2->setIconSize(QSize(60, 60));
        tBtnMonitor_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnMonitor_3 = new QToolButton(centralWidget);
        tBtnMonitor_3->setObjectName(QStringLiteral("tBtnMonitor_3"));
        tBtnMonitor_3->setEnabled(true);
        tBtnMonitor_3->setGeometry(QRect(515, 495, 120, 100));
        tBtnMonitor_3->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/node.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_3->setIcon(icon2);
        tBtnMonitor_3->setIconSize(QSize(60, 60));
        tBtnMonitor_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnMonitor_4 = new QToolButton(centralWidget);
        tBtnMonitor_4->setObjectName(QStringLiteral("tBtnMonitor_4"));
        tBtnMonitor_4->setEnabled(true);
        tBtnMonitor_4->setGeometry(QRect(640, 495, 120, 100));
        tBtnMonitor_4->setFont(font);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_4->setIcon(icon3);
        tBtnMonitor_4->setIconSize(QSize(60, 60));
        tBtnMonitor_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnMonitor_5 = new QToolButton(centralWidget);
        tBtnMonitor_5->setObjectName(QStringLiteral("tBtnMonitor_5"));
        tBtnMonitor_5->setEnabled(true);
        tBtnMonitor_5->setGeometry(QRect(890, 495, 120, 100));
        tBtnMonitor_5->setFont(font);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Image/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_5->setIcon(icon4);
        tBtnMonitor_5->setIconSize(QSize(60, 60));
        tBtnMonitor_5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        lbBack = new QLabel(centralWidget);
        lbBack->setObjectName(QStringLiteral("lbBack"));
        lbBack->setGeometry(QRect(0, 0, 1024, 70));
        lbBack->setStyleSheet(QString::fromUtf8("font: 30pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 122, 165);"));
        lbBack->setAlignment(Qt::AlignCenter);
        tBtnMonitor_6 = new QToolButton(centralWidget);
        tBtnMonitor_6->setObjectName(QStringLiteral("tBtnMonitor_6"));
        tBtnMonitor_6->setEnabled(true);
        tBtnMonitor_6->setGeometry(QRect(890, 495, 120, 100));
        tBtnMonitor_6->setFont(font);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Image/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_6->setIcon(icon5);
        tBtnMonitor_6->setIconSize(QSize(60, 60));
        tBtnMonitor_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 10, 146, 50));
        label->setStyleSheet(QStringLiteral("border-image: url(:/Image/logo.png);"));
        lbCompany = new QLabel(centralWidget);
        lbCompany->setObjectName(QStringLiteral("lbCompany"));
        lbCompany->setGeometry(QRect(790, 35, 230, 30));
        lbCompany->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        lbCompany->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbTime = new QLabel(centralWidget);
        lbTime->setObjectName(QStringLiteral("lbTime"));
        lbTime->setGeometry(QRect(789, 5, 230, 30));
        lbTime->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        lbTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tBtnMonitor_7 = new QToolButton(centralWidget);
        tBtnMonitor_7->setObjectName(QStringLiteral("tBtnMonitor_7"));
        tBtnMonitor_7->setEnabled(true);
        tBtnMonitor_7->setGeometry(QRect(15, 495, 120, 100));
        tBtnMonitor_7->setFont(font);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Image/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_7->setIcon(icon6);
        tBtnMonitor_7->setIconSize(QSize(60, 60));
        tBtnMonitor_7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnMonitor_8 = new QToolButton(centralWidget);
        tBtnMonitor_8->setObjectName(QStringLiteral("tBtnMonitor_8"));
        tBtnMonitor_8->setEnabled(true);
        tBtnMonitor_8->setGeometry(QRect(140, 495, 120, 100));
        tBtnMonitor_8->setFont(font);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Image/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_8->setIcon(icon7);
        tBtnMonitor_8->setIconSize(QSize(60, 60));
        tBtnMonitor_8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 488, 1024, 2));
        line->setStyleSheet(QStringLiteral("border:2px solid rgb(0, 122, 165);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tBtnMonitor_9 = new QToolButton(centralWidget);
        tBtnMonitor_9->setObjectName(QStringLiteral("tBtnMonitor_9"));
        tBtnMonitor_9->setEnabled(true);
        tBtnMonitor_9->setGeometry(QRect(765, 495, 120, 100));
        tBtnMonitor_9->setFont(font);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Image/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor_9->setIcon(icon8);
        tBtnMonitor_9->setIconSize(QSize(60, 60));
        tBtnMonitor_9->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        gBox_1 = new QGroupBox(centralWidget);
        gBox_1->setObjectName(QStringLiteral("gBox_1"));
        gBox_1->setGeometry(QRect(520, 70, 500, 413));
        gBox_1->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(gBox_1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 365, 40, 40));
        label_2->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_4 = new QLabel(gBox_1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 365, 150, 40));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(gBox_1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 365, 150, 40));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(gBox_1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(255, 365, 40, 40));
        label_3->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_7 = new QLabel(gBox_1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 35, 110, 40));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(gBox_1);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 35, 40, 40));
        label_16->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_17 = new QLabel(gBox_1);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(80, 90, 110, 40));
        label_17->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_18 = new QLabel(gBox_1);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 90, 40, 40));
        label_18->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_19 = new QLabel(gBox_1);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(80, 145, 110, 40));
        label_19->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_20 = new QLabel(gBox_1);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 145, 40, 40));
        label_20->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_21 = new QLabel(gBox_1);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(80, 205, 110, 40));
        label_21->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_22 = new QLabel(gBox_1);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 205, 40, 40));
        label_22->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_23 = new QLabel(gBox_1);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(310, 145, 150, 40));
        label_23->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_24 = new QLabel(gBox_1);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(255, 200, 40, 40));
        label_24->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_25 = new QLabel(gBox_1);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(310, 255, 150, 40));
        label_25->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_26 = new QLabel(gBox_1);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(255, 255, 40, 40));
        label_26->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_27 = new QLabel(gBox_1);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(255, 90, 40, 40));
        label_27->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_28 = new QLabel(gBox_1);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(255, 145, 40, 40));
        label_28->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_29 = new QLabel(gBox_1);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(255, 35, 40, 40));
        label_29->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_30 = new QLabel(gBox_1);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(310, 310, 150, 40));
        label_30->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_31 = new QLabel(gBox_1);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(310, 35, 150, 40));
        label_31->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_32 = new QLabel(gBox_1);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(255, 310, 40, 40));
        label_32->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_33 = new QLabel(gBox_1);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(310, 200, 150, 40));
        label_33->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_34 = new QLabel(gBox_1);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(310, 90, 150, 40));
        label_34->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_35 = new QLabel(gBox_1);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(80, 260, 110, 40));
        label_35->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_36 = new QLabel(gBox_1);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(20, 260, 40, 40));
        label_36->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        label_37 = new QLabel(gBox_1);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(80, 310, 110, 40));
        label_37->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_38 = new QLabel(gBox_1);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(20, 310, 40, 40));
        label_38->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"border-radius:20px;\n"
"background-color: rgb(0, 180, 0);"));
        gBox_2 = new QGroupBox(centralWidget);
        gBox_2->setObjectName(QStringLiteral("gBox_2"));
        gBox_2->setGeometry(QRect(5, 70, 266, 412));
        gBox_2->setStyleSheet(QLatin1String("QLabel{\n"
"font: 14pt;\n"
"color: rgb(0, 0, 0);\n"
"}"));
        label_15 = new QLabel(gBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(25, 80, 80, 30));
        label_15->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(gBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(25, 280, 80, 30));
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(gBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(25, 160, 80, 30));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(gBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(25, 40, 80, 30));
        label_13->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_14 = new QLabel(gBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(25, 120, 80, 30));
        label_14->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(gBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(25, 320, 80, 30));
        label_11->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(gBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(25, 200, 80, 30));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_12 = new QLabel(gBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(25, 360, 80, 30));
        label_12->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(gBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(25, 240, 80, 30));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        lcdNumber = new QLCDNumber(gBox_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(105, 40, 90, 30));
        lcdNumber->setProperty("intValue", QVariant(1000));
        lcdNumber_2 = new QLCDNumber(gBox_2);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(105, 80, 90, 30));
        lcdNumber_3 = new QLCDNumber(gBox_2);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(105, 120, 90, 30));
        lcdNumber_4 = new QLCDNumber(gBox_2);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(105, 160, 90, 30));
        lcdNumber_5 = new QLCDNumber(gBox_2);
        lcdNumber_5->setObjectName(QStringLiteral("lcdNumber_5"));
        lcdNumber_5->setGeometry(QRect(105, 200, 90, 30));
        lcdNumber_6 = new QLCDNumber(gBox_2);
        lcdNumber_6->setObjectName(QStringLiteral("lcdNumber_6"));
        lcdNumber_6->setGeometry(QRect(105, 360, 90, 30));
        lcdNumber_9 = new QLCDNumber(gBox_2);
        lcdNumber_9->setObjectName(QStringLiteral("lcdNumber_9"));
        lcdNumber_9->setGeometry(QRect(105, 320, 90, 30));
        lcdNumber_10 = new QLCDNumber(gBox_2);
        lcdNumber_10->setObjectName(QStringLiteral("lcdNumber_10"));
        lcdNumber_10->setGeometry(QRect(105, 240, 90, 30));
        lcdNumber_11 = new QLCDNumber(gBox_2);
        lcdNumber_11->setObjectName(QStringLiteral("lcdNumber_11"));
        lcdNumber_11->setGeometry(QRect(105, 280, 90, 30));
        label_39 = new QLabel(gBox_2);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(215, 40, 30, 30));
        label_50 = new QLabel(gBox_2);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(215, 80, 30, 30));
        label_51 = new QLabel(gBox_2);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setGeometry(QRect(215, 125, 30, 30));
        label_52 = new QLabel(gBox_2);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(210, 160, 30, 30));
        label_53 = new QLabel(gBox_2);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(210, 200, 30, 30));
        label_54 = new QLabel(gBox_2);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(210, 240, 30, 30));
        label_55 = new QLabel(gBox_2);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setGeometry(QRect(210, 280, 30, 30));
        label_56 = new QLabel(gBox_2);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(210, 320, 30, 30));
        label_57 = new QLabel(gBox_2);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(210, 360, 30, 30));
        gBox_3 = new QGroupBox(centralWidget);
        gBox_3->setObjectName(QStringLiteral("gBox_3"));
        gBox_3->setGeometry(QRect(275, 70, 241, 412));
        label_58 = new QLabel(gBox_3);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setGeometry(QRect(25, 40, 61, 70));
        label_58->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"\n"
"background-color: rgb(0, 180, 0);"));
        label_59 = new QLabel(gBox_3);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(25, 110, 61, 70));
        label_59->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"\n"
"background-color: rgb(0, 180, 0);"));
        label_60 = new QLabel(gBox_3);
        label_60->setObjectName(QStringLiteral("label_60"));
        label_60->setGeometry(QRect(25, 180, 61, 70));
        label_60->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"\n"
"background-color: rgb(0, 180, 0);"));
        label_61 = new QLabel(gBox_3);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setGeometry(QRect(25, 320, 61, 70));
        label_61->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"\n"
"background-color: rgb(0, 180, 0);"));
        label_62 = new QLabel(gBox_3);
        label_62->setObjectName(QStringLiteral("label_62"));
        label_62->setGeometry(QRect(25, 250, 61, 70));
        label_62->setStyleSheet(QLatin1String("border:1px solid rgb(0, 122, 165);\n"
"\n"
"background-color: rgb(0, 180, 0);"));
        label_63 = new QLabel(gBox_3);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setGeometry(QRect(115, 55, 110, 40));
        label_63->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_64 = new QLabel(gBox_3);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setGeometry(QRect(120, 120, 110, 40));
        label_64->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_65 = new QLabel(gBox_3);
        label_65->setObjectName(QStringLiteral("label_65"));
        label_65->setGeometry(QRect(120, 195, 110, 40));
        label_65->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_66 = new QLabel(gBox_3);
        label_66->setObjectName(QStringLiteral("label_66"));
        label_66->setGeometry(QRect(120, 265, 110, 40));
        label_66->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_67 = new QLabel(gBox_3);
        label_67->setObjectName(QStringLiteral("label_67"));
        label_67->setGeometry(QRect(120, 335, 110, 40));
        label_67->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralWidget);
        tBtnMonitor_6->raise();
        tBtnMonitor->raise();
        tBtnMonitor_2->raise();
        tBtnMonitor_3->raise();
        tBtnMonitor_4->raise();
        tBtnMonitor_5->raise();
        lbBack->raise();
        label->raise();
        lbCompany->raise();
        lbTime->raise();
        tBtnMonitor_7->raise();
        tBtnMonitor_8->raise();
        line->raise();
        tBtnMonitor_9->raise();
        gBox_1->raise();
        gBox_2->raise();
        gBox_3->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        tBtnMonitor->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\346\250\241\345\274\217", 0));
        tBtnMonitor_2->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\250\241\345\274\217", 0));
        tBtnMonitor_3->setText(QApplication::translate("MainWindow", "\346\243\200\344\277\256\346\250\241\345\274\217", 0));
        tBtnMonitor_4->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\351\205\215\347\275\256", 0));
        tBtnMonitor_5->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\231\273\351\231\206", 0));
        lbBack->setText(QApplication::translate("MainWindow", "\345\205\205\347\224\265\345\274\223\346\216\247\345\210\266\345\231\250", 0));
        tBtnMonitor_6->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\351\200\200\345\207\272", 0));
        label->setText(QString());
        lbCompany->setText(QApplication::translate("MainWindow", "\345\214\227\344\272\254\347\273\264\351\200\232\345\210\251\347\224\265\346\260\224\346\234\211\351\231\220\345\205\254\345\217\270", 0));
        lbTime->setText(QApplication::translate("MainWindow", "2020/09/03 14:25:20", 0));
        tBtnMonitor_7->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\344\270\213\351\231\215", 0));
        tBtnMonitor_8->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\344\270\212\345\215\207", 0));
        tBtnMonitor_9->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\244\215\344\275\215", 0));
        gBox_1->setTitle(QApplication::translate("MainWindow", "\345\274\223\346\225\205\351\232\234", 0));
        label_2->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233\344\274\240\346\204\237\345\231\2501\346\225\205\351\232\234", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233\344\274\240\346\204\237\345\231\2502\346\225\205\351\232\234", 0));
        label_3->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\344\270\212\346\255\242\347\202\271\346\225\205\351\232\234", 0));
        label_16->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "\344\270\213\346\255\242\347\202\271\346\225\205\351\232\234", 0));
        label_18->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "\347\247\201\346\234\215\346\225\205\351\232\234", 0));
        label_20->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\346\200\245\345\201\234\346\225\205\351\232\234", 0));
        label_22->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\2503\346\225\205\351\232\234", 0));
        label_24->setText(QString());
        label_25->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\2505\346\225\205\351\232\234", 0));
        label_26->setText(QString());
        label_27->setText(QString());
        label_28->setText(QString());
        label_29->setText(QString());
        label_30->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\2506\346\225\205\351\232\234", 0));
        label_31->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\2501\346\225\205\351\232\234", 0));
        label_32->setText(QString());
        label_33->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\2504\346\225\205\351\232\234", 0));
        label_34->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\2502\346\225\205\351\232\234", 0));
        label_35->setText(QApplication::translate("MainWindow", "\350\266\205\346\227\266\346\225\205\351\232\234", 0));
        label_36->setText(QString());
        label_37->setText(QApplication::translate("MainWindow", "\346\226\255\347\224\265\346\225\205\351\232\234", 0));
        label_38->setText(QString());
        gBox_2->setTitle(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\225\260\346\215\256", 0));
        label_15->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233-2:", 0));
        label_10->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-4:", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-1:", 0));
        label_13->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233-1:", 0));
        label_14->setText(QApplication::translate("MainWindow", "CP\347\224\265\345\216\213:", 0));
        label_11->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-5:", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-2:", 0));
        label_12->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-6:", 0));
        label_9->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-3:", 0));
        label_39->setText(QApplication::translate("MainWindow", "N", 0));
        label_50->setText(QApplication::translate("MainWindow", "N", 0));
        label_51->setText(QApplication::translate("MainWindow", "V", 0));
        label_52->setText(QApplication::translate("MainWindow", "\342\204\203", 0));
        label_53->setText(QApplication::translate("MainWindow", "\342\204\203", 0));
        label_54->setText(QApplication::translate("MainWindow", "\342\204\203", 0));
        label_55->setText(QApplication::translate("MainWindow", "\342\204\203", 0));
        label_56->setText(QApplication::translate("MainWindow", "\342\204\203", 0));
        label_57->setText(QApplication::translate("MainWindow", "\342\204\203", 0));
        gBox_3->setTitle(QApplication::translate("MainWindow", "\345\274\223\347\212\266\346\200\201", 0));
        label_58->setText(QString());
        label_59->setText(QString());
        label_60->setText(QString());
        label_61->setText(QString());
        label_62->setText(QString());
        label_63->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\344\275\215\347\275\256", 0));
        label_64->setText(QApplication::translate("MainWindow", "\351\231\215\345\274\223\344\270\255", 0));
        label_65->setText(QApplication::translate("MainWindow", "\351\231\215\345\274\223\345\210\260\344\275\215", 0));
        label_66->setText(QApplication::translate("MainWindow", "\345\215\207\345\274\223\344\270\255", 0));
        label_67->setText(QApplication::translate("MainWindow", "\345\215\207\345\274\223\345\210\260\344\275\215", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
