/*
  BarrierSensor.cpp - Library for automated station barrier sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "BarrierSensor.h"

BarrierSensor::BarrierSensor()
{}

BarrierSensor::BarrierSensor(int ldrPin, int laserPin)
{
    this->_ldrPin = ldrPin;
    pinMode(this->_ldrPin, INPUT);
    this->_ldrValue = 0;

    this->_laserPin = laserPin;
    pinMode(this->_laserPin, OUTPUT);
    digitalWrite(this->_laserPin, HIGH);  
    this->_laserState = 1;

    //this->barrierSensorCalibrate();
}

/*
    Returns the cached ldr value
*/ 
int BarrierSensor::getLdrValue(){
	return this->_ldrValue;
}

void BarrierSensor::setCalibratedValue(int calibratedValue){
    this->_calibratedValue = calibratedValue;
}

/*
	Returns the cached ldr calibrated value
*/
int BarrierSensor::getCalibratedValue(){
    return this->_calibratedValue;
}

 /*
     Read ldr value
*/
void BarrierSensor::readLdrValue(){
	this->_ldrValue = analogRead(this->_ldrPin);
	//return this->getLdrValue();
}

 /*
	 Change laser state 0N/OFF
*/
void BarrierSensor::laserChangeState(){
    if(_laserState == 1){
         digitalWrite(_laserPin, LOW); 
         this->_laserState = 0;
    }else{
         digitalWrite(_laserPin, HIGH);
         this->_laserState = 1;
    }

}

 /*
	Return true if light is blocked
*/
bool BarrierSensor::lightBlocked(){
    if(this->getLdrValue() <= this->getCalibratedValue()){
        return true;
    }else{
        return false;
    }
        
}

void BarrierSensor::barrierSensorCalibrate()
{
    int minValue = 0;
    int maxValue = 0;

    delay(1000);
    this->laserChangeState();
    delay(500);
    this->readLdrValue();
    delay(500);
    minValue = this->getLdrValue();
    this->laserChangeState();
    delay(500);
    this->readLdrValue();    
    delay(500);
    maxValue = this->getLdrValue();

    this->_calibratedValue = (((maxValue - minValue)/2) + minValue);

}