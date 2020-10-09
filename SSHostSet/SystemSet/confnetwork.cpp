#include "confnetwork.h"
#include "ui_confnetwork.h"
#include "SQLite/mysqlite.h"
#include "MsgBox/msgbox.h"
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
    //QRegExp regExpPort("^[5-9][0-9][0-9][0-9]$");
    //ui->lineEditPort_11->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_12->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_13->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_14->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_15->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_16->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_17->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_18->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_21->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_22->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_23->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_24->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_25->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_26->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_27->setValidator(new QRegExpValidator(regExpPort, this));
    //ui->lineEditPort_28->setValidator(new QRegExpValidator(regExpPort, this));
    QString desIP_1,desIP_2,desIP_3,desIP_4,hostIP_1,hostIP_2,hostIP_3,hostIP_4;

    m_lineEditList_1.append(ui->lineEditDesIP_1);
    m_lineEditList_1.append(ui->lineEditDesIP_2);
    m_lineEditList_1.append(ui->lineEditDesIP_3);
    m_lineEditList_1.append(ui->lineEditDesIP_4);
    m_lineEditList_1.append(ui->lineEditHostIP_1);
    m_lineEditList_1.append(ui->lineEditHostIP_2);
    m_lineEditList_1.append(ui->lineEditHostIP_3);
    m_lineEditList_1.append(ui->lineEditHostIP_4);
    m_lineEditList_1.append(ui->lineEditPort_11);
    m_lineEditList_1.append(ui->lineEditPort_12);
    m_lineEditList_1.append(ui->lineEditPort_13);
    m_lineEditList_1.append(ui->lineEditPort_14);
    m_lineEditList_1.append(ui->lineEditPort_15);
    m_lineEditList_1.append(ui->lineEditPort_15);
    m_lineEditList_1.append(ui->lineEditPort_16);
    m_lineEditList_1.append(ui->lineEditPort_17);
    m_lineEditList_1.append(ui->lineEditPort_18);


    m_lineEditList_2.append(ui->lineEditDesIP_5);
    m_lineEditList_2.append(ui->lineEditDesIP_6);
    m_lineEditList_2.append(ui->lineEditDesIP_7);
    m_lineEditList_2.append(ui->lineEditDesIP_8);
    m_lineEditList_2.append(ui->lineEditHostIP_5);
    m_lineEditList_2.append(ui->lineEditHostIP_6);
    m_lineEditList_2.append(ui->lineEditHostIP_7);
    m_lineEditList_2.append(ui->lineEditHostIP_8);
    m_lineEditList_2.append(ui->lineEditPort_21);
    m_lineEditList_2.append(ui->lineEditPort_22);
    m_lineEditList_2.append(ui->lineEditPort_23);
    m_lineEditList_2.append(ui->lineEditPort_24);
    m_lineEditList_2.append(ui->lineEditPort_25);
    m_lineEditList_2.append(ui->lineEditPort_25);
    m_lineEditList_2.append(ui->lineEditPort_26);
    m_lineEditList_2.append(ui->lineEditPort_27);
    m_lineEditList_2.append(ui->lineEditPort_28);

    //获取数据库IP地址
    QSqlDatabase db1 = MySQLite::openConnection();
    QStringList stringList_1 = MySQLite::getNetWorkIP(db1,1);
    MySQLite::closeConnection(db1);
    QString desIP1  = stringList_1.value(0);
    QString hostIP1 = stringList_1.value(1);
    QString port_11 = stringList_1.value(2);
    QString port_12 = stringList_1.value(3);
    QString port_13 = stringList_1.value(4);
    QString port_14 = stringList_1.value(5);
    QString port_15 = stringList_1.value(6);
    QString port_16 = stringList_1.value(7);
    QString port_17 = stringList_1.value(8);
    QString port_18 = stringList_1.value(9);
    QString able1   = stringList_1.value(10);
    ui->checkBox_1->setChecked(able1.toUInt());
    QString ipCmdStr_1 = QString("ifconfig eth0 %1").arg(hostIP1);
    QProcess procss_1;
    procss_1.execute(ipCmdStr_1);
    qDebug("******IFCONFIG ETH0**********");
    qDebug()<<"port_11 : "<<port_11;
    qDebug()<<"port_12 : "<<port_12;
    qDebug()<<"port_13 : "<<port_13;
    qDebug()<<"port_14 : "<<port_14;
    qDebug()<<"port_15 : "<<port_15;
    qDebug()<<"port_16 : "<<port_16;
    qDebug()<<"port_17 : "<<port_17;
    qDebug()<<"port_18 : "<<port_18;
    qDebug()<<"desIP1  : "<<desIP1;
    qDebug()<<"hostIP1 : "<<hostIP1;
    qDebug()<<"CmdStr_1: "<<ipCmdStr_1;
    parseStringIP(desIP1, desIP_1, desIP_2, desIP_3, desIP_4);
    parseStringIP(hostIP1,hostIP_1,hostIP_2,hostIP_3,hostIP_4);

    ui->lineEditPort_11->setText(port_11);
    ui->lineEditPort_12->setText(port_12);
    ui->lineEditPort_13->setText(port_13);
    ui->lineEditPort_14->setText(port_14);
    ui->lineEditPort_15->setText(port_15);
    ui->lineEditPort_16->setText(port_16);
    ui->lineEditPort_17->setText(port_17);
    ui->lineEditPort_18->setText(port_18);
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
    QString port_21 = stringList_1.value(2);
    QString port_22 = stringList_1.value(3);
    QString port_23 = stringList_1.value(4);
    QString port_24 = stringList_1.value(5);
    QString port_25 = stringList_1.value(6);
    QString port_26 = stringList_1.value(7);
    QString port_27 = stringList_1.value(8);
    QString port_28 = stringList_1.value(9);
    QString able2   = stringList_2.value(10);
    ui->checkBox_2->setChecked(able2.toUInt());
    QString ipCmdStr_2 = QString("ifconfig eth1 %1").arg(hostIP2);
    QProcess procss_2;
    procss_2.execute(ipCmdStr_2);
    qDebug("******IFCONFIG ETH1**********");
    qDebug()<<"port_21 : "<<port_21;
    qDebug()<<"port_22 : "<<port_22;
    qDebug()<<"port_23 : "<<port_23;
    qDebug()<<"port_24 : "<<port_24;
    qDebug()<<"port_25 : "<<port_25;
    qDebug()<<"port_26 : "<<port_26;
    qDebug()<<"port_27 : "<<port_27;
    qDebug()<<"port_28 : "<<port_28;
    qDebug()<<"desIP2  : "<<desIP2;
    qDebug()<<"hostIP2 : "<<hostIP2;
    qDebug()<<"CmdStr_2: "<<ipCmdStr_2;
    parseStringIP( desIP2, desIP_1, desIP_2, desIP_3, desIP_4);
    parseStringIP(hostIP2,hostIP_1,hostIP_2,hostIP_3,hostIP_4);
    ui->lineEditPort_21->setText(port_21);
    ui->lineEditPort_22->setText(port_22);
    ui->lineEditPort_23->setText(port_23);
    ui->lineEditPort_24->setText(port_24);
    ui->lineEditPort_25->setText(port_25);
    ui->lineEditPort_26->setText(port_26);
    ui->lineEditPort_27->setText(port_27);
    ui->lineEditPort_28->setText(port_28);
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

    QString portStr_1= lineEditList.value(8)->text();
    QString portStr_2= lineEditList.value(9)->text();
    QString portStr_3= lineEditList.value(10)->text();
    QString portStr_4= lineEditList.value(11)->text();
    QString portStr_5= lineEditList.value(12)->text();
    QString portStr_6= lineEditList.value(13)->text();
    QString portStr_7= lineEditList.value(14)->text();
    QString portStr_8= lineEditList.value(15)->text();

    if(portStr_1.isEmpty() || portStr_2.isEmpty() || portStr_3.isEmpty() || portStr_4.isEmpty() ||
            portStr_5.isEmpty() || portStr_6.isEmpty() || portStr_7.isEmpty() || portStr_8.isEmpty()) {
        MsgBox::showInformation(this,tr("操作提示"), tr("端口不能为空！"),tr("关闭"));
        return;
    }

    if(desIP_1.isEmpty() || desIP_2.isEmpty() || desIP_3.isEmpty() || desIP_4.isEmpty()) {
        MsgBox::showInformation(this,tr("操作提示"), tr("目标IP地址不能为空！"),tr("关闭"));
        return;
    }

    if(hostIP_1.isEmpty() || hostIP_2.isEmpty() || hostIP_3.isEmpty() || hostIP_4.isEmpty()) {
        MsgBox::showInformation(this,tr("操作提示"), tr("IP地址不能为空！"),tr("关闭"));
        return;
    }

    QString desIP = desIP_1 +"."+desIP_2 +"."+ desIP_3 +"."+ desIP_4;
    QString hostIP = hostIP_1 +"."+hostIP_2 +"."+ hostIP_3 +"."+ hostIP_4;
    QString ableStr = QString::number(able);
    QString netNumStr = QString::number(netNum);
    QSqlDatabase db = MySQLite::openConnection();
    if(MySQLite::setNetWorkIP(db,netNumStr,ableStr,desIP,hostIP,portStr_1,portStr_2,portStr_3,
                              portStr_4,portStr_5,portStr_6,portStr_7,portStr_8)) {
        MySQLite::closeConnection(db);
        MsgBox::showInformation(this,tr("操作提示"), tr("IP地址配置成功，重启后生效！"),tr("关闭"));
        return;
    } else {
        MySQLite::closeConnection(db);
        MsgBox::showInformation(this,tr("操作提示"), tr("IP地址配置失败！"),tr("关闭"));
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
