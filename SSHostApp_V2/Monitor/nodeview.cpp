#include "dbthead.h"
#include "nodeview.h"
#include "nodeinfo.h"
#include "stateinfo.h"
#include "nodestate.h"
#include "ui_nodeview.h"
#include "MsgBox/msgbox.h"
#include <QDebug>
#include <QTimer>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QScrollBar>
#include <QMessageBox>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QGraphicsDropShadowEffect>

#include "includes.h"



NodeView::NodeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NodeView)
{
    ui->setupUi(this);
    initWidget();
    initVariable();
    initConnect();
    initNodeLayout();
}

void NodeView::confNodeView(int loop, int index)
{
    m_loop = loop;
    m_index = index;
    QList<QStringList> nodeInfoList = getNodeInfoList(loop);//
    initNodeState(nodeInfoList);
    //qDebug()<<"nodeInfoList : "<<nodeInfoList;
    m_nodeCount = nodeInfoList.count();
    m_pageCount = getPageCount(m_nodeCount) - 1;
    if(m_pageCount > 0)
    {
        ui->tBtnNestPage->setEnabled(true);
    }

    ui->lbNodeCount->setText(QString::number(m_nodeCount));

    DBThead *dbThread = new DBThead;
    QThread *thread = new QThread;
    dbThread->moveToThread(thread);
    thread->start();
    connect(this,SIGNAL(sigInsertAlarmInfo(int,int,int,int,int,int,uint,QString)),
            dbThread,SLOT(slotInsertAlarmInfo(int,int,int,int,int,int,uint,QString)));
    //配置完成后发送回路板工作命令

    //
    m_heartTimer = new QTimer;
    connect(m_heartTimer,SIGNAL(timeout()),this,SLOT(slotHeartTimer()));
    m_heartTimer->start(HEARTTIME);

    m_UdpDataTimer = new QTimer;
    connect(m_UdpDataTimer,SIGNAL(timeout()),this,SLOT(slotUdpDateTimer()));
    m_UdpDataTimer->start(300);

}
/*
* @项目   TBus_SSEF
* @函数   void resetNodeInfo();
* @描述   复位节点信息
* @作者   Micheal(陈明明)
* @时间   2019-04-29
*/
void NodeView::resetNodeInfo()
{
    for(int index = 0; index < m_nodeInfoList.size();index++)
    {
        m_nodeInfoList[index].m_nodeState = "0";
        m_nodeInfoList[index].m_alarmLock = "0";
        m_nodeInfoList[index].m_normalflag= false;
        m_nodeInfoList[index].m_errorFlag = false;
        m_nodeInfoList[index].m_alarmFlag = false;
        m_nodeInfoList[index].m_offLineFlag = false;
        m_nodeInfoList[index].m_powerLostFlag = false;
        m_nodeInfoList[index].m_overVolFlag = false;
        m_nodeInfoList[index].m_overCurFlag = false;
        m_nodeInfoList[index].m_lackVolFlag = false;
        m_nodeInfoList[index].m_lackPhaFlag = false;
        m_nodeInfoList[index].m_errorPhaFlag= false;
    }
}

void NodeView::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

NodeView::~NodeView()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数   void recvCanData(QList<int> dataList);
* @描述   接收数据与状态
* @作者   Micheal(陈明明)
* @时间   2019-03-13
*/

