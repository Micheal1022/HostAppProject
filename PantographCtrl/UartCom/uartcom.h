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
private:
    QSerialPort *m_port;
    QTimer *m_timer;
    QByteArray m_buffer;
    void initPort(QString port);
    void analysisData(QByteArray buffer);
    quint16 CRC16(uchar *data, int len);

signals:
    void sigSendUartData(QList<int> uartData);

private slots:
    void slotReadTimeout();
    void slotReadAllDate();

};

#endif // UARTCOM_H
