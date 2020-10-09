#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class ConfPwd;
class RecvFile;
class ConfAddr;
class ConfLoop;
class ConfNode;
class ConfTime;
class UserLogin;
class QTcpSocket;
class QTcpServer;
class CanDataMgm;
class ConfNetWork;
class ConfDevice;
class QButtonGroup;
class QGraphicsDropShadowEffect;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);

    ConfPwd  *m_confPwd;
    RecvFile *m_recvFile;
    ConfLoop *m_confLoop;
    ConfNode *m_confNode;
    ConfAddr *m_confAddr;
    ConfTime *m_confTime;
    UserLogin *m_userLoign;
    ConfDevice  *m_confDevice;
    ConfNetWork *m_confNetWork;
    QButtonGroup *m_btnGroup;
    CanDataMgm *m_canDataMgm;





    int m_user;
    void initWidget();
    void initConnect();


signals:
    void sigMainBack();

private slots:
    void slotBtnGroup(int index);
    void slotSystemShow(int user);


public slots:
    void slotSendSetValue(int cmd, int type, int value);
};

#endif // MAINWINDOW_H