void NodeView::recvCanData(QList<int> dataList)
{
    //接收到心跳命令
    recvHeartBeat();
    //更新节点数值，通过故障类型判断数值显示为报警锁定，传感器故障，通讯故障,正常
    //qDebug()<<"dataList : "<<dataList;
    int loop    = dataList.value(LOOP);
    int cmd     = dataList.value(CMD);
    int type    = dataList.value(TYPE);
    int state   = dataList.value(STATE);
    int canId   = dataList.value(CANID);
    int value_1 = dataList.value(VALUE_1);
    int value_2 = dataList.value(VALUE_2);
    int value_3 = dataList.value(VALUE_3);
    int pass    = dataList.value(PASS);
    int pstate  = dataList.value(PSTATE);
    int ptype   = dataList.value(PTYPE);

    m_nodeState->recvCanData(canId,pass,ptype,pstate,value_1,value_2,value_3);
    if (cmd == 0x02) {
        return;
    }
    //更新节点状态
    int index = m_btnIndexList.indexOf(canId);//获得按钮的节点
    if (index == -1)//判断该节点是否存在，不存在返回-1
        return;

    m_nodeInfoList[index].m_nodeType = QString::number(type);//设置类型
    m_nodeInfoList[index].m_nodeState= QString::number(state);
    QString nodeStr = QString::number(loop)+"-"+QString::number(canId)+"\n"+getTypeStr(type);//设置类型
    m_tBtnGroup->button(index)->setText(nodeStr);

    QString alarmTime = QDateTime::currentDateTime().toString(tr("yyyy-MM-dd hh:mm:ss"));
    QString nodeArea  = m_nodeInfoList.value(index).m_nodeArea;

    switch (state) {
    case N_NORMAL:
        //如果该节点发生过报警,不能自动恢复正常绿色
        if (m_nodeInfoList[index].m_normalflag == false) {
            if (m_nodeInfoList[index].m_alarmFlag == false) {
                m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(14, 221, 111);");
            }
            setNodeStateFlag(state,index,canId);
            QStringList normalList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_normalList.append(normalList);
        }
        break;
    case N_ERROR:
        if (m_nodeInfoList[index].m_errorFlag == false) {
            if (m_nodeInfoList[index].m_alarmFlag == false) {
                m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 255, 0);");
            }
            setNodeStateFlag(state,index,canId);
            //故障列表
            QStringList errorList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_errorList.append(errorList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_OFFLINE:
        if (m_nodeInfoList[index].m_offLineFlag == false) {
            if(m_nodeInfoList[index].m_alarmFlag == false)//如果掉线之前位发生报警,设置为黄色
                m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(171, 171, 171);");
            setNodeStateFlag(state,index,canId);
            //故障列表
            QStringList offLineList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_offLineList.append(offLineList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_ALARM:
        if (m_nodeInfoList[index].m_alarmFlag == false) {
            setNodeStateFlag(state,index,canId);
            m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 77, 70);");
            //报警列表
            m_nodeInfoList[index].m_alarmLock = QString::number(value_1);

            if (isContains(m_alarmList,loop,state,canId) == false) {
                QStringList alarmList = addStringList(loop,type,state,canId,value_1,alarmTime,nodeArea);
                m_alarmList.append(alarmList);
            }
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,value_1,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_POWERLOST:
        if (m_nodeInfoList[index].m_powerLostFlag == false) {
            setNodeStateFlag(state,index,canId);
            m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 77, 70);");
            //中断列表
            QStringList powerLostList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_powerLostList.append(powerLostList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_OVERVOL:
        if (m_nodeInfoList[index].m_overVolFlag == false) {
            setNodeStateFlag(state,index,canId);
            m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 233, 32);");
            //过压列表
            QStringList errorList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_errorList.append(errorList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_OVERCUR:
        if (m_nodeInfoList[index].m_overCurFlag == false) {
            setNodeStateFlag(state,index,canId);
            m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 233, 32);");
            //过流列表
            QStringList errorList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_errorList.append(errorList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_LACKVOL:
        if (m_nodeInfoList[index].m_lackVolFlag == false) {
            setNodeStateFlag(state,index,canId);
            m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 233, 32);");
            //欠压列表
            QStringList errorList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_errorList.append(errorList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_LACKPHA:
        if (m_nodeInfoList[index].m_lackPhaFlag == false) {
            setNodeStateFlag(state,index,canId);
            m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 233, 32);");
            //却相列表
            QStringList errorList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_errorList.append(errorList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    case N_ERRORPHA:
        if (m_nodeInfoList[index].m_errorPhaFlag == false) {
            setNodeStateFlag(state,index,canId);
            m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(255, 233, 32);");
            //错相列表
            QStringList errorList = addStringList(loop,type,state,canId,0,alarmTime,nodeArea);
            m_errorList.append(errorList);
        }
        emit sigInsertAlarmInfo(loop,ptype,pstate,canId,0,pass,QDateTime::currentDateTime().toTime_t(),nodeArea);
        break;
    }

    emit sigNodeInfoCount(m_index,m_normalList.count(),m_alarmList.count(),m_errorList.count(),m_offLineList.count(),m_powerLostList.count());
}

/*d
* @项目   TBus_SSEF
* @函数   void initWidget();
* @描述   初始化界面UI
* @作者   Micheal(陈明明)
* @时间   2019-03-12
*/
void NodeView::initWidget()
{
    ui->tBtnLastPage->setEnabled(false);
    ui->tBtnNestPage->setEnabled(false);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnLastPage);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnNestPage);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnAlarmInfo);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnErrorInfo);
}
/*
* @项目   TBus_SSEF
* @函数   void initConnect();
* @描述   初始化信号槽函数
* @作者   Micheal(陈明明)
* @时间   2019-03-12
*/
void NodeView::initConnect()
{
    connect(this,SIGNAL(sigSetValue(int)),ui->scrollArea->verticalScrollBar(),SLOT(setValue(int)));
    connect(ui->tBtnLastPage,SIGNAL(clicked(bool)),this,SLOT(slotLastPage()));
    connect(ui->tBtnNestPage,SIGNAL(clicked(bool)),this,SLOT(slotNestPage()));
    connect(ui->tBtnAlarmInfo,SIGNAL(clicked(bool)),this,SLOT(slotAlarmInfo()));
    connect(ui->tBtnErrorInfo,SIGNAL(clicked(bool)),this,SLOT(slotErrorInfo()));
    connect(ui->tBtnOffLineInfo,SIGNAL(clicked(bool)),this,SLOT(slotOffLineInfo()));
}
/*
* @项目   TBus_SSEF
* @函数   void initVariable();
* @描述   初始化成员变量
* @作者   Micheal(陈明明)
* @时间   2019-03-12
*/
void NodeView::initVariable()
{
    m_heartBeat = 0;
    m_nodeCount = 0;
    m_pageCount = 0;
    m_currentIndex = -1;
    m_currentPage = 0;
    m_loopError = false;
    m_alarmList.clear();
    m_errorList.clear();
    m_offLineList.clear();
    m_powerLostList.clear();
    m_btnIndexList.clear();

    //获取可用的设备
    QSqlDatabase devdb = MySQLite::openConnection();
    int devType = MySQLite::getDevType(devdb);
    MySQLite::closeConnection(devdb);
    if (DEV_EFMQ == devType) {
        m_monitorType = ElectricFire;
        ui->tBtnAlarmInfo->setText(tr("报警信息"));
    } else if (DEV_PMFE == devType) {
        m_monitorType = PowerMonitor;
        ui->tBtnAlarmInfo->setText(tr("电源中断"));
    }
    m_nodeState = new NodeState;

}
/*
* @项目   TBus_SSEF
* @函数   void initNodeState(QList<QStringList> nodeInfoList);
* @描述   初始化节点信息和节点显示按钮
* @作者   Micheal(陈明明)
* @时间   2019-03-11
*/
void NodeView::initNodeState(QList<QStringList> nodeInfoList)
{
    m_tBtnGroup = new QButtonGroup;
    for (int index = 0;index < nodeInfoList.count();index++) {
        //节点存储列表
        BtnUnitInfo btnUnitInfo;
        btnUnitInfo.initData(nodeInfoList.value(index));
        m_nodeInfoList.append(btnUnitInfo);
        //初始化按钮，设置大小，文本
        QToolButton *tBtn = new QToolButton(ui->scrollAreaWidgetContents);
        tBtn->setFocusPolicy(Qt::ClickFocus);
        tBtn->setMinimumSize(QSize(90, 60));
        tBtn->setMaximumSize(QSize(90, 60));
        tBtn->setText(btnUnitInfo.m_nodeLoop+"-"+btnUnitInfo.m_nodeId+tr("\n未注册"));
        //显示按钮索引
        m_btnIndexList.append(btnUnitInfo.m_nodeId.toInt());
        //添加到按钮管理容器
        m_tBtnGroup->addButton(tBtn,index);
        //添加布局
        int column = index % COLUMNSIZE;
        int row = index / COLUMNSIZE;
        m_gridLayout->addWidget(tBtn, row, column, 1, 1);
    }
    connect(m_tBtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotNodeBtnGroup(int)));
}
/*
* @项目   TBus_SSEF
* @函数   QStringList addStringList(int loop, int canId, int type, int state, int value, QString alarmTime, QString area);
* @描述   添加信息列表
* @作者   Micheal(陈明明)
* @时间   2019-04-02
*/
QStringList NodeView::addStringList(int loop, int type, int state, int canId, int value, QString alarmTime, QString area)
{
    QString loopStr  = QString::number(loop);
    QString stateStr = QString::number(state);
    QString typeStr  = QString::number(type);
    QString canIdStr = QString::number(canId);
    QString valueStr = QString::number(value);;
    QStringList strList;
    strList<<loopStr<<typeStr<<stateStr<<canIdStr<<valueStr<<alarmTime<<area;
    return strList;
}
/*
* @项目   TBus_SSEF
* @函数   void delStringList(QList<QStringList> &stringList, int loop, int canId, int state);
* @描述   删除信息列表
* @作者   Micheal(陈明明)
* @时间   2019-04-02
*/
void NodeView::delStringList(QList<QStringList> &stringList, int canId, int state)
{
    QString canIdStr = QString::number(canId);
    QString stateStr = QString::number(state);
    for (int index = 0;index < stringList.count();index++) {
        if (stringList.at(index).at(L_STATE) == stateStr && stringList.at(index).at(L_CANID) == canIdStr) {
            stringList.removeAt(index);
        }
    }
}

bool NodeView::isContains(QList<QStringList> stringList, int loop, int state, int canId)
{
    for (int i = 0; i < stringList.count();i++) {
        if(stringList.value(i).at(0).toInt() == loop && stringList.value(i).at(2).toInt() == state && stringList.value(i).at(3).toInt() == canId) {
            return true;
        }
    }
    return false;
}


void NodeView::initNodeLayout()
{
    QVBoxLayout *verticalLayout = new QVBoxLayout(ui->scrollAreaWidgetContents);
    verticalLayout->setSpacing(5);
    verticalLayout->setContentsMargins(5, 0, 5, 5);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(5);

    m_gridLayout = new QGridLayout();
    m_gridLayout->setHorizontalSpacing(15);
    m_gridLayout->setVerticalSpacing(10);
    m_gridLayout->setContentsMargins(5, 5, 0, 0);

    horizontalLayout->addLayout(m_gridLayout);
    QSpacerItem *horizontalSpacer = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacer);

    verticalLayout->addLayout(horizontalLayout);
    QSpacerItem *verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    verticalLayout->addItem(verticalSpacer);

    ui->scrollArea->verticalScrollBar()->setSingleStep(PAGESTEP);
}
/*
* @项目   TBus_SSEF
* @函数   int getPageCount(int nodeCount);
* @描述   根据节点个数计算总共有多少页
* @作者   Micheal(陈明明)
* @时间   2019-03-12
*/
int NodeView::getPageCount(int nodeCount)
{
    int pageCount;
    pageCount = nodeCount / NODECOUNT;
    if((nodeCount % NODECOUNT) > 0)
    {
        pageCount += 1;
    }
    return pageCount;
}
/*
* @项目   TBus_SSEF
* @函数   QList<QStringList> getNodeInfoList(int loop);
* @描述   获取当前回路的节点
* @作者   Micheal(陈明明)
* @时间   2019-03-11
*/
QList<QStringList> NodeView::getNodeInfoList(int loop)
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("NODEINFO.db");
    }

    if (!database.open()) {
        qDebug() << "Error: Failed to connect database."<< database.lastError();
    } else {
        qDebug() << "Succeed to connect database : loop "<< loop;
    }

    QList<QStringList> nodeInfoStringList;
    QString sqlQuery = "select LOOP,ID,ABLE,AREA from NODELIST where LOOP = "+QString::number(loop)+" and ABLE = 1 order by ID asc;";
    QSqlQuery query(database);

    if (query.exec(sqlQuery)) {
        while (query.next()) {
            QStringList nodeStringList;
            nodeStringList.append(query.value(0).toString());
            nodeStringList.append(query.value(1).toString());
            nodeStringList.append(query.value(2).toString());
            nodeStringList.append(query.value(3).toString());
            nodeInfoStringList.append(nodeStringList);
        }
    }
    query.finish();
    query.clear();
    database.close();
    //QT数据库移除
    QSqlDatabase::removeDatabase("QSQLITE");
    return nodeInfoStringList;
}

