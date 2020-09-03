#ifndef NODESQLITE_H
#define NODESQLITE_H
#include "mysqlite.h"

class NodeSQLIte : public MySQLite
{
public:
    NodeSQLIte();
    NodeSQLIte(QString dataBaseName);

    static QList<QStringList> getNodeInfoList(QSqlDatabase db,int loop);


};

#endif // NODESQLITE_H
