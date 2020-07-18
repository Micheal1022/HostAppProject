/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Record
{
public:
    QToolButton *tBtnQuery;
    QToolButton *tBtnFilter;
    QLabel *lb_count_3;
    QLabel *label_25;
    QToolButton *tBtnBack;
    QLabel *lbCountNum;
    QTableWidget *tableWgtRecord;
    QToolButton *tBtnDel;
    QToolButton *tBtnPrint;
    QLabel *lb_count_2;
    QToolButton *tBtnNest;
    QToolButton *tBtnLast;
    QLabel *label;
    QLabel *lbPageCount;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *lbPageCurrent;
    QToolButton *tBtnAllDel;

    void setupUi(QWidget *Record)
    {
        if (Record->objectName().isEmpty())
            Record->setObjectName(QString::fromUtf8("Record"));
        Record->resize(1024, 600);
        Record->setStyleSheet(QString::fromUtf8("QWidget#Record{\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton{\n"
"font: 12pt \"DejaVu Sans\";\n"
"color:rgb(15, 41, 68);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 12pt \"DejaVu Sans\";\n"
"color: rgb(180, 180, 180);\n"
"border:2px solid rgb(180, 180, 180);\n"
"border-radius:10px;\n"
"}\n"
"QLabel{\n"
"font: 16pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"}"));
        tBtnQuery = new QToolButton(Record);
        tBtnQuery->setObjectName(QString::fromUtf8("tBtnQuery"));
        tBtnQuery->setGeometry(QRect(765, 620, 120, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tBtnQuery->setFont(font);
        tBtnQuery->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/dataSearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnQuery->setIcon(icon);
        tBtnQuery->setIconSize(QSize(35, 35));
        tBtnQuery->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnFilter = new QToolButton(Record);
        tBtnFilter->setObjectName(QString::fromUtf8("tBtnFilter"));
        tBtnFilter->setGeometry(QRect(770, 535, 120, 60));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tBtnFilter->sizePolicy().hasHeightForWidth());
        tBtnFilter->setSizePolicy(sizePolicy);
        tBtnFilter->setFont(font);
        tBtnFilter->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/datafilter.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnFilter->setIcon(icon1);
        tBtnFilter->setIconSize(QSize(35, 35));
        tBtnFilter->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lb_count_3 = new QLabel(Record);
        lb_count_3->setObjectName(QString::fromUtf8("lb_count_3"));
        lb_count_3->setGeometry(QRect(980, 5, 30, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lb_count_3->setFont(font1);
        lb_count_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_count_3->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(Record);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, 0, 1024, 40));
        label_25->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color:rgb(0, 122, 165);\n"
""));
        tBtnBack = new QToolButton(Record);
        tBtnBack->setObjectName(QString::fromUtf8("tBtnBack"));
        tBtnBack->setGeometry(QRect(895, 535, 120, 60));
        tBtnBack->setFont(font);
        tBtnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon2);
        tBtnBack->setIconSize(QSize(35, 35));
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbCountNum = new QLabel(Record);
        lbCountNum->setObjectName(QString::fromUtf8("lbCountNum"));
        lbCountNum->setGeometry(QRect(905, 5, 70, 30));
        lbCountNum->setFont(font1);
        lbCountNum->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbCountNum->setAlignment(Qt::AlignCenter);
        tableWgtRecord = new QTableWidget(Record);
        tableWgtRecord->setObjectName(QString::fromUtf8("tableWgtRecord"));
        tableWgtRecord->setGeometry(QRect(5, 45, 1016, 485));
        tableWgtRecord->setFont(font);
        tableWgtRecord->setStyleSheet(QString::fromUtf8("QTableWidget{\n"
"font: 12pt DejaVu Sans;\n"
"gridline-color: rgb(0, 0, 0);\n"
"border:1px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QTableWidgetItem{\n"
"border:1px solid rgb(0, 0, 0);\n"
"}\n"
""));
        tableWgtRecord->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWgtRecord->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tBtnDel = new QToolButton(Record);
        tBtnDel->setObjectName(QString::fromUtf8("tBtnDel"));
        tBtnDel->setGeometry(QRect(200, 535, 190, 60));
        sizePolicy.setHeightForWidth(tBtnDel->sizePolicy().hasHeightForWidth());
        tBtnDel->setSizePolicy(sizePolicy);
        tBtnDel->setFont(font);
        tBtnDel->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/dataDel.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnDel->setIcon(icon3);
        tBtnDel->setIconSize(QSize(35, 35));
        tBtnDel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnPrint = new QToolButton(Record);
        tBtnPrint->setObjectName(QString::fromUtf8("tBtnPrint"));
        tBtnPrint->setGeometry(QRect(395, 535, 120, 60));
        tBtnPrint->setFont(font);
        tBtnPrint->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Image/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnPrint->setIcon(icon4);
        tBtnPrint->setIconSize(QSize(35, 35));
        tBtnPrint->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lb_count_2 = new QLabel(Record);
        lb_count_2->setObjectName(QString::fromUtf8("lb_count_2"));
        lb_count_2->setGeometry(QRect(825, 5, 80, 30));
        lb_count_2->setFont(font1);
        lb_count_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lb_count_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tBtnNest = new QToolButton(Record);
        tBtnNest->setObjectName(QString::fromUtf8("tBtnNest"));
        tBtnNest->setGeometry(QRect(645, 535, 120, 60));
        tBtnNest->setFont(font);
        tBtnNest->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Image/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnNest->setIcon(icon5);
        tBtnNest->setIconSize(QSize(35, 35));
        tBtnNest->setAutoRepeat(true);
        tBtnNest->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnLast = new QToolButton(Record);
        tBtnLast->setObjectName(QString::fromUtf8("tBtnLast"));
        tBtnLast->setGeometry(QRect(520, 535, 120, 60));
        tBtnLast->setFont(font);
        tBtnLast->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Image/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnLast->setIcon(icon6);
        tBtnLast->setIconSize(QSize(35, 35));
        tBtnLast->setAutoRepeat(true);
        tBtnLast->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        label = new QLabel(Record);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(825, 5, 80, 30));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbPageCount = new QLabel(Record);
        lbPageCount->setObjectName(QString::fromUtf8("lbPageCount"));
        lbPageCount->setGeometry(QRect(925, 5, 70, 30));
        lbPageCount->setFont(font1);
        lbPageCount->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbPageCount->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Record);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(990, 5, 30, 30));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Record);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(715, 5, 30, 30));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Record);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(555, 5, 80, 30));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbPageCurrent = new QLabel(Record);
        lbPageCurrent->setObjectName(QString::fromUtf8("lbPageCurrent"));
        lbPageCurrent->setGeometry(QRect(645, 5, 70, 30));
        lbPageCurrent->setFont(font1);
        lbPageCurrent->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lbPageCurrent->setAlignment(Qt::AlignCenter);
        tBtnAllDel = new QToolButton(Record);
        tBtnAllDel->setObjectName(QString::fromUtf8("tBtnAllDel"));
        tBtnAllDel->setGeometry(QRect(5, 535, 190, 60));
        sizePolicy.setHeightForWidth(tBtnAllDel->sizePolicy().hasHeightForWidth());
        tBtnAllDel->setSizePolicy(sizePolicy);
        tBtnAllDel->setFont(font);
        tBtnAllDel->setFocusPolicy(Qt::NoFocus);
        tBtnAllDel->setIcon(icon3);
        tBtnAllDel->setIconSize(QSize(35, 35));
        tBtnAllDel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbCountNum->raise();
        lb_count_3->raise();
        lb_count_2->raise();
        label_25->raise();
        tBtnQuery->raise();
        tBtnFilter->raise();
        tBtnBack->raise();
        tableWgtRecord->raise();
        tBtnDel->raise();
        tBtnPrint->raise();
        tBtnNest->raise();
        tBtnLast->raise();
        label->raise();
        lbPageCount->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        lbPageCurrent->raise();
        tBtnAllDel->raise();

        retranslateUi(Record);

        QMetaObject::connectSlotsByName(Record);
    } // setupUi

    void retranslateUi(QWidget *Record)
    {
        Record->setWindowTitle(QApplication::translate("Record", "Form", 0, QApplication::UnicodeUTF8));
        tBtnQuery->setText(QApplication::translate("Record", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        tBtnFilter->setText(QApplication::translate("Record", "\347\255\233\351\200\211", 0, QApplication::UnicodeUTF8));
        lb_count_3->setText(QApplication::translate("Record", "\346\235\241", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("Record", " \345\216\206\345\217\262\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
        tBtnBack->setText(QApplication::translate("Record", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        lbCountNum->setText(QString());
        tBtnDel->setText(QApplication::translate("Record", "\351\200\211\346\213\251\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        tBtnPrint->setText(QApplication::translate("Record", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        lb_count_2->setText(QApplication::translate("Record", "\345\205\261", 0, QApplication::UnicodeUTF8));
        tBtnNest->setText(QApplication::translate("Record", "\344\270\213\351\241\265", 0, QApplication::UnicodeUTF8));
        tBtnLast->setText(QApplication::translate("Record", "\344\270\212\351\241\265", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Record", "\345\205\261", 0, QApplication::UnicodeUTF8));
        lbPageCount->setText(QString());
        label_2->setText(QApplication::translate("Record", "\351\241\265", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Record", "\351\241\265", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Record", "\347\254\254", 0, QApplication::UnicodeUTF8));
        lbPageCurrent->setText(QString());
        tBtnAllDel->setText(QApplication::translate("Record", "\345\205\250\351\203\250\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Record: public Ui_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
