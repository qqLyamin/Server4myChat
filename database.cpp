#include "database.h"
/*10*/
Database::Database(QObject *parent) : QObject(parent)
{
    allclients_db = QSqlDatabase::addDatabase("QMYSQL");
    allclients_db.setHostName("localhost");
    allclients_db.setDatabaseName("allclients");
    allclients_db.setUserName("root");
    allclients_db.setPassword("2708tjlfe");

    if (!allclients_db.open())
    {
        qDebug() << "db openning error " << allclients_db.lastError().text();
    }
    else {
        qDebug() << "Success!";
    }
}

void Database::add_newclient(const QString & name, const QString & password, const QString & email) const
{
    QSqlQuery query;
    query.prepare("INSERT INTO clients(name, email, password)" "VALUES(?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(password);
    query.addBindValue(email);
    if (query.exec())
    {
        qDebug() << "success table";
    }
    else {
        qDebug() << query.lastError().text();
    }
}

bool Database::confirm_entrance(const QString & name, const QString & password)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM clients WHERE NAME = (?) AND PASSWORD = (?)");
    query.addBindValue(name);
    query.addBindValue(password);
    if (query.exec())
    {
        query.first();
        int a = query.value(0).toInt();
        return static_cast<bool>(a);
    }
    return false;
}
