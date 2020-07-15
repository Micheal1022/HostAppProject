#include "mysqlite.h"

#define MAXNUM      1000*1000

QMutex MySQLite::m_mutex;
MySQLite* MySQLite::m_instance = NULL;
QWaitCondition MySQLite::m_waitConnection;

MySQLite::MySQLite()
{
    m_dataBaseName = "./SYSTEM.db";
    m_dataBaseType = "QSQLITE";
    m_testOnBorrow = true;

    m_maxWaitTime  = 1000;
    m_waitInterval = 200;
    m_maxConntCount = 5;
}

MySQLite::~MySQLite()
{
    // 销毁连接池的时候删除所有的连接
    foreach(QString connectionName, m_usedConntNames)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }

    foreach(QString connectionName, m_unusedConntNames)
    {
        QSqlDatabase::removeDatabase(connectionName);
    }
}

QSqlDatabase MySQLite::openConnection()
{
    MySQLite& pool = MySQLite::getInstance();
    QMutexLocker locker(&m_mutex);

    // 已创建连接数
    int conntCount = pool.m_unusedConntNames.size() + pool.m_usedConntNames.size();

    // 如果连接已经用完,等待 waitInterval 毫秒看看是否有可用连接,最长等待 maxWaitTime 毫秒
    for(int i=0;i<pool.m_maxWaitTime&&pool.m_unusedConntNames.size()==0&&conntCount==pool.m_maxConntCount;i+=pool.m_waitInterval)
    {
        m_waitConnection.wait(&m_mutex,pool.m_waitInterval);
        // 重新计算已创建连接数
        conntCount = pool.m_unusedConntNames.size() + pool.m_usedConntNames.size();
    }
    QString connectionName;
    if(pool.m_unusedConntNames.size() > 0)
    {
        // 有已经回收的连接，复用它们
        connectionName = pool.m_unusedConntNames.dequeue();
    }
    else if(conntCount < pool.m_maxConntCount)
    {
        // 没有已经回收的连接，但是没有达到最大连接数，则创建新的连接
        connectionName = QString("Connection-%1").arg(conntCount + 1);
    }
    else
    {
        // 已经达到最大连接数
        qDebug() << "Cannot create more connections.";
        return QSqlDatabase();
    }

    // 创建连接
    QSqlDatabase db = pool.createConnection(connectionName);

    // 有效的连接才放入 usedConnectionNames
    if (db.isOpen())
    {
        pool.m_usedConntNames.enqueue(connectionName);
    }

    return db;
}

void MySQLite::closeConnection(QSqlDatabase connection)
{
    MySQLite& pool = MySQLite::getInstance();
    QString connectionName = connection.connectionName();

    // 如果是我们创建的连接，从 used 里删除,放入 unused 里
    if (pool.m_usedConntNames.contains(connectionName))
    {
        QMutexLocker locker(&m_mutex);
        pool.m_usedConntNames.removeOne(connectionName);
        pool.m_unusedConntNames.enqueue(connectionName);
        m_waitConnection.wakeOne();
    }

}


