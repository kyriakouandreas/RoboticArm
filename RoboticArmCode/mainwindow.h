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

//For the Reset actions
#define RESET_BUTTON 5
//Emergency LED
#define LED_RED 2


//INITIAL POSITION
#define CLAMP_POS 90
#define ELBOW_POS 90
#define SHOULDER_B_POS 90
#define SHOULDER_A_POS 90

//Array Position
#define CLAMP 0
#define ELBOW 1
#define SHOULDER_B 2
#define SHOULDER_A 3

//CLAMP limits
#define CLAMP_LOW_LIMIT 65
#define CLAMP_HIGH_LIMIT 125

//Amount until alram state
#define ALARM_TEMP_COUNT 5

//Global Functions
void resetPositionISR(void);

static int g_initPos[4];
static int g_motorAddr[4];

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

    void on_sBox_addrSA_valueChanged(int arg1);

    void on_sBox_addrSB_valueChanged(int arg1);

    void on_sBox_addrE_valueChanged(int arg1);

    void on_sBox_addrC_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QTime time;
    ServoController *servoi2c;
    SensorThread *sensorThread;
    ButtonsThread *btnThread;
    QMutex main_mutex;
    int initPos[4];
    int high_state; //To avoid the glitches that makes false reset

    void resetActions();
    void setDials(bool);
};

#endif // MAINWINDOW_H
