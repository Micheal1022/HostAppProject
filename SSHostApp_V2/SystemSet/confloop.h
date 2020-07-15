#ifndef CONFLOOP_H
#define CONFLOOP_H

#include <QWidget>

namespace Ui {
class ConfLoop;
}
class QButtonGroup;
class QGraphicsDropShadowEffect;
class ConfLoop : public QWidget
{
    Q_OBJECT

public:
    explicit ConfLoop(QWidget *parent = 0);
    ~ConfLoop();

private:
    Ui::ConfLoop *ui;
    QString m_selectStr;
    QString m_unSelectStr;
    QList<bool> m_btnSelect;
    QButtonGroup *m_btnLoopGroup;
    void initConf();
    void initLoopBtn();
    void setBtnVisible(int count);
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
private slots:
    void slotBtnLoop(int index);


};

#endif // CONFLOOP_H
