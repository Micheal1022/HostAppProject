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
#include <QtWidgets/QHeaderView>
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
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QToolButton *tBtnMonitor_7;
    QToolButton *tBtnMonitor_8;
    QFrame *line;
    QToolButton *tBtnMonitor_9;

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
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 90, 90, 41));
        label_4->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(315, 95, 90, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(570, 100, 90, 41));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 205, 90, 40));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(35, 255, 90, 40));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 345, 90, 40));
        label_9->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(360, 215, 90, 40));
        label_10->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(355, 300, 90, 40));
        label_11->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(355, 355, 90, 40));
        label_12->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(670, 355, 90, 40));
        label_13->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(660, 220, 90, 40));
        label_14->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(665, 285, 90, 40));
        label_15->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);"));
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
        label_4->raise();
        label_5->raise();
        label_7->raise();
        label_6->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        label_14->raise();
        label_15->raise();
        tBtnMonitor_7->raise();
        tBtnMonitor_8->raise();
        line->raise();
        tBtnMonitor_9->raise();

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
        label_4->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\346\250\241\345\274\217:", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\274\223\347\212\266\346\200\201", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\274\223\346\225\205\351\232\234:", 0));
        label_6->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-1:", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-2:", 0));
        label_9->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-3:", 0));
        label_10->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-4:", 0));
        label_11->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-5:", 0));
        label_12->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246-6:", 0));
        label_13->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233-1:", 0));
        label_14->setText(QApplication::translate("MainWindow", "CP\347\224\265\345\216\213:", 0));
        label_15->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233-2:", 0));
        tBtnMonitor_7->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\344\270\213\351\231\215", 0));
        tBtnMonitor_8->setText(QApplication::translate("MainWindow", "\346\211\213\345\212\250\344\270\212\345\215\207", 0));
        tBtnMonitor_9->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\345\244\215\344\275\215", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
