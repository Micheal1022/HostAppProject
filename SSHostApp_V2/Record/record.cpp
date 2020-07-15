#include "datafilter.h"
#include "record.h"
#include "ui_record.h"
#include <QDateTime>
#include <QGraphicsDropShadowEffect>
#include <QTableWidget>
#include "myprint.h"
#include "SQLite/mysqlite.h"
#include "MsgBox/msgbox.h"
#include <QMessageBox>
#include "includes.h"


Record::Record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Record)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(0,0,1024,600);
    initVar();
    initConnect();
    initTabelWgt(ui->tableWgtRecord);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnDel);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnAllDel);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnBack);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnPrint);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnQuery);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnFilter);


}

Record::~Record()
{
    delete ui;
}

void Record::confShow(int user)
{
    show();
    switch (user) {
    case ADMIN:
        ui->tBtnDel->setVisible(false);
        ui->tBtnPrint->setVisible(true);
        ui->tBtnAllDel->setVisible(false);
        break;
    case SUPER:
        ui->tBtnDel->setVisible(true);
        ui->tBtnPrint->setVisible(true);
        ui->tBtnAllDel->setVisible(true);
        break;
    default:
        ui->tBtnDel->setVisible(false);
        ui->tBtnPrint->setVisible(false);
        ui->tBtnAllDel->setVisible(false);
        break;
    }
}

void Record::initVar()
{
    m_pageCount = 0;
    m_pageCurrent = 1;
    ui->tBtnNest->setEnabled(false);
    ui->tBtnLast->setEnabled(false);
    m_dataFilter = new DataFilter;
    MyPrint::initSerialPort();
    ui->lbCountNum->setText("0");
    m_formatTime = QString(tr("yyyy-MM-dd hh:mm:ss"));
    QString dateTimeStr = QString::number(QDateTime::currentDateTime().toTime_t());
    m_queryStr = "select LOOP,CANID,PASS,TYPE,STS,VALUE,TIME,AREA from RECORD where TIME <= "+dateTimeStr+" order by TIME desc;";
}

void Record::initConnect()
{
    connect(ui->tBtnDel,SIGNAL(clicked(bool)),this,SLOT(slotBtnDel()));
    connect(ui->tBtnAllDel,SIGNAL(clicked(bool)),this,SLOT(slotBtnAllDel()));
    connect(ui->tBtnNest,SIGNAL(clicked(bool)),this,SLOT(slotBtnNest()));
    connect(ui->tBtnLast,SIGNAL(clicked(bool)),this,SLOT(slotBtnLast()));
    connect(ui->tBtnBack,SIGNAL(clicked(bool)),this,SLOT(slotBtnBack()));
    connect(ui->tBtnPrint,SIGNAL(clicked(bool)),this,SLOT(slotBtnPrint()));
    connect(ui->tBtnQuery,SIGNAL(clicked(bool)),this,SLOT(slotBtnQuery()));
    connect(ui->tBtnFilter,SIGNAL(clicked(bool)),this,SLOT(slotBtnFilter()));

    connect(m_dataFilter,SIGNAL(sigSqlQuery(QString)),this,SLOT(slotSqlQuery(QString)));
}

int Record::getPageCount(QString queryStr)
{
    QSqlDatabase db = MySQLite::openConnection();
    QList<QStringList> recordList = MySQLite::getRecordList(db,queryStr);
    MySQLite::closeConnection(db);
    int rowCount = recordList.size();//记录的数目

    //计算一共有多少页数据,如果不是整数则加1
    int pageCount = rowCount / ROWMUN;
    if (rowCount % ROWMUN > 0) {
        pageCount += 1;
    }
    return pageCount;
}

