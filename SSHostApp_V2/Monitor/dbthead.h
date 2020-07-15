#ifndef DBTHEAD_H
#define DBTHEAD_H

#include <QObject>
#include "SQLite/mysqlite.h"
class DBThead : public QObject
{
    Q_OBJECT
public:
    explicit DBThead(QObject *parent = 0);

signals:

public slots:
    void slotInsertAlarmInfo(int loop, int type, int state, int canId, int value, int pass, uint time, QString area);
    //void slotInsertErrorInfo();
};

#endif // DBTHEAD_H
