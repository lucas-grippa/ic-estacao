/*
  BarrierSensorFreeRTOS.cpp - Library for automated station barrier sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "BarrierSensorFreeRTOS.h"
#include "Arduino_FreeRTOS.h"

BarrierSensorFreeRTOS::BarrierSensorFreeRTOS()
{}

BarrierSensorFreeRTOS::BarrierSensorFreeRTOS(int ldrPin, int laserPin)
{
    this->_ldrPin = ldrPin;
    pinMode(this->_ldrPin, INPUT);
    this->_ldrValue = 0;

    this->_laserPin = laserPin;
    pinMode(this->_laserPin, OUTPUT);
    digitalWrite(this->_laserPin, HIGH);  
    this->_laserState = 1;

    //this->BarrierSensorFreeRTOSCalibrate();
}

/*
    Returns the cached ldr value
*/ 
int BarrierSensorFreeRTOS::getLdrValue(){
	return this->_ldrValue;
}

void BarrierSensorFreeRTOS::setCalibratedValue(int calibratedValue){
    this->_calibratedValue = calibratedValue;
}

/*
	Returns the cached ldr calibrated value
*/
int BarrierSensorFreeRTOS::getCalibratedValue(){
    return this->_calibratedValue;
}

 /*
     Read ldr value
*/
void BarrierSensorFreeRTOS::readLdrValue(){
	this->_ldrValue = analogRead(this->_ldrPin);
	//return this->getLdrValue();
}

 /*
	 Change laser state 0N/OFF
*/
void BarrierSensorFreeRTOS::laserChangeState(){
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
bool BarrierSensorFreeRTOS::lightBlocked(){
    if(this->getLdrValue() <= this->getCalibratedValue()){
        return false;
    }else{
        return true;
    }
        
}

void BarrierSensorFreeRTOS::barrierSensorCalibrate()
{
    int minValue = 0;
    int maxValue = 0;

    vTaskDelay( 1000 / portTICK_PERIOD_MS );
    this->laserChangeState();
    vTaskDelay( 500 / portTICK_PERIOD_MS );
    this->readLdrValue();
    vTaskDelay( 500 / portTICK_PERIOD_MS );
    minValue = this->getLdrValue();
    this->laserChangeState();
    vTaskDelay( 500 / portTICK_PERIOD_MS );
    this->readLdrValue(); 
    vTaskDelay( 500 / portTICK_PERIOD_MS );   
    maxValue = this->getLdrValue();

    this->_calibratedValue = (((maxValue - minValue)/2) + minValue);

}