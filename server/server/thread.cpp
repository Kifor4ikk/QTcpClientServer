#include "thread.h"
#include <QDir>


QString Thread::getDataFromFile(QString path){

    QFile file(path);
    if(!file.exists()){
        qDebug() << "File do not exist";
        socket->write("File do not exist");
        return "";
    }
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "File closed";
        return "";
    }
    return QString(file.readAll());
}

void Thread::writeDataToFile(QString path,QString data){

    QFile file(path);
    if(file.exists()){
        qDebug() << "File already exist";
        socket->write("File already exist");
        return;
    }
    if(file.open(QIODevice::WriteOnly)){
        file.write(data.toUtf8());
    }
}


Thread::Thread(int ID ,QObject *parent):
    QThread(parent) {
    this->socketDescriptor = ID;
}
//зашифровать
QByteArray encrypt (QByteArray msg) {
    for(int i = 0; i < msg.size();i++)
        msg[i] = msg[i]+14;
    return msg;
}
//дешифровать
QByteArray decrypt(QByteArray msg) {
    for(int i = 0; i < msg.size();i++)
        msg[i] = msg[i]-14;
    return msg;
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
    socket->write( ("You are connected!"));

    exec();
}


void saveDataToFile(QString file, QByteArray data){
    QFile temp(file);

    temp.open(QFile::WriteOnly);
    temp.write(data);
    temp.close();
}

void Thread::readyRead(){

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

    if(command[0] == "01"){
        checkDir(command[1]);
    }
    if(command[0] == "02"){
        QString temp;
        for(int i = 0; i < command.length();i++){

            if(command[i] == command[0] || command[i] == command[1] || command[i] == command[2]){

            }
            else{
                temp += command[i];
            }
        }
        loadFileToServer(command[1], temp.toUtf8() );
        temp.clear();
    }
    if(command[0] == "03"){

    }
    if(command[0] == "04"){
        deleteFile(command[1]);
    }
    if(command[0] == "97"){
        test1();
    }
    if(command[0] == "98"){
        test2(command[1]);
    }
    if(command[0] == "99"){
        disconnected();
    }
//---------------------//

}

void Thread::deleteFile(QString fileName){
     QFile file(fileName);

     if(file.exists() && file.open(QIODevice::ReadWrite)){
        file.remove();
        socket->write(QString("File " + fileName + " succesfully deleted").toUtf8());
     }
     else{
        socket->write(QString("File " + fileName + " not exist").toUtf8());
     }

}

void Thread::checkDir(QString dataInfo){
        //CUT DIRECTORY FROM MESSAGE
        QByteArray data = dataInfo.toUtf8();
        qDebug() << "User: " << socketDescriptor << " open direction " << data;
        QDir directory(data);
        QString files;
        QStringList fileList = directory.entryList(QStringList(),QDir::AllEntries);
        foreach(QString fileName, fileList){
            files += fileName + '\n';
        }
        socket->write((files.toUtf8()));
        qDebug() << files;
}

void Thread::loadFileToServer(QString fileName , QString data){
    qDebug() << socketDescriptor << " transfering data";
    QFile file2(fileName);
    QTextStream file(&file2);
    if(file2.open(QIODevice::Append | QIODevice::WriteOnly)){
        file2.write(data.toUtf8());
        //qDebug() << data.toUtf8();
        file2.close();
        socket->write(("Successfuly loaded - " + fileName.toUtf8()));
    }else{
        socket->write("Something go wrong");
        return;
    }
}


void Thread::disconnected(){
    socket->write(("You was disconnected"));
    socket->disconnect();
    qDebug() << "User: "<<  socketDescriptor << " was disconnected";
    exit(0);
}


void Thread::test1(){

        QString files;
        QDir directory("C:\\Users\\Кифор\\Desktop");
        QStringList fileList = directory.entryList(QStringList() , QDir::AllEntries);
        foreach(QString filename, fileList) {
            files += filename + '\n';
        }
        qDebug() << files.toUtf8()  ;
        QByteArray data = files.toUtf8();
        socket->write((data));

}

void Thread::test2(QString data){
        socket->write(data.toUtf8());
}
//WORK WITH FILE
