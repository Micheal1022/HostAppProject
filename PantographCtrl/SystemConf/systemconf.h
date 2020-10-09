#ifndef SYSTEMCONF_H
#define SYSTEMCONF_H

#include <QWidget>

namespace Ui {
class SystemConf;
}
class QButtonGroup;
class QGraphicsDropShadowEffect;
class SystemConf : public QWidget
{
    Q_OBJECT

public:
    explicit SystemConf(QWidget *parent = 0);
    ~SystemConf();
    void systemConfData(QList<int> dataList);
private:
    Ui::SystemConf *ui;
    void initKey();
    void initConnect();
    QButtonGroup *m_btnKeyGroup;
    void SystemConfData(QByteArray &byteArray);
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
signals:
    void sigSystemConfData(QByteArray data);
    void sigReplayData(int cmd);
private slots:
    void slotBtnOk();
    void slotBtnBack();
    void slotBtnKey(int index);
    void slotSetSystemTime();
    void slotCalibration();
    void slotSystemConfData(QList<int> dataList);
public slots:
    void slotReplay();
};

#endif // SYSTEMCONF_H
