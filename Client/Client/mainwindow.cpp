#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QFile>
#include <QString>


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


/**
 * @brief IPChecker
 * @param str
 * @return
 */
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

/**
 * @brief PortChecker
 * @param str
 * @return
 */
bool PortChecker(QString str){

    int x = str.toInt();
    if(x > 0 && x < 65536){
        return true;
    }
    else{
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

/**
 * @brief MainWindow::on_connect_button_clicked
 */
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

                ui->download_file_button->setDisabled(false);
                ui->load_file_button->setDisabled(false);
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

/**
 * @brief MainWindow::on_disconnect_button_clicked
 */
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

/**
 * @brief MainWindow::socketDisconnect
 */
void MainWindow::socketDisconnect(){
    this->socket->disconnect();
    this->socket->close();
}

/**
 * @brief MainWindow::socketReady
 */
void MainWindow::socketReady(){
    //BACK
    QByteArray data = (socket->readAll());
    //FRONT
    ui->SERVERWRITE->setText(data);
    qDebug() << "Server write : " << data;
}




//SEND DIR TO TAKE FILES AND PATCHES
void MainWindow::on_loadDir_clicked(){
    qDebug() << "LOAD DIR";
    checkDir();
}
/**
 * @brief MainWindow::on_load_file_button_clicked
 */
void MainWindow::on_load_file_button_clicked(){

    ui->load_file_button->setDisabled(true);
    ui->disconnect_button->setDisabled(true);
    ui->dirLocal->setDisabled(true);
    ui->dirServer->setDisabled(true);
    ui->download_file_button->setDisabled(true);
//--------------------------------------------------------------------//
    loadFile();
//--------------------------------------------------------------------//
    ui->load_file_button->setDisabled(false);
    ui->disconnect_button->setDisabled(false);
    ui->dirLocal->setDisabled(false);
    ui->dirServer->setDisabled(false);
    ui->download_file_button->setDisabled(false);
}

void MainWindow::on_download_file_button_clicked() {

    socket->write(("DOWNLOADFILE"));
}

void MainWindow::checkDir(){
    QByteArray dir = ui->dirServer->text().toUtf8();
    socket->write(("01|SPLIT|" + dir));
}

void MainWindow::loadFile(){

    QString dir = QString(ui->dirServer->text());
    QString name;
    QString data;

    for(int i = QString(ui->dirLocal->text()).length()-1; i > 0 ;i--){

        if(QString(ui->dirLocal->text())[i] == '\\' || QString(ui->dirLocal->text())[i] == '\/'){
            break;
        }
        name.push_front(QString(ui->dirLocal->text())[i]);
    }

    QFile file(ui->dirLocal->text());
    if(!file.open(QIODevice::ReadOnly)){
        return;
    }

    QString block;

    qDebug() << block;
    ui->LOADFILEPANEL->setText("Load - " + dir + "/" + name);
    ui->SERVERWRITE->setText("02|SPLIT|"+dir+"|SPLIT|"+name+"|SPLIT|"+block);
    int tempBytes = 0;
    while(!file.atEnd()){
    block = file.read((1024 - QString("02|SPLIT|"+dir+"|SPLIT|"+name+"|SPLIT|").length()));
    qDebug() << "Bytes sended - " << tempBytes;
    qDebug() << block;
    tempBytes += socket->write(QString("02|SPLIT|"+dir+"|SPLIT|"+name+"|SPLIT|"+block).toUtf8() , 1024);
    ui->LOADFILEPANEL->setText("Loading " + name + " " + QString::number(tempBytes) + "/" +
                               QString::number(file.size()));
    socket->waitForBytesWritten(10);
    }
    file.close();
}

void MainWindow::downloadFile(){

}

void MainWindow::disconnect(){
    this->socket->write(("disconnect"));
    this->socketDisconnect();
    ui->statusBar->setText("Disconnected...");
}

//COMMAND LIST
/*
 * 01 - CHECK DIR
 * 02 - LOAD FILE
 * 03 - DOWNLOAD FILE
 * 04 - FIND FILE
 * 05 - DELETE FILE
 * 97 - TEST3
 * 98 - TEST2
 * 99 - DISCONNECT
 */


void MainWindow::on_test2_clicked()
{
    QString data = "Oleg тут 123!@#(!*$)!(";
    socket->write(data.toUtf8());
}

void MainWindow::on_delete_file_button_clicked(){
    socket->write(QString("04|SPLIT|" + ui->dirServer->text()).toUtf8());
}
