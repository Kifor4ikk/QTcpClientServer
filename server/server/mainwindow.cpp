#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QTcpServer(),QMainWindow(parent)

    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startServer(){

    if(this->listen(QHostAddress::Any , 1488)){

        qDebug() <<"Sucseccful start server with port " << this->serverPort();

    }
    else{
        qDebug() <<"Something wrong... Cant start server";
    }
}

void MainWindow::incomingConnection(qintptr socketDescriptor){

    qDebug() << socketDescriptor << "Connecting...";
    Thread *thread = new Thread(socketDescriptor);
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start();
}

