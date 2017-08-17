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
    BarrierSensor(int laserPin, int ldrPin);
    void barrierSensorOn();
    void barrierSensorOff();
    int ldrRead();
    bool barrierSensorRead();
    void barrierSensorCalibrate();
  private:
    int _laserPin;
    int _ldrPin;
    int _ldrValue;
    int _calibratedValue;
};

#endif