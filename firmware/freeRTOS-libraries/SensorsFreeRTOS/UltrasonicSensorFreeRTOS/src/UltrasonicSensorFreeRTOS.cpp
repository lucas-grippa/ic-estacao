/*
  UltrasonicSensorFreeRTOS.cpp - Library for automated station ultrasonic sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "UltrasonicSensorFreeRTOS.h"
#include "Arduino_FreeRTOS.h"

UltrasonicSensorFreeRTOS::UltrasonicSensorFreeRTOS()
{}

UltrasonicSensorFreeRTOS::UltrasonicSensorFreeRTOS(int trigPin, int echoPin)
{
    this->_trigPin = trigPin;
    pinMode(this->_trigPin, OUTPUT);

    this->_echoPin = echoPin;
    pinMode(this->_echoPin, INPUT);

    

    this->_duration = 0;
    this->_distance = 0.0;
    this->_height = 0.0;
    this->_short = false;
    this->_high = false;
}

float UltrasonicSensorFreeRTOS::getDistance(){
    return this->_distance;
}

float UltrasonicSensorFreeRTOS::getInitialDistance(){
    return this->_initialDistance;
}

void UltrasonicSensorFreeRTOS::readDistanceCalibrate(){
    // Clears the trigPin
    digitalWrite(this->_trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(this->_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->_trigPin, LOW);
     // Reads the echoPin, returns the sound wave travel time in microseconds
    this->_duration = pulseIn(this->_echoPin, HIGH);
    // Calculating the distance
    this->_distance = (this->_duration)*0.034/2.0;
}

void UltrasonicSensorFreeRTOS::readDistance(){
    // Clears the trigPin
    digitalWrite(this->_trigPin, LOW);
    vTaskDelay( 0.002 / portTICK_PERIOD_MS );
    //delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(this->_trigPin, HIGH);
    vTaskDelay( 0.010 / portTICK_PERIOD_MS );
    //delayMicroseconds(10);
    digitalWrite(this->_trigPin, LOW);
     // Reads the echoPin, returns the sound wave travel time in microseconds
    this->_duration = pulseIn(this->_echoPin, HIGH);
    // Calculating the distance
    this->_distance = (this->_duration)*0.034/2.0;
}

void UltrasonicSensorFreeRTOS::ultrasonicSensorCalibrate(){
    this->readDistanceCalibrate();
    this->_initialDistance = this->getDistance();
}

float UltrasonicSensorFreeRTOS::getHeight(){
    this->_height = (this->getInitialDistance() - this->getDistance());

    return this->_height;   
}


bool UltrasonicSensorFreeRTOS::isItShort(){
    if(this->getHeight() < 1.56){
        this->_short = true;
    }else{
        this->_short = false;
    }

    return this->_short;
}

bool UltrasonicSensorFreeRTOS::isItHigh(){
    if(this->getHeight() > 1.56){
        this->_high = true;
    }else{
        this->_high = false;
    }

    return this->_high;
}

