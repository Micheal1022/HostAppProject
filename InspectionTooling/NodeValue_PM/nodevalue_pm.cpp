#include "nodevalue_pm.h"
#include "ui_nodevalue_pm.h"
#include "includes.h"
#include <QDebug>
#define MAX 1.04
#define MIN 0.96
NodeValue_PM::NodeValue_PM(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NodeValue_PM)
{
    ui->setupUi(this);
    m_labelList.append(ui->lb_result_1);
    m_labelList.append(ui->lb_result_2);
    m_labelList.append(ui->lb_result_3);
    m_labelList.append(ui->lb_result_4);
    m_labelList.append(ui->lb_result_5);
    m_labelList.append(ui->lb_result_6);
    m_labelList.append(ui->lb_result_7);
    m_labelList.append(ui->lb_result_8);
    m_labelList.append(ui->lb_result_9);
    cleanValue();
}

NodeValue_PM::~NodeValue_PM()
{
    delete ui;
}

void NodeValue_PM::updateValue(QList<int> valueList)
{

    int nodeType  = valueList.value(TYPE);
    int nodeState = valueList.value(STATE);
    int nodeAddr  = valueList.value(CANID);
    int nodeValue1= valueList.value(VALUE_1);
    int nodeValue2= valueList.value(VALUE_2);
    int nodeValue3= valueList.value(VALUE_3);
    int nodePass  = valueList.value(PASS);
    if (nodeValue1 == 0 && nodeValue2 == 0 && nodeValue3 == 0) {
        return;
    }
    if (nodeValue1 >= 0x2710 || nodeValue2 >= 0x2710 || nodeValue3 >= 0x2710) {
        return;
    }
    ui->lbAddr->setText(QString::number(nodeAddr));
    confNodeType(nodeType);
    confNodeState(nodeState);
    confNodeValue(nodePass,nodeType,nodeValue1,nodeValue2,nodeValue3);


}

