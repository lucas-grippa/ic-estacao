/*
  CircularActuatorFreeRTOS.h - Library for automated station circular actuator.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "CircularActuatorFreeRTOS.h"
#include "SwitchSensor.h"
#include "Arduino_FreeRTOS.h"

CircularActuatorFreeRTOS::CircularActuatorFreeRTOS()
{}

CircularActuatorFreeRTOS::CircularActuatorFreeRTOS(int m1, int m2, int m3, int m4, int switchPin1, int switchPin2, int switchPin3)
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

int CircularActuatorFreeRTOS::getDelayTime(){
    return this->_delayTime;
}

int CircularActuatorFreeRTOS::getPosition(){
    return this->_position;
}

void CircularActuatorFreeRTOS::setSpeed(int speed){
    /*
    if(speed >= 5 and speed <= 50){
        this->_delayTime = (55 - speed);
    }
    */
    this->_delayTime = speed;
}

void CircularActuatorFreeRTOS::motorControl(){
    int xLastWakeTime;
    int xFrequency = ( this->getDelayTime() / portTICK_PERIOD_MS );

    xLastWakeTime = xTaskGetTickCount ();


    digitalWrite(this->_m1, HIGH);
    digitalWrite(this->_m2, HIGH); 
    //vTaskDelayUntil( &xLastWakeTime, xFrequency );   
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS );               
    digitalWrite(this->_m1, LOW);   
    vTaskDelayUntil( &xLastWakeTime, xFrequency ); 
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS );               
    digitalWrite(this->_m2, HIGH); 
    digitalWrite(this->_m3, HIGH);
    vTaskDelayUntil( &xLastWakeTime, xFrequency );   
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS );               
    digitalWrite(this->_m2, LOW); 
    vTaskDelayUntil( &xLastWakeTime, xFrequency );   
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS );             
    digitalWrite(this->_m3, HIGH); 
    digitalWrite(this->_m4, HIGH); 
    vTaskDelayUntil( &xLastWakeTime, xFrequency );  
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS );               
    digitalWrite(this->_m3, LOW);  
    vTaskDelayUntil( &xLastWakeTime, xFrequency );  
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS );             
    digitalWrite(this->_m4, HIGH);
    digitalWrite(this->_m1, HIGH);
    vTaskDelayUntil( &xLastWakeTime, xFrequency );   
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS );               
    digitalWrite(this->_m4, LOW); 
    vTaskDelayUntil( &xLastWakeTime, xFrequency );   
    //vTaskDelay( (this->getDelayTime()) / portTICK_PERIOD_MS ); 

}

void CircularActuatorFreeRTOS::toPosition1(){
    while(position1.getSwitchState() == 0){
        position1.readSwitchState();
        this->motorControl();
    }

    this->_position = 0;
}

void CircularActuatorFreeRTOS::goToPosition1(){
    this->_position = 1;
}

void CircularActuatorFreeRTOS::toPosition2(){
    while(position2.getSwitchState() == 0){
        position2.readSwitchState();
        this->motorControl();
    }
    this->_position = 0;
}

void CircularActuatorFreeRTOS::goToPosition2(){
    this->_position = 2;
}

void CircularActuatorFreeRTOS::toPosition3(){
    while(position3.getSwitchState() == 0){
        position3.readSwitchState();
        this->motorControl();
    }
    this->_position = 0;
}

void CircularActuatorFreeRTOS::goToPosition3(){
    this->_position = 3;
}

bool CircularActuatorFreeRTOS::isItInPosition1(){
    if(position1.getSwitchState() == 1){
        this->_position1 = true;
    }else{
        this->_position1= false;
    }

    return this->_position1;
}

bool CircularActuatorFreeRTOS::isItInPosition2(){
    if(position2.getSwitchState() == 1){
        this->_position2 = true;
    }else{
        this->_position2= false;
    }

    return this->_position2;
}

bool CircularActuatorFreeRTOS::isItInPosition3(){
    if(position3.getSwitchState() == 1){
        this->_position3 = true;
    }else{
        this->_position3= false;
    }

    return this->_position3;
}

void CircularActuatorFreeRTOS::off(){

    digitalWrite(this->_m1, LOW);
    digitalWrite(this->_m2, LOW);
    digitalWrite(this->_m3, LOW);
    digitalWrite(this->_m4, LOW);
}

void CircularActuatorFreeRTOS::circularActuatorControl(){
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