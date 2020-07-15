#include "myprint.h"
#include <QSerialPort>
#include <QDebug>

char MyPrint::m_lf[2]={0x0A,'\0'};
MyPrint *MyPrint::m_print = NULL;
QSerialPort *MyPrint::m_myCom = NULL;

void MyPrint::initSerialPort()
{
    m_myCom = new QSerialPort(QString("/dev/ttymxc1"));
    if (m_myCom->isOpen()) {
        m_myCom->close();
    }

    if (m_myCom->open(QIODevice::ReadWrite)) {
        m_myCom->setBaudRate(QSerialPort::Baud9600);
        //数据位设置，我们设置为8位数据位
        m_myCom->setDataBits(QSerialPort::Data8);
        //奇偶校验设置，我们设置为无校验
        m_myCom->setParity(QSerialPort::NoParity);
        //停止位设置，我们设置为1位停止位
        m_myCom->setStopBits(QSerialPort::OneStop);
        //数据流控制设置，我们设置为无数据流控制
        m_myCom->setFlowControl(QSerialPort::NoFlowControl);
        qDebug()<<"Open print OK !";
    } else {
        qDebug()<<"Open print FAIL !";
    }
}

MyPrint *MyPrint::getInstance()
{
    if(m_print == NULL)
    {
        m_print = new MyPrint();
    }
    return m_print;
}

void MyPrint::selfCheckFinished()
{
    QString compelet = tr("自检完成");
    QByteArray byte = compelet.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //space
    QString space =  tr("  ");
    byte = space.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
}

void MyPrint::printData(QString loop, QString canId, QString pass, QString type, QString state, QString value, QString time, QString addr)
{
    QByteArray byte;
    //打印地址
    QString modAddr =   tr("区域 : ") + addr;
    byte = modAddr.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //打印时间
    QString modTime =   tr("时间 : ") + time;
    byte = modTime.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //数值
    QString modValue =  tr("数值 : ") + value;
    byte = modValue.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //状态
    QString modStatus = tr("状态 : ") + state;
    byte = modStatus.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //打印类型
    QString printType = tr("类型 : ") + type;
    byte = printType.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //打印通道
    QString printPass= tr("通道 :") + pass;
    byte = printPass.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //打印网络和地址
    QString modNetId =  tr("回路 : ")+ loop +tr("    节点 : ")+ canId;
    byte = modNetId.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    //space
    QString space1 =  tr("  ");
    byte = space1.toLocal8Bit();
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);
    m_myCom->write(byte);
    m_myCom->write(m_lf,1);

}

MyPrint::MyPrint()
{

}

MyPrint::~MyPrint()
{
    m_myCom->close();
    delete m_print;
}

