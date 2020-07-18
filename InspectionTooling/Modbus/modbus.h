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
    QSerialPort *initProt(QString port);
    void sendCurrentData(int cmd);
    void sendVoltageData(int cmd);
    void sendLeakData(int cmd);
    void initVoltageConf();
    void initCurrentConf();

    quint16 dataCRC16(uchar *data, int len);
signals:

public slots:
    void slotSendVoltageData(int cmd);
    void slotSendCurrentData(int cmd);
};

#endif // MODBUS_H
