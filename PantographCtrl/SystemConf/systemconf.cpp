#include "systemconf.h"
#include "ui_systemconf.h"
#include "includes.h"

#define DATASIZE    9
SystemConf::SystemConf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemConf)
{
    ui->setupUi(this);
    setGeometry(0,0,1024,600);
    setWindowFlags(Qt::FramelessWindowHint);
    initKey();
    initConnect();
}

SystemConf::~SystemConf()
{
    delete ui;
}

void SystemConf::systemConfData(QList<int> dataList)
{
    slotSystemConfData(dataList);
}

void SystemConf::initKey()
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

void SystemConf::initConnect()
{
    connect(ui->tBtnOk,SIGNAL(clicked(bool)),this,SLOT(slotBtnOk()));
    connect(ui->tBtnBack,SIGNAL(clicked(bool)),this,SLOT(slotBtnBack()));
    connect(ui->tBtnSysTimeOk,SIGNAL(clicked(bool)),this,SLOT(slotSetSystemTime()));
    connect(ui->tBtnCalibration,SIGNAL(clicked(bool)),this,SLOT(slotCalibration()));
}

void SystemConf::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

void SystemConf::slotBtnOk()
{
    QByteArray byteArray;
    SystemConfData(byteArray);
    if (byteArray.size() == DATASIZE) {
        emit sigSystemConfData(byteArray);
    }
}

void SystemConf::slotBtnBack()
{
    this->hide();
}

