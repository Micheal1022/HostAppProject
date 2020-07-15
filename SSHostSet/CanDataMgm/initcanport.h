#ifndef INITCANPORT_H
#define INITCANPORT_H

#include <QDebug>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <net/if.h>
#include <sys/uio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include "linux/can.h"
#include <linux/can/error.h>
#include <linux/can/raw.h>

#define CANFRAMESIZE 16

#define PF_CAN 29
#define LEAKTYPE 1
#define TEMPTYPE 2
//主机下发命令
#define SCMD_UPDATE 0x02    //实施更新数值
#define SCMD_RESET  0x03    //探测器复位
#define SCMD_CHECK  0x04    //探测器自检
#define SCMD_WORK   0x05    //回路板开始工作
#define SCMD_SALARM 0x08    //设置报警值
#define SCMD_SHAVE  0x09    //设置固有值
#define SCMD_SRATIO 0x0A    //设置变比值
#define SCMD_SCALIB 0x0E    //设置校准
#define SCMD_QALARM 0x0B    //查询／上传报警值
#define SCMD_QHAVE  0x0C    //查询／上传固有值
#define SCMD_QRATIO 0x0D    //查询／上传变比值

//回路板上发命令
#define DEV_STATE   0x01    //节点状态信息
#define DEV_UPDATE  0x02    //实施更新数值
#define DEV_HEART   0x06    //心跳命令
#define DEV_REPLY   0x07    //主机回复
class InitCanPort
{
public:
    InitCanPort();

    static int m_canFd;
    int getCanfd(const char *canName);
    static can_frame confCanFrame(uint loop, uint canId, uint cmd, uint type, uint state, uint pass = 0, uint valueSet = 0,uint pstate = 0, uint ptype = 0);
    static void sendCmdDate(uint loop, uint canId, uint cmd, uint type, uint state, uint pass = 0, uint valueSet = 0,uint pstate = 0, uint ptype = 0);
    static void setNodeValue(uint loop,uint canId,uint cmd,uint valueSet,uint valueBase = 0);
    static void sendCanData(can_frame frame, int cmd);
    static int sendCanData(int canfd, can_frame frame);
    static int recvCanData(int canfd, can_frame &frame);
    static void printFrame(can_frame frame);
private:
    int m_pass;
    struct ifreq m_ifr;
    struct sockaddr_can m_addr;
    struct can_frame m_canSetFrame;
};

#endif // INITCANPORT_H
