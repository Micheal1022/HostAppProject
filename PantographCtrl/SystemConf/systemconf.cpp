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
    if (GETCONF != cmd) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据命令错误！！！"),tr("关闭"));
        return;
    }

    uint len = byteArray.at(G_LEN);
    if (DATASIZE != len) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("数据长度错误！！！"),tr("关闭"));
        return;
    }

    uint mode = byteArray.at(G_MODE);
    switch (mode) {
    case AUTOMODE:
        ui->rBtnAutoMode->setChecked(true);
        break;
    case MANUALMODE:
        ui->rBtnManualMode->setChecked(true);
        break;
    case REPAIRMODE:
        ui->rBtnRepairMode->setChecked(true);
        break;
    }

    uint p_1 = byteArray.at(G_PH);
    p_1 = (p_1 << 8) | byteArray.at(G_PL);
    ui->lineEditP_1->setText(QString::number(p_1));
    uint ls = byteArray.at(G_LS);
    ui->lineEditLS->setText(QString::number(ls));
    uint ms = byteArray.at(G_MS);
    ui->lineEditMS->setText(QString::number(ms));
    uint hs = byteArray.at(G_HS);
    ui->lineEditHS->setText(QString::number(hs));
    uint mt = byteArray.at(G_MT);
    ui->lineEditMT->setText(QString::number(mt));
    uint st = byteArray.at(G_ST);
    ui->lineEditST->setText(QString::number(st));
    uint rt = byteArray.at(G_RT);
    ui->lineEditRT->setText(QString::number(rt));

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
    //低速档位
    uchar ls_1 = ui->lineEditLS->text().toUInt();
    if (0 == ls_1 || 3 < ls_1) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("低速档位参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(ls_1);
    }
    //中速档位
    uchar ms_2 = ui->lineEditMS->text().toUInt();
    if (3 > ms_2 || 5 < ms_2) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("中速档位参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(ms_2);
    }
    //高速档位
    uchar hs_3 = ui->lineEditHS->text().toUInt();
    if (5 > hs_3 || 7 < hs_3) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("高速档位参数错误！！！"),tr("关闭"));
        return;
    } else {
        byteArray.append(hs_3);
    }
    //手动时间2-6
    uint mt = ui->lineEditMT->text().toUInt();
    if (2 > mt || 6 < mt) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("手动时间参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (mt >> 8) & 0xFF;
        uchar data_L = mt & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    //起停时间1-5
    uint st = ui->lineEditST->text().toUInt();
    if (1 > mt || 5 < mt) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("起停时间参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (st >> 8) & 0xFF;
        uchar data_L = st & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }
    //运行时间5-8
    uint rt = ui->lineEditRT->text().toUInt();
    if (5 > mt || 8 < mt) {
        MsgBox::showInformation(NULL,tr("错误提示"),tr("运行时间参数错误！！！"),tr("关闭"));
        return;
    } else {
        uchar data_H = (rt >> 8) & 0xFF;
        uchar data_L = rt & 0xFF;
        byteArray.append(data_H);
        byteArray.append(data_L);
    }

}

