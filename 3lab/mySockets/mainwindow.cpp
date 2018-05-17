#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUdpSocket>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
QUdpSocket *socket;
int msg;
QString prevText;
QHostAddress groupAddress;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init(){
    groupAddress =  QHostAddress("127.0.0.1");
    socket = new QUdpSocket();
    if(socket->bind(QHostAddress::AnyIPv4, 45454)){
        ui->pushButton->setText("You are connected.");
    }
    else
    {
        ui->pushButton->setText("Something wrong...");
    }
    socket->joinMulticastGroup(groupAddress);
    connect(socket, SIGNAL(readyRead()), this, SLOT(processDatagram()));
}

void MainWindow::sendDatagram()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out << ui->plainTextEdit->toPlainText();
    prevText = ui->plainTextEdit->toPlainText();
     ui->pushButton->setText("Start to work with this document:");
   socket->writeDatagram(datagram, groupAddress, 45454);

}

void MainWindow::processDatagram()
{
    while (socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(), datagram.size());
        QString s="";
                char *d=datagram.data();
            for (int i=0;i<datagram.size();i++)
            {
                if(d!='\0');
                {
                    s+=d;
                }
              ++d;
            }
          ui->plainTextEdit->setPlainText(s);
 }
}


void MainWindow::processWHATDatagram(){
    /*
    QByteArray datagram;
    if(socket->readDatagram(datagram.data(), datagram.size()) != ui->plainTextEdit->toPlainText()){
        ui->plainTextEdit->setPlainText(datagram.data());
    }
*/
}
void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton2_clicked()
{
    QFile file("file.txt");
        file.open(QIODevice::WriteOnly);
        QTextStream out(&file);
        out << ui->plainTextEdit->toPlainText();
        file.close();
}

void MainWindow::on_pushButton3_clicked()
{

}

void MainWindow::on_plainTextEdit_textChanged()
{/*
    QString datagram = ui->plainTextEdit->toPlainText();
    socket->writeDatagram(datagram.data(), groupAddress, 45545);
    */
}
