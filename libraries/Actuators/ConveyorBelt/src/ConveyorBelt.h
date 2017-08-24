/*
  ConveyorBelt.h - Library for automated station conveyor belt.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef ConveyorBelt_h
#define ConveyorBelt_h

#include "Arduino.h"

class ConveyorBelt
{
  public:
    ConveyorBelt();
    ConveyorBelt(int, int, int, int);
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