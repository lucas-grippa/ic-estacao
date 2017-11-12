/*
  SwitchSensor.h - Library for automated station switch sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef SwitchSensor_h
#define SwitchSensor_h

#include "Arduino.h"

class SwitchSensor
{
  public:
    SwitchSensor();
    SwitchSensor(int);
    int getSwitchPin();
    int getSwitchState();
    void readSwitchState();
    bool isItHigh();
    bool isItLow();
  private:
    int _switchPin;
    int _switchState;
    bool _high;
    bool _low;

};

#endif