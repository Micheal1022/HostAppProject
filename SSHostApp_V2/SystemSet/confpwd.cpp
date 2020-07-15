#include "confpwd.h"
#include "ui_confpwd.h"
#include "SQLite/mysqlite.h"
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "MsgBox/msgbox.h"
#define ADMIN   0
#define SUPER   1
ConfPwd::ConfPwd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfPwd)
{
    ui->setupUi(this);

    initKey();
    connect(ui->tBtnPwdOk,SIGNAL(clicked(bool)),this,SLOT(slotBtnPwdOk()));
    connect(ui->tBtnResetPwdOk,SIGNAL(clicked(bool)),this,SLOT(slotBtnRestore()));
    connect(ui->tBtnAdmin,SIGNAL(clicked(bool)),this,SLOT(slotBtnAdmin()));
    connect(ui->tBtnSuper,SIGNAL(clicked(bool)),this,SLOT(slotBtnSuper()));
    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnPwdOk);
    m_unSelectStr = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(0, 122, 165);background-color: rgb(255, 255, 255);}";
    m_selectStr   = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(255, 255, 255);background-color: rgb(0, 122, 165);}";
    btnAdminSelect = true;
    btnSuperSelect = false;
    ui->tBtnAdmin->setStyleSheet(m_selectStr);
}

ConfPwd::~ConfPwd()
{
    delete ui;
}

void ConfPwd::initKey()
{
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
    connect(m_btnKeyGroup,SIGNAL(buttonClicked(int)),this,SLOT(slotBtnKey(int)));
    for (int index = 0 ; index < m_btnKeyGroup->buttons().count(); index++) {
        setGraphicsEffect(new QGraphicsDropShadowEffect,m_btnKeyGroup->button(index));
    }
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnPwdOk();
* @描述   更新密码确定
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void ConfPwd::slotBtnPwdOk()
{
    QString pwdStr,typeStr;
    QString newPwd = ui->lineEditNewPwd->text();
    QString oldPwd = ui->lineEditOldPwd->text();
    if (newPwd.isEmpty() || oldPwd.isEmpty()) {
        MsgBox::showInformation(NULL,tr("操作提示"),tr("原密码和新密码不能为空!"),tr("关闭"));
        return;
    }

    if (btnAdminSelect == true) {
        typeStr = QString("ADMIN");
    } else if (btnSuperSelect == true) {
        typeStr = QString("SUPER");
    }
    QSqlDatabase db = MySQLite::openConnection();
    pwdStr = MySQLite::getUserPwd(db,typeStr);
    if (oldPwd == pwdStr) {
        if (MySQLite::setUserPwd(db,typeStr,newPwd) == true) {
            MySQLite::closeConnection(db);
            ui->lineEditOldPwd->clear();
            ui->lineEditNewPwd->clear();
            MsgBox::showInformation(NULL,tr("操作提示"),tr("密码修改成功!"),tr("关闭"));
        } else {
            MySQLite::closeConnection(db);
            ui->lineEditOldPwd->clear();
            ui->lineEditNewPwd->clear();
            MsgBox::showInformation(NULL,tr("操作提示"),tr("密码修改失败!"),tr("关闭"));
        }
    }
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnRestore();
* @描述   恢复出厂密码
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void ConfPwd::slotBtnRestore()
{
    QSqlDatabase db = MySQLite::openConnection();
    if (MySQLite::setRestorePwd(db)) {
        MySQLite::closeConnection(db);
        MsgBox::showInformation(NULL,tr("操作提示"),tr("密码恢复成功!"),tr("关闭"));
    } else {
        MySQLite::closeConnection(db);
        MsgBox::showInformation(NULL,tr("操作提示"),tr("密码恢复失败!"),tr("关闭"));
    }
}

void ConfPwd::slotBtnAdmin()
{
    btnAdminSelect = true;
    btnSuperSelect = false;
    ui->tBtnAdmin->setStyleSheet(m_selectStr);
    ui->tBtnSuper->setStyleSheet(m_unSelectStr);
}

void ConfPwd::slotBtnSuper()
{
    btnAdminSelect = false;
    btnSuperSelect = true;
    ui->tBtnAdmin->setStyleSheet(m_unSelectStr);
    ui->tBtnSuper->setStyleSheet(m_selectStr);
}

void ConfPwd::slotBtnKey(int index)
{
    QString text = m_btnKeyGroup->button(index)->text();
    if (index == 10) {
        if (focusWidget() == NULL) {
            return;
        }
        if (focusWidget()->inherits("QLineEdit")) {
            QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
            edit->clear();
        }
    } else {
        if (focusWidget() == NULL) {
            return;
        }
        if (focusWidget()->inherits("QLineEdit")) {
            QLineEdit *edit = qobject_cast<QLineEdit*>(focusWidget());
            QString curStr = edit->text();
            edit->setText(curStr+text);
        }
    }
}

void ConfPwd::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

