#include "sensorthread.h"

void SensorThread::run(){
    while(1){
        float t = bmp180sensor->read_temperature();
        int p = bmp180sensor->read_pressure();
        emit sensevalues(t, p);
        msleep(50);
    }
}
