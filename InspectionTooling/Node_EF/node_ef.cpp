#include "node_ef.h"
#include "ui_node_ef.h"
#include "NodeValue_EF/nodevalue_ef.h"
#include "includes.h"
#include <QTimer>
#include <QDebug>
#include "CanDataMgm/initcanport.h"


#define TIMEOUT 100

Node_EF::Node_EF(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Node_EF)
{
    ui->setupUi(this);
    m_step = 0;
    m_pass = 0;
    m_time = 0;
    m_delay= 0;
    m_keyCheck = false;
    m_dataFlag = false;
    m_checkFlag = false;

    m_nodeValue_1 = new NodeValue_EF(ui->gBox_1);
    m_nodeValue_2 = new NodeValue_EF(ui->gBox_2);
    m_funBtnGroup  = new QButtonGroup;
    m_funBtnGroup->addButton(ui->tBtnClear,0);
    m_funBtnGroup->addButton(ui->tBtnCheck,1);
    m_funBtnGroup->addButton(ui->tBtnReset,2);
    m_funBtnGroup->addButton(ui->tBtnBack, 3);
    connect(m_funBtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotFunBtn(int)));

    m_typeBtnGroup = new QButtonGroup;
    m_typeBtnGroup->addButton(ui->tBtn_L12,0);
    m_typeBtnGroup->addButton(ui->tBtn_L8T4,1);
    m_typeBtnGroup->addButton(ui->tBtn_T4,2);
    m_typeBtnGroup->addButton(ui->tBtnSet,3);
    connect(m_typeBtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotTypeBtn(int)));
    ui->tBtnClear->setVisible(false);

    m_timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotTimeOut()));
}

Node_EF::~Node_EF()
{
    delete ui;
}

void Node_EF::updateValue(QList<int> valueList)
{
    if (valueList.value(0) == 1) {
        m_nodeValue_1->updateValue(valueList);
    } else if (valueList.value(0) == 2) {
        m_nodeValue_2->updateValue(valueList);
    }
}

void Node_EF::keyCheck()
{
    if (m_keyCheck == false) {
        m_keyCheck = true;
        slotFunBtn(1);
    }
}

void Node_EF::initVar()
{
    m_step = 0;
    m_pass = 0;
    m_time = 0;
    m_delay= 0;
    m_keyCheck = false;
    m_dataFlag = false;
    m_checkFlag = false;
}

void Node_EF::slotFunBtn(int index)
{
    switch (index) {
    case 0:

        break;
    case 1:
        ui->tBtnCheck->setEnabled(false);
        ui->tBtnReset->setEnabled(false);
        ui->tBtnBack->setEnabled(false);
        m_checkFlag = true;
        m_timer->start(TIMEOUT);
        emit sigLeakCmd(P_START,0);
        m_nodeValue_1->clearValue();
        m_nodeValue_2->clearValue();
        break;
    case 2:
        for (int i = 0 ; i < 3;i++) {
            InitCanPort::sendCmdDate(1,1,SCMD_RESET,0,0);
            InitCanPort::sendCmdDate(2,1,SCMD_RESET,0,0);
        }
        break;
    case 3:
        emit sigBtnBack();
        break;
    }
}

void Node_EF::slotTypeBtn(int index)
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


void Node_EF::slotTimeOut()
{
    /*
     * 1-000ma  2-050ma  3-100ma  4-150ma
     * 5-200ma  6-300ma  7-500ma  8-800ma
    */
    if(m_checkFlag == true) {
        //发命令，模块校准
        switch (m_step) {
        case 0:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_000);
            } else if (m_delay == 50) {
                m_delay = 0;
                InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
                InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
                m_step++;
            }
            break;
        case 1:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_100);
            } else if (m_delay == 50) {
                m_delay = 0;
                InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+2);
                InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+2);
                m_step++;
            }
            break;
        case 2:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_150);
            } else if (m_delay == 50) {
                m_delay = 0;
                InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+2);
                InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+2);
                m_step++;
            }
            break;
        case 3:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_200);
            } else if (m_delay == 50) {
                m_delay = 0;
                InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+2);
                InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+2);
                m_step++;
            }
            break;
        case 4:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_300);
            } else if (m_delay == 50) {
                m_delay = 0;
                InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+2);
                InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+2);
                m_step++;
            }
            break;
        case 5:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_500);
            } else if (m_delay == 50) {
                m_delay = 0;
                InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+2);
                InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+2);
                m_step++;
            }
            break;
        case 6:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_800);
            } else if (m_delay == 50) {
                m_delay = 0;
                InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+2);
                InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+2);
                m_step++;
            }
            break;
        case 7:
            m_delay++;
            if (m_delay == 10) {
                emit sigLeakCmd(P_SET,D_100);
                InitCanPort::sendCmdDate(1,1,SCMD_RESET,0,0);
                InitCanPort::sendCmdDate(2,1,SCMD_RESET,0,0);
            } else if (m_delay == 100) {
                m_delay = 0;
                m_step = 0;
                m_checkFlag = false;
                m_dataFlag = true;
            }
            break;
        }

    } else if (m_dataFlag == true) {
        //发命令，获取数据

        m_pass++;
        if (m_pass < 96) {
            InitCanPort::sendCmdDate(1,1,SCMD_UPDATE,0,0,m_pass % 12 + 1);
            InitCanPort::sendCmdDate(2,1,SCMD_UPDATE,0,0,m_pass % 12 + 1);
        } else {
            m_checkFlag = true;
            m_dataFlag  = false;
            m_keyCheck  = false;
            ui->tBtnBack->setEnabled(true);
            ui->tBtnCheck->setEnabled(true);
            ui->tBtnReset->setEnabled(true);
            m_pass = 0;
            m_timer->stop();
            //emit sigLeakCmd(P_SET,D_000);
        }

    }
}
