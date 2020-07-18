#ifndef NODE12L_H
#define NODE12L_H

#include <QWidget>

namespace Ui {
class Node12L;
}

class Node12L : public QWidget
{
    Q_OBJECT

public:
    explicit Node12L(QWidget *parent = 0);
    ~Node12L();

private:
    Ui::Node12L *ui;
};

#endif // NODE12L_H
