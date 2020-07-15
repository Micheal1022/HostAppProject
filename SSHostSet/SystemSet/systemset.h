#ifndef SYSTEMSET_H
#define SYSTEMSET_H

#include <QWidget>

namespace Ui {
class SystemSet;
}

class ConfPwd;
class ConfLoop;
class ConfNode;
class ConfTime;
class ConfNetWork;
class ConfDevice;
class QButtonGroup;
class QGraphicsDropShadowEffect;
class SystemSet : public QWidget
{
    Q_OBJECT

public:
    explicit SystemSet(QWidget *parent = 0);
    ~SystemSet();

    void confShow(int user);
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);

private:
    Ui::SystemSet *ui;
    ConfPwd  *m_confPwd;
    ConfLoop *m_confLoop;
    ConfNode *m_confNode;
    ConfTime *m_confTime;
    ConfDevice  *m_confDevice;
    ConfNetWork *m_confNetWork;
    QButtonGroup *m_btnGroup;
    int m_user;
    void initWidget();
    void initConnect();
signals:
    void sigMainBack();

private slots:
    void slotBtnGroup(int index);
public slots:
    void slotSendSetValue(int cmd, int type, int value);

};

#endif // SYSTEMSET_H
