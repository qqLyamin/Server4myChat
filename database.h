#ifndef DATABASE_H
#define DATABASE_H
/*9*/
#include <QObject>
#include <QSqlError>
#include <QSqlRecord>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>

class Database : public QObject
{
    Q_OBJECT
    QSqlDatabase allclients_db;
public:
    explicit Database(QObject *parent = nullptr);
    void add_newclient(const QString & name, const QString & password, const QString & email) const;
    bool confirm_entrance(const QString & name, const QString & password);

signals:

public slots:
};

#endif // DATABASE_H