/*
* @项目   TBus_SSEF
* @函数   static int getCanPassState(QSqlDatabase db);
* @描述   获取CAN通道选用状态
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
int MySQLite::getCanPassState(QSqlDatabase db)
{
    QString sqlQuery = "select CAN0,CAN1 from CANCONF;";
    QSqlQuery query(db);
    int can0 = 0;
    int can1 = 0;
    if (query.exec(sqlQuery)) {
        if (query.next()) {
            can0 = query.value(0).toInt();
            can1 = query.value(1).toInt();
        }
    }
    query.finish();
    query.clear();

    if (can1 == 1 && can0 == 0) {
        return 1;
    }
    return 0;
}
/*
* @项目   TBus_SSEF
* @函数   static QString setUserPwd(QSqlDatabase db,int userType,QString pwd);
* @描述   设置用户密码
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
bool MySQLite::setUserPwd(QSqlDatabase db, QString userType, QString pwd)
{
    //防止出现相同的密码
    if (userType == QString("ADMIN")) {
        QString superPwd = getUserPwd(db,QString("SUPER"));
        if (superPwd == pwd) {
            return false;
        }
    } else if (userType == QString("SUPER")) {
        QString adminPwd = getUserPwd(db,QString("ADMIN"));
        if (adminPwd == pwd) {
            return false;
        }
    }

    QString sqlQuery = QString("update LOGINPWD set PWD = '%1' where TYPE = '%2';").arg(pwd).arg(userType);
    QSqlQuery query(db);
    if (!query.exec(sqlQuery)) {
        return false;
    }
    query.finish();
    query.clear();
    return true;
}
/*
* @项目   TBus_SSEF
* @函数   static bool setRestorePwd(QSqlDatabase db, QString userType,QString pwd);
* @描述   恢复出厂密码
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
bool MySQLite::setRestorePwd(QSqlDatabase db)
{
    QString sqlQuery_1 = "update LOGINPWD set PWD = '111111' where TYPE = 'ADMIN';";
    QString sqlQuery_2 = "update LOGINPWD set PWD = '222222' where TYPE = 'SUPER';";
    QSqlQuery query(db);
    if(query.exec(sqlQuery_1) && query.exec(sqlQuery_2))
    {
        query.finish();
        query.clear();
        return true;
    }
    query.finish();
    query.clear();
    return false;
}

bool MySQLite::setNetWorkIP(QSqlDatabase db, int netNum, int able, QString desIP, QString hostIP, QStringList portList)
{
    QString string;
    for (int ind = 0; ind < portList.count(); ind++) {
        string = QString("PORT_")+QString::number(ind+1)+QString(" = ")
    }


    QString sqlQuery = "update CONFNET set DESIP = '"+desIP+"',LOCALIP = '"+hostIP+"',PORT = '"+portList+"', ABLE = "+QString::number(able)+" where NETNUM = "+QString::number(netNum)+";";
    //qDebug()<<"sqlQuery : "<<sqlQuery;
    QSqlQuery query(db);
    if(query.exec(sqlQuery)) {
        query.finish();
        query.clear();
        return true;
    }
    query.finish();
    query.clear();
    return false;
}

QStringList MySQLite::getNetWorkIP(QSqlDatabase db,int netNum)
{
    QStringList stringList;
    QString sqlQuery = "select DESIP,LOCALIP,PORT_1,PORT_2,PORT_3,PORT_4,PORT_5,PORT_6,PORT_7,PORT_8,ABLE from CONFNET where NETNUM = "+QString::number(netNum)+";";
    QSqlQuery query(db);
    if (query.exec(sqlQuery)) {
        if (query.next()) {
            stringList.append(query.value(0).toString());
            stringList.append(query.value(1).toString());
            stringList.append(query.value(2).toString());
            stringList.append(query.value(3).toString());
            stringList.append(query.value(4).toString());
            stringList.append(query.value(5).toString());
            stringList.append(query.value(6).toString());
            stringList.append(query.value(7).toString());
            stringList.append(query.value(8).toString());
            stringList.append(query.value(9).toString());
            stringList.append(query.value(10).toString());
        }
    }
    query.finish();
    query.clear();
    return stringList;
}

void MySQLite::getNetWorkState(QSqlDatabase db, int &able1, int &able2)
{
    QString sqlQuery = "select ABLE from CONFNET where NETNUM >= 1;";
    QSqlQuery query(db);
    if(query.exec(sqlQuery))
    {
        if(query.next())
        {
            able1 = query.value(0).toUInt();
            able2 = query.value(1).toUInt();
        }
    }
    query.finish();
    query.clear();
}


/*
* @项目   TBus_SSEF
* @函数   static getRowCount(QSqlDatabase db, const QString &sqlQuery);
* @描述   获得记录条目总数
* @作者   Micheal(陈明明)
* @时间   2019-04-21
*/
int MySQLite::getRowCount(QSqlDatabase db, const QString &sqlQuery)
{
    QSqlQuery query(db);
    if(query.exec(sqlQuery))
    {
        if(query.next())
        {
            return query.value(0).toInt();
        }
    }
    query.finish();
    query.clear();
    return -1;
}
/*
* @项目   TBus_SSEF
* @函数   static void coverRecord(QSqlDatabase db);
* @描述   删除最小ROWID的记录
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
void MySQLite::coverRecord(QSqlDatabase db)
{
    QString sqlQuery = "delete from RECORD where rowid = (select min(rowid) from RECORD);";
    QSqlQuery query(db);
    if(query.exec(sqlQuery))
    {
        if(query.next())
        {
            query.finish();
            query.clear();
        }
    }
    query.finish();
    query.clear();
}
/*
* @项目   TBus_SSEF
* @函数   QList<QStringList> getRecordList(QSqlDatabase db, QString queryStr);
* @描述   过去记录的列表
* @作者   Micheal(陈明明)
* @时间   2019-04-21
*/
QList<QStringList> MySQLite::getRecordList(QSqlDatabase db, QString queryStr)
{
    QList<QStringList> recordList;
    QSqlQuery query(db);
    if (query.exec(queryStr)) {
        while (query.next()) {
            QStringList stringList;
            stringList.append(query.value(0).toString());//loop
            stringList.append(query.value(1).toString());//id
            stringList.append(query.value(2).toString());//type
            stringList.append(query.value(3).toString());//state
            stringList.append(query.value(4).toString());//value
            stringList.append(query.value(5).toString());//time
            stringList.append(query.value(6).toString());//area
            recordList.append(stringList);
        }
    }
    query.finish();
    query.clear();
    return recordList;
}
/*
* @项目   TBus_SSEF
* @函数   static QString getUserPwd(QSqlDatabase db,int userType);
* @描述   获得用户密码
* @作者   Micheal(陈明明)
* @时间   2019-04-18
*/
QString MySQLite::getUserPwd(QSqlDatabase db, QString userType)
{
    QString pwdStr;
    QString sqlQuery = "select PWD from LOGINPWD where TYPE = '"+userType+"';";
    QSqlQuery query(db);
    if (query.exec(sqlQuery)) {
        if (query.next()) {
            pwdStr = query.value(0).toString();
        }
    }
    query.finish();
    query.clear();
    return pwdStr;
}
/*
* @项目   TBus_SSEF
* @函数   static QList<int> getLoopState(QSqlDatabase db);
* @描述   获取回路启用状态
* @作者   Micheal(陈明明)
* @时间   2019-03-08
*/
QList<int> MySQLite::getLoopState(QSqlDatabase db)
{
    QList<int> loopStateList;
    QString sqlQuery = "select LOOP_1,LOOP_2,LOOP_3,LOOP_4,LOOP_5,LOOP_6,LOOP_7,LOOP_8 from LOOPCONF;";
    QSqlQuery query(db);
    if(query.exec(sqlQuery))
    {
        if(query.next())
        {
            for(int i = 0;i<8;i++)
            {
                loopStateList.append(query.value(i).toInt());
            }
        }
    }
    query.finish();
    query.clear();

    return loopStateList;
}
/*
* @项目   TBus_SSEF
* @函数   static QList<QList<int> > getLoopConf(QSqlDatabase db);
* @描述   获取回路启用和类型配置
* @作者   Micheal(陈明明)
* @时间   2019-04-13
*/
QList<int>  MySQLite::getUsableLoop(QSqlDatabase db)
{
    QList<int> loopConf;
    QString sqlQuery = "select LOOPNUM from CONFLOOP where ENABLE = 1;";
    QSqlQuery query(db);
    if (query.exec(sqlQuery)) {
        while(query.next()) {
            loopConf.append(query.value(0).toInt());
        }
    }
    query.finish();
    query.clear();
    return loopConf;

}

