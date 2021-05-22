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

    //Buttons
    void on_connect_button_clicked();

    void on_disconnect_button_clicked();

    void on_ip_line_textChanged(const QString &arg1);

    void on_port_line_textChanged(const QString &arg1);

    void on_download_file_button_clicked();

    void on_load_file_button_clicked();

    void on_loadDir_clicked();


    //actions
    void checkDir();
    //
    void sendFile();
    //
    void downloadFile();
    void disconnect();

    //TESTS
    void on_test2_clicked();
    void loadFileToClient(QString fileName , QByteArray data);
    void on_delete_file_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
