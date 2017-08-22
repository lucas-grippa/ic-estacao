/*
  BarrierSensor.h - Library for automated station barrier sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef BarrierSensor_h
#define BarrierSensor_h

#include "Arduino.h"

class BarrierSensor
{
  public:
    BarrierSensor();
    BarrierSensor(int, int);
    int getLdrValue();
    void setCalibratedValue(int);
    int getCalibratedValue();
    void readLdrValue();
    void laserChangeState();
    bool lightBlocked();
    void barrierSensorCalibrate();
  private:
    int _laserPin;
    int _ldrPin;
    int _ldrValue;
    int _calibratedValue;
    int _laserState;
};

#endif