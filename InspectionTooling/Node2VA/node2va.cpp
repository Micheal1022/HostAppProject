#include "node2va.h"
#include "ui_node2va.h"

Node2VA::Node2VA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Node2VA)
{
    ui->setupUi(this);
}

Node2VA::~Node2VA()
{
    delete ui;
}
