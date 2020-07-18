/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lbVersonPM;
    QToolButton *tBtnLginout;
    QToolButton *tBtnRecord;
    QToolButton *tBtnSystemSet;
    QLabel *lbCurPass;
    QLabel *lbTitle;
    QLabel *lbLogoSensor;
    QToolButton *tBtnUserLogin;
    QLabel *lbBack;
    QLabel *lbCompany;
    QToolButton *tBtnSelfCheck;
    QToolButton *tBtnMonitor;
    QToolButton *tBtnSystemError;
    QLabel *lbLogoBevone;
    QLabel *lbVersonEF;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralWidget{\n"
"background-color: rgb(255, 255, 255);\n"
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
"border:2px solid rgb(28, 183, 200);\n"
"border-radius:10px;\n"
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
"QLabel#lbTitle{\n"
""
                        "font: 30pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:1px solid rgb(0, 122, 165) ;\n"
"color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 122, 165);\n"
"border-bottom-left-radius:40px;\n"
"border-bottom-right-radius:40px;\n"
"}\n"
"QLabel#lbCompany{\n"
"font: 25pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 101, 150);\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        centralWidget->setFont(font);
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        lbVersonPM = new QLabel(centralWidget);
        lbVersonPM->setObjectName(QString::fromUtf8("lbVersonPM"));
        lbVersonPM->setGeometry(QRect(925, 565, 90, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lbVersonPM->setFont(font1);
        lbVersonPM->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";"));
        tBtnLginout = new QToolButton(centralWidget);
        tBtnLginout->setObjectName(QString::fromUtf8("tBtnLginout"));
        tBtnLginout->setGeometry(QRect(430, 275, 150, 130));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        tBtnLginout->setFont(font2);
        tBtnLginout->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnLginout->setIcon(icon);
        tBtnLginout->setIconSize(QSize(80, 80));
        tBtnLginout->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnRecord = new QToolButton(centralWidget);
        tBtnRecord->setObjectName(QString::fromUtf8("tBtnRecord"));
        tBtnRecord->setGeometry(QRect(230, 275, 150, 130));
        tBtnRecord->setFont(font2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/volume.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnRecord->setIcon(icon1);
        tBtnRecord->setIconSize(QSize(80, 80));
        tBtnRecord->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnSystemSet = new QToolButton(centralWidget);
        tBtnSystemSet->setObjectName(QString::fromUtf8("tBtnSystemSet"));
        tBtnSystemSet->setGeometry(QRect(830, 275, 150, 130));
        tBtnSystemSet->setFont(font2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnSystemSet->setIcon(icon2);
        tBtnSystemSet->setIconSize(QSize(80, 80));
        tBtnSystemSet->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        lbCurPass = new QLabel(centralWidget);
        lbCurPass->setObjectName(QString::fromUtf8("lbCurPass"));
        lbCurPass->setGeometry(QRect(740, 515, 30, 30));
        lbCurPass->setAlignment(Qt::AlignCenter);
        lbTitle = new QLabel(centralWidget);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setGeometry(QRect(250, 5, 524, 100));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font3.setPointSize(30);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        lbTitle->setFont(font3);
        lbTitle->setFocusPolicy(Qt::ClickFocus);
        lbTitle->setStyleSheet(QString::fromUtf8(""));
        lbTitle->setAlignment(Qt::AlignCenter);
        lbLogoSensor = new QLabel(centralWidget);
        lbLogoSensor->setObjectName(QString::fromUtf8("lbLogoSensor"));
        lbLogoSensor->setGeometry(QRect(5, 10, 226, 61));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font4.setPointSize(24);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        lbLogoSensor->setFont(font4);
        lbLogoSensor->setFocusPolicy(Qt::ClickFocus);
        lbLogoSensor->setStyleSheet(QString::fromUtf8("border-image: url(:/Image/ss_logo.png);"));
        lbLogoSensor->setAlignment(Qt::AlignCenter);
        tBtnUserLogin = new QToolButton(centralWidget);
        tBtnUserLogin->setObjectName(QString::fromUtf8("tBtnUserLogin"));
        tBtnUserLogin->setGeometry(QRect(430, 275, 150, 130));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnUserLogin->setIcon(icon3);
        tBtnUserLogin->setIconSize(QSize(80, 80));
        tBtnUserLogin->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        lbBack = new QLabel(centralWidget);
        lbBack->setObjectName(QString::fromUtf8("lbBack"));
        lbBack->setGeometry(QRect(0, 0, 1024, 80));
        lbBack->setStyleSheet(QString::fromUtf8("font: 30pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 122, 165);"));
        lbBack->setAlignment(Qt::AlignCenter);
        lbCompany = new QLabel(centralWidget);
        lbCompany->setObjectName(QString::fromUtf8("lbCompany"));
        lbCompany->setGeometry(QRect(260, 545, 504, 40));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font5.setPointSize(25);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        lbCompany->setFont(font5);
        lbCompany->setFocusPolicy(Qt::ClickFocus);
        lbCompany->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        tBtnSelfCheck = new QToolButton(centralWidget);
        tBtnSelfCheck->setObjectName(QString::fromUtf8("tBtnSelfCheck"));
        tBtnSelfCheck->setGeometry(QRect(630, 275, 150, 130));
        tBtnSelfCheck->setFont(font2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Image/selfCheck.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnSelfCheck->setIcon(icon4);
        tBtnSelfCheck->setIconSize(QSize(80, 80));
        tBtnSelfCheck->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnMonitor = new QToolButton(centralWidget);
        tBtnMonitor->setObjectName(QString::fromUtf8("tBtnMonitor"));
        tBtnMonitor->setEnabled(true);
        tBtnMonitor->setGeometry(QRect(30, 275, 150, 130));
        tBtnMonitor->setFont(font2);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Image/node.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnMonitor->setIcon(icon5);
        tBtnMonitor->setIconSize(QSize(80, 80));
        tBtnMonitor->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnSystemError = new QToolButton(centralWidget);
        tBtnSystemError->setObjectName(QString::fromUtf8("tBtnSystemError"));
        tBtnSystemError->setGeometry(QRect(10, 520, 86, 76));
        lbLogoBevone = new QLabel(centralWidget);
        lbLogoBevone->setObjectName(QString::fromUtf8("lbLogoBevone"));
        lbLogoBevone->setGeometry(QRect(10, 20, 216, 36));
        lbLogoBevone->setFont(font4);
        lbLogoBevone->setFocusPolicy(Qt::ClickFocus);
        lbLogoBevone->setStyleSheet(QString::fromUtf8(""));
        lbLogoBevone->setAlignment(Qt::AlignCenter);
        lbVersonEF = new QLabel(centralWidget);
        lbVersonEF->setObjectName(QString::fromUtf8("lbVersonEF"));
        lbVersonEF->setGeometry(QRect(925, 565, 90, 31));
        lbVersonEF->setFont(font1);
        lbVersonEF->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";"));
        MainWindow->setCentralWidget(centralWidget);
        tBtnLginout->raise();
        tBtnUserLogin->raise();
        lbVersonPM->raise();
        tBtnRecord->raise();
        tBtnSystemSet->raise();
        lbCurPass->raise();
        lbBack->raise();
        lbCompany->raise();
        tBtnSelfCheck->raise();
        tBtnMonitor->raise();
        lbTitle->raise();
        lbLogoSensor->raise();
        tBtnSystemError->raise();
        lbLogoBevone->raise();
        lbVersonEF->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        lbVersonPM->setText(QApplication::translate("MainWindow", "V-2.0.3", 0, QApplication::UnicodeUTF8));
        tBtnLginout->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\263\250\351\224\200", 0, QApplication::UnicodeUTF8));
        tBtnRecord->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        tBtnSystemSet->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        lbCurPass->setText(QString());
        lbTitle->setText(QString());
        lbLogoSensor->setText(QString());
        tBtnUserLogin->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        lbBack->setText(QString());
        lbCompany->setText(QApplication::translate("MainWindow", "\350\245\277\345\256\211\347\233\233\350\265\233\345\260\224\347\224\265\345\255\220\346\234\211\351\231\220\345\205\254\345\217\270", 0, QApplication::UnicodeUTF8));
        tBtnSelfCheck->setText(QApplication::translate("MainWindow", "\344\270\273\346\234\272\350\207\252\346\243\200", 0, QApplication::UnicodeUTF8));
        tBtnMonitor->setText(QApplication::translate("MainWindow", "\347\233\221\346\216\247\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        tBtnSystemError->setText(QApplication::translate("MainWindow", "\347\263\273\347\273\237\n"
"\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        lbLogoBevone->setText(QString());
        lbVersonEF->setText(QApplication::translate("MainWindow", "V-2.0.1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
