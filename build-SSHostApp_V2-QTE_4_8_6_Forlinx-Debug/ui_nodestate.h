/********************************************************************************
** Form generated from reading UI file 'nodestate.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODESTATE_H
#define UI_NODESTATE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_NodeState
{
public:
    QLabel *lbTitle;
    QTableWidget *tableWidget;
    QLabel *lb_2;
    QLabel *lbLocal;
    QLabel *lb_1;
    QLabel *lbCurId;
    QToolButton *tBtnBack;
    QLabel *lb_3;
    QLabel *lbNodeType;

    void setupUi(QDialog *NodeState)
    {
        if (NodeState->objectName().isEmpty())
            NodeState->setObjectName(QString::fromUtf8("NodeState"));
        NodeState->resize(1024, 600);
        NodeState->setStyleSheet(QString::fromUtf8("QDialog{\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:0px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLCDNumber{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:8px;\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"}\n"
"QLabel{\n"
"font: 12pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"}\n"
"QLabel#lbArea{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"}QGroupBox{\n"
"fon"
                        "t: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:8px;\n"
"margin-top:10px;\n"
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
        lbTitle = new QLabel(NodeState);
        lbTitle->setObjectName(QString::fromUtf8("lbTitle"));
        lbTitle->setGeometry(QRect(0, 0, 1024, 40));
        lbTitle->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 122, 165);"));
        tableWidget = new QTableWidget(NodeState);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(2, 80, 1020, 463));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lb_2 = new QLabel(NodeState);
        lb_2->setObjectName(QString::fromUtf8("lb_2"));
        lb_2->setGeometry(QRect(530, 45, 110, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lb_2->setFont(font);
        lbLocal = new QLabel(NodeState);
        lbLocal->setObjectName(QString::fromUtf8("lbLocal"));
        lbLocal->setGeometry(QRect(640, 45, 380, 35));
        lbLocal->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbLocal->setWordWrap(true);
        lb_1 = new QLabel(NodeState);
        lb_1->setObjectName(QString::fromUtf8("lb_1"));
        lb_1->setGeometry(QRect(10, 45, 86, 35));
        lbCurId = new QLabel(NodeState);
        lbCurId->setObjectName(QString::fromUtf8("lbCurId"));
        lbCurId->setGeometry(QRect(95, 45, 50, 35));
        lbCurId->setAlignment(Qt::AlignCenter);
        tBtnBack = new QToolButton(NodeState);
        tBtnBack->setObjectName(QString::fromUtf8("tBtnBack"));
        tBtnBack->setEnabled(true);
        tBtnBack->setGeometry(QRect(460, 545, 104, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        tBtnBack->setFont(font1);
        tBtnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon);
        tBtnBack->setIconSize(QSize(30, 30));
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lb_3 = new QLabel(NodeState);
        lb_3->setObjectName(QString::fromUtf8("lb_3"));
        lb_3->setGeometry(QRect(160, 45, 110, 35));
        lbNodeType = new QLabel(NodeState);
        lbNodeType->setObjectName(QString::fromUtf8("lbNodeType"));
        lbNodeType->setGeometry(QRect(270, 45, 240, 35));
        lbNodeType->setAlignment(Qt::AlignCenter);

        retranslateUi(NodeState);

        QMetaObject::connectSlotsByName(NodeState);
    } // setupUi

    void retranslateUi(QDialog *NodeState)
    {
        NodeState->setWindowTitle(QApplication::translate("NodeState", "Dialog", 0, QApplication::UnicodeUTF8));
        lbTitle->setText(QApplication::translate("NodeState", " \350\212\202\347\202\271\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        lb_2->setText(QApplication::translate("NodeState", "\345\256\211\350\243\205\344\275\215\347\275\256:", 0, QApplication::UnicodeUTF8));
        lbLocal->setText(QString());
        lb_1->setText(QApplication::translate("NodeState", "\350\212\202\347\202\271ID\357\274\232", 0, QApplication::UnicodeUTF8));
        lbCurId->setText(QApplication::translate("NodeState", "20", 0, QApplication::UnicodeUTF8));
        tBtnBack->setText(QApplication::translate("NodeState", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        lb_3->setText(QApplication::translate("NodeState", "\350\212\202\347\202\271\347\261\273\345\236\213\357\274\232", 0, QApplication::UnicodeUTF8));
        lbNodeType->setText(QApplication::translate("NodeState", "\344\270\211\347\233\270\344\270\244\350\267\257\347\224\265\345\216\213\344\270\200\350\267\257\347\224\265\346\265\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NodeState: public Ui_NodeState {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODESTATE_H
