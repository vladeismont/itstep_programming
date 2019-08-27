#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTcpServer * server;
    QSet<QTcpSocket*> socketsList;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void createSockets();
    void myReadSlot();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
