#include "node12l.h"
#include "ui_node12l.h"

Node12L::Node12L(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Node12L)
{
    ui->setupUi(this);
}

Node12L::~Node12L()
{
    delete ui;
}
