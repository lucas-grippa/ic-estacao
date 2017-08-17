/*
  BarrierSensor.cpp - Library for automated station barrier sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "BarrierSensor.h"

BarrierSensor::BarrierSensor()
{}

BarrierSensor::BarrierSensor(int laserPin, int ldrPin)
{
    pinMode(laserPin, OUTPUT);
    this->_laserPin = laserPin;
    this->_ldrPin = ldrPin;
    this->_ldrValue = 0;
    this->barrierSensorCalibrate();
}

 void BarrierSensor::barrierSensorOn()
 {
    digitalWrite(this->_laserPin, HIGH);
 }

 void BarrierSensor::barrierSensorOff()
 {
    digitalWrite(this->_laserPin, LOW);
 }

 int BarrierSensor::ldrRead()
 {  
    this->_ldrValue = analogRead(_ldrPin);
    return (this->_ldrValue);
 }

bool BarrierSensor::barrierSensorRead()
{
    this->_ldrValue = analogRead(this->_ldrPin);

    if(this->_ldrValue <= this->_calibratedValue){
        return false;
    }else{
        return true;
    }
}

void BarrierSensor::barrierSensorCalibrate()
{
    int minValue, maxValue;

    barrierSensorOff();
    minValue = analogRead(this->_ldrPin);
    delay(500);
    barrierSensorOn();
    maxValue = analogRead(this->_ldrPin);
    delay(500);

    this->_calibratedValue = (((maxValue - minValue)/2) + minValue);

}