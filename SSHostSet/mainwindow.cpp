#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UserLogin/userlogin.h"
#include "SystemSet/systemset.h"
#include "SystemSet/confloop.h"
#include "SystemSet/confnetwork.h"
#include "SystemSet/confnode.h"
#include "SystemSet/confpwd.h"
#include "SystemSet/conftime.h"
#include "SystemSet/systemset.h"
#include "SystemSet/confdevice.h"
#include "CanDataMgm/initcanport.h"
#include <time.h>
#include "MsgBox/recvfile.h"
#include <QMessageBox>
#include <MsgBox/msgbox.h>
#include <QGraphicsDropShadowEffect>
#include <QProcess>
#include <SystemSet/confaddr.h>
#include <CanDataMgm/candatamgm.h>

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

#define USER    0
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
#define NODEMGM     6
#define USERLOGIN   7
#define USERLOGOUT  8
#define CALIBRATION 9
#define CONFBACK    10
#define MAINBACK    11

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(0,0,1024,600);
    initWidget();
    initConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initWidget()
{
    m_confPwd     = new ConfPwd;
    m_recvFile    = new RecvFile;
    m_confLoop    = new ConfLoop;
    m_confNode    = new ConfNode;
    m_confTime    = new ConfTime;
    m_confAddr    = new ConfAddr;
    m_userLoign   = new UserLogin;
    m_confDevice  = new ConfDevice;
    m_confNetWork = new ConfNetWork;

    m_canDataMgm  = new CanDataMgm("can0");

    //添加阴影效果
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfPwd);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnNodeAddr);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfBack);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfNode);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnHostApp);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfTime);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnUserLogin);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnUserLogout);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfSystem);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnCalibration);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnConfNetWork);

    //添加到栈
    ui->stackedWgtConf->addWidget(m_confNode);      //节点配置
    ui->stackedWgtConf->addWidget(m_confTime);      //系统时间
    ui->stackedWgtConf->addWidget(m_confPwd);       //密码设置
    ui->stackedWgtConf->addWidget(m_confLoop);      //回路配置
    ui->stackedWgtConf->addWidget(m_confNetWork);   //网络配置
    ui->stackedWgtConf->addWidget(m_confDevice);    //设备设置
    ui->stackedWgtConf->addWidget(m_confAddr);      //地址管理
    ui->stackedWgtConf->addWidget(m_userLoign);     //用户登陆
    //配置按钮位置
    m_btnGroup = new QButtonGroup;
    m_btnGroup->addButton(ui->tBtnConfNode,   CONFNODE);
    m_btnGroup->addButton(ui->tBtnConfTime,   CONFTIME);
    m_btnGroup->addButton(ui->tBtnConfPwd,    CONFPWD);
    m_btnGroup->addButton(ui->tBtnConfLoop,   CONFLOOP);
    m_btnGroup->addButton(ui->tBtnConfNetWork,CONFNETWOOR);
    m_btnGroup->addButton(ui->tBtnConfSystem, CONFDEVICE);
    m_btnGroup->addButton(ui->tBtnNodeAddr,   NODEMGM);
    m_btnGroup->addButton(ui->tBtnUserLogin,  USERLOGIN);
    m_btnGroup->addButton(ui->tBtnUserLogout, USERLOGOUT);

    m_btnGroup->addButton(ui->tBtnCalibration,CALIBRATION);
    m_btnGroup->addButton(ui->tBtnConfBack,   CONFBACK);
    m_btnGroup->addButton(ui->tBtnHostApp,    MAINBACK);


    ui->tBtnConfPwd->setEnabled(false);
    ui->tBtnConfNode->setEnabled(false);
    ui->tBtnConfLoop->setEnabled(false);
    ui->tBtnNodeAddr->setEnabled(false);
    ui->tBtnConfSystem->setEnabled(false);

}

void MainWindow::initConnect()
{
    connect(m_btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnGroup(int)));
    connect(m_userLoign,SIGNAL(sigUserLogin(int)),this,SLOT(slotSystemShow(int)));
    connect(m_canDataMgm,SIGNAL(sigSendSetValue(int,int,int)),this,SLOT(slotSendSetValue(int,int,int)));

}



void MainWindow::slotBtnGroup(int index)
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
    case USERLOGIN:
        m_userLoign->confShow();
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(USERLOGIN);
        break;
    case USERLOGOUT:
        ui->tBtnUserLogin->setVisible(true);
        ui->tBtnUserLogout->setVisible(false);
        ui->tBtnConfPwd->setEnabled(false);
        ui->tBtnConfNode->setEnabled(false);
        ui->tBtnConfLoop->setEnabled(false);
        ui->tBtnNodeAddr->setEnabled(false);
        ui->tBtnConfSystem->setEnabled(false);
        break;
    case NODEMGM:
        ui->stackedWgtBtn->setCurrentIndex(CONFPAGE);
        ui->stackedWgtConf->setCurrentIndex(NODEMGM);
        break;
    case CALIBRATION:
    {
        QProcess process;
        process.start("/usr/local/tslib/bin/ts_calibrate");
        process.waitForStarted();
        process.waitForFinished(-1);
        repaint();
        MsgBox::showInformation(NULL,tr("系统提示"),tr("完成屏幕校准."),tr("关闭"));
    }
        break;
    case CONFBACK:
        ui->stackedWgtBtn->setCurrentIndex(BTNPAGE);
        break;
    case MAINBACK:
        int ret = MsgBox::showQuestion(NULL,tr("系统提示"),tr("系统将重启,进入监控界面"),tr("确定"),tr("取消"));
        if (0 == ret) {
            ::system("chmod +x /root/SSApp/ssApp && chmod -x /root/SSApp/ssSet && reboot");
        }
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
void MainWindow::slotSendSetValue(int cmd,int type,int value)
{
    m_confNode->setValue(cmd,type,value);
}

void MainWindow::slotSystemShow(int user)
{
    ui->stackedWgtBtn->setCurrentIndex(BTNPAGE);
    switch (user) {
    case ADMIN:
        ui->tBtnUserLogin->setVisible(false);
        ui->tBtnUserLogout->setVisible(true);

        ui->tBtnConfPwd->setEnabled(true);
        ui->tBtnConfNode->setEnabled(true);
        ui->tBtnConfTime->setEnabled(true);
        ui->tBtnConfLoop->setEnabled(false);
        ui->tBtnConfSystem->setEnabled(false);
        ui->tBtnNodeAddr->setEnabled(true);
        break;
    case SUPER:
        ui->tBtnUserLogin->setVisible(false);
        ui->tBtnUserLogout->setVisible(true);

        ui->tBtnConfTime->setEnabled(true);
        ui->tBtnConfPwd->setEnabled(true);
        ui->tBtnConfNode->setEnabled(true);
        ui->tBtnConfLoop->setEnabled(true);
        ui->tBtnConfSystem->setEnabled(true);
        ui->tBtnNodeAddr->setEnabled(true);
        break;
    default:
        ui->tBtnUserLogin->setVisible(true);
        ui->tBtnUserLogout->setVisible(false);

        ui->tBtnConfPwd->setEnabled(false);
        ui->tBtnConfNode->setEnabled(false);
        ui->tBtnConfLoop->setEnabled(false);
        ui->tBtnNodeAddr->setEnabled(false);
        ui->tBtnConfSystem->setEnabled(false);
        break;
    }
}


void MainWindow::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}
