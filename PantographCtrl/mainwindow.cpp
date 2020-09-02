#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QTimer>

#define TIMEOUT    1000
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWidget()
{
    ui->lbTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
    m_timeTimer = new QTimer;
    connect(m_timeTimer,SIGNAL(timeout()),this,SLOT(slotTimeTimerOut()));
    m_timeTimer->start(TIMEOUT);
}

void MainWindow::slotTimeTimerOut()
{
    ui->lbTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
}
