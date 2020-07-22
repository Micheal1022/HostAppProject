#include "keycheck.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <string.h>
#include <QTimer>
#include <QDebug>
#define TIME 100
const char *in  = "in";
//复位信号
const char *btnResetValue = "/sys/class/gpio/gpio124/value";
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
KeyCheck::KeyCheck(QObject *parent) : QObject(parent)
{
    m_keyCheck = new GPIOKeyPin;
    m_keyCheck->initKeyPin(btnResetValue);
    m_timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotTimeOut()));
    m_timer->start(TIME);
}



char KeyCheck::readKeyState()
{
    char buf[2]={'0','0'};
    m_keyCheck->readKeyPin(buf,btnResetValue);
    return buf[0];
}

void KeyCheck::slotTimeOut()
{
    if(readKeyState() == '0') {
        emit sigkeyCheck();
    }
}

GPIOKeyPin::GPIOKeyPin()
{
    m_fdVal    = -1;
}

void GPIOKeyPin::initKeyPin(const char *devValue)
{
    //打开输入输出电平值设备
    m_fdVal = open(devValue, O_RDWR);
}

void GPIOKeyPin::readKeyPin(char *buf, const char *devValue)
{
    int fdVal = open(devValue, O_RDWR);
    read(fdVal, buf, sizeof(buf));// 读出电平值
    close(fdVal);
}
