/*
  AutomatedStation.h - Library for didatic automated station.
  Created by Lucas Grippa Marques, August 22, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "AutomatedStation.h"

AutomatedStation::AutomatedStation()
{
    ThreadController cpu;
    Thread sensorReading;
    this->barrierSensorsSetup();

    cpu.run();
}

void AutomatedStation::barrierSensorsSetup(){
    barrierSensor1 = BarrierSensor(0, 7);
    barrierSensor1.barrierSensorCalibrate();
    sensorReading.setInterval(50);
    sensorReading.onRun(this->barrierSensorReading());

    cpu.add(&sensorReading);

}



void AutomatedStation::barrierSensorReading(){
    barrierSensor1.readLdrValue();

}