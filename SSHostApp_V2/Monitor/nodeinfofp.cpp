#include "nodeinfofp.h"
#include "ui_nodeinfofp.h"

NodeInfoFP::NodeInfoFP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodeInfoFP)
{
    ui->setupUi(this);
}

NodeInfoFP::~NodeInfoFP()
{
    delete ui;
}
