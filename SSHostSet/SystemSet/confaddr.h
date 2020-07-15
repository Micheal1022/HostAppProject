#ifndef CONFADDR_H
#define CONFADDR_H

#include <QTableWidget>
#include <QWidget>
#include <QScrollBar>
#include <QAbstractScrollArea>
namespace Ui {
class ConfAddr;
}
class InfoDlg;
class QSqlDatabase;
class ConfAddr : public QWidget
{
    Q_OBJECT

public:
    explicit ConfAddr(QWidget *parent = 0);
    ~ConfAddr();
    void showNodeInfo();
private:
    Ui::ConfAddr *ui;
    InfoDlg *m_infoDlg;
    QList<QStringList> m_nodeInfoList;
    void getUseLoopList();
    bool updateNodeInfo(QString loop, QString canId, QString enable);
    void initTableWidget(QTableWidget *tableWidget);
    QList<QStringList> getNodeInfoList(int loop);
private slots:
    void slotDbOpen();
    void slotDbSave();
    void slotAllStart();
    void slotAllClose();
    void slotCellClick(int row, int column);
};

#endif // CONFADDR_H
