# Robotic Arm

## Introduction 
This project aims to provide a practical tool semiautomated to work in control environments as labs where the contamination of the human hand, for example, is not allowed in certain samples. The movement is control by a user through an interface and physical buttons as well. 
The semiautomated is related to the constant sensing of the temperature for keeping the hand save from sudden temperatures raisings. Besides, the sensing of the pressure is for controlling the strength of the grap perform for the clamp.

It can also be an intelligent crane for a Kid and a nice DIY project. Also, an example of using threads in raspberry pi using c++ and Qt

[ see our wiki! ](https://github.com/kyriakouandreas/RoboticArm/wiki)

[ watch a video of the finished project](https://youtu.be/8hPd8vS8S5o)

![](https://raw.githubusercontent.com/kyriakouandreas/RoboticArm/master/render2.JPG)

## Contributors 
- Sharraf Eltelbani
- Daniel Alvarez Geronimo
- Andreas Kyrikaou

## Parts 
- 4*servos the model             (LewanSoul LD-3015MG)
- 1*metallic claw                (MagiDeal Aluminium Mechanical Robotic Arm Clamp Claw Mount)
- some 3D printed parts          (look in the mech des folder to see them)
- i2c controlled servo driver ic (from [hobby electronics](http://www.hobbytronics.co.uk/servo-controller-12ch-ht))
- 3*push buttons  
- raspberry pi 3
- pcb's                          (look at the pcb folder for more detail)

## Requirments
- Control each motor individually on the interface.
- Allow the possibility of controlling both motors selected by the user with physicals buttons to perform more complex movements
- The values of temperature should show on the screen to keep a record of the trends of it
- Security actions as Resets buttons on both, the interface and the physical panel
- Indicators of the process
- Portable and hand shape
- Protect the sample from being accidentally crushed by the user
- Good responsiveness to commands 