void NodeView::insertNode()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("NODEINFO.db");
    }
    QSqlQuery query(database);

    for (int id = 25;id < 129;id++) {
        QString sql = "insert into NODELIST values(1,"+QString::number(id)+",1,'----');";
        query.exec(sql);
    }
    query.finish();
    query.clear();

}
/*
* @项目   TBus_SSEF
* @函数   void slotAlarmInfo();
* @描述   显示报警信息列表
* @作者   Micheal(陈明明)
* @时间   2019-04-01
*/
void NodeView::slotAlarmInfo()
{
    StateInfo alarmStateInfo;
    if (m_monitorType == ElectricFire) {
        alarmStateInfo.showInfo(m_alarmList,StateInfo::AlarmInfo);
    } else if (m_monitorType == PowerMonitor) {
        alarmStateInfo.showInfo(m_powerLostList,StateInfo::PowerLost);
    }
    alarmStateInfo.exec();
}
/*
* @项目   TBus_SSEF
* @函数   void slotErrorInfo();
* @描述   显示故障信息列表
* @作者   Micheal(陈明明)
* @时间   2019-04-01
*/
void NodeView::slotErrorInfo()
{
    StateInfo errorStateInfo;
    if (m_monitorType == ElectricFire) {
        errorStateInfo.showInfo(m_errorList,StateInfo::ErrorInfo);
    } else if(m_monitorType == PowerMonitor) {
        errorStateInfo.showInfo(m_errorList,StateInfo::PowerError);
    }
    errorStateInfo.exec();
}

