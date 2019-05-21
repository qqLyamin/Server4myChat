#include "client.h"

Client::Client()
{

}

Client::~Client()
{
    socket->deleteLater(); /*8*/
}

void Client::SetSocket(QTcpSocket * S)
{
    socket = S;/*6*/
    connect(socket, &QTcpSocket::stateChanged, this, &Client::SocketStateChanged);
}

void Client::SocketStateChanged(QAbstractSocket::SocketState State)
{
    switch (State) {
        case QAbstractSocket::ConnectedState:
            qDebug() << "Connected";
        break;

        case QAbstractSocket::UnconnectedState:
            qDebug() << "No Connection";
            emit Disconnected();
        break;
    default: break;
    }
}
