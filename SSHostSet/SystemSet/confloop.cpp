#include "confloop.h"
#include "ui_confloop.h"
#include "SQLite/mysqlite.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "MsgBox/msgbox.h"
#define DISABLE 0
#define ENABLE  1
#define LOOPCOUNT 12
ConfLoop::ConfLoop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfLoop)
{
    ui->setupUi(this);
    initLoopBtn();
    initConf();

}

ConfLoop::~ConfLoop()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数   void initConf();
* @描述   配置初始状态
* @作者   Micheal(陈明明)
* @时间   2019-04-19
*/
void ConfLoop::initConf()
{
    m_unSelectStr = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(0, 122, 165);background-color: rgb(255, 255, 255);}";
    m_selectStr   = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(255, 255, 255);background-color: rgb(0, 122, 165);}";
    //获取可用的回路
    QSqlDatabase db = MySQLite::openConnection();
    int loopCount = MySQLite::getLoopNum(db);
    setBtnVisible(loopCount);
    QList<int> loopList = MySQLite::getLoopConf(db);
    MySQLite::closeConnection(db);
    for (int index = 0; index < loopList.count(); index++) {
        if (loopList.value(index) == 1) {
            m_btnSelect[index] = true;
            m_btnLoopGroup->button(index)->setStyleSheet(m_selectStr);
        } else {
            m_btnSelect[index] = false;
            m_btnLoopGroup->button(index)->setStyleSheet(m_unSelectStr);
        }
    }
}

void ConfLoop::initLoopBtn()
{
    m_btnLoopGroup = new QButtonGroup;
    m_btnLoopGroup->addButton(ui->tBtnLoop_1,0);
    m_btnLoopGroup->addButton(ui->tBtnLoop_2,1);
    m_btnLoopGroup->addButton(ui->tBtnLoop_3,2);
    m_btnLoopGroup->addButton(ui->tBtnLoop_4,3);
    m_btnLoopGroup->addButton(ui->tBtnLoop_5,4);
    m_btnLoopGroup->addButton(ui->tBtnLoop_6,5);
    m_btnLoopGroup->addButton(ui->tBtnLoop_7,6);
    m_btnLoopGroup->addButton(ui->tBtnLoop_8,7);
    m_btnLoopGroup->addButton(ui->tBtnLoop_9,8);
    m_btnLoopGroup->addButton(ui->tBtnLoop_10,9);
    m_btnLoopGroup->addButton(ui->tBtnLoop_11,10);
    m_btnLoopGroup->addButton(ui->tBtnLoop_12,11);

    connect(m_btnLoopGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnLoop(int)));
    for (int index = 0 ; index < m_btnLoopGroup->buttons().count(); index++) {
        m_btnSelect.append(false);
        m_btnLoopGroup->button(index)->setVisible(false);
        setGraphicsEffect(new QGraphicsDropShadowEffect,m_btnLoopGroup->button(index));
    }
}

void ConfLoop::setBtnVisible(int count)
{
    for (int index = 0; index < count; index++) {
        m_btnLoopGroup->button(index)->setVisible(true);
    }
}

void ConfLoop::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

void ConfLoop::slotBtnLoop(int index)
{
    if (m_btnSelect.value(index) == false) {
        m_btnSelect[index] = true;
        m_btnLoopGroup->button(index)->setStyleSheet(m_selectStr);
        QSqlDatabase db = MySQLite::openConnection();
        if(!MySQLite::setLoopConf(db,index+1,m_btnSelect.value(index) ? 1 : 0)) {
            MsgBox::showInformation(NULL,tr("操作提示"), tr("此回路开启失败!"),tr("关闭"));
        } else {
            MsgBox::showInformation(NULL,tr("操作提示"), tr("此回路开启成功!"),tr("关闭"));
        }
        MySQLite::closeConnection(db);
    } else {
        m_btnSelect[index] = false;
        m_btnLoopGroup->button(index)->setStyleSheet(m_unSelectStr);
        QSqlDatabase db = MySQLite::openConnection();
        if(!MySQLite::setLoopConf(db,index+1,m_btnSelect.value(index) ? 1 : 0)) {
            MsgBox::showInformation(NULL,tr("操作提示"), tr("此回路关闭失败!"),tr("关闭"));
        } else {
            MsgBox::showInformation(NULL,tr("操作提示"), tr("此回路关闭成功!"),tr("关闭"));
        }
        MySQLite::closeConnection(db);
    }
}


