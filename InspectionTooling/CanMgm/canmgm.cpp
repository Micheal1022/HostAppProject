#include "canmgm.h"
#include "thread.h"
#include <QDebug>
#include "includes.h"
DWORD CanMgm::m_devType = USBCAN1;

CanMgm::CanMgm(QObject *parent) : QObject(parent)
{

}

CanMgm::~CanMgm()
{
    CloseDevice(m_devType,0);
}

bool CanMgm::initCanDevice()
{
    if (openCanDevice()) {
        qDebug()<<"USBCAN openCanDevice  OK";
    } else {
        qDebug()<<"USBCAN openCanDevice  ERROR";
        return false;
    }

    INIT_CONFIG init_config;
    init_config.AccCode = 0;
    init_config.AccMask = 0xffffff;
    init_config.Filter  = 0;
    init_config.Timing0 = 0x31;
    init_config.Timing1 = 0x1C;
    init_config.Mode    = 0;

    if (InitCAN(m_devType,0,0,&init_config) == STATUS_OK)  {
        qDebug("InitCAN OK !");
    } else {
        qDebug("InitCAN ERROR !");
        return false;
    }

    if (StartCAN(m_devType,0,0) == STATUS_OK) {
        qDebug("StartCAN OK !");
    } else {
        qDebug("StartCAN ERROR !");
        return false;
    }
    return true;
}


int CanMgm::sendCanData(CAN_OBJ transmitFrameInfo)
{
    int ret = Transmit(m_devType,0,0,&transmitFrameInfo,1);;
    return ret;
}

int CanMgm::recvCanData(CAN_OBJ &receiveFrameInfo)
{
    int ret = Receive(m_devType,0,0,&receiveFrameInfo,1,0);
    return ret;
}

CAN_OBJ CanMgm::confCanFrame(uint loop, uint canId, uint cmd, uint type, uint state, uint pass, uint valueSet, uint pstate, uint ptype)
{
    //    qDebug()<<"****************";
    //    qDebug()<<"loop : "<<loop;
    //    qDebug()<<"cmd  : "<<cmd;
    //    qDebug()<<"type : "<<type;
    //    qDebug()<<"canId: "<<canId;
    CAN_OBJ can_OBJ;
    can_OBJ.ID &= 0x00;
    can_OBJ.DataLen = 0;
    for (int i = 0; i < 8; i++) {
        can_OBJ.Data[0] = 0;
    }

    switch (cmd) {
    case SCMD_RESET://探测器复位
        can_OBJ.DataLen = 0;
        break;
    case SCMD_SCALIB:
        can_OBJ.DataLen = 0;
        break;
    case SCMD_SALARM:   //报警设置
    case SCMD_SHAVE:    //固有设置
    case SCMD_SRATIO:   //变比设置
        can_OBJ.DataLen = 2;
        can_OBJ.Data[0] = valueSet >> 8;   //值高
        can_OBJ.Data[1] = valueSet & 0xFF; //值低

        break;
    case SCMD_UPDATE://数据更新
        can_OBJ.DataLen = 8;
        can_OBJ.Data[6] = pass << 4;
        break;
    case SCMD_CHECK://回路板工作
        can_OBJ.DataLen = 0;

        break;
    case SCMD_WORK://回路板工作
        can_OBJ.DataLen = 0;

        break;
    case DEV_REPLY://主机回复
        can_OBJ.DataLen = 8;
        can_OBJ.Data[0] = valueSet;
        can_OBJ.Data[6] = pass << 4 | pstate;
        can_OBJ.Data[7] = ptype;

        break;
    case SCMD_QALARM://查询阈值
        can_OBJ.DataLen = 0;
        break;
    case SCMD_QHAVE://查询固有
        can_OBJ.DataLen = 0;
        break;
    case SCMD_QRATIO://查询变比
        can_OBJ.DataLen = 0;
        break;
    }

    loop = loop << 24;
    cmd  = cmd  << 18;
    type = type << 12;
    state= state<< 8;
    can_OBJ.SendType = 0;
    can_OBJ.RemoteFlag = 0;
    can_OBJ.ExternFlag = 1;
    can_OBJ.ID = loop | cmd | type | state |canId;
    return can_OBJ;
}

void CanMgm::sendCmdDate(uint loop, uint canId, uint cmd, uint type, uint state, uint pass, uint valueSet, uint pstate, uint ptype)
{
    CAN_OBJ canFrame = confCanFrame(loop,canId,cmd,type,state,pass,valueSet,pstate,ptype);
    int ret = sendCanData(canFrame);
    if (ret > 0) {
        //qDebug()<<"sendCanData---success:"<<canFrame;
    } else {
        //qDebug()<<"sendCanData---error";
    }
}

