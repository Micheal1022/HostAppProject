#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include "ThirdLib/ECanVci.h"

class Thread : public QThread
{
    Q_OBJECT
public:
    Thread();
    ~Thread();
private:
    void parseCanData(CAN_OBJ frame);
    bool m_runFlag;
protected:
    virtual void run();
signals:
    void sigHeartBeat(int loop);//心跳命令
    void sigSendCanData(QList<int> dataList);//实时数据
    void sigSendSetValue(int cmd, int type, int value);//查询设置值
public slots:

};

#endif // THREAD_H
