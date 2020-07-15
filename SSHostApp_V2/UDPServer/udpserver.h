#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
class UDPServer : public QObject
{
    Q_OBJECT
public:
    explicit UDPServer(QObject *parent = NULL);
    ~UDPServer();
    void initConf();
    void sendCanData(int index, int loop, int canId, int type, int state, QList<int> valueList, QString area);
private:
    quint16 m_targetPort_1;
    quint16 m_targetPort_2;
    QHostAddress m_targetIP_1;
    QHostAddress m_targetIP_2;
    QUdpSocket *m_udpSocket;
    QString getHostIPAddr();
    void sendDate(QByteArray byteArray);

signals:
    void sigReset();
    void sigMute();
private slots:
    void slotReadReady();
    void slotSendCanData(int index, int loop, int canId, int type, int state, QList<int> valueList, QString area);
public slots:

    void slotSendCanData(int index, int pass, int canId, int type, int state, QList<int> voltageList, QList<qreal> currentList, QString area);
};

#endif // UDPSERVER_H
