#ifndef STATEINFO_H
#define STATEINFO_H

#include <QDialog>

namespace Ui {
class StateInfo;
}

class StateInfo : public QDialog
{
    Q_OBJECT

public:
    explicit StateInfo(QWidget *parent = 0);
    ~StateInfo();
    enum InfoType{
        AlarmInfo  = 0x01,
        ErrorInfo  = 0x02,
        PowerError = 0x03,
        PowerLost  = 0x04,
        OffLine    = 0x05
    };
    void showInfo(QList<QStringList> InfoList,InfoType type);

private:
    Ui::StateInfo *ui;
    int m_index;//当前索引
    int m_count;//索引总数
    QList<QStringList> m_InfoList;//信息列表

    void currentIndexInfo(QStringList infoList);
    void setLabelAlarmVisible(bool visible);
    void initConnect();


private slots:
    void slotHide();
    void slotLastStrip();
    void slotNestStrip();
};

#endif // STATEINFO_H
