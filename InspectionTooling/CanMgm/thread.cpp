#include "thread.h"

#include <QDebug>
#include "includes.h"
#include "CanMgm/canmgm.h"
#define LOOP_FLGE   0x1F000000
#define CMD_FLGE    0x003F0000
#define TYPE_FLGE   0x0003F000
#define STATE_FLGE  0x00000F00
#define CANID_FLGE  0x000000FF

//#define PRINT

Thread::Thread()
{
    qRegisterMetaType<QList<int>> ("QList<int>");
    CanMgm::initCanDevice();
    m_runFlag = false;
}

Thread::~Thread()
{

}

void Thread::parseCanData(CAN_OBJ frame)
{
    int loop = (frame.ID & LOOP_FLGE)  >> 24;//回路28-24
    int cmd  = (frame.ID & CMD_FLGE)   >> 18;//命令23-18
    int type = (frame.ID & TYPE_FLGE)  >> 12;//类型17-12
    int state= (frame.ID & STATE_FLGE) >> 8; //状态11-08
    int canId= (frame.ID & CANID_FLGE);      //地址7-0

    QList<int> dataList;
    int value_1 = (frame.Data[0]<<8) | frame.Data[1];//漏电实时 | /A电压/电流
    int value_2 = (frame.Data[2]<<8) | frame.Data[3];//漏电报警 | /B电压/电流
    int value_3 = (frame.Data[4]<<8) | frame.Data[5];//设置为空 | /C电压/电流

    int pass    =  frame.Data[6] >> 4;   //通道
    int pstate  =  frame.Data[6] & 0xF;  //状态
    int ptype   =  frame.Data[7];        //类型

#ifdef PRINT
    if (cmd != DEV_HEART) {
        qDebug()<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^";
        qDebug()<<"loop    : "<<loop;
        qDebug()<<"cmd     : "<<cmd;
        qDebug()<<"type    : "<<type;
        qDebug()<<"canId   : "<<canId;
        qDebug()<<"state   : "<<state;
        qDebug()<<"value_1 : "<<value_1;
        qDebug()<<"value_2 : "<<value_2;
        qDebug()<<"value_3 : "<<value_3;
        qDebug()<<"pass    : "<<pass;
        qDebug()<<"pstate  : "<<pstate;
        qDebug()<<"ptype   : "<<ptype;
        qDebug()<<"vvvvvvvvvvvvvvvvvvvvvvvvvv";
    }
#endif
    switch (cmd) {
    case DEV_HEART:
        emit sigHeartBeat(loop);
        break;
    case SCMD_QALARM:
    case SCMD_QHAVE:
    case SCMD_QRATIO:
        //查询数值
        emit sigSendSetValue(cmd,type,value_1);
        break;
    case DEV_STATE: //状态上传
        CanMgm::sendCmdDate(loop,canId,DEV_REPLY,type,state,pass,DEV_STATE,pstate,ptype);
    case DEV_UPDATE://实时数据
        CanMgm::sendCmdDate(loop,canId,DEV_REPLY,type,state,pass,DEV_UPDATE,pstate,ptype);
        //发送数值到节点信息
        dataList<<loop<<cmd<<type<<state<<canId<<value_1<<value_2<<value_3<<pass<<pstate<<ptype;
        if(dataList.isEmpty() == false)
            emit sigSendCanData(dataList);
        break;
    }
}


void Thread::run()
{
    CAN_OBJ readCanFrame;
    while(1) {
        msleep(50);
        memset(&readCanFrame, 0x00, sizeof(readCanFrame));
        if(CanMgm::recvCanData(readCanFrame) > 0) {
            parseCanData(readCanFrame);//解析CAN数据包
        }
    }
}





