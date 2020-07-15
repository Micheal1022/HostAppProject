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
#include "includes.h"

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
