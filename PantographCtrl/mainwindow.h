#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QTimer;
class UserLogin;
class SystemConf;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *m_timeTimer;
    UserLogin *m_userLogin;
    SystemConf *m_systemConf;
    void initObject();
    void initWidget();
    void initConnect();
private slots:
    void slotTimeTimerOut();
    void slotUserLogin();
    void slotUserLoginOk();
    void slotUserLogout();

    void slotAutoMode();
    void slotManualMode();
    void slotRepairMode();
};

#endif // MAINWINDOW_H
