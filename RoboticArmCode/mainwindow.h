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
#include "servoslavei2c.h"
#include "sensorthread.h"
#include "buttonsthread.h"
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

    void on_valuesread(float,int);

    void on_keyrelease();

    void on_updatepos(int);

    void on_rBtn_MtrSA_clicked();

    void on_rBtn_MtrSB_clicked();

    void on_rBtn_MtrElbow_clicked();

    void on_rBtn_MtrClaw_clicked();

    void on_rBtn_MtrNone_clicked();

    void on_vSdr_speed_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QTime time;
    ServoController *servoi2c;
    SensorThread *sensorThread;
    ButtonsThread *btnThread;
    QMutex main_mutex;
};

#endif // MAINWINDOW_H
