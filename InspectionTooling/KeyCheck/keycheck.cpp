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
