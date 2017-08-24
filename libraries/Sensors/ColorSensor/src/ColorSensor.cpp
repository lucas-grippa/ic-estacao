/*
  ColorSensor.cpp - Library for automated station color sensor.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ColorSensor.h"

ColorSensor::ColorSensor()
{}

ColorSensor::ColorSensor(int s0Pin, int s1Pin, int s2Pin, int s3Pin, int sensorDataPin)
{
    this->_s0Pin = s0Pin;
    pinMode(this->_s0Pin, OUTPUT);
    this->_s1Pin = s1Pin;
    pinMode(this->_s1Pin, OUTPUT);
    this->_s2Pin = s2Pin;
    pinMode(this->_s2Pin, OUTPUT);
    this->_s3Pin = s3Pin;
    pinMode(this->_s3Pin, OUTPUT);
    this->_sensorDataPin = sensorDataPin;
    pinMode(this->_sensorDataPin, INPUT);
    

    this->_dataRed = 0;
    this->_dataGreen = 0;
    this->_dataBlue = 0;

    this->_red = false;
    this->_green = false;
    this->_blue = false;

    digitalWrite(this->_s0Pin, HIGH);
    digitalWrite(this->_s1Pin, HIGH);

}

int ColorSensor::getDataRed(){
    return this->_dataRed;
}

int ColorSensor::getDataGreen(){
    return this->_dataGreen;
}

int ColorSensor::getDataBlue(){
    return this->_dataBlue;
}

void ColorSensor::readRed(){
    digitalWrite(this->_s2Pin, LOW);
    digitalWrite(this->_s3Pin, LOW);

    this->_dataRed = pulseIn(this->_sensorDataPin, LOW);
}

void ColorSensor::readGreen(){
    digitalWrite(this->_s2Pin, HIGH);
    digitalWrite(this->_s3Pin, HIGH);

    this->_dataGreen = pulseIn(this->_sensorDataPin, LOW);
}

void ColorSensor::readBlue(){
    digitalWrite(this->_s2Pin, LOW);
    digitalWrite(this->_s3Pin, HIGH);

    this->_dataBlue = pulseIn(this->_sensorDataPin, LOW);
}

void ColorSensor::readColors(){
    this->readRed();
    delay(20);
    this->readGreen();
    delay(20);
    this->readBlue();
    delay(20);
}

bool ColorSensor::isItRed(){
    if(this->getDataRed() < this->getDataGreen() and this->getDataRed() < this->getDataBlue() ){
        this->_red = true;
    }else{
        this->_red = false;
    }

    return this->_red;
}

bool ColorSensor::isItGreen(){
    if(this->getDataGreen() < this->getDataRed() and this->getDataGreen() < this->getDataBlue() ){
        this->_green = true;
    }else{
        this->_green = false;
    }

    return this->_green;
}

bool ColorSensor::isItBlue(){
    if(this->getDataBlue() < this->getDataRed() and this->getDataBlue() < this->getDataGreen() ){
        this->_blue = true;
    }else{
        this->_blue = false;
    }

    return this->_blue;
}

