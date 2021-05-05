#include "server.h"


Server::Server(QObject *parent):QTcpServer(){}

void Server::startServer(){

    if(this->listen(QHostAddress::Any , 1488)){

        qDebug() <<"Sucseccful start server with port " << this->serverPort();
    }
    else{
        qDebug() <<"Something wrong... Cant start server";
    }
}

void Server::incomingConnection(qintptr socketDescriptor){

    qDebug() << socketDescriptor << "Connecting...";
    Thread *thread = new Thread(socketDescriptor,this);

    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));

    thread->start();
}
