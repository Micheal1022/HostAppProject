#include "confnode.h"
#include "ui_confnode.h"
#include "CanDataMgm/initcanport.h"
#include <QButtonGroup>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <SQLite/mysqlite.h>
/*探测器型号*/
#define N_UREG  0x00
#define N_LEAK  0x01
#define N_TEMP  0x02
#define N_ACV3  0x11
#define N_ACI3  0x12
#define N_ACV   0x13
#define N_ACI   0x14
#define N_DCV   0x15
#define N_DCI   0x16

#define DEV_EFMQ  0
#define DEV_PMFE  1

ConfNode::ConfNode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfNode)
{
    ui->setupUi(this);
    //CANDI
    QRegExp regExpCanId("^([1-9][0-9])|(1[0-1][0-9])|(12[0-9])|0$");//0-128
    ui->lineEditCanId->setValidator(new QRegExpValidator(regExpCanId,this));
    //回路地址
    QRegExp regExpLoop("^[1-12]$");//1-4
    ui->lineEditLoop->setValidator(new QRegExpValidator(regExpLoop,this));
    //温度阈值
    QRegExp regExpSetTemp("^(([5-9][0-9])|(1[0-3][0-9])|140)$");//55-140
    ui->lineEditSetTemp->setValidator(new QRegExpValidator(regExpSetTemp, this));
    //漏电阈值
    QRegExp regExpSetLeak("^([2-9][0-9][0-9])|(1[0-9][0-9][0-9])|2000$");//200-2000
    ui->lineEditSetLeak->setValidator(new QRegExpValidator(regExpSetLeak, this));
    //固有漏电
    QRegExp regExpBaseLeak("([1-9][0-9]{1,2})|1000|0$");//0-1000
    ui->lineEditSetBase->setValidator(new QRegExpValidator(regExpBaseLeak, this));
    //电流变比
    QRegExp regExpSetRadio("^([2-9][0-9][0-9])|(1[0-9][0-9][0-9])|2000$");//200-2000
    ui->lineEditSetLeak->setValidator(new QRegExpValidator(regExpSetRadio, this));

    m_unSelectStr = "QToolButton{font: 18pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(0, 122, 165);background-color: rgb(255, 255, 255);}";
    m_selectStr   = "QToolButton{font: 18pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(255, 255, 255);background-color: rgb(0, 122, 165);}";

    m_btnSelect<<true<<false<<false<<false;
    m_btnTypeGroup = new QButtonGroup;
    m_btnTypeGroup->addButton(ui->tBtnLeak, 0);
    m_btnTypeGroup->addButton(ui->tBtnTemp, 1);
    m_btnTypeGroup->addButton(ui->tBtnRatio,2);
    m_btnTypeGroup->addButton(ui->tBtnVol,  3);
    connect(m_btnTypeGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnTypeIndex(int)));

    //获取可用的设备
    QSqlDatabase devdb = MySQLite::openConnection();
    int devType = MySQLite::getDevType(devdb);
    MySQLite::closeConnection(devdb);
    if (DEV_EFMQ == devType) {
        ui->tBtnRatio->setVisible(false);
        ui->tBtnCalibr->setVisible(false);
        ui->tBtnLeak->setStyleSheet(m_selectStr);
        ui->stackedWidget->setCurrentIndex(0);
    } else if (DEV_PMFE == devType) {
        ui->tBtnLeak->setVisible(false);
        ui->tBtnTemp->setVisible(false);
        ui->tBtnRatio->setStyleSheet(m_selectStr);
        ui->stackedWidget->setCurrentIndex(2);
    }

    m_tbtnGroup = new QButtonGroup;
    m_tbtnGroup->addButton(ui->tBtnRecvLeak, 0);
    m_tbtnGroup->addButton(ui->tBtnRecvTemp, 1);
    m_tbtnGroup->addButton(ui->tBtnRecvBase, 2);
    m_tbtnGroup->addButton(ui->tBtnRecvRatio,3);
    m_tbtnGroup->addButton(ui->tBtnSendLeak, 4);
    m_tbtnGroup->addButton(ui->tBtnSendTemp, 5);
    m_tbtnGroup->addButton(ui->tBtnSendBase, 6);
    m_tbtnGroup->addButton(ui->tBtnSendRatio,7);
    m_tbtnGroup->addButton(ui->tBtnCalibr,   8);
    connect(m_tbtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotTBtnIndex(int)));
    for (int index = 0 ; index < m_tbtnGroup->buttons().count(); index++) {
        setGraphicsEffect(new QGraphicsDropShadowEffect,m_tbtnGroup->button(index));
    }

    m_btnKeyGroup = new QButtonGroup;
    m_btnKeyGroup->addButton(ui->tBtn_0,0);
    m_btnKeyGroup->addButton(ui->tBtn_1,1);
    m_btnKeyGroup->addButton(ui->tBtn_2,2);
    m_btnKeyGroup->addButton(ui->tBtn_3,3);
    m_btnKeyGroup->addButton(ui->tBtn_4,4);
    m_btnKeyGroup->addButton(ui->tBtn_5,5);
    m_btnKeyGroup->addButton(ui->tBtn_6,6);
    m_btnKeyGroup->addButton(ui->tBtn_7,7);
    m_btnKeyGroup->addButton(ui->tBtn_8,8);
    m_btnKeyGroup->addButton(ui->tBtn_9,9);
    m_btnKeyGroup->addButton(ui->tBtn_del,10);
    connect(m_btnKeyGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnKeyIndex(int)));

}

