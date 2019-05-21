#include <QCoreApplication>
#include "server.h"
#include "QDebug"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server main;
/*1*/if (!main.listen(QHostAddress::Any, 25000))//потом сюда порт который прочитаю из файла с открытыми портами
    {
        qDebug() << main.serverError();
        exit(EXIT_FAILURE);//все развалилось - выходим
    }
    return a.exec();
}