void Record::initTabelWgt(QTableWidget *tableWidget)
{
    QStringList headList;
    headList<<tr("回路")<<tr("地址")<<tr("通道")<<tr("类型")<<tr("状态")<<tr("数值")<<tr("事件时间")<<tr("安装位置");
    tableWidget->setColumnCount(headList.size());
    tableWidget->setHorizontalHeaderLabels(headList);
    tableWidget->horizontalHeader()->setFixedHeight(30);
    tableWidget->horizontalHeader()->setDefaultSectionSize(140);
    QString hstyleStr ="QHeaderView::section{font: 11pt 'DejaVu Sans'; background-color: rgb(0, 122, 165);"
                       "color: white;}";
    QString vstyleStr ="QHeaderView::section{font: 11pt 'DejaVu Sans'; background-color: rgb(0, 122, 165);"
                       "color: white;}";
    //tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->verticalHeader()->setStyleSheet(vstyleStr);
    tableWidget->verticalHeader()->setFixedWidth(35);
    tableWidget->verticalHeader()->setEnabled(false);
    tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignRight | Qt::AlignVCenter);

    tableWidget->horizontalHeader()->setStyleSheet(hstyleStr);
    tableWidget->horizontalHeader()->setEnabled(false);
    tableWidget->horizontalHeader()->setVisible(true);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->horizontalHeader()->setHighlightSections(false);
    tableWidget->setStyleSheet("QTableWidget::item:selected {color: rgb(255, 255, 255);background-color: rgb(72, 199, 221);}");

    tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);//单元格不可编
    tableWidget->setSelectionBehavior (QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    tableWidget->setSelectionMode (QAbstractItemView::MultiSelection); //设置选择模式，选择单行

    tableWidget->setColumnWidth(0,50);
    tableWidget->setColumnWidth(1,50);
    tableWidget->setColumnWidth(2,50);
    tableWidget->setColumnWidth(3,100);
    tableWidget->setColumnWidth(4,120);
    tableWidget->setColumnWidth(5,100);
    tableWidget->setColumnWidth(6,230);
    tableWidget->setColumnWidth(7,230);
}
/*
* @项目   TBus_SSEF
* @函数   void displayQuery(QString queryStr, QTableWidget *tableWidget);
* @描述   显示查询结果并显示
* @作者   Micheal(陈明明)
* @时间   2019-04-21
*/
void Record::displayQuery(QString queryStr, QTableWidget *tableWidget, int pageCurrent)
{
    tableWidget->clearContents();
    m_pageCount = getPageCount(queryStr);
    ui->lbPageCurrent->setText(QString::number(pageCurrent+1));
    ui->lbPageCount->setText(QString::number(m_pageCount));
    if (m_pageCount - 1 > m_pageCurrent && m_pageCount > 1) {
        ui->tBtnNest->setEnabled(true);
    }

    int baseNum = pageCurrent * 10;
    queryStr = queryStr.left(queryStr.size()-1) + " limit 10 offset "+QString::number(baseNum)+";";
    //qDebug()<<"queryStr : "<<queryStr;
    QSqlDatabase db = MySQLite::openConnection();
    QList<QStringList> recordList = MySQLite::getRecordList(db,queryStr);
    MySQLite::closeConnection(db);
    int rowCount = recordList.size();//记录的数目

    if(rowCount == 0) {
        tableWidget->setRowCount(0);
        ui->lbCountNum->setText(QString::number(0));
        ui->lbPageCount->setText(QString::number(0));
        ui->lbPageCurrent->setText(QString::number(0));
        MsgBox::showInformation(NULL,tr("查询提示"),tr("没有符合条件的记录!"),tr("关闭"));
    } else {
        tableWidget->setRowCount(rowCount);
        ui->lbCountNum->setText(QString::number(rowCount));
        QString typeStr,stateStr,timeStr;
        QDateTime dateTime;
        QFont ft("文泉驿等宽微米黑",10);
        QTableWidgetItem *item;
        for (int row = 0; row < rowCount;row++) {
            ui->tableWgtRecord->setRowHeight(row,45);
            QStringList stringList = recordList.value(row);
            for (int column = 0;column < stringList.size();column++)  {
                item = new QTableWidgetItem;
                item->setFont(ft);
                item->setTextColor(QColor(0,0,0));
                item->setTextAlignment(Qt::AlignCenter);
                switch (column) {
                case R_LOOP:
                    item->setText(stringList.value(column));
                    break;
                case R_CANID:
                    item->setText(stringList.value(column));
                    break;
                case R_PASS:
                    if (stringList.value(column).toInt() != 0) {
                        item->setText(stringList.value(column));
                    } else {
                        item->setText(tr(" "));
                    }
                    break;
                case R_TYPE:
                    typeStr = stringList.value(column);
                    switch (typeStr.toInt()) {
                    case N_HOST:
                        item->setText(tr("主机"));
                        break;
                    case N_EXTE:
                        item->setText(tr("分机"));
                        break;
                    case N_LEAK:
                        item->setText(tr("漏电"));
                        break;
                    case N_TEMP:
                        item->setText(tr("温度"));
                        break;
                    case N_ACV3:
                        item->setText(tr("三相电压"));
                        break;
                    case N_ACI3:
                        item->setText(tr("三相电流"));
                        break;
                    case N_ACV:
                        item->setText(tr("单相电压"));
                        break;
                    case N_ACI:
                        item->setText(tr("单相电流"));
                        break;
                    case N_DCV:
                        item->setText(tr("直流电压"));
                        break;
                    case N_DCI:
                        item->setText(tr("直流电流"));
                        break;
                    }
                    break;
                case R_STATE:
                    stateStr = stringList.value(column);
                    switch (stateStr.toInt()) {
                    case N_LOSTPOW:
                        item->setText(tr("电源中断"));
                        break;
                    case N_OVERVOL:
                        item->setText(tr("过压故障"));
                        break;
                    case N_OVERCUR:
                        item->setText(tr("过流故障"));
                        break;
                    case N_LACKVOL:
                        item->setText(tr("欠压故障"));
                        break;
                    case N_LACKPHA:
                        item->setText(tr("缺相故障"));
                        break;
                    case N_ERRORPHA:
                        item->setText(tr("错相故障"));
                        break;
                    case N_ERROR:
                        item->setText(tr("节点故障"));
                        break;
                    case N_ALARM:
                        item->setText(tr("节点报警"));
                        break;
                    case N_OFFLINE:
                        item->setText(tr("通讯故障"));
                        break;
                    case N_MAINPOW:
                        item->setText(tr("主电故障"));
                        break;
                    case N_BACKPOW:
                        item->setText(tr("备电故障"));
                        break;
                    case N_RESET:
                        item->setText(tr("主机复位"));
                        break;
                    case N_MUTE:
                        item->setText(tr("主机静音"));
                        break;
                    case N_EXTEERROR:
                        item->setText(tr("分机故障"));
                        break;
                    }
                    break;
                case R_VALUE://只有报警记录数值，其他都是--
                    if (stateStr.toInt() == N_ALARM) {
                        item->setText(stringList.value(column));
                    } else {
                        item->setText(tr("--"));
                    }
                    break;
                case R_TIME:
                    timeStr = stringList.value(column);
                    dateTime.setTime_t(timeStr.toUInt());
                    item->setText(dateTime.toString(m_formatTime));
                    break;
                case R_AREA:
                    item->setText(stringList.value(column));
                    break;
                }
                tableWidget->setItem(row,column,item);
            }
        }
    }
}

