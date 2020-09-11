#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "includes.h"
#include "UserLogin/userlogin.h"
#include "SystemConf/systemconf.h"
#include "UartCom/uartcom.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *m_timeTimer;
    UartCom    *m_uartCom;
    UserLogin  *m_userLogin;
    SystemConf *m_systemConf;
    QString m_select;
    QString m_unselect;
    QString m_redColorState;
    QString m_greenColorState;
    QString m_redColorError;
    QString m_greenColorError;
    QButtonGroup *m_btnGroup;
    QList<QLabel *> m_stateLabelList;
    QList<QLabel *> m_errorLabelList;
    int m_error;
    uchar m_mode;
    void initObject();
    void initWidget();
    void initConnect();
    void initLabelList(QList<QLabel *> labelList, QString string);
    void setLabelListValue(QList<QLabel *> labelList, int index, QString string);
    void analysisRealData(QList<int> dataList);
    void analysisBowError(int error);
    void analysisBowState(int state);
signals:
    void sigSportMode(QByteArray byteArray);
private slots:
    void slotTimeTimerOut();
    void slotUserLogin();
    void slotUserLoginOk();
    void slotUserLogout();
    void slotSystemConf();

    void slotSportMode(int btn);
    void slotSystemConfData(QByteArray byteArray);

    void slotRecvSystemConfData(QList<int> dataList);
    void slotRecvData(QList<int> dataList);
};

#endif // MAINWINDOW_H
