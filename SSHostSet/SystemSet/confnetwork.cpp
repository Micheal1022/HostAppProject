#include "confnetwork.h"
#include "ui_confnetwork.h"
#include "SQLite/mysqlite.h"
#include <QProcess>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>
ConfNetWork::ConfNetWork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfNetWork)
{
    ui->setupUi(this);

    initConf();
    connect(ui->tBtnNetWorkOk_1,SIGNAL(clicked(bool)),this,SLOT(slotBtnNetWorkOk_1()));
    connect(ui->tBtnNetWorkOk_2,SIGNAL(clicked(bool)),this,SLOT(slotBtnNetWorkOk_2()));

}

ConfNetWork::~ConfNetWork()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数   void initConf();
* @描述   获取网络配置
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void ConfNetWork::initConf()
{
    QList<QLineEdit*> lineEditList = this->findChildren<QLineEdit*>();
    for(int i = 0; i < lineEditList.size(); i++) {
        //1-255
        QRegExp regExpIP("^[1-9][0-9]|1[0-9][0-9]|2[0-5][0-5]$");
        QLineEdit *lineEdit = lineEditList.at(i);
        lineEdit->setValidator(new QRegExpValidator(regExpIP, this));
    }
    //5000-9999
    QRegExp regExpPort("^[5-9][0-9][0-9][0-9]$");
    ui->lineEditPort_1->setValidator(new QRegExpValidator(regExpPort, this));
    ui->lineEditPort_2->setValidator(new QRegExpValidator(regExpPort, this));
    QString desIP_1,desIP_2,desIP_3,desIP_4,hostIP_1,hostIP_2,hostIP_3,hostIP_4;

    m_lineEditList_1.append(ui->lineEditDesIP_1);
    m_lineEditList_1.append(ui->lineEditDesIP_2);
    m_lineEditList_1.append(ui->lineEditDesIP_3);
    m_lineEditList_1.append(ui->lineEditDesIP_4);
    m_lineEditList_1.append(ui->lineEditHostIP_1);
    m_lineEditList_1.append(ui->lineEditHostIP_2);
    m_lineEditList_1.append(ui->lineEditHostIP_3);
    m_lineEditList_1.append(ui->lineEditHostIP_4);
    m_lineEditList_1.append(ui->lineEditPort_1);

    m_lineEditList_2.append(ui->lineEditDesIP_5);
    m_lineEditList_2.append(ui->lineEditDesIP_6);
    m_lineEditList_2.append(ui->lineEditDesIP_7);
    m_lineEditList_2.append(ui->lineEditDesIP_8);
    m_lineEditList_2.append(ui->lineEditHostIP_5);
    m_lineEditList_2.append(ui->lineEditHostIP_6);
    m_lineEditList_2.append(ui->lineEditHostIP_7);
    m_lineEditList_2.append(ui->lineEditHostIP_8);
    m_lineEditList_2.append(ui->lineEditPort_2);

    //获取数据库IP地址
    QSqlDatabase db1 = MySQLite::openConnection();
    QStringList stringList_1 = MySQLite::getNetWorkIP(db1,1);
    MySQLite::closeConnection(db1);
    QString desIP1  = stringList_1.value(0);
    QString hostIP1 = stringList_1.value(1);
    QString port1   = stringList_1.value(2);
    QString able1   = stringList_1.value(3);
    ui->checkBox_1->setChecked(able1.toUInt());
    QString ipCmdStr_1 = QString("ifconfig eth0 %1").arg(hostIP1);
    QProcess procss_1;
    procss_1.execute(ipCmdStr_1);
    qDebug("******IFCONFIG ETH0**********");
    qDebug()<<"port1   : "<<port1;
    qDebug()<<"desIP1  : "<<desIP1;
    qDebug()<<"hostIP1 : "<<hostIP1;
    qDebug()<<"CmdStr_1: "<<ipCmdStr_1;
    parseStringIP( desIP1, desIP_1, desIP_2, desIP_3, desIP_4);
    parseStringIP(hostIP1,hostIP_1,hostIP_2,hostIP_3,hostIP_4);

    ui->lineEditPort_1->setText(port1);
    ui->lineEditDesIP_1->setText(desIP_1);
    ui->lineEditDesIP_2->setText(desIP_2);
    ui->lineEditDesIP_3->setText(desIP_3);
    ui->lineEditDesIP_4->setText(desIP_4);
    ui->lineEditHostIP_1->setText(hostIP_1);
    ui->lineEditHostIP_2->setText(hostIP_2);
    ui->lineEditHostIP_3->setText(hostIP_3);
    ui->lineEditHostIP_4->setText(hostIP_4);

    QSqlDatabase db2 = MySQLite::openConnection();
    QStringList stringList_2 = MySQLite::getNetWorkIP(db2,2);
    MySQLite::closeConnection(db2);
    QString desIP2  = stringList_2.value(0);
    QString hostIP2 = stringList_2.value(1);
    QString port2   = stringList_2.value(2);
    QString able2   = stringList_2.value(3);
    ui->checkBox_2->setChecked(able2.toUInt());
    QString ipCmdStr_2 = QString("ifconfig eth1 %1").arg(hostIP2);
    QProcess procss_2;
    procss_2.execute(ipCmdStr_2);
    qDebug("******IFCONFIG ETH1**********");
    qDebug()<<"port2   : "<<port2;
    qDebug()<<"desIP2  : "<<desIP2;
    qDebug()<<"hostIP2 : "<<hostIP2;
    qDebug()<<"CmdStr_2: "<<ipCmdStr_2;
    parseStringIP( desIP2, desIP_1, desIP_2, desIP_3, desIP_4);
    parseStringIP(hostIP2,hostIP_1,hostIP_2,hostIP_3,hostIP_4);
    ui->lineEditPort_2->setText(port2);
    ui->lineEditDesIP_5->setText(desIP_1);
    ui->lineEditDesIP_6->setText(desIP_2);
    ui->lineEditDesIP_7->setText(desIP_3);
    ui->lineEditDesIP_8->setText(desIP_4);
    ui->lineEditHostIP_5->setText(hostIP_1);
    ui->lineEditHostIP_6->setText(hostIP_2);
    ui->lineEditHostIP_7->setText(hostIP_3);
    ui->lineEditHostIP_8->setText(hostIP_4);

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

void ConfNetWork::setNetWorkIP(QList<QLineEdit *> lineEditList, int netNum)
{
    int able;
    if (netNum == 1) {
        if (ui->checkBox_1->isChecked() == false) {
            able = Qt::Unchecked;
        } else {
            able = Qt::Checked;
        }
    } else {
        if (ui->checkBox_2->isChecked() == false) {
            able = Qt::Unchecked;
        } else {
            able = Qt::Checked;
        }
    }

    QString desIP_1  = lineEditList.value(0)->text();
    QString desIP_2  = lineEditList.value(1)->text();
    QString desIP_3  = lineEditList.value(2)->text();
    QString desIP_4  = lineEditList.value(3)->text();
    QString hostIP_1 = lineEditList.value(4)->text();
    QString hostIP_2 = lineEditList.value(5)->text();
    QString hostIP_3 = lineEditList.value(6)->text();
    QString hostIP_4 = lineEditList.value(7)->text();
    QString port     = lineEditList.value(8)->text();

    if(port.isEmpty()) {
        QMessageBox::information(this,tr("操作提示"), tr("端口不能为空！"),tr("关闭"));
        return;
    }

    if(desIP_1.isEmpty() || desIP_2.isEmpty() || desIP_3.isEmpty() || desIP_4.isEmpty()) {
        QMessageBox::information(this,tr("操作提示"), tr("目标IP地址不能为空！"),tr("关闭"));
        return;
    }

    if(hostIP_1.isEmpty() || hostIP_2.isEmpty() || hostIP_3.isEmpty() || hostIP_4.isEmpty()) {
        QMessageBox::information(this,tr("操作提示"), tr("IP地址不能为空！"),tr("关闭"));
        return;
    }

    QString desIP = desIP_1 +"."+desIP_2 +"."+ desIP_3 +"."+ desIP_4;
    QString hostIP = hostIP_1 +"."+hostIP_2 +"."+ hostIP_3 +"."+ hostIP_4;

    QSqlDatabase db = MySQLite::openConnection();
    if(MySQLite::setNetWorkIP(db,netNum,able,desIP,hostIP,port)) {
        MySQLite::closeConnection(db);
        QMessageBox::information(this,tr("操作提示"), tr("IP地址配置成功，重启后生效！"),tr("关闭"));
        return;
    } else {
        MySQLite::closeConnection(db);
        QMessageBox::information(this,tr("操作提示"), tr("IP地址配置失败！"),tr("关闭"));
        return;
    }
}
/*
* @项目   TBus_SSEF
* @函数   void parseStringIP(QString ip, QString &ip_1, QString &ip_2, QString &ip_3, QString &ip_4;
* @描述   解析地址字符串成为单个地址
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void ConfNetWork::parseStringIP(QString ip, QString &ip_1, QString &ip_2, QString &ip_3,QString &ip_4)
{
    int index_0,index_1,index_2,strSize;
    strSize = ip.size();
    index_0 = ip.indexOf(".");
    index_1 = ip.indexOf(".",index_0+1);
    index_2 = ip.indexOf(".",index_1+1);

    ip_1 = ip.left(index_0);
    ip_2 = ip.mid(index_0+1,index_1 - index_0 - 1);
    ip_3 = ip.mid(index_1+1,index_2 - index_1 - 1);
    ip_4 = ip.right(strSize - index_2 - 1);
}
/*
* @项目   TBus_SSEF
* @函数   void slotBtnNetWorkOk();
* @描述   设置网络参数
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void ConfNetWork::slotBtnNetWorkOk_1()
{
    setNetWorkIP(m_lineEditList_1,1);
}

void ConfNetWork::slotBtnNetWorkOk_2()
{
    setNetWorkIP(m_lineEditList_2,2);
}

void ConfNetWork::slotBtnKeyIndex(int index)
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
