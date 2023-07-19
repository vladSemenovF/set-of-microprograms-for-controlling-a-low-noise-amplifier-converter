#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //проверка сохраненных настроек
    QSettings settings("MyApp","MySettings");
    if(settings.contains("IP")&&settings.contains("Port"))
    {
        QString ip = settings.value("IP").toString();
        QString port = settings.value("Port").toString();

        ui->lineEditIP->setText(ip);
        ui->lineEditPort->setText(port);

        connectToDevice(ip,port);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonApply_clicked()
{
    QString ip = ui->lineEditIP->text();
    QString port = ui->lineEditPort->text();

    QSettings settings("MyApp","MySettings");
    settings.setValue("IP",ip);
    settings.setValue("Port",port);

    connectToDevice(ip,port);
}
void MainWindow::connectToDevice(const QString &ip,const QString &port){
    QHostAddress address(ip);
    quint16 portNumber = port.toUShort();

    QTcpSocket socket;
    socket.connectToHost(address,portNumber);

    if(socket.waitForConnected()){
        qDebug()<<"Успешное подключение к устройству";

        socket.disconnectFromHost();
    }else{
        qDebug()<<"Ошибка подключения к устройству: "<<socket.errorString();
    }
}

void MainWindow::showErrorMessage(const QString &message){
    QMessageBox::critical(this,"Error",message);
}
