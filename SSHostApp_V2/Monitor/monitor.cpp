#include "monitor.h"
#include "ui_monitor.h"
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include "nodeview.h"
#include "CanDataMgm/candatamgm.h"
#include "SQLite/mysqlite.h"
#include "GPIOControl/gpiocontrol.h"
#include "MsgBox/msgbox.h"
#include "Record/myprint.h"
#include "UDPServer/udpserver.h"
#include "includes.h"


Monitor::Monitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Monitor)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(0,0,1024,600);

    //获取可用的设备
    QSqlDatabase devdb = MySQLite::openConnection();
    m_devType = MySQLite::getDevType(devdb);
    MySQLite::closeConnection(devdb);

    if (DEV_EFMQ == m_devType) {
        ui->lbAlarm->setVisible(true);
        ui->lbAlarmTotal->setVisible(true);
        ui->lbPowerLost->setVisible(false);
        ui->lbPowerLostTotal->setVisible(false);
    } else if (DEV_PMFE == m_devType) {
        ui->lbAlarm->setVisible(false);
        ui->lbAlarmTotal->setVisible(false);
        ui->lbPowerLost->setVisible(true);
        ui->lbPowerLostTotal->setVisible(true);
    }

    //获取可用的回路
    QSqlDatabase db = MySQLite::openConnection();
    QList<int>  loopConfList = MySQLite::getUsableLoop(db);
    MySQLite::closeConnection(db);
    initVariable(loopConfList);
    initConnect();
}

Monitor::~Monitor()
{
    delete ui;
}

void Monitor::confShow(int user)
{
    show();
    if (user != 0) {
        ui->tBtnReset->setEnabled(true);
    } else {
        ui->tBtnReset->setEnabled(false);
    }
}

