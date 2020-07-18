/********************************************************************************
** Form generated from reading UI file 'screen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Screen
{
public:
    QLabel *lbColor;

    void setupUi(QWidget *Screen)
    {
        if (Screen->objectName().isEmpty())
            Screen->setObjectName(QString::fromUtf8("Screen"));
        Screen->resize(1024, 600);
        lbColor = new QLabel(Screen);
        lbColor->setObjectName(QString::fromUtf8("lbColor"));
        lbColor->setGeometry(QRect(0, 0, 1024, 600));

        retranslateUi(Screen);

        QMetaObject::connectSlotsByName(Screen);
    } // setupUi

    void retranslateUi(QWidget *Screen)
    {
        Screen->setWindowTitle(QApplication::translate("Screen", "Form", 0, QApplication::UnicodeUTF8));
        lbColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Screen: public Ui_Screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_H