void Record::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

void Record::deleteAllData()
{
    QSqlDatabase db = MySQLite::openConnection();
    MySQLite::delAllData(db);
    MySQLite::closeConnection(db);
    ui->tableWgtRecord->clearContents();//删除全部内容
}

void Record::deleteSelectData(int Loop,int CanID, uint alarmTime)
{
    QSqlDatabase db = MySQLite::openConnection();
    MySQLite::delSelectData(db,Loop,CanID,alarmTime);
    MySQLite::closeConnection(db);
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnDel();
* @描述
* @作者   Micheal(陈明明)
* @时间   2019-04-20
*/
void Record::slotBtnDel()
{
    int ret = MsgBox::showQuestion(this,tr("操作提示"),tr("要删除选中的记录？"),tr("确定"),tr("取消"));
    if (0 == ret) {
        bool flag = ui->tableWgtRecord->isItemSelected(ui->tableWgtRecord->item(ui->tableWgtRecord->currentRow(),LOOP));
        if (flag == false) {
            MsgBox::showInformation(NULL,tr("操作提示"),tr("未选中要删除的记录!"),tr("关闭"));
            return;
        }
        for (int row = 0;row < ui->tableWgtRecord->rowCount();row++) {
            if (ui->tableWgtRecord->item(row,LOOP)->isSelected()) {
                int loop  = ui->tableWgtRecord->item(row,LOOP)->text().toUInt();
                int CanID = ui->tableWgtRecord->item(row,CANID)->text().toUInt();
                uint alarmTime = QDateTime::fromString(ui->tableWgtRecord->item(row,R_TIME)->text(),m_formatTime).toTime_t();
                deleteSelectData(loop,CanID,alarmTime);
            }
        }
    }
    displayQuery(m_queryStr,ui->tableWgtRecord,m_pageCurrent);
}

void Record::slotBtnAllDel()
{
     int ret = MsgBox::showQuestion(this,tr("操作提示"),tr("要删除全部记录？"),tr("确定"),tr("取消"));
     if (0 == ret) {
         deleteAllData();
     }
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnBack();
* @描述   返回主界面
* @作者   Micheal(陈明明)
* @时间   2019-04-20
*/
void Record::slotBtnBack()
{
    hide();
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnPrint();
* @描述   数据打印
* @作者   Micheal(陈明明)
* @时间   2019-04-20
*/
void Record::slotBtnPrint()
{
    bool flag = ui->tableWgtRecord->isItemSelected(ui->tableWgtRecord->item(ui->tableWgtRecord->currentRow(),LOOP));
    if (flag == false) {
        MsgBox::showInformation(NULL,tr("打印提示"),tr("未选中要打印的内容!"),tr("关闭"));
        return;
    }
    for(int row = 0;row < ui->tableWgtRecord->rowCount();row++) {
        if (ui->tableWgtRecord->item(row,1)->isSelected()) {
            QString loop  = ui->tableWgtRecord->item(row,R_LOOP)->text();
            QString canId = ui->tableWgtRecord->item(row,R_CANID)->text();
            QString pass  = ui->tableWgtRecord->item(row,R_PASS)->text();
            QString type  = ui->tableWgtRecord->item(row,R_TYPE)->text();
            QString state = ui->tableWgtRecord->item(row,R_STATE)->text();
            QString value = ui->tableWgtRecord->item(row,R_VALUE)->text();
            QString time  = ui->tableWgtRecord->item(row,R_TIME)->text();
            QString area  = ui->tableWgtRecord->item(row,R_AREA)->text();
            MyPrint::printData(loop,canId,pass,type,state,value,time,area);
        }
    }
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnQuery();
* @描述   数据查询
* @作者   Micheal(陈明明)
* @时间   2019-04-20
*/
void Record::slotBtnQuery()
{
    m_pageCurrent = 0;
    ui->tBtnLast->setEnabled(false);
    displayQuery(m_queryStr,ui->tableWgtRecord,m_pageCurrent);
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnFilter();
* @描述   数据过滤
* @作者   Micheal(陈明明)
* @时间   2019-04-20
*/
void Record::slotBtnFilter()
{
    m_dataFilter->showConf();
}

void Record::slotSqlQuery(QString queryStr)
{
    m_pageCurrent = 0;
    m_queryStr = queryStr;
    qDebug()<<"queryStr : "<<m_queryStr;
    ui->tBtnLast->setEnabled(false);
    displayQuery(m_queryStr,ui->tableWgtRecord,m_pageCurrent);
}

void Record::slotBtnNest()
{
    m_pageCurrent++;
    if (m_pageCurrent < m_pageCount - 1) {
        ui->tBtnLast->setEnabled(true);
        ui->tBtnNest->setEnabled(true);
        displayQuery(m_queryStr,ui->tableWgtRecord,m_pageCurrent);
    } else if (m_pageCurrent == m_pageCount - 1 ) {
        ui->tBtnLast->setEnabled(true);
        ui->tBtnNest->setEnabled(false);
        displayQuery(m_queryStr,ui->tableWgtRecord,m_pageCurrent);
    }
}

void Record::slotBtnLast()
{
    m_pageCurrent--;
    if (m_pageCurrent > 0) {
        ui->tBtnNest->setEnabled(true);
        ui->tBtnLast->setEnabled(true);
        displayQuery(m_queryStr,ui->tableWgtRecord,m_pageCurrent);
    } else if (0 == m_pageCurrent) {
        ui->tBtnNest->setEnabled(true);
        ui->tBtnLast->setEnabled(false);
        displayQuery(m_queryStr,ui->tableWgtRecord,m_pageCurrent);
    }

}
