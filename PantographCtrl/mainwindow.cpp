#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    m_mode  = 0;
    m_timeTimer = new QTimer;
    m_uartCom   = new UartCom;
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

    m_select = QString("image: url(:/Image/enable.png);");
    m_unselect = QString("image: url(:/Image/disenable.png);");
    m_btnGroup = new QButtonGroup;
    m_btnGroup->addButton(ui->tBtnDrop,0);
    m_btnGroup->addButton(ui->tBtnRise,1);
    m_btnGroup->addButton(ui->tBtnStop,2);


#ifdef RUN_ON_ARM
    m_uartCom->initPort(QString("/dev/ttymxc1"));
#else
    m_uartCom->initPort(QString("/dev/ttyUSB0"));
#endif

}

void MainWindow::initConnect()
{
    connect(ui->tBtnUserLogin,SIGNAL(clicked(bool)),this,SLOT(slotUserLogin()));
    connect(ui->tBtnUserLogout,SIGNAL(clicked(bool)),this,SLOT(slotUserLogout()));
    connect(m_userLogin,SIGNAL(sigUserLoginOk()),this,SLOT(slotUserLoginOk()));
    connect(m_timeTimer,SIGNAL(timeout()),this,SLOT(slotTimeTimerOut()));
    m_timeTimer->start(TIMEOUT);
    connect(ui->tBtnSystemConf,SIGNAL(clicked(bool)),this,SLOT(slotSystemConf()));
    connect(m_btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotSportMode(int)));
    connect(m_uartCom,SIGNAL(sigRecvUartData(QList<int>)),this,SLOT(slotRecvData(QList<int>)));
    connect(m_uartCom,SIGNAL(sigReplay()),m_systemConf,SLOT(slotReplay()));
    connect(m_uartCom,SIGNAL(sigRecvConfData(QList<int>)),this,SLOT(slotRecvSystemConfData(QList<int>)));
    connect(m_systemConf,SIGNAL(sigReplayData(int)),m_uartCom,SLOT(slotReplayData(int)));
    connect(m_systemConf,SIGNAL(sigSystemConfData(QByteArray)),this,SLOT(slotSystemConfData(QByteArray)));

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
    int mode = dataList.value(0);
    switch (mode) {
    case MANUALMODE:
        ui->lbManualMode->setStyleSheet(m_select);
        ui->lbAutoMode->setStyleSheet(m_unselect);
        ui->lbRepairMode->setStyleSheet(m_unselect);
        break;
    case AUTOMODE:
        ui->lbManualMode->setStyleSheet(m_unselect);
        ui->lbAutoMode->setStyleSheet(m_select);
        ui->lbRepairMode->setStyleSheet(m_unselect);
        break;
    case REPAIRMODE:
        ui->lbAutoMode->setStyleSheet(m_unselect);
        ui->lbManualMode->setStyleSheet(m_unselect);
        ui->lbRepairMode->setStyleSheet(m_select);
        break;
    }
    ui->lcdNbP_1->display(dataList.value(P_1));
    ui->lcdNbP_2->display(dataList.value(P_2));
    ui->lcdNbT_1->display(dataList.value(T_1));
    ui->lcdNbT_2->display(dataList.value(T_2));
    ui->lcdNbT_3->display(dataList.value(T_3));
    ui->lcdNbT_4->display(dataList.value(T_4));
    ui->lcdNbT_5->display(dataList.value(T_5));
    ui->lcdNbT_6->display(dataList.value(T_6));
    ui->lcdNbCP1->display(dataList.value(CPV));
}

void MainWindow::analysisBowError(int error)
{
    initLabelList(m_errorLabelList,m_greenColorError);
    setLabelListValue(m_errorLabelList,error,m_redColorError);

}

void MainWindow::analysisBowState(int state)
{
    initLabelList(m_stateLabelList,m_greenColorState);
    setLabelListValue(m_stateLabelList,state,m_redColorState);
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

    ui->tBtnDrop->setEnabled(true);
    ui->tBtnRise->setEnabled(true);
    ui->tBtnStop->setEnabled(true);
}

void MainWindow::slotUserLogout()
{
    ui->tBtnUserLogin->setVisible(true);
    ui->tBtnUserLogout->setVisible(false);
    ui->tBtnSystemConf->setEnabled(false);
}

void MainWindow::slotSystemConf()
{
    m_systemConf->show();
}

void MainWindow::slotSportMode(int btn)
{
    uchar data_aa = 0xAA;
    uchar data_00 = 0x00;
    QByteArray byteArray;
    byteArray.append(data_aa);
    byteArray.append(data_00);
    byteArray.append(SETDATA);
    byteArray.append(0x01);
    byteArray.append(m_mode);
    byteArray.append(btn);
    m_uartCom->sendUartData(byteArray);
}

void MainWindow::slotSystemConfData(QByteArray byteArray)
{
    uchar data_aa = 0xAA;
    uchar data_00 = 0x00;
    QByteArray buffer;
    buffer.append(data_aa);
    buffer.append(data_00);
    buffer.append(SETDATA);
    buffer.append(0x09);
    buffer.append(byteArray);
    m_uartCom->sendUartData(buffer);
}

void MainWindow::slotRecvSystemConfData(QList<int> dataList)
{
    m_mode = dataList.value(0);
    switch (m_mode) {
    case MANUALMODE:
        ui->lbManualMode->setStyleSheet(m_select);
        ui->lbAutoMode->setStyleSheet(m_unselect);
        ui->lbRepairMode->setStyleSheet(m_unselect);
        break;
    case AUTOMODE:
        ui->lbManualMode->setStyleSheet(m_unselect);
        ui->lbAutoMode->setStyleSheet(m_select);
        ui->lbRepairMode->setStyleSheet(m_unselect);
        break;
    case REPAIRMODE:
        ui->lbAutoMode->setStyleSheet(m_unselect);
        ui->lbManualMode->setStyleSheet(m_unselect);
        ui->lbRepairMode->setStyleSheet(m_select);
        break;
    }
    m_systemConf->systemConfData(dataList);
}

void MainWindow::slotRecvData(QList<int> dataList)
{
    analysisRealData(dataList);
    analysisBowState(dataList.value(10));
    analysisBowError(dataList.value(11));
}
