/********************************************************************************
** Form generated from reading UI file 'datafilter.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAFILTER_H
#define UI_DATAFILTER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataFilter
{
public:
    QLineEdit *lineEditCanId;
    QLabel *lb_end;
    QCheckBox *checkBoxLoop;
    QLineEdit *lineEditLoop;
    QDateTimeEdit *dTEditStart;
    QLabel *lb_start;
    QCheckBox *checkBoxCanId;
    QToolButton *tBtnOk;
    QToolButton *tBtnBack;
    QLabel *label_23;
    QToolButton *tBtnAllError;
    QStackedWidget *stackedWidget;
    QWidget *pagePMFE;
    QToolButton *tBtnErrorPha;
    QToolButton *tBtnOverVol;
    QToolButton *tBtnLostPow;
    QToolButton *tBtnLackVol;
    QToolButton *tBtnOverCur;
    QToolButton *tBtnLostPha;
    QWidget *pageEFMQ;
    QToolButton *tBtnError;
    QToolButton *tBtnAlarm;
    QToolButton *tBtnOffLine;
    QToolButton *tBtnHost;
    QDateTimeEdit *dTEditEnd;
    QWidget *KeyBwidget;
    QToolButton *tBtn_6;
    QToolButton *tBtn_9;
    QToolButton *tBtn_8;
    QToolButton *tBtn_7;
    QToolButton *tBtn_4;
    QToolButton *tBtn_5;
    QToolButton *tBtn_1;
    QToolButton *tBtn_0;
    QToolButton *tBtn_3;
    QToolButton *tBtn_del;
    QToolButton *tBtn_2;

    void setupUi(QWidget *DataFilter)
    {
        if (DataFilter->objectName().isEmpty())
            DataFilter->setObjectName(QString::fromUtf8("DataFilter"));
        DataFilter->resize(1024, 600);
        DataFilter->setFocusPolicy(Qt::NoFocus);
        DataFilter->setStyleSheet(QString::fromUtf8("QWidget#DataFilter{\n"
"color:rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"font: 12pt \"DejaVu Sans\";\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"color:rgb(0, 122, 165);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel#lb_start{\n"
"font: 16pt \"DejaVu Sans\";\n"
"color:rgb(0, 122, 165);\n"
"}\n"
"QLabel#lb_end{\n"
"font: 16pt \"DejaVu Sans\";\n"
"color:rgb(0, 122, 165);\n"
"}\n"
"QLineEdit{\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color:rgb(15, 41, 68);\n"
"border-radius:5px;\n"
"border:2px solid rgb(0, 122, 165);\n"
"}\n"
"QCheckBox{\n"
"spacing: 5px;\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"font: 14pt \"DejaVu Sans\";\n"
"color:rgb(0, 122, 165);\n"
"border:2px"
                        " solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"}\n"
"QCheckBox::indicator{\n"
"width:15px;\n"
"height:15px;\n"
"margin-left:5px;\n"
"border-radius:10px;\n"
"image: url(:/Image/uncheck.png);\n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"image: url(:/Image/uncheck.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"image: url(:/Image/checked.png);\n"
"}\n"
"\n"
"QDateTimeEdit{\n"
"color: rgb(0, 122, 165);\n"
"font: 14pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\" ;\n"
"border:2px solid  rgb(0, 122, 165);\n"
"}\n"
"QDateTimeEdit::up-button {\n"
"width: 30px; \n"
"height:28px;\n"
"}\n"
"QDateTimeEdit::down-button {\n"
" width: 30px;\n"
"height:28px;\n"
"}\n"
"\n"
""));
        lineEditCanId = new QLineEdit(DataFilter);
        lineEditCanId->setObjectName(QString::fromUtf8("lineEditCanId"));
        lineEditCanId->setGeometry(QRect(140, 140, 80, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lineEditCanId->setFont(font);
        lineEditCanId->setFocusPolicy(Qt::ClickFocus);
        lineEditCanId->setMaxLength(3);
        lineEditCanId->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lb_end = new QLabel(DataFilter);
        lb_end->setObjectName(QString::fromUtf8("lb_end"));
        lb_end->setGeometry(QRect(530, 225, 140, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lb_end->setFont(font1);
        checkBoxLoop = new QCheckBox(DataFilter);
        checkBoxLoop->setObjectName(QString::fromUtf8("checkBoxLoop"));
        checkBoxLoop->setGeometry(QRect(30, 65, 100, 60));
        QFont font2;
        font2.setFamily(QString::fromUtf8("DejaVu Sans"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        checkBoxLoop->setFont(font2);
        checkBoxLoop->setFocusPolicy(Qt::NoFocus);
        checkBoxLoop->setStyleSheet(QString::fromUtf8(""));
        checkBoxLoop->setChecked(false);
        lineEditLoop = new QLineEdit(DataFilter);
        lineEditLoop->setObjectName(QString::fromUtf8("lineEditLoop"));
        lineEditLoop->setGeometry(QRect(140, 65, 80, 60));
        lineEditLoop->setFont(font);
        lineEditLoop->setFocusPolicy(Qt::ClickFocus);
        lineEditLoop->setMaxLength(2);
        lineEditLoop->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dTEditStart = new QDateTimeEdit(DataFilter);
        dTEditStart->setObjectName(QString::fromUtf8("dTEditStart"));
        dTEditStart->setGeometry(QRect(170, 230, 320, 60));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        dTEditStart->setFont(font3);
        dTEditStart->setFocusPolicy(Qt::ClickFocus);
        dTEditStart->setStyleSheet(QString::fromUtf8("color: rgb(0, 122, 165);\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\" ;\n"
"border:2px solid  rgb(0, 122, 165);"));
        dTEditStart->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dTEditStart->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        dTEditStart->setCurrentSection(QDateTimeEdit::YearSection);
        dTEditStart->setTimeSpec(Qt::LocalTime);
        lb_start = new QLabel(DataFilter);
        lb_start->setObjectName(QString::fromUtf8("lb_start"));
        lb_start->setGeometry(QRect(25, 230, 140, 60));
        lb_start->setFont(font1);
        checkBoxCanId = new QCheckBox(DataFilter);
        checkBoxCanId->setObjectName(QString::fromUtf8("checkBoxCanId"));
        checkBoxCanId->setGeometry(QRect(30, 140, 100, 60));
        checkBoxCanId->setFont(font2);
        checkBoxCanId->setFocusPolicy(Qt::NoFocus);
        checkBoxCanId->setChecked(false);
        tBtnOk = new QToolButton(DataFilter);
        tBtnOk->setObjectName(QString::fromUtf8("tBtnOk"));
        tBtnOk->setGeometry(QRect(380, 510, 92, 80));
        QFont font4;
        font4.setFamily(QString::fromUtf8("DejaVu Sans"));
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        tBtnOk->setFont(font4);
        tBtnOk->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnOk->setIcon(icon);
        tBtnOk->setIconSize(QSize(35, 35));
        tBtnOk->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        tBtnBack = new QToolButton(DataFilter);
        tBtnBack->setObjectName(QString::fromUtf8("tBtnBack"));
        tBtnBack->setEnabled(true);
        tBtnBack->setGeometry(QRect(560, 510, 92, 80));
        tBtnBack->setFont(font4);
        tBtnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon1);
        tBtnBack->setIconSize(QSize(35, 35));
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        label_23 = new QLabel(DataFilter);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(0, 0, 1024, 40));
        label_23->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 122, 165);"));
        tBtnAllError = new QToolButton(DataFilter);
        tBtnAllError->setObjectName(QString::fromUtf8("tBtnAllError"));
        tBtnAllError->setGeometry(QRect(240, 60, 96, 140));
        tBtnAllError->setFocusPolicy(Qt::NoFocus);
        tBtnAllError->setChecked(false);
        stackedWidget = new QStackedWidget(DataFilter);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(450, 50, 540, 160));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pagePMFE = new QWidget();
        pagePMFE->setObjectName(QString::fromUtf8("pagePMFE"));
        tBtnErrorPha = new QToolButton(pagePMFE);
        tBtnErrorPha->setObjectName(QString::fromUtf8("tBtnErrorPha"));
        tBtnErrorPha->setGeometry(QRect(190, 90, 160, 60));
        tBtnErrorPha->setFocusPolicy(Qt::NoFocus);
        tBtnOverVol = new QToolButton(pagePMFE);
        tBtnOverVol->setObjectName(QString::fromUtf8("tBtnOverVol"));
        tBtnOverVol->setGeometry(QRect(365, 90, 160, 60));
        tBtnOverVol->setFocusPolicy(Qt::NoFocus);
        tBtnLostPow = new QToolButton(pagePMFE);
        tBtnLostPow->setObjectName(QString::fromUtf8("tBtnLostPow"));
        tBtnLostPow->setGeometry(QRect(15, 10, 160, 60));
        tBtnLostPow->setFocusPolicy(Qt::NoFocus);
        tBtnLackVol = new QToolButton(pagePMFE);
        tBtnLackVol->setObjectName(QString::fromUtf8("tBtnLackVol"));
        tBtnLackVol->setGeometry(QRect(190, 10, 160, 60));
        tBtnLackVol->setFocusPolicy(Qt::NoFocus);
        tBtnOverCur = new QToolButton(pagePMFE);
        tBtnOverCur->setObjectName(QString::fromUtf8("tBtnOverCur"));
        tBtnOverCur->setGeometry(QRect(15, 90, 160, 60));
        tBtnOverCur->setFocusPolicy(Qt::NoFocus);
        tBtnLostPha = new QToolButton(pagePMFE);
        tBtnLostPha->setObjectName(QString::fromUtf8("tBtnLostPha"));
        tBtnLostPha->setGeometry(QRect(365, 10, 160, 60));
        tBtnLostPha->setFocusPolicy(Qt::NoFocus);
        stackedWidget->addWidget(pagePMFE);
        pageEFMQ = new QWidget();
        pageEFMQ->setObjectName(QString::fromUtf8("pageEFMQ"));
        tBtnError = new QToolButton(pageEFMQ);
        tBtnError->setObjectName(QString::fromUtf8("tBtnError"));
        tBtnError->setGeometry(QRect(130, 10, 95, 140));
        tBtnError->setFocusPolicy(Qt::NoFocus);
        tBtnAlarm = new QToolButton(pageEFMQ);
        tBtnAlarm->setObjectName(QString::fromUtf8("tBtnAlarm"));
        tBtnAlarm->setGeometry(QRect(15, 10, 95, 140));
        tBtnAlarm->setFocusPolicy(Qt::NoFocus);
        tBtnOffLine = new QToolButton(pageEFMQ);
        tBtnOffLine->setObjectName(QString::fromUtf8("tBtnOffLine"));
        tBtnOffLine->setGeometry(QRect(245, 10, 95, 140));
        tBtnOffLine->setFocusPolicy(Qt::NoFocus);
        stackedWidget->addWidget(pageEFMQ);
        tBtnHost = new QToolButton(DataFilter);
        tBtnHost->setObjectName(QString::fromUtf8("tBtnHost"));
        tBtnHost->setGeometry(QRect(350, 60, 96, 140));
        tBtnHost->setFocusPolicy(Qt::NoFocus);
        tBtnHost->setChecked(false);
        dTEditEnd = new QDateTimeEdit(DataFilter);
        dTEditEnd->setObjectName(QString::fromUtf8("dTEditEnd"));
        dTEditEnd->setGeometry(QRect(670, 225, 320, 60));
        dTEditEnd->setFont(font3);
        dTEditEnd->setFocusPolicy(Qt::ClickFocus);
        dTEditEnd->setStyleSheet(QString::fromUtf8("color: rgb(0, 122, 165);\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\345\276\256\347\261\263\351\273\221\" ;\n"
"border:2px solid  rgb(0, 122, 165);"));
        dTEditEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dTEditEnd->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        dTEditEnd->setCurrentSection(QDateTimeEdit::YearSection);
        dTEditEnd->setTimeSpec(Qt::LocalTime);
        KeyBwidget = new QWidget(DataFilter);
        KeyBwidget->setObjectName(QString::fromUtf8("KeyBwidget"));
        KeyBwidget->setGeometry(QRect(60, 330, 906, 80));
        tBtn_6 = new QToolButton(KeyBwidget);
        tBtn_6->setObjectName(QString::fromUtf8("tBtn_6"));
        tBtn_6->setGeometry(QRect(385, 10, 60, 60));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tBtn_6->sizePolicy().hasHeightForWidth());
        tBtn_6->setSizePolicy(sizePolicy);
        tBtn_6->setFont(font4);
        tBtn_6->setFocusPolicy(Qt::NoFocus);
        tBtn_6->setAutoRepeat(true);
        tBtn_9 = new QToolButton(KeyBwidget);
        tBtn_9->setObjectName(QString::fromUtf8("tBtn_9"));
        tBtn_9->setGeometry(QRect(610, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_9->sizePolicy().hasHeightForWidth());
        tBtn_9->setSizePolicy(sizePolicy);
        tBtn_9->setFont(font4);
        tBtn_9->setFocusPolicy(Qt::NoFocus);
        tBtn_9->setAutoRepeat(true);
        tBtn_8 = new QToolButton(KeyBwidget);
        tBtn_8->setObjectName(QString::fromUtf8("tBtn_8"));
        tBtn_8->setGeometry(QRect(535, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_8->sizePolicy().hasHeightForWidth());
        tBtn_8->setSizePolicy(sizePolicy);
        tBtn_8->setFont(font4);
        tBtn_8->setFocusPolicy(Qt::NoFocus);
        tBtn_8->setAutoRepeat(true);
        tBtn_7 = new QToolButton(KeyBwidget);
        tBtn_7->setObjectName(QString::fromUtf8("tBtn_7"));
        tBtn_7->setGeometry(QRect(460, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_7->sizePolicy().hasHeightForWidth());
        tBtn_7->setSizePolicy(sizePolicy);
        tBtn_7->setFont(font4);
        tBtn_7->setFocusPolicy(Qt::NoFocus);
        tBtn_7->setAutoRepeat(true);
        tBtn_4 = new QToolButton(KeyBwidget);
        tBtn_4->setObjectName(QString::fromUtf8("tBtn_4"));
        tBtn_4->setGeometry(QRect(235, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_4->sizePolicy().hasHeightForWidth());
        tBtn_4->setSizePolicy(sizePolicy);
        tBtn_4->setFont(font4);
        tBtn_4->setFocusPolicy(Qt::NoFocus);
        tBtn_4->setAutoRepeat(true);
        tBtn_5 = new QToolButton(KeyBwidget);
        tBtn_5->setObjectName(QString::fromUtf8("tBtn_5"));
        tBtn_5->setGeometry(QRect(310, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_5->sizePolicy().hasHeightForWidth());
        tBtn_5->setSizePolicy(sizePolicy);
        tBtn_5->setFont(font4);
        tBtn_5->setFocusPolicy(Qt::NoFocus);
        tBtn_5->setAutoRepeat(true);
        tBtn_1 = new QToolButton(KeyBwidget);
        tBtn_1->setObjectName(QString::fromUtf8("tBtn_1"));
        tBtn_1->setGeometry(QRect(10, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_1->sizePolicy().hasHeightForWidth());
        tBtn_1->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        tBtn_1->setFont(font5);
        tBtn_1->setFocusPolicy(Qt::NoFocus);
        tBtn_1->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        tBtn_1->setAutoRepeat(true);
        tBtn_0 = new QToolButton(KeyBwidget);
        tBtn_0->setObjectName(QString::fromUtf8("tBtn_0"));
        tBtn_0->setGeometry(QRect(685, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_0->sizePolicy().hasHeightForWidth());
        tBtn_0->setSizePolicy(sizePolicy);
        tBtn_0->setFont(font4);
        tBtn_0->setFocusPolicy(Qt::NoFocus);
        tBtn_0->setAutoRepeat(true);
        tBtn_3 = new QToolButton(KeyBwidget);
        tBtn_3->setObjectName(QString::fromUtf8("tBtn_3"));
        tBtn_3->setGeometry(QRect(160, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_3->sizePolicy().hasHeightForWidth());
        tBtn_3->setSizePolicy(sizePolicy);
        tBtn_3->setFont(font4);
        tBtn_3->setFocusPolicy(Qt::NoFocus);
        tBtn_3->setAutoRepeat(true);
        tBtn_del = new QToolButton(KeyBwidget);
        tBtn_del->setObjectName(QString::fromUtf8("tBtn_del"));
        tBtn_del->setGeometry(QRect(760, 10, 136, 60));
        sizePolicy.setHeightForWidth(tBtn_del->sizePolicy().hasHeightForWidth());
        tBtn_del->setSizePolicy(sizePolicy);
        tBtn_del->setMinimumSize(QSize(0, 0));
        tBtn_del->setFont(font4);
        tBtn_del->setFocusPolicy(Qt::NoFocus);
        tBtn_del->setAutoRepeat(true);
        tBtn_2 = new QToolButton(KeyBwidget);
        tBtn_2->setObjectName(QString::fromUtf8("tBtn_2"));
        tBtn_2->setGeometry(QRect(85, 10, 60, 60));
        sizePolicy.setHeightForWidth(tBtn_2->sizePolicy().hasHeightForWidth());
        tBtn_2->setSizePolicy(sizePolicy);
        tBtn_2->setFont(font4);
        tBtn_2->setFocusPolicy(Qt::NoFocus);
        tBtn_2->setAutoRepeat(true);

        retranslateUi(DataFilter);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DataFilter);
    } // setupUi

    void retranslateUi(QWidget *DataFilter)
    {
        DataFilter->setWindowTitle(QApplication::translate("DataFilter", "Form", 0, QApplication::UnicodeUTF8));
        lineEditCanId->setText(QString());
        lb_end->setText(QApplication::translate("DataFilter", "\347\273\223\346\235\237\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        checkBoxLoop->setText(QApplication::translate("DataFilter", "\345\233\236\350\267\257", 0, QApplication::UnicodeUTF8));
        lineEditLoop->setText(QString());
        dTEditStart->setDisplayFormat(QApplication::translate("DataFilter", "yyyy/MM/dd hh:mm:ss", 0, QApplication::UnicodeUTF8));
        lb_start->setText(QApplication::translate("DataFilter", "\350\265\267\345\247\213\346\227\266\351\227\264:", 0, QApplication::UnicodeUTF8));
        checkBoxCanId->setText(QApplication::translate("DataFilter", "\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        tBtnOk->setText(QApplication::translate("DataFilter", "\347\241\256\350\256\244", 0, QApplication::UnicodeUTF8));
        tBtnBack->setText(QApplication::translate("DataFilter", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("DataFilter", " \346\225\260\346\215\256\347\255\233\351\200\211", 0, QApplication::UnicodeUTF8));
        tBtnAllError->setText(QApplication::translate("DataFilter", "\345\205\250\351\203\250\n"
"\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        tBtnErrorPha->setText(QApplication::translate("DataFilter", "\350\212\202\347\202\271\351\224\231\347\233\270", 0, QApplication::UnicodeUTF8));
        tBtnOverVol->setText(QApplication::translate("DataFilter", "\350\212\202\347\202\271\350\277\207\345\216\213", 0, QApplication::UnicodeUTF8));
        tBtnLostPow->setText(QApplication::translate("DataFilter", "\347\224\265\346\272\220\344\270\255\346\226\255", 0, QApplication::UnicodeUTF8));
        tBtnLackVol->setText(QApplication::translate("DataFilter", "\350\212\202\347\202\271\346\254\240\345\216\213", 0, QApplication::UnicodeUTF8));
        tBtnOverCur->setText(QApplication::translate("DataFilter", "\350\212\202\347\202\271\350\277\207\346\265\201", 0, QApplication::UnicodeUTF8));
        tBtnLostPha->setText(QApplication::translate("DataFilter", "\350\212\202\347\202\271\347\274\272\347\233\270", 0, QApplication::UnicodeUTF8));
        tBtnError->setText(QApplication::translate("DataFilter", "\350\212\202\347\202\271\n"
"\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        tBtnAlarm->setText(QApplication::translate("DataFilter", "\350\212\202\347\202\271\n"
"\346\212\245\350\255\246", 0, QApplication::UnicodeUTF8));
        tBtnOffLine->setText(QApplication::translate("DataFilter", "\351\200\232\350\256\257\n"
"\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        tBtnHost->setText(QApplication::translate("DataFilter", "\344\270\273\346\234\272\n"
"\346\225\205\351\232\234", 0, QApplication::UnicodeUTF8));
        dTEditEnd->setDisplayFormat(QApplication::translate("DataFilter", "yyyy/MM/dd hh:mm:ss", 0, QApplication::UnicodeUTF8));
        tBtn_6->setText(QApplication::translate("DataFilter", "6", 0, QApplication::UnicodeUTF8));
        tBtn_9->setText(QApplication::translate("DataFilter", "9", 0, QApplication::UnicodeUTF8));
        tBtn_8->setText(QApplication::translate("DataFilter", "8", 0, QApplication::UnicodeUTF8));
        tBtn_7->setText(QApplication::translate("DataFilter", "7", 0, QApplication::UnicodeUTF8));
        tBtn_4->setText(QApplication::translate("DataFilter", "4", 0, QApplication::UnicodeUTF8));
        tBtn_5->setText(QApplication::translate("DataFilter", "5", 0, QApplication::UnicodeUTF8));
        tBtn_1->setText(QApplication::translate("DataFilter", "1", 0, QApplication::UnicodeUTF8));
        tBtn_0->setText(QApplication::translate("DataFilter", "0", 0, QApplication::UnicodeUTF8));
        tBtn_3->setText(QApplication::translate("DataFilter", "3", 0, QApplication::UnicodeUTF8));
        tBtn_del->setText(QApplication::translate("DataFilter", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        tBtn_2->setText(QApplication::translate("DataFilter", "2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DataFilter: public Ui_DataFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAFILTER_H
