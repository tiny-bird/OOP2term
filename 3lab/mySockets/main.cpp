#include "mainwindow.h"
#include <QApplication>
#include <QUdpSocket>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.Init();
    return a.exec();
}
