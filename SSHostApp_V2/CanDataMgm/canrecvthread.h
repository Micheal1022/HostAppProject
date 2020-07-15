#ifndef CANRECVTHREAD_H
#define CANRECVTHREAD_H

#include <QList>
#include <QThread>
#include <QObject>
#include "initcanport.h"
class CanRecvThread : public QThread
{
    Q_OBJECT
public:
    CanRecvThread();
    CanRecvThread(int canFd);
    ~CanRecvThread();

private:
    int m_canFd;
    void parseCanData(can_frame frame);
protected:
    virtual void run();
signals:
    void sigHeartBeat(int loop);//心跳命令
    void sigSendCanData(QList<int> dataList);//实时数据
    void sigSendSetValue(int cmd, int type, int value);//查询设置值
};

#endif // CANRECVTHREAD_H
