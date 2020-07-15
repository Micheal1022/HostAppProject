#ifndef CONFPWD_H
#define CONFPWD_H

#include <QWidget>

namespace Ui {
class ConfPwd;
}
class QButtonGroup;
class QGraphicsDropShadowEffect;
class ConfPwd : public QWidget
{
    Q_OBJECT

public:
    explicit ConfPwd(QWidget *parent = 0);
    ~ConfPwd();


private:
    Ui::ConfPwd *ui;
    QString m_selectStr;
    QString m_unSelectStr;
    bool btnAdminSelect;
    bool btnSuperSelect;

    void initKey();
    QButtonGroup *m_btnKeyGroup;
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
private slots:
    void slotBtnPwdOk();
    void slotBtnRestore();
    void slotBtnAdmin();
    void slotBtnSuper();
    void slotBtnKey(int index);
};

#endif // CONFPWD_H
