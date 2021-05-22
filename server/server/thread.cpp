#include "thread.h"
#include <QDir>
#include <QFile>

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

void Thread::readyRead(){

    QByteArray data = QByteArray(socket->readAll());
    //socket->write(("DIR;")+ui->dirServer->text().toUtf8()+";"+name.toUtf8());

    QString cmd = QString::fromUtf8(data.data(), data.length());
    QStringList command = cmd.split("|SPLIT|");

    for(int i = 0; i < command.size(); i++){

        if(command[i].length() > 100){
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

    if(command[0] == "01COMMAND"){
        checkDir(command[1]);
    }
    if(command[0] == "02COMMAND"){
        QString temp;
        for(int i = 0; i < command.length();i++){

            if(command[i] == command[0] || command[i] == command[1]){

            }
            else{
                temp += command[i];
            }
        }
        loadFileToServer(command[1], temp.toUtf8());
        temp.clear();
    }
    if(command[0] == "03COMMAND"){
        sendFileToClient(command[1],command[2]);
    }
    if(command[0] == "04COMMAND"){
        deleteFile(command[1]);
    }
    if(command[0] == "97COMMAND"){
        test1();
    }
    if(command[0] == "98COMMAND"){
        test2(command[1]);
    }
    if(command[0] == "99COMMAND"){
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

void Thread::sendFileToClient(QString path , QString pathOnClient){
    QFile file(path);
    QString name;
    //GetName
    for(int i = QString(path).length()-1; i > 0 ;i--){
        if(QString(path)[i] == '\\' || QString(path)[i] == '\/'){
            break;
        }
        name.push_front(QString(path)[i]);
    }

    if(!file.exists()){
        socket->write("File do not exist");
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        socket->write("Bad file");
        return;
    }
    long tempBytes = 0;
    int bytesToSend = 1024; // im not shure
    QByteArray block;

    while(!file.atEnd()){
        if(tempBytes + bytesToSend >= file.size()){
            block = (file.read(file.size() - tempBytes));
            tempBytes += (file.size() - tempBytes);

        } else{
            block = (file.read(bytesToSend));
            tempBytes += bytesToSend;
        }
        socket->write(("03COMMAND|SPLIT|"+ pathOnClient + name + "|SPLIT|" + block.toBase64() +"|SPLIT|").toUtf8());
        socket->waitForReadyRead(10);
        socket->write((name + " loaded " + QString::number(tempBytes) + " / " + QString::number(file.size())).toUtf8());
        socket->waitForReadyRead(10);
    }
    file.close();
    socket->write("File loaded...");
}

void Thread::checkDir(QString dataInfo){
        //CUT DIRECTORY FROM MESSAGE
        QByteArray data = dataInfo.toUtf8();
        qDebug() << "User: " << socketDescriptor << " open direction " << data;
        QFile file(data);
        QDir directory(data);
        QString files;
        QStringList fileList = directory.entryList(QStringList(),QDir::AllEntries);
        foreach(QString fileName, fileList){
            files += fileName + '\n';
        }
        socket->write((files.toUtf8()));
        qDebug() << files;
}



void Thread::loadFileToServer(QString fileName , QByteArray data){
    qDebug() << socketDescriptor << " transfering data";
    QFile file2(fileName);
    if(file2.open(QIODevice::Append | QIODevice::WriteOnly)){
        file2.write(QByteArray::fromBase64(data));
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