void NodeView::slotOffLineInfo()
{
    StateInfo errorStateInfo;
    errorStateInfo.showInfo(m_offLineList,StateInfo::OffLine);
    errorStateInfo.exec();
}
/*
* @项目   TBus_SSEF
* @函数   void recvHeartBeat();
* @描述   接收心跳命令
* @作者   Micheal(陈明明)
* @时间   2019-04-09
*/
void NodeView::recvHeartBeat()
{
    m_heartBeat = 0;
    m_loopError = false;
}
/*
* @项目   TBus_SSEF
* @函数   void slotHeartTimer();
* @描述   心跳标志检测
* @作者   Micheal(陈明明)
* @时间   2019-04-09
*/
void NodeView::slotHeartTimer()
{
    m_heartBeat++;
    if(m_heartBeat == LOOPERROR)
    {
        m_heartBeat = 0;
        if(m_loopError == false)
        {
            m_loopError = true;
            //回路板故障loop
            //发送报警记录到线程
            //emit sigInsertAlarmInfo(m_loop,0xAA,N_LOOPERR,0,0,QDateTime::currentDateTime().toTime_t(),tr("----"));
        }
    }
}
//发送数据到远程客户端
void NodeView::slotUdpDateTimer()
{
    m_currentIndex++;
    if (m_currentIndex < m_nodeInfoList.count()) {
        int nodeType = m_nodeInfoList.value(m_currentIndex).m_nodeType.toInt();
        int nodeState = m_nodeInfoList.value(m_currentIndex).m_nodeState.toInt();
        int nodeCanId = m_nodeInfoList.value(m_currentIndex).m_nodeId.toInt();
        QString nodeArea = m_nodeInfoList.value(m_currentIndex).m_nodeArea;
        if (nodeType == 1) {
            QList<int>  valueList;
            int leakValue = m_nodeInfoList.value(m_currentIndex).m_leakValue.toInt();
            int leakLock = m_nodeInfoList.value(m_currentIndex).m_alarmLock.toInt();
            int leakSet = m_nodeInfoList.value(m_currentIndex).m_leakSet.toInt();
            valueList<<leakValue<<leakLock<<leakSet;
            emit sigSendUdpData(m_currentIndex,m_loop,nodeCanId,nodeType,nodeState,valueList,nodeArea);
        } else {
            QList<int> valueList;
            int tempValue = m_nodeInfoList.value(m_currentIndex).m_tempValue.toInt();
            int tempLock = m_nodeInfoList.value(m_currentIndex).m_alarmLock.toInt();
            int tempSet = m_nodeInfoList.value(m_currentIndex).m_tempSet.toInt();
            valueList<<tempValue<<tempLock<<tempSet;
            emit sigSendUdpData(m_currentIndex,m_loop,nodeCanId,nodeType,nodeState,valueList,nodeArea);
        }
    } else {
        m_currentIndex = -1;
    }
}
//复位
void NodeView::slotReset()
{
    m_UdpDataTimer->stop();
    m_currentIndex=-1;
    m_loopError = false;
    m_errorList.clear();
    m_alarmList.clear();
    m_normalList.clear();
    m_offLineList.clear();
    m_powerLostList.clear();
    resetNodeInfo();

    for (int index = 0;index < m_nodeInfoList.size();index++) {
        //QString text = m_nodeInfoList.value(index).m_nodeLoop+"-"+m_nodeInfoList.value(index).m_nodeId+tr("\n未注册");
        //m_tBtnGroup->button(index)->setText(text);
        m_tBtnGroup->button(index)->setStyleSheet("background-color: rgb(14, 221, 111);");
    }
    m_UdpDataTimer->start();
}

