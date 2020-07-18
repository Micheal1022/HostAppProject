/********************************************************************************
** Form generated from reading UI file 'userlogin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserLogin
{
public:
    QLabel *label_26;
    QToolButton *tBtnOk;
    QToolButton *tBtnBack;
    QLabel *label_3;
    QLabel *lbUser;
    QLineEdit *lineEditPwd;
    QToolButton *tBtn_7;
    QToolButton *tBtn_9;
    QToolButton *tBtn_2;
    QToolButton *tBtn_8;
    QToolButton *tBtn_5;
    QToolButton *tBtn_4;
    QToolButton *tBtn_6;
    QToolButton *tBtn_1;
    QToolButton *tBtn_3;
    QToolButton *tBtn_0;
    QToolButton *tBtn_del;
    QToolButton *tBtnAdmin;
    QToolButton *tBtnSuper;

    void setupUi(QWidget *UserLogin)
    {
        if (UserLogin->objectName().isEmpty())
            UserLogin->setObjectName(QString::fromUtf8("UserLogin"));
        UserLogin->resize(1024, 600);
        UserLogin->setFocusPolicy(Qt::NoFocus);
        UserLogin->setStyleSheet(QString::fromUtf8("QWidget{\n"
"color:rgb(15, 41, 68);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLineEdit{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"}\n"
"QLabel{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(15, 41, 68);\n"
"}\n"
"QToolButton#tBtnBack{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb("
                        "255, 255, 255);\n"
"}\n"
"QToolButton#tBtnOk{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"\n"
""));
        label_26 = new QLabel(UserLogin);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(0, 0, 1024, 40));
        label_26->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 122, 165);"));
        tBtnOk = new QToolButton(UserLogin);
        tBtnOk->setObjectName(QString::fromUtf8("tBtnOk"));
        tBtnOk->setGeometry(QRect(380, 510, 92, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tBtnOk->setFont(font);
        tBtnOk->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnOk->setIcon(icon);
        tBtnOk->setIconSize(QSize(35, 35));
        tBtnOk->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnBack = new QToolButton(UserLogin);
        tBtnBack->setObjectName(QString::fromUtf8("tBtnBack"));
        tBtnBack->setEnabled(true);
        tBtnBack->setGeometry(QRect(555, 510, 92, 80));
        tBtnBack->setFont(font);
        tBtnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon1);
        tBtnBack->setIconSize(QSize(35, 35));
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        label_3 = new QLabel(UserLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(315, 150, 50, 50));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Image/pwd.png);"));
        lbUser = new QLabel(UserLogin);
        lbUser->setObjectName(QString::fromUtf8("lbUser"));
        lbUser->setGeometry(QRect(315, 75, 50, 50));
        lbUser->setStyleSheet(QString::fromUtf8("\n"
"border-image: url(:/Image/login.png);"));
        lineEditPwd = new QLineEdit(UserLogin);
        lineEditPwd->setObjectName(QString::fromUtf8("lineEditPwd"));
        lineEditPwd->setGeometry(QRect(375, 150, 281, 50));
        lineEditPwd->setFocusPolicy(Qt::StrongFocus);
        lineEditPwd->setMaxLength(6);
        lineEditPwd->setEchoMode(QLineEdit::Password);
        lineEditPwd->setAlignment(Qt::AlignCenter);
        tBtn_7 = new QToolButton(UserLogin);
        tBtn_7->setObjectName(QString::fromUtf8("tBtn_7"));
        tBtn_7->setGeometry(QRect(380, 360, 80, 60));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tBtn_7->sizePolicy().hasHeightForWidth());
        tBtn_7->setSizePolicy(sizePolicy);
        tBtn_7->setFont(font);
        tBtn_7->setFocusPolicy(Qt::NoFocus);
        tBtn_7->setAutoRepeat(true);
        tBtn_9 = new QToolButton(UserLogin);
        tBtn_9->setObjectName(QString::fromUtf8("tBtn_9"));
        tBtn_9->setGeometry(QRect(570, 360, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_9->sizePolicy().hasHeightForWidth());
        tBtn_9->setSizePolicy(sizePolicy);
        tBtn_9->setFont(font);
        tBtn_9->setFocusPolicy(Qt::NoFocus);
        tBtn_9->setAutoRepeat(true);
        tBtn_2 = new QToolButton(UserLogin);
        tBtn_2->setObjectName(QString::fromUtf8("tBtn_2"));
        tBtn_2->setGeometry(QRect(475, 220, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_2->sizePolicy().hasHeightForWidth());
        tBtn_2->setSizePolicy(sizePolicy);
        tBtn_2->setFont(font);
        tBtn_2->setFocusPolicy(Qt::NoFocus);
        tBtn_2->setAutoRepeat(true);
        tBtn_8 = new QToolButton(UserLogin);
        tBtn_8->setObjectName(QString::fromUtf8("tBtn_8"));
        tBtn_8->setGeometry(QRect(475, 360, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_8->sizePolicy().hasHeightForWidth());
        tBtn_8->setSizePolicy(sizePolicy);
        tBtn_8->setFont(font);
        tBtn_8->setFocusPolicy(Qt::NoFocus);
        tBtn_8->setAutoRepeat(true);
        tBtn_5 = new QToolButton(UserLogin);
        tBtn_5->setObjectName(QString::fromUtf8("tBtn_5"));
        tBtn_5->setGeometry(QRect(475, 290, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_5->sizePolicy().hasHeightForWidth());
        tBtn_5->setSizePolicy(sizePolicy);
        tBtn_5->setFont(font);
        tBtn_5->setFocusPolicy(Qt::NoFocus);
        tBtn_5->setAutoRepeat(true);
        tBtn_4 = new QToolButton(UserLogin);
        tBtn_4->setObjectName(QString::fromUtf8("tBtn_4"));
        tBtn_4->setGeometry(QRect(380, 290, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_4->sizePolicy().hasHeightForWidth());
        tBtn_4->setSizePolicy(sizePolicy);
        tBtn_4->setFont(font);
        tBtn_4->setFocusPolicy(Qt::NoFocus);
        tBtn_4->setAutoRepeat(true);
        tBtn_6 = new QToolButton(UserLogin);
        tBtn_6->setObjectName(QString::fromUtf8("tBtn_6"));
        tBtn_6->setGeometry(QRect(570, 290, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_6->sizePolicy().hasHeightForWidth());
        tBtn_6->setSizePolicy(sizePolicy);
        tBtn_6->setFont(font);
        tBtn_6->setFocusPolicy(Qt::NoFocus);
        tBtn_6->setAutoRepeat(true);
        tBtn_1 = new QToolButton(UserLogin);
        tBtn_1->setObjectName(QString::fromUtf8("tBtn_1"));
        tBtn_1->setGeometry(QRect(380, 220, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_1->sizePolicy().hasHeightForWidth());
        tBtn_1->setSizePolicy(sizePolicy);
        tBtn_1->setFont(font);
        tBtn_1->setFocusPolicy(Qt::NoFocus);
        tBtn_1->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        tBtn_1->setAutoRepeat(true);
        tBtn_3 = new QToolButton(UserLogin);
        tBtn_3->setObjectName(QString::fromUtf8("tBtn_3"));
        tBtn_3->setGeometry(QRect(570, 220, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_3->sizePolicy().hasHeightForWidth());
        tBtn_3->setSizePolicy(sizePolicy);
        tBtn_3->setFont(font);
        tBtn_3->setFocusPolicy(Qt::NoFocus);
        tBtn_3->setAutoRepeat(true);
        tBtn_0 = new QToolButton(UserLogin);
        tBtn_0->setObjectName(QString::fromUtf8("tBtn_0"));
        tBtn_0->setGeometry(QRect(380, 430, 80, 60));
        sizePolicy.setHeightForWidth(tBtn_0->sizePolicy().hasHeightForWidth());
        tBtn_0->setSizePolicy(sizePolicy);
        tBtn_0->setFont(font);
        tBtn_0->setFocusPolicy(Qt::NoFocus);
        tBtn_0->setAutoRepeat(true);
        tBtn_del = new QToolButton(UserLogin);
        tBtn_del->setObjectName(QString::fromUtf8("tBtn_del"));
        tBtn_del->setGeometry(QRect(475, 430, 176, 60));
        sizePolicy.setHeightForWidth(tBtn_del->sizePolicy().hasHeightForWidth());
        tBtn_del->setSizePolicy(sizePolicy);
        tBtn_del->setMinimumSize(QSize(0, 0));
        tBtn_del->setFont(font);
        tBtn_del->setFocusPolicy(Qt::NoFocus);
        tBtn_del->setAutoRepeat(true);
        tBtnAdmin = new QToolButton(UserLogin);
        tBtnAdmin->setObjectName(QString::fromUtf8("tBtnAdmin"));
        tBtnAdmin->setGeometry(QRect(375, 70, 136, 50));
        sizePolicy.setHeightForWidth(tBtnAdmin->sizePolicy().hasHeightForWidth());
        tBtnAdmin->setSizePolicy(sizePolicy);
        tBtnAdmin->setMinimumSize(QSize(0, 0));
        tBtnAdmin->setFont(font);
        tBtnAdmin->setFocusPolicy(Qt::NoFocus);
        tBtnAdmin->setAutoRepeat(true);
        tBtnSuper = new QToolButton(UserLogin);
        tBtnSuper->setObjectName(QString::fromUtf8("tBtnSuper"));
        tBtnSuper->setGeometry(QRect(520, 70, 136, 50));
        sizePolicy.setHeightForWidth(tBtnSuper->sizePolicy().hasHeightForWidth());
        tBtnSuper->setSizePolicy(sizePolicy);
        tBtnSuper->setMinimumSize(QSize(0, 0));
        tBtnSuper->setFont(font);
        tBtnSuper->setFocusPolicy(Qt::NoFocus);
        tBtnSuper->setAutoRepeat(true);
        label_26->raise();
        tBtnOk->raise();
        tBtnBack->raise();
        label_3->raise();
        lineEditPwd->raise();
        lbUser->raise();
        tBtn_7->raise();
        tBtn_9->raise();
        tBtn_2->raise();
        tBtn_8->raise();
        tBtn_5->raise();
        tBtn_4->raise();
        tBtn_6->raise();
        tBtn_1->raise();
        tBtn_3->raise();
        tBtn_0->raise();
        tBtn_del->raise();
        tBtnAdmin->raise();
        tBtnSuper->raise();

        retranslateUi(UserLogin);

        QMetaObject::connectSlotsByName(UserLogin);
    } // setupUi

    void retranslateUi(QWidget *UserLogin)
    {
        UserLogin->setWindowTitle(QApplication::translate("UserLogin", "Form", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("UserLogin", " \347\224\250\346\210\267\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        tBtnOk->setText(QApplication::translate("UserLogin", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        tBtnBack->setText(QApplication::translate("UserLogin", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        lbUser->setText(QString());
        lineEditPwd->setText(QString());
        lineEditPwd->setPlaceholderText(QApplication::translate("UserLogin", "   \350\257\267\350\276\223\345\205\245\345\257\206\347\240\201...", 0, QApplication::UnicodeUTF8));
        tBtn_7->setText(QApplication::translate("UserLogin", "7", 0, QApplication::UnicodeUTF8));
        tBtn_9->setText(QApplication::translate("UserLogin", "9", 0, QApplication::UnicodeUTF8));
        tBtn_2->setText(QApplication::translate("UserLogin", "2", 0, QApplication::UnicodeUTF8));
        tBtn_8->setText(QApplication::translate("UserLogin", "8", 0, QApplication::UnicodeUTF8));
        tBtn_5->setText(QApplication::translate("UserLogin", "5", 0, QApplication::UnicodeUTF8));
        tBtn_4->setText(QApplication::translate("UserLogin", "4", 0, QApplication::UnicodeUTF8));
        tBtn_6->setText(QApplication::translate("UserLogin", "6", 0, QApplication::UnicodeUTF8));
        tBtn_1->setText(QApplication::translate("UserLogin", "1", 0, QApplication::UnicodeUTF8));
        tBtn_3->setText(QApplication::translate("UserLogin", "3", 0, QApplication::UnicodeUTF8));
        tBtn_0->setText(QApplication::translate("UserLogin", "0", 0, QApplication::UnicodeUTF8));
        tBtn_del->setText(QApplication::translate("UserLogin", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        tBtnAdmin->setText(QApplication::translate("UserLogin", "\347\256\241\347\220\206\345\221\230", 0, QApplication::UnicodeUTF8));
        tBtnSuper->setText(QApplication::translate("UserLogin", "\350\266\205\347\272\247\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserLogin: public Ui_UserLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
