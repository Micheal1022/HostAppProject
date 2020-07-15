#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>


#define ADMIN   1
#define SUPER   2

namespace Ui {
class UserLogin;
}
class QButtonGroup;
class QGraphicsDropShadowEffect;
class UserLogin : public QWidget
{
    Q_OBJECT

public:
    explicit UserLogin(QWidget *parent = 0);
    ~UserLogin();
    void confShow();
private:
    void initConnect();
private:
    Ui::UserLogin *ui;

    QString m_adminPwd;//管理员密码
    QString m_superPwd;//超级密码
    QString m_selectStr;
    QString m_unSelectStr;
    bool m_adminSelect;
    bool m_superSelect;

    void initKey();
    QButtonGroup *m_btnKeyGroup;
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
signals:
    void sigUserLogin(int user);
private slots:
    void slotBtnOk();
    void slotBtnAdmin();
    void slotBtnSuper();
    void slotBtnKey(int index);


};

#endif // USERLOGIN_H
