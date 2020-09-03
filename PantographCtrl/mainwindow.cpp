#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include "UserLogin/userlogin.h"
#include "SystemConf/systemconf.h"
#define TIMEOUT    1000
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initObject();
    initWidget();
    initConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initObject()
{
    m_timeTimer = new QTimer;
    m_userLogin = new UserLogin;
    m_systemConf= new SystemConf;
}

void MainWindow::initWidget()
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->lbTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    ui->tBtnUserLogin->setVisible(true);
    ui->tBtnUserLogout->setVisible(false);
    ui->tBtnSystemConf->setEnabled(false);

}

void MainWindow::initConnect()
{

    connect(ui->rBtnAutoMode,SIGNAL(clicked(bool)),this,SLOT(slotAutoMode()));
    connect(ui->rBtnManualMode,SIGNAL(clicked(bool)),this,SLOT(slotManualMode()));
    connect(ui->rBtnRepairMode,SIGNAL(clicked(bool)),this,SLOT(slotRepairMode()));
    connect(ui->tBtnUserLogin,SIGNAL(clicked(bool)),this,SLOT(slotUserLogin()));
    connect(ui->tBtnUserLogout,SIGNAL(clicked(bool)),this,SLOT(slotUserLogout()));
    connect(m_userLogin,SIGNAL(sigUserLoginOk()),this,SLOT(slotUserLoginOk()));
    connect(m_timeTimer,SIGNAL(timeout()),this,SLOT(slotTimeTimerOut()));
    m_timeTimer->start(TIMEOUT);
}

void MainWindow::slotTimeTimerOut()
{
    ui->lbTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
}

void MainWindow::slotUserLogin()
{
    m_userLogin->confShow();
}

void MainWindow::slotUserLoginOk()
{
    ui->tBtnUserLogin->setVisible(false);
    ui->tBtnUserLogout->setVisible(true);
    ui->tBtnSystemConf->setEnabled(true);
    ui->rBtnAutoMode->setEnabled(true);
    ui->rBtnManualMode->setEnabled(true);
    ui->tBtnSystemReset->setEnabled(true);
}

void MainWindow::slotUserLogout()
{
    ui->tBtnUserLogin->setVisible(true);
    ui->tBtnUserLogout->setVisible(false);
    ui->tBtnSystemConf->setEnabled(false);
}

void MainWindow::slotAutoMode()
{
    ui->tBtnDrop->setEnabled(false);
    ui->tBtnRise->setEnabled(false);
}

void MainWindow::slotManualMode()
{
    ui->tBtnDrop->setEnabled(true);
    ui->tBtnRise->setEnabled(true);
}

void MainWindow::slotRepairMode()
{
    ui->tBtnUserLogin->setVisible(true);
    ui->tBtnUserLogout->setVisible(false);
    ui->tBtnDrop->setEnabled(false);
    ui->tBtnRise->setEnabled(false);
    ui->rBtnAutoMode->setEnabled(false);
    ui->rBtnManualMode->setEnabled(false);
    ui->tBtnSystemReset->setEnabled(false);
    ui->tBtnSystemConf->setEnabled(false);
}
