#include "buttonsthread.h"

ButtonsThread::ButtonsThread(int p, int adr, ServoController* si2c):QThread(){
    BtnFlag = FALSE;
    m_speed = 5;
    MotorPos = p;
    servoi2c = si2c;
    address = adr;

    servoi2c->motorPos(address, MotorPos);

    wiringPiSetup();

    pinMode(LED, OUTPUT);
    pinMode(BUTTON_LEFT, INPUT);
    pinMode(BUTTON_RIGHT, INPUT);
}

void ButtonsThread::run(){
    while(BtnFlag){
        if(digitalRead(BUTTON_LEFT)){
                digitalWrite(LED, 1);
                delay(m_speed);
                //sleep(m_speed);

                if (MotorPos < servoi2c->getAngleLimit(address)){
                    MotorPos++;
                }
                this->mutex.lock();
                servoi2c->motorPos(address, MotorPos);
                this->mutex.unlock();

                emit updatePos(MotorPos);
        }
        if(digitalRead(BUTTON_RIGHT)){
                digitalWrite(LED, 1);
                delay(m_speed);
                //sleep(m_speed);

                if (MotorPos > servoi2c->getLowAngleLimit(address)){
                    MotorPos--;
                }
                this->mutex.lock();
                servoi2c->motorPos(address, MotorPos);
                this->mutex.unlock();

                emit updatePos(MotorPos);
        }
        digitalWrite(LED, 0);
        //emit updatePos(MotorPos);
    }//and while
emit keyrelease();
}
