/*
  LinearDCActuator.h - Library for automated station linear DC actuator.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#ifndef LinearDCActuator_h
#define LinearDCActuator_h

#include "Arduino.h"
#include "SwitchSensor.h"

class LinearDCActuator
{
  public:
    LinearDCActuator();
    LinearDCActuator(int, int, int, int);
    int getDirection();
    void goForward();
    void goBackward();
    void forward();
    void backward();
    bool isItForward();
    bool isItBackward();
    void linearDCActuatorControl();
  private:
    SwitchSensor forwardSensor;
    SwitchSensor backwardSensor;
    int _m1;
    int _m2;
    int _direction;
    bool _forward;
    bool _backward;

};

#endif