#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Init();

private slots:
    void on_pushButton_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_plainTextEdit_textChanged();

    void sendDatagram();

    void processDatagram();

    void processWHATDatagram();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
