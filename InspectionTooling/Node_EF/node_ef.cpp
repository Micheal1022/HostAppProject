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

void Node_EF::slotFunBtn(int index)
{
    switch (index) {
    case 0:
        m_nodeValue_1->clearValue();
        m_nodeValue_2->clearValue();
        break;
    case 1:
        m_checkFlag = true;
        m_timer->start(TIMEOUT);
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
    /*0-100-150-200-300-500-800*/
    if(m_checkFlag) {
        switch (m_step) {
        case 0:
            InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
            InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
            break;
        case 1:
            InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
            InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
            break;
        case 2:
            InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
            InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
            break;
        case 3:
            InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
            InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
            break;
        case 4:
            InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
            InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
            break;
        case 5:
            InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
            InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
            break;
        case 6:
            InitCanPort::sendCmdDate(1,0,SCMD_SCALIB,0,m_step+1);
            InitCanPort::sendCmdDate(2,0,SCMD_SCALIB,0,m_step+1);
            break;
        }
        m_step++;
        if (m_step == 6) {
            m_step = 0;
            m_checkFlag = false;
            m_dataFlag = true;
        }

    } else if (m_dataFlag) {
        //发命令，获取数据
        if (m_time < 10) {
            m_pass++;
            if (m_pass == 13) {
                m_time++;
                m_pass = 0;
            } else {
                InitCanPort::sendCmdDate(1,1,SCMD_UPDATE,0,0,m_pass);
                InitCanPort::sendCmdDate(2,1,SCMD_UPDATE,0,0,m_pass);
            }
        } else {
            m_time = 0;
            m_timer->stop();
        }
    }
}
