#ifndef CONFNETWORK_H
#define CONFNETWORK_H

#include <QWidget>

namespace Ui {
class ConfNetWork;
}
class QLineEdit;
class QButtonGroup;
class ConfNetWork : public QWidget
{
    Q_OBJECT

public:
    explicit ConfNetWork(QWidget *parent = 0);
    ~ConfNetWork();

private:
    Ui::ConfNetWork *ui;
    QButtonGroup *m_btnKeyGroup;
    QList<QLineEdit *> m_lineEditList_1;
    QList<QLineEdit *> m_lineEditList_2;
    void initConf();
    void setNetWorkIP(QList<QLineEdit *> lineEditList, int netNum);
    void parseStringIP(QString ip, QString &ip_1, QString &ip_2, QString &ip_3, QString &ip_4);

private slots:
    void slotBtnNetWorkOk_1();
    void slotBtnNetWorkOk_2();
    void slotBtnKeyIndex(int index);
};

#endif // CONFNETWORK_H
