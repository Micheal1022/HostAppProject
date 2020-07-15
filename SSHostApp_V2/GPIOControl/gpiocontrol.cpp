#include "gpiocontrol.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <string.h>
#include "includes.h"
#include "SQLite/mysqlite.h"

/*
            𝑮𝑷𝑰𝑶排列序号=(𝑩𝑨𝑵𝑲−𝟏)×𝟑𝟐+𝑵
在公式中BANK为GPIO引脚所在的BANK，N则为引脚在该个BANK中的序号。
P3.4为例，其BANK值为3，N值为4，因此排列序号为(3-1)*32+4=68。
控制输出
GPIO4_21    GPIO117    报警
GPIO4_21    GPIO118    故障
GPIO4_23    GPIO119    通讯
GPIO4_24    GPIO120    主电正常
GPIO4_25    GPIO121    主电故障
GPIO4_26    GPIO122    备电正常
GPIO4_27    GPIO123    备电故障
控制输入
GPIO4_22    GPIO124    复位信号高电位
GPIO1_05    GPIO5      主电信号
GPIO1_09    GPIO9      备电信号
继电器K1,K2 高电平导通
GPIO251    继电器1
GPIO252    继电器2
GPIO253    蜂鸣器高开低关
GPIO254    高故障-低报警
*/

const char *out = "out";
const char *in  = "in";
const char *high= "1";
const char *low = "0";
/*
 *写操作引脚
*/
//报警
const char *ledAlarmValue =        "/sys/class/gpio/gpio119/value";
//故障
const char *ledErrorValue =        "/sys/class/gpio/gpio118/value";
//通讯
const char *ledCanValue =          "/sys/class/gpio/gpio117/value";
//主电正常
const char *ledMainNormalValue =   "/sys/class/gpio/gpio121/value";
//主电故障
const char *ledMainErrorValue =    "/sys/class/gpio/gpio120/value";
//备电正常
const char *ledBackupNormalValue = "/sys/class/gpio/gpio123/value";
//备电故障
const char *ledBackupErrorValue =  "/sys/class/gpio/gpio122/value";
/*****************************************************************/
//继电器K1 高电平导通
const char *ledRelay_1Value = "/sys/class/gpio/gpio251/value";
//继电器K2 高电平导通
const char *ledRelay_2Value = "/sys/class/gpio/gpio252/value";
//蜂鸣器 low-open high-close
const char *buzzValue =       "/sys/class/gpio/gpio253/value";
//声音类型 low-alarm high-error
const char *buzzTypeValue =   "/sys/class/gpio/gpio254/value";
/*
 *读操作引脚
*/
//主电状态  低电平正常，高电平故障
const char *mainPowerValue = "/sys/class/gpio/gpio5/value";
//备电状态  高电平正常，低电平故障
const char *backupPowerValue = "/sys/class/gpio/gpio18/value";
//复位信号
const char *btnResetValue = "/sys/class/gpio/gpio124/value";

