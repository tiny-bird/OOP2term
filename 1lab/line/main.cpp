#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    srand(time(NULL));
    w.initialization();
    w.make_new_points();
    w.remake();
    return a.exec();
}
