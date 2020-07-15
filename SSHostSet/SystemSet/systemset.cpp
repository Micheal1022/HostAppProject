#include "confloop.h"
#include "confnetwork.h"
#include "confnode.h"
#include "confpwd.h"
#include "conftime.h"
#include "systemset.h"
#include "confdevice.h"
#include "ui_systemset.h"
#include "CanDataMgm/initcanport.h"
#include <time.h>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>


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


#define ADMIN   1
#define SUPER   2


#define BTNPAGE     0
#define CONFPAGE    1

#define CONFNODE    0
#define CONFTIME    1
#define CONFPWD     2
#define CONFLOOP    3
#define CONFNETWOOR 4
#define CONFDEVICE  5
#define MAINBACK    6
#define CONFBACK    7

SystemSet::SystemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemSet)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(0,0,1024,600);
    initWidget();
    initConnect();


}

SystemSet::~SystemSet()
{
    delete ui;
}

void SystemSet::initWidget()
{
    m_confPwd  = new ConfPwd;
    m_confLoop = new ConfLoop;
    m_confNode = new ConfNode;
    m_confTime = new ConfTime;
    m_confNetWork = new ConfNetWork;
    m_confDevice  = new ConfDevice;

    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfPwd);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfBack);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfNode);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnBackMain);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfTime);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfSystem);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfNetWork);

    ui->stackedWgtConf->addWidget(m_confNode);
    ui->stackedWgtConf->addWidget(m_confTime);
    ui->stackedWgtConf->addWidget(m_confPwd);
    ui->stackedWgtConf->addWidget(m_confLoop);
    ui->stackedWgtConf->addWidget(m_confNetWork);
    ui->stackedWgtConf->addWidget(m_confDevice);

    m_btnGroup = new QButtonGroup;
    m_btnGroup->addButton(ui->tBtnConfNode,   CONFNODE);
    m_btnGroup->addButton(ui->tBtnConfTime,   CONFTIME);
    m_btnGroup->addButton(ui->tBtnConfPwd,    CONFPWD);
    m_btnGroup->addButton(ui->tBtnConfLoop,   CONFLOOP);
    m_btnGroup->addButton(ui->tBtnConfNetWork,CONFNETWOOR);
    m_btnGroup->addButton(ui->tBtnConfSystem, CONFDEVICE);
    m_btnGroup->addButton(ui->tBtnBackMain,   MAINBACK);
    m_btnGroup->addButton(ui->tBtnConfBack,   CONFBACK);



}

void SystemSet::initConnect()
{
    connect(m_btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnGroup(int)));
}

void SystemSet::slotBtnGroup(int index)
{
    switch (index) {
    case CONFNODE:
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(CONFNODE);
        break;
    case CONFTIME:
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(CONFTIME);
        break;
    case CONFPWD:
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(CONFPWD);
        break;
    case CONFLOOP:
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(CONFLOOP);
        break;
    case CONFNETWOOR:
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(CONFNETWOOR);
        break;
    case CONFDEVICE:
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(CONFDEVICE);
        break;
    case MAINBACK:
        this->hide();
        break;
    case CONFBACK:
        ui->stackedWgtBtn->setCurrentIndex(BTNPAGE);
        break;
    }
}
/*
* @项目   TBus_SSEF
* @函数   void slotSendSetValue(int value);
* @描述   处理设置的阈值
* @作者   Micheal(陈明明)
* @时间   2019-04-23
*/
void SystemSet::slotSendSetValue(int cmd,int type,int value)
{
    m_confNode->setValue(cmd,type,value);
}

void SystemSet::confShow(int user)
{
    show();
    ui->stackedWgtBtn->setCurrentIndex(BTNPAGE);
    switch (user) {
    case ADMIN:
        ui->tBtnConfTime->setEnabled(true);
        ui->tBtnConfPwd->setEnabled(false);
        ui->tBtnConfNode->setEnabled(false);
        ui->tBtnConfLoop->setEnabled(false);
        ui->tBtnConfSystem->setEnabled(false);
        ui->tBtnConfNetWork->setEnabled(false);
        break;
    case SUPER:
        ui->tBtnConfTime->setEnabled(true);
        ui->tBtnConfPwd->setEnabled(true);
        ui->tBtnConfNode->setEnabled(true);
        ui->tBtnConfLoop->setEnabled(true);
        ui->tBtnConfSystem->setEnabled(true);
        ui->tBtnConfNetWork->setEnabled(true);
        break;
    }
}

void SystemSet::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}