ConfNode::~ConfNode()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数   void setValue(int value);
* @描述   处理设置的阈值
* @作者   Micheal(陈明明)
* @时间   2019-04-23
*/
void ConfNode::setValue(int cmd, int type, int value)
{
    switch (cmd) {
    case SCMD_QALARM:
        if(type == N_LEAK) {
            ui->lineEditSetLeak->setText(QString::number(value));
        } else if (type == N_TEMP) {
            ui->lineEditSetTemp->setText(QString::number(value));
        }
        break;
    case SCMD_QHAVE:
        ui->lineEditSetBase->setText(QString::number(value));
        break;
    case SCMD_QRATIO:
        ui->lineEditSetRatio->setText(QString::number(value));
        break;
    }
}

void ConfNode::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

/*
* @项目   TBus_SSEF
* @函数   void slotChkNodeType();
* @描述   改变类型配置标签
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void ConfNode::slotBtnTypeIndex(int index)
{
    ui->lineEditSetLeak->clear();
    ui->lineEditSetBase->clear();
    ui->lineEditSetTemp->clear();
    ui->lineEditSetRatio->clear();
    ui->stackedWidget->setCurrentIndex(index);

    switch (index) {
    case 0:
        m_btnSelect[0] = true;
        m_btnSelect[1] = false;
        m_btnSelect[2] = false;
        m_btnSelect[3] = false;
        ui->tBtnLeak->setStyleSheet(m_selectStr);
        ui->tBtnTemp->setStyleSheet(m_unSelectStr);
        ui->tBtnRatio->setStyleSheet(m_unSelectStr);
        ui->tBtnVol->setStyleSheet(m_unSelectStr);
        break;
    case 1:
        m_btnSelect[0] = false;
        m_btnSelect[1] = true;
        m_btnSelect[2] = false;
        m_btnSelect[3] = false;
        ui->tBtnLeak->setStyleSheet(m_unSelectStr);
        ui->tBtnTemp->setStyleSheet(m_selectStr);
        ui->tBtnRatio->setStyleSheet(m_unSelectStr);
        ui->tBtnVol->setStyleSheet(m_unSelectStr);
        break;
    case 2:
        m_btnSelect[0] = false;
        m_btnSelect[1] = false;
        m_btnSelect[2] = true;
        m_btnSelect[3] = false;
        ui->tBtnLeak->setStyleSheet(m_unSelectStr);
        ui->tBtnTemp->setStyleSheet(m_unSelectStr);
        ui->tBtnRatio->setStyleSheet(m_selectStr);
        ui->tBtnVol->setStyleSheet(m_unSelectStr);
        break;
    case 3:
        m_btnSelect[0] = false;
        m_btnSelect[1] = false;
        m_btnSelect[2] = false;
        m_btnSelect[3] = true;
        ui->tBtnLeak->setStyleSheet(m_unSelectStr);
        ui->tBtnTemp->setStyleSheet(m_unSelectStr);
        ui->tBtnRatio->setStyleSheet(m_unSelectStr);
        ui->tBtnVol->setStyleSheet(m_selectStr);
        break;
    }

}

void ConfNode::slotTBtnIndex(int index)
{
    uint loop  = ui->lineEditLoop->text().toUInt();
    uint canId = ui->lineEditCanId->text().toUInt();
    if (ui->lineEditLoop->text().isEmpty() || ui->lineEditCanId->text().isEmpty()) {
        QMessageBox::information(this,tr("错误提示"),tr("回路或ID不能为空"),tr("关闭"));
        return;
    }
    switch (index) {
    case 0:
        //发送查询漏电阈值命令
        InitCanPort::sendCmdDate(loop,canId,SCMD_QALARM,N_LEAK,0);
        QMessageBox::information(this,tr("操作提示"),tr("设置漏电阈值命令已发送!"),tr("关闭"));
        break;
    case 1:
        //发送查询温度阈值命令
        InitCanPort::sendCmdDate(loop,canId,SCMD_QALARM,N_TEMP,0);
        QMessageBox::information(this,tr("操作提示"),tr("设置温度阈值命令已发送!"),tr("关闭"));
        break;
    case 2:
        //发送查询固有值命令
        InitCanPort::sendCmdDate(loop,canId,SCMD_QHAVE,N_LEAK,0);
        QMessageBox::information(this,tr("操作提示"),tr("设置漏电固有值命令已发送!"),tr("关闭"));
        break;
    case 3:
        //发送查询变比值命令
        InitCanPort::sendCmdDate(loop,canId,SCMD_QRATIO,N_ACI3,0);
        QMessageBox::information(this,tr("操作提示"),tr("设置电流变比值命令已发送!"),tr("关闭"));
        break;
    case 4:
        //发送设置漏电阈值命令
        if (ui->lineEditSetLeak->text().isEmpty()) {
            QMessageBox::information(this,tr("错误提示"),tr("漏电阈值不能为空!"),tr("关闭"));
            return;
        }
        if (ui->lineEditSetLeak->text().toUInt() > 1500) {
            QMessageBox::information(this,tr("错误提示"),tr("漏电阈值不能超过1500!"),tr("关闭"));
            return;
        }
        InitCanPort::sendCmdDate(loop,canId,SCMD_SALARM,N_LEAK,0,ui->lineEditSetLeak->text().toUInt());
        break;
    case 5:
        //发送设置温度阈值命令
        if ( ui->lineEditSetTemp->text().isEmpty()) {
            QMessageBox::information(this,tr("错误提示"),tr("温度阈值不能为空!"),tr("关闭"));
            return;
        }
        if (ui->lineEditSetTemp->text().toUInt() > 150) {
            QMessageBox::information(this,tr("错误提示"),tr("温度阈值不能超过150!"),tr("关闭"));
            return;
        }
        InitCanPort::sendCmdDate(loop,canId,SCMD_SALARM,N_TEMP,0,ui->lineEditSetTemp->text().toUInt());
        break;
    case 6:
        //发送设置固有值命令
        if (ui->lineEditSetBase->text().isEmpty()) {
            QMessageBox::information(this,tr("错误提示"),tr("漏电固有值不能为空!"),tr("关闭"));
            return;
        }
        if (ui->lineEditSetLeak->text().toUInt() > 1500) {
            QMessageBox::information(this,tr("错误提示"),tr("漏电固有值不能超过1500!"),tr("关闭"));
            return;
        }
        InitCanPort::sendCmdDate(loop,canId,SCMD_SHAVE,N_LEAK,0,ui->lineEditSetBase->text().toUInt());
        break;
    case 7:
        //发送设置变比值命令
        if (ui->lineEditSetRatio->text().isEmpty()) {
            QMessageBox::information(this,tr("错误提示"),tr("电流变比值不能为空!"),tr("关闭"));
            return;
        }
        InitCanPort::sendCmdDate(loop,canId,SCMD_SRATIO,N_ACI3,0,ui->lineEditSetRatio->text().toUInt());
        break;
    case 8:
        if (m_btnSelect[0] == true) {
            //发送漏电校准命令
            InitCanPort::sendCmdDate(loop,0,SCMD_SCALIB,N_LEAK,0,0);
        } else if (m_btnSelect[1] == true) {
            //发送温度校准命令
            InitCanPort::sendCmdDate(loop,0,SCMD_SCALIB,N_TEMP,0,0);
        } else if (m_btnSelect[3] == true) {
            //发送电压校准命令
            InitCanPort::sendCmdDate(loop,0,SCMD_SCALIB,0,0,0);
        }
        break;
    }
}

void ConfNode::slotBtnKeyIndex(int index)
{
    QString text = m_btnKeyGroup->button(index)->text();
    if (index == 10) {
        if (focusWidget() == NULL) {
            return;
        }
        if (focusWidget()->inherits("QLineEdit")) {
            QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
            edit->clear();
        }
    } else {
        if (focusWidget() == NULL) {
            return;
        }
        if (focusWidget()->inherits("QLineEdit")) {
            QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
            QString curStr = edit->text();
            edit->setText(curStr+text);
        }
    }
}

