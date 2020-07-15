#include "initcanport.h"

//#define SendData
//#define RecvData;

int InitCanPort::m_canFd = 0;
InitCanPort::InitCanPort()
{

}
/*
* @项目   TBus_SSEF
* @描述   通过输入设备名称，获取CAN文件描述符
* @函数   int getCanfd(const char *canName)
* @作者   Micheal(陈明明)
* @时间   2019-03-06
*/
int InitCanPort::getCanfd(const char *canName)
{
    m_canFd = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(m_canFd == -1)
    {
        qDebug("socket error");
        return m_canFd;
    }
    else
    {
        strcpy(m_ifr.ifr_name, canName );
        if(ioctl(m_canFd, SIOCGIFINDEX, &m_ifr))
        {
            qDebug()<<"ioctl error";
            return -1;
        }

        m_addr.can_family = PF_CAN;
        m_addr.can_ifindex = m_ifr.ifr_ifindex;
        if(bind(m_canFd, (struct sockaddr *)&m_addr, sizeof(m_addr)) < 0)
        {
            qDebug()<<"bind error";
            return -1;
        }
        qDebug()<<"**** Open "<<canName<<"_canFD"<<m_canFd<<" OK **** ";
    }
    return m_canFd;
}
/*
* @项目   TBus_SSEF
* @函数   static can_frame confCanFrame(uint loop, uint canId, uint cmd, uint type, uint valueSet = 0, uint valueBase = 0);
* @描述   打包配置CAN数据包
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
can_frame InitCanPort::confCanFrame(uint loop, uint canId, uint cmd, uint type, uint state, uint pass, uint valueSet, uint pstate, uint ptype)
{

//    qDebug()<<"****************";
//    qDebug()<<"loop : "<<loop;
//    qDebug()<<"cmd  : "<<cmd;
//    qDebug()<<"type : "<<type;
//    qDebug()<<"canId: "<<canId;
    can_frame canFrame;
    canFrame.can_id &= 0x00;
    canFrame.can_dlc = 0;
    for (int i = 0; i < 8; i++) {
        canFrame.data[0] = 0;
    }

    switch (cmd) {
    case SCMD_RESET://探测器复位
        canFrame.can_dlc = 0;

        break;
    case SCMD_SALARM:   //报警设置
    case SCMD_SHAVE:    //固有设置
    case SCMD_SRATIO:   //变比设置
        canFrame.can_dlc = 2;
        canFrame.data[0] = valueSet >> 8;   //值高
        canFrame.data[1] = valueSet & 0xFF; //值低

        break;
    case SCMD_UPDATE://数据更新
        canFrame.can_dlc = 8;
        canFrame.data[6] = pass << 4;
        break;
    case SCMD_CHECK://回路板工作
        canFrame.can_dlc = 0;

        break;
    case SCMD_WORK://回路板工作
        canFrame.can_dlc = 0;

        break;
    case DEV_REPLY://主机回复
        canFrame.can_dlc = 8;
        canFrame.data[0] = valueSet;
        canFrame.data[6] = pass << 4 | pstate;
        canFrame.data[7] = ptype;

        break;
    case SCMD_QALARM://查询阈值
        canFrame.can_dlc = 0;
        break;
    case SCMD_QHAVE://查询固有
        canFrame.can_dlc = 0;
        break;
    case SCMD_QRATIO://查询变比
        canFrame.can_dlc = 0;
        break;
    }

    loop = loop << 24;
    cmd  = cmd  << 18;
    type = type << 12;
    state= state<< 8;
    canFrame.can_id = CAN_EFF_FLAG | loop | cmd | type | state |canId;
    return canFrame;

}

/*
* @项目   TBus_SSEF
* @函数   static void sendCmdDate(uint loop, uint canId, uint cmd, uint type, uint valueSet = 0, uint valueBase = 0);
* @描述   向回路板发送数据
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
void InitCanPort::sendCmdDate(uint loop, uint canId, uint cmd, uint type, uint state, uint pass, uint valueSet, uint pstate, uint ptype)
{
    can_frame canFrame = confCanFrame(loop,canId,cmd,type,state,pass,valueSet,pstate,ptype);
    int ret = sendCanData(m_canFd,canFrame);
    if (ret > 0) {
        //qDebug()<<"sendCanData---success:"<<cmd;
    } else {
        //qDebug()<<"sendCanData---error";
    }
}

void InitCanPort::sendCanData(can_frame frame,int cmd)
{
    //frame.can_id = frame.can_id | 0xFFFFFFF;
    //frame.can_id = frame.can_id & 0xFFFFFFF;
    frame.data[0] = cmd;
    int ret = sendCanData(m_canFd,frame);
    if (ret > 0) {
        //qDebug()<<"sendCanData---success:"<<cmd;
    } else {
        //qDebug()<<"sendCanData---error";
    }
}



/*
* @项目   TBus_SSEF
* @函数   static int sendCanData(int canfd, can_frame frame);
* @描述   向回路板发送CAN数据
* @作者   Micheal(陈明明)
* @时间   2019-03-06
*/

int InitCanPort::sendCanData(int canfd, can_frame frame)
{
    int retNo = send(canfd, &frame, sizeof(frame),MSG_DONTWAIT);
#ifdef SendData
    qDebug()<<"************ DataWrite **************";
    qDebug()<<"retNo  = "<<retNo;
    printFrame(frame);
#endif
    return retNo ;
}

/*
* @项目   TBus_SSEF
* @函数   static int recvCanData(int canfd, can_frame &frame);
* @描述   接受回路板CAN返回的数据
* @作者   Micheal(陈明明)
* @时间   2019-03-06
*/
int InitCanPort::recvCanData(int canfd, can_frame &frame)
{
    int retNo = recv(canfd, &frame, sizeof(frame),MSG_DONTWAIT);
#ifdef RecvData
    qDebug()<<"************ DataRead **************";
    qDebug()<<"retNo  = "<<retNo;
    printFrame(frame);
#endif

    return retNo;
}

void InitCanPort::printFrame(can_frame frame)
{
    qDebug()<<"can_id  = "<<frame.can_id;
    qDebug()<<"can_dlc = "<<frame.can_dlc;
    for(int i = 0;i<frame.can_dlc;i++)
    {
        qDebug()<<"data["<<i<<"] = "<<frame.data[i];
    }
    //总线挂起
    if(frame.can_id & CAN_ERR_BUSOFF)
    {
        qDebug("CAN_ERR_BUSOFF");
    }
    //总线错误
    if(frame.can_id & CAN_ERR_BUSERROR)
    {
        qDebug("CAN_ERR_BUSERROR");
    }
    //控制器重启
    if(frame.can_id & CAN_ERR_RESTARTED)
    {
        qDebug("CAN_ERR_RESTARTED");
    }
}



