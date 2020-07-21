#include "nodevalue_ef.h"
#include "ui_nodevalue_ef.h"
#include "includes.h"
#include <QDebug>
#define TIMES   10
#define VALUE   20

NodeValue_EF::NodeValue_EF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NodeValue_EF)
{
    ui->setupUi(this);
    m_labelList.append(ui->lb_result01);
    m_labelList.append(ui->lb_result02);
    m_labelList.append(ui->lb_result03);
    m_labelList.append(ui->lb_result04);
    m_labelList.append(ui->lb_result05);
    m_labelList.append(ui->lb_result06);
    m_labelList.append(ui->lb_result07);
    m_labelList.append(ui->lb_result08);
    m_labelList.append(ui->lb_result09);
    m_labelList.append(ui->lb_result10);
    m_labelList.append(ui->lb_result11);
    m_labelList.append(ui->lb_result12);
    clearValue();
}

NodeValue_EF::~NodeValue_EF()
{
    delete ui;
}

void NodeValue_EF::updateValue(QList<int> valueList)
{

    qDebug()<<"dataList : "<<valueList;
//    int loop    = dataList.value(LOOP);
//    int type    = dataList.value(TYPE);
//    int state   = dataList.value(STATE);
//    int canId   = dataList.value(CANID);
//    int value_1 = dataList.value(VALUE_1);
//    int value_2 = dataList.value(VALUE_2);
//    int value_3 = dataList.value(VALUE_3);
//    int pass    = dataList.value(PASS);
//    int pstate  = dataList.value(PSTATE);
//    int ptype   = dataList.value(PTYPE);

    int nodeAddr  = valueList.value(3);
    int nodeState = valueList.value(4);
    int nodeValue1= valueList.value(5);
    int nodeValue2= valueList.value(6);
    int nodePass  = valueList.value(8);
    int nodeType  = valueList.value(10);

    ui->lbAddrValue->setText(QString::number(nodeAddr));
    confNodeType(nodeType);
    confNodeState(nodeState);
    confNodeValue(nodePass,nodeType,nodeValue1,nodeValue2);
}

void NodeValue_EF::clearValue()
{
    m_baseLeakValue = 100;
    m_baseAlarmValue = 300;
    ui->lbAddrValue->clear();
    ui->lbTypeValue->clear();
    ui->lbStateValue->clear();
    ui->lcd_Leak01->display(0);    ui->lcd_Alarm01->display(0);     confResult(1, NodeValue_EF::ToBeTested);
    ui->lcd_Leak02->display(0);    ui->lcd_Alarm02->display(0);     confResult(2, NodeValue_EF::ToBeTested);
    ui->lcd_Leak03->display(0);    ui->lcd_Alarm03->display(0);     confResult(3, NodeValue_EF::ToBeTested);
    ui->lcd_Leak04->display(0);    ui->lcd_Alarm04->display(0);     confResult(4, NodeValue_EF::ToBeTested);
    ui->lcd_Leak05->display(0);    ui->lcd_Alarm05->display(0);     confResult(5, NodeValue_EF::ToBeTested);
    ui->lcd_Leak06->display(0);    ui->lcd_Alarm06->display(0);     confResult(6, NodeValue_EF::ToBeTested);
    ui->lcd_Leak07->display(0);    ui->lcd_Alarm07->display(0);     confResult(7, NodeValue_EF::ToBeTested);
    ui->lcd_Leak08->display(0);    ui->lcd_Alarm08->display(0);     confResult(8, NodeValue_EF::ToBeTested);
    ui->lcd_Leak09->display(0);    ui->lcd_Alarm09->display(0);     confResult(9, NodeValue_EF::ToBeTested);
    ui->lcd_Leak10->display(0);    ui->lcd_Alarm10->display(0);     confResult(10,NodeValue_EF::ToBeTested);
    ui->lcd_Leak11->display(0);    ui->lcd_Alarm11->display(0);     confResult(11,NodeValue_EF::ToBeTested);
    ui->lcd_Leak12->display(0);    ui->lcd_Alarm12->display(0);     confResult(12,NodeValue_EF::ToBeTested);
    m_testLeakTimes_01 = 0;        m_testLeakTimes_02 = 0;          m_testLeakTimes_03 = 0;         m_testLeakTimes_04 = 0;
    m_testLeakTimes_05 = 0;        m_testLeakTimes_06 = 0;          m_testLeakTimes_07 = 0;         m_testLeakTimes_08 = 0;
    m_testLeakTimes_09 = 0;        m_testLeakTimes_10 = 0;          m_testLeakTimes_11 = 0;         m_testLeakTimes_12 = 0;
    m_testLeakFlag_01 = true;
    m_testLeakFlag_02 = true;
    m_testLeakFlag_03 = true;
    m_testLeakFlag_04 = true;
    m_testLeakFlag_05 = true;
    m_testLeakFlag_06 = true;
    m_testLeakFlag_07 = true;
    m_testLeakFlag_08 = true;
    m_testLeakFlag_09 = true;
    m_testLeakFlag_10 = true;
    m_testLeakFlag_11 = true;
    m_testLeakFlag_12 = true;
}

