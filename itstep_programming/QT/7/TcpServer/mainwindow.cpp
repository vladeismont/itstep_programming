#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,1212);
    connect(server,SIGNAL(newConnection()),
            SLOT(createSockets()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),
            SLOT(on_pushButton_clicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createSockets()
{
    QTcpSocket * socket = server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),SLOT(myReadSlot()));
    connect(socket,SIGNAL(disconnected()),
            socket,SLOT(deleteLater()));
    socketsList.insert(socket);
}

void MainWindow::myReadSlot()
{
    QTcpSocket * socket =
            reinterpret_cast<QTcpSocket *>(sender());
    QTextStream stream(socket);
    QString str;
    stream >> str;
    ui->textEdit->append(str);
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->append("You: " + ui->lineEdit->text());
    for(auto i : socketsList)
    {
        if(i->isWritable())
        {
            QTextStream stream(i);
            stream << ui->lineEdit->text();
        }
    }
    ui->lineEdit->clear();
}