void SystemConf::slotBtnKey(int index)
{
    QString text = m_btnKeyGroup->button(index)->text();
    if (index == 10) {
        if (focusWidget()->inherits("QLineEdit")) {
            qobject_cast<QLineEdit*>(focusWidget())->clear();
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

void SystemConf::slotSystemConfData(QList<int> dataList)
{
    //    uint cmd = dataList.at(DATA_CMD);
    //    if (GETCONF != cmd) {
    //        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据命令错误！！！"),tr("关闭"));
    //        return;
    //    }

    //    uint len = dataList.at(DATA_LEN);
    //    if (DATASIZE != len) {
    //        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据长度错误！！！"),tr("关闭"));
    //        return;
    //    }

    uint mode = dataList.at(CONF_MODE);
    switch (mode) {
    case AUTOMODE:
        ui->rBtnAutoMode->setChecked(true);
        break;
    case MANUALMODE:
        ui->rBtnManualMode->setChecked(true);
        break;
    case REPAIRMODE:
        ui->rBtnRepairMode->setChecked(true);
        break;
    }

    uint p_1 = dataList.at(CONF_PH);
    p_1 = (p_1 << 8) | dataList.at(CONF_PL);
    ui->lineEditP_1->setText(QString::number(p_1));
    uint ls = dataList.at(CONF_LS);
    ui->lineEditLS->setText(QString::number(ls));
    uint ms = dataList.at(CONF_MS);
    ui->lineEditMS->setText(QString::number(ms));
    uint hs = dataList.at(CONF_HS);
    ui->lineEditHS->setText(QString::number(hs));
    uint mt = dataList.at(CONF_MT);
    ui->lineEditMT->setText(QString::number(mt));
    uint st = dataList.at(CONF_ST);
    ui->lineEditST->setText(QString::number(st));
    uint rt = dataList.at(CONF_RT);
    ui->lineEditRT->setText(QString::number(rt));
    emit sigReplayData(GETCONF);


}

void SystemConf::slotReplay()
{
    MsgBox::showInformation(NULL,tr("配置提示"),tr("参数配置成功！！！"),tr("关闭"));
}

void SystemConf::SystemConfData(QByteArray &byteArray)
{
    //模式
    if (ui->rBtnManualMode->isChecked()) {
        byteArray.append(MANUALMODE);
    } else if (ui->rBtnAutoMode->isChecked()) {
        byteArray.append(AUTOMODE);
    } else if (ui->rBtnRepairMode->isChecked()) {
        byteArray.append(REPAIRMODE);
    }
    //压力
    uint p_1 = ui->lineEditP_1->text().toUInt();
    if (1000 < p_1) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("最大压力1参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (p_1 >> 8) & 0xFF;
        uchar data_L = p_1 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    //低速档位
    uchar ls = ui->lineEditLS->text().toUInt();
    if (0 == ls || 3 < ls) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("低速档位参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(ls);
    }
    //中速档位
    uchar ms = ui->lineEditMS->text().toUInt();
    if (3 > ms || 5 < ms) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("中速档位参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(ms);
    }
    //高速档位
    uchar hs = ui->lineEditHS->text().toUInt();
    if (5 > hs || 7 < hs) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("高速档位参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(hs);
    }
    //手动时间2-6
    uint mt = ui->lineEditMT->text().toUInt();
    if (2 > mt || 6 < mt) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("手动时间参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(mt);
    }
    //起停时间1-5
    uint st = ui->lineEditST->text().toUInt();
    if (1 > st || 5 < st) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("起停时间参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(st);
    }
    //运行时间5-8
    uint rt = ui->lineEditRT->text().toUInt();
    if (5 > rt || 8 < rt) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("运行时间参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(rt);
    }

}

void SystemConf::slotSetSystemTime()
{
    if(ui->lineEditYear->text().isEmpty()  || ui->lineEditMonth->text().isEmpty() ||
            ui->lineEditDay->text().isEmpty()   || ui->lineEditHour->text().isEmpty()  ||
            ui->lineEditMinute->text().isEmpty())
    {
        MsgBox::showInformation(NULL,tr("操作提示"), tr("日期/时间设置不能为空！"),tr("确定"));
        return;
    }
    int year,month,date,hour,minute,second;

    year  = ui->lineEditYear->text().toInt();
    month = ui->lineEditMonth->text().toInt();
    date  = ui->lineEditDay->text().toInt();

    if (month == 0 || month > 12) {
        MsgBox::showInformation(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
        return;
    }

    if (date == 0 || date > 31) {
        MsgBox::showInformation(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
        return;
    }
    switch (month) {
    case 2:
        //是闰年
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            if(date > 29) {
                MsgBox::showInformation(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
                return;
            }
        } else {
            if(date > 28) {
                MsgBox::showInformation(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
                return;
            }
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (date > 30) {
            MsgBox::showInformation(NULL,tr("操作提示"), tr("日期设置错误！"),tr("确定"));
            return;
        }
        break;
    }

    hour  = ui->lineEditHour->text().toInt();
    minute= ui->lineEditMinute->text().toInt();
    second = ui->lineEditSecond->text().toInt();

    if(hour > 23 || ui->lineEditHour->text().isEmpty() == true) {
        MsgBox::showInformation(NULL,tr("操作提示"), tr("时间设置错误！"),tr("确定"));
        return;
    }

    if (minute > 59 || ui->lineEditMinute->text().isEmpty() == true) {
        MsgBox::showInformation(NULL,tr("操作提示"), tr("时间设置错误！"),tr("确定"));
        return;
    }

    if (ui->lineEditSecond->text().isEmpty() == true) {
        second = 0;
    } else {
        if (second > 59) {
            MsgBox::showInformation(NULL,tr("操作提示"), tr("时间设置错误！"),tr("确定"));
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
        MsgBox::showInformation(this,tr("操作提示"), tr("时间修改失败！"),tr("确定"));
        return;
    }

    if (stime(&time) == 0) {
        ::system("hwclock -w");
        MsgBox::showInformation(this,tr("操作提示"), tr("时间修改成功！"),tr("确定"));
    } else {
        MsgBox::showInformation(this,tr("操作提示"), tr("时间修改失败！"),tr("确定"));
    }
}

void SystemConf::slotCalibration()
{
    QProcess process;
    process.start("/usr/local/tslib/bin/ts_calibrate");
    process.waitForStarted();
    process.waitForFinished(-1);
    repaint();
    MsgBox::showInformation(NULL,tr("系统提示"),tr("完成屏幕校准."),tr("关闭"));

}


