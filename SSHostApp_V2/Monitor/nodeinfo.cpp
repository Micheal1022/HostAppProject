#include "nodeinfo.h"
#include "ui_nodeinfo.h"
#include <QTimer>
#include "CanDataMgm/initcanport.h"
/*移动位置坐标*/
#define X_POS   245
#define Y_POS   190

/*探测器型号*/
#define N_LEAK  0x01
#define N_TEMP  0x02
#define N_ACV3  0x11
#define N_ACI3  0x12
#define N_ACV   0x13
#define N_ACI   0x14
#define N_DCV   0x15
#define N_DCI   0x16
/*探测器状态*/
#define N_NOMAL         0x01//节点正常
#define N_LOSTPOWER     0x02//电源中断
#define N_OVERVOL       0x03//节点过压
#define N_OVERCUR       0x04//节点过流
#define N_UNDERVOL      0x05//节点欠压
#define N_LOSTPHASE     0x06//节点错相
#define N_ERRORPHASE    0x07//节点缺相
#define N_ERROR         0x08//节点故障
#define N_ALARM         0x09//节点报警
#define N_OFFLINE       0x0A//节点掉线

#define TIMER   500
NodeInfo::NodeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodeInfo)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setModal(true);
    hide();
    m_valueTimer = new QTimer;
    connect(m_valueTimer,SIGNAL(timeout()),this,SLOT(slotTimeOut()));
    connect(ui->tBtnBack,SIGNAL(clicked(bool)),this,SLOT(slotBtnHide()));


}

