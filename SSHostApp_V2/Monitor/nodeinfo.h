#ifndef NODEINFO_H
#define NODEINFO_H

#include <QDialog>

namespace Ui {
class NodeInfo;
}
class QTimer;
class NodeInfo : public QDialog
{
    Q_OBJECT

public:
    explicit NodeInfo(QWidget *parent = 0);
    ~NodeInfo();
    void showNodeValue(uint loop, uint type, uint state, uint canId, uint value, QString area);
    void recvCanData(int type,int state,int value_1,int value_2,int value_3);
    void setValueType(int type);
    QString getStateStr(int state);
    void setLockValue(int type, int value);
    void allLcdClean();

private:
    Ui::NodeInfo *ui;
    uint m_loop;
    uint m_canId;
    QTimer *m_valueTimer;
private slots:
    void slotTimeOut();
    void slotBtnHide();
};

#endif // NODEINFO_H
