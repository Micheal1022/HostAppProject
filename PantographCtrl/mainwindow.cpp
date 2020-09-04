#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "includes.h"





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
    m_error = 0;
    m_timeTimer = new QTimer;
    m_userLogin = new UserLogin;
    m_systemConf= new SystemConf;
}

void MainWindow::initWidget()
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->lbTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    m_redColorState   = QString("border:1px solid rgb(0, 122, 165);background-color: rgb(244, 0, 0);");
    m_greenColorState = QString("border:1px solid rgb(0, 122, 165);background-color: rgb(0, 180, 0);");
    m_redColorError   = QString("border:1px solid rgb(0, 122, 165);border-radius:20px;background-color: rgb(244, 0, 0);");
    m_greenColorError = QString("border:1px solid rgb(0, 122, 165);border-radius:20px;background-color: rgb(0, 180, 0);");
    m_errorLabelList.append(ui->lbUpperLimitError);
    m_errorLabelList.append(ui->lbLowerLimitError);
    m_errorLabelList.append(ui->lbServoError);
    m_errorLabelList.append(ui->lbSuddenStopError);
    m_errorLabelList.append(ui->lbTimeOutError);
    m_errorLabelList.append(ui->lbPowerLostError);
    m_errorLabelList.append(ui->lbPressureError_1);
    m_errorLabelList.append(ui->lbTempError_1);
    m_errorLabelList.append(ui->lbTempError_2);
    m_errorLabelList.append(ui->lbTempError_3);
    m_errorLabelList.append(ui->lbTempError_4);
    m_errorLabelList.append(ui->lbTempError_5);
    m_errorLabelList.append(ui->lbTempError_6);
    m_errorLabelList.append(ui->lbPressureError_2);
    initLabelList(m_errorLabelList,m_greenColorError);

    m_stateLabelList.append(ui->lbInit);
    m_stateLabelList.append(ui->lbDropping);
    m_stateLabelList.append(ui->lbDropped);
    m_stateLabelList.append(ui->lbRising);
    m_stateLabelList.append(ui->lbRised);
    initLabelList(m_stateLabelList,m_greenColorState);



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

void MainWindow::initLabelList(QList<QLabel *> labelList,QString string)
{
    for (int i = 0; i < labelList.size(); i++) {
        labelList.value(i)->setStyleSheet(string);
    }
}

void MainWindow::setLabelListValue(QList<QLabel *> labelList, int index, QString string)
{
    labelList.value(index)->setStyleSheet(string);
}

void MainWindow::analysisRealData(QList<int> dataList)
{
    ui->lcdNbP_1->display(dataList.value(P_1));
    ui->lcdNbP_2->display(dataList.value(P_2));
    ui->lcdNbCP1->display(dataList.value(CP1));
    ui->lcdNbT_1->display(dataList.value(T_1));
    ui->lcdNbT_2->display(dataList.value(T_2));
    ui->lcdNbT_3->display(dataList.value(T_3));
    ui->lcdNbT_4->display(dataList.value(T_4));
    ui->lcdNbT_5->display(dataList.value(T_5));
    ui->lcdNbT_6->display(dataList.value(T_6));
}

void MainWindow::analysisBowError(int error)
{
    initLabelList(m_errorLabelList,m_greenColorError);
    setLabelListValue(m_errorLabelList,error,m_redColorError);
    switch (error) {
    case INIT:

        break;
    case DROPPING:

        break;
    case DROPPED:

        break;
    case RISING:

        break;
    case RISED:

        break;
    }
}

void MainWindow::analysisBowState(int state)
{
    initLabelList(m_stateLabelList,m_greenColorState);
    setLabelListValue(m_stateLabelList,state,m_redColorState);
    switch (state) {
    case UPPERLIMITERROR:

        break;
    case LOWERLIMITERROR:

        break;
    case SERVOERROR:

        break;
    case SUDDENSTOPERROR:

        break;
    case TIMEOUTERROR:

        break;
    case POWERLOSERROR:

        break;
    case PRESSOURERROR_1:

        break;
    case PRESSOURERROR_2:

        break;
    case TEMPERROR_1:

        break;
    case TEMPERROR_2:

        break;
    case TEMPERROR_3:

        break;
    case TEMPERROR_4:

        break;
    case TEMPERROR_5:

        break;
    case TEMPERROR_6:

        break;
    }
}

void MainWindow::slotTimeTimerOut()
{
    ui->lbTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    analysisBowError((m_error++) % 14);
    analysisBowState((m_error) % 5);
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

void MainWindow::slotRecvData(QList<int> dataList)
{
    analysisRealData(dataList);
    analysisBowError(dataList.value(1));
    analysisBowState(dataList.value(2));
}
