#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket* socket;
    QByteArray Data;

public slots:
    void socketReady();
    void socketDisconnect();

private slots:

    void on_connect_button_clicked();

    void on_disconnect_button_clicked();

    void on_TestMessage_clicked();

    void on_test2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
