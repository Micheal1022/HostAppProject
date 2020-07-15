#ifndef RECORD_H
#define RECORD_H

#include <QWidget>

namespace Ui {
class Record;
}
class DataFilter;
class QTableWidget;
class QGraphicsDropShadowEffect;
class Record : public QWidget
{
    Q_OBJECT

public:
    explicit Record(QWidget *parent = 0);
    ~Record();
    void confShow(int user);

private:
    Ui::Record *ui;
    QString m_queryStr;
    QString m_formatTime;
    DataFilter *m_dataFilter;
    int m_pageCount;
    int m_pageCurrent;
private:
    void initVar();
    void initConnect();
    int getPageCount(QString queryStr);
    void initTabelWgt(QTableWidget *tableWidget);
    void displayQuery(QString queryStr, QTableWidget *tableWidget, int pageCurrent);
    void setGraphicsEffect(QGraphicsDropShadowEffect *effect, QWidget *widget);
    void deleteAllData();
    void deleteSelectData(int Loop, int CanID, uint alarmTime);
private slots:
    void slotBtnDel();
    void slotBtnAllDel();
    void slotBtnBack();
    void slotBtnPrint();
    void slotBtnQuery();
    void slotBtnFilter();
    void slotSqlQuery(QString queryStr);
    void slotBtnNest();
    void slotBtnLast();
};

#endif // RECORD_H
