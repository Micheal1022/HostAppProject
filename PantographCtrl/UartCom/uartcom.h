#ifndef UARTCOM_H
#define UARTCOM_H

#include <QObject>
class QTimer;
class QSerialPort;
class UartCom : public QObject
{
    Q_OBJECT
public:
    explicit UartCom(QObject *parent = 0);
    ~UartCom();
    void initPort(QString port);
    void sendUartData(QByteArray byteArray);
private:
    QSerialPort *m_port;
    QTimer *m_timer;
    QByteArray m_buffer;
    void analysisData(QByteArray buffer);
    quint16 CRC16(uchar *data, int len);
    bool CRC16_OK(QByteArray buffer);
    void replayDataConf(int cmd);
signals:
    void sigRecvUartData(QList<int> dataList);
    void sigRecvConfData(QList<int> dataList);
    void sigReplay();
private slots:
    void slotReadTimeout();
    void slotReadAllDate();
public slots:
    void slotReplayData(int cmd);

};

#endif // UARTCOM_H
