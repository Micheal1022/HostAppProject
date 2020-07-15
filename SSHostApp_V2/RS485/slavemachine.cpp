#include "slavemachine.h"

#include <QDebug>
#include <QSettings>
#include <QDateTime>
#include <QtSerialPort/QSerialPort>

#define BUFFSIZE  8
#define CRC_L_TIME  13
#define CRC_H_TIME  14
#define CRC_L   6
#define CRC_H   7

char null_d =0x00;
char host_add = 0x01;
char code_func = 0x06;
char code_power = 0x03;

quint16 reg_mute  = 0x2333;//消音
quint16 regMpower = 0x2334;//主电
quint16 regBPower = 0x2335;//备电
quint16 regReset  = 0x2332;//复位


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

SlaveMachine::SlaveMachine(QObject *parent) : QObject(parent)
{
    initProt();
    initConnect();
}

void SlaveMachine::initProt()
{
    QSettings settings("./Conf.ini", QSettings::IniFormat);
    m_hostNumber = settings.value("RS485/HostNumber").toInt();
    int baudRate = settings.value("RS485/BaudRate").toInt();
    int dataBits = settings.value("RS485/DataBits").toInt();
    int stopBits = settings.value("RS485/StopBits").toInt();
    int parity   = settings.value("RS485/Parity").toInt();
    QString RS485Port = settings.value("RS485/RS485Port").toString();

    m_mainPower = 0;
    m_backPower = 0;

    m_serialPort = new QSerialPort;
    if(m_serialPort->isOpen())
        m_serialPort->close();
    //设置串口名
    m_serialPort->setPortName(RS485Port);
    //设置波特率
    m_serialPort->setBaudRate((QSerialPort::BaudRate)baudRate);
    //设置数据位数
    m_serialPort->setDataBits((QSerialPort::DataBits)dataBits);
    //设置停止位
    m_serialPort->setStopBits(QSerialPort::StopBits(stopBits));
    //设置奇偶校验
    m_serialPort->setParity(QSerialPort::Parity(parity));
    //设置流控制
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serialPort->open(QIODevice::ReadWrite)) {
        qDebug()<<RS485Port<<" OK";
        m_serialPort->setReadBufferSize(BUFFSIZE);
    } else {
        qDebug()<<RS485Port<<" ERROR";
    }
}

void SlaveMachine::initConnect()
{
    connect(m_serialPort,SIGNAL(readyRead()),this,SLOT(slotReadAll()));
}

void SlaveMachine::writeData(char code,qint16 reg, qint16 date)
{
    QByteArray ba;
    ba.append(m_hostNumber);
    ba.append(code);
    ba.append(reg>>8);
    ba.append(reg&0xFF);
    ba.append(date);
    ba.append(date);

    char *data = ba.data();
    qint16 crcNum = N_CRC16((uchar*)data,ba.size());

    ba.append(crcNum & 0xFF);
    ba.append(crcNum >> 8);

    m_serialPort->write(ba);
}

void SlaveMachine::writeData(char code, char *data, int len)
{
    QByteArray ba;
    ba.append(m_hostNumber);
    ba.append(code);
    ba.append(len);
    for (int i = 0;i < len;i++) {
        ba.append((uchar)data[i]);
    }

    char *data_crc = ba.data();
    quint16 crcNum = N_CRC16((uchar*)data_crc,ba.size());

    ba.append(crcNum & 0xFF);
    ba.append(crcNum >> 8);

    m_serialPort->write(ba);
}