void NodeView::slotNodeBtnGroup(int curBtn)
{
    uint type = m_nodeInfoList.value(curBtn).m_nodeType.toUInt();
    if(type == MOD_UREG) {
        MsgBox::showInformation(NULL,tr(" 节点提示"),tr("当前节点未注册，不能显示相关信息!"),tr("关闭"));
        return;
    }
    uint loop = m_nodeInfoList.value(curBtn).m_nodeLoop.toUInt();
    uint canId = m_nodeInfoList.value(curBtn).m_nodeId.toUInt();
    m_curCanId = canId;
    QString area = m_nodeInfoList.value(curBtn).m_nodeArea;
    m_nodeState->showNodeInfo(loop,canId,type,area);
}
/*
* @项目   TBus_SSEF
* @函数   void slotLastPage();
* @描述   向上翻一页
* @作者   Micheal(陈明明)
* @时间   2019-03-11
*/
void NodeView::slotLastPage()
{
    m_currentPage--;
    if (m_currentPage > 0) {
        emit sigSetValue(m_currentPage*PAGESTEP);
        ui->tBtnNestPage->setEnabled(true);
    } else if (m_currentPage == 0) {
        emit sigSetValue(m_currentPage*PAGESTEP);
        ui->tBtnLastPage->setEnabled(false);
    }
    ui->tBtnNestPage->setEnabled(true);
}
/*
* @项目   TBus_SSEF
* @函数   void slotNestPage();
* @描述   向下翻一页
* @作者   Micheal(陈明明)
* @时间   2019-03-11
*/
void NodeView::slotNestPage()
{
    m_currentPage++;
    if (m_currentPage < m_pageCount) {
        emit sigSetValue(m_currentPage*PAGESTEP);
        ui->tBtnNestPage->setEnabled(true);
    } else if (m_currentPage == m_pageCount) {
        emit sigSetValue(m_currentPage*PAGESTEP);;
        ui->tBtnNestPage->setEnabled(false);
    }
    ui->tBtnLastPage->setEnabled(true);
}

