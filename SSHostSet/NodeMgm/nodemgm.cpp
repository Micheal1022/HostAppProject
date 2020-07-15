#include "nodemgm.h"
#include "ui_nodemgm.h"

NodeMgm::NodeMgm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NodeMgm)
{
    ui->setupUi(this);
}

NodeMgm::~NodeMgm()
{
    delete ui;
}
