#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTcpSocket * socket;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();
    void mySlotConneted();
    void on_pushButton_clicked();
    void myReadSlot();
private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
