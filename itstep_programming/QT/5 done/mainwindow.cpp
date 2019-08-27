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
    //QDomDocument dom;
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

void MainWindow::on_actionSave_triggered()
{
    QFile file("D:/qt-ptoj/myxml.xml");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        return;
    }
    else{
        QTextStream stream(&file);
        stream<<dom.toString();
        file.close();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QDomElement elem =dom.createElement("persona");
    dom.documentElement().appendChild(elem);

    QDomElement elem2=dom.createElement("name");
    QDomText newNomeText = dom.createTextNode(ui->lineEdit->text());
    elem2.appendChild(newNomeText);
    elem.appendChild(elem2);

    QDomElement elem3=dom.createElement("age");
    QDomText newNomeText2 = dom.createTextNode(ui->lineEdit_2->text());
    elem3.appendChild(newNomeText2);
    elem.appendChild(elem3);

    QDomElement elem4=dom.createElement("color");
    QDomText newNomeText3 = dom.createTextNode(ui->lineEdit_3->text());
    elem4.appendChild(newNomeText3);
    elem.appendChild(elem4);
}
