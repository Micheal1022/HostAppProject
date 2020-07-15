#ifndef MONITOR_H
#define MONITOR_H

#include <QMap>
#include <QWidget>

namespace Ui {
class Monitor;
}
class QTimer;
class NodeView;
class CanDataMgm;
class GPIOControl;
class QGraphicsDropShadowEffect;
class Monitor : public QWidget
{
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = 0);
    ~Monitor();
    void confShow(int user);
    void setUserLogOut(bool user);

    void controlSelfCheck();

private:
    Ui::Monitor *ui;
    int m_times;
    QTimer *m_systemTimer;
    QTimer *m_resetTimer;
    QTimer *m_canBusTimer;

    int m_curPass;
    int m_curLoop;
    int m_totalPass;
    int m_selfCheckType;
    bool m_selfCheckFlag;
    int m_devType;

    QList<int>  m_LoopList;
    CanDataMgm *m_canDataMgm;
    GPIOControl *m_GPIOControl;
    QMap<int ,NodeView* > m_nodeViewMap;//保存视图的容器

    /* 正常总数*/
    int m_normalCount;
    QList<int> m_normalCountList;
    /*故障总数*/
    int m_errorCount;
    QList<int> m_errorCountList;
    /*报警总数*/
    int m_alarmCount;
    QList<int> m_alarmCountList;
    /*掉线总数*/
    int m_offLineCount;
    QList<int> m_offLineCountList;
    /*电源中断总数*/
    int m_powerLostCount;
    QList<int> m_powerLostCountList;

    bool m_muteOn;
    bool m_mainPower;
    bool m_mainOldPower;
    bool m_backPower;
    bool m_backOldPower;

    void initVar();
    void insertList();
    void replaceList();
    void controlLed();
    void initConnect();
    void resetLoopInfo();
    void calErrorCount();
    void setAlarmLedOn();
    void setAlarmLedOff();
    void setMuteBtnEnable();
    void setMuteBtnDisEnable();

    void setErrorCount(int index, int errorCount);
    void setAlarmCount(int index, int alarmCount);
    void setNormalCount(int index, int normalCount);
    void setOffLineCount(int index, int offLineCount);
    void setPowerLostCount(int index, int powerLostCount);

    void initVariable(QList<int> passList);
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);

signals:
    void sigBackHome();
    void sigBtnReset();
    void sigSendSetValue(int cmd, int value);//查询设置值
private slots:
    void slotBtnMute();
    void slotBtnReset();
    void slotResetTime();
    void slotSystemTime();
    void slotBtnBackHome();
    void slotBtnLoopSwitch();
    void slotCanBusTime();


public slots:
    void slotHeartBeat(int loop);
    void slotRecvCanData(QList<int> dataList);
    void slotNodeInfoCount(int index, int normalCount, int alarmCount, int errorCount, int offLineCount,int powerLostCount);
};

#endif // MONITOR_H