QString NodeView::getStateStr(int state)
{
    QString stateStr;
    switch (state) {
    case N_NORMAL:
        stateStr = tr("节点正常");
        break;
    case N_POWERLOST:
        stateStr = tr("电源中断");
        break;
    case N_OVERVOL:
        stateStr = tr("节点过压");
        break;
    case N_OVERCUR:
        stateStr = tr("节点过流");
        break;
    case N_LACKVOL:
        stateStr = tr("节点欠压");
        break;
    case N_LACKPHA:
        stateStr = tr("节点缺相");
        break;
    case N_ERRORPHA:
        stateStr = tr("节点错相");
        break;
    case N_ERROR:
        stateStr = tr("节点故障");
        break;
    case N_ALARM:
        stateStr = tr("节点报警");
        break;
    case N_OFFLINE:
        stateStr = tr("节点掉线");
        break;
    }
    return stateStr;
}

QString NodeView::getTypeStr(int type)
{
    QString typeStr;
    switch (type) {
    case MOD_L1T4:
        typeStr = tr("L1T4");
        break;
    case MOD_L12T4:
        typeStr = tr("L12T4");
        break;
    case MOD_THER:
        typeStr = tr("热成像");
        break;
    case MOD_2VA:
        typeStr = tr("2VA");
        break;
    case MOD_VA:
        typeStr = tr("VA");
        break;
    case MOD_A:
        typeStr = tr("A");
        break;
    case MOD_3V:
        typeStr = tr("3V");
        break;
    case MOD_2V:
        typeStr = tr("2V");
        break;
    case MOD_V:
        typeStr = tr("V");
        break;
    case MOD_6V3A:
        typeStr = tr("6V3A");
        break;
    }
    return typeStr;
}
/*
* @项目   TBus_SSEF
* @函数   void setNodeStateFlag(int state);
* @描述   设置电源监控节点状态，只显示当前状态
* @作者   Micheal(陈明明)
* @时间   2019-04-12
*/
void NodeView::setNodeStateFlag(int state, int index ,int canId)
{

    switch (state) {
    case N_NORMAL:
        m_nodeInfoList[index].m_normalflag = true;
        setNodeNormal(index,canId);//设置节点标志位正常
        break;
    case N_ALARM://
        m_nodeInfoList[index].m_alarmFlag = true;
        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_errorList,canId,N_ERROR);
        delStringList(m_normalList,canId,N_NORMAL);
        delStringList(m_offLineList,canId,N_OFFLINE);
        break;
    case N_ERROR://
        m_nodeInfoList[index].m_errorFlag = true;
        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);
        delStringList(m_offLineList,canId,N_OFFLINE);
        break;
    case N_POWERLOST://电源中断
        m_nodeInfoList[index].m_powerLostFlag = true;

        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);
        //删除过压
        m_nodeInfoList[index].m_overVolFlag = false;
        delStringList(m_errorList,canId,N_OVERVOL);
        //删除过流
        m_nodeInfoList[index].m_overCurFlag = false;
        delStringList(m_errorList,canId,N_OVERCUR);
        //删除欠压
        m_nodeInfoList[index].m_lackVolFlag = false;
        delStringList(m_errorList,canId,N_LACKVOL);
        //删除缺相
        m_nodeInfoList[index].m_lackPhaFlag = false;
        delStringList(m_errorList,canId,N_LACKPHA);
        //删除错相
        m_nodeInfoList[index].m_errorPhaFlag= false;
        delStringList(m_errorList,canId,N_ERRORPHA);
        //删除掉线
        m_nodeInfoList[index].m_offLineFlag = false;
        delStringList(m_offLineList,canId,N_OFFLINE);
        break;
    case N_OVERVOL://过压

        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);
        //删除中断
        m_nodeInfoList[index].m_powerLostFlag = false;
        delStringList(m_powerLostList,canId,N_POWERLOST);

        m_nodeInfoList[index].m_overVolFlag = true;
        //删除过流
        m_nodeInfoList[index].m_overCurFlag = false;
        delStringList(m_errorList,canId,N_OVERCUR);
        //删除欠压
        m_nodeInfoList[index].m_lackVolFlag = false;
        delStringList(m_errorList,canId,N_LACKVOL);
        //删除缺相
        m_nodeInfoList[index].m_lackPhaFlag = false;
        delStringList(m_errorList,canId,N_LACKPHA);
        //删除错相
        m_nodeInfoList[index].m_errorPhaFlag= false;
        delStringList(m_errorList,canId,N_ERRORPHA);
        //删除掉线
        m_nodeInfoList[index].m_offLineFlag = false;
        delStringList(m_offLineList,canId,N_OFFLINE);

        break;
    case N_OVERCUR://过流
        m_nodeInfoList[index].m_overCurFlag = true;

        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);
        //删除中断
        m_nodeInfoList[index].m_powerLostFlag = false;
        delStringList(m_powerLostList,canId,N_POWERLOST);
        //删除过压
        m_nodeInfoList[index].m_overVolFlag = false;
        delStringList(m_errorList,canId,N_OVERVOL);
        //删除欠压
        m_nodeInfoList[index].m_lackVolFlag = false;
        delStringList(m_errorList,canId,N_LACKVOL);
        //删除缺相
        m_nodeInfoList[index].m_lackPhaFlag = false;
        delStringList(m_errorList,canId,N_LACKPHA);
        //删除错相
        m_nodeInfoList[index].m_errorPhaFlag= false;
        delStringList(m_errorList,canId,N_ERRORPHA);
        //删除掉线
        m_nodeInfoList[index].m_offLineFlag = false;
        delStringList(m_offLineList,canId,N_OFFLINE);
        break;
    case N_LACKVOL://欠压
        m_nodeInfoList[index].m_lackVolFlag = true;

        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);
        //删除中断
        m_nodeInfoList[index].m_powerLostFlag = false;
        delStringList(m_powerLostList,canId,N_POWERLOST);
        //删除过压
        m_nodeInfoList[index].m_overVolFlag = false;
        delStringList(m_errorList,canId,N_OVERVOL);
        //删除过流
        m_nodeInfoList[index].m_overCurFlag = false;
        delStringList(m_errorList,canId,N_OVERCUR);
        //删除缺相
        m_nodeInfoList[index].m_lackPhaFlag = false;
        delStringList(m_errorList,canId,N_LACKPHA);
        //删除错相
        m_nodeInfoList[index].m_errorPhaFlag= false;
        delStringList(m_errorList,canId,N_ERRORPHA);
        //删除掉线
        m_nodeInfoList[index].m_offLineFlag = false;
        delStringList(m_offLineList,canId,N_OFFLINE);
        break;
    case N_LACKPHA://缺相
        m_nodeInfoList[index].m_lackPhaFlag = true;

        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);
        //删除中断
        m_nodeInfoList[index].m_powerLostFlag = false;
        delStringList(m_powerLostList,canId,N_POWERLOST);
        //删除过压
        m_nodeInfoList[index].m_overVolFlag = false;
        delStringList(m_errorList,canId,N_OVERVOL);
        //删除过流
        m_nodeInfoList[index].m_overCurFlag = false;
        delStringList(m_errorList,canId,N_OVERCUR);
        //删除欠压
        m_nodeInfoList[index].m_lackVolFlag = false;
        delStringList(m_errorList,canId,N_LACKVOL);
        //删除错相
        m_nodeInfoList[index].m_errorPhaFlag= false;
        delStringList(m_errorList,canId,N_ERRORPHA);
        //删除掉线
        m_nodeInfoList[index].m_offLineFlag = false;
        delStringList(m_offLineList,canId,N_OFFLINE);
        break;
    case N_ERRORPHA://错相
        m_nodeInfoList[index].m_errorPhaFlag= true;

        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);
        //删除中断
        m_nodeInfoList[index].m_powerLostFlag = false;
        delStringList(m_powerLostList,canId,N_POWERLOST);
        //删除过压
        m_nodeInfoList[index].m_overVolFlag = false;
        delStringList(m_errorList,canId,N_OVERVOL);
        //删除过流
        m_nodeInfoList[index].m_overCurFlag = false;
        delStringList(m_errorList,canId,N_OVERCUR);
        //删除欠压
        m_nodeInfoList[index].m_lackVolFlag = false;
        delStringList(m_errorList,canId,N_LACKVOL);
        //删除缺相
        m_nodeInfoList[index].m_lackPhaFlag = false;
        delStringList(m_errorList,canId,N_LACKPHA);
        //删除掉线
        m_nodeInfoList[index].m_offLineFlag = false;
        delStringList(m_offLineList,canId,N_OFFLINE);
        break;
    case N_OFFLINE://掉线
        //删除
        m_nodeInfoList[index].m_normalflag = false;
        delStringList(m_normalList,canId,N_NORMAL);

        m_nodeInfoList[index].m_powerLostFlag = false;
        delStringList(m_powerLostList,canId,N_POWERLOST);

        m_nodeInfoList[index].m_errorFlag = false;
        delStringList(m_errorList,canId,N_ERROR);
        //删除过压
        m_nodeInfoList[index].m_overVolFlag = false;
        delStringList(m_errorList,canId,N_OVERVOL);
        //删除过流
        m_nodeInfoList[index].m_overCurFlag = false;
        delStringList(m_errorList,canId,N_OVERCUR);
        //删除欠压
        m_nodeInfoList[index].m_lackVolFlag = false;
        delStringList(m_errorList,canId,N_LACKVOL);
        //删除缺相
        m_nodeInfoList[index].m_lackPhaFlag = false;
        delStringList(m_errorList,canId,N_LACKPHA);
        //删除错相
        m_nodeInfoList[index].m_errorPhaFlag= false;
        delStringList(m_errorList,canId,N_ERRORPHA);

        m_nodeInfoList[index].m_offLineFlag = true;
        m_nodeInfoList[index].m_alarmFlag   = false;
        break;
    }
    emit sigNodeInfoCount(m_index,m_normalList.count(),m_alarmList.count(),m_errorList.count(),m_offLineList.count(),m_powerLostList.count());
}
/*
* @项目   TBus_SSEF
* @函数   void setNodeNormal(int index, int canId);
* @描述   设置节点正常状态
* @作者   Micheal(陈明明)
* @时间   2019-04-12
*/
void NodeView::setNodeNormal(int index, int canId)
{
    //删除故障
    if (m_nodeInfoList[index].m_errorFlag == true) {
        m_nodeInfoList[index].m_errorFlag = false;
        delStringList(m_errorList,canId,N_ERROR);
    }
    //删除掉线
    if (m_nodeInfoList[index].m_offLineFlag == true) {
        m_nodeInfoList[index].m_offLineFlag = false;
        delStringList(m_offLineList,canId,N_OFFLINE);
    }
    //删除中断
    if (m_nodeInfoList[index].m_powerLostFlag == true) {
        delStringList(m_powerLostList,canId,N_POWERLOST);
        m_nodeInfoList[index].m_powerLostFlag = false;
    }
    //删除过压
    if (m_nodeInfoList[index].m_overVolFlag == true) {
        delStringList(m_errorList,canId,N_OVERVOL);
        m_nodeInfoList[index].m_overVolFlag = false;
    }
    //删除过流
    if (m_nodeInfoList[index].m_overCurFlag == true) {
        delStringList(m_errorList,canId,N_OVERCUR);
        m_nodeInfoList[index].m_overCurFlag = false;
    }
    //删除欠压
    if (m_nodeInfoList[index].m_lackVolFlag == true) {
        delStringList(m_errorList,canId,N_LACKVOL);
        m_nodeInfoList[index].m_lackVolFlag = false;
    }
    //删除缺相
    if (m_nodeInfoList[index].m_lackPhaFlag == true) {
        delStringList(m_errorList,canId,N_LACKPHA);
        m_nodeInfoList[index].m_lackPhaFlag = false;
    }
    //删除错相
    if (m_nodeInfoList[index].m_errorPhaFlag == true) {
        delStringList(m_errorList,canId,N_ERRORPHA);
        m_nodeInfoList[index].m_errorPhaFlag = false;
    }
    emit sigNodeInfoCount(m_index,m_normalList.count(),m_alarmList.count(),m_errorList.count(),m_offLineList.count(),m_powerLostList.count());
}
