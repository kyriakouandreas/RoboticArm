#ifndef SENSORTHREAD_H
#define SENSORTHREAD_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <QThread>
#include <QMutex>
#include "bmp180.h"
#include <wiringPi.h>


class SensorThread : public QThread
{
    Q_OBJECT
    void run();
    Qbmp180* bmp180sensor;
public:
    SensorThread():QThread(){bmp180sensor = new Qbmp180();}
    ~SensorThread(){delete bmp180sensor;}
signals:
    void sensevalues(float, int);
};

#endif // SENSORTHREAD_H
