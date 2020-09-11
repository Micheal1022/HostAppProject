#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>

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

    QString m_passwd;//超级密码

    void initKey();
    QButtonGroup *m_btnKeyGroup;
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
signals:
    void sigUserLoginOk();
private slots:
    void slotBtnOk();
    void slotBtnBack();
    void slotBtnKey(int index);


};

#endif // USERLOGIN_H
