#ifndef SLAVEMACHINE_H
#define SLAVEMACHINE_H

#include <QObject>

class QSerialPort;
class SlaveMachine : public QObject
{
    Q_OBJECT

public:
    explicit SlaveMachine(QObject *parent = NULL);
    void initProt();
    void initConnect();
    QByteArray m_tempbyteArray;
    QSerialPort *m_serialPort;
    qint16 m_mainPower;
    qint16 m_backPower;
    char m_hostNumber;
    enum NodeSts{
        Normal = 0x0000,
        Alarm  = 0x0001,
        Error  = 0x0008,
        Unmatched = 0x0009//没有节点

    };
    struct nodeInfo
    {
        int m_state;
        nodeInfo(){
          m_state = Error;
        }
    };


    nodeInfo m_nodeArray[2048];

    void writeData(char code, qint16 reg, qint16 date);
    void writeData(char code, char* data, int len);
    quint16 N_CRC16(uchar *data, int len);

    void updateNodeSts(int pass, int canId, int state);
    void updatePowerSts(int m_mainPower,int m_backPower);
signals:
    void sigMute();
    void sigReset();
private slots:
    void slotReadAll();



};

#endif // SLAVEMACHINE_H
