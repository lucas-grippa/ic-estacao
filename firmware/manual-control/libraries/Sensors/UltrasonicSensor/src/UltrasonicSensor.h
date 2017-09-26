/*
  UltrasonicSensor.h - Library for automated station ultrasonic sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h

#include "Arduino.h"

class UltrasonicSensor
{
  public:
    UltrasonicSensor();
    UltrasonicSensor(int, int);
    float getDistance();
    float getInitialDistance();
    void readDistance();
    void ultrasonicSensorCalibrate();
    float getHeight();
    bool isItShort();
    bool isItHigh();
  private:
    int _trigPin;
    int _echoPin;
    long _duration;
    float _distance;
    float _initialDistance;
    float _height;
    bool _short;
    bool _high;
};

#endif