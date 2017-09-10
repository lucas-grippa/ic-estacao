/*
  ConveyorBeltFreeRTOS.cpp - Library for automated station conveyor belt.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ConveyorBeltFreeRTOS.h"
#include "Arduino_FreeRTOS.h"

ConveyorBeltFreeRTOS::ConveyorBeltFreeRTOS()
{}

ConveyorBeltFreeRTOS::ConveyorBeltFreeRTOS(int m1, int m2, int m3, int m4)
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

int ConveyorBeltFreeRTOS::getDirection(){
    return this->_direction;
}

int ConveyorBeltFreeRTOS::getDelayTime(){
    return this->_delayTime;
}

int ConveyorBeltFreeRTOS::getOnOffStatus(){
    return this->_onOff;
}

void ConveyorBeltFreeRTOS::setSpeed(int speed){
    /*
    if(speed >= 5 and speed <= 50){
        this->_delayTime = (55 - speed);
    }
    */
    this->_delayTime = speed;
}

void ConveyorBeltFreeRTOS::motorControlRight(){
        int xLastWakeTime;
        int xFrequency = ( this->getDelayTime() / portTICK_PERIOD_MS );

        xLastWakeTime = xTaskGetTickCount();

        digitalWrite(this->_m4, HIGH);
        digitalWrite(this->_m3, HIGH);
        vTaskDelayUntil( &xLastWakeTime, xFrequency );
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );             
        digitalWrite(this->_m4, LOW);
        vTaskDelayUntil( &xLastWakeTime, xFrequency );    
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );              
        digitalWrite(this->_m3, HIGH); 
        digitalWrite(this->_m2, HIGH);  
        vTaskDelayUntil( &xLastWakeTime, xFrequency );
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );              
        digitalWrite(this->_m3, LOW);  
        vTaskDelayUntil( &xLastWakeTime, xFrequency );  
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );            
        digitalWrite(this->_m2, HIGH); 
        digitalWrite(this->_m1, HIGH);  
        vTaskDelayUntil( &xLastWakeTime, xFrequency ); 
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );              
        digitalWrite(this->_m2, LOW);  
        vTaskDelayUntil( &xLastWakeTime, xFrequency );  
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );            
        digitalWrite(this->_m1, HIGH);
        digitalWrite(this->_m4, HIGH);  
        vTaskDelayUntil( &xLastWakeTime, xFrequency ); 
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );              
        digitalWrite(this->_m1, LOW);  
        vTaskDelayUntil( &xLastWakeTime, xFrequency );
        //vTaskDelay( this->_delayTime / portTICK_PERIOD_MS );          
}

void ConveyorBeltFreeRTOS::motorControlLeft(){
        int xLastWakeTime;
        int xFrequency = ( this->getDelayTime() / portTICK_PERIOD_MS );

        xLastWakeTime = xTaskGetTickCount();

        digitalWrite(this->_m1, HIGH);
        digitalWrite(this->_m2, HIGH);   
        vTaskDelayUntil( &xLastWakeTime, xFrequency ); 
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

void ConveyorBeltFreeRTOS::setDirectionToRight(){
    this->_direction = 1;
}

void ConveyorBeltFreeRTOS::setDirectionToLeft(){
    this->_direction = 0;
}

void ConveyorBeltFreeRTOS::turnOn(){
    this->_onOff = 1;
}

void ConveyorBeltFreeRTOS::turnOff(){
    this->_onOff = 0;
}

void ConveyorBeltFreeRTOS::on(){

    if(this->getDirection() == 1){
        this->motorControlRight();
    }else{
        this->motorControlLeft();
    }

}

void ConveyorBeltFreeRTOS::off(){

    digitalWrite(this->_m1, LOW);
    digitalWrite(this->_m2, LOW);
    digitalWrite(this->_m3, LOW);
    digitalWrite(this->_m4, LOW);

}

void ConveyorBeltFreeRTOS::conveyorBeltControl(){
    if(this->getOnOffStatus() == 1){
        this->on();
    }else{
        this->off();
    }

}

