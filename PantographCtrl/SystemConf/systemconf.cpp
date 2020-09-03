#include "systemconf.h"
#include "ui_systemconf.h"

SystemConf::SystemConf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemConf)
{
    ui->setupUi(this);
}

SystemConf::~SystemConf()
{
    delete ui;
}
