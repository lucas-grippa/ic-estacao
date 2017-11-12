/*
  SwitchSensor.cpp - Library for automated station switch sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "SwitchSensor.h"

SwitchSensor::SwitchSensor()
{}

SwitchSensor::SwitchSensor(int switchPin)
{
    this->_switchPin = switchPin;
    pinMode(this->_switchPin, INPUT);

    this->_switchState = 0;
    this->_high = false;
    this->_low = false;

}

int SwitchSensor::getSwitchPin(){
    return this->_switchPin;
}

int SwitchSensor::getSwitchState(){
    return this->_switchState;
}

void SwitchSensor::readSwitchState(){
    if (digitalRead(getSwitchPin()) == LOW ) {
        this->_switchState = 0;
    }

    if (digitalRead(getSwitchPin()) == HIGH ) {
        this->_switchState = 1;
    }
}

bool SwitchSensor::isItHigh(){
    if(this->getSwitchState() == 1){
        this->_high = true;
    }else{
        this->_high = false;
    }

    return this->_high;
}

bool SwitchSensor::isItLow(){
    if(this->getSwitchState() == 0){
        this->_low = true;
    }else{
        this->_low = false;
    }
    
    return this->_low;
}
