#include "conftime.h"
#include "ui_conftime.h"
#include <time.h>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
ConfTime::ConfTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfTime)
{
    ui->setupUi(this);
    //系统时间
    initKey();
    QRegExp regExpYear("^20[1-3][0-9]$");
    ui->lineEditYear->setValidator(new QRegExpValidator(regExpYear, this));
    QRegExp regExpYeMonth("^[1-9]|(1[0-2])$");
    ui->lineEditMonth->setValidator(new QRegExpValidator(regExpYeMonth, this));
    QRegExp regExpDay("^([1-9])|([1-2][0-9])|(3[0-1])$");
    ui->lineEditDay->setValidator(new QRegExpValidator(regExpDay, this));
    QRegExp regExpYHour("^([0-9])|(1[0-9])|(2[0-3])$");
    ui->lineEditHour->setValidator(new QRegExpValidator(regExpYHour, this));
    QRegExp regExpminute("^([0-9])|([1-5][0-9])$");
    ui->lineEditMinute->setValidator(new QRegExpValidator(regExpminute, this));
    QRegExp regExpSecond("^([0-9])|([1-5][0-9])$");
    ui->lineEditSecond->setValidator(new QRegExpValidator(regExpSecond, this));


    m_timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotTimeOut()));
    m_timer->start(1000);
    connect(ui->tBtnSysTimeOk,SIGNAL(clicked(bool)),this,SLOT(slotSetSystemTime()));
}

ConfTime::~ConfTime()
{
    delete ui;
}

void ConfTime::initKey()
{
    m_btnKeyGroup = new QButtonGroup;
    m_btnKeyGroup->addButton(ui->tBtn_0,0);
    m_btnKeyGroup->addButton(ui->tBtn_1,1);
    m_btnKeyGroup->addButton(ui->tBtn_2,2);
    m_btnKeyGroup->addButton(ui->tBtn_3,3);
    m_btnKeyGroup->addButton(ui->tBtn_4,4);
    m_btnKeyGroup->addButton(ui->tBtn_5,5);
    m_btnKeyGroup->addButton(ui->tBtn_6,6);
    m_btnKeyGroup->addButton(ui->tBtn_7,7);
    m_btnKeyGroup->addButton(ui->tBtn_8,8);
    m_btnKeyGroup->addButton(ui->tBtn_9,9);
    m_btnKeyGroup->addButton(ui->tBtn_del,10);
    connect(m_btnKeyGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnKey(int)));
    for (int index = 0 ; index < m_btnKeyGroup->buttons().count(); index++) {
        setGraphicsEffect(new QGraphicsDropShadowEffect,m_btnKeyGroup->button(index));
    }
}

void ConfTime::getTime()
{
    QString timeStr = QDateTime::currentDateTime().toString(tr("yyyy年MM月dd日 hh:mm:ss"));
    ui->lbGetTime->setText(timeStr);
}

void ConfTime::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}
/*
* @项目   TBus_SSEF
* @函数   void slotSetSystemTime();
* @描述   设置系统时间
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void ConfTime::slotSetSystemTime()
{
    if(ui->lineEditYear->text().isEmpty()  || ui->lineEditMonth->text().isEmpty() ||
            ui->lineEditDay->text().isEmpty()   || ui->lineEditHour->text().isEmpty()  ||
            ui->lineEditMinute->text().isEmpty())
    {
        QMessageBox::information(this,tr("操作提示"), tr("日期/时间设置不能为空！"),tr("确定"));
        return;
    }
    int year,month,date,hour,minute,second;

    year  = ui->lineEditYear->text().toInt();
    month = ui->lineEditMonth->text().toInt();
    date  = ui->lineEditDay->text().toInt();

    if (month == 0 || month > 12) {
        QMessageBox::information(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
        return;
    }

    if (date == 0 || date > 31) {
        QMessageBox::information(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
        return;
    }
    switch (month) {
    case 2:
        //是闰年
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            if(date > 29) {
                QMessageBox::information(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
                return;
            }
        } else {
            if(date > 28) {
                QMessageBox::information(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
                return;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (date > 30) {
            QMessageBox::information(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
            return;
        }
        break;
    }

    hour  = ui->lineEditHour->text().toInt();
    minute= ui->lineEditMinute->text().toInt();
    second = ui->lineEditSecond->text().toInt();

    if(hour > 23 || ui->lineEditHour->text().isEmpty() == true) {
        QMessageBox::information(NULL,tr("操作提示"), tr("时间设置错误！"),tr("确定"));
        return;
    }

    if (minute > 59 || ui->lineEditMinute->text().isEmpty() == true) {
        QMessageBox::information(NULL,tr("操作提示"), tr("时间设置错误！"),tr("确定"));
        return;
    }

    if (ui->lineEditSecond->text().isEmpty() == true) {
        second = 0;
    } else {
        if (second > 59) {
            QMessageBox::information(NULL,tr("操作提示"), tr("时间设置错误！"),tr("确定"));
            return;
        }
    }

    time_t time;
    struct tm systemTime;
    systemTime.tm_year = year-1900;
    systemTime.tm_mon  = month-1;
    systemTime.tm_mday = date;
    systemTime.tm_hour = hour;
    systemTime.tm_min  = minute;
    systemTime.tm_sec  = second;
    time = mktime(&systemTime);
    if(time < 0) {
        QMessageBox::information(this,tr("操作提示"), tr("时间修改失败！"),tr("确定"));
        return;
    }

    if (stime(&time) == 0) {
        ::system("hwclock -w");
        QMessageBox::information(this,tr("操作提示"), tr("时间修改成功！"),tr("确定"));
    } else {
        QMessageBox::information(this,tr("操作提示"), tr("时间修改失败！"),tr("确定"));
    }
}

void ConfTime::slotBtnKey(int index)
{
    QString text = m_btnKeyGroup->button(index)->text();
    if (index == 10) {
        if (focusWidget() == NULL) {
            return;
        }
        if (focusWidget()->inherits("QLineEdit")) {
            QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
            edit->clear();
        }
    } else {
        if (focusWidget() == NULL) {
            return;
        }
        if (focusWidget()->inherits("QLineEdit")) {
            QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
            QString curStr = edit->text();
            edit->setText(curStr+text);
        }
    }
}

void ConfTime::slotTimeOut()
{
    getTime();
}
