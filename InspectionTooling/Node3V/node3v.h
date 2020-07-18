#ifndef NODE3V_H
#define NODE3V_H

#include <QWidget>

namespace Ui {
class Node3V;
}
class NodeValue_PM;
class QButtonGroup;
class Node3V : public QWidget
{
    Q_OBJECT

public:
    explicit Node3V(QWidget *parent = 0);
    ~Node3V();
    void confType(int type);

private:
    Ui::Node3V *ui;
    NodeValue_PM *m_nodeValue_1;
    NodeValue_PM *m_nodeValue_2;
    QButtonGroup *m_funBtnGroup;
    QButtonGroup *m_typeBtnGroup;
private slots:
    void slotFunBtn(int index);
    void slotTypeBtn(int index);
signals:
    void sigBtnBack();
private slots:
    void slotBtnClear();
    void slotBtnReset();
    void slotBtnCheck();
    void slotGetData();
};

#endif // NODE3V_H
