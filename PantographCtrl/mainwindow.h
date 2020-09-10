#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class QTimer;
class QLabel;
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
    QString m_redColorState;
    QString m_greenColorState;
    QString m_redColorError;
    QString m_greenColorError;
    QList<QLabel *> m_stateLabelList;
    QList<QLabel *> m_errorLabelList;
    int m_error;
    void initObject();
    void initWidget();
    void initConnect();
    void initLabelList(QList<QLabel *> labelList, QString string);
    void setLabelListValue(QList<QLabel *> labelList, int index, QString string);
    void analysisRealData(QList<int> dataList);
    void analysisBowError(int error);
    void analysisBowState(int state);
private slots:
    void slotTimeTimerOut();
    void slotUserLogin();
    void slotUserLoginOk();
    void slotUserLogout();
    void slotSystemConf();

    void slotAutoMode();
    void slotManualMode();
    void slotRepairMode();

    void slotRecvData(QList<int> dataList);
};

#endif // MAINWINDOW_H
