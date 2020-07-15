#include "stateinfofp.h"
#include "ui_stateinfofp.h"

StateInfoFP::StateInfoFP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StateInfoFP)
{
    ui->setupUi(this);
}

StateInfoFP::~StateInfoFP()
{
    delete ui;
}
