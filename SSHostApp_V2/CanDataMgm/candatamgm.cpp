#include "candatamgm.h"



CanDataMgm::CanDataMgm(QObject *parent) : QObject(parent)
{


}
/*
* @项目   TBus_SSEF
* @函数   CanDataMgm(const char *canName);
* @描述   初始化
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
CanDataMgm::CanDataMgm(const char *canName)
{
    qRegisterMetaType<QList<int> >("QList<int>");
    m_initCanPort = new InitCanPort;
    int canFd = m_initCanPort->getCanfd(canName);
    if (canFd > 0) {
        m_canRecvThread = new CanRecvThread(canFd);
        connect(m_canRecvThread,SIGNAL(sigHeartBeat(int)),this,SIGNAL(sigHeartBeat(int)));
        connect(m_canRecvThread,SIGNAL(sigSendSetValue(int,int,int)),this,SIGNAL(sigSendSetValue(int,int,int)));
        connect(m_canRecvThread,SIGNAL(sigSendCanData(QList<int>)),this,SIGNAL(sigSendCanData(QList<int>)));
        m_canRecvThread->start();
    } else {
        qDebug()<<"******************************";
        qDebug()<<"---canFd--- : "<<canFd;
    }
}



