/*
  ColorSensor.h - Library for automated station color sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/
#ifndef ColorSensor_h
#define ColorSensor_h

#include "Arduino.h"

class ColorSensor
{
  public:
    ColorSensor();
    ColorSensor(int, int, int, int, int);
    int getDataRed();
    int getDataGreen();
    int getDataBlue();
    void readRed();
    void readGreen();
    void readBlue();
    void readColors();
    bool isItRed();
    bool isItGreen();
    bool isItBlue();
  private:
    int _s0Pin;
    int _s1Pin;
    int _s2Pin;
    int _s3Pin;
    int _sensorDataPin;
    int _dataRed;
    int _dataGreen;
    int _dataBlue;
    bool _red;
    bool _green;
    bool _blue;
};

#endif