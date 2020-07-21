#include "modbus.h"

#include <QDebug>
#include <QThread>
#include <QSettings>
#include <QIODevice>
#include <QtSerialPort/QSerialPort>

#include "includes.h"

uchar CRC_High[] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1,
    0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0,
    0x80, 0x41, 0x00, 0xC1, 0x81, 0x40
};

/* Table of CRC values for low-order byte */
uchar CRC_Low[] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06,
    0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD,
    0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09,
    0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A,
    0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4,
    0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3,
    0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4,
    0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A,
    0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29,
    0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED,
    0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60,
    0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67,
    0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F,
    0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68,
    0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E,
    0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71,
    0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92,
    0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C,
    0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B,
    0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B,
    0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42,
    0x43, 0x83, 0x41, 0x81, 0x80, 0x40
};




Modbus::Modbus(QObject *parent) : QObject(parent)
{
//    QSettings settings("./COMCONF.ini", QSettings::IniFormat);
//    QString VolCOM  = settings.value("RS232_VOL/VolCOM").toString();
//    QString CurCOM  = settings.value("RS485_CUR/CurCOM").toString();
//    QString LeakCOM = settings.value("RS232_LEAK/LeakCOM").toString();
    QString VolCOM  = QString("/dev/ttymxc1");//串口
    QString CurCOM  = QString("/dev/ttymxc2");//485-1
    QString LeakCOM = QString("/dev/ttymxc4");//485-2
//    QString LeakCOM  = QString("/dev/ttymxc1");//串口
    //QString LeakCOM = QString("/dev/ttyUSB0");//485-2
    m_voltagePort = initProt(VolCOM,QSerialPort::Baud9600);
    m_currentPort = initProt(CurCOM,QSerialPort::Baud9600);
    m_leakPort    = initProt(LeakCOM,QSerialPort::Baud115200);
    initLeakConf();
    initLeakValue();
    initVoltageConf();
    initCurrentConf();
}

Modbus::~Modbus()
{
    m_voltagePort->close();
    m_currentPort->close();
    m_leakPort->close();

    delete m_voltagePort;
    delete m_currentPort;
    delete m_leakPort;
}

QSerialPort *Modbus::initProt(QString port,int baudRate)
{
    QSerialPort *serialPort = new QSerialPort;
    //设置串口名
    serialPort->setPortName(port);
    //设置波特率
    serialPort->setBaudRate(baudRate);;
    //设置数据位数
    serialPort->setDataBits(QSerialPort::Data8);
    //设置停止位
    serialPort->setStopBits(QSerialPort::OneStop);
    //设置奇偶校验
    serialPort->setParity(QSerialPort::NoParity);
    //设置流控制
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug()<<port<<" OK";
    } else {
        qDebug()<<port<<" ERROR";
    }
    return serialPort;

}

void Modbus::sendCurrentData(int cmd)
{
    QByteArray byteArray;
    if (P_START == cmd) {
        byteArray.append('#');  byteArray.append('G');
    } else if (P_STOP == cmd) {
        byteArray.append('#');  byteArray.append('U');
    } else if (P_SET == cmd) {
        byteArray.append('#');  byteArray.append('S');  byteArray.append('0');  byteArray.append('5');  byteArray.append('0');
        byteArray.append('0');  byteArray.append('0');  byteArray.append('5');  byteArray.append('0');  byteArray.append('0');
    }
    m_currentPort->write(byteArray);
}

void Modbus::sendVoltageData(int cmd)
{
    QByteArray byteArray;
    if (P_START == cmd) {
        byteArray.append(0x01); byteArray.append(0x57); byteArray.append(0x35); byteArray.append((char)_DATA);
        byteArray.append((char)_DATA); byteArray.append((char)_DATA); byteArray.append((char)_DATA);
        byteArray.append(0x8D);
    } else if (P_STOP == cmd) {
        byteArray.append(0x01); byteArray.append(0x57); byteArray.append(0x36); byteArray.append((char)_DATA);
        byteArray.append((char)_DATA); byteArray.append((char)_DATA); byteArray.append((char)_DATA);
        byteArray.append(0x8E);
    } else if (P_SET == cmd) {

    }
    m_voltagePort->write(byteArray);
}

