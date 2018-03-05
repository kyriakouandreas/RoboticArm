#ifndef BUTTONSTHREAD_H
#define BUTTONSTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QApplication>
#include <QMessageBox>
#include <wiringPi.h>
#include "servoslavei2c.h"

//GPIO related
#define LED 7
#define BUTTON_LEFT 3
#define BUTTON_RIGHT 0

class ButtonsThread : public QThread{
    Q_OBJECT
    void run();
    bool BtnFlag;
    int m_speed;
    int MotorPos;
    int address;
    ServoController* servoi2c;
    QMutex mutex;
public:
    ButtonsThread(int, int, ServoController*);
    void setBtnFlag(bool s){BtnFlag = s;}
    void setmspeed(int _s){m_speed = _s;}
    void setPosAddress(int _p, int _adr){address = _adr; MotorPos = _p;}


signals:
    void keyrelease();
    void updatePos(int);
};

#endif // BUTTONSTHREAD_H
