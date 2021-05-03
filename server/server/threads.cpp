#include "threads.h"

Thread::Thread(int ID ,QObject *parent):
    QThread(parent) {
    this->socketDescriptor = ID;
}

void Thread::start(){

    qDebug()<< "Starting thread - " << socketDescriptor;
    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        qDebug() << socketDescriptor << " something wrong!";
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()) ,Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()) ,Qt::DirectConnection);

    qDebug() << socketDescriptor << " - Succesful connected!";
    socket->write("You are connected!");

    exec();
}

void Thread::readyRead(){
    QByteArray dataInfo = socket->readAll();
    qDebug() << socketDescriptor << " Data : " << dataInfo;
    if(dataInfo == "Disconnect"){
        socket->disconnect();
    }
    //socket->write(Data);
}

void Thread::disconnected(){
    qDebug() << socketDescriptor << " disconnected ";
    socket->disconnect();
    socket->deleteLater();
    exit(0);
}
