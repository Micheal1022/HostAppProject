#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class Modbus;
class Node_EF;
class Node_PM;
class KeyCheck;
class CanDataMgm;
class QButtonGroup;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QButtonGroup *m_buttonGroup;
    Modbus  *m_modbus;
    Node_PM *m_node3V;
    Node_PM *m_node2VA;
    Node_PM *m_node6V3A;
    Node_EF *m_nodeEF;
    KeyCheck *m_keyCheck;
    //Thread  *m_thread;
    CanDataMgm *m_canDataMgm;

    bool m_nodeEFFlag;
    bool m_node3VFlag;
    bool m_node2VAFlag;
    bool m_node6V3AFlag;


private slots:
    void slotBtnIndex(int index);
    void slotBtnBack();
    void slotSendCanData(QList<int> valueList);
    void slotKeyCheck();
};

#endif // MAINWINDOW_H
