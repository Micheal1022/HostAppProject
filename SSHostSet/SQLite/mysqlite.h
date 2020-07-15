#ifndef MYSQLITE_H
#define MYSQLITE_H
#include <QtSql>
#include <QDebug>
#include <QMutex>
#include <QQueue>
#include <QString>
#include <QVariant>
#include <QDateTime>
#include <QMutexLocker>
#include <QSqlQueryModel>
#include <QWaitCondition>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>
#include <QCryptographicHash>


class MySQLite
{
public:
    ~MySQLite();

    // 获取数据库连接
    static QSqlDatabase openConnection();
    // 释放数据库连接回连接池
    static void closeConnection(QSqlDatabase connection);


    //获取回路启用状态
    static QList<int> getLoopState(QSqlDatabase db);
    //获取回路可用状态
    static QList<int> getUsableLoop(QSqlDatabase db);
    //获取回路启用状态
    static QList<int> getLoopConf(QSqlDatabase db);
    //设置回路总数
    static bool setLoopNum(QSqlDatabase db, int count);
    //获取回路总数
    static int getLoopNum(QSqlDatabase db);
    //设置回路启用状态
    static bool setLoopConf(QSqlDatabase db, int loopNum, int able);
    //获取CAN通道选用状态
    static int getCanPassState(QSqlDatabase db);
    //根据获取当前回路下的节点信息
    static QList<QStringList> getNodeInfoList(QSqlDatabase db,int loop);
    //获得用户密码
    static QString getUserPwd(QSqlDatabase db, QString userType);
    //设置用户密码
    static bool setUserPwd(QSqlDatabase db, QString userType,QString pwd);
    //恢复出厂密码
    static bool setRestorePwd(QSqlDatabase db);
    //设置网络参数
    static bool setNetWorkIP(QSqlDatabase db, int netNum, int able, QString desIP, QString hostIP, QStringList portList);
    //获取网络参数
    static QStringList getNetWorkIP(QSqlDatabase db, int netNum);
    //获取网络状态
    static void getNetWorkState(QSqlDatabase db, int &able1,int &able2);
    //获取记录的条数
    static int getRowCount(QSqlDatabase db, const QString &sqlQuery);
    //覆盖数据
    static void coverRecord(QSqlDatabase db);
    //回去记录里列表
    static QList<QStringList> getRecordList(QSqlDatabase db,QString queryStr);
    //设置主机类型
    static bool setDevType(QSqlDatabase db, int type);
    //获取主机类型
    static int getDevType(QSqlDatabase db);
    //插入报警信息
    static void insertErrorInfo(int loop, int type, int state, int canId, int value, uint time, QString area);
    //删除全部数据
    static bool delAllData(QSqlDatabase db);
    //删除选择数据
    static bool delSelectData(QSqlDatabase db, int loop, int canId, uint alarmTime);
    //获取语言类型
    static int getLanguageType(QSqlDatabase db);
    //设置语言类型
    static bool setLanguageType(QSqlDatabase db,int type);

private:

    MySQLite();
    //互斥锁
    static QMutex m_mutex;
    //
    static MySQLite *m_instance;
    //
    QString m_dataBaseName;
    //
    static QWaitCondition m_waitConnection;
    //创建单例
    static MySQLite& getInstance();
    // 创建数据库连接
    QSqlDatabase createConnection(const QString &connectionName);
    // 数据库类型 QSQLITE
    QString m_dataBaseType;
    // 取得连接的时候验证连接是否有效
    bool m_testOnBorrow;
    // 获取连接最大等待时间
    int m_maxWaitTime;
    // 尝试获取连接时等待间隔时间
    int m_waitInterval;
    // 最大连接数
    int m_maxConntCount;
    // 测试访问数据库的 SQL
    QString m_testOnBorrowSql;
    // 已使用的数据库连接名
    QQueue<QString> m_usedConntNames;
    // 未使用的数据库连接名
    QQueue<QString> m_unusedConntNames;


};

#endif // MYSQLITE_H
