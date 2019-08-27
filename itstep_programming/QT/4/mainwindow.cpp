#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mymodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto model = new MyModel(this);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
