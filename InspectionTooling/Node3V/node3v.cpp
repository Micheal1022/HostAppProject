#include "node3v.h"
#include "ui_node3v.h"
#include "NodeValue_PM/nodevalue_pm.h"

#include <QTimer>
Node3V::Node3V(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Node3V)
{
    ui->setupUi(this);
    m_nodeValue_1 = new NodeValue_PM(ui->gBox_1);
    m_nodeValue_1->confCurLoopNum(1);
    m_nodeValue_2 = new NodeValue_PM(ui->gBox_2);
    m_nodeValue_2->confCurLoopNum(2);

    m_funBtnGroup  = new QButtonGroup;
    m_funBtnGroup->addButton(ui->tBtnClear,0);
    m_funBtnGroup->addButton(ui->tBtnCheck,1);
    m_funBtnGroup->addButton(ui->tBtnReset,2);
    m_funBtnGroup->addButton(ui->tBtnBack, 3);
    connect(m_funBtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotFunBtn(int)));

}


Node3V::~Node3V()
{
    delete ui;
}

void Node3V::confType(int type)
{
    if (2 == type) {
        ui->tBtn_3V->show();  ui->tBtn_2V->show();  ui->tBtn_1V->show();
        ui->tBtn_2VA->hide(); ui->tBtn_1VA->hide();
        m_typeBtnGroup = new QButtonGroup;
        m_typeBtnGroup->addButton(ui->tBtn_3V,0);
        m_typeBtnGroup->addButton(ui->tBtn_2V,1);
        m_typeBtnGroup->addButton(ui->tBtn_1V,2);
        m_typeBtnGroup->addButton(ui->tBtnSet,3);
    } else if (1 == type) {
        ui->tBtn_3V->hide();  ui->tBtn_2V->hide();  ui->tBtn_1V->hide();
        ui->tBtn_2VA->show(); ui->tBtn_1VA->show();
        m_typeBtnGroup = new QButtonGroup;
        m_typeBtnGroup->addButton(ui->tBtn_2VA,0);
        m_typeBtnGroup->addButton(ui->tBtn_1VA,1);
        m_typeBtnGroup->addButton(ui->tBtnSet, 3);
    }
    connect(m_typeBtnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotTypeBtn(int)));
}

void Node3V::slotFunBtn(int index)
{
    switch (index) {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:
        emit sigBtnBack();
        break;
    }
}

void Node3V::slotTypeBtn(int index)
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

void Node3V::slotBtnClear()
{
    m_nodeValue_1->cleanValue();
    m_nodeValue_2->cleanValue();
}

void Node3V::slotBtnReset()
{

}

void Node3V::slotBtnCheck()
{

    QTimer::singleShot(3000, this, SLOT(slotGetData()));
}

void Node3V::slotGetData()
{

}
