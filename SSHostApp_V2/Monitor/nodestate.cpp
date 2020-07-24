#include "nodestate.h"
#include "ui_nodestate.h"
#include <QDateTime>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QGraphicsDropShadowEffect>
#include "MsgBox/msgbox.h"
#include "SQLite/mysqlite.h"
#include "CanDataMgm/initcanport.h"
#include "includes.h"




NodeState::NodeState(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodeState)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setModal(true);
    hide();
    m_valueTimer = new QTimer;
    connect(m_valueTimer,SIGNAL(timeout()),this,SLOT(slotTimeOut()));
    connect(ui->tBtnBack,SIGNAL(clicked(bool)),this,SLOT(slotBtnHide()));

    //获取可用的设备
    QSqlDatabase devdb = MySQLite::openConnection();
    m_hostType = MySQLite::getDevType(devdb);
    MySQLite::closeConnection(devdb);
    if (DEV_EFMQ == m_hostType) {
        m_rowCount = 21;
    } else if (DEV_PMFE == m_hostType) {
        m_rowCount = 9;
    }
    initNodeTable(ui->tableWidget,m_hostType);

    for (int canId = 0; canId < CANDINUM; canId++) {
        QList<bool> passEnable;
        for (int index = 0; index <= m_rowCount; index++) {
            passEnable.append(false);
        }
        m_passEnableList.insert(canId,passEnable);
    }
}

NodeState::~NodeState()
{
    delete ui;
}

void NodeState::showNodeInfo(int loop, int canId, int nodeType, QString area)
{
    show();
    m_loop = loop;
    m_canId= canId;
    m_nodeType = nodeType;
    itemClear();
    m_valueTimer->start(TIMER);
    ui->lbLocal->setText(area);/*安装位置*/
    ui->lbCurId->setText(QString::number(canId));
    ui->lbNodeType->setText(getNodeTypeStr(m_nodeType));

    if (m_nodeType == MOD_THER) {
        m_rowCount = 21;
        ui->tableWidget->horizontalHeaderItem(3)->setText(tr("最高温度"));
        ui->tableWidget->horizontalHeaderItem(4)->setText(tr("最低温度"));
        ui->tableWidget->horizontalHeaderItem(5)->setText(tr("平均温度"));
    } else if (m_nodeType == MOD_L1T4 || m_nodeType == MOD_L12T4) {
        m_rowCount = 12;
        ui->tableWidget->horizontalHeaderItem(3)->setText(tr("实时值"));
        ui->tableWidget->horizontalHeaderItem(4)->setText(tr("报警值"));
        ui->tableWidget->horizontalHeaderItem(5)->setText(tr("设定值"));
    } else {
        m_rowCount = 9;
        ui->tableWidget->horizontalHeaderItem(3)->setText(tr("Ua/Ia/1路"));
        ui->tableWidget->horizontalHeaderItem(4)->setText(tr("Ub/Ib/2路"));
        ui->tableWidget->horizontalHeaderItem(5)->setText(tr("Uc/Ic/2路"));
    }
    QFont ft("文泉驿等宽微米黑",10);
    QTableWidgetItem *item;
    ui->tableWidget->setRowCount(m_rowCount);
    for (int row = 0; row < m_rowCount; row++) {
        ui->tableWidget->setRowHeight(row,35);
        for (int column = 0;column < ui->tableWidget->columnCount();column++)  {
            item = new QTableWidgetItem;
            item->setFont(ft);
            item->setTextColor(QColor(0, 122, 165));
            item->setTextAlignment(Qt::AlignCenter);
            if (column == 0) {
                item->setText(QString::number(row+1));
            } else {
                item->setText("--");
            }
            ui->tableWidget->setItem(row,column,item);
        }
    }
}

QString NodeState::getStateStr(int state)
{
    QString stateStr;
    switch (state) {
    case N_NOMAL:
        stateStr = tr("通道正常");
        break;
    case N_LOSTPOWER:
        stateStr = tr("电源中断");
        break;
    case N_OVERVOL:
        stateStr = tr("过压故障");
        break;
    case N_OVERCUR:
        stateStr = tr("过流故障");
        break;
    case N_UNDERVOL:
        stateStr = tr("欠压故障");
        break;
    case N_LOSTPHASE:
        stateStr = tr("缺相故障");
        break;
    case N_ERRORPHASE:
        stateStr = tr("错相故障");
        break;
    case N_ERROR:
        stateStr = tr("传感器故障");
        break;
    case N_ALARM:
        stateStr = tr("通道报警");
        break;
    case N_OFFLINE:
        stateStr = tr("通讯故障");
        break;
    case N_COVER:
        stateStr = tr("视频遮挡");
        break;
    case N_DISCON:
        stateStr = tr("设备断网");
        break;
    case N_COVDIS:
        stateStr = tr("遮挡+断网");
        break;
    default:
        stateStr = tr("--");
        break;
    }
    return stateStr;
}

