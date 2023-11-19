
#include "databasemanager.h"

QSqlDatabase DatabaseManager::getDatabase(const QString &databasePath, const QString &connectionName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    db.setDatabaseName(databasePath);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    }
    return db;
}

void DatabaseManager::closeDatabase(const QString &connectionName)
{
    QSqlDatabase db = QSqlDatabase::database(connectionName);
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database connection closed.";
    }
    //QSqlDatabase::removeDatabase("qt_sql_default_connection");
}
