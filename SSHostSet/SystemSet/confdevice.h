#ifndef CONFDEVICE_H
#define CONFDEVICE_H

#include <QWidget>

namespace Ui {
class ConfDevice;
}
class QButtonGroup;
class QGraphicsDropShadowEffect;
class ConfDevice : public QWidget
{
    Q_OBJECT

public:
    explicit ConfDevice(QWidget *parent = 0);
    ~ConfDevice();

private:
    Ui::ConfDevice *ui;
    QString m_selectStr;
    QString m_unSelectStr;
    QList<bool> m_btnLoopSelect;
    QList<bool> m_btnDevSelect;
    QButtonGroup *m_btnLoopGroup;
    QButtonGroup *m_btnDevGroup;
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
private slots:
    void slotBtnIndex(int index);
    void slotBtnUpdateDB();
    void slotBtnUpdateApp();
    void slotBtnUpdateHost();
    void slotBtnUpdateConf();
    void slotBtnDevType(int index);
    void slotBtnZH();
    void slotBtnEN();
};

#endif // CONFDEVICE_H
