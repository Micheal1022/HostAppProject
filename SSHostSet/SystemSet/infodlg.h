#ifndef INFODLG_H
#define INFODLG_H

#include <QDialog>

namespace Ui {
class InfoDlg;
}

class InfoDlg : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDlg(QWidget *parent = 0);
    ~InfoDlg();
    void initInfoDlg(QString title, QString context);
private:
    Ui::InfoDlg *ui;
};

#endif // INFODLG_H
