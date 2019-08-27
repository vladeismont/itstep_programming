#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyThread * thread = new MyThread(this);
    MyThread * thread2 = new MyThread(this);
    thread->start();
    thread2->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
