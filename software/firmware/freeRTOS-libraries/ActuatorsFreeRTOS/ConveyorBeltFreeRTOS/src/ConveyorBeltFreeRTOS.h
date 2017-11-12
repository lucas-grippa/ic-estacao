/*
  ConveyorBeltFreeRTOS.h - Library for automated station conveyor belt.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef ConveyorBeltFreeRTOS_h
#define ConveyorBeltFreeRTOS_h

#include "Arduino.h"
#include "Arduino_FreeRTOS.h"

class ConveyorBeltFreeRTOS
{
  public:
    ConveyorBeltFreeRTOS();
    ConveyorBeltFreeRTOS(int, int, int, int);
    int getDirection();
    int getDelayTime();
    int getOnOffStatus();
    void setSpeed(int);
    void motorControlRight();
    void motorControlLeft();
    void setDirectionToRight();
    void setDirectionToLeft();
    void turnOn();
    void turnOff();
    void on();
    void off();
    void conveyorBeltControl();
  private:
    int _m1;
    int _m2;
    int _m3;
    int _m4;
    int _delayTime;
    int _direction;
    int _onOff;

};

#endif