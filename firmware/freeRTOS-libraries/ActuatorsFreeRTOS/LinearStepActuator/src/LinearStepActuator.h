/*
  LinearStepActuator.h - Library for automated station linear step actuator.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#ifndef LinearStepActuator_h
#define LinearStepActuator_h

#include "Arduino.h"
#include "SwitchSensor.h"
#include "Stepper.h"


class LinearStepActuator
{
  public:
    LinearStepActuator();
    LinearStepActuator(int, int, int, int, int, int);
    int getDirection();
    void setSpeed(int);
    int getSpeed();
    int getStepModeStatus();
    void stepModeOn();
    void stepModeOff();
    int getSteps();
    void goForward();
    void goForwardSteps(int);
    void goBackward();
    void goBackwardSteps(int);
    void forward();
    void forwardSteps();
    void backward();
    void backwardSteps();
    bool isItForward();
    bool isItBackward();
    void linearStepActuatorControl();
  private:
    SwitchSensor forwardSensor;
    SwitchSensor backwardSensor;
    Stepper motor;
    int _m1;
    int _m2;
    int _m3;
    int _m4;
    int _motorSteps;
    int _speed;
    int _direction;
    int _steps;
    int _stepMode;
    bool _forward;
    bool _backward;

};

#endif