#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "interfacesdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    devices = new Devices();
    // connect(ui->actionRefresh_Interfaces,SIGNAL(triggered(bool)),devices,SLOT(getDevices()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete devices;
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_startbutton_clicked()
{
    //StartCpature（）；
    //InactivateStart（）；
    //ActivatePause（）；
    //ActivateRestart（）；
}

void MainWindow::on_pausebutton_clicked()
{
    //PauseCapture();
    //InactivatePause(）；
    //ActivateStart();

}

void MainWindow::on_actionAbout_mSniffer_triggered()
{
    QMessageBox::about(this,"About mSniffer", "This is mini Sniffer powered by Qt!\n");
}

void MainWindow::on_actionRefresh_Interfaces_triggered()
{
//    devices->getDevices();
//    devices->printDevices();
    InterfacesDialog devicesdia;
    devicesdia.setModal(true);
    devicesdia.exec();
    devices->getDevices();
}
