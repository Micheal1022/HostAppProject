#ifndef NODE12L_H
#define NODE12L_H

#include <QWidget>

namespace Ui {
class Node_EF;
}
class QTimer;
class NodeValue_EF;
class QButtonGroup;
class Node_EF : public QWidget
{
    Q_OBJECT

public:
    explicit Node_EF(QWidget *parent = 0);
    ~Node_EF();
    void updateValue(QList<int> valueList);
    void keyCheck();
    void initVar();
private:
    Ui::Node_EF *ui;
    int m_pass;
    int m_time;
    int m_step;
    int m_delay;
    bool m_keyCheck;
    bool m_checkFlag;
    bool m_dataFlag;
    QTimer *m_timer;
    NodeValue_EF *m_nodeValue_1;
    NodeValue_EF *m_nodeValue_2;
    QButtonGroup *m_funBtnGroup;
    QButtonGroup *m_typeBtnGroup;
private slots:
    void slotFunBtn(int index);
    void slotTypeBtn(int index);
signals:
    void sigBtnBack();
    void sigStart();
    void sigStop();
    void sigLeakCmd(int cmd,int state);
private slots:
    void slotTimeOut();
};

#endif // NODE12L_H
