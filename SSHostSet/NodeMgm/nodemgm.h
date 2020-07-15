#ifndef NODEMGM_H
#define NODEMGM_H

#include <QWidget>

namespace Ui {
class NodeMgm;
}

class NodeMgm : public QWidget
{
    Q_OBJECT

public:
    explicit NodeMgm(QWidget *parent = 0);
    ~NodeMgm();

private:
    Ui::NodeMgm *ui;
};

#endif // NODEMGM_H
