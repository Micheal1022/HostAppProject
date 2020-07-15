#ifndef CANDATAMGM_H
#define CANDATAMGM_H

#include <QObject>
#include "initcanport.h"
#include "canrecvthread.h"
class CanDataMgm : public QObject
{
    Q_OBJECT
public:
    explicit CanDataMgm(QObject *parent = 0);
    CanDataMgm(const char *canName);


private:
    InitCanPort *m_initCanPort;
    CanRecvThread *m_canRecvThread;
signals:
    void sigHeartBeat(int loop);//心跳命令
    void sigSendCanData(QList<int> dataList);//实时数据
    void sigSendSetValue(int cmd, int type, int value);//查询设置值

public slots:
};

#endif // CANDATAMGM_H
