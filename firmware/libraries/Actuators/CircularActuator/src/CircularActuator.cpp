/*
  CircularActuator.h - Library for automated station circular actuator.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "CircularActuator.h"
#include "SwitchSensor.h"

CircularActuator::CircularActuator()
{}

CircularActuator::CircularActuator(int m1, int m2, int m3, int m4, int switchPin1, int switchPin2, int switchPin3)
{
    this->_m1 = m1;
    pinMode(this->_m1, OUTPUT);
    this->_m2 = m2;
    pinMode(this->_m2, OUTPUT);
    this->_m3 = m3;
    pinMode(this->_m3, OUTPUT);
    this->_m4 = m4;
    pinMode(this->_m4, OUTPUT);

    position1 = SwitchSensor(switchPin1);
    position2 = SwitchSensor(switchPin2);
    position3 = SwitchSensor(switchPin3); 

    this->_delayTime = 10;
    this->_position = 1;

}

int CircularActuator::getDelayTime(){
    return this->_delayTime;
}

int CircularActuator::getPosition(){
    return this->_position;
}

void CircularActuator::setSpeed(int speed){
    if(speed >= 5 and speed <= 50){
        this->_delayTime = (55 - speed);
    }
}

void CircularActuator::motorControl(){
    digitalWrite(this->_m1, HIGH);
    digitalWrite(this->_m2, HIGH);    
    delay(this->getDelayTime());              
    digitalWrite(this->_m1, LOW);    
    delay(this->getDelayTime());              
    digitalWrite(this->_m2, HIGH); 
    digitalWrite(this->_m3, HIGH);   
    delay(this->getDelayTime());              
    digitalWrite(this->_m2, LOW);    
    delay(this->getDelayTime());            
    digitalWrite(this->_m3, HIGH); 
    digitalWrite(this->_m4, HIGH);   
    delay(this->getDelayTime());              
    digitalWrite(this->_m3, LOW);    
    delay(this->getDelayTime());            
    digitalWrite(this->_m4, HIGH);
    digitalWrite(this->_m1, HIGH);   
    delay(this->getDelayTime());              
    digitalWrite(this->_m4, LOW);    
    delay(this->getDelayTime());

}

void CircularActuator::toPosition1(){
    while(position1.getSwitchState() == 0){
        position1.readSwitchState();
        this->motorControl();
    }
    this->_position = 0;
}

void CircularActuator::goToPosition1(){
    this->_position = 1;
}

void CircularActuator::toPosition2(){
    while(position2.getSwitchState() == 0){
        position2.readSwitchState();
        this->motorControl();
    }
    this->_position = 0;
}

void CircularActuator::goToPosition2(){
    this->_position = 2;
}

void CircularActuator::toPosition3(){
    while(position3.getSwitchState() == 0){
        position3.readSwitchState();
        this->motorControl();
    }
    this->_position = 0;
}

void CircularActuator::goToPosition3(){
    this->_position = 3;
}

bool CircularActuator::isItInPosition1(){
    if(position1.getSwitchState() == 1){
        this->_position1 = true;
    }else{
        this->_position1= false;
    }

    return this->_position1;
}

bool CircularActuator::isItInPosition2(){
    if(position2.getSwitchState() == 1){
        this->_position2 = true;
    }else{
        this->_position2= false;
    }

    return this->_position2;
}

bool CircularActuator::isItInPosition3(){
    if(position3.getSwitchState() == 1){
        this->_position3 = true;
    }else{
        this->_position3= false;
    }

    return this->_position3;
}

void CircularActuator::off(){

    digitalWrite(this->_m1, LOW);
    digitalWrite(this->_m2, LOW);
    digitalWrite(this->_m3, LOW);
    digitalWrite(this->_m4, LOW);
}

void CircularActuator::circularActuatorControl(){
    position1.readSwitchState();
    position2.readSwitchState();
    position3.readSwitchState();
    if(this->getPosition() == 1){
        this->toPosition1();
    }else if(this->getPosition() == 2){
        this->toPosition2();
    }else if(this->getPosition() == 3){
        this->toPosition3();
    }else {
        this->off();
    }
}