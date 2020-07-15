#ifndef BYDZ_RS485_BUS_H
#define BYDZ_RS485_BUS_H

#include <QObject>
class SlaveMachine;
class  RS485 : public QObject
{

    Q_OBJECT
public:
    explicit RS485(QObject *parent = NULL);
    ~RS485();
    SlaveMachine *m_slaveMachine;
signals:
    void sigMute();
    void sigReset();
public slots:
    void slotUpdateNodeSts(QList<uint> data);
    void slotUpdatePowerSts(int mainPower,int backPower);


};

#endif // RS485_BUS_H
