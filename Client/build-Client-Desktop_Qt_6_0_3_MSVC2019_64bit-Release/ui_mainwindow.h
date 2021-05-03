/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *ip_line;
    QTextBrowser *IP;
    QTextBrowser *PORT;
    QLineEdit *port_line;
    QTextBrowser *TWOPOINTS;
    QPushButton *connect_button;
    QPushButton *disconnect_button;
    QPushButton *load_file_button;
    QPushButton *download_file_button;
    QTextBrowser *statusBar;
    QPushButton *TestMessage;
    QTextBrowser *STATUS;
    QTextBrowser *SERVERWRITE;
    QPushButton *test2;
    QMenuBar *menubar;
    QMenu *menuClient_explorer_v1_0;
    QMenu *menu_1_1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ip_line = new QLineEdit(centralwidget);
        ip_line->setObjectName(QString::fromUtf8("ip_line"));
        ip_line->setGeometry(QRect(520, 160, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Hobo Std"));
        font.setPointSize(14);
        font.setBold(false);
        ip_line->setFont(font);
        IP = new QTextBrowser(centralwidget);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setGeometry(QRect(520, 130, 171, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Hobo Std"));
        IP->setFont(font1);
        PORT = new QTextBrowser(centralwidget);
        PORT->setObjectName(QString::fromUtf8("PORT"));
        PORT->setGeometry(QRect(710, 130, 71, 31));
        PORT->setFont(font1);
        port_line = new QLineEdit(centralwidget);
        port_line->setObjectName(QString::fromUtf8("port_line"));
        port_line->setGeometry(QRect(710, 160, 71, 41));
        port_line->setFont(font);
        TWOPOINTS = new QTextBrowser(centralwidget);
        TWOPOINTS->setObjectName(QString::fromUtf8("TWOPOINTS"));
        TWOPOINTS->setGeometry(QRect(690, 160, 21, 41));
        connect_button = new QPushButton(centralwidget);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        connect_button->setGeometry(QRect(560, 210, 201, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Hobo Std"));
        font2.setPointSize(26);
        font2.setBold(false);
        connect_button->setFont(font2);
        disconnect_button = new QPushButton(centralwidget);
        disconnect_button->setObjectName(QString::fromUtf8("disconnect_button"));
        disconnect_button->setGeometry(QRect(560, 480, 201, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Comic Sans MS"));
        font3.setPointSize(26);
        font3.setBold(true);
        disconnect_button->setFont(font3);
        load_file_button = new QPushButton(centralwidget);
        load_file_button->setObjectName(QString::fromUtf8("load_file_button"));
        load_file_button->setGeometry(QRect(560, 270, 201, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Hobo Std"));
        font4.setPointSize(20);
        load_file_button->setFont(font4);
        download_file_button = new QPushButton(centralwidget);
        download_file_button->setObjectName(QString::fromUtf8("download_file_button"));
        download_file_button->setGeometry(QRect(560, 330, 201, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Hobo Std"));
        font5.setPointSize(22);
        download_file_button->setFont(font5);
        statusBar = new QTextBrowser(centralwidget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setGeometry(QRect(520, 70, 261, 51));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Hobo Std"));
        font6.setPointSize(12);
        statusBar->setFont(font6);
        TestMessage = new QPushButton(centralwidget);
        TestMessage->setObjectName(QString::fromUtf8("TestMessage"));
        TestMessage->setGeometry(QRect(560, 390, 201, 51));
        TestMessage->setFont(font4);
        STATUS = new QTextBrowser(centralwidget);
        STATUS->setObjectName(QString::fromUtf8("STATUS"));
        STATUS->setGeometry(QRect(550, 20, 201, 51));
        STATUS->setFont(font4);
        SERVERWRITE = new QTextBrowser(centralwidget);
        SERVERWRITE->setObjectName(QString::fromUtf8("SERVERWRITE"));
        SERVERWRITE->setGeometry(QRect(10, 10, 481, 291));
        SERVERWRITE->setFont(font6);
        test2 = new QPushButton(centralwidget);
        test2->setObjectName(QString::fromUtf8("test2"));
        test2->setGeometry(QRect(350, 390, 201, 51));
        test2->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        menuClient_explorer_v1_0 = new QMenu(menubar);
        menuClient_explorer_v1_0->setObjectName(QString::fromUtf8("menuClient_explorer_v1_0"));
        menu_1_1 = new QMenu(menubar);
        menu_1_1->setObjectName(QString::fromUtf8("menu_1_1"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuClient_explorer_v1_0->menuAction());
        menubar->addAction(menu_1_1->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ip_line->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        IP->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Hobo Std'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">IP</span></p></body></html>", nullptr));
        PORT->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Hobo Std'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">PORT</span></p></body></html>", nullptr));
        port_line->setText(QCoreApplication::translate("MainWindow", "1488", nullptr));
        TWOPOINTS->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600;\">:</span></p></body></html>", nullptr));
        connect_button->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        disconnect_button->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        load_file_button->setText(QCoreApplication::translate("MainWindow", "Load file", nullptr));
        download_file_button->setText(QCoreApplication::translate("MainWindow", "Download file", nullptr));
        statusBar->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Hobo Std'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Status here...</span></p></body></html>", nullptr));
        TestMessage->setText(QCoreApplication::translate("MainWindow", "TestButton", nullptr));
        STATUS->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Hobo Std'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Status</p></body></html>", nullptr));
        SERVERWRITE->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Hobo Std'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:28pt;\">Server will write here;</span></p></body></html>", nullptr));
        test2->setText(QCoreApplication::translate("MainWindow", "Test2", nullptr));
        menuClient_explorer_v1_0->setTitle(QCoreApplication::translate("MainWindow", "Client explorer v1.0", nullptr));
        menu_1_1->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\321\201\321\202 1 \320\264\321\203\320\261\320\273\321\214 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
