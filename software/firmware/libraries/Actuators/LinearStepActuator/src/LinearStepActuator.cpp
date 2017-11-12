/*
  LinearStepActuator.h - Library for automated station linear step actuator.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "LinearStepActuator.h"
#include "SwitchSensor.h"
#include "Stepper.h"

LinearStepActuator::LinearStepActuator()
{}

LinearStepActuator::LinearStepActuator(int m1, int m2, int m3, int m4, int switchPin1, int switchPin2)
{
    this->_m1 = m1;
    pinMode(this->_m1, OUTPUT);
    this->_m2 = m2;
    pinMode(this->_m2, OUTPUT);
    this->_m3 = m3;
    pinMode(this->_m3, OUTPUT);
    this->_m4 = m4;
    pinMode(this->_m4, OUTPUT);

    this->_motorSteps = 400;
    this->_direction = -1;
    this->_forward = 0;
    this->_backward = 1;
    this->_speed = 30;
    this->_steps = 0;
    this->_stepMode = 0;

    forwardSensor = SwitchSensor(switchPin1);
    backwardSensor = SwitchSensor(switchPin2); 

    motor = Stepper((this->_motorSteps), (this->_m1), (this->_m2), (this->_m3), (this->_m4));

}

int LinearStepActuator::getDirection(){
    return this->_direction;
}

void LinearStepActuator::setSpeed(int speed){
    this->_speed = speed;
}

int LinearStepActuator::getSpeed(){
    return this->_speed;
}

int LinearStepActuator::getStepModeStatus(){
    return this->_stepMode;
}

int LinearStepActuator::getSteps(){
    return this->_steps;
}

void LinearStepActuator::stepModeOn(){
    this->_stepMode = 1;
}

void LinearStepActuator::stepModeOff(){
    this->_stepMode = 0;
}

void LinearStepActuator::goForward(){
    this->_direction = 1;
}

void LinearStepActuator::goForwardSteps(int steps){
    this->_direction = 1;
    this->_steps = steps;
}

void LinearStepActuator::goBackward(){
    this->_direction = 0;
}

void LinearStepActuator::goBackwardSteps(int steps){
    this->_direction = 0;
    this->_steps = steps;
}

void LinearStepActuator::forward(){
    while(forwardSensor.getSwitchState() == 0){
        forwardSensor.readSwitchState();
        motor.step(1);
    }
    this->_direction = -1;
}

void LinearStepActuator::forwardSteps(){
    motor.step(this->getSteps());
    this->_direction = -1;
}

void LinearStepActuator::backward(){
    while(backwardSensor.getSwitchState() == 0){
        backwardSensor.readSwitchState();
        motor.step(-1);
    }
    this->_direction = -1;
}

void LinearStepActuator::backwardSteps(){
    motor.step(-(this->getSteps()));
    this->_direction = -1;
}


bool LinearStepActuator::isItForward(){
    if(forwardSensor.getSwitchState() == 1){
        this->_forward = true;
    }else{
        this->_forward = false;
    }

    return this->_forward;
}

bool LinearStepActuator::isItBackward(){
    if(backwardSensor.getSwitchState() == 1){
        this->_backward = true;
    }else{
        this->_backward = false;
    }

    return this->_backward;
}

void LinearStepActuator::linearStepActuatorControl(){
    forwardSensor.readSwitchState();
    backwardSensor.readSwitchState();
    if(this->getStepModeStatus() == 0){
        if(this->getDirection() == 1){
            motor.setSpeed(this->getSpeed());
            this->forward();
         }else if(this->getDirection() == 0){
            motor.setSpeed(this->getSpeed());
            this->backward();
        }
    }else{
        if(this->getDirection() == 1){
            motor.setSpeed(this->getSpeed());
            this->forwardSteps();
         }else if(this->getDirection() == 0){
            motor.setSpeed(this->getSpeed());
            this->backwardSteps();
        }
    } 
}
