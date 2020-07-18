#include "canrecvthread.h"


#define PRINT
//命令解析
#define LOOP_FLGE   0x1F000000
#define CMD_FLGE    0x003F0000
#define TYPE_FLGE   0x0003F000
#define STATE_FLGE  0x00000F00
#define CANID_FLGE  0x000000FF
CanRecvThread::CanRecvThread()
{

}
/*
* @项目   TBus_SSEF
* @函数   CanRecvThread(int canFd);
* @描述   构造函数初始化文件描述符
* @作者   Micheal(陈明明)
* @时间   2019-03-06
*/
CanRecvThread::CanRecvThread(int canFd)
{
    m_canFd = canFd;
    qRegisterMetaType<QList<int> >("QList<int>");

}

CanRecvThread::~CanRecvThread()
{

}
/*
* @项目   TBus_SSEF
* @函数   void parseCanData(can_frame frame);
* @描述   数据解析
* @作者   Micheal(陈明明)
* @时间   2019-03-06
*/
void CanRecvThread::parseCanData(can_frame frame)
{


    int loop = (frame.can_id & LOOP_FLGE)  >> 24;//回路28-24
    int cmd  = (frame.can_id & CMD_FLGE)   >> 18;//命令23-18
    int type = (frame.can_id & TYPE_FLGE)  >> 12;//类型17-12
    int state= (frame.can_id & STATE_FLGE) >> 8; //状态11-08
    int canId= (frame.can_id & CANID_FLGE);      //地址7-0

    QList<int> dataList;
    int pass, pstate, ptype;
    int value_1 = (frame.data[0]<<8) | frame.data[1];//漏电实时 | /A电压/电流
    int value_2 = (frame.data[2]<<8) | frame.data[3];//漏电报警 | /B电压/电流
    int value_3 = (frame.data[4]<<8) | frame.data[5];//设置为空 | /C电压/电流
    if (type == 9) {
        pass   = (frame.data[6] / 3) +1;  //通道
        pstate = 0;  //状态
        ptype  = type;
    } else {
        pass   = frame.data[6] >> 4;  //通道
        pstate = frame.data[6] & 0xF; //状态
        ptype  = frame.data[7];       //类型
    }

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
        InitCanPort::sendCmdDate(loop,canId,DEV_REPLY,type,state,pass,DEV_STATE,pstate,ptype);
    case DEV_UPDATE://实时数据
        InitCanPort::sendCmdDate(loop,canId,DEV_REPLY,type,state,pass,DEV_UPDATE,pstate,ptype);
        //发送数值到节点信息
        dataList<<loop<<cmd<<type<<state<<canId<<value_1<<value_2<<value_3<<pass<<pstate<<ptype;
        if(dataList.isEmpty() == false)
            emit sigSendCanData(dataList);
        break;
    }

}
/*
* @项目   TBus_SSEF
* @函数   void run()
* @描述   循环读取CAN设备上发的数据
* @作者   Micheal(陈明明)
* @时间   2019-03-06
*/
void CanRecvThread::run()
{
    while(1) {
        msleep(50);
        struct can_frame readCanFrame;
        memset(&readCanFrame, 0x00, sizeof(readCanFrame));
        if(InitCanPort::recvCanData(m_canFd,readCanFrame) == CANFRAMESIZE) {
            parseCanData(readCanFrame);//解析CAN数据包
        }
    }
}

