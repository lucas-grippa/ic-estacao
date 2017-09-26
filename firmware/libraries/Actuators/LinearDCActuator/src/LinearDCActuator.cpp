/*
  LinearDCActuator.h - Library for automated station linear DC actuator.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "LinearDCActuator.h"
#include "SwitchSensor.h"

LinearDCActuator::LinearDCActuator()
{}

LinearDCActuator::LinearDCActuator(int m1, int m2, int switchPin1, int switchPin2)
{
    this->_m1 = m1;
    pinMode(this->_m1, OUTPUT);
    this->_m2 = m2;
    pinMode(this->_m2, OUTPUT);

    forwardSensor = SwitchSensor(switchPin1);
    backwardSensor = SwitchSensor(switchPin2); 

    this->_direction = -1;
    this->_forward = 0;
    this->_backward = 1;

}

int LinearDCActuator::getDirection(){
    return this->_direction;
}

void LinearDCActuator::goForward(){
    this->_direction = 1;
}

void LinearDCActuator::goBackward(){
    this->_direction = 0;
}

void LinearDCActuator::forward(){
    while(forwardSensor.getSwitchState() == 0){
        forwardSensor.readSwitchState();
        digitalWrite(this->_m1, LOW);
        digitalWrite(this->_m2, HIGH);
    }
    this->_direction = -1;
    digitalWrite(this->_m1, LOW);
    digitalWrite(this->_m2, LOW);
}

void LinearDCActuator::backward(){
    while(backwardSensor.getSwitchState() == 0){
        backwardSensor.readSwitchState();
        digitalWrite(this->_m1, HIGH);
        digitalWrite(this->_m2, LOW);
    }
    this->_direction = -1;
    digitalWrite(this->_m1, LOW);
    digitalWrite(this->_m2, LOW);
}

bool LinearDCActuator::isItForward(){
    if(forwardSensor.getSwitchState() == 1){
        this->_forward = true;
    }else{
        this->_forward = false;
    }

    return this->_forward;
}

bool LinearDCActuator::isItBackward(){
    if(backwardSensor.getSwitchState() == 1){
        this->_backward = true;
    }else{
        this->_backward = false;
    }

    return this->_backward;
}

void LinearDCActuator::linearDCActuatorControl(){
    forwardSensor.readSwitchState();
    backwardSensor.readSwitchState();
    digitalWrite(this->_m1, LOW);
    digitalWrite(this->_m2, LOW);
    if(this->getDirection() == 1){
        this->forward();
    }else if(this->getDirection() == 0){
        this->backward();
    }
}