#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include<QTcpSocket>

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(int id ,QObject *parent = 0);
    void start();
signals:

void error(QTcpSocket::SocketError socketerror);

public slots:

public slots:

    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    int socketDescriptor;
};

#endif // THREAD_H
