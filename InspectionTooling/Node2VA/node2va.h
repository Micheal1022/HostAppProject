#ifndef NODE2VA_H
#define NODE2VA_H

#include <QWidget>

namespace Ui {
class Node2VA;
}

class Node2VA : public QWidget
{
    Q_OBJECT

public:
    explicit Node2VA(QWidget *parent = 0);
    ~Node2VA();

private:
    Ui::Node2VA *ui;
};

#endif // NODE2VA_H