QString NodeState::getNodeTypeStr(int nodeType)
{
    QString nodeTypeStr;
//    switch (nodeType) {
//    case MOD_L1T4:
//        nodeTypeStr = tr("一体式探测器");
//        break;
//    case MOD_L8T4:
//        nodeTypeStr = tr("组合式探测器");
//        break;
//    case MOD_EARC:
//        nodeTypeStr = tr("电弧探测器");
//        break;
//    case MOD_PYRO:
//        nodeTypeStr = tr("热解探测器");
//        break;
//    case MOD_THER:
//        nodeTypeStr = tr("热成像探测器");
//        break;
//    case MOD_2VA:
//        nodeTypeStr = tr("三相电压电流");
//        break;
//    case MOD_VA:
//        nodeTypeStr = tr("三相电压电流");
//        break;
//    case MOD_A:
//        nodeTypeStr = tr("三相电流");
//        break;
//    case MOD_3V:
//        nodeTypeStr = tr("三相电压");
//        break;
//    case MOD_2V:
//        nodeTypeStr = tr("三相电压");
//        break;
//    case MOD_V:
//        nodeTypeStr = tr("三相电压");
//        break;
//    case MOD_6V3A:
//        nodeTypeStr = tr("单相电压电流");
//        break;
//    case MOD_6V:
//        nodeTypeStr = tr("单相电压");
//        break;
//    case MOD_3A:
//        nodeTypeStr = tr("单相电流");
//        break;
//    default:
//        nodeTypeStr = tr("--");
//        break;
//    }
    switch (nodeType) {
    case MOD_L1T4:
        nodeTypeStr = tr("L1T4");
        break;
    case MOD_L12T4:
        nodeTypeStr = tr("L12T4");
        break;
    case MOD_EARC:
        nodeTypeStr = tr("EARC");
        break;
    case MOD_PYRO:
        nodeTypeStr = tr("PYRO");
        break;
    case MOD_THER:
        nodeTypeStr = tr("THER");
        break;
    case MOD_2VA:
        nodeTypeStr = tr("2VA");
        break;
    case MOD_VA:
        nodeTypeStr = tr("VA");
        break;
    case MOD_A:
        nodeTypeStr = tr("A");
        break;
    case MOD_3V:
        nodeTypeStr = tr("3V");
        break;
    case MOD_2V:
        nodeTypeStr = tr("2V");
        break;
    case MOD_V:
        nodeTypeStr = tr("V");
        break;
    case MOD_6V3A:
        nodeTypeStr = tr("6V3A");
        break;
    case MOD_6V:
        nodeTypeStr = tr("6V");
        break;
    case MOD_3A:
        nodeTypeStr = tr("3A");
        break;
    default:
        nodeTypeStr = tr("--");
        break;
    }
    return nodeTypeStr;
}



