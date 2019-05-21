#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "client.h"

class Server : public QObject
{
    Q_OBJECT
    QTcpServer my_server;/*2*/
    QList<Client *> my_clients;

public:
    explicit Server(QObject *parent = nullptr);
    bool listen(const QHostAddress &address = QHostAddress::Any, quint16 port = 0);/*3*/
    QAbstractSocket::SocketError serverError() const;
signals:
private slots:
    void newConnection();/*11*/
    void Disconnected_signal();
public slots:
};

#endif // SERVER_H
