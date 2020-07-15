#include "rs485.h"
#include "slavemachine.h"
#include <QDebug>
RS485::RS485(QObject *parent) : QObject(parent)
{
    m_slaveMachine = new SlaveMachine;
    connect(m_slaveMachine,SIGNAL(sigMute()),this,SIGNAL(sigMute()));
    connect(m_slaveMachine,SIGNAL(sigReset()),this,SIGNAL(sigReset()));
}

RS485::~RS485()
{
    delete m_slaveMachine;
    m_slaveMachine = NULL;
}

void RS485::slotUpdateNodeSts(QList<uint> data)
{
    int pass  = data.at(1);
    int canId = data.at(2);
    int state = data.at(3);
    m_slaveMachine->updateNodeSts(pass,canId,state);
}

void RS485::slotUpdatePowerSts(int mainPower, int backPower)
{
    m_slaveMachine->updatePowerSts(mainPower,backPower);
}



