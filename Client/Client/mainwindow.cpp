#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->disconnect_button->setDisabled(true);
    ui->download_file_button->setDisabled(true);
    ui->load_file_button->setDisabled(true);
    socket = new QTcpSocket;
      connect(socket, SIGNAL(readyRead()),this, SLOT(socketReady()));
      connect(socket, SIGNAL(disconnected()),this, SLOT(socketDisconnect()));
}

QByteArray encrypt(QByteArray msg) {
    for(int i = 0; i < msg.size();i++)
        msg[i] = msg[i]+14;
    return msg;
}

QByteArray decrypt(QByteArray msg) {
    for(int i = 0; i < msg.size();i++)
        msg[i] = msg[i]-14;
    return msg;
}


MainWindow::~MainWindow()
{
    delete ui;
}


//check ip
bool IPChecker(QString str)
{
    QRegularExpression ipFormat("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegularExpressionMatch mre = ipFormat.match(str);
    QStringList count = mre.capturedTexts();

    if ((count.size() > 0) && (count.contains(str))) {
        return true;
    }
    return false;
}

//check port
bool PortChecker(QString str){

    int x = str.toInt();
    if(x > 0 && x < 65536){
        return true;
    }
    else{
        return false;
    }

}

//Click connect button
void MainWindow::on_connect_button_clicked() {

    QString IP = "127.0.0.1";
    QString PORT = "1488";

    IP = ui->ip_line->text();
    PORT = ui->port_line->text();
    ui->connect_button->setDisabled(true);
    ui->disconnect_button->setDisabled(true);
    ui->ip_line->setDisabled(true);
    ui->port_line->setDisabled(true);

    if(IPChecker(IP)){

        if(PortChecker(PORT)){

            ui->statusBar->setText("Try connect to " + IP+ ":" + PORT);
            qDebug()<< "Try connect to " << IP << " : " << PORT.toInt();
            socket->connectToHost(IP, PORT.toInt());
            if(socket->waitForConnected(2000)){

                ui->statusBar->setText("Sucesful connect!");

                qDebug() << "Sucesful connect - " << socket->isOpen();;

                ui->disconnect_button->setDisabled(false);
                qDebug() << "Sucesful connect!";
            } else{
                ui->connect_button->setDisabled(false);
                ui->ip_line->setDisabled(false);
                ui->port_line->setDisabled(false);
                ui->statusBar->setText("Cant find this server or bad connection...");
                qDebug() << "Cant find this server or bad connection...";
            }

        }else{
            ui->statusBar->setText("Bad PORT");
            qDebug() << "Bad PORT";
        }

    }else{

        ui->statusBar->setText("Bad IP");
        qDebug() << "Bad IP";
    }
}

void MainWindow::socketDisconnect(){
    this->socket->disconnect();
    this->socket->close();
}
//
void MainWindow::on_disconnect_button_clicked(){
    ui->connect_button->setDisabled(false);
    ui->ip_line->setDisabled(false);
    ui->port_line->setDisabled(false);
    ui->disconnect_button->setDisabled(true);

    this->socket->write(encrypt("disconnect"));
    this->socketDisconnect();
    ui->statusBar->setText("Disconnected...");
    //this->socket->close();

}

void MainWindow::on_TestMessage_clicked(){
    this->socket->write(encrypt("Test message"));
    qDebug() << "Send " << "test message";
}

//READY
void MainWindow::socketReady(){
    QByteArray data = socket->readAll();
    data = decrypt(data);
    ui->SERVERWRITE->setText(data);
    qDebug() << "Server write : " << data;
}

void MainWindow::on_test2_clicked() {
    socket->write(encrypt("Do you hear me?"));
}
