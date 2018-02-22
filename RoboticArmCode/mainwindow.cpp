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

void MainWindow::on_pBtn_reset_clicked()
{

}

void MainWindow::on_pBtn_close_clicked()
{

}

void MainWindow::on_pBtn_setinitPos_clicked()
{

}

void MainWindow::on_dial_MotorClamp_valueChanged(int value)
{

}

void MainWindow::on_dial_MotorElbow_valueChanged(int value)
{

}

void MainWindow::on_dial_MotorSB_valueChanged(int value)
{

}

void MainWindow::on_dial_MotorSA_valueChanged(int value)
{

}

void MainWindow::on_vSdr_speed_valueChanged(int value)
{

}
