#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <QWidget>
namespace Ui {
class DataFilter;
}
class QButtonGroup;
class DataFilter : public QWidget
{
    Q_OBJECT

public:
    explicit DataFilter(QWidget *parent = 0);
    ~DataFilter();
    void showConf();
    void initBtnGroup();

private:
    Ui::DataFilter *ui;
    QButtonGroup *m_btnGroup;
    QButtonGroup *m_btnKeyGroup;
    QString m_selectStr;
    QString m_unSelectStr;
    QList<bool> m_btnSelect;

signals:
    void sigSqlQuery(QString queryStr);
private slots:
    void slotBtnOk();
    void slotBtnBack();
    void slotBtnIndex(int index);
    void slotSetCanIdEnable(bool enable);
    void slotSetLoopEnable(bool enable);
    void slotBtnKeyIndex(int index);
};

#endif // DATAFILTER_H
