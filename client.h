#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>

class Client : public QObject
{
    Q_OBJECT
    QTcpSocket * socket;    /*4*/
public:
    void SetSocket(QTcpSocket *); /*5*/
    Client();
    ~Client();/*7*/
private slots:
    void SocketStateChanged(QAbstractSocket::SocketState);//состояние сокета
signals:
    void Disconnected();
};

#endif // CLIENT_H
