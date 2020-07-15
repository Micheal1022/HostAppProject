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

void UDPServer::initConf()
{
    //QList<QPair<QString,int> > addList;
    //addList.append(qMakePair(QString("192.168.126.35"),9990));
    //addList.append(qMakePair(QString("192.168.126.35"),9991));
    //addList.append(qMakePair(QString("192.168.126.35"),9992));
    //addList.append(qMakePair(QString("192.168.126.35"),9993));

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

void UDPServer::sendCanData(int index, int loop, int canId, int type, int state, QList<int> valueList, QString area)
{
    slotSendCanData(index,loop,canId,type,state,valueList,area);
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

void UDPServer::slotSendCanData(int index, int pass, int canId, int type, int state, QList<int> voltageList, QList<qreal> currentList,QString area)
{
    QByteArray byteArray;
    byteArray.append((uint)(index)>>8);
    byteArray.append((uint)(index) & 0xFF);
    byteArray.append((uint)(pass));
    byteArray.append((uint)(canId)>>8);
    byteArray.append((uint)(canId) & 0xFF);
    byteArray.append((uint)(type));
    byteArray.append((uint)(state));

    uint av1_h = (uint)voltageList.value(0) >> 8;
    uint av1_l = (uint)voltageList.value(0) & 0xFF;
    uint bv1_h = (uint)voltageList.value(1) >> 8;
    uint bv1_l = (uint)voltageList.value(1) & 0xFF;
    uint cv1_h = (uint)voltageList.value(2) >> 8;
    uint cv1_l = (uint)voltageList.value(2) & 0xFF;
    uint av2_h = (uint)voltageList.value(3) >> 8;
    uint av2_l = (uint)voltageList.value(3) & 0xFF;
    uint bv2_h = (uint)voltageList.value(4) >> 8;
    uint bv2_l = (uint)voltageList.value(4) & 0xFF;
    uint cv2_h = (uint)voltageList.value(5) >> 8;;
    uint cv2_l = (uint)voltageList.value(5) & 0xFF;

    byteArray.append(av1_h);
    byteArray.append(av1_l);
    byteArray.append(bv1_h);
    byteArray.append(bv1_l);
    byteArray.append(cv1_h);
    byteArray.append(cv1_l);

    byteArray.append(av2_h);
    byteArray.append(av2_l);
    byteArray.append(bv2_h);
    byteArray.append(bv2_l);
    byteArray.append(cv2_h);
    byteArray.append(cv2_l);

    QString aiStr = QString::number(currentList.value(0));
    QString biStr = QString::number(currentList.value(1));
    QString ciStr = QString::number(currentList.value(2));

    byteArray.append(aiStr.left(aiStr.indexOf(".")).toUInt());
    byteArray.append(aiStr.right(1).toUInt());
    byteArray.append(biStr.left(biStr.indexOf(".")).toUInt());
    byteArray.append(biStr.right(1).toUInt());
    byteArray.append(ciStr.left(ciStr.indexOf(".")).toUInt());
    byteArray.append(ciStr.right(1).toUInt());

    QByteArray nodeAddrBy = area.toUtf8().data();
    byteArray.append(nodeAddrBy);
    sendDate(byteArray);
}


void UDPServer::slotSendCanData(int index, int loop, int canId, int type, int state, QList<int> valueList,QString area)
{

    QByteArray byteArray;
    byteArray.append(index >>8);
    byteArray.append(index & 0xFF);
    byteArray.append(loop);
    byteArray.append(canId >>8);
    byteArray.append(canId & 0xFF);
    byteArray.append(type);
    byteArray.append(state);

    switch (type) {
    case N_LEAK:    {
        uint leak_h  = (uint)valueList.value(0) >> 8;
        uint leak_l  = (uint)valueList.value(0) & 0xFF;
        uint alarm_h = (uint)valueList.value(1) >> 8;
        uint alarm_l = (uint)valueList.value(1) & 0xFF;
        uint base_h  = (uint)valueList.value(2) >> 8;
        uint base_l  = (uint)valueList.value(2) & 0xFF;

        byteArray.append(leak_h);byteArray.append(alarm_h);byteArray.append(base_h);
        byteArray.append(leak_l);byteArray.append(alarm_l);byteArray.append(base_l);
    }
        break;
    case N_TEMP: {
        uint temp_h  = (uint)valueList.value(0) >> 8;
        uint temp_l  = (uint)valueList.value(0) & 0xFF;
        uint alarm_h = (uint)valueList.value(1) >> 8;
        uint alarm_l = (uint)valueList.value(1) & 0xFF;
        uint null_h  = (uint)valueList.value(2) >> 8;
        uint null_l  = (uint)valueList.value(2) & 0xFF;

        byteArray.append(temp_h);byteArray.append(alarm_h);byteArray.append(null_h);
        byteArray.append(temp_l);byteArray.append(alarm_l);byteArray.append(null_l);
    }
        break;
    case N_ACV3:
    case N_ACV:
    case N_DCV: {
        uint av_h = (uint)valueList.value(0) >> 8;
        uint av_l = (uint)valueList.value(0) & 0xFF;
        uint bv_h = (uint)valueList.value(1) >> 8;
        uint bv_l = (uint)valueList.value(1) & 0xFF;
        uint cv_h = (uint)valueList.value(2) >> 8;
        uint cv_l = (uint)valueList.value(2) & 0xFF;

        byteArray.append(av_h);byteArray.append(bv_h);byteArray.append(cv_h);
        byteArray.append(av_l);byteArray.append(bv_l);byteArray.append(cv_l);
    }
        break;
    case N_ACI3:
    case N_ACI:
    case N_DCI:
    {
        QString aiStr = QString::number(valueList.value(0));
        QString biStr = QString::number(valueList.value(1));
        QString ciStr = QString::number(valueList.value(2));

        byteArray.append(aiStr.left(aiStr.indexOf(".")).toUInt());  byteArray.append(aiStr.right(1).toUInt());
        byteArray.append(biStr.left(biStr.indexOf(".")).toUInt());  byteArray.append(biStr.right(1).toUInt());
        byteArray.append(ciStr.left(ciStr.indexOf(".")).toUInt());  byteArray.append(ciStr.right(1).toUInt());

    }
        break;
    }

    QByteArray nodeAddrBy = area.toUtf8().data();
    byteArray.append(nodeAddrBy);
    sendDate(byteArray);
}