void Monitor::setUserLogOut(bool user)
{
    ui->tBtnReset->setEnabled(user);
}
/*
* @项目   TBus_SSEF
* @函数   void resetLoopInfo();
* @描述   复位回路信息
* @作者   Micheal(陈明明)
* @时间   2019-04-29
*/
void Monitor::resetLoopInfo()
{
    m_times   = 0;
    m_curPass = 0;
    m_curLoop = 0;
    m_mainPower = true;
    m_backPower = true;
    m_selfCheckType = 0;
    m_selfCheckFlag = false;
    m_normalCount= 0;
    m_errorCount = 0;
    m_alarmCount = 0;
    m_offLineCount= 0;
    m_powerLostCount = 0;
    ui->lbNormalTotal->setText("0");
    ui->lbAlarmTotal->setText("0");
    ui->lbPowerLostTotal->setText("0");
    ui->lbErrorTotal->setText("0");
    ui->lbOffLineTotal->setText("0");
    replaceList();
    //默认为不可用状态
    m_muteOn = true;
    //显示回路信息
    //ui->stackedWgtPass->setCurrentIndex(0);

}
/*替换链表数据*/
void Monitor::replaceList()
{
    for (int index = 0; index < 12;index++) {
        m_normalCountList.replace(index,0);
        m_alarmCountList.replace(index,0);
        m_errorCountList.replace(index,0);
        m_offLineCountList.replace(index,0);
        m_powerLostCountList.replace(index,0);
    }
}
/*插入链表数据*/
void Monitor::insertList()
{
    for (int index = 0; index < 12;index++) {
        m_normalCountList.insert(index,0);
        m_alarmCountList.insert(index,0);
        m_errorCountList.insert(index,0);
        m_offLineCountList.insert(index,0);
        m_powerLostCountList.insert(index,0);
    }
}
/*
* @项目   TBus_SSEF
* @函数   void initVariable();
* @描述   初始化变量
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
void Monitor::initVariable(QList<int> passList)
{
    initVar();
    insertList();
    //显示回路信息
    m_totalPass = passList.count()-1;
    ui->lbTotalPass->setText(QString::number(passList.count()));//回路总数
    ui->stackedWgtPass->setCurrentIndex(0);

    for (int index = 0;index < passList.count();index++) {
        int loop = passList.at(index);
        m_LoopList.append(loop);
        NodeView *nodeView = new NodeView;
        nodeView->confNodeView(loop,index);
        m_nodeViewMap.insert(loop,nodeView);//存储到MAP
        ui->stackedWgtPass->addWidget(nodeView);//添加到堆栈视图
        UDPServer *udpServer = new UDPServer;
        udpServer->initConf();
        connect(this,SIGNAL(sigBtnReset()),nodeView,SLOT(slotReset()));
        connect(nodeView,SIGNAL(sigNodeInfoCount(int,int,int,int,int,int)),this,SLOT(slotNodeInfoCount(int,int,int,int,int,int)));
        connect(nodeView,SIGNAL(sigSendUdpData(int,int,int,int,int,QList<int>,QString)),udpServer,SLOT(slotSendCanData(int,int,int,int,int,QList<int>,QString)));
    }
    //判断回路开启的数量，配置第一条回路
    if (m_LoopList.count() > 0) {
        ui->stackedWgtPass->setCurrentIndex(m_curLoop);
        ui->tBtnLoopSwitch->setText(tr("回路-")+QString::number(m_LoopList.value(0)));
    } else{
        ui->tBtnLoopSwitch->setText(tr("回路-")+QString::number(0));
    }
    m_GPIOControl = new GPIOControl;
}


void Monitor::initConnect()
{
    m_systemTimer = new QTimer;
    connect(m_systemTimer,SIGNAL(timeout()),this,SLOT(slotSystemTime()));
    m_systemTimer->start(SYSTIME);
    m_resetTimer = new QTimer;
    connect(m_resetTimer,SIGNAL(timeout()),this,SLOT(slotResetTime()));
    m_resetTimer->start(SYSTIME);

    m_canBusTimer = new QTimer;
    connect(m_canBusTimer,SIGNAL(timeout()),this,SLOT(slotCanBusTime()));
    m_canBusTimer->start(SYSTIME/5);

    connect(ui->tBtnMute,SIGNAL(clicked(bool)),this,SLOT(slotBtnMute()));
    connect(ui->tBtnReset,SIGNAL(clicked(bool)),this,SLOT(slotBtnReset()));
    connect(ui->tBtnBackHome,SIGNAL(clicked(bool)),this,SLOT(slotBtnBackHome()));
    connect(ui->tBtnLoopSwitch,SIGNAL(clicked(bool)),this,SLOT(slotBtnLoopSwitch()));

}
/*
* @项目   TBus_SSEF
* @函数   void controlLed();
* @描述   控制指示灯状态
* @作者   Micheal(陈明明)
* @时间   2019-04-25
*/
void Monitor::controlLed()
{
    //报警，故障，离线，主备电故障
}
/*
* @项目   TBus_SSEF
* @函数   void slotSystemTime();
* @描述   系统时钟
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
void Monitor::slotSystemTime()
{
    //2次后时间为1S
    m_times++;
    if (m_times == 2) {
        m_times = 0;
        ui->lbSystemTime->setText(QDateTime::currentDateTime().toString(tr("yyyy年MM月dd日 hh:mm:ss")));
    }

    //selfcheck
    if (true == m_selfCheckFlag ) {
        m_selfCheckType++;
        m_GPIOControl->controlSelfCheck(m_selfCheckType);
        if (m_selfCheckType == 10){
            m_selfCheckType = 0;
            m_selfCheckFlag = false;
            MyPrint::selfCheckFinished();
        }
    } else {
        //计算节点故障
        calErrorCount();
    }
}

void Monitor::slotResetTime()
{
    //复位按键检测
    if (true == m_GPIOControl->resetBtnTest()) {
        slotBtnReset();
    }
}

void Monitor::slotBtnReset()
{
#ifdef RUN_ON_ARM
    if (ui->tBtnReset->isEnabled() == true) {
        int ret = MsgBox::showQuestion(NULL,tr(" 操作提示"), tr("确定要复位系统吗?"),tr("确定"),tr("取消"));
        if (ret == 0) {
            emit sigBtnReset();
            InitCanPort::sendCmdDate(0,0,SCMD_RESET,0,0);
            InitCanPort::sendCmdDate(0,0,SCMD_RESET,0,0);
            resetLoopInfo();
            m_GPIOControl->defaultState();

            QSqlDatabase db  = MySQLite::openConnection();
            MySQLite::insertErrorInfo(0,N_HOST,N_RESET,0,0,QDateTime::currentDateTime().toTime_t(),tr("--------"));
            MySQLite::closeConnection(db);
        }
    } else {
        MsgBox::showInformation(NULL,tr(" 操作提示"), tr("没有权限操作复位!"),tr("关闭"));
    }
#endif
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnMute();
* @描述   消音操按钮
* @作者   Micheal(陈明明)
* @时间   2019-04-28
*/
void Monitor::slotBtnMute()
{
    setMuteBtnDisEnable();
    m_GPIOControl->controlBuzzType(S_NORAML);
    QSqlDatabase db  = MySQLite::openConnection();
    MySQLite::insertErrorInfo(0,N_HOST,N_MUTE,0,0,QDateTime::currentDateTime().toTime_t(),tr("--------"));
    MySQLite::closeConnection(db);
}

