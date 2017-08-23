/*
  AutomatedStation.h - Library for didatic automated station.
  Created by Lucas Grippa Marques, August 22, 2017.
  Released into the public domain.
*/

#ifndef AutomatedStation_h
#define AutomatedStation_h

#include "Arduino.h"
#include "Thread.h"
#include "ThreadController.h"
#include "BarrierSensor.h"

class AutomatedStation
{
  public:
    AutomatedStation();
  private:
    BarrierSensor barrierSensor1;
    
};

#endif