#include "userlogin.h"
#include "ui_userlogin.h"
#include "SQLite/mysqlite.h"
#include "MsgBox/msgbox.h"
#include <QButtonGroup>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>



UserLogin::UserLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserLogin)
{
    ui->setupUi(this);
    setGeometry(0,0,1024,600);
    setWindowFlags(Qt::FramelessWindowHint);
    initKey();
    initConnect();

    setGraphicsEffect(new QGraphicsDropShadowEffect,ui->tBtnOk);
    m_unSelectStr = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(0, 122, 165);background-color: rgb(255, 255, 255);}";
    m_selectStr   = "QToolButton{font: 20pt '文泉驿等宽微米黑';border:2px solid rgb(0, 122, 165);"
                    "border-radius:10px;color:rgb(255, 255, 255);background-color: rgb(0, 122, 165);}";
    m_adminSelect = true;
    m_superSelect = false;
    ui->tBtnAdmin->setStyleSheet(m_selectStr);
    connect(ui->tBtnAdmin,SIGNAL(clicked(bool)),this,SLOT(slotBtnAdmin()));
    connect(ui->tBtnSuper,SIGNAL(clicked(bool)),this,SLOT(slotBtnSuper()));

}

UserLogin::~UserLogin()
{
    delete ui;
}

void UserLogin::initConnect()
{
    connect(ui->tBtnOk,SIGNAL(clicked(bool)),this,SLOT(slotBtnOk()));

}

void UserLogin::initKey()
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

void UserLogin::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}
/*
* @项目   TBus_SSEF
* @函数   void confShow();
* @描述   显示登录界面
* @作者   Micheal(陈明明)
* @时间   2019-04-15
*/
void UserLogin::confShow()
{
    ui->lineEditPwd->clear();
    ui->lineEditPwd->setFocus();
    QSqlDatabase db = MySQLite::openConnection();
    m_adminPwd = MySQLite::getUserPwd(db,QString("ADMIN"));
    m_superPwd = MySQLite::getUserPwd(db,QString("SUPER"));
    MySQLite::closeConnection(db);
    //qDebug("**************************");
    //qDebug()<<"m_adminPwd :" <<m_adminPwd;
    //qDebug()<<"m_superPwd :" <<m_superPwd;
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnOk();
* @描述   确定输入的密码是否正确
* @作者   Micheal(陈明明)
* @时间   2019-04-15
*/
void UserLogin::slotBtnOk()
{
    QString pwd = ui->lineEditPwd->text();
    if (pwd.isEmpty()) {
        MsgBox::showInformation(NULL,tr(" 操作提示"), tr("密码不能为空！"),tr("关闭"));
        return;
    }
    if (m_adminSelect == true) {
        if (pwd == m_adminPwd) {
            emit sigUserLogin(ADMIN);
            ui->lineEditPwd->clear();
            return;
        }
    } else if (m_superSelect == true ) {
        if (pwd == m_superPwd) {
            emit sigUserLogin(SUPER);
            ui->lineEditPwd->clear();
            return;
        }
    }
    ui->lineEditPwd->clear();
    MsgBox::showInformation(NULL,tr(" 操作提示"), tr("密码错误！"),tr("关闭"));
}

void UserLogin::slotBtnAdmin()
{
    m_adminSelect = true;
    m_superSelect = false;
    ui->tBtnAdmin->setStyleSheet(m_selectStr);
    ui->tBtnSuper->setStyleSheet(m_unSelectStr);
}

void UserLogin::slotBtnSuper()
{
    m_adminSelect = false;
    m_superSelect = true;
    ui->tBtnAdmin->setStyleSheet(m_unSelectStr);
    ui->tBtnSuper->setStyleSheet(m_selectStr);
}

void UserLogin::slotBtnKey(int index)
{
    QString text = m_btnKeyGroup->button(index)->text();
    if (index == 10) {
        ui->lineEditPwd->clear();
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

