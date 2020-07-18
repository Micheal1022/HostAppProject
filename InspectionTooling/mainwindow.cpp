#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Modbus/modbus.h"
#include "Node_PM/node_pm.h"
#include "Node_EF/node_ef.h"
#include "includes.h"
#include <QDebug>
#include <QButtonGroup>
#include "CanDataMgm/candatamgm.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    //showFullScreen();
    qRegisterMetaType<QList<int> >("QList<int>");

    m_nodeEFFlag = false;
    m_node3VFlag = false;
    m_node2VAFlag= false;
    m_node6V3AFlag = false;

    m_modbus = new Modbus;

    m_nodeEF = new Node_EF(ui->pageLeak);
    m_node2VA = new Node_PM(ui->pageThreeCurVol);
    m_node2VA->confType(MOD_2VA);
    m_node3V  =  new Node_PM(ui->pageThreeVol);
    m_node3V->confType(MOD_3V);
    m_node6V3A = new Node_PM(ui->pageSingelCurVol);
    m_node6V3A->confType(MOD_6V3A);

    m_buttonGroup = new QButtonGroup;
    m_buttonGroup->addButton(ui->tBtnLeak,        1);
    m_buttonGroup->addButton(ui->tBtnThreeVolCur, 2);
    m_buttonGroup->addButton(ui->tBtnThreeVol,    3);
    m_buttonGroup->addButton(ui->tBtnSingleVolCur,4);
    m_buttonGroup->addButton(ui->tBtnQuit,        5);
    ui->tBtnQuit->setVisible(false);
    connect(m_buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnIndex(int)));

    connect(m_nodeEF,  SIGNAL(sigBtnBack()),this,SLOT(slotBtnBack()));
    connect(m_node3V,  SIGNAL(sigBtnBack()),this,SLOT(slotBtnBack()));
    connect(m_node2VA, SIGNAL(sigBtnBack()),this,SLOT(slotBtnBack()));
    connect(m_node6V3A,SIGNAL(sigBtnBack()),this,SLOT(slotBtnBack()));

    m_canDataMgm = new CanDataMgm;
    connect(m_canDataMgm,SIGNAL(sigSendCanData(QList<int>)),this,SLOT(slotSendCanData(QList<int>)));


    connect(m_node2VA, SIGNAL(sigVoltageCmd(int)),m_modbus,SLOT(slotSendVoltageData(int)));
    connect(m_node2VA, SIGNAL(sigCurrentCmd(int)),m_modbus,SLOT(slotSendCurrentData(int)));
    connect(m_node3V,  SIGNAL(sigVoltageCmd(int)),m_modbus,SLOT(slotSendVoltageData(int)));
    connect(m_node6V3A,SIGNAL(sigVoltageCmd(int)),m_modbus,SLOT(slotSendVoltageData(int)));
    connect(m_node6V3A,SIGNAL(sigCurrentCmd(int)),m_modbus,SLOT(slotSendCurrentData(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotBtnIndex(int index)
{
    switch (index) {
    case 1:
        m_nodeEFFlag = true;
        ui->stackedWidget->setCurrentIndex(index);
        break;
    case 2:
        m_node2VAFlag = true;
        ui->stackedWidget->setCurrentIndex(index);
        break;
    case 3:
        m_node3VFlag = true;
        ui->stackedWidget->setCurrentIndex(index);
        break;
    case 4:
        m_node6V3AFlag = true;
        ui->stackedWidget->setCurrentIndex(index);
        break;
    case 5:
        QApplication::quit();
        break;
    }
}

void MainWindow::slotBtnBack()
{
    m_nodeEFFlag = false;
    m_node3VFlag = false;
    m_node2VAFlag= false;
    m_node6V3AFlag = false;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::slotSendCanData(QList<int> valueList)
{
    if (m_nodeEFFlag) {
        m_nodeEF->updateValue(valueList);
    } else if (m_node2VAFlag) {
        m_node2VA->updateValue(valueList);
    } else if (m_node3VFlag) {
        m_node3V->updateValue(valueList);
    } else if (m_node6V3AFlag) {
        m_node6V3A->updateValue(valueList);
    }
}
