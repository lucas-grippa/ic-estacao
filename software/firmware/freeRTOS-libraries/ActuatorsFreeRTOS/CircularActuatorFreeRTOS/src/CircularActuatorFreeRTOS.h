/*
  CircularActuatorFreeRTOS.h - Library for automated station circular actuator.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef CircularActuatorFreeRTOS_h
#define CircularActuatorFreeRTOS_h

#include "Arduino.h"
#include "SwitchSensor.h"
#include "Arduino_FreeRTOS.h"

class CircularActuatorFreeRTOS
{
  public:
    CircularActuatorFreeRTOS();
    CircularActuatorFreeRTOS(int, int, int, int, int, int, int);
    int getDelayTime();
    int getPosition();
    void setSpeed(int);
    void motorControl();
    void toPosition1();
    void goToPosition1();
    void toPosition2();
    void goToPosition2();
    void toPosition3();
    void goToPosition3();
    bool isItInPosition1();
    bool isItInPosition2();
    bool isItInPosition3();
    void off();
    void circularActuatorControl();
  private:
    SwitchSensor position1;
    SwitchSensor position2;
    SwitchSensor position3;
    int _m1;
    int _m2;
    int _m3;
    int _m4;
    int _position;
    bool _position1;
    bool _position2;
    bool _position3;
    int _delayTime;
    int _direction;

};

#endif