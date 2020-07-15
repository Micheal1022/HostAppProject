#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class Screen;
class Record;
class Monitor;
class UserLogin;
class SystemSet;
class CanDataMgm;
class QToolButton;
class QGraphicsDropShadowEffect;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    struct NodeInfo{
        int loop;
        int canId;

    } ;

    void initConnect();
    void initVariable();
    void initWidget();
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
    Ui::MainWindow *ui;
    int m_user;
    Screen  *m_screen;
    Record  *m_record;
    Monitor *m_monitor;
    UserLogin *m_userLogin;
    //SystemSet *m_systemSet;
    CanDataMgm *m_canDataMgm;
    QTimer *m_timer;

//    QGraphicsDropShadowEffect *m_monitorEffect;
//    QGraphicsDropShadowEffect *m_loginoutEffect;
//    QGraphicsDropShadowEffect *m_recordEffect;
//    QGraphicsDropShadowEffect *m_selfCheckEffect;
//    QGraphicsDropShadowEffect *m_systemSetEffect;
//    QGraphicsDropShadowEffect *m_userLoginEffect;
    bool m_checkSelf;

    void initStylesheet();
private slots:

    void slotUserLogin(int user);

    void slotBtnRecord();
    void slotBtnMonitor();
    void slotBtnSystemSet();
    void slotBtnUserLogin();
    void slotBtnSelfCheck();

    void slotBackHome();

    void slotLogout();



    void on_tBtnSystemError_clicked();
};

#endif // MAINWINDOW_H