void NodeState::initNodeTable(QTableWidget *tableWidget,int hostType)
{

    if (hostType == DEV_EFMQ) {
        m_headListEF<<tr("通道")<<tr("类型")<<tr("状态")<<tr("实时值")<<tr("报警值")<<tr("设定值");
        tableWidget->setColumnCount(m_headListEF.size());
        tableWidget->setHorizontalHeaderLabels(m_headListEF);
    } else if (hostType == DEV_PMFE) {
        m_headListPM<<tr("通道")<<tr("类型")<<tr("状态")<<tr("Ua/Ia/1路")<<tr("Ub/Ib/2路")<<tr("Uc/Ic/3路");
        tableWidget->setColumnCount(m_headListPM.size());
        tableWidget->setHorizontalHeaderLabels(m_headListPM);
    }

    tableWidget->horizontalHeader()->setFixedHeight(40);
    tableWidget->horizontalHeader()->setDefaultSectionSize(140);
    QString hstyleStr ="QHeaderView::section{font: 14pt '文泉驿等宽微米黑'; background-color: rgb(0, 122, 165);"
                       "color: white;}";
    QString vstyleStr ="QHeaderView::section{font: 12pt '文泉驿等宽微米黑'; background-color: rgb(0, 122, 165);"
                       "color: white;}";
    //tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->verticalHeader()->setStyleSheet(vstyleStr);
    tableWidget->verticalHeader()->setFixedWidth(50);
    tableWidget->verticalHeader()->setEnabled(false);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignRight | Qt::AlignVCenter);

    tableWidget->horizontalHeader()->setStyleSheet(hstyleStr);
    tableWidget->horizontalHeader()->setEnabled(false);
    tableWidget->horizontalHeader()->setVisible(true);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->horizontalHeader()->setHighlightSections(false);
    tableWidget->setStyleSheet("QTableWidget::item:selected {color: rgb(255, 255, 255);background-color: rgb(72, 199, 221);}");

    tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);//单元格不可编
    //tableWidget->setSelectionBehavior (QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    tableWidget->setSelectionMode (QAbstractItemView::NoSelection); //设置选择模式，选择单行

    tableWidget->setColumnWidth(0,50);
    tableWidget->setColumnWidth(1,200);
    tableWidget->setColumnWidth(2,200);
    tableWidget->setColumnWidth(3,180);
    tableWidget->setColumnWidth(4,180);
    tableWidget->setColumnWidth(5,180);
    QFont ft("文泉驿等宽微米黑",10);
    QTableWidgetItem *item;
    ui->tableWidget->setRowCount(m_rowCount);
    for (int row = 0; row < m_rowCount; row++) {
        ui->tableWidget->setRowHeight(row,35);
        for (int column = 0;column < ui->tableWidget->columnCount();column++)  {
            item = new QTableWidgetItem;
            item->setFont(ft);
            item->setTextColor(QColor(0, 122, 165));
            item->setTextAlignment(Qt::AlignCenter);
            if (column == 0) {
                item->setText(QString::number(row+1));
            } else {
                item->setText("--");
            }
            ui->tableWidget->setItem(row,column,item);
        }
    }
}


