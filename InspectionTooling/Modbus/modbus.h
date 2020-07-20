#ifndef MODBUS_H
#define MODBUS_H

#include <QObject>
class QSerialPort;
class Modbus : public QObject
{
    Q_OBJECT
public:
    explicit Modbus(QObject *parent = NULL);
    ~Modbus();
private:
    uchar m_volData[8];
    QByteArray m_recvByteArray;
    QSerialPort *m_voltagePort;
    QSerialPort *m_currentPort;
    QSerialPort *m_leakPort;
    QByteArray m_BaseByteArray;
    QByteArray m_100_ByteArray;
    QByteArray m_150_ByteArray;
    QByteArray m_200_ByteArray;
    QByteArray m_300_ByteArray;
    QByteArray m_500_ByteArray;
    QByteArray m_800_ByteArray;

    QSerialPort *initProt(QString port,int baudRate);

    void sendCurrentData(int cmd);
    void sendVoltageData(int cmd);
    void sendLeakData(int cmd, int state);
    void initVoltageConf();
    void initCurrentConf();
    void initLeakConf();
    void initLeakValue();

    quint16 dataCRC16(uchar *data, int len);
signals:

public slots:
    void slotSendVoltageData(int cmd);
    void slotSendCurrentData(int cmd);
    void slotSendLeakData(int cmd, int state);
};

#endif // MODBUS_H