/*
 *控制引脚类
* @项目   TBus_SSEF
* @函数   void initpin(char *dev, char *devValue, char *devDirection)
* @描述   初始化引脚
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
GPIOPin::GPIOPin()
{
    m_fdVal    = -1;
}


void GPIOPin::initPin(const char *devValue)
{
    m_fdVal = open(devValue, O_RDWR);           //打开输入输出电平值设备
}

/*
* @项目   TBus_SSEF
* @函数   void writePin(char *buf);
* @描述   写入数值高低
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
void GPIOPin::writePin(const char *buf)
{
    write(m_fdVal, buf, sizeof(buf));	// 写输入电平值
}
/*
* @项目   TBus_SSEF
* @函数   void readPin(char *buf);
* @描述   读入数值高低
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
void GPIOPin::readPin(char *buf,const char *devValue)
{
    int fdVal = open(devValue, O_RDWR);
    read(fdVal, buf, sizeof(buf));// 读出电平值
    close(fdVal);
}


GPIOControl::GPIOControl(QObject *parent) : QObject(parent)
{
    initVar();
    initPins();
    defaultState();
}
/*
* @项目   TBus_SSEF
* @函数   void initVar();
* @描述   初始化
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
void GPIOControl::initVar()
{
    m_mainPower = true;
    m_backPower = true;
    m_mainPowerFlag   = false;
    m_backPowerFlag   = false;
    m_mainPowerInsert = false;
    m_backPowerInsert = false;
    m_mainPowerErrorTimes = 0;
    m_mainPowerNormalTimes = 0;
    m_backPowerErrorTimes = 0;
    m_backPowerNormalTimes = 0;
}

void GPIOControl::defaultState()
{
    controlPin(MPOWERNORMAL);
    controlPin(BPOWERNORMAL);
    controlPin(CANBUS_OFF);
    controlPin(BUZZ_OFF);
    controlPin(ERRORLED_OFF);
    controlPin(ALARMLED_OFF);
    controlPin(RELAY_1_OFF);
    controlPin(RELAY_2_OFF);

}
/*
* @项目   TBus_SSEF
* @函数   void controlPin(int type);
* @描述   控制引脚状态
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/

void GPIOControl::controlPin(int type)
{
    switch (type) {
    case MPOWERNORMAL:
        m_mainPowerNormalLed->writePin(high);
        m_mainPowerErrorLed->writePin(low);
        break;
    case MPOWERERROR:
        m_mainPowerNormalLed->writePin(low);
        m_mainPowerErrorLed->writePin(high);
        break;
    case BPOWERNORMAL:
        m_backPowerNormalLed->writePin(high);
        m_backPowerErrorLed->writePin(low);
        break;
    case BPOWERERROR:
        m_backPowerNormalLed->writePin(low);
        m_backPowerErrorLed->writePin(high);
        break;
    case CANBUS_ON:
        m_canLed->writePin(high);
        break;
    case CANBUS_OFF:
        m_canLed->writePin(low);
        break;
    case BUZZ_ON:
        m_buzzSwitch->writePin(low);
        break;
    case BUZZ_OFF:
        m_buzzSwitch->writePin(high);
        break;
    case ERRORLED_ON:
        m_errorled->writePin(high);
        break;
    case ERRORLED_OFF:
        m_errorled->writePin(low);
        break;
    case ALARMLED_ON:
#ifdef  BEVONE
        m_alarmLed->writePin(high);
#elif   SENSOR
        m_backPowerNormalLed->writePin(high);
#endif
        break;
    case ALARMLED_OFF:
#ifdef  BEVONE
        m_alarmLed->writePin(low);
#elif   SENSOR
        m_backPowerNormalLed->writePin(low);
#endif
        break;
    case ERRORBUZZ:
        m_buzzSwitch->writePin(low);
        m_buzzType->writePin(high);
        break;
    case ALARMBUZZ:
        m_buzzSwitch->writePin(low);
        m_buzzType->writePin(low);
        break;
    case RELAY_1_ON:
        m_Relay_1->writePin(high);
        break;
    case RELAY_1_OFF:
        m_Relay_1->writePin(low);
        break;
    case RELAY_2_ON:
        m_Relay_2->writePin(high);
        break;
    case RELAY_2_OFF:
        m_Relay_2->writePin(low);
        break;
    case SYSTEM_ON:
        m_alarmLed->writePin(high);
        break;
    case SYSTEM_OFF:
        m_alarmLed->writePin(low);
        break;
    }
}
/*
* @项目   TBus_SSEF
* @函数   void readPinState(int type);
* @描述   读取引脚状态
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
char GPIOControl::readPinState(int type)
{
    char buf[2]={'0','0'};
    switch(type) {
    case MPOWERSTATE://主电
        m_mainPowerState->readPin(buf,mainPowerValue);
        break;
    case BPOWERSTATE://备电
        m_backPowerState->readPin(buf,backupPowerValue);
        break;
    case RESETBTNSTATE://复位
        m_resetBtn->readPin(buf,btnResetValue);
        break;
    }
    return buf[0];
}
/*
* @项目   TBus_SSEF
* @函数   void controlBuzzType(int type);
* @描述   控制声音类型
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
void GPIOControl::controlBuzzType(int type)
{
    /*
     * 高-消音;低-蜂鸣;
     * 高-故障;低-报警
     */
    switch (type) {
    case S_NORAML://正常
        controlPin(BUZZ_OFF);
        break;
    case S_ERROR: //故障
        controlPin(BUZZ_ON);
        controlPin(ERRORBUZZ);
        break;
    case S_ALARM: //报警
        controlPin(BUZZ_ON);
        controlPin(ALARMBUZZ);
        break;
    }
}
/*
* @项目   TBus_SSEF
* @函数   void controlSelfCheck(int type)
* @描述   自检指示灯蜂鸣
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
void GPIOControl::controlSelfCheck(int type)
{

    switch (type) {
    case 1:
        defaultState();
        controlPin(BUZZ_ON);
        controlPin(ERRORBUZZ);
        controlPin(MPOWERERROR);
        break;
    case 2:
        controlPin(MPOWERNORMAL);
        break;
    case 3:
        controlPin(BPOWERERROR);
        break;
    case 4:
        controlPin(BPOWERNORMAL);
        break;
    case 5:
        controlPin(CANBUS_ON);
        break;
    case 6:
        controlPin(ALARMBUZZ);
        controlPin(CANBUS_OFF);
        break;
    case 7:
        controlPin(ERRORLED_ON);
        break;
    case 8:
        controlPin(ERRORLED_OFF);
        break;
    case 9:
#ifdef  BEVONE
        controlPin(ALARMLED_ON);
#elif   SENSOR
        controlPin(SYSTEM_ON);
#endif
        controlPin(RELAY_1_ON);
        break;
    case 10:

#ifdef  BEVONE
        controlPin(ALARMLED_OFF);
#elif   SENSOR
        controlPin(SYSTEM_OFF);
#endif
        controlPin(BUZZ_OFF);
        controlPin(RELAY_1_OFF);
        break;
    }
}
/*
* @项目   TBus_SSEF
* @函数   bool mainPowerTest();
* @描述   主电检测,主电正常返回-true，主电故障返回-false
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
bool GPIOControl::mainPowerTest()
{
    //主电检测
    int mainPowerState = readPinState(MPOWERSTATE);
    if (mainPowerState == '1') {
        m_mainPowerNormalTimes++;
        if (m_mainPowerNormalTimes == TESTTIMES) {
            m_mainPowerNormalTimes = 0;
            m_mainPowerErrorTimes = 0;
            m_mainPowerInsert = false;
            controlPin(MPOWERNORMAL);
            m_mainPower = true;
        }

    } else {
        m_mainPowerErrorTimes++;
        if (m_mainPowerErrorTimes == TESTTIMES) {
            m_mainPowerNormalTimes = 0;
            m_mainPowerErrorTimes = 0;
            if(m_mainPowerInsert == false) {
                m_mainPowerInsert = true;
                QSqlDatabase db  = MySQLite::openConnection();
                MySQLite::insertErrorInfo(0,N_HOST,N_MAINPOW,0,0,QDateTime::currentDateTime().toTime_t(),tr("消防中控室"));
                MySQLite::closeConnection(db);
            }
            m_mainPower = false;
            controlPin(ERRORLED_ON);
            controlPin(MPOWERERROR);
        }
    }
    return m_mainPower;
}
/*
* @项目   TBus_SSEF
* @函数   bool backPowertest();
* @描述   备电检测
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
bool GPIOControl::backPowertest()
{
    //备电检测
    int backPowerState = readPinState(BPOWERSTATE);
    if (backPowerState == '0') {
        m_backPowerNormalTimes++;
        if (m_backPowerNormalTimes == TESTTIMES) {
            m_backPowerErrorTimes = 0;
            m_backPowerNormalTimes = 0;
            m_backPowerInsert = false;
            controlPin(BPOWERNORMAL);
            m_backPower = true;
        }
    } else {
        m_backPowerErrorTimes++;
        if (m_backPowerErrorTimes == TESTTIMES) {
            m_backPowerErrorTimes = 0;
            m_backPowerNormalTimes = 0;
            if (m_backPowerInsert == false) {
                m_backPowerInsert = true;
                QSqlDatabase db  = MySQLite::openConnection();
                MySQLite::insertErrorInfo(0,N_HOST,N_BACKPOW,0,0,QDateTime::currentDateTime().toTime_t(),tr("消防中控室"));
                MySQLite::closeConnection(db);
            }
            m_backPower = false;
            controlPin(ERRORLED_ON);
            controlPin(BPOWERERROR);
        }
    }
    return m_backPower;
}



void GPIOControl::insertErrorInfo(int loop, int type, int state, int canId, int value, uint time, QString area)
{
    //删除最小的rowid
    //select count(*) from RECORD;
    //delete from CONFLOOP where rowid = (select min(rowid) from RECORD);
    QSqlDatabase db  = MySQLite::openConnection();
    //如果数目到达10000条后数据删除最小ROWID的记录
    int count = MySQLite::getRowCount(db,QString("select count(*) from RECORD;"));
    if (count == MAXNUM) {
        MySQLite::coverRecord(db);
    }

    QString loopStr  = QString::number(loop);
    QString canIdStr = QString::number(canId);
    QString typeStr  = QString::number(type);
    QString stateStr = QString::number(state);
    QString valueStr = QString::number(value);
    QString timeStr  = QString::number(time);
    QString sql = "insert into RECORD values(";
    sql += loopStr+","+canIdStr+","+typeStr+","+stateStr+","+valueStr+","+timeStr+",'"+area+"');";
    QSqlQuery query(db);
    if (!query.exec(sql)) {
        MySQLite::closeConnection(db);
    }
    MySQLite::closeConnection(db);
    query.finish();
    query.clear();
}
/*
* @项目   TBus_SSEF
* @函数   bool resetBtnTest(bool state);
* @描述   复位按键检测状态
* @作者   Micheal(陈明明)
* @时间   2019-04-28
*/
bool GPIOControl::resetBtnTest()
{
    int resetState = readPinState(RESETBTNSTATE);
    if(resetState == '0') {
        return true;
    }
    return false;
}

