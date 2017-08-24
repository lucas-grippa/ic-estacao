/*
  ConveyorBelt.cpp - Library for automated station conveyor belt.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ConveyorBelt.h"

ConveyorBelt::ConveyorBelt()
{}

ConveyorBelt::ConveyorBelt(int m1, int m2, int m3, int m4)
{
    this->_m1 = m1;
    pinMode(this->_m1, OUTPUT);
    this->_m2 = m2;
    pinMode(this->_m2, OUTPUT);
    this->_m3 = m3;
    pinMode(this->_m3, OUTPUT);
    this->_m4 = m4;
    pinMode(this->_m4, OUTPUT);
    

    this->_delayTime = 10;
    this->_direction = 1;
    this->_onOff = 0;

}

int ConveyorBelt::getDirection(){
    return this->_direction;
}

int ConveyorBelt::getDelayTime(){
    return this->_delayTime;
}

int ConveyorBelt::getOnOffStatus(){
    return this->_onOff;
}

void ConveyorBelt::setSpeed(int speed){
    if(speed >= 5 and speed <= 50){
        this->_delayTime = (55 - speed);
    }
}

void ConveyorBelt::motorControlRight(){
    digitalWrite(this->_m4, HIGH);
    digitalWrite(this->_m3, HIGH);    
    delay(this->getDelayTime());              
    digitalWrite(this->_m4, LOW);    
    delay(this->getDelayTime());              
    digitalWrite(this->_m3, HIGH); 
    digitalWrite(this->_m2, HIGH);   
    delay(this->getDelayTime());              
    digitalWrite(this->_m3, LOW);    
    delay(this->getDelayTime());            
    digitalWrite(this->_m2, HIGH); 
    digitalWrite(this->_m1, HIGH);   
    delay(this->getDelayTime());              
    digitalWrite(this->_m2, LOW);    
    delay(this->getDelayTime());            
    digitalWrite(this->_m1, HIGH);
    digitalWrite(this->_m4, HIGH);   
    delay(this->getDelayTime());              
    digitalWrite(this->_m1, LOW);    
    delay(this->getDelayTime());            

}

void ConveyorBelt::motorControlLeft(){
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

void ConveyorBelt::setDirectionToRight(){
    this->_direction = 1;
}

void ConveyorBelt::setDirectionToLeft(){
    this->_direction = 0;
}

void ConveyorBelt::turnOn(){
    this->_onOff = 1;
}

void ConveyorBelt::turnOff(){
    this->_onOff = 0;
}

void ConveyorBelt::on(){

    if(this->getDirection() == 1){
        this->motorControlRight();
    }else{
        this->motorControlLeft();
    }

}

void ConveyorBelt::off(){

    digitalWrite(this->_m1, LOW);
    digitalWrite(this->_m2, LOW);
    digitalWrite(this->_m3, LOW);
    digitalWrite(this->_m4, LOW);

}

void ConveyorBelt::conveyorBeltControl(){
    if(getOnOffStatus() == 1){
        this->on();
    }else{
        this->off();
    }

}

