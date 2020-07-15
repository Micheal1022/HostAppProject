#include "screen.h"
#include "ui_screen.h"
#include <QTimer>
#include <QDebug>

#define RED    1
#define YELLOW 1
#define BLUE   2
#define GREEN  3
#define WHITE  4
#define END    5

#define TIME 1000

Screen::Screen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Screen)
{
    ui->setupUi(this);
    setGeometry(0,0,1024,600);
    setWindowFlags(Qt::FramelessWindowHint);
    m_colorTimer = new QTimer;
    connect(m_colorTimer,SIGNAL(timeout()),this,SLOT(slotTimeOut()));
    ui-> lbColor->setStyleSheet(QString("background-color: rgb(255, 0,   0)"));
}

Screen::~Screen()
{
    delete ui;
}
/*
* @项目   TBus_SSEF
* @函数
* @描述   开始自检
* @作者   Micheal(陈明明)
* @时间   2019-04-25
*/
void Screen::startScreen()
{
    show();
    m_index = 0;
    m_colorTimer->start(TIME);
}
/*
* @项目   TBus_SSEF
* @函数   void setColor(int num);
* @描述   设置自检屏幕颜色
* @作者   Micheal(陈明明)
* @时间   2019-04-25
*/
void Screen::setColor(int num)
{
    //红、黄、蓝、绿、白
    switch (num) {
    case YELLOW:
        ui-> lbColor->setStyleSheet(QString("background-color: rgb(255, 255, 0)"));
        break;
    case BLUE:
        ui-> lbColor->setStyleSheet(QString("background-color: rgb(0,   0,   255)"));
        break;
    case GREEN:
        ui-> lbColor->setStyleSheet(QString("background-color: rgb(0,   255, 0)"));
        break;
    case WHITE:
        ui-> lbColor->setStyleSheet(QString("background-color: rgb(255, 255, 255)"));
        break;
    }
}
/*
* @项目   TBus_SSEF
* @函数   void slotTimeOut();
* @描述   定时器改变颜色
* @作者   Micheal(陈明明)
* @时间   2019-04-25
*/
void Screen::slotTimeOut()
{
    m_index++;
    setColor(m_index);
    if (m_index == END) {
        hide();
        m_index = 0;
        m_colorTimer->stop();
        ui->lbColor->setStyleSheet(QString("background-color: rgb(255, 0,   0)"));
    }
}