/*
* @项目   TBus_SSEF
* @函数   void slotBtnBackHome();
* @描述   返回主界面
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
void Monitor::slotBtnBackHome()
{
    hide();
    emit sigBackHome();
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnLoopSwitch();
* @描述   回路切换，可以循环切换
* @作者   Micheal(陈明明)
* @时间   2019-04-22
*/
void Monitor::slotBtnLoopSwitch()
{
    if (m_curLoop < m_totalPass) {
        m_curLoop++;
    } else if (m_curLoop == m_totalPass) {
        m_curLoop = 0;
    }

    ui->stackedWgtPass->setCurrentIndex(m_curLoop);
    ui->tBtnLoopSwitch->setText(tr("回路-")+QString::number(m_LoopList.value(m_curLoop)));
}

void Monitor::slotCanBusTime()
{
    m_GPIOControl->controlPin(CANBUS_OFF);
}

void Monitor::controlSelfCheck()
{
    m_selfCheckFlag = true;
}

void Monitor::initVar()
{
    m_muteOn = true;
    m_times   = 0;
    m_curPass = 0;
    m_curLoop = 0;
    m_normalCount = 0;
    m_errorCount   = 0;
    m_alarmCount   = 0;
    m_offLineCount   = 0;
    m_powerLostCount = 0;
    m_selfCheckType = 0;
    m_selfCheckFlag = false;
    m_mainPower = true;
    m_backPower = true;
    m_mainOldPower = true;
    m_backOldPower = true;
    //默认为不可用状态
    ui->tBtnReset->setEnabled(false);
    setGraphicsEffect(new QGraphicsDropShadowEffect ,ui->tBtnMute);
    setGraphicsEffect(new QGraphicsDropShadowEffect ,ui->tBtnReset);
    setGraphicsEffect(new QGraphicsDropShadowEffect ,ui->tBtnBackHome);
    setGraphicsEffect(new QGraphicsDropShadowEffect ,ui->tBtnLoopSwitch);
}

/*
* @项目   TBus_SSEF
* @函数   void slotRecvCanData(QList<int> dataList);
* @描述   接收回路板数据，根据不同的回路号，更行相应回路的视图状态
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
void Monitor::slotRecvCanData(QList<int> dataList)
{
    if (m_nodeViewMap.size() > 0) {
        m_GPIOControl->controlPin(CANBUS_ON);
        int loop = dataList.first();//回路号
        //判断是否存在这个回路,没有就返回
        if (!m_nodeViewMap.contains(loop))
            return;
        m_nodeViewMap.value(loop)->recvCanData(dataList);//该回路号对应的视图
    }
}


/*
* @项目   TBus_SSEF
* @函数   void slotHeartBeat(int loop);
* @描述   接收心跳命令
* @作者   Micheal(陈明明)
* @时间   2019-04-23
*/
void Monitor::slotHeartBeat(int loop)
{
    if(false == m_nodeViewMap.contains(loop))
        return;
    m_GPIOControl->controlPin(CANBUS_ON);
    m_nodeViewMap.value(loop)->recvHeartBeat();//该回路号对应的视图
}
/*
* @项目   TBus_SSEF
* @函数   void slotCalCount();
* @描述   计算报警.故障.掉线总数显示
* @作者   Micheal(陈明明)
* @时间   2019-04-12
*/
void Monitor::calErrorCount()
{

    m_mainPower = m_GPIOControl->mainPowerTest();
#ifdef SENSOR
    //报警指示灯状态控制
    if (DEV_PMFE == m_devType) {
        //电源状态检测
        m_backPower = m_GPIOControl->backPowertest();
    }
#else
    m_backPower = m_GPIOControl->backPowertest();
#endif

    //如果有故障存在，故障石指示灯就亮
    if (m_mainOldPower != m_mainPower || m_backOldPower != m_backPower) {
        setMuteBtnEnable();
        m_mainOldPower = m_mainPower;
        m_backOldPower = m_backPower;
    }

    if (false == m_mainPower || false == m_backPower || 0 != m_errorCount || 0 != m_offLineCount || 0 != m_powerLostCount) {
        //判断声音如果已经关闭,在没有新的故障发生,声音应该保持的关闭的状态
        if (true == m_muteOn) {
            if (m_alarmCount == 0) {
                m_GPIOControl->controlBuzzType(S_ERROR);
            } else {
                m_GPIOControl->controlBuzzType(S_ALARM);
            }
        }
        m_GPIOControl->controlPin(ERRORLED_ON);//只要有故障,指示灯就常亮
    }

    //所有的故障都消除并且在没有报警的情况下，声音关闭,所有故障灯熄灭；
    if (true == m_mainPower && true == m_backPower  && 0 == m_errorCount && 0 == m_offLineCount && 0 == m_powerLostCount) {
        //故障指示灯之灭;
        m_GPIOControl->controlPin(ERRORLED_OFF);
        //不存在报警的节点
        if (0 == m_alarmCount) {
            setMuteBtnDisEnable();
            m_GPIOControl->controlBuzzType(S_NORAML);
        } else {//目前 有报警的节点
            if (true == m_muteOn) {
                m_GPIOControl->controlBuzzType(S_NORAML);
            }
        }
    }

    //报警指示灯状态控制
    if (DEV_EFMQ == m_devType) {
        if (0 == m_alarmCount) {
            m_GPIOControl->controlPin(ALARMLED_OFF);
            m_GPIOControl->controlPin(RELAY_1_OFF);
        } else {
            m_GPIOControl->controlPin(ALARMLED_ON);
            m_GPIOControl->controlPin(RELAY_1_ON);
            if (true == m_muteOn) {
                m_GPIOControl->controlBuzzType(S_ALARM);
            }
        }
    }
}

