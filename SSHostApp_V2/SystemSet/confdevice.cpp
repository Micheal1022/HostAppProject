#include "confdevice.h"
#include "ui_confdevice.h"
#include <QButtonGroup>
#include <QGraphicsDropShadowEffect>
#include "SQLite/mysqlite.h"
#include "MsgBox/msgbox.h"

#include <QFileInfo>

#define DEV_EFMQ  0
#define DEV_PMFE  1
#define DEV_DB    2
#define DEV_APP   3
ConfDevice::ConfDevice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfDevice)
{
    ui->setupUi(this);

    m_unSelectStr = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(0, 122, 165);background-color: rgb(255, 255, 255);}";
    m_selectStr   = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(255, 255, 255);background-color: rgb(0, 122, 165);}";

    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnUpdateDB);
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnUpdateApp);
    connect(ui->tBtnUpdateDB,SIGNAL(clicked(bool)),this,SLOT(slotBtnUpdateDB()));
    connect(ui->tBtnUpdateApp,SIGNAL(clicked(bool)),this,SLOT(slotBtnUpdateApp()));

    m_btnDevGroup = new QButtonGroup;
    m_btnDevGroup->addButton(ui->tBtnEFMQ,DEV_EFMQ);    //电气火灾
    m_btnDevGroup->addButton(ui->tBtnPMFE,DEV_PMFE);    //电源监控
    connect(m_btnDevGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnDevType(int)));
    for (int index = 0 ; index < m_btnDevGroup->buttons().count(); index++) {
        setGraphicsEffect(new QGraphicsDropShadowEffect,m_btnDevGroup->button(index));
    }

    //获取可用的设备
    QSqlDatabase devdb = MySQLite::openConnection();
    int devType = MySQLite::getDevType(devdb);
    MySQLite::closeConnection(devdb);

    if (DEV_EFMQ == devType) {
        ui->tBtnEFMQ->setStyleSheet(m_selectStr);
        ui->tBtnPMFE->setStyleSheet(m_unSelectStr);
    } else if (DEV_PMFE == devType) {
        ui->tBtnEFMQ->setStyleSheet(m_unSelectStr);
        ui->tBtnPMFE->setStyleSheet(m_selectStr);
    }


    m_btnLoopGroup = new QButtonGroup;
    m_btnLoopGroup->addButton(ui->tBtn_4,0);
    m_btnLoopGroup->addButton(ui->tBtn_8,1);
    m_btnLoopGroup->addButton(ui->tBtn_12,2);
    connect(m_btnLoopGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnIndex(int)));
    for (int index = 0 ; index < m_btnLoopGroup->buttons().count(); index++) {
        setGraphicsEffect(new QGraphicsDropShadowEffect,m_btnLoopGroup->button(index));
    }
    //获取可用的回路
    QSqlDatabase db = MySQLite::openConnection();
    int loopCount = MySQLite::getLoopNum(db);
    MySQLite::closeConnection(db);

    if (4 == loopCount) {
        ui->tBtn_4->setStyleSheet(m_selectStr);
        ui->tBtn_8->setStyleSheet(m_unSelectStr);
        ui->tBtn_12->setStyleSheet(m_unSelectStr);
    } else if (8 == loopCount) {
        ui->tBtn_4->setStyleSheet(m_unSelectStr);
        ui->tBtn_8->setStyleSheet(m_selectStr);
        ui->tBtn_12->setStyleSheet(m_unSelectStr);
    } else if (12 == loopCount) {
        ui->tBtn_4->setStyleSheet(m_unSelectStr);
        ui->tBtn_8->setStyleSheet(m_unSelectStr);
        ui->tBtn_12->setStyleSheet(m_selectStr);
    }
}

ConfDevice::~ConfDevice()
{
    delete ui;
}

void ConfDevice::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