NodeInfo::~NodeInfo()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数   void showNodeValue(uint loop, uint canId);
* @描述   启动定时器，配置回路和节点地址
* @作者   Micheal(陈明明)
* @时间   2019-03-12
*/
void NodeInfo::showNodeValue(uint loop, uint type ,uint state,uint canId, uint value,QString area)
{
    show();
    m_loop = loop;
    m_canId= canId;
    move(X_POS,Y_POS);
    m_valueTimer->start(TIMER);
    setValueType(type);
    setLockValue(type,value);
    ui->lbState->setText(getStateStr(state));
    ui->lbArea->setText(area);/*安装位置*/
    ui->lbCurId->setText(QString::number(canId));
}
/*
* @项目   TBus_SSEF
* @函数   void recvCanData(QList<int> dataList);
* @描述   接受发来的数据
* @作者   Micheal(陈明明)
* @时间   2019-04-02
*/
void NodeInfo::recvCanData(int type,int state,int value_1,int value_2,int value_3)
{
    /*节点类型*/
    setValueType(type);
    switch (type) {
    case N_LEAK:
        ui->lcdNbCurrentLeakValue->display(value_1);
        ui->lcdNbSetLeakValue->display(value_2);
        break;
    case N_TEMP:
        ui->lcdNbCurrentTempValue->display(value_1);
        ui->lcdNbSetTempValue->display(value_2);
        break;
    case N_ACV3:
        ui->lb_AV_1->setText(tr("A相电压值:"));
        ui->lb_BV_2->setText(tr("B相电压值:"));
        ui->lb_CV_3->setText(tr("C相电压值:"));
        ui->lb_BV_2->setVisible(true);
        ui->lb_CV_3->setVisible(true);
        ui->lcdNbBV->setVisible(true);
        ui->lcdNbCV->setVisible(true);

        ui->lcdNbAV->display(value_1/10);
        ui->lcdNbBV->display(value_2/10);
        ui->lcdNbCV->display(value_3/10);
        ui->lbAddr->setText(tr("传感器位置:"));
        break;
    case N_ACI3:
        ui->lb_AI_1->setText(tr("A相电流值:"));
        ui->lb_BI_2->setText(tr("B相电流值:"));
        ui->lb_CI_3->setText(tr("C相电流值:"));
        ui->lb_BI_2->setVisible(true);
        ui->lb_CI_3->setVisible(true);
        ui->lcdNbBI->setVisible(true);
        ui->lcdNbCI->setVisible(true);
        ui->lbUnitB->setVisible(true);
        ui->lbUnitC->setVisible(true);

        /*电流数值 = 整数+"."+小数*/
        ui->lcdNbAI->display(QString::number(value_1/10) +"."+ QString::number(value_1%10));
        ui->lcdNbBI->display(QString::number(value_2/10) +"."+ QString::number(value_2%10));
        ui->lcdNbCI->display(QString::number(value_3/10) +"."+ QString::number(value_3%10));
        ui->lbAddr->setText(tr("传感器位置:"));
        break;
    case N_ACV:
        ui->lb_AV_1->setText(tr("单相电压值:"));
        ui->lb_BV_2->setVisible(false);
        ui->lb_CV_3->setVisible(false);
        ui->lcdNbBV->setVisible(false);
        ui->lcdNbCV->setVisible(false);
        ui->lbUnitB->setVisible(false);
        ui->lbUnitC->setVisible(false);

        ui->lcdNbAV->display(value_1/10);
        ui->lbAddr->setText(tr("传感器位置:"));
        break;
    case N_ACI:
        ui->lb_AI_1->setText(tr("单相电流值:"));
        ui->lb_BI_2->setVisible(false);
        ui->lb_CI_3->setVisible(false);
        ui->lcdNbBI->setVisible(false);
        ui->lcdNbCI->setVisible(false);
        /*电流数值 = 整数+"."+小数*/
        ui->lcdNbAI->display(QString::number(value_1/10) +"."+ QString::number(value_1%10));
        ui->lbAddr->setText(tr("传感器位置:"));
        break;
    case N_DCV:
        ui->lcdNbAV->display(value_1/10);
        ui->lcdNbBV->display(value_2/10);
        ui->lcdNbCV->display(value_3/10);
        ui->lbAddr->setText(tr("传感器位置:"));
        break;
    case N_DCI:
        /*电流数值 = 整数+"."+小数*/
        ui->lcdNbAI->display(QString::number(value_1/10) +"."+ QString::number(value_1%10));
        ui->lcdNbBI->display(QString::number(value_2/10) +"."+ QString::number(value_2%10));
        ui->lcdNbCI->display(QString::number(value_3/10) +"."+ QString::number(value_3%10));
        ui->lbAddr->setText(tr("传感器位置:"));
        break;
    }
    /*节点状态*/
    QString statStr = getStateStr(state);
    ui->lbState->setText(statStr);

}
/*
* @项目   TBus_SSEF
* @函数   void setValueType(int type);
* @描述   控制显示数值的页面栈
* @作者   Micheal(陈明明)
* @时间   2019-04-02
*/
void NodeInfo::setValueType(int type)
{
    switch (type) {
    case N_LEAK:
        ui->lbType->setText(tr("漏电"));
        ui->stackedWidget->setCurrentWidget(ui->pageLeak);
        break;
    case N_TEMP:
        ui->lbType->setText(tr("温度"));
        ui->stackedWidget->setCurrentWidget(ui->pageTemp);
        break;
    case N_ACV3:
        ui->lbType->setText(tr("三相电压"));
        ui->stackedWidget->setCurrentWidget(ui->pageVol);
        break;
    case N_ACI3:
        ui->lbType->setText(tr("三相电流"));
        ui->stackedWidget->setCurrentWidget(ui->pageCur);
        break;
    case N_ACV:
        ui->lbType->setText(tr("单相电压"));
        ui->stackedWidget->setCurrentWidget(ui->pageVol);
        break;
    case N_ACI:
        ui->lbType->setText(tr("单相电流"));
        ui->stackedWidget->setCurrentWidget(ui->pageCur);
        break;
    case N_DCV:
        ui->lbType->setText(tr("直流电压"));
        ui->stackedWidget->setCurrentWidget(ui->pageVol);
        break;
    case N_DCI:
        ui->lbType->setText(tr("直流电流"));
        ui->stackedWidget->setCurrentWidget(ui->pageCur);
        break;
    }
}
/*
* @项目   TBus_SSEF
* @函数   QString getStateStr(int state);
* @描述   获得节点状态的字符串
* @作者   Micheal(陈明明)
* @时间   2019-04-02
*/
QString NodeInfo::getStateStr(int state)
{
    QString stateStr;
    switch (state) {
    case N_NOMAL:
        stateStr = tr("节点正常");
        break;
    case N_LOSTPOWER:
        stateStr = tr("电源中断");
        break;
    case N_OVERVOL:
        stateStr = tr("节点过压");
        break;
    case N_OVERCUR:
        stateStr = tr("节点过流");
        break;
    case N_UNDERVOL:
        stateStr = tr("节点欠压");
        break;
    case N_LOSTPHASE:
        stateStr = tr("节点缺相");
        break;
    case N_ERRORPHASE:
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

void NodeInfo::setLockValue(int type,int value)
{
    switch (type) {
    case N_LEAK:
        ui->lcdNbLockLeakValue->display(value);
        break;
    case N_TEMP:
        ui->lcdNbLockTempValue->display(value);
        break;
    }
}
/*
* @项目   TBus_SSEF
* @函数   void allLcdClean
* @描述   清楚所有LCD显示的数据
* @作者   Micheal(陈明明)
* @时间   2019-04-02
*/
void NodeInfo::allLcdClean()
{
    ui->lcdNbCurrentTempValue->display(0);
    ui->lcdNbLockTempValue->display(0);
    ui->lcdNbSetTempValue->display(0);

    ui->lcdNbAV->display(0);
    ui->lcdNbBV->display(0);
    ui->lcdNbCV->display(0);

    ui->lcdNbAI->display(0);
    ui->lcdNbBI->display(0);
    ui->lcdNbCI->display(0);
}
/*
* @项目   TBus_SSEF
* @函数   void slotTimeOut();
* @描述   定时发送更新数据命令
* @作者   Micheal(陈明明)
* @时间   2019-03-12
*/
void NodeInfo::slotTimeOut()
{
    InitCanPort::sendCmdDate(m_loop,m_canId,SCMD_UPDATE,0,0,0);
}

void NodeInfo::slotBtnHide()
{
    hide();
    m_valueTimer->stop();
}