/*
* @项目   TBus_SSEF
* @函数   void setMuteOn();
* @描述   静音按钮可用
* @作者   Micheal(陈明明)
* @时间   2019-04-28
*/
void Monitor::setMuteBtnEnable()
{
    m_muteOn = true;//声音打开
}

void Monitor::setMuteBtnDisEnable()
{
    m_muteOn = false;//声音关闭
}

void Monitor::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}
/*
* @项目   TBus_SSEF
* @函数   void slotErrorCount(int index,errorCount);
* @描述   错误总数计算
* @作者   Micheal(陈明明)
* @时间   2019-04-12
*/
void Monitor::setErrorCount(int index, int errorCount)
{
    if (errorCount > m_errorCountList.value(index)) {
        setMuteBtnEnable();
    }
    m_errorCountList.replace(index,errorCount);
    int errorTotal = 0;
    for (int  i = 0; i< m_errorCountList.count();i++) {
        errorTotal += m_errorCountList.value(i);
    }
    m_errorCount = errorTotal;
    ui->lbErrorTotal->setText(QString::number(m_errorCount));
}
/*
* @项目   TBus_SSEF
* @函数   void slotAlarmCount(int index,alarmCount);
* @描述   报警总数计算
* @作者   Micheal(陈明明)
* @时间   2019-04-12
*/
void Monitor::setAlarmCount(int index, int alarmCount)
{
    //报警的数目只会增加，只需要更新数目就行
    if (alarmCount > m_alarmCountList.value(index)) {
        setMuteBtnEnable();
    }
    m_alarmCountList.replace(index,alarmCount);
    int alarmTotal = 0;
    for (int  i = 0; i < m_alarmCountList.count();i++) {
        alarmTotal += m_alarmCountList.value(i);
    }
    m_alarmCount = alarmTotal;
    ui->lbAlarmTotal->setText(QString::number(m_alarmCount));
}

void Monitor::setPowerLostCount(int index, int powerLostCount)
{
    //报警的数目只会增加，只需要更新数目就行
    if (powerLostCount > m_powerLostCountList.value(index)) {
        setMuteBtnEnable();
    }
    m_powerLostCountList.replace(index,powerLostCount);
    int powerLostTotal = 0;
    for (int  i = 0; i < m_powerLostCountList.count();i++) {
        powerLostTotal += m_powerLostCountList.value(i);
    }
    m_powerLostCount = powerLostTotal;
    ui->lbPowerLostTotal->setText(QString::number(m_powerLostCount));
}

void Monitor::setOffLineCount(int index, int offLineCount)
{
    if (offLineCount > m_offLineCountList.value(index)) {
        setMuteBtnEnable();
    }
    m_offLineCountList.replace(index,offLineCount);
    int offLineTotal = 0;
    for (int  i = 0; i < m_offLineCountList.count();i++) {
        offLineTotal += m_offLineCountList.value(i);
    }
    m_offLineCount = offLineTotal;
    ui->lbOffLineTotal->setText(QString::number(m_offLineCount));
}

void Monitor::setNormalCount(int index, int normalCount)
{
    m_normalCountList.replace(index,normalCount);
    int normalTotal = 0;
    for (int  i = 0; i < m_normalCountList.count();i++) {
        normalTotal += m_normalCountList.value(i);
    }
    m_normalCount = normalTotal;
    ui->lbNormalTotal->setText(QString::number(m_normalCount));
}

void Monitor::slotNodeInfoCount(int index, int normalCount, int alarmCount, int errorCount, int offLineCount, int powerLostCount)
{
    setAlarmCount(index, alarmCount);
    setErrorCount(index, errorCount);
    setNormalCount(index,normalCount);
    setOffLineCount(index, offLineCount);
    setPowerLostCount(index,powerLostCount);
}
