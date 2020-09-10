#include "systemconf.h"
#include "ui_systemconf.h"
#include "includes.h"

#define DATASIZE    22
SystemConf::SystemConf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemConf)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    initKey();
    initConnect();
}

SystemConf::~SystemConf()
{
    delete ui;
}

void SystemConf::initKey()
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

void SystemConf::initConnect()
{
    connect(ui->tBtnOk,SIGNAL(clicked(bool)),this,SLOT(slotBtnOk()));
    connect(ui->tBtnBack,SIGNAL(clicked(bool)),this,SLOT(slotBtnBack()));
}

void SystemConf::setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget)
{
    effect->setOffset(4, 4);
    effect->setColor(QColor(200, 200, 200));
    effect->setBlurRadius(6);
    widget->setGraphicsEffect(effect);
}

void SystemConf::slotBtnOk()
{
    QByteArray byteArray;
    SystemConfData(byteArray);
    if (byteArray.size() == DATASIZE) {
        emit sigSystemConfData(byteArray);
    }
    qDebug("**************************************************************");
    qDebug()<<"byteArray --->>> "<<byteArray;
    qDebug()<<"byteArray --->>> "<<byteArray.size();
}

void SystemConf::slotBtnBack()
{
    this->hide();
}

void SystemConf::slotBtnKey(int index)
{
    QString text = m_btnKeyGroup->button(index)->text();
    if (index == 10) {
        if (focusWidget()->inherits("QLineEdit")) {
            qobject_cast<QLineEdit*>(focusWidget())->clear();
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

void SystemConf::slotSystemConfData(QByteArray byteArray)
{
    uint cmd = byteArray.at(G_CMD);
    if (0x03 != cmd) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据命令错误！！！"),tr("关闭"));
        return;
    }

    uint len = byteArray.at(G_LEN);
    if (DATASIZE != len) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据长度错误！！！"),tr("关闭"));
        return;
    }

    uint p_1 = byteArray.at(G_P1_H);
    p_1 = (p_1 << 8) | byteArray.at(G_P1_L);
    ui->lineEditP_1->setText(QString::number(p_1));

    uint p_2 = byteArray.at(G_P2_H);
    p_2 = (p_2 << 8) | byteArray.at(G_P2_L);
    ui->lineEditP_2->setText(QString::number(p_2));

    uint rs_1 = byteArray.at(G_RS_1);


}

void SystemConf::SystemConfData(QByteArray &byteArray)
{
    //压力
    uint p_1 = ui->lineEditP_1->text().toUInt();
    if (1000 < p_1) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("最大压力1参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (p_1 >> 8) & 0xFF;
        uchar data_L = p_1 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    uint p_2 = ui->lineEditP_2->text().toUInt();
    if (1000 < p_2) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("最大压力2参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (p_2 >> 8) & 0xFF;
        uchar data_L = p_2 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    //上升速度
    uchar rs_1 = ui->lineEditRS_1->text().toUInt();
    if (0 == rs_1 || 8 < rs_1) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("上升速度-1参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(rs_1);
    }
    uchar rs_2 = ui->lineEditRS_2->text().toUInt();
    if (0 == rs_2 || 8 < rs_2) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("上升速度-2参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(rs_2);
    }
    uchar rs_3 = ui->lineEditRS_3->text().toUInt();
    if (0 == rs_3 || 8 < rs_3) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("上升速度-3参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(rs_3);
    }
    //上升时间
    uint rt_1 = ui->lineEditRT_1->text().toUInt();
    if (30000 < rt_1) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("上升时间-1参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (rt_1 >> 8) & 0xFF;
        uchar data_L = rt_1 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    uint rt_2 = ui->lineEditRT_2->text().toUInt();
    if (3000 < rt_2) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("上升时间-2参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (rt_2 >> 8) & 0xFF;
        uchar data_L = rt_2 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    uint rt_3 = ui->lineEditRT_2->text().toUInt();
    if (3000 < rt_3) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("上升时间-3参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (rt_3 >> 8) & 0xFF;
        uchar data_L = rt_3 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    //下降速度
    uchar ds_1 = ui->lineEditDS_1->text().toUInt();
    if (0 == ds_1 || 8 < ds_1) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("下降速度-1参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(ds_1);
    }
    uchar ds_2 = ui->lineEditRS_2->text().toUInt();
    if (0 == ds_2 || 8 < ds_2) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("下降速度-2参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append((uchar)ds_2);
    }
    uchar ds_3 = ui->lineEditRS_3->text().toUInt();
    if (0 == ds_3 || 8 < ds_3) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("下降速度-3参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append((uchar)ds_3);
    }
    //下降时间
    uint dt_1 = ui->lineEditRT_1->text().toUInt();
    if (30000 < dt_1) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("下降时间-1参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (dt_1 >> 8) & 0xFF;
        uchar data_L = dt_1 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    uint dt_2 = ui->lineEditRT_2->text().toUInt();
    if (3000 < dt_2) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("下降时间-2参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (dt_2 >> 8) & 0xFF;
        uchar data_L = dt_2 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    uint dt_3 = ui->lineEditRT_2->text().toUInt();
    if (3000 < dt_3) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("下降时间-3参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (dt_3 >> 8) & 0xFF;
        uchar data_L = dt_3 & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
}

