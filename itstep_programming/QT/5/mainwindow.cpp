#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString path = QFileDialog::getOpenFileName();
    if(path.isEmpty()) return;
    QDomDocument dom;
    QFile file(path);
    if(file.open(QFile::ReadOnly)){
        if(dom.setContent(&file)){
           QDomElement elem = dom.documentElement();
           showXML(elem);
        }
    }

    file.close();
}

void MainWindow::showXML(QDomNode & node)
{
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull())
    {
        if(domNode.isElement()){
            QDomElement elem = domNode.toElement();
            if(!elem.isNull()){
                ui->label->setText(ui->label->text()+
                                   elem.text()+'\n');
            }
        }
        showXML(domNode);
        domNode = domNode.nextSibling();
    }
}
