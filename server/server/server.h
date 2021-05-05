#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include<QDebug>
#include "thread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:

    explicit Server(QObject *parent = 0);
    void startServer();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);
    void reciveFrom(qintptr socketDescriptor);
    void disconnected();

};

#endif // SERVER_H
