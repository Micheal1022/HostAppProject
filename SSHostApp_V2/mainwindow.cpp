#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Monitor/monitor.h"
#include "SQLite/mysqlite.h"
#include <QTimer>
#include <QMessageBox>
#include <SystemSet/systemset.h>
#include "CanDataMgm/candatamgm.h"
#include <qsqldatabase.h>
#include <UserLogin/userlogin.h>
#include <Record/record.h>
#include "Screen/screen.h"
#include <QGraphicsDropShadowEffect>
#include "MsgBox/msgbox.h"
void MainWindow::initStylesheet()
{

    QFile file(":/StyleSheet/MainWindow.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    file.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(0,0,1024,600);
    setWindowFlags(Qt::FramelessWindowHint);
    initWidget();
    initStylesheet();
    initVariable();
    initConnect();


    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnRecord);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnMonitor);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnLginout);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnSelfCheck);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnSystemSet);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnUserLogin);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initConnect()
{
    connect(ui->tBtnLginout,SIGNAL(clicked(bool)),this,SLOT(slotLogout()));
    connect(ui->tBtnRecord,SIGNAL(clicked(bool)),this,SLOT(slotBtnRecord()));
    connect(ui->tBtnMonitor,SIGNAL(clicked(bool)),this,SLOT(slotBtnMonitor()));
    connect(ui->tBtnSelfCheck,SIGNAL(clicked(bool)),this,SLOT(slotBtnSelfCheck()));
    connect(ui->tBtnSystemSet,SIGNAL(clicked(bool)),this,SLOT(slotBtnSystemSet()));
    connect(ui->tBtnUserLogin,SIGNAL(clicked(bool)),this,SLOT(slotBtnUserLogin()));
    connect(m_userLogin,SIGNAL(sigUserLogin(int)),this,SLOT(slotUserLogin(int)));
    connect(m_canDataMgm,SIGNAL(sigHeartBeat(int)),m_monitor,SLOT(slotHeartBeat(int)));
    /**canDataMgm**/
    connect(m_canDataMgm,SIGNAL(sigSendCanData(QList<int>)),m_monitor,SLOT(slotRecvCanData(QList<int>)));
}

void MainWindow::initVariable()
{
    m_user = 0;
    m_checkSelf = false;
    m_monitor   = new Monitor;
    m_canDataMgm = new CanDataMgm("can0");
    //初始化复位回路板
    InitCanPort::sendCmdDate(0,0,SCMD_WORK,0,0);//host work
    m_screen    = new Screen;
    m_record    = new Record;
    m_userLogin = new UserLogin;

    ui->tBtnSystemError->setVisible(false);
}

void MainWindow::initWidget()
{
#ifdef BEVONE
    ui->lbLogoBevone->setStyleSheet("border-image: url(:/Image/Bevone.png);");
    ui->lbCompany->setText(tr("北京北元安达电子有限公司"));
#elif  SENSOR
    ui->lbLogoSensor->setStyleSheet("border-image: url(:/Image/Sensor.png);");
    ui->lbCompany->setText(tr("西安盛赛尔电子有限公司"));
#endif

    //获取可用的设备
    QSqlDatabase devdb = MySQLite::openConnection();
    int devType = MySQLite::getDevType(devdb);
    MySQLite::closeConnection(devdb);
    if (DEV_EFMQ == devType) {
        ui->lbTitle->setText(tr("电气火灾监控设备"));
        ui->tBtnSystemError->setVisible(false);
        ui->lbVersonEF->setVisible(true);
        ui->lbVersonPM->setVisible(false);
    } else if (DEV_PMFE == devType) {
        ::system("./syserror.sh &");
        ui->lbTitle->setText(tr("消防设备电源监控系统"));
        ui->tBtnSystemError->setVisible(true);
        ui->lbVersonEF->setVisible(false);
        ui->lbVersonPM->setVisible(true);
    }
    ui->tBtnSystemSet->setEnabled(false);
    ui->tBtnSelfCheck->setEnabled(false);
}

void MainWindow::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(5, 5);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(8);
    widget->setGraphicsEffect(effect);
}
/*
* @项目   TBus_SSEF
* @函数   void slotUserLogin(int user);
* @描述   用户登录
* @作者   Micheal(陈明明)
* @时间   2019-04-15
*/
void MainWindow::slotUserLogin(int user)
{
    m_user = user;
    m_monitor->setUserLogOut(true);
    ui->tBtnLginout->setVisible(true);
    ui->tBtnSystemSet->setEnabled(true);
    ui->tBtnSelfCheck->setEnabled(true);
    ui->tBtnUserLogin->setVisible(false);
}

void MainWindow::slotBtnRecord()
{
    m_record->confShow(m_user);
}

void MainWindow::slotBtnMonitor()
{
    m_monitor->confShow(m_user);
}

void MainWindow::slotBtnSystemSet()
{
    int ret = MsgBox::showQuestion(NULL,tr("系统提示"),tr("系统将重启,进入设置界面"),tr("确定"),tr("取消"));
    if (0 == ret) {
        ::system("chmod -x /root/SSApp/ssApp && chmod +x /root/SSApp/ssSet && reboot");
    }
}

void MainWindow::slotBtnUserLogin()
{
    m_userLogin->confShow();
}

void MainWindow::slotBtnSelfCheck()
{
    InitCanPort::sendCmdDate(0,0,SCMD_CHECK,0,0);
    m_screen->startScreen();
    m_monitor->controlSelfCheck();

}

void MainWindow::slotBackHome()
{
    show();
}
/*
* @项目   TBus_SSEF
* @函数   void slotLoginout();
* @描述   注销登录
* @作者   Micheal(陈明明)
* @时间   2019-04-15
*/
void MainWindow::slotLogout()
{
    m_user = USERS;
    m_monitor->setUserLogOut(false);
    ui->tBtnLginout->setVisible(false);
    ui->tBtnUserLogin->setVisible(true);
    ui->tBtnSystemSet->setEnabled(false);
    ui->tBtnSelfCheck->setEnabled(false);
}

/*测试系统故障*/
void MainWindow::on_tBtnSystemError_clicked()
{
    qDebug()<<"SystemError";
    QApplication::quit();
}