void NodeValue_EF::confResult(int index, NodeValue_EF::RESULT type)
{
    index = index - 1;
    if (NodeValue_EF::Qualified == type) {
        m_labelList[index]->setText(tr("合格"));
        m_labelList[index]->setStyleSheet("color: rgb(55, 255, 20);");
    } else if (NodeValue_EF::Unqualified == type) {
        m_labelList[index]->setText(tr("不合格"));
        m_labelList[index]->setStyleSheet("color: rgb(255, 0, 0);");
    } else {
        m_labelList[index]->setText(tr("待测"));
        m_labelList[index]->setStyleSheet("color: rgb(255, 255, 255);");
    }
}

void NodeValue_EF::confNodeType(int nodeType)
{
    switch (nodeType) {
    case MOD_COMB:
        ui->lbTypeValue->setText(tr("L12T4"));
        break;
    case MOD_UNIT:
        ui->lbTypeValue->setText(tr("L1T4"));
        break;
    }
}

void NodeValue_EF::confNodeState(int nodeState)
{
    switch (nodeState) {
    case N_NORMAL:
        ui->lbStateValue->setText(tr("正常"));
        break;
    case N_ALARM:
        ui->lbStateValue->setText(tr("报警"));
        break;
    case N_ERROR:
        ui->lbStateValue->setText(tr("故障"));
        break;
    case N_OFFLINE:
        ui->lbStateValue->setText(tr("离线"));
        break;
    }
}

