#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include "threads.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow , public QTcpServer
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    explicit MainWindow(QObject *parent = 0);
    void startServer();

protected:
    void incomingConnection(qintptr socketDescriptor);
    void reciveFrom(qintptr socketDescriptor);
    void disconnected();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
