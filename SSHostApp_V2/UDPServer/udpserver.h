#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include "includes.h"
#include <QTimer>

#define DATASIZE    129
class UDPServer : public QObject
{
    Q_OBJECT
public:
    explicit UDPServer(QObject *parent = NULL);
    ~UDPServer();
    void initConf(int loop);
private:
    quint16 m_targetPort_1;
    quint16 m_targetPort_2;
    QHostAddress m_targetIP_1;
    QHostAddress m_targetIP_2;
    QUdpSocket *m_udpSocket_1;
    //QUdpSocket *m_udpSocket_2;
    QTimer *m_sendDataTimer;
    QString getHostIPAddr();
    void sendDate(QByteArray byteArray);
    struct NodeData{
        void initData(int loop, int id){
            m_nodeUsed  = true;
            m_nodeLoop  = loop;
            m_nodeID    = id;
            m_nodeType  = MOD_L12T4;
            m_nodeState = N_NORMAL;
        }
        bool m_nodeUsed;
        uchar m_nodeLoop;
        uchar m_nodeID;
        uchar m_nodeType;
        uchar m_nodeState;
    } m_nodeData[DATASIZE];
    int m_currentID;


signals:
    void sigReset();
    void sigMute();
private slots:
    void slotReadReady();
    void slotSendDataTimeOut();
};

#endif // UDPSERVER_H
