#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCoreApplication>
#include <QtGui>
#include <QString>
#include <QThread>
#include <QMutex>
#include <QTimer>
#include <QTime>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "bmp180.h"
#include <wiringPi.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void resetTime(){time = QTime::currentTime();}
    ~MainWindow();

private slots:
    void on_pBtn_reset_clicked();

    void on_pBtn_close_clicked();

    void on_pBtn_setinitPos_clicked();

    void on_dial_MotorClamp_valueChanged(int value);

    void on_dial_MotorElbow_valueChanged(int value);

    void on_dial_MotorSB_valueChanged(int value);

    void on_dial_MotorSA_valueChanged(int value);

    void on_vSdr_speed_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QTime time;
};

#endif // MAINWINDOW_H
