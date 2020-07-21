#ifndef NODE3V_H
#define NODE3V_H

#include <QWidget>

namespace Ui {
class Node_PM;
}
class QTimer;
class NodeValue_PM;
class QButtonGroup;
class Node_PM : public QWidget
{
    Q_OBJECT

public:
    explicit Node_PM(QWidget *parent = 0);
    ~Node_PM();
    void confType(int type);
    void updateValue(QList<int> valueList);
    void keyCheck();

private:
    Ui::Node_PM *ui;
    QTimer *m_timer;
    int m_pass;
    int m_type;
    int m_runFlag;
    NodeValue_PM *m_nodeValue_1;
    NodeValue_PM *m_nodeValue_2;
    QButtonGroup *m_funBtnGroup;
    QButtonGroup *m_typeBtnGroup;
private slots:
    void slotGetData();
    void slotTimeOut();
    void slotFunBtn(int index);
    void slotTypeBtn(int index);
signals:
    void sigBtnBack();
    void sigRunFlag(bool run);
    void sigStart(int cmd);
    void sigCurrentCmd(int cmd);
    void sigVoltageCmd(int cmd);
private:
    void btnClear();
    void btnReset();
    void btnCheck();

};

#endif // NODE3V_H
