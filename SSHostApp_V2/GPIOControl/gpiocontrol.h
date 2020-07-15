#ifndef GPIOCONTROL_H
#define GPIOCONTROL_H

#include <QObject>

class GPIOPin
{
public:
    GPIOPin();
    int m_fdVal;
    void initPin(const char *devValue);
    void writePin(const char *buf);
    void readPin(char *buf, const char *devValue);
};

class GPIOControl : public QObject
{
    Q_OBJECT
public:
    explicit GPIOControl(QObject *parent = 0);
    void initVar();
    void defaultState();
    void controlPin(int type);
    char readPinState(int type);
    void controlBuzzType(int type);
    void controlSelfCheck(int type);
    bool resetBtnTest();

    bool mainPowerTest();
    bool backPowertest();
private:
    GPIOPin *m_mainPowerNormalLed;//主电正常指示灯
    GPIOPin *m_mainPowerErrorLed; //主电故障指示灯
    GPIOPin *m_backPowerNormalLed;//备电正常指示灯
    GPIOPin *m_backPowerErrorLed; //备电故障指示灯
    GPIOPin *m_alarmLed;          //报警指示灯
    GPIOPin *m_errorled;          //故障指示灯
    GPIOPin *m_canLed;            //通讯指示灯
    GPIOPin *m_buzzSwitch;        //蜂鸣器开关
    GPIOPin *m_buzzType;          //蜂鸣器类型
    GPIOPin *m_resetBtn;          //复位按钮
    GPIOPin *m_Relay_1;           //继电器1
    GPIOPin *m_Relay_2;           //继电器2
    GPIOPin *m_mainPowerState;    //主电状态,low-noraml,high-error
    GPIOPin *m_backPowerState;    //备电状态,low-noraml,high-error
    GPIOPin *m_backErrorState;    //备电故障,low-noraml,high-error

    bool m_mainPowerInsert;//存入主电故障
    bool m_backPowerInsert;//存入备电故障

    bool m_mainPower;
    bool m_backPower;
    uint m_mainPowerNormalTimes;//主电检测次数
    uint m_backPowerNormalTimes;//备电检测次数
    uint m_mainPowerErrorTimes;//主电检测次数
    uint m_backPowerErrorTimes;//备电检测次数

    bool m_mainPowerFlag;//主电标志位
    bool m_backPowerFlag;//备电标志位

    void initPins();
    void insertErrorInfo(int loop, int type, int state, int canId, int value, uint time, QString area);

signals:

public slots:
};

#endif // GPIOCONTROL_H