QList<int> MySQLite::getLoopConf(QSqlDatabase db)
{
    QList<int> loopList;
    QString sqlQuery = "select ENABLE from CONFLOOP order by LOOPNUM asc;";
    QSqlQuery query(db);
    if(query.exec(sqlQuery)) {
        while (query.next()) {
            loopList.append(query.value(0).toInt());
        }
    }
    query.finish();
    query.clear();
    return loopList;
}

bool MySQLite::setLoopNum(QSqlDatabase db, int count)
{
    QSqlQuery query(db);
    QString sqlQuery = "update LOOPCOUNT set COUNT = "+QString::number(count)+";";
    if (query.exec(sqlQuery)) {
        query.finish();
        query.clear();
        return true;
    }
    query.finish();
    query.clear();
    return false;
}

int MySQLite::getLoopNum(QSqlDatabase db)
{
    int count;
    QString sqlQuery = "select COUNT from LOOPCOUNT;";
    QSqlQuery query(db);
    if (query.exec(sqlQuery)) {
        if (query.next()) {
            count = query.value(0).toInt();
        }
    }
    query.finish();
    query.clear();
    return count;
}
/*
* @项目   TBus_SSEF
* @函数   void setLoopConf(QSqlDatabase db,int loopNum,int able,int type);
* @描述   设置回路类型，启用状态
* @作者   Micheal(陈明明)
* @时间   2019-04-19
*/
bool MySQLite::setLoopConf(QSqlDatabase db, int loopNum, int able)
{
    QString ableStr = QString ::number(able);
    QString loopNumStr = QString ::number(loopNum);
    QSqlQuery query(db);
    QString sqlQuery = "update CONFLOOP set ENABLE = "+ableStr+" where LOOPNUM = "+loopNumStr+";";
    qDebug()<<"sqlQuery : "<<sqlQuery;
    if (query.exec(sqlQuery)) {
        query.finish();
        query.clear();
        return true;
    }
    query.finish();
    query.clear();
    return false;
}

