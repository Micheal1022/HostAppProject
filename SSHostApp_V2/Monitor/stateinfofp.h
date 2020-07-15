#ifndef STATEINFOFP_H
#define STATEINFOFP_H

#include <QDialog>

namespace Ui {
class StateInfoFP;
}

class StateInfoFP : public QDialog
{
    Q_OBJECT

public:
    explicit StateInfoFP(QWidget *parent = 0);
    ~StateInfoFP();

private:
    Ui::StateInfoFP *ui;
};

#endif // STATEINFOFP_H
