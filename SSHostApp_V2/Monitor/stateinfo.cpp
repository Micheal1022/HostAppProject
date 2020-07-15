#include "stateinfo.h"
#include "ui_stateinfo.h"
#include <QDateTime>
#include <QDebug>
#include "includes.h"


StateInfo::StateInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StateInfo)
{
    ui->setupUi(this);
    setModal(true);
    hide();
    setWindowFlags(Qt::FramelessWindowHint);
    initConnect();
}

StateInfo::~StateInfo()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数   void showInfo(QList<QStringList> InfoList,InfoType type);
* @描述   显示信息窗口，配置链表信息
* @作者   Micheal(陈明明)
* @时间   2019-04-01
*/
void StateInfo::showInfo(QList<QStringList> InfoList,InfoType type)
{
    show();
    move(X_POS,Y_POS);
    m_count = 0;
    m_index = 0;
    m_InfoList = InfoList;
    m_count = InfoList.count();//链表总数
    if (m_count < 2) {
        ui->tBtnNestStrip->setEnabled(false);
        ui->tBtnLastStrip->setEnabled(false);
    }
    ui->lbCount->setText(QString::number(m_count));
    if (m_count > m_index) {
        currentIndexInfo(m_InfoList.value(m_index));
    }
    switch (type) {
    case AlarmInfo:
        setLabelAlarmVisible(true);
        ui->lbTitle->setText(tr(" 报警信息"));
        break;
    case ErrorInfo:
        setLabelAlarmVisible(false);
        ui->lbTitle->setText(tr(" 故障信息"));
        break;
    case PowerError:
        setLabelAlarmVisible(false);
        ui->lbTitle->setText(tr(" 故障信息"));
        break;
    case PowerLost:
        setLabelAlarmVisible(false);
        ui->lbTitle->setText(tr(" 电源中断"));
        break;
    case OffLine:
        setLabelAlarmVisible(false);
        ui->lbTitle->setText(tr(" 通讯故障"));
        break;
    }

}
/*
* @项目   TBus_SSEF
* @函数   void currentIndexInfo(QStringList infoList);
* @描述   显示当前索引的信息
* @作者   Micheal(陈明明)
* @时间   2019-04-01
*/
void StateInfo::currentIndexInfo(QStringList infoList)
{
    QString loopStr = infoList.value(INFO_LOOP);
    QString typeStr = infoList.value(INFO_TYPE);
    QString stateStr= infoList.value(INFO_STATE);
    QString idStr   = infoList.value(INFO_ID);
    QString valueStr= infoList.value(INFO_VALUE);
    QString timeStr = infoList.value(INFO_TIME);
    QString areaStr = infoList.value(INFO_AREA);

    ui->lbNodeAddr->setText(loopStr+"-"+idStr);/*节点类型*/
    int type = typeStr.toInt();
    switch (type) {
    case N_LEAK:
        ui->lbUnit->setText(tr("mA"));
        ui->lbType->setText(tr("漏电"));
        ui->lbAlarmValue->setText(valueStr);
        break;
    case N_TEMP:
        ui->lbUnit->setText(tr("℃"));
        ui->lbType->setText(tr("温度"));
        ui->lbAlarmValue->setText(valueStr);
        break;
    case N_ACV3:
        ui->lbType->setText(tr("三相电压"));
        break;
    case N_ACI3:
        ui->lbType->setText(tr("三相电流"));
        break;
    case N_ACV:
        ui->lbType->setText(tr("单相电压"));
        break;
    case N_ACI:
        ui->lbType->setText(tr("单相电流"));
        break;
    case N_DCV:
        ui->lbType->setText(tr("直流电压"));
        break;
    case N_DCI:
        ui->lbType->setText(tr("直流电流"));
        break;
    }
    int state = stateStr.toInt();/*节点状态*/
    switch (state) {
    case N_POWERLOST:
        ui->lbState->setText(tr("电源中断"));
        ui->lbState->setStyleSheet("color: rgb(255, 77, 70);");
        break;
    case N_OVERVOL:
        ui->lbState->setText(tr("节点过压"));
        ui->lbState->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    case N_OVERCUR:
        ui->lbState->setText(tr("过流故障"));
        ui->lbState->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    case N_UNDERVOL:
        ui->lbState->setText(tr("欠压故障"));
        ui->lbState->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    case N_LOSTPHASE:
        ui->lbState->setText(tr("缺相故障"));
        ui->lbState->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    case N_ERRORPHASE:
        ui->lbState->setText(tr("错相故障"));
        ui->lbState->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    case N_ERROR:
        ui->lbState->setText(tr("传感器故障"));
        ui->lbState->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    case N_ALARM:
        ui->lbState->setText(tr("通道报警"));
        ui->lbState->setStyleSheet("color: rgb(255, 77, 70);");
        break;
    case N_OFFLINE:
        ui->lbState->setText(tr("通讯故障"));
        ui->lbState->setStyleSheet("color: rgb(255, 255, 0);");
        break;
    }
    ui->lbArea->setText(areaStr);/*安装位置*/
    ui->lbTimeValue->setText(timeStr);/*报警时间*/

}
/*
* @项目   TBus_SSEF
* @函数   void setLabelAlarmVisible(bool visible);
* @描述   用于显示控制报警数值标签单位
* @作者   Micheal(陈明明)
* @时间   2019-04-02
*/
void StateInfo::setLabelAlarmVisible(bool visible)
{
    ui->lbUnit->setVisible(visible);
    ui->lbAlarm->setVisible(visible);
    ui->lbAlarmValue->setVisible(visible);
    visible ? ui->lbTime->setText(tr("报警时间:")): ui->lbTime->setText(tr("故障时间:"));

}

void StateInfo::initConnect()
{
    connect(ui->tBtnBack,SIGNAL(clicked(bool)),this,SLOT(slotHide()));
    connect(ui->tBtnLastStrip,SIGNAL(clicked(bool)),this,SLOT(slotLastStrip()));
    connect(ui->tBtnNestStrip,SIGNAL(clicked(bool)),this,SLOT(slotNestStrip()));
}
/*
* @项目   TBus_SSEF
* @函数   void slotClose();
* @描述   关闭窗口
* @作者   Micheal(陈明明)
* @时间   2019-04-01
*/
void StateInfo::slotHide()
{
    this->hide();
    m_InfoList.clear();
}
/*
* @项目   TBus_SSEF
* @函数   void slotLastStrip();
* @描述   上一条
* @作者   Micheal(陈明明)
* @时间   2019-04-01
*/
void StateInfo::slotLastStrip()
{
    m_index--;
    if(m_index > 0)
    {
        ui->tBtnNestStrip->setEnabled(true);
        currentIndexInfo(m_InfoList.value(m_index));
    }
    else if(m_index == 0)
    {
        ui->tBtnLastStrip->setEnabled(false);
        ui->tBtnNestStrip->setEnabled(true);
        currentIndexInfo(m_InfoList.value(m_index));
    }
}
/*
* @项目   TBus_SSEF
* @函数   void slotNestStrip();
* @描述   下一条
* @作者   Micheal(陈明明)
* @时间   2019-04-01
*/
void StateInfo::slotNestStrip()
{
    m_index++;
    if(m_index < m_count-1)
    {
        ui->tBtnLastStrip->setEnabled(true);
        currentIndexInfo(m_InfoList.value(m_index));
    }
    else if(m_index == m_count-1)
    {
        ui->tBtnNestStrip->setEnabled(false);
        ui->tBtnLastStrip->setEnabled(true);
        currentIndexInfo(m_InfoList.value(m_index));
    }
}

