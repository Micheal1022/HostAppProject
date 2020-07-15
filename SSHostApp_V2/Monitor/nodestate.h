#ifndef NODESTATE_H
#define NODESTATE_H

#include <QDialog>

namespace Ui {
class NodeState;
}
class QTmier;
class QTableWidget;
class QTableWidgetItem;
class NodeState : public QDialog
{
    Q_OBJECT

public:
    explicit NodeState(QWidget *parent = 0);
    ~NodeState();
    void showNodeInfo(int loop, int canId, int nodeType, QString area);
    void recvCanData(int canId, int pass, int ptype, int pstate, int value_1, int value_2, int value_3);
private:
    Ui::NodeState *ui;
    QList<bool> m_passEnable;
    QList<QList<bool> > m_passEnableList;
    QTimer *m_valueTimer;
    QStringList m_headListEF;
    QStringList m_headListPM;
    QStringList m_headListTD;
    int m_loop;
    int m_canId;
    int m_nodeType;
    int m_rowCount;
    int m_hostType;
    void itemClear();
    QString getStateStr(int state);
    QString getNodeTypeStr(int nodeType);
    void initNodeTable(QTableWidget *tableWidget, int hostType);
    void updateTableData(int canId, int pass, int ptype, int pstate, int value_1, int value_2, int value_3);
private slots:

     void slotTimeOut();
     void slotBtnHide();
};

#endif // NODESTATE_H
