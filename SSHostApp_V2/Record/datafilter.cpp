#include "datafilter.h"
#include "ui_datafilter.h"
#include "MsgBox/msgbox.h"
#include "SQLite/mysqlite.h"
#include <QDebug>
#include <QDateTime>
#include <QButtonGroup>
#include <QCryptographicHash>
#include "includes.h"


DataFilter::DataFilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataFilter)
{
    ui->setupUi(this);
    setGeometry(0,0,1024,600);
    setWindowFlags(Qt::FramelessWindowHint);
    initBtnGroup();

    //获取可用的设备
    QSqlDatabase devdb = MySQLite::openConnection();
    int devType = MySQLite::getDevType(devdb);
    MySQLite::closeConnection(devdb);

    if (DEV_EFMQ == devType) {
        ui->stackedWidget->setCurrentWidget(ui->pageEFMQ);
    } else if (DEV_PMFE == devType) {
        ui->stackedWidget->setCurrentWidget(ui->pagePMFE);
    }

    connect(ui->tBtnOk,SIGNAL(clicked(bool)),this,SLOT(slotBtnOk()));
    connect(ui->tBtnBack,SIGNAL(clicked(bool)),this,SLOT(slotBtnBack()));
    connect(m_btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnIndex(int)));
    connect(ui->checkBoxLoop,SIGNAL(clicked(bool)),this,SLOT(slotSetLoopEnable(bool)));
    connect(ui->checkBoxCanId,SIGNAL(clicked(bool)),this,SLOT(slotSetCanIdEnable(bool)));


    m_btnKeyGroup = new QButtonGroup;
    m_btnKeyGroup->addButton(ui->tBtn_0,0);
    m_btnKeyGroup->addButton(ui->tBtn_1,1);
    m_btnKeyGroup->addButton(ui->tBtn_2,2);
    m_btnKeyGroup->addButton(ui->tBtn_3,3);
    m_btnKeyGroup->addButton(ui->tBtn_4,4);
    m_btnKeyGroup->addButton(ui->tBtn_5,5);
    m_btnKeyGroup->addButton(ui->tBtn_6,6);
    m_btnKeyGroup->addButton(ui->tBtn_7,7);
    m_btnKeyGroup->addButton(ui->tBtn_8,8);
    m_btnKeyGroup->addButton(ui->tBtn_9,9);
    m_btnKeyGroup->addButton(ui->tBtn_del,10);
    connect(m_btnKeyGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnKeyIndex(int)));
}

DataFilter::~DataFilter()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数   void showConf();
* @描述   配置显示界面S
* @作者   Micheal(陈明明)
* @时间   2019-04-22
*/
void DataFilter::showConf()
{
    setVisible(true);
    ui->lineEditLoop->clear();
    ui->lineEditCanId->clear();
    ui->lineEditLoop->setEnabled(false);
    ui->lineEditCanId->setEnabled(false);
    ui->checkBoxCanId->setChecked(false);
    ui->dTEditEnd->setDateTime(QDateTime::currentDateTime());
}

