#include "udpserver.h"
#include "SQLite/mysqlite.h"
#include "includes.h"
#include <QNetworkInterface>
UDPServer::UDPServer(QObject *parent) : QObject(parent)
{

    m_udpSocket = new QUdpSocket(this);

}

UDPServer::~UDPServer()
{
    delete m_udpSocket;
}

void UDPServer::initConf(int loop)
{
    for (int i = 1; i <= DATASIZE; i++) {
        m_nodeData[i].m_nodeUsed = true;
        m_nodeData[i].m_nodeLoop = loop;
        m_nodeData[i].m_nodeID   = i;
        m_nodeData[i].m_nodeType = MOD_L12T4;
        m_nodeData[i].m_nodeState= N_NORMAL;
    }
    m_currentID = 1;
    m_sendDataTimer = new QTimer;
    connect(m_sendDataTimer,SIGNAL(timeout()),this,SLOT(slotSendDataTimeOut()));
    m_sendDataTimer->start(TIMER);


    QSqlDatabase db1 = MySQLite::openConnection();
    QStringList stringList_1 = MySQLite::getNetWorkIP(db1,1);
    MySQLite::closeConnection(db1);
    QString desIP1  = stringList_1.value(0);
    QString hostIP1 = stringList_1.value(1);
    uint port1   = stringList_1.value(2).toUInt();
    QString able1   = stringList_1.value(3);

    m_targetIP_1   = desIP1;
    m_targetPort_1 = port1;
    if (able1.toUInt() == 2) {
        QString ipCmdStr_1 = QString("ifconfig eth0 ")+hostIP1;
        QProcess procss_1;
        procss_1.execute(ipCmdStr_1);
    }

    QSqlDatabase db2 = MySQLite::openConnection();
    QStringList stringList_2 = MySQLite::getNetWorkIP(db2,2);
    MySQLite::closeConnection(db2);
    QString desIP2  = stringList_2.value(0);
    QString hostIP2 = stringList_2.value(1);
    uint port2   = stringList_2.value(2).toUInt();
    QString able2   = stringList_2.value(3);

    m_targetIP_2   = desIP2;
    m_targetPort_2 = port2;
    if (able2.toUInt() == 2) {
        QString ipCmdStr_2 = QString("ifconfig eth1 ")+hostIP2;
        QProcess procss_2;
        procss_2.execute(ipCmdStr_2);
    }

    m_udpSocket->bind(m_targetIP_1,m_targetPort_1);//监听端口和地址
    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(slotReadReady()));
}

QString UDPServer::getHostIPAddr()
{
    QString strIpAddress;
    QList<QHostAddress> ipAddrList = QNetworkInterface::allAddresses();
    // 获取第一个本主机的IPv4地址
    int listSize = ipAddrList.size();
    for (int i = 0; i < listSize; ++i) {
        if (ipAddrList.at(i) != QHostAddress::LocalHost && ipAddrList.at(i).toIPv4Address()) {
            strIpAddress = ipAddrList.at(i).toString();
            break;
        }
    }     // 如果没有找到，则以本地IP地址为IP
    if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return strIpAddress;
}

void UDPServer::sendDate(QByteArray byteArray)
{
    /*
    qDebug()<<"<---------------------------------------->";
    qDebug()<<"m_currentID    -----> "<<m_currentID;
    qDebug()<<"byteArray[HEAD]-----> "<<(uchar)byteArray.at(0);
    qDebug()<<"byteArray[LOOP]-----> "<<(uchar)byteArray.at(1);
    qDebug()<<"byteArray[NOID]-----> "<<(uchar)byteArray.at(2);
    qDebug()<<"byteArray[TYPE]-----> "<<(uchar)byteArray.at(3);
    qDebug()<<"byteArray[STAT]-----> "<<(uchar)byteArray.at(4);
    qDebug()<<"byteArray[TAIL]-----> "<<(uchar)byteArray.at(5);
    */
    m_udpSocket->writeDatagram(byteArray,m_targetIP_1,m_targetPort_1);
}

void UDPServer::slotReadReady()
{
    while (m_udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_udpSocket->pendingDatagramSize());
        m_udpSocket->readDatagram(datagram.data(), datagram.size());
        switch (datagram.at(0)) {
        case 1://mute
            emit sigMute();
            break;
        case 2://reset
            emit sigReset();
            break;
        default:
            break;
        }
    }
}

void UDPServer::slotSendDataTimeOut()
{
    QByteArray pByteArray;pByteArray.clear();
    if (m_nodeData[m_currentID].m_nodeUsed) {
        pByteArray.append(HEAD_AA);
        pByteArray.append(m_nodeData[m_currentID].m_nodeLoop);
        pByteArray.append(m_nodeData[m_currentID].m_nodeID);
        pByteArray.append(m_nodeData[m_currentID].m_nodeType);
        pByteArray.append(m_nodeData[m_currentID].m_nodeState);
        pByteArray.append(TAIL_FF);
        sendDate(pByteArray);
    }
    m_currentID++;
    if (m_currentID == DATASIZE) {
        m_currentID = 1;
    }
}
