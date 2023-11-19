#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>


class DatabaseManager
{
public:
    static QSqlDatabase getDatabase(const QString &databasePath, const QString &connectionName);
    static void closeDatabase(const QString &connectionName);

    //static QSqlDatabase getDatabase();
};


#endif // DATABASEMANAGER_H
