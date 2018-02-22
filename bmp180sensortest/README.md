# Qt-RPI_bmp180sensor

An example program using Qt widgets and Raspberry Pi to read from a bmp180 sensor for temperature and pressure. 
It will diplay the temperature on a graph. For accessing the gpio is use the wiringPi library. To comunicate with the sensor is use the I2C serial protocol.

* [Qt5 Homepage](https://www.qt.io/)
* [wiringPiI2C](http://wiringpi.com/reference/i2c-library/)
* [BMP180](http://www.haoyuelectronics.com/Attachment/GY-68/BMP180.pdf)

# Making it work

Hardware
--------------
Power ->   pin 3.3V

SDA   -> GPIO2 (8)

SCL   -> GPIO3 (9)

GND   -> any ground pin

Software
-----

To clone the git repository:

    git clone https://github.com/DevGero/Qt-RPI_ServoThread.git    

To build:

    cd Qt-RPI_ServoThread/ServoCode
    qmake
    make

To run it needs to be as root user to be able to access the PWM.

    sudo ./Servo_Butons_Threads

Possible trouble
----------------

If it screen an error of not been able to access the interface resources type:

    sudo cp /home/pi/.Xauthority /root

and try again.
