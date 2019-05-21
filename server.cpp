#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    connect(&my_server, &QTcpServer::newConnection, this, &Server::newConnection); // появился сокет - обработал его nextPendingConnection
}

bool Server::listen(const QHostAddress &address, quint16 port)
{
    return my_server.listen(address, port);
}

QAbstractSocket::SocketError Server::serverError() const
{
    return my_server.serverError();
}

void Server::newConnection()/*12*/
{
    Client * new_client = new Client;
    connect(new_client, &Client::Disconnected, this, &Server::Disconnected_signal);
    new_client->SetSocket(my_server.nextPendingConnection()); //создаю клиента, отдав ему сокет от сервера

    my_clients.push_back(new_client);//закинул ко всем клиентам
}

void Server::Disconnected_signal()
{
    Client * Any_client = reinterpret_cast<Client*>(QObject::sender()); // почему не съел статик каст????????????
    for (auto i = my_clients.begin(); i != my_clients.end(); ++i)
    {
        if (Any_client == * i)
        {
            my_clients.removeOne(*i);
            delete Any_client;
        }
    }
}
