#include "infodlg.h"
#include "ui_infodlg.h"

InfoDlg::InfoDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDlg)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setModal(true);

}

InfoDlg::~InfoDlg()
{
    delete ui;
}

void InfoDlg::initInfoDlg(QString title, QString context)
{
    ui->lbTitle->clear();
    ui->lbContext->clear();
    ui->lbTitle->setText(title);
    ui->lbContext->setText(context);
}