void NodeState::updateTableData(int canId, int pass, int ptype, int pstate, int value_1, int value_2, int value_3)
{
    //判断通道是否启用
    if (pstate > 0) {
        m_passEnableList[canId].replace(pass,true);
        qDebug("*********************************");
        qDebug()<<m_passEnableList.value(canId);
    } else {
        m_passEnableList[canId].replace(pass,false);
        qDebug("*********************************");
        qDebug()<<m_passEnableList.value(canId);
    }

    if (0 == pstate && 0 == pass && 0 == ptype) {
        return;
    }

    if (canId != m_canId) {
        return;
    }

    if (pass <= 0) {
        return;
    }

    QString passStr,typeStr,stateStr,value1Str,value2Str,value3Str;

    passStr  = QString::number(pass);
    stateStr = getStateStr(pstate);
    switch (ptype) {
    case N_LEAK:
        typeStr = tr("漏电");
        value1Str = QString::number(value_1)+tr(" mA");
        value2Str = QString::number(value_2)+tr(" mA");
        value3Str = QString::number(value_3)+tr(" mA");
        break;
    case N_TEMP:
        typeStr = tr("温度");
        value1Str = QString::number(value_1)+tr(" ℃");
        value2Str = QString::number(value_2)+tr(" ℃");
        value3Str = QString::number(value_3)+tr(" ℃");
        break;
    case N_THER:
        typeStr = tr("热成像");
        if (value_1 > 0x7FFF) {
            value_1 = 0xFFFF - value_1;
            value1Str = QString("-") + QString::number(value_1/10) +"."+ QString::number(value_1%10)+tr(" ℃");
        } else {
            value1Str = QString::number(value_1/10) +"."+ QString::number(value_1%10)+tr(" ℃");
        }

        if (value_2 > 0x7FFF) {
            value_2 = 0xFFFF - value_2;
            value2Str = QString("-") + QString::number(value_2/10) +"."+ QString::number(value_2%10)+tr(" ℃");
        } else {
            /*温度数值 = 整数+"."+小数*/
            value2Str = QString::number(value_2/10) +"."+ QString::number(value_2%10)+tr(" ℃");
        }

        if (value_3 > 0x7FFF) {
            value_3 = 0xFFFF - value_3;
            value3Str = QString("-") + QString::number(value_3/10) +"."+ QString::number(value_3%10)+tr(" ℃");
        } else {
            value3Str = QString::number(value_3/10) +"."+ QString::number(value_3%10)+tr(" ℃");
        }

        break;
    case N_ACV3:
        typeStr = tr("三相电压");
        value1Str = QString::number(value_1/10)+tr(" V");
        value2Str = QString::number(value_2/10)+tr(" V");
        value3Str = QString::number(value_3/10)+tr(" V");
        break;
    case N_ACI3:
        typeStr = tr("三相电流");
        /*电流数值 = 整数+"."+小数*/
        value1Str = QString::number(value_1/10) +"."+ QString::number(value_1%10)+tr(" A");
        value2Str = QString::number(value_2/10) +"."+ QString::number(value_2%10)+tr(" A");
        value3Str = QString::number(value_3/10) +"."+ QString::number(value_3%10)+tr(" A");
        break;
    case N_ACV:
        typeStr = tr("单相电压");
        value1Str = QString::number(value_1/10)+tr(" V");
        value2Str = tr("--");
        value3Str = tr("--");
        break;
    case N_ACI:
        typeStr = tr("单相电流");
        /*电流数值 = 整数+"."+小数*/
        value1Str = QString::number(value_1/10) +"."+ QString::number(value_1%10)+tr(" A");
        value2Str = tr("--");
        value3Str = tr("--");
        break;
    case N_DCV:
        typeStr = tr("直流电压");
        value1Str = QString::number(value_1/10)+tr(" V");
        value2Str = QString::number(value_2/10)+tr(" V");
        value3Str = QString::number(value_3/10)+tr(" V");
        break;
    case N_DCI:
        typeStr = tr("直流电流");
        /*电流数值 = 整数+"."+小数*/
        value1Str = QString::number(value_1/10) +"."+ QString::number(value_1%10)+tr(" A");
        value2Str = QString::number(value_2/10) +"."+ QString::number(value_2%10)+tr(" A");
        value3Str = QString::number(value_3/10) +"."+ QString::number(value_3%10)+tr(" A");
        break;
    default:
        typeStr   = tr("--");
        value1Str = tr("--");
        value2Str = tr("--");
        value3Str = tr("--");
        break;
    }

    for (int column = 0; column < ui->tableWidget->columnCount(); column++) {
        switch (column) {
        case N_PASS:
            ui->tableWidget->item(pass-1,column)->setText(passStr);
            break;
        case N_TYPE:
            ui->tableWidget->item(pass-1,column)->setText(typeStr);
            break;
        case N_STATE:
            ui->tableWidget->item(pass-1,column)->setText(stateStr);
            break;
        case N_VALUE_1:
            ui->tableWidget->item(pass-1,column)->setText(value1Str);
            break;
        case N_VALUE_2:
            ui->tableWidget->item(pass-1,column)->setText(value2Str);
            break;
        case N_VALUE_3:
            ui->tableWidget->item(pass-1,column)->setText(value3Str);
            break;
        }
    }
}

void NodeState::recvCanData(int canId, int pass, int ptype, int pstate, int value_1, int value_2, int value_3)
{
    updateTableData(canId, pass, ptype, pstate, value_1, value_2, value_3);
}

void NodeState::itemClear()
{
    for (int row = 0; row < ui->tableWidget->rowCount(); row++) {
        for (int column = 1;column < ui->tableWidget->columnCount();column++)  {
            ui->tableWidget->item(row,column)->setText("--");
        }
    }
}

void NodeState::slotTimeOut()
{
    if (m_nodeType == MOD_THER) {
        InitCanPort::sendCmdDate(m_loop,m_canId,SCMD_UPDATE,0,0);
    } else {
        QList<bool> passEnable = m_passEnableList.value(m_canId);
        for (int pass = 1; pass <= m_rowCount; pass++) {
            if (passEnable.value(pass) == true) {
                InitCanPort::sendCmdDate(m_loop,m_canId,SCMD_UPDATE,0,0,pass);
            }
        }
    }
}

void NodeState::slotBtnHide()
{
    hide();
    m_valueTimer->stop();
}

/*
 * 每一个数据用两个字节整数表示,高位在前,低位在后 带符号整数
 * 范围 -32768---32767 上传数据需除十,
 * 正数的范围为16进制0X0000-0X7FFF,
 * 负数采用正数的补码方式传输,其范围为16进制 0X8000-0XFFFF，
 * 温度上传16进制0X00FF,对应十进制255,表示 25.5 摄氏度
 * 温度上传16进制0XFF9B,对应十进制100(0XFFFF-0XFF9B = 0X64),表示-10.0摄氏度
 */