void Modbus::sendLeakData(int cmd, int state)
{
    qDebug()<<"*********************";
    qDebug()<<"cmd  : "<<cmd;
    qDebug()<<"state: "<<state;
    QByteArray byteArray;
    if (P_START == cmd) {
        byteArray.append(0x81); byteArray.append((char)_DATA); byteArray.append(0x08); byteArray.append((char)_DATA);
        byteArray.append(0xDC); byteArray.append(0x04); byteArray.append(0x01); byteArray.append(0xD1);
        qDebug()<<byteArray;
        m_leakPort->write(byteArray);
    } else if (P_STOP == cmd) {
        byteArray.append(0x81); byteArray.append((char)_DATA); byteArray.append(0x06); byteArray.append((char)_DATA);
        byteArray.append(0x4F); byteArray.append(0x49);
        qDebug()<<byteArray;
        m_leakPort->write(byteArray);
    } else if (P_SET == cmd) {
        switch (state) {
        case D_000:
            qDebug()<<m_BaseByteArray;
            m_leakPort->write(m_BaseByteArray);
            break;
        case D_100:
            qDebug()<<m_100_ByteArray;
            m_leakPort->write(m_100_ByteArray);
            break;
        case D_150:
            qDebug()<<m_150_ByteArray;
            m_leakPort->write(m_150_ByteArray);
            break;
        case D_200:
            qDebug()<<m_200_ByteArray;
            m_leakPort->write(m_200_ByteArray);
            break;
        case D_300:
            qDebug()<<m_300_ByteArray;
            m_leakPort->write(m_300_ByteArray);
            break;
        case D_500:
            qDebug()<<m_500_ByteArray;
            m_leakPort->write(m_500_ByteArray);
            break;
        case D_800:
            qDebug()<<m_800_ByteArray;
            m_leakPort->write(m_800_ByteArray);
            break;
        }
    }
}

void Modbus::initVoltageConf()
{
    QByteArray byteArray;
    /*设置电压-220V*/
    byteArray.append(0x01); byteArray.append(0x57); byteArray.append(0x33); byteArray.append(0x98);
    byteArray.append(0x08); byteArray.append((char)_DATA); byteArray.append((char)_DATA);
    byteArray.append(0x2B);
    m_voltagePort->write(byteArray);
}

void Modbus::initCurrentConf()
{
    sendCurrentData(P_SET);
}

void Modbus::initLeakConf()
{
    QByteArray byteArray;
    /*设置电压-220V,1A*/
    byteArray.append(0x81); byteArray.append((char)_DATA); byteArray.append(0x0C); byteArray.append((char)_DATA);
    byteArray.append(0x31); byteArray.append(0x01); byteArray.append(0x01); byteArray.append(0x01);
    byteArray.append(0x02); byteArray.append(0x02); byteArray.append(0x02); byteArray.append(0x3E);
    m_leakPort->write(byteArray);
}

void Modbus::initLeakValue()
{
    m_BaseByteArray.append(0x81);
    m_BaseByteArray.append((char)_DATA);
    m_BaseByteArray.append(0x1E);
    m_BaseByteArray.append((char)_DATA);
    m_BaseByteArray.append(0x32);
    for (int i = 0; i < 24;i++) {
        m_BaseByteArray.append((char)_DATA);
    }
    m_BaseByteArray.append(0x2C);

    m_100_ByteArray = m_BaseByteArray;
    m_100_ByteArray[17] = 0x10;
    m_100_ByteArray[18] = 0x27;
    m_100_ByteArray[19] = _DATA;
    m_100_ByteArray[20] = _DATA;
    m_100_ByteArray[29] = 0x1B;

    m_150_ByteArray = m_BaseByteArray;
    m_150_ByteArray[17] = 0x98;
    m_150_ByteArray[18] = 0x3A  ;
    m_150_ByteArray[19] = _DATA;
    m_150_ByteArray[20] = _DATA;
    m_150_ByteArray[29] = 0x8E;

    m_200_ByteArray = m_BaseByteArray;
    m_200_ByteArray[17] = 0x20;
    m_200_ByteArray[18] = 0x4E;
    m_200_ByteArray[19] = _DATA;
    m_200_ByteArray[20] = _DATA;
    m_200_ByteArray[29] = 0x42;

    m_300_ByteArray = m_BaseByteArray;
    m_300_ByteArray[17] = 0x30;
    m_300_ByteArray[18] = 0x75;
    m_300_ByteArray[19] = _DATA;
    m_300_ByteArray[20] = _DATA;
    m_300_ByteArray[29] = 0x69;

    m_500_ByteArray = m_BaseByteArray;
    m_500_ByteArray[17] = 0x50;
    m_500_ByteArray[18] = 0xC3;
    m_500_ByteArray[19] = _DATA;
    m_500_ByteArray[20] = _DATA;
    m_500_ByteArray[29] = 0xBF;

    m_800_ByteArray = m_BaseByteArray;
    m_800_ByteArray[17] = 0x80;
    m_800_ByteArray[18] = 0x38;
    m_800_ByteArray[19] = 0x01;
    m_800_ByteArray[20] = _DATA;
    m_800_ByteArray[29] = 0x95;



}


quint16 Modbus::dataCRC16(uchar *data, int len)
{
    uchar uchCRCHi = 0xff;
    uchar uchCRCLo = 0xff;
    quint16  uindex;
    while(len--) {
        uindex  = uchCRCLo ^ *data++;
        uchCRCLo = uchCRCHi ^ CRC_High[uindex];
        uchCRCHi = CRC_Low[uindex];
    }
    return (uchCRCLo << 8 | uchCRCHi);
}

void Modbus::slotSendVoltageData(int cmd)
{
    sendVoltageData(cmd);
}

void Modbus::slotSendCurrentData(int cmd)
{
    sendCurrentData(cmd);
}

void Modbus::slotSendLeakData(int cmd, int state)
{
    sendLeakData(cmd,state);
}
