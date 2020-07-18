#ifndef CANMGM_H
#define CANMGM_H

#include <QObject>
#include "ThirdLib/ECanVci.h"
class CanMgm : public QObject
{
    Q_OBJECT
public:
    explicit CanMgm(QObject *parent = nullptr);
    ~CanMgm();
    static DWORD m_devType;
    static bool openCanDevice() {
        if(OpenDevice(m_devType,0,0) != STATUS_OK) {
            return false;
        }
        return true;
    }
    static bool closeCanDevice() {
        if(CloseDevice(m_devType,0) != STATUS_OK) {
            return false;
        }
        return true;
    }
    static bool initCanDevice();
    static int sendCanData(CAN_OBJ transmitFrameInfo);
    static int recvCanData(CAN_OBJ &receiveFrameInfo);
    static CAN_OBJ confCanFrame(uint loop, uint canId, uint cmd, uint type, uint state, uint pass = 0, uint valueSet = 0,uint pstate = 0, uint ptype = 0);
    static void sendCmdDate(uint loop, uint canId, uint cmd, uint type, uint state, uint pass = 0, uint valueSet = 0,uint pstate = 0, uint ptype = 0);

};

#endif // CANMGM_H
