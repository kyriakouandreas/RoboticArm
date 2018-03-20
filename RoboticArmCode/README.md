# Qt-RPI_Robotic Arm Shell

The porpouse of this shell is to incorporate on it the advances on each phase. To be able to make a branch of it and 
after performing Unit Test to each part it can then be incorporated to the master branch. 

At the end of the process in here we will have the final code and Software instructions to make it 
work.
The hardware instructions will be in other README file on the master branch and on The WIKI. More information about code structure is on the WIKI. Here are the installation instructions and status on the code.

5/3/2018:
The present program incorporate the reading and display of the readings of the sensors. Also, the controll of the motors using the servo slave i2c and the use of two buttons to control any of the motors select it by the user.

20/3/2018 (v3):
It has fix some GUI updates missing. First try together with the hardware mounting on the PCB, no bread board anymore. It still missing the close loop for the pressure. So, if try this version (Also on YouTube https://www.youtube.com/watch?v=8hPd8vS8S5o) watch for the pressure increase, two hPa above the value when no load is enough for a staedy grap.


# Making it work

Hardware
-----
Go to Hardware instructions for instalation of this project

Software
-----

To clone the git repository:

    git clone https://github.com/kyriakouandreas/RoboticArm.git  

To build:

    cd RoboticArm/RoboticArmCode
    qmake
    make

To run

    ./RoboticArm_Qt-RPI


