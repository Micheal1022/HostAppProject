#ifndef KEYCHECK_H
#define KEYCHECK_H

#include <QObject>
class QTimer;
class GPIOKeyPin
{
public:
    GPIOKeyPin();
    int m_fdVal;
    void initKeyPin(const char *devValue);
    void readKeyPin(char *buf, const char *devValue);
};

class KeyCheck : public QObject
{
    Q_OBJECT
public:
    explicit KeyCheck(QObject *parent = 0);
    char readKeyState();
private:
    QTimer *m_timer;
    GPIOKeyPin *m_canLed;            //通讯指示灯
    GPIOKeyPin *m_buzzSwitch;        //蜂鸣器开关
    GPIOKeyPin *m_buzzType;          //蜂鸣器类型
    GPIOKeyPin *m_Relay_1;           //继电器1
    GPIOKeyPin *m_Relay_2;           //继电器2
    GPIOKeyPin *m_keyCheck;          //复位按钮
    GPIOKeyPin *m_burnPro;           //烧写程序,low-noraml,high-error
signals:
    void sigkeyCheck();
public slots:
    void slotTimeOut();
};

#endif // KEYCHECK_H
