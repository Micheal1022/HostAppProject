#include "confaddr.h"
#include "ui_confaddr.h"
#include <QDebug>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "MsgBox/msgbox.h"
#include "infodlg.h"
ConfAddr::ConfAddr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfAddr)
{
    ui->setupUi(this);
    m_infoDlg = new InfoDlg;
    initTableWidget(ui->tableWidget);
    getUseLoopList();
    connect(ui->tBtnDbOpen,SIGNAL(clicked(bool)),this,SLOT(slotDbOpen()));
    connect(ui->tBtnDbSave,SIGNAL(clicked(bool)),this,SLOT(slotDbSave()));
    connect(ui->tBtnAllStart,SIGNAL(clicked(bool)),this,SLOT(slotAllStart()));
    connect(ui->tBtnAllClose,SIGNAL(clicked(bool)),this,SLOT(slotAllClose()));
    connect(ui->tableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(slotCellClick(int,int)));


}

ConfAddr::~ConfAddr()
{
    delete ui;
}

void ConfAddr::showNodeInfo()
{

}



void ConfAddr::getUseLoopList()
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }
    database.setDatabaseName("SYSTEM.db");

    if (!database.open()) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据库文件打开失败!!!"),tr("关闭"));
        return;
    }

    QList<int> loopList;
    QString sqlQuery = "select LOOPNUM from CONFLOOP where ENABLE = 1;";
    QSqlQuery query(database);
    if (query.exec(sqlQuery)) {
        while(query.next()) {
            loopList.append(query.value(0).toInt());
        }
    }
    query.finish();
    query.clear();
    QSqlDatabase::removeDatabase("QSQLITE");
    QString textStr = tr("回路-");
    for (int i = 0;i < loopList.count();i++) {
        QString itemStr = textStr + QString::number(loopList.at(i));
        ui->cbBoxLoop->addItem(itemStr);
    }
}

bool ConfAddr::updateNodeInfo(QString loop, QString canId, QString enable)
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }
    database.setDatabaseName("NODEINFO.db");

    if (!database.open()) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据库文件打开失败!!!"),tr("关闭"));
    }
    QString sqlQuery = QString("update NODELIST set ABLE = %1 where LOOP = %2 and ID = %3;").arg(enable).arg(loop).arg(canId);
    qDebug()<<"sqlQuery : "<<sqlQuery;
    QSqlQuery query(database);
    if (!query.exec(sqlQuery)) {
        return false;
    }
    query.finish();
    query.clear();
    QSqlDatabase::removeDatabase("QSQLITE");
    return true;
}

void ConfAddr::initTableWidget(QTableWidget *tableWidget)
{
    QStringList headList;
    headList<<tr("回路")<<tr("ID地址")<<tr("状态")<<tr("安装位置");
    tableWidget->setColumnCount(headList.size());
    tableWidget->setHorizontalHeaderLabels(headList);
    tableWidget->horizontalHeader()->setFixedHeight(30);
    tableWidget->horizontalHeader()->setDefaultSectionSize(140);
    QString hstyleStr ="QHeaderView::section{font: 12pt '文泉驿等宽微米黑'; background-color: rgb(0, 122, 165);"
                       "color: white;}";
    QString vstyleStr ="QHeaderView::section{font: 12pt '文泉驿等宽微米黑'; background-color: rgb(0, 122, 165);"
                       "color: white;}";
    //tableWidget->setFocusPolicy(Qt::NoFocus);
//    tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{width:50px;background:rgba(255,255,255,0%);margin:0px,0px,0px,0px;"
//                                                    "padding-top:25px;padding-bottom:25px;}");
    QString verticalScrollBarString = "QScrollBar:vertical{ width:50px; background:rgb(0,0,0,0%); margin:0px,0px,0px,0px; padding-top:50px; padding-bottom:50px;}"
                                      "QScrollBar::handle:vertical{ width:50px;background:rgb(0,0,0,25%);border-radius:5px;min-height:50px;}"
                                      "QScrollBar::handle:vertical:hover{ width:50px;background:rgb(0,0,0,50%); border-radius:5px; min-height:50px;}";
    tableWidget->verticalScrollBar()->setStyleSheet(verticalScrollBarString);


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
    tableWidget->setSelectionMode (QAbstractItemView::SingleSelection); //设置选择模式，选择单行

    tableWidget->setColumnWidth(0,80);
    tableWidget->setColumnWidth(1,80);
    tableWidget->setColumnWidth(2,100);
    tableWidget->setColumnWidth(3,250);

}