void NodeValue_EF::confNodeValue(int pass, int nodeType, int leakValue, int alarmValue)
{
    switch (pass) {
    case 1:

        if (N_LEAK == nodeType) {
            ui->lb_Leak01->setText(tr("漏电:"));
            ui->lb_LeakUnit01->setText(tr("mA"));
            ui->lb_AlarmUnit01->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak01->setText(tr("温度:"));
            ui->lb_LeakUnit01->setText(tr("℃"));
            ui->lb_AlarmUnit01->setText(tr("℃"));
        }
        ui->lcd_Leak01->display(leakValue);
        ui->lcd_Alarm01->display(alarmValue);

        if (m_testLeakFlag_01 == true) {
            if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04) && m_baseAlarmValue == alarmValue) {
                m_testLeakTimes_01++;
                if (m_testLeakTimes_01 == TIMENUM ) {
                    m_testLeakFlag_01 = false;
                    confResult(pass,NodeValue_EF::Qualified);
                }
            } else {
                m_testLeakFlag_01 = false;
                confResult(pass,NodeValue_EF::Unqualified);
            }
        }

        break;
    case 2:
        if (N_LEAK == nodeType) {
            ui->lb_Leak02->setText(tr("漏电:"));
            ui->lb_LeakUnit02->setText(tr("mA"));
            ui->lb_AlarmUnit02->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak02->setText(tr("温度:"));
            ui->lb_LeakUnit02->setText(tr("℃"));
            ui->lb_AlarmUnit02->setText(tr("℃"));
        }
        ui->lcd_Leak02->display(leakValue);
        ui->lcd_Alarm02->display(alarmValue);
        if (m_testLeakFlag_02 == true) {
            if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
                m_testLeakTimes_02++;
                if (m_testLeakTimes_02 == TIMENUM ) {
                    m_testLeakFlag_02 = false;
                    confResult(pass,NodeValue_EF::Qualified);
                }
            } else {
                m_testLeakFlag_02 = false;
                confResult(pass,NodeValue_EF::Unqualified);
            }
        }

        break;
    case 3:
        if (N_LEAK == nodeType) {
            ui->lb_Leak03->setText(tr("漏电:"));
            ui->lb_LeakUnit03->setText(tr("mA"));
            ui->lb_AlarmUnit03->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak03->setText(tr("温度:"));
            ui->lb_LeakUnit03->setText(tr("℃"));
            ui->lb_AlarmUnit03->setText(tr("℃"));
        }
        ui->lcd_Leak03->display(leakValue);
        ui->lcd_Alarm03->display(alarmValue);

        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_03++;
            if (m_testLeakTimes_03 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 4:
        if (N_LEAK == nodeType) {
            ui->lb_Leak04->setText(tr("漏电:"));
            ui->lb_LeakUnit04->setText(tr("mA"));
            ui->lb_AlarmUnit04->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak04->setText(tr("温度:"));
            ui->lb_LeakUnit04->setText(tr("℃"));
            ui->lb_AlarmUnit04->setText(tr("℃"));
        }
        ui->lcd_Leak04->display(leakValue);
        ui->lcd_Alarm04->display(alarmValue);

        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_04++;
            if (m_testLeakTimes_04 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 5:
        if (N_LEAK == nodeType) {
            ui->lb_Leak05->setText(tr("漏电:"));
            ui->lb_LeakUnit05->setText(tr("mA"));
            ui->lb_AlarmUnit05->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak05->setText(tr("温度:"));
            ui->lb_LeakUnit05->setText(tr("℃"));
            ui->lb_AlarmUnit05->setText(tr("℃"));
        }
        ui->lcd_Leak05->display(leakValue);
        ui->lcd_Alarm05->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_05++;
            if (m_testLeakTimes_05 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 6:
        if (N_LEAK == nodeType) {
            ui->lb_Leak06->setText(tr("漏电:"));
            ui->lb_LeakUnit06->setText(tr("mA"));
            ui->lb_AlarmUnit06->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak06->setText(tr("温度:"));
            ui->lb_LeakUnit06->setText(tr("℃"));
            ui->lb_AlarmUnit06->setText(tr("℃"));
        }
        ui->lcd_Leak06->display(leakValue);
        ui->lcd_Alarm06->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_06++;
            if (m_testLeakTimes_06 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 7:
        if (N_LEAK == nodeType) {
            ui->lb_Leak07->setText(tr("漏电:"));
            ui->lb_LeakUnit07->setText(tr("mA"));
            ui->lb_AlarmUnit07->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak07->setText(tr("温度:"));
            ui->lb_LeakUnit07->setText(tr("℃"));
            ui->lb_AlarmUnit07->setText(tr("℃"));
        }
        ui->lcd_Leak07->display(leakValue);
        ui->lcd_Alarm07->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_07++;
            if (m_testLeakTimes_07 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 8:
        if (N_LEAK == nodeType) {
            ui->lb_Leak08->setText(tr("漏电:"));
            ui->lb_LeakUnit08->setText(tr("mA"));
            ui->lb_AlarmUnit08->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak08->setText(tr("温度:"));
            ui->lb_LeakUnit08->setText(tr("℃"));
            ui->lb_AlarmUnit08->setText(tr("℃"));
        }
        ui->lcd_Leak08->display(leakValue);
        ui->lcd_Alarm08->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_08++;
            if (m_testLeakTimes_08 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 9:
        if (N_LEAK == nodeType) {
            ui->lb_Leak09->setText(tr("漏电:"));
            ui->lb_LeakUnit09->setText(tr("mA"));
            ui->lb_AlarmUnit09->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak09->setText(tr("温度:"));
            ui->lb_LeakUnit09->setText(tr("℃"));
            ui->lb_AlarmUnit09->setText(tr("℃"));
        }
        ui->lcd_Leak09->display(leakValue);
        ui->lcd_Alarm09->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_09++;
            if (m_testLeakTimes_09 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 10:
        if (N_LEAK == nodeType) {
            ui->lb_Leak10->setText(tr("漏电:"));
            ui->lb_LeakUnit10->setText(tr("mA"));
            ui->lb_AlarmUnit10->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak10->setText(tr("温度:"));
            ui->lb_LeakUnit10->setText(tr("℃"));
            ui->lb_AlarmUnit10->setText(tr("℃"));
        }
        ui->lcd_Leak10->display(leakValue);
        ui->lcd_Alarm10->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_10++;
            if (m_testLeakTimes_10 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }

        break;
    case 11:
        if (N_LEAK == nodeType) {
            ui->lb_Leak11->setText(tr("漏电:"));
            ui->lb_LeakUnit11->setText(tr("mA"));
            ui->lb_AlarmUnit11->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak11->setText(tr("温度:"));
            ui->lb_LeakUnit11->setText(tr("℃"));
            ui->lb_AlarmUnit11->setText(tr("℃"));
        }
        ui->lcd_Leak11->display(leakValue);
        ui->lcd_Alarm11->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_11++;
            if (m_testLeakTimes_11 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }
        break;
    case 12:
        if (N_LEAK == nodeType) {
            ui->lb_Leak12->setText(tr("漏电:"));
            ui->lb_LeakUnit12->setText(tr("mA"));
            ui->lb_AlarmUnit12->setText(tr("mA"));
        } else if (N_TEMP == nodeType) {
            ui->lb_Leak12->setText(tr("漏电:"));
            ui->lb_LeakUnit12->setText(tr("℃"));
            ui->lb_AlarmUnit12->setText(tr("℃"));
        }
        ui->lcd_Leak12->display(leakValue);
        ui->lcd_Alarm12->display(alarmValue);
        if (leakValue <= m_baseLeakValue*(1 + 0.04) && leakValue >= m_baseLeakValue*(1 - 0.04)) {
            m_testLeakTimes_12++;
            if (m_testLeakTimes_12 == TIMENUM ) {
                confResult(pass,NodeValue_EF::Qualified);
            }
        } else {
            confResult(pass,NodeValue_EF::Unqualified);
        }
        break;
    }
}


