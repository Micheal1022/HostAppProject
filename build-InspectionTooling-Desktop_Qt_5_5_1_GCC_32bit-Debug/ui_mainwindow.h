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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lbBack;
    QStackedWidget *stackedWidget;
    QWidget *pageMain;
    QToolButton *tBtnLeak;
    QToolButton *tBtnThreeVol;
    QToolButton *tBtnThreeVolCur;
    QToolButton *tBtnQuit;
    QToolButton *tBtnSingleVolCur;
    QWidget *pageLeak;
    QWidget *pageThreeCurVol;
    QWidget *pageThreeVol;
    QWidget *pageSingelCurVol;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 600);
        QIcon icon;
        icon.addFile(QStringLiteral("system.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget#centralWidget{\n"
"background-color: rgb(0, 85, 127);\n"
"}\n"
"\n"
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
"}"));
        lbBack = new QLabel(centralWidget);
        lbBack->setObjectName(QStringLiteral("lbBack"));
        lbBack->setGeometry(QRect(0, 0, 1024, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(25);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lbBack->setFont(font);
        lbBack->setStyleSheet(QString::fromUtf8("font: 25pt \"\345\256\213\344\275\223\";\n"
"color:rgb(0, 122, 165);\n"
"background-color: rgb(255, 255, 255);"));
        lbBack->setAlignment(Qt::AlignCenter);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 40, 1024, 560));
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(0, 85, 127);\n"
"}\n"
"QToolButton{\n"
"font: 28pt \"\345\256\213\344\275\223\";\n"
"color:  rgb(0, 85, 127);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        pageMain = new QWidget();
        pageMain->setObjectName(QStringLiteral("pageMain"));
        tBtnLeak = new QToolButton(pageMain);
        tBtnLeak->setObjectName(QStringLiteral("tBtnLeak"));
        tBtnLeak->setGeometry(QRect(50, 180, 200, 140));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(28);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        tBtnLeak->setFont(font1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnLeak->setIcon(icon1);
        tBtnLeak->setIconSize(QSize(80, 80));
        tBtnLeak->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnThreeVol = new QToolButton(pageMain);
        tBtnThreeVol->setObjectName(QStringLiteral("tBtnThreeVol"));
        tBtnThreeVol->setGeometry(QRect(530, 180, 200, 140));
        tBtnThreeVol->setFont(font1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnThreeVol->setIcon(icon2);
        tBtnThreeVol->setIconSize(QSize(80, 80));
        tBtnThreeVol->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnThreeVolCur = new QToolButton(pageMain);
        tBtnThreeVolCur->setObjectName(QStringLiteral("tBtnThreeVolCur"));
        tBtnThreeVolCur->setGeometry(QRect(290, 180, 200, 140));
        tBtnThreeVolCur->setFont(font1);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/selfCheck.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnThreeVolCur->setIcon(icon3);
        tBtnThreeVolCur->setIconSize(QSize(80, 80));
        tBtnThreeVolCur->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnQuit = new QToolButton(pageMain);
        tBtnQuit->setObjectName(QStringLiteral("tBtnQuit"));
        tBtnQuit->setGeometry(QRect(885, 460, 120, 60));
        tBtnQuit->setFont(font1);
        tBtnQuit->setIcon(icon2);
        tBtnQuit->setIconSize(QSize(80, 80));
        tBtnQuit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnSingleVolCur = new QToolButton(pageMain);
        tBtnSingleVolCur->setObjectName(QStringLiteral("tBtnSingleVolCur"));
        tBtnSingleVolCur->setGeometry(QRect(765, 180, 200, 140));
        tBtnSingleVolCur->setFont(font1);
        tBtnSingleVolCur->setIcon(icon3);
        tBtnSingleVolCur->setIconSize(QSize(80, 80));
        tBtnSingleVolCur->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        stackedWidget->addWidget(pageMain);
        pageLeak = new QWidget();
        pageLeak->setObjectName(QStringLiteral("pageLeak"));
        stackedWidget->addWidget(pageLeak);
        pageThreeCurVol = new QWidget();
        pageThreeCurVol->setObjectName(QStringLiteral("pageThreeCurVol"));
        stackedWidget->addWidget(pageThreeCurVol);
        pageThreeVol = new QWidget();
        pageThreeVol->setObjectName(QStringLiteral("pageThreeVol"));
        stackedWidget->addWidget(pageThreeVol);
        pageSingelCurVol = new QWidget();
        pageSingelCurVol->setObjectName(QStringLiteral("pageSingelCurVol"));
        stackedWidget->addWidget(pageSingelCurVol);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lbBack->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213/\347\224\265\346\265\201\346\216\242\346\265\213\345\231\250\346\243\200\346\265\213\345\267\245\350\243\205", 0));
        tBtnLeak->setText(QApplication::translate("MainWindow", "\346\274\217\347\224\265", 0));
        tBtnThreeVol->setText(QApplication::translate("MainWindow", "3V/2V/V", 0));
        tBtnThreeVolCur->setText(QApplication::translate("MainWindow", "2VA/VA", 0));
        tBtnQuit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        tBtnSingleVolCur->setText(QApplication::translate("MainWindow", "6V3A", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