QList<QStringList> ConfAddr::getNodeInfoList(int loop)
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        database = QSqlDatabase::database("qt_sql_default_connection");
    else {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }
    database.setDatabaseName("NODEINFO.db");
    if (!database.open()) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据库文件打开失败!!!"),tr("关闭"));
    }

    QList<QStringList> nodeInfoStringList;
    QString sqlQuery = "select LOOP,ID,ABLE,AREA from NODELIST where LOOP = "+QString::number(loop)+" order by ID asc;";
    //qDebug()<<"sqlQuery : "<<sqlQuery;
    QSqlQuery query(database);

    if (query.exec(sqlQuery)) {
        while (query.next()) {
            QStringList nodeStringList;
            nodeStringList.append(query.value(0).toString());
            nodeStringList.append(query.value(1).toString());
            nodeStringList.append(query.value(2).toString());
            nodeStringList.append(query.value(3).toString());
            nodeInfoStringList.append(nodeStringList);
        }
    }
    query.finish();
    query.clear();
    database.close();
    //QT数据库移除
    QSqlDatabase::removeDatabase("QSQLITE");
    return nodeInfoStringList;
}

void ConfAddr::slotDbOpen()
{

    QString text = ui->cbBoxLoop->currentText();
    int loop;
    if (text.size() > 5) {
        loop = text.mid(5,text.count()-2).toInt();
    } else {
        loop = text.mid(3,text.count()-2).toInt();
    }

    m_nodeInfoList.clear();
    m_nodeInfoList = getNodeInfoList(loop);

    ui->tableWidget->setRowCount(m_nodeInfoList.count());
    ui->tableWidget->clearContents();
    QTableWidgetItem *item;
    for (int row = 0; row < m_nodeInfoList.count();row++) {
        QStringList strList = m_nodeInfoList.at(row);
        ui->tableWidget->setRowHeight(row,35);
        for (int column = 0;column < ui->tableWidget->rowCount();column++) {
            item = new QTableWidgetItem;
            item->setFont(QFont("文泉驿等宽微米黑",14));
            item->setTextAlignment(Qt::AlignCenter);
            item->setTextColor(QColor(17,17,17));

            if (column == 0) {
                item->setText(strList.value(0));
            } else if (column == 1) {
                item->setText(strList.value(1));
            } else if(column == 2) {
                if(strList.value(2) == "0") {
                    item->setText(tr("屏蔽"));
                    item->setTextColor(QColor(255,0,0));
                } else {
                    item->setText(tr("启用"));
                    item->setTextColor(QColor(0,255,0));
                }
            } else if(column == 3) {
                item->setText(strList.value(3));
            }
            ui->tableWidget->setItem(row,column,item);
        }
    }
}

void ConfAddr::slotCellClick(int row, int column)
{
    if (column == 2){
        if(ui->tableWidget->item(row,column)->text() == tr("启用")) {
            ui->tableWidget->item(row,column)->setText(tr("屏蔽"));
            ui->tableWidget->item(row,column)->setTextColor(QColor(255,0,0));
        } else {
            ui->tableWidget->item(row,column)->setText(tr("启用"));
            ui->tableWidget->item(row,column)->setTextColor(QColor(0,255,0));
        }
    }
}

void ConfAddr::slotDbSave()
{
    if (ui->tableWidget->rowCount() == 0) {
        MsgBox::showInformation(NULL,tr("系统提示"),tr("没有要保存的数据!!!"),tr("关闭"));
        return;
    }
    //m_infoDlg->initInfoDlg(tr("系统提示"),tr("数据库正在存储,请勿断电!!!"));
    //m_infoDlg->show();
    for (int row = 0; row < ui->tableWidget->rowCount();row++) {
        QString textStr = ui->tableWidget->item(row,2)->text();
        QString str = m_nodeInfoList.value(row).value(2);
        int enable = 0;
        if (textStr == tr("启用")) {
            enable = 1;
        } else {
            enable = 0;
        }
        if (enable != str.toInt()) {
            updateNodeInfo(ui->tableWidget->item(row,0)->text(),ui->tableWidget->item(row,1)->text(),QString::number(enable));
        }
    }
    //m_infoDlg->hide();
    MsgBox::showInformation(NULL,tr("系统提示"),tr("数据库保存完毕!!!"),tr("关闭"));
}

void ConfAddr::slotAllStart()
{
    if (ui->tableWidget->rowCount() == 0) {
        MsgBox::showInformation(NULL,tr("系统提示"),tr("请打开数据库文件再操作!!!"),tr("关闭"));
        return;
    }
    for (int row = 0 ;row < ui->tableWidget->rowCount();row++) {
        if (ui->tableWidget->item(row,2)->text() == tr("屏蔽"))
        ui->tableWidget->item(row,2)->setText(tr("启用"));
        ui->tableWidget->item(row,2)->setTextColor(QColor(0,255,0));
    }
}

void ConfAddr::slotAllClose()
{
    if (ui->tableWidget->rowCount() == 0) {
        MsgBox::showInformation(NULL,tr("系统提示"),tr("请打开数据库文件再操作!!!"),tr("关闭"));
        return;
    }
    for (int row = 0 ;row < ui->tableWidget->rowCount();row++) {
        if (ui->tableWidget->item(row,2)->text() == tr("启用"))
        ui->tableWidget->item(row,2)->setText(tr("屏蔽"));
        ui->tableWidget->item(row,2)->setTextColor(QColor(255,0,0));
    }
}


