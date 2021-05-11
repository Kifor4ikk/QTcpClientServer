#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QTcpSocket>

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(int id ,QObject *parent = 0);
    void start();
signals:
    void started(QPrivateSignal);
    void finished(QPrivateSignal);

void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

    void checkDir(QString msg);
    void loadFileToServer(QString fileName , QString data);
    void deleteFile(QString file);

    void test1();
    void test2(QString data);
    QString getDataFromFile(QString path);
    void writeDataToFile(QString path , QString data);

private:
    QTcpSocket *socket;
    int socketDescriptor;
};

#endif // THREAD_H
