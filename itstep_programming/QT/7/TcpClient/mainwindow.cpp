#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),
            SLOT(mySlotConneted()));
    connect(socket,SIGNAL(readyRead()),
            SLOT(myReadSlot()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),
            SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    socket->connectToHost("localhost",1212);
}

void MainWindow::mySlotConneted()
{
    ui->textEdit->append("Connected to Server");
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->append("You: " + ui->lineEdit->text());
    QTextStream stream(socket);
    stream << ui->lineEdit->text();
    ui->lineEdit->clear();
}

void MainWindow::myReadSlot()
{
    QTextStream stream(socket);
    QString str;
    stream >> str;
    ui->textEdit->append(str);
}
