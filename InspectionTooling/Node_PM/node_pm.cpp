#include "node_pm.h"
#include "ui_node_pm.h"
#include "NodeValue_PM/nodevalue_pm.h"
#include "includes.h"

#include <QTimer>
#include <QDebug>
#include "CanDataMgm/initcanport.h"
Node_PM::Node_PM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Node_PM)
{
    ui->setupUi(this);
    m_nodeValue_1 = new NodeValue_PM(ui->gBox_1);
    m_nodeValue_2 = new NodeValue_PM(ui->gBox_2);

    m_pass = 0;
    m_funBtnGroup  = new QButtonGroup;
    m_funBtnGroup->addButton(ui->tBtnClear,0);
    m_funBtnGroup->addButton(ui->tBtnCheck,1);
    m_funBtnGroup->addButton(ui->tBtnReset,2);
    m_funBtnGroup->addButton(ui->tBtnBack, 3);
    connect(m_funBtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotFunBtn(int)));
    m_timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotTimeOut()));


}


Node_PM::~Node_PM()
{
    delete ui;
}

void Node_PM::confType(int type)
{
    m_type = type;
    m_typeBtnGroup = new QButtonGroup;
    if (MOD_3V == type) {
        m_nodeValue_1->initWidget(1,MOD_3V);
        m_nodeValue_2->initWidget(2,MOD_3V);
        ui->tBtn_3V->show();  ui->tBtn_2V->show();  ui->tBtn_1V->show();
        ui->tBtn_2VA->hide(); ui->tBtn_1VA->hide();

        m_typeBtnGroup->addButton(ui->tBtn_3V,0);
        m_typeBtnGroup->addButton(ui->tBtn_2V,1);
        m_typeBtnGroup->addButton(ui->tBtn_1V,2);
        m_typeBtnGroup->addButton(ui->tBtnSet,3);
    } else if (MOD_2VA == type) {
        m_nodeValue_1->initWidget(1,MOD_2VA);
        m_nodeValue_2->initWidget(2,MOD_2VA);
        ui->tBtn_3V->hide();  ui->tBtn_2V->hide();  ui->tBtn_1V->hide();
        ui->tBtn_2VA->show(); ui->tBtn_1VA->show();

        m_typeBtnGroup->addButton(ui->tBtn_2VA,0);
        m_typeBtnGroup->addButton(ui->tBtn_1VA,1);
        m_typeBtnGroup->addButton(ui->tBtnSet, 3);
    } else if (MOD_6V3A == type) {
        m_nodeValue_1->initWidget(1,MOD_6V3A);
        m_nodeValue_2->initWidget(2,MOD_6V3A);
        ui->gBoxType->setVisible(false);

    }
    connect(m_typeBtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotTypeBtn(int)));
}

void Node_PM::updateValue(QList<int> valueList)
{
    if (valueList.value(LOOP) == 1) {
        m_nodeValue_1->updateValue(valueList);
    }
    if (valueList.value(LOOP) == 2) {
        m_nodeValue_2->updateValue(valueList);
    }

}

void Node_PM::keyCheck()
{
    slotFunBtn(1);
}

void Node_PM::slotTimeOut()
{
    //发命令，获取数据
    m_pass++;
    if (m_pass < 50) {
        if (MOD_6V3A == m_type) {
            InitCanPort::sendCmdDate(1,1,SCMD_UPDATE,0,0,m_pass % 9+1);
            InitCanPort::sendCmdDate(2,1,SCMD_UPDATE,0,0,m_pass % 9+1);
        } else {
            InitCanPort::sendCmdDate(1,1,SCMD_UPDATE,0,0,m_pass % 3+1);
            InitCanPort::sendCmdDate(2,1,SCMD_UPDATE,0,0,m_pass % 3+1);
        }
    } else {
        m_pass = 0;
        m_timer->stop();
        ui->tBtnBack->setEnabled(true);
        ui->tBtnCheck->setEnabled(true);
        ui->tBtnClear->setEnabled(true);
        ui->tBtnReset->setEnabled(true);
        emit sigVoltageCmd(P_STOP);
        emit sigCurrentCmd(P_STOP);

    }
}

void Node_PM::slotFunBtn(int index)
{
    switch (index) {
    case 0:
        btnClear();
        break;
    case 1:
        btnClear();
        btnCheck();
        break;
    case 2:
        btnReset();
        break;
    case 3:
        emit sigBtnBack();
        break;
    }
}

void Node_PM::slotTypeBtn(int index)
{
    switch (index) {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    }
}

void Node_PM::btnClear()
{
    m_pass = 0;
    emit sigVoltageCmd(P_STOP);
    emit sigCurrentCmd(P_STOP);
    m_nodeValue_1->cleanValue();
    m_nodeValue_2->cleanValue();
}

void Node_PM::btnReset()
{
    btnClear();
//    for (int i = 0 ; i < 3;i++) {
//        CanMgm::sendCmdDate(1,1,SCMD_RESET,0,0);
//        CanMgm::sendCmdDate(2,1,SCMD_RESET,0,0);
//    }
}

void Node_PM::btnCheck()
{
    m_pass = 0;
    ui->tBtnBack->setEnabled(false);
    ui->tBtnCheck->setEnabled(false);
    ui->tBtnClear->setEnabled(false);
    ui->tBtnReset->setEnabled(false);
    emit sigVoltageCmd(P_START);
    emit sigCurrentCmd(P_START);
    QTimer::singleShot(4500, this, SLOT(slotGetData()));
}

void Node_PM::slotGetData()
{
    InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,0);
    InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,0);
    m_timer->start(100);
}
