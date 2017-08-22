/*
  Belt.h - Library for automated station barrier sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef Belt_h
#define Belt_h

#include "Arduino.h"

class Belt
{
  public:
    Belt(int laserPin, int ldrPin);
    void beltOnRight();
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