void SlaveMachine::slotReadAll()
{
    QByteArray byteArray = m_serialPort->readAll();
    m_tempbyteArray += byteArray;
    if (m_tempbyteArray.size() == 8) {
        //for (int i = 0; i < ba.size();i++) {
        //    qDebug()<<"ba = "<<(uchar)ba.at(i);
        //}
        //qDebug()<<"****************";
        if (m_tempbyteArray.at(0) == 0x01) {
            uint code = m_tempbyteArray.at(1);
            int  addr = ((uchar)m_tempbyteArray.at(2)<<8) | (uchar)m_tempbyteArray.at(3);
            quint16 crcNum;
            switch (code) {
            case 0x03:
                crcNum = N_CRC16((uchar*)m_tempbyteArray.left(6).data(),m_tempbyteArray.size()-2);
                if(((crcNum >> 8) == (uchar)m_tempbyteArray.at(CRC_L)) && ((crcNum & 0xFF) == (uchar)m_tempbyteArray.at(CRC_H))) {
                    if (addr == regMpower){
                        //mainpower
                        writeData(0x03,regMpower,m_mainPower);
                    } else if (addr == regBPower) {
                        //backpower
                        writeData(0x03,regBPower,m_backPower);
                    } else {
                        //node-sts
                        if (addr <= 0x2710+1024) {
                            QByteArray dateArray;
                            int canId = addr - 10000;
                            int num = (uchar)m_tempbyteArray.at(4) << 8 | (uchar)m_tempbyteArray.at(5);
                            for(int i = canId; i < canId+num;i++)
                            {
                                dateArray.append(null_d);
                                dateArray.append(m_nodeArray[i].m_state);
                            }
                            writeData(0x03,dateArray.data(),dateArray.size());
                        } else {
                            QByteArray dateArray;
                            int canId = addr - 10000-1024;
                            int num = (uchar)m_tempbyteArray.at(4) << 8 | (uchar)m_tempbyteArray.at(5);
                            for (int i = canId; i < canId+num;i++) {
                                dateArray.append(null_d);
                                dateArray.append(m_nodeArray[i].m_state);
                            }
                            writeData(0x03,dateArray.data(),dateArray.size());
                        }
                    }
                }
                break;
            case 0x06:

                crcNum = N_CRC16((uchar*)m_tempbyteArray.left(6).data(),m_tempbyteArray.size()-2);
                if(((crcNum >> 8) == (uchar)m_tempbyteArray.at(CRC_L)) && ((crcNum & 0xFF) == (uchar)m_tempbyteArray.at(CRC_H))) {
                    int yy,MM,dd,hh,mm,ss;
                    QString year,month,date,hour,minute,second;
                    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                    year   = dateTime.left(4);
                    month  = dateTime.mid(5,2);
                    date   = dateTime.mid(8,2);
                    hour   = dateTime.mid(10,2);
                    minute = dateTime.mid(13,2);
                    second = dateTime.right(2);
                    addr = ((m_tempbyteArray.at(2)<<8) | m_tempbyteArray.at(3));
                    switch (addr) {
                    case 0x2329://time-year
                        yy = year.toInt() - 2000;
                        writeData(0x056,0x2329,yy);
                        break;
                    case 0x232A://time-month
                        MM = month.toInt();
                        writeData(0x06,0x0232A,MM);
                        break;
                    case 0x232B://time-date
                        dd = date.toInt();
                        writeData(0x06,0x0232B,dd);
                        break;
                    case 0x232C://time-hour
                        hh = hour.toInt();
                        writeData(0x06,0x0232C,hh);
                        break;
                    case 0x232D://time-minute
                        mm = minute.toInt();
                        writeData(0x06,0x0232D,mm);
                        break;
                    case 0x232E://second
                        ss = second.toInt();
                        writeData(0x06,0x0232E,ss);
                        break;
                    case 0x2332://reset
                        emit sigReset();
                        m_serialPort->write(m_tempbyteArray);
                        break;
                    case 0x2333://mute
                        emit sigMute();
                        m_serialPort->write(m_tempbyteArray);
                        break;
                    }
                }
                break;
            case 0x10://set-time
                crcNum = N_CRC16((uchar*)m_tempbyteArray.left(6).data(),m_tempbyteArray.size()-2);
                if (((crcNum >> 8) == m_tempbyteArray.at(CRC_L_TIME)) && ((crcNum & 0xFF) == m_tempbyteArray.at(CRC_L_TIME))) {
                    QString year   = QString::number(m_tempbyteArray.at(7)+ 2000);
                    QString month  = QString::number(m_tempbyteArray.at(8));
                    QString date   = QString::number(m_tempbyteArray.at(9));;
                    QString hour   = QString::number(m_tempbyteArray.at(10));
                    QString minute = QString::number(m_tempbyteArray.at(11));
                    QString second = QString::number(m_tempbyteArray.at(12));
                    QString cmd = QStringLiteral("date -s ");
                    QString cmdStr = cmd+year+"-"+month+"-"+date+" "+hour+":"+minute+":"+second+" && hwclock -w";
                    ::system(cmdStr.toLatin1().data());
                }
                break;
            }
        }
        m_tempbyteArray.clear();
    }
}

void SlaveMachine::updateNodeSts(int pass, int canId, int state)
{
    if (state == 3) {
        state = 8;
    }
    if (pass == 1) {
        m_nodeArray[canId-1].m_state = state;
    } else if (pass == 2) {
        m_nodeArray[canId-1+1024].m_state = state;
    }
    writeData(pass,canId,state);
}

void SlaveMachine::updatePowerSts(int mainPower, int backPower)
{
    this->m_mainPower = mainPower;
    this->m_backPower = backPower;
}

quint16 SlaveMachine::N_CRC16(uchar *data,int len)
{
    uchar uchCRCHi = 0xff;
    uchar uchCRCLo = 0xff;
    quint16  uindex;
    while (len--) {
        uindex  = uchCRCHi ^ *data++;
        uchCRCHi = uchCRCLo ^ CRC_High[uindex];
        uchCRCLo = CRC_Low[uindex];
    }
    return (uchCRCHi<<8|uchCRCLo);
}