void NodeValue_PM::initWidget(int loopNum, int type)
{
    m_curLoopNum = loopNum;
    if (MOD_2VA == type) {
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-Ua:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("1-Ub:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("1-Uc:"));
        ui->lb_2Ua->show();     ui->lb_2Ua->setText(tr("2-Ua:"));
        ui->lb_2Ub->show();     ui->lb_2Ub->setText(tr("2-Ub:"));
        ui->lb_2Uc->show();     ui->lb_2Uc->setText(tr("2-Uc:"));
        ui->lb_1Ia->show();     ui->lb_1Ia->setText(tr("1-Ia:"));   ui->lb_1IaUnit->setText(tr("A"));
        ui->lb_1Ib->show();     ui->lb_1Ib->setText(tr("1-Ib:"));   ui->lb_1IbUnit->setText(tr("A"));
        ui->lb_1Ic->show();     ui->lb_1Ic->setText(tr("1-Ic:"));   ui->lb_1IcUnit->setText(tr("A"));
    } else if (MOD_3V == type) {
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-Ua:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("1-Ub:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("1-Uc:"));
        ui->lb_2Ua->show();     ui->lb_2Ua->setText(tr("2-Ua:"));
        ui->lb_2Ub->show();     ui->lb_2Ub->setText(tr("2-Ub:"));
        ui->lb_2Uc->show();     ui->lb_2Uc->setText(tr("2-Uc:"));
        ui->lb_1Ia->show();     ui->lb_1Ia->setText(tr("3-Ua:"));   ui->lb_1IaUnit->setText(tr("V"));
        ui->lb_1Ib->show();     ui->lb_1Ib->setText(tr("3-Ub:"));   ui->lb_1IbUnit->setText(tr("V"));
        ui->lb_1Ic->show();     ui->lb_1Ic->setText(tr("3-Uc:"));   ui->lb_1IcUnit->setText(tr("V"));
    } else if (MOD_6V3A == type) {
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-U:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("2-U:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("3-U:"));
        ui->lb_2Ua->show();     ui->lb_2Ua->setText(tr("4-U:"));
        ui->lb_2Ub->show();     ui->lb_2Ub->setText(tr("5-U:"));
        ui->lb_2Uc->show();     ui->lb_2Uc->setText(tr("6-U:"));
        ui->lb_1Ia->show();     ui->lb_1Ia->setText(tr("1-I:"));    ui->lb_1IaUnit->setText(tr("A"));
        ui->lb_1Ib->show();     ui->lb_1Ib->setText(tr("2-I:"));    ui->lb_1IbUnit->setText(tr("A"));
        ui->lb_1Ic->show();     ui->lb_1Ic->setText(tr("3-I:"));    ui->lb_1IcUnit->setText(tr("A"));
    }

}

void NodeValue_PM::cleanValue()
{

    m_testTimes = 0;
    m_testVolFlag_01 = true;
    m_testVolFlag_02 = true;
    m_testVolFlag_03 = true;
    m_testVolFlag_04 = true;
    m_testVolFlag_05 = true;
    m_testVolFlag_06 = true;
    m_testVolFlag_07 = true;
    m_testVolFlag_08 = true;
    m_testVolFlag_09 = true;
    m_testCurFlag_01 = true;
    m_testCurFlag_02 = true;
    m_testCurFlag_03 = true;
    m_testCurTimes_01 = 0;
    m_testCurTimes_02 = 0;
    m_testCurTimes_03 = 0;
    m_testVolTimes_01 = 0;
    m_testVolTimes_02 = 0;
    m_testVolTimes_03 = 0;
    m_testVolTimes_04 = 0;
    m_testVolTimes_05 = 0;
    m_testVolTimes_06 = 0;
    m_testVolTimes_07 = 0;
    m_testVolTimes_08 = 0;
    m_testVolTimes_09 = 0;
    m_baseCurValue = 50;
    m_baseVolValue = 2200;
    ui->lcd_1Ua->display(0);
    ui->lcd_1Ub->display(0);
    ui->lcd_1Uc->display(0);
    ui->lcd_2Ua->display(0);
    ui->lcd_2Ub->display(0);
    ui->lcd_2Uc->display(0);
    ui->lcd_1Ia->display(0);
    ui->lcd_1Ib->display(0);
    ui->lcd_1Ic->display(0);
    ui->lbAddr->clear();
    ui->lbTypeValue->clear();
    ui->lbStateValue->clear();
    for (int index = 0; index < m_labelList.count(); index++) {
        m_labelList[index]->setText(tr("待测"));
        m_labelList[index]->setStyleSheet("color: rgb(255, 255, 255);");
    }
}

void NodeValue_PM::confResult(int index,NodeValue_PM::RESULT type)
{
    if (NodeValue_PM::Qualified == type) {
        m_labelList[index-1]->setText(tr("合格"));
        m_labelList[index-1]->setStyleSheet("color: rgb(0, 255, 0);");
    } else if (NodeValue_PM::Unqualified == type) {
        m_labelList[index-1]->setText(tr("不合格"));
        m_labelList[index-1]->setStyleSheet("color: rgb(255, 0, 0);");
    } else {
        m_labelList[index-1]->setText(tr("待测"));
        m_labelList[index-1]->setStyleSheet("color: rgb(255, 255, 255);");
    }
}

void NodeValue_PM::confNodeType(int nodeType)
{
    switch (nodeType) {
    case MOD_2VA:
        ui->lbTypeValue->setText("2VA");
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-Ua:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("1-Ub:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("1-Uc:"));
        ui->lb_2Ua->show();     ui->lb_2Ua->setText(tr("2-Ua:"));
        ui->lb_2Ub->show();     ui->lb_2Ub->setText(tr("2-Ub:"));
        ui->lb_2Uc->show();     ui->lb_2Uc->setText(tr("2-Uc:"));
        ui->lb_1Ia->show();     ui->lb_1Ia->setText(tr("1-Ia:"));
        ui->lb_1Ib->show();     ui->lb_1Ib->setText(tr("1-Ib:"));
        ui->lb_1Ic->show();     ui->lb_1Ic->setText(tr("1-Ic:"));
        break;
    case MOD_VA:
        ui->lbTypeValue->setText("VA");
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-Ua:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("1-Ub:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("1-Uc:"));
        ui->lb_2Ua->hide();     ui->lb_2Ua->setText(tr("2-Ua:"));
        ui->lb_2Ub->hide();     ui->lb_2Ub->setText(tr("2-Ub:"));
        ui->lb_2Uc->hide();     ui->lb_2Uc->setText(tr("2-Uc:"));
        ui->lb_1Ia->show();     ui->lb_1Ia->setText(tr("1-Ia:"));
        ui->lb_1Ib->show();     ui->lb_1Ib->setText(tr("1-Ib:"));
        ui->lb_1Ic->show();     ui->lb_1Ic->setText(tr("1-Ic:"));
        break;
    case MOD_3V:
        ui->lbTypeValue->setText("3V");
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-Ua:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("1-Ub:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("1-Uc:"));
        ui->lb_2Ua->show();     ui->lb_2Ua->setText(tr("2-Ua:"));
        ui->lb_2Ub->show();     ui->lb_2Ub->setText(tr("2-Ub:"));
        ui->lb_2Uc->show();     ui->lb_2Uc->setText(tr("2-Uc:"));
        ui->lb_1Ia->show();     ui->lb_1Ia->setText(tr("3-Ua:"));
        ui->lb_1Ib->show();     ui->lb_1Ib->setText(tr("3-Ub:"));
        ui->lb_1Ic->show();     ui->lb_1Ic->setText(tr("3-Uc:"));
        break;
    case MOD_2V:
        ui->lbTypeValue->setText("2V");
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-Ua:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("1-Ub:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("1-Uc:"));
        ui->lb_2Ua->show();     ui->lb_2Ua->setText(tr("2-Ua:"));
        ui->lb_2Ub->show();     ui->lb_2Ub->setText(tr("2-Ub:"));
        ui->lb_2Uc->show();     ui->lb_2Uc->setText(tr("2-Uc:"));
        ui->lb_1Ia->hide();     ui->lb_1Ia->setText(tr("1-Ia:"));
        ui->lb_1Ib->hide();     ui->lb_1Ib->setText(tr("1-Ib:"));
        ui->lb_1Ic->hide();     ui->lb_1Ic->setText(tr("1-Ic:"));
        break;
    case MOD_V:
        ui->lbTypeValue->setText("V");
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-Ua:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("1-Ub:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("1-Uc:"));
        ui->lb_2Ua->hide();     ui->lb_2Ua->setText(tr("2-Ua:"));
        ui->lb_2Ub->hide();     ui->lb_2Ub->setText(tr("2-Ub:"));
        ui->lb_2Uc->hide();     ui->lb_2Uc->setText(tr("2-Uc:"));
        ui->lb_1Ia->hide();     ui->lb_1Ia->setText(tr("1-Ia:"));
        ui->lb_1Ib->hide();     ui->lb_1Ib->setText(tr("1-Ib:"));
        ui->lb_1Ic->hide();     ui->lb_1Ic->setText(tr("1-Ic:"));
        break;
    case MOD_6V3A:
        ui->lbTypeValue->setText("6V3A");
        ui->lb_1Ua->show();     ui->lb_1Ua->setText(tr("1-U:"));
        ui->lb_1Ub->show();     ui->lb_1Ub->setText(tr("2-U:"));
        ui->lb_1Uc->show();     ui->lb_1Uc->setText(tr("3-U:"));
        ui->lb_2Ua->show();     ui->lb_2Ua->setText(tr("4-U:"));
        ui->lb_2Ub->show();     ui->lb_2Ub->setText(tr("5-U:"));
        ui->lb_2Uc->show();     ui->lb_2Uc->setText(tr("6-U:"));
        ui->lb_1Ia->show();     ui->lb_1Ia->setText(tr("1-I:"));    ui->lb_1IaUnit->setText(tr("V"));
        ui->lb_1Ib->show();     ui->lb_1Ib->setText(tr("2-I:"));    ui->lb_1IbUnit->setText(tr("V"));
        ui->lb_1Ic->show();     ui->lb_1Ic->setText(tr("3-I:"));    ui->lb_1IcUnit->setText(tr("V"));
        break;
    }
}

void NodeValue_PM::confNodeValue(int pass, int nodeType, int nodeValue1, int nodeValue2, int nodeValue3)
{
    QString value1Str,value2Str,value3Str;

    switch (nodeType) {
    case MOD_2VA:
        if (pass == 1) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_1Ua->display(value1Str);
            if (m_testVolFlag_01 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_01++;
                    if ( m_testVolTimes_01 == TIMENUM ) {
                        m_testVolTimes_01 = 0;
                        m_testVolFlag_01 = false;
                        confResult(1,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_01 = false;
                    confResult(1,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_1Ub->display(value2Str);
            if (m_testVolFlag_02 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_02++;
                    if ( m_testVolTimes_02 == TIMENUM ) {
                        m_testVolTimes_02 = 0;
                        m_testVolFlag_02 = false;
                        confResult(2,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_02 = false;
                    confResult(2,NodeValue_PM::Unqualified);
                }

            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_1Uc->display(value3Str);
            if (m_testVolFlag_03 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_03++;
                    if ( m_testVolTimes_03 == TIMENUM ) {
                        m_testVolTimes_03 = 0;
                        m_testVolFlag_03 = false;
                        confResult(3,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_03 = false;
                    confResult(3,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 2) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_2Ua->display(value1Str);
            if (m_testVolFlag_04 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_04++;
                    if ( m_testVolTimes_04 == TIMENUM ) {
                        m_testVolTimes_04 = 0;
                        m_testVolFlag_04 = false;
                        confResult(4,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_04 = false;
                    confResult(4,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_2Ub->display(value2Str);
            if (m_testVolFlag_05 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_05++;
                    if ( m_testVolTimes_05 == TIMENUM ) {
                        m_testVolTimes_05 = 0;
                        m_testVolFlag_05 = false;
                        confResult(5,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_05 = false;
                    confResult(5,NodeValue_PM::Unqualified);
                }
            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_2Uc->display(value3Str);
            if (m_testVolFlag_06 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_06++;
                    if ( m_testVolTimes_06 == TIMENUM ) {
                        m_testVolTimes_06 = 0;
                        m_testVolFlag_06 = false;
                        confResult(6,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_06 = false;
                    confResult(6,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 3) {
            value1Str = QString::number(nodeValue1/10) +"."+ QString::number(nodeValue1%10);    ui->lcd_1Ia->display(value1Str);
            if (m_testCurFlag_01 == true) {
                if (nodeValue1 <= m_baseCurValue*MAX && nodeValue1 >= m_baseCurValue*MIN) {
                    m_testCurTimes_01++;
                    if (m_testCurTimes_01 == TIMENUM ) {
                        m_testCurTimes_01 = 0;
                        m_testCurFlag_01 = false;
                        confResult(7,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_01 = false;
                    confResult(7,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10) +"."+ QString::number(nodeValue2%10);    ui->lcd_1Ib->display(value2Str);
            if (m_testCurFlag_02 == true) {
                if (nodeValue2 <= m_baseCurValue*MAX && nodeValue2 >= m_baseCurValue*MIN) {
                    m_testCurTimes_02++;
                    if (m_testCurTimes_02 == TIMENUM ) {
                        m_testCurTimes_02 = 0;
                        m_testCurFlag_02 = false;
                        confResult(8,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_02 = false;
                    confResult(8,NodeValue_PM::Unqualified);
                }
            }

            value3Str = QString::number(nodeValue3/10) +"."+ QString::number(nodeValue3%10);    ui->lcd_1Ic->display(value3Str);
            if (m_testCurFlag_03 == true) {
                if (nodeValue3 <= m_baseCurValue*MAX && nodeValue3 >= m_baseCurValue*MIN) {
                    m_testCurTimes_03++;
                    if (m_testCurTimes_03 == TIMENUM ) {
                        m_testCurTimes_03 = 0;
                        m_testCurFlag_03 = false;
                        confResult(9,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_03 = false;
                    confResult(9,NodeValue_PM::Unqualified);
                }
            }
        }
        break;
    case MOD_VA:
        if (pass == 1) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_1Ua->display(value1Str);
            if (m_testVolFlag_01 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_01++;
                    if ( m_testVolTimes_01 == TIMENUM ) {
                        m_testVolTimes_01 = 0;
                        m_testVolFlag_01 = false;
                        confResult(1,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_01 = false;
                    confResult(1,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_1Ub->display(value2Str);
            if (m_testVolFlag_02 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_02++;
                    if ( m_testVolTimes_02 == TIMENUM ) {
                        m_testVolTimes_02 = 0;
                        m_testVolFlag_02 = false;
                        confResult(2,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_02 = false;
                    confResult(2,NodeValue_PM::Unqualified);
                }

            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_1Uc->display(value3Str);
            if (m_testVolFlag_03 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_03++;
                    if ( m_testVolTimes_03 == TIMENUM ) {
                        m_testVolTimes_03 = 0;
                        m_testVolFlag_03 = false;
                        confResult(3,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_03 = false;
                    confResult(3,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 3) {
            value1Str = QString::number(nodeValue1/10) +"."+ QString::number(nodeValue1%10);
            ui->lcd_1Ia->display(value1Str);
            ui->lcd_1Ib->display(value2Str);
            ui->lcd_1Ic->display(value3Str);
            if (m_testCurFlag_01 == true) {
                if (nodeValue1 <= m_baseCurValue*MAX && nodeValue1 >= m_baseCurValue*MIN) {
                    m_testCurTimes_01++;
                    if (m_testCurTimes_01 == TIMENUM ) {
                        m_testCurTimes_01 = 0;
                        m_testCurFlag_01 = false;
                        confResult(7,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_01 = false;
                    confResult(7,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10) +"."+ QString::number(nodeValue2%10);
            if (m_testCurFlag_02 == true) {
                if (nodeValue2 <= m_baseCurValue*MAX && nodeValue2 >= m_baseCurValue*MIN) {
                    m_testCurTimes_02++;
                    if (m_testCurTimes_02 == TIMENUM ) {
                        m_testCurTimes_02 = 0;
                        m_testCurFlag_02 = false;
                        confResult(8,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_01 = false;
                    confResult(8,NodeValue_PM::Unqualified);
                }
            }

            value3Str = QString::number(nodeValue3/10) +"."+ QString::number(nodeValue3%10);
            if (m_testCurFlag_03 == true) {
                if (nodeValue3 <= m_baseCurValue*MAX && nodeValue3 >= m_baseCurValue*MIN) {
                    m_testCurTimes_01++;
                    if (m_testCurTimes_03 == TIMENUM ) {
                        m_testCurTimes_03 = 0;
                        m_testCurFlag_03 = false;
                        confResult(9,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_03 = false;
                    confResult(9,NodeValue_PM::Unqualified);
                }
            }
        }
        break;
    case MOD_3V:
        if (pass == 1) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_1Ua->display(value1Str);
            if (m_testVolFlag_01 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_01++;
                    if ( m_testVolTimes_01 == TIMENUM ) {
                        m_testVolTimes_01 = 0;
                        m_testVolFlag_01 = false;
                        confResult(1,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_01 = false;
                    confResult(1,NodeValue_PM::Unqualified);
                }
            }
            value2Str = QString::number(nodeValue2/10);     ui->lcd_1Ub->display(value2Str);
            if (m_testVolFlag_02 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_02++;
                    if ( m_testVolTimes_02 == TIMENUM ) {
                        m_testVolTimes_02 = 0;
                        m_testVolFlag_02 = false;
                        confResult(2,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_02 = false;
                    confResult(2,NodeValue_PM::Unqualified);
                }

            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_1Uc->display(value3Str);
            if (m_testVolFlag_03 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_03++;
                    if ( m_testVolTimes_03 == TIMENUM ) {
                        m_testVolTimes_03 = 0;
                        m_testVolFlag_03 = false;
                        confResult(3,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_03 = false;
                    confResult(3,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 2) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_2Ua->display(value1Str);
            if (m_testVolFlag_04 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_04++;
                    if ( m_testVolTimes_04 == TIMENUM ) {
                        m_testVolTimes_04 = 0;
                        m_testVolFlag_04 = false;
                        confResult(4,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_04 = false;
                    confResult(4,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_2Ub->display(value2Str);
            if (m_testVolFlag_05 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_05++;
                    if ( m_testVolTimes_05 == TIMENUM ) {
                        m_testVolTimes_05 = 0;
                        m_testVolFlag_05 = false;
                        confResult(5,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_05 = false;
                    confResult(5,NodeValue_PM::Unqualified);
                }
            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_2Uc->display(value3Str);
            if (m_testVolFlag_06 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_06++;
                    if ( m_testVolTimes_06 == TIMENUM ) {
                        m_testVolTimes_06 = 0;
                        m_testVolFlag_06 = false;
                        confResult(6,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_06 = false;
                    confResult(6,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 3) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_1Ia->display(value1Str);
            if (m_testVolFlag_07 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_07++;
                    if ( m_testVolTimes_07 == TIMENUM ) {
                        m_testVolTimes_07 = 0;
                        m_testVolFlag_07 = false;
                        confResult(1,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_07 = false;
                    confResult(1,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_1Ib->display(value2Str);
            if (m_testVolFlag_08 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_08++;
                    if ( m_testVolTimes_08 == TIMENUM ) {
                        m_testVolTimes_08 = 0;
                        m_testVolFlag_08 = false;
                        confResult(8,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_08 = false;
                    confResult(8,NodeValue_PM::Unqualified);
                }
            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_1Ic->display(value3Str);
            if (m_testVolFlag_09 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_09++;
                    if ( m_testVolTimes_09 == TIMENUM ) {
                        m_testVolTimes_09 = 0;
                        m_testVolFlag_09 = false;
                        confResult(9,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_09 = false;
                    confResult(9,NodeValue_PM::Unqualified);
                }
            }
        }
        break;
    case MOD_2V:
        if (pass == 1) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_1Ua->display(value1Str);
            if (m_testVolFlag_01 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_01++;
                    if ( m_testVolTimes_01 == TIMENUM ) {
                        m_testVolTimes_01 = 0;
                        m_testVolFlag_01 = false;
                        confResult(1,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_01 = false;
                    confResult(1,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_1Ub->display(value2Str);
            if (m_testVolFlag_02 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_02++;
                    if ( m_testVolTimes_02 == TIMENUM ) {
                        m_testVolTimes_02 = 0;
                        m_testVolFlag_02 = false;
                        confResult(2,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_02 = false;
                    confResult(2,NodeValue_PM::Unqualified);
                }

            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_1Uc->display(value3Str);
            if (m_testVolFlag_03 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_03++;
                    if ( m_testVolTimes_03 == TIMENUM ) {
                        m_testVolTimes_03 = 0;
                        m_testVolFlag_03 = false;
                        confResult(3,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_03 = false;
                    confResult(3,NodeValue_PM::Unqualified);
                }
            }

        }
        if (pass == 2) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_2Ua->display(value1Str);
            if (m_testVolFlag_04 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_04++;
                    if ( m_testVolTimes_04 == TIMENUM ) {
                        m_testVolTimes_04 = 0;
                        m_testVolFlag_04 = false;
                        confResult(4,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_04 = false;
                    confResult(4,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_2Ub->display(value2Str);
            if (m_testVolFlag_05 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_05++;
                    if ( m_testVolTimes_05 == TIMENUM ) {
                        m_testVolTimes_05 = 0;
                        m_testVolFlag_05 = false;
                        confResult(5,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_05 = false;
                    confResult(5,NodeValue_PM::Unqualified);
                }
            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_2Uc->display(value3Str);
            if (m_testVolFlag_06 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_06++;
                    if ( m_testVolTimes_06 == TIMENUM ) {
                        m_testVolTimes_06 = 0;
                        m_testVolFlag_06 = false;
                        confResult(6,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_06 = false;
                    confResult(6,NodeValue_PM::Unqualified);
                }
            }
        }
        break;
    case MOD_V:
        if (pass == 1) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_1Ua->display(value1Str);
            if (m_testVolFlag_01 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_01++;
                    if ( m_testVolTimes_01 == TIMENUM ) {
                        m_testVolTimes_01 = 0;
                        m_testVolFlag_01 = false;
                        confResult(1,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_01 = false;
                    confResult(1,NodeValue_PM::Unqualified);
                }
            }

            value2Str = QString::number(nodeValue2/10);     ui->lcd_1Ub->display(value2Str);
            if (m_testVolFlag_02 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_02++;
                    if ( m_testVolTimes_02 == TIMENUM ) {
                        m_testVolTimes_02 = 0;
                        m_testVolFlag_02 = false;
                        confResult(2,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_02 = false;
                    confResult(2,NodeValue_PM::Unqualified);
                }

            }

            value3Str = QString::number(nodeValue3/10);     ui->lcd_1Uc->display(value3Str);
            if (m_testVolFlag_03 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_03++;
                    if ( m_testVolTimes_03 == TIMENUM ) {
                        m_testVolTimes_03 = 0;
                        m_testVolFlag_03 = false;
                        confResult(3,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_03 = false;
                    confResult(3,NodeValue_PM::Unqualified);
                }
            }
        }
        break;
    case MOD_6V3A:
        if (pass == 1) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_1Ua->display(value1Str);
            if (m_testVolFlag_01 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_01++;
                    if ( m_testVolTimes_01 == TIMENUM ) {
                        m_testVolTimes_01 = 0;
                        m_testVolFlag_01 = false;
                        confResult(1,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_01 = false;
                    confResult(1,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 2) {
            value2Str = QString::number(nodeValue2/10);     ui->lcd_1Ub->display(value2Str);
            if (m_testVolFlag_02 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_02++;
                    if ( m_testVolTimes_02 == TIMENUM ) {
                        m_testVolTimes_02 = 0;
                        m_testVolFlag_02 = false;
                        confResult(2,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_02 = false;
                    confResult(2,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 3) {
            value3Str = QString::number(nodeValue3/10);     ui->lcd_1Uc->display(value3Str);
            if (m_testVolFlag_03 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_03++;
                    if ( m_testVolTimes_03 == TIMENUM ) {
                        m_testVolTimes_03 = 0;
                        m_testVolFlag_03 = false;
                        confResult(3,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_03 = false;
                    confResult(3,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 4) {
            value1Str = QString::number(nodeValue1/10);     ui->lcd_2Ua->display(value1Str);
            if (m_testVolFlag_04 == true) {
                if (nodeValue1 <= m_baseVolValue*MAX && nodeValue1 >= m_baseVolValue*MIN) {
                    m_testVolTimes_04++;
                    if ( m_testVolTimes_04 == TIMENUM ) {
                        m_testVolTimes_04 = 0;
                        m_testVolFlag_04 = false;
                        confResult(4,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_04 = false;
                    confResult(4,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 5) {
            value2Str = QString::number(nodeValue2/10);     ui->lcd_2Ub->display(value2Str);
            if (m_testVolFlag_05 == true) {
                if (nodeValue2 <= m_baseVolValue*MAX && nodeValue2 >= m_baseVolValue*MIN) {
                    m_testVolTimes_05++;
                    if ( m_testVolTimes_05 == TIMENUM ) {
                        m_testVolTimes_05 = 0;
                        m_testVolFlag_05 = false;
                        confResult(5,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_05 = false;
                    confResult(5,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 6) {
            value3Str = QString::number(nodeValue3/10);     ui->lcd_2Uc->display(value3Str);
            if (m_testVolFlag_06 == true) {
                if (nodeValue3 <= m_baseVolValue*MAX && nodeValue3 >= m_baseVolValue*MIN) {
                    m_testVolTimes_06++;
                    if ( m_testVolTimes_06 == TIMENUM ) {
                        m_testVolTimes_06 = 0;
                        m_testVolFlag_06 = false;
                        confResult(6,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testVolFlag_06 = false;
                    confResult(6,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 7) {
            value1Str = QString::number(nodeValue1/10) +"."+ QString::number(nodeValue1%10);    ui->lcd_1Ia->display(value1Str);
            if (m_testCurFlag_01 == true) {
                if (nodeValue1 <= m_baseCurValue*MAX && nodeValue1 >= m_baseCurValue*MIN) {
                    m_testCurTimes_01++;
                    if (m_testCurTimes_01 == TIMENUM ) {
                        m_testCurTimes_01 = 0;
                        m_testCurFlag_01 = false;
                        confResult(7,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_01 = false;
                    confResult(7,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 8) {
            value2Str = QString::number(nodeValue2/10) +"."+ QString::number(nodeValue2%10);    ui->lcd_1Ib->display(value2Str);
            if (m_testCurFlag_02 == true) {
                if (nodeValue2 <= m_baseCurValue*MAX && nodeValue2 >= m_baseCurValue*MIN) {
                    m_testCurTimes_02++;
                    if (m_testCurTimes_02 == TIMENUM ) {
                        m_testCurTimes_02 = 0;
                        m_testCurFlag_02 = false;
                        confResult(8,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_01 = false;
                    confResult(8,NodeValue_PM::Unqualified);
                }
            }
        }
        if (pass == 9) {
            value3Str = QString::number(nodeValue3/10) +"."+ QString::number(nodeValue3%10);    ui->lcd_1Ic->display(value3Str);
            if (m_testCurFlag_03 == true) {
                if (nodeValue3 <= m_baseCurValue*MAX && nodeValue3 >= m_baseCurValue*MIN) {
                    m_testCurTimes_01++;
                    if (m_testCurTimes_03 == TIMENUM ) {
                        m_testCurTimes_03 = 0;
                        m_testCurFlag_03 = false;
                        confResult(9,NodeValue_PM::Qualified);
                    }
                } else {
                    m_testCurFlag_03 = false;
                    confResult(9,NodeValue_PM::Unqualified);
                }
            }
        }
        break;
    }
}


void NodeValue_PM::slotCleanValue()
{
    cleanValue();
}

void NodeValue_PM::slotUpdateValue(QList<int> valueList)
{
    updateValue(valueList);
}

void NodeValue_PM::confNodeState(int nodeState)
{
    switch (nodeState) {
    case N_NORMAL:
        ui->lbStateValue->setText(tr("正常"));
        break;
    case N_POWERLOST:
        ui->lbStateValue->setText(tr("中断"));
        break;
    case N_OVERVOL:
        ui->lbStateValue->setText(tr("过压"));
        break;
    case N_OVERCUR:
        ui->lbStateValue->setText(tr("过流"));
        break;
    case N_LACKVOL:
        ui->lbStateValue->setText(tr("欠压"));
        break;
    case N_LACKPHA:
        ui->lbStateValue->setText(tr("缺相"));
        break;
    case N_OFFLINE:
        ui->lbStateValue->setText(tr("离线"));
        break;
    }
}
