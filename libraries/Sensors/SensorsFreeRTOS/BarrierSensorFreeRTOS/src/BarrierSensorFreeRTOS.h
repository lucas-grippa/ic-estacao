/*
  BarrierSensorFreeRTOS.h - Library for automated station barrier sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef BarrierSensorFreeRTOS_h
#define BarrierSensorFreeRTOS_h
#include "Arduino_FreeRTOS.h"

#include "Arduino.h"

class BarrierSensorFreeRTOS
{
  public:
    BarrierSensorFreeRTOS();
    BarrierSensorFreeRTOS(int, int);
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