void ConfDevice::slotBtnIndex(int index)
{
    int loopCount = (index + 1) * 4;
    if (4 == loopCount) {
        ui->tBtn_4->setStyleSheet(m_selectStr);
        ui->tBtn_8->setStyleSheet(m_unSelectStr);
        ui->tBtn_12->setStyleSheet(m_unSelectStr);
    } else if (8 == loopCount) {
        ui->tBtn_4->setStyleSheet(m_unSelectStr);
        ui->tBtn_8->setStyleSheet(m_selectStr);
        ui->tBtn_12->setStyleSheet(m_unSelectStr);
    } else if (12 == loopCount) {
        ui->tBtn_4->setStyleSheet(m_unSelectStr);
        ui->tBtn_8->setStyleSheet(m_unSelectStr);
        ui->tBtn_12->setStyleSheet(m_selectStr);
    }

    QSqlDatabase db = MySQLite::openConnection();
    for (int ind = loopCount+1; ind <= 12; ind++) {
        MySQLite::setLoopConf(db,ind, 0);
    }

    if (!MySQLite::setLoopNum(db,loopCount)) {
        MsgBox::showInformation(this,tr("操作提示"), tr("设置失败！"),tr("关闭"));
    } else {
        MsgBox::showInformation(this,tr("操作提示"), tr("设置成功,重启后生效！"),tr("关闭"));
    }
    MySQLite::closeConnection(db);

}

void ConfDevice::slotBtnUpdateDB()
{
    QFileInfo filePaht_1("/media/sda1/NODEINFO.db");
    if (filePaht_1.exists() == true) {
        ::system("cp /media/sda1/NODEINFO.db /root/SSApp/");
        MsgBox::showInformation(this,tr("操作提示"), tr("更新成功,重启后生效！"),tr("关闭"));
        return;
    }
    QFileInfo filePaht_2("/media/sdb1/NODEINFO.db");
    if (filePaht_2.exists() == true) {
        ::system("cp /media/sdb1/NODEINFO.db /root/SSApp/");
        MsgBox::showInformation(this,tr("操作提示"), tr("更新成功,重启后生效！"),tr("关闭"));
        return;
    }
    QFileInfo filePaht_3("/media/mmcblk0p1/NODEINFO.db");
    if (filePaht_3.exists() == true) {
        ::system("cp /media/mmcblk0p1/NODEINFO.db /root/SSApp/");
        MsgBox::showInformation(this,tr("操作提示"), tr("更新成功,重启后生效！"),tr("关闭"));
        return;
    }
    MsgBox::showInformation(this,tr("操作提示"), tr("文件不存在,更新失败！"),tr("关闭"));
}

void ConfDevice::slotBtnUpdateApp()
{
    QFileInfo filePaht_1("/media/sda1/ssApp");
    if (filePaht_1.exists() == true) {
        ::system("cp /media/sda1/ssApp /root/SSApp/");
        MsgBox::showInformation(this,tr("操作提示"), tr("更新成功,重启后生效！"),tr("关闭"));
        return;
    }
    QFileInfo filePaht_2("/media/sdb1/ssApp");
    if (filePaht_2.exists() == true) {
        ::system("cp /media/sdb1/ssApp /root/SSApp/");
        MsgBox::showInformation(this,tr("操作提示"), tr("更新成功,重启后生效！"),tr("关闭"));
        return;
    }
    QFileInfo filePaht_3("/media/mmcblk0p1/ssApp");
    if (filePaht_3.exists() == true) {
        ::system("cp /media/mmcblk0p1/ssApp /root/SSApp/");
        MsgBox::showInformation(this,tr("操作提示"), tr("更新成功,重启后生效！"),tr("关闭"));
        return;
    }
    MsgBox::showInformation(this,tr("操作提示"), tr("文件不存在,更新失败！"),tr("关闭"));
}

void ConfDevice::slotBtnDevType(int index)
{
    if (DEV_EFMQ == index) {
        ui->tBtnEFMQ->setStyleSheet(m_selectStr);
        ui->tBtnPMFE->setStyleSheet(m_unSelectStr);
    } else if (DEV_PMFE == index) {
        ui->tBtnEFMQ->setStyleSheet(m_unSelectStr);
        ui->tBtnPMFE->setStyleSheet(m_selectStr);
    }
    QSqlDatabase db = MySQLite::openConnection();
    if (!MySQLite::setDevType(db,index)) {
        MsgBox::showInformation(this,tr("操作提示"), tr("设置失败！"),tr("关闭"));
    } else {
        MsgBox::showInformation(this,tr("操作提示"), tr("设置成功,重启后生效！"),tr("关闭"));
    }
    MySQLite::closeConnection(db);

}
