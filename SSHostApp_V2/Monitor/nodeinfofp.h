#ifndef NODEINFOFP_H
#define NODEINFOFP_H

#include <QDialog>

namespace Ui {
class NodeInfoFP;
}

class NodeInfoFP : public QDialog
{
    Q_OBJECT

public:
    explicit NodeInfoFP(QWidget *parent = 0);
    ~NodeInfoFP();

private:
    Ui::NodeInfoFP *ui;
};

#endif // NODEINFOFP_H