void DataFilter::initBtnGroup()
{
    m_unSelectStr = "color:rgb(0, 122, 165);background-color: rgb(255, 255, 255);";
    m_selectStr   = "color:rgb(255, 255, 255);background-color: rgb(0, 122, 165);";
    ui->tBtnAllError->setStyleSheet(m_selectStr);

    m_btnGroup = new QButtonGroup;
    m_btnGroup->addButton(ui->tBtnAllError,0);
    m_btnGroup->addButton(ui->tBtnHost,    1);
    m_btnGroup->addButton(ui->tBtnLostPow, 2);
    m_btnGroup->addButton(ui->tBtnOverVol, 3);
    m_btnGroup->addButton(ui->tBtnOverCur, 4);
    m_btnGroup->addButton(ui->tBtnLackVol, 5);
    m_btnGroup->addButton(ui->tBtnLostPha, 6);
    m_btnGroup->addButton(ui->tBtnErrorPha,7);
    m_btnGroup->addButton(ui->tBtnError,   8);
    m_btnGroup->addButton(ui->tBtnAlarm,   9);
    m_btnGroup->addButton(ui->tBtnOffLine, 10);

    for(int index = 0;index < 11;index++){
        if (index == 0) {
            m_btnSelect.append(true);
        }
        m_btnSelect.append(false);
    }

    ui->KeyBwidget->setVisible(false);
    ui->lb_end->setVisible(false);
    ui->lb_start->setVisible(false);
    ui->dTEditEnd->setVisible(false);
    ui->dTEditStart->setVisible(false);
    ui->checkBoxLoop->setVisible(false);
    ui->lineEditLoop->setVisible(false);
    ui->checkBoxCanId->setVisible(false);
    ui->lineEditCanId->setVisible(false);
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnBack();
* @描述   隐藏关闭界面
* @作者   Micheal(陈明明)
* @时间   2019-04-22
*/
void DataFilter::slotBtnBack()
{
    hide();
}

void DataFilter::slotBtnIndex(int index)
{
    //如果选择全部故障，其他状态将设置为不选中
    if (m_btnSelect.at(index) == false){
        if(index < 2) {
            ui->lb_end->setVisible(false);
            ui->lb_start->setVisible(false);
            ui->dTEditEnd->setVisible(false);
            ui->dTEditStart->setVisible(false);

            ui->checkBoxLoop->setVisible(false);
            ui->checkBoxLoop->setChecked(false);
            ui->checkBoxCanId->setVisible(false);
            ui->checkBoxCanId->setChecked(false);

            ui->lineEditLoop->clear();
            ui->lineEditLoop->setVisible(false);
            ui->lineEditCanId->clear();
            ui->lineEditCanId->setVisible(false);

            ui->KeyBwidget->setVisible(false);

        } else {
            ui->lb_end->setVisible(true);
            ui->lb_start->setVisible(true);
            ui->dTEditEnd->setVisible(true);
            ui->dTEditStart->setVisible(true);
            ui->checkBoxLoop->setVisible(true);
            ui->lineEditLoop->setVisible(true);
            ui->checkBoxCanId->setVisible(true);
            ui->lineEditCanId->setVisible(true);
            ui->KeyBwidget->setVisible(true);
        }

        m_btnSelect[index] = true;
        m_btnGroup->button(index)->setStyleSheet(m_selectStr);

        for(int i = 0; i < 11;i++){
            if (i != index) {
                m_btnSelect[i] = false;
                m_btnGroup->button(i)->setStyleSheet(m_unSelectStr);
            }
        }
    }
}

void DataFilter::slotBtnOk()
{

    //主机故障 = 0x1A;分机故障 = 0x1B;
    //主电故障 = 0xAA;
    //备电故障 = 0xBB;
    //主机复位 = 0xCC;
    //主机静音 = 0xDD;
    //电源中断 = 2;节点过压 = 3;节点过流 = 4;节点欠压 = 5;
    //节点缺相 = 6;节点错相 = 7;节点故障 = 8;节点报警 = 9;节点离线 = 10;
    QString sqlQuery = "select LOOP,CANID,PASS,TYPE,STS,VALUE,TIME,AREA from RECORD where";
    //Time
    QString fromTime = QString::number(ui->dTEditStart->dateTime().toTime_t());
    QString endTime = QString::number(ui->dTEditEnd->dateTime().toTime_t());
    sqlQuery += " TIME between "+fromTime+" and "+endTime;

    if (m_btnSelect.value(1)) {
        sqlQuery += " and TYPE = 26";   //主机故障
    } else if (m_btnSelect.value(2)) {  //电源中断
        sqlQuery += " and STS = 2";
    } else if (m_btnSelect.value(3)) {  //节点过压
        sqlQuery += " and STS = 3";
    } else if (m_btnSelect.value(4)) {  //节点过流
        sqlQuery += " and STS = 4";
    } else if (m_btnSelect.value(5)) {  //节点欠压
        sqlQuery += " and STS = 5";
    } else if (m_btnSelect.value(6)) {  //节点缺相
        sqlQuery += " and STS = 6";
    } else if (m_btnSelect.value(7)) {  //节点错相
        sqlQuery += " and STS = 7";
    } else if (m_btnSelect.value(8)) {  //节点故障
        sqlQuery += " and STS = 8";
    } else if (m_btnSelect.value(9)) {  //节点报警
        sqlQuery += " and STS = 9";
    } else if (m_btnSelect.value(10)) { //节点离线
        sqlQuery += " and STS = 10";
    }

    //PASS
    if (true == ui->checkBoxLoop->isChecked()) {
        if (false == ui->lineEditLoop->text().isEmpty()) {
            sqlQuery += " and LOOP = " + ui->lineEditLoop->text();
        }else {
            MsgBox::showInformation(NULL,tr("操作提示"),tr("回路编号不能为空!"),tr("关闭"));
            return;
        }
    }
    //CANID
    if (true == ui->checkBoxCanId->isChecked()) {
        if (false == ui->lineEditCanId->text().isEmpty()) {
            sqlQuery += " and CANID = " + ui->lineEditCanId->text();
        } else {
            MsgBox::showInformation(NULL,tr("操作提示"),tr("地址编号不能为空!"),tr("关闭"));
            return;
        }
    }

    sqlQuery += " order by TIME desc ";
    hide();

    emit sigSqlQuery(sqlQuery);
}

void DataFilter::slotSetCanIdEnable(bool enable)
{
    ui->lineEditCanId->setEnabled(enable);
    if (enable != true) {
        ui->lineEditCanId->clear();
    }
}

void DataFilter::slotSetLoopEnable(bool enable)
{
    ui->lineEditLoop->setEnabled(enable);
    if (enable != true) {
        ui->lineEditLoop->clear();
    }
}

void DataFilter::slotBtnKeyIndex(int index)
{
    QString text = m_btnKeyGroup->button(index)->text();
    if (index == 10) {
        if (focusWidget() != NULL) {
            if (focusWidget()->inherits("QLineEdit")) {
                QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
                edit->clear();
            }
        }
    } else {
        if (focusWidget() != NULL) {
            if (focusWidget()->inherits("QLineEdit")) {
                QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
                QString curStr = edit->text();
                edit->setText(curStr+text);
            }
        }
    }
}