MySQLite &MySQLite::getInstance()
{
    if (NULL == m_instance) {
        QMutexLocker locker(&m_mutex);

        if (NULL == m_instance) {
            m_instance = new MySQLite();
        }
    }
    return *m_instance;
}


QSqlDatabase MySQLite::createConnection(const QString &connectionName)
{
    // 连接已经创建过了,复用它,而不是重新创建
    if(QSqlDatabase::contains(connectionName))
    {
        QSqlDatabase dbPre = QSqlDatabase::database(connectionName);

        if(m_testOnBorrow)
        {
            //返回连接前访问数据库，如果连接断开，重新建立连接
            //qDebug() << "Test connection on borrow, execute:" << testOnBorrowSql << ", for" << connectionName;
            QSqlQuery query(dbPre);
            if (query.lastError().type() != QSqlError::NoError && !dbPre.open())
            {
                qDebug() << "Open datatabase error:" << dbPre.lastError().text();
                return QSqlDatabase();
            }
        }
        return dbPre;
    }

    // 创建一个新的连接
    QSqlDatabase db = QSqlDatabase::addDatabase(m_dataBaseType, connectionName);
    db.setDatabaseName(m_dataBaseName);
    if (!db.open())
    {
        qDebug() << "Open datatabase error:" << db.lastError().text();
        return QSqlDatabase();
    }
    return db;
}


bool MySQLite::setDevType(QSqlDatabase db, int type)
{
    QSqlQuery query(db);
    QString sqlQuery = "update DEVTYPE set TYPE = "+QString::number(type)+";";
    if (query.exec(sqlQuery)) {
        query.finish();
        query.clear();
        return true;
    }
    query.finish();
    query.clear();
    return false;
}

int MySQLite::getDevType(QSqlDatabase db)
{
    int type;
    QString sqlQuery = "select TYPE from DEVTYPE;";
    QSqlQuery query(db);
    if (query.exec(sqlQuery)) {
        if (query.next()) {
            type = query.value(0).toInt();
        }
    }
    query.finish();
    query.clear();
    return type;
}

void MySQLite::insertErrorInfo(int loop, int type, int state, int canId, int value, uint time, QString area)
{
    //删除最小的rowid
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
    QString valueStr = QString::number(value);
    QString timeStr  = QString::number(time);
    QString sql = "insert into RECORD values("+loopStr+","+canIdStr+","+typeStr+","+stateStr+","+valueStr+","+timeStr+",'"+area+"');";
    QSqlQuery query(db);
    if (!query.exec(sql)) {
        MySQLite::closeConnection(db);
    }
    MySQLite::closeConnection(db);
    query.finish();
    query.clear();
}

bool MySQLite::delAllData(QSqlDatabase db)
{
    QSqlQuery query(db);
    if (!query.exec(QString("delete from RECORD;"))) {
        return false;
    }
    query.finish();
    query.clear();
    return true;
}

bool MySQLite::delSelectData(QSqlDatabase db, int loop, int canId, uint alarmTime)
{
    QString loopStr = QString::number(loop);
    QString canIdStr = QString::number(canId);
    QString alarmTimeStr = QString::number(alarmTime);
    QString sqlQuery = QString("delete from RECORD where LOOP = %1 and CANID = %2 and TIME = %3;").arg(loopStr).arg(canIdStr).arg(alarmTimeStr);
    QSqlQuery query(db);
    if (!query.exec(sqlQuery)) {
        return false;
    }
    query.finish();
    query.clear();

    return true;
}



int MySQLite::getLanguageType(QSqlDatabase db)
{
    int type;
    QString sqlQuery = "select TYPE from LANG;";
    QSqlQuery query(db);
    if (query.exec(sqlQuery)) {
        if (query.next()) {
            type = query.value(0).toInt();
        }
    }
    query.finish();
    query.clear();
    return type;
}

bool MySQLite::setLanguageType(QSqlDatabase db, int type)
{
    QSqlQuery query(db);
    QString sqlQuery = "update LANG set TYPE = "+QString::number(type)+";";
    if (query.exec(sqlQuery)) {
        query.finish();
        query.clear();
        return true;
    }
    query.finish();
    query.clear();
    return false;
}
