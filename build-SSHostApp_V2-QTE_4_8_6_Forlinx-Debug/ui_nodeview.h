/********************************************************************************
** Form generated from reading UI file 'nodeview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEVIEW_H
#define UI_NODEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NodeView
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QToolButton *tBtnNestPage;
    QToolButton *tBtnAlarmInfo;
    QLabel *lbNodeCount;
    QToolButton *tBtnLastPage;
    QLabel *label_20;
    QToolButton *tBtnErrorInfo;
    QLabel *lb_node;
    QToolButton *tBtnOffLineInfo;

    void setupUi(QWidget *NodeView)
    {
        if (NodeView->objectName().isEmpty())
            NodeView->setObjectName(QString::fromUtf8("NodeView"));
        NodeView->resize(850, 560);
        NodeView->setStyleSheet(QString::fromUtf8("QWidget#NodeView{\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton{\n"
"font: 12pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QScrollArea#scrollArea{\n"
"border:1px none;\n"
"background-color: rgb(15, 41, 68);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{\n"
"font: 15pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"}\n"
""));
        scrollArea = new QScrollArea(NodeView);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 70, 850, 490));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea#scrollArea{\n"
"border:1px none;\n"
"}\n"
""));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 850, 490));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget#scrollAreaWidgetContents{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton{\n"
"color: rgb(0, 0, 0);\n"
"font: 13pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"border:1px solid rgb(0, 122, 165);\n"
"background-color: rgb(14, 221, 111);\n"
"border-radius:10px;\n"
"}\n"
""));
        scrollArea->setWidget(scrollAreaWidgetContents);
        tBtnNestPage = new QToolButton(NodeView);
        tBtnNestPage->setObjectName(QString::fromUtf8("tBtnNestPage"));
        tBtnNestPage->setEnabled(true);
        tBtnNestPage->setGeometry(QRect(745, 5, 100, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tBtnNestPage->setFont(font);
        tBtnNestPage->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnNestPage->setIcon(icon);
        tBtnNestPage->setIconSize(QSize(35, 35));
        tBtnNestPage->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnAlarmInfo = new QToolButton(NodeView);
        tBtnAlarmInfo->setObjectName(QString::fromUtf8("tBtnAlarmInfo"));
        tBtnAlarmInfo->setGeometry(QRect(200, 5, 130, 60));
        tBtnAlarmInfo->setFont(font);
        tBtnAlarmInfo->setFocusPolicy(Qt::NoFocus);
        tBtnAlarmInfo->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/alarmInfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnAlarmInfo->setIcon(icon1);
        tBtnAlarmInfo->setIconSize(QSize(35, 35));
        tBtnAlarmInfo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbNodeCount = new QLabel(NodeView);
        lbNodeCount->setObjectName(QString::fromUtf8("lbNodeCount"));
        lbNodeCount->setGeometry(QRect(110, 15, 71, 38));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lbNodeCount->setFont(font1);
        lbNodeCount->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(0, 122, 165);\n"
"}"));
        lbNodeCount->setAlignment(Qt::AlignCenter);
        tBtnLastPage = new QToolButton(NodeView);
        tBtnLastPage->setObjectName(QString::fromUtf8("tBtnLastPage"));
        tBtnLastPage->setGeometry(QRect(635, 5, 100, 60));
        tBtnLastPage->setFont(font);
        tBtnLastPage->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnLastPage->setIcon(icon2);
        tBtnLastPage->setIconSize(QSize(35, 35));
        tBtnLastPage->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label_20 = new QLabel(NodeView);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(0, 70, 850, 2));
        label_20->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"background-color: rgb(0, 122, 165);"));
        tBtnErrorInfo = new QToolButton(NodeView);
        tBtnErrorInfo->setObjectName(QString::fromUtf8("tBtnErrorInfo"));
        tBtnErrorInfo->setGeometry(QRect(345, 5, 130, 60));
        tBtnErrorInfo->setFont(font);
        tBtnErrorInfo->setFocusPolicy(Qt::NoFocus);
        tBtnErrorInfo->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/errorInfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnErrorInfo->setIcon(icon3);
        tBtnErrorInfo->setIconSize(QSize(35, 35));
        tBtnErrorInfo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lb_node = new QLabel(NodeView);
        lb_node->setObjectName(QString::fromUtf8("lb_node"));
        lb_node->setGeometry(QRect(5, 5, 101, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        lb_node->setFont(font2);
        lb_node->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 15pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"	font: 14pt \"DejaVu Sans\";\n"
"color:rgb(0, 122, 165);\n"
"}"));
        lb_node->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tBtnOffLineInfo = new QToolButton(NodeView);
        tBtnOffLineInfo->setObjectName(QString::fromUtf8("tBtnOffLineInfo"));
        tBtnOffLineInfo->setGeometry(QRect(490, 5, 130, 60));
        tBtnOffLineInfo->setFont(font);
        tBtnOffLineInfo->setFocusPolicy(Qt::NoFocus);
        tBtnOffLineInfo->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Image/offLineInfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnOffLineInfo->setIcon(icon4);
        tBtnOffLineInfo->setIconSize(QSize(35, 35));
        tBtnOffLineInfo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        retranslateUi(NodeView);

        QMetaObject::connectSlotsByName(NodeView);
    } // setupUi

    void retranslateUi(QWidget *NodeView)
    {
        NodeView->setWindowTitle(QApplication::translate("NodeView", "Form", 0, QApplication::UnicodeUTF8));
        tBtnNestPage->setText(QApplication::translate("NodeView", "\344\270\213\351\241\265", 0, QApplication::UnicodeUTF8));
        tBtnAlarmInfo->setText(QApplication::translate("NodeView", "\346\212\245\350\255\246\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        lbNodeCount->setText(QApplication::translate("NodeView", "0", 0, QApplication::UnicodeUTF8));
        tBtnLastPage->setText(QApplication::translate("NodeView", "\344\270\212\351\241\265", 0, QApplication::UnicodeUTF8));
        label_20->setText(QString());
        tBtnErrorInfo->setText(QApplication::translate("NodeView", "\346\225\205\351\232\234\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        lb_node->setText(QApplication::translate("NodeView", "\350\212\202\347\202\271\346\200\273\346\225\260:", 0, QApplication::UnicodeUTF8));
        tBtnOffLineInfo->setText(QApplication::translate("NodeView", "\351\200\232\350\256\257\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NodeView: public Ui_NodeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEVIEW_H