/*
* @项目   TBus_SSEF
* @函数   void initPins();
* @描述   初始化所有引脚
* @作者   Micheal(陈明明)
* @时间   2019-04-26
*/
void GPIOControl::initPins()
{
    /*写入状态*/
    m_mainPowerNormalLed = new GPIOPin;
    m_mainPowerNormalLed->initPin(ledMainNormalValue);
    m_mainPowerErrorLed = new GPIOPin;
    m_mainPowerErrorLed->initPin(ledMainErrorValue);
    m_backPowerNormalLed = new GPIOPin;
    m_backPowerNormalLed->initPin(ledBackupNormalValue);
    m_backPowerErrorLed = new GPIOPin;
    m_backPowerErrorLed->initPin(ledBackupErrorValue);

    m_alarmLed = new GPIOPin;
    m_alarmLed->initPin(ledAlarmValue);
    m_errorled = new GPIOPin;
    m_errorled->initPin(ledErrorValue);
    m_canLed = new GPIOPin;
    m_canLed->initPin(ledCanValue);
    m_buzzSwitch = new GPIOPin;
    m_buzzSwitch->initPin(buzzValue);
    m_buzzType = new GPIOPin;
    m_buzzType->initPin(buzzTypeValue);
    m_Relay_1 = new GPIOPin;
    m_Relay_1->initPin(ledRelay_1Value);
    m_Relay_2 = new GPIOPin;
    m_Relay_2->initPin(ledRelay_2Value);

    m_resetBtn = new GPIOPin;
    m_resetBtn->initPin(btnResetValue);
    m_mainPowerState  = new GPIOPin;
    m_mainPowerState->initPin(mainPowerValue);
    m_backPowerState = new GPIOPin;
    m_backPowerState->initPin(backupPowerValue);

}
