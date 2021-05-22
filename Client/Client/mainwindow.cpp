#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QFile>
#include <QString>
#include <QFileDevice>
#include <QThread>
#include <thread>
#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->disconnect_button->setDisabled(true);
    ui->download_file_button->setDisabled(true);
    ui->load_file_button->setDisabled(true);
    ui->delete_file_button->setDisabled(true);
    socket = new QTcpSocket;
      connect(socket, SIGNAL(readyRead()),this, SLOT(socketReady()));
      connect(socket, SIGNAL(disconnected()),this, SLOT(socketDisconnect()));
}

MainWindow::~MainWindow(){
    delete ui;
}


//CHECK IS IP VALID
bool IPChecker(QString str){
    QRegularExpression ipFormat("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    QRegularExpressionMatch mre = ipFormat.match(str);
    QStringList count = mre.capturedTexts();
    if ((count.size() > 0) && (count.contains(str))) {
        return true;
    }
    return false;
}

//CHECK IS PORT VALID
bool PortChecker(QString str){
    int x = str.toInt();
    if(x > 0 && x < 65536){
        return true;
    } else{
        return false;
    }
}
//CLEAR PORT AND IP WHEN TOO MUCH SYMBOLS
void MainWindow::on_ip_line_textChanged(const QString &arg1){
    qDebug() << arg1.length();
    if(arg1.length() > 18){
        ui->ip_line->setText("");
    }
}
void MainWindow::on_port_line_textChanged(const QString &arg1){
    qDebug() << arg1.length();
    if(arg1.length() > 6){
        ui->ip_line->setText("");
    }
}

//Connect button
//Here checked valid IP PORT
//And try to connect to server
void MainWindow::on_connect_button_clicked() {
    QString IP = "127.0.0.1";
    QString PORT = "1488";
    IP = ui->ip_line->text();
    PORT = ui->port_line->text();
    ui->connect_button->setDisabled(true);
    ui->disconnect_button->setDisabled(true);
    ui->ip_line->setDisabled(true);
    ui->port_line->setDisabled(true);
    ui->delete_file_button->setDisabled(true);
    if(IPChecker(IP)){
        if(PortChecker(PORT)){
            ui->statusBar->setText("Try connect to " + IP+ ":" + PORT);
            qDebug()<< "Try connect to " << IP << " : " << PORT.toInt();
            socket->connectToHost(IP, PORT.toInt());
            if(socket->waitForConnected(2000)){
                ui->statusBar->setText("Sucesful connect!");
                ui->download_file_button->setDisabled(false);
                ui->load_file_button->setDisabled(false);
                ui->disconnect_button->setDisabled(false);
                ui->delete_file_button->setDisabled(false);
                qDebug() << "Sucesful connect!";
            } else{
                ui->connect_button->setDisabled(false);
                ui->ip_line->setDisabled(false);
                ui->port_line->setDisabled(false);
                ui->statusBar->setText("Cant find this server or bad connection...");
                qDebug() << "Cant find this server or bad connection...";
            }
        }else{
            ui->connect_button->setDisabled(false);
            ui->ip_line->setDisabled(false);
            ui->port_line->setDisabled(false);
            ui->statusBar->setText("Bad PORT");
            qDebug() << "Bad PORT";
        }
    }else{
        ui->connect_button->setDisabled(false);
        ui->ip_line->setDisabled(false);
        ui->port_line->setDisabled(false);
        ui->statusBar->setText("Bad IP");
        qDebug() << "Bad IP";
    }
}

void MainWindow::disconnect(){
    this->socket->write(("disconnect"));
    this->socketDisconnect();
    ui->statusBar->setText("Disconnected...");
}

//Here socket disconnected from server if connected
void MainWindow::on_disconnect_button_clicked(){
//FRONT END
    ui->connect_button->setDisabled(false);
    ui->ip_line->setDisabled(false);
    ui->port_line->setDisabled(false);
    ui->disconnect_button->setDisabled(true);
    ui->download_file_button->setDisabled(true);
    ui->load_file_button->setDisabled(true);
//BACK END
    disconnect();
}

//nothing
void MainWindow::socketDisconnect(){
    this->socket->disconnect();
    this->socket->close();
}

//READ ALL INCOMMING MESSAGE
void MainWindow::socketReady(){
    QByteArray data = QByteArray(socket->readAll());
    //socket->write(("DIR;")+ui->dirServer->text().toUtf8()+";"+name.toUtf8());

    QString cmd = QString::fromUtf8(data.data(), data.length());
    QStringList command = cmd.split("|SPLIT|");

    for(int i = 0; i < command.size(); i++){

        if(command[i].length() > 50){
            qDebug() << i << "# big data";
        } else{
            qDebug() << i << "# " + command[i];
        }
    }

    if(command[0] == "03COMMAND"){
        QString temp;
        for(int i = 0; i < command.length();i++){

            if(command[i] == command[0] || command[i] == command[1]){}
            else temp += command[i];
        }
        loadFileToClient(command[1], temp.toUtf8());
        temp.clear();
        ui->load_file_button->setDisabled(true);
        ui->disconnect_button->setDisabled(true);
        ui->dirLocal->setDisabled(true);
        ui->dirServer->setDisabled(true);
        ui->download_file_button->setDisabled(true);
        ui->delete_file_button->setDisabled(true);
        ui->loadDir->setDisabled(true);

    } else if(command[0] == "File loaded..."){
        ui->load_file_button->setDisabled(false);
        ui->disconnect_button->setDisabled(false);
        ui->dirLocal->setDisabled(false);
        ui->dirServer->setDisabled(false);
        ui->download_file_button->setDisabled(false);
        ui->delete_file_button->setDisabled(false);
        ui->loadDir->setDisabled(false);

    }else{
        ui->SERVERWRITE->setText(data);
    }
}


void MainWindow::on_download_file_button_clicked() {
    downloadFile();
}

//SEND DIR TO TAKE FILES AND PATCHES
void MainWindow::on_loadDir_clicked(){
    qDebug() << "LOAD DIR";
    checkDir();
}
//check DIR
void MainWindow::checkDir(){
    QByteArray dir = ui->dirServer->text().toUtf8();
    socket->write(("01COMMAND|SPLIT|" + dir));
}

void MainWindow::sendFile(){
    QString dir = QString(ui->dirServer->text());
    QString name;
    QString data;
    //GetName
    for(int i = QString(ui->dirLocal->text()).length()-1; i > 0 ;i--){
        if(QString(ui->dirLocal->text())[i] == '\\' || QString(ui->dirLocal->text())[i] == '\/'){
            break;
        }
        name.push_front(QString(ui->dirLocal->text())[i]);
    }
    //Check file
    QFile file(ui->dirLocal->text());
    if(!file.open(QIODevice::ReadOnly)){
        ui->load_file_button->setDisabled(false);
        ui->disconnect_button->setDisabled(false);
        ui->dirLocal->setDisabled(false);
        ui->dirServer->setDisabled(false);
        ui->download_file_button->setDisabled(false);
        return;
    }

    ui->LOADFILEPANEL->setText("Load - " + dir + "/" + name);
    //Transfering file!
    QByteArray block;
    long tempBytes = 0;
    int bytesToSend = 1024; // no more then 1024
    while(!file.atEnd()){
        if(tempBytes + bytesToSend >= file.size()){
            block = (file.read(file.size() - tempBytes));
            tempBytes += (file.size() - tempBytes);

        } else{
            block = (file.read(bytesToSend));
            tempBytes += bytesToSend;
        }
        socket->write(("02COMMAND|SPLIT|" + dir + name +"|SPLIT|"+ block.toBase64() + "|SPLIT|").toUtf8());
       //qDebug() << "Bytes sended - " << tempBytes;
       //qDebug() << block;
        ui->LOADFILEPANEL->setText("Loading " + name + " " + QString::number(tempBytes) + "/" + QString::number(file.size()));
        socket->waitForReadyRead(10000);
    }
    file.close();
    ui->load_file_button->setDisabled(false);
    ui->disconnect_button->setDisabled(false);
    ui->dirLocal->setDisabled(false);
    ui->dirServer->setDisabled(false);
    ui->download_file_button->setDisabled(false);
}

void MainWindow::loadFileToClient(QString fileName , QByteArray data){
    QFile file2(fileName);
    if(file2.open(QIODevice::Append | QIODevice::WriteOnly)){
        file2.write(QByteArray::fromBase64(data));
        file2.close();
    }else{
        socket->write("Something go wrong");
        return;
    }
}

void MainWindow::on_delete_file_button_clicked(){
    socket->write(QString("04COMMAND|SPLIT|" + ui->dirServer->text()).toUtf8());
}

void MainWindow::downloadFile(){
    socket->write(QString("03COMMAND|SPLIT|" + ui->dirServer->text() + "|SPLIT|" + ui->dirLocal->text()).toUtf8());
}


//Button click load file
void MainWindow::on_load_file_button_clicked(){
    ui->load_file_button->setDisabled(true);
    ui->disconnect_button->setDisabled(true);
    ui->dirLocal->setDisabled(true);
    ui->dirServer->setDisabled(true);
    ui->download_file_button->setDisabled(true);
    sendFile();
}

//COMMAND LIST
/*
 * 01 - CHECK DIR
 * 02 - LOAD FILE
 * 03 - DOWNLOAD FILE
 * 04 - DELETE FILE
 * 97 - TEST1
 * 98 - TEST2
 * 99 - DISCONNECT
 */


void MainWindow::on_test2_clicked() {
    /*
    QString data = "98|SPLIT|‘‘‘‘‘‘‘‘‘)*@@*(%&@#%!($*!@$!($ ОЛЕГ ВАЛЕНТИНОВИЧ";
    socket->write(data.toUtf8());
    */
    QFile in(ui->dirLocal->text());
    in.open(QIODevice::ReadOnly);
    QDataStream file(&in);
    char * test;
    uint length = 64;
    file.readBytes(test, length);

    QFile file2("C:/Users/Кифор/Desktop/folder/123.txt");
    file2.open(QIODevice::WriteOnly);
    QDataStream file3(&file2);
    file3.writeBytes(test , length);

}


