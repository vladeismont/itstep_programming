#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtXml>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void showXML(QDomNode&);
    QDomDocument dom;
};

#endif // MAINWINDOW_H
