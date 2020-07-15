#include "dbthead.h"
#include "SQLite/mysqlite.h"
#include "includes.h"

DBThead::DBThead(QObject *parent) : QObject(parent)
{

}
/*
* @项目   TBus_SSEF
* @函数   bool slotInsertAlarmInfo(int loop, int type, int state, int canId, int value, uint time, QString area);
* @描述   通过线程槽函数进行存储，较少事务等待时间，防止冻结界面
* @作者   Micheal(陈明明)
* @时间   2019-04-09
*/
void DBThead::slotInsertAlarmInfo(int loop, int type, int state, int canId, int value, int pass, uint time, QString area)
{
    //删除最小的rowid
    //select count(*) from RECORD;
    //delete from CONFLOOP where rowid = (select min(rowid) from RECORD);
    QSqlDatabase db  = MySQLite::openConnection();
    //如果数目到达10000条后数据删除最小ROWID的记录
    int count = MySQLite::getRowCount(db,QString("select count(*) from RECORD;"));
    if (count == MAXNUM) {
        MySQLite::coverRecord(db);
    }

    QString loopStr  = QString::number(loop);
    QString canIdStr = QString::number(canId);
    QString typeStr  = QString::number(type);
    QString stateStr = QString::number(state);
    QString passStr  = QString::number(pass);
    QString valueStr = QString::number(value);
    QString timeStr  = QString::number(time);
    QString sql = "insert into RECORD values(";
    sql += loopStr+","+canIdStr+","+passStr+","+typeStr+","+stateStr+","+valueStr+","+timeStr+",'"+area+"');";
    QSqlQuery query(db);
    if (!query.exec(sql)) {
        MySQLite::closeConnection(db);
    }
    MySQLite::closeConnection(db);
    query.finish();
    query.clear();
}

