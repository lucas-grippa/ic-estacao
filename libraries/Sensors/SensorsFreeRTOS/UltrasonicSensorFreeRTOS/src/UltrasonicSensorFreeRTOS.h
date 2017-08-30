/*
  UltrasonicSensorFreeRTOS.h - Library for automated station ultrasonic sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef UltrasonicSensorFreeRTOS_h
#define UltrasonicSensorFreeRTOS_h

#include "Arduino.h"
#include "Arduino_FreeRTOS.h"

class UltrasonicSensorFreeRTOS
{
  public:
    UltrasonicSensorFreeRTOS();
    UltrasonicSensorFreeRTOS(int, int);
    float getDistance();
    float getInitialDistance();
    void readDistance();
    void readDistanceCalibrate();
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