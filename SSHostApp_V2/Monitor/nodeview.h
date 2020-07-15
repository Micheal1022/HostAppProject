#ifndef NODEVIEW_H
#define NODEVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QButtonGroup>
#include "includes.h"

namespace Ui {
class NodeView;
}

class QGraphicsDropShadowEffect;
class BtnUnitInfo
{
public:

    /********温度***********/
    QString m_tempValue;    //温度实时
    QString m_tempSet;      //温度报警值
    /********漏电***********/
    QString m_leakValue;    //实时数据
    QString m_leakBase;     //固有漏电
    QString m_leakSet;      //漏电报警值
    QString m_alarmLock;    //漏电报警锁定值
    /********状态***********/
    QString m_nodeState;    //模块状态
    QString m_nodeType;     //模块类型
    QString m_nodeArea;     //模块区域
    QString m_nodeLoop;     //模块回路
    QString m_nodeId;       //模块ID
    bool m_normalflag;      //正常
    bool m_errorFlag;       //故障
    bool m_alarmFlag;       //报警
    bool m_offLineFlag;     //掉线

    bool m_powerLostFlag;   //中断
    bool m_overVolFlag;     //过压
    bool m_overCurFlag;     //过流
    bool m_lackVolFlag;     //欠压
    bool m_lackPhaFlag;     //缺相
    bool m_errorPhaFlag;    //错相

    void initData(QStringList nodeInfo){
        m_tempValue = "0";
        m_tempSet = "0";
        m_nodeLoop = nodeInfo.value(N_LOOP);
        m_nodeId   = nodeInfo.value(N_NODEID);

        m_leakValue = "0";
        m_leakBase  = "0";
        m_leakSet   = "0";
        m_alarmLock = "0";
        m_nodeState = "0";
        m_nodeType  = "0";
        m_nodeArea  = nodeInfo.value(N_AREA);
        m_offLineFlag  = false;
        /*电气火灾状态标志位*/
        m_normalflag = false;
        m_errorFlag  = false;
        m_alarmFlag  = false;
        /*电源监控状态标志位*/
        m_powerLostFlag = false;
        m_overVolFlag   = false;
        m_overCurFlag   = false;
        m_lackVolFlag   = false;
        m_lackPhaFlag   = false;
        m_errorPhaFlag  = false;
    }
};
class NodeInfo;
class QTimer;
class NodeState;
class UDPServer;
class NodeView : public QWidget
{
    Q_OBJECT

public:
    explicit NodeView(QWidget *parent = 0);
    ~NodeView();
    void recvCanData(QList<int> dataList);
    void recvHeartBeat();
    enum MonitorType{
        ElectricFire = 0x01,
        PowerMonitor = 0x02
    };
    void confNodeView(int loop, int index);
    void resetNodeInfo();
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);




private:
    Ui::NodeView *ui;
    int m_nodeCount;
    int m_pageCount;
    int m_currentPage;
    int m_heartBeat;
    bool m_loopError;
    int m_monitorType;
    int m_index;
    int m_curCanId;
    int m_loop;
    QString m_normalStyleSheet;
    QString m_errorStyleSheet;
    QString m_alarmStyleSheet;
    QString m_OffLineStyleSheet;
    QTimer *m_heartTimer;
    QTimer *m_UdpDataTimer;
    NodeInfo *m_nodeInfo;
    NodeState *m_nodeState;
    QButtonGroup *m_tBtnGroup;
    QGridLayout *m_gridLayout;
    QList<int> m_btnIndexList;
    QList<QStringList> m_normalList;
    QList<QStringList> m_errorList;
    QList<QStringList> m_alarmList;
    QList<QStringList> m_offLineList;
    QList<QStringList> m_powerLostList;

    QList<BtnUnitInfo> m_nodeInfoList;
    int m_currentIndex;
private:
    void insertNode();
    void initWidget();
    void initConnect();
    void initVariable();
    void initNodeLayout();
    int getPageCount(int nodeCount);
    QList<QStringList> getNodeInfoList(int loop);
    void initNodeState(QList<QStringList> nodeInfoList);
    QStringList addStringList(int loop, int type, int state, int canId, int value, QString alarmTime, QString area);
    void delStringList(QList<QStringList> &stringList, int canId, int state);
    bool isContains(QList<QStringList> stringList, int loop, int state, int canId);
    QString getStateStr(int state);
    QString getTypeStr(int type);
    void setNodeStateFlag(int state, int index, int canId);
    void setNodeNormal(int index, int canId);
signals:
    void sigAlarmCount(int index, int count);
    void sigErrorCount(int index, int count);
    void sigOffLineCount(int index, int count);
    void sigSetValue(int step);
    void sigInsertAlarmInfo(int loop, int type, int state, int canId, int value, int pass, uint time, QString area);
    void sigSendUdpData(int index,int loop, int canId, int type, int state, QList<int> valueList, QString area);

    void sigNodeInfoCount(int index, int normalCount, int alarmCount, int errorCount, int offLineCount, int powerLostCount);
private slots:
    void slotNodeBtnGroup(int curBtn);

    void slotLastPage();
    void slotNestPage();

    void slotAlarmInfo();
    void slotErrorInfo();
    void slotOffLineInfo();

    void slotHeartTimer();
    void slotUdpDateTimer();
    void slotReset();
};

#endif // NODEVIEW_H
