/*
  DisplayInterface.h - Library for automated station display interface.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DisplayInterface.h"

DisplayInterface::DisplayInterface()
{
    this->setLine1("Estacao");
    this->setLine2("Automatizada");
}

void DisplayInterface::setLine1(String line1){
    this->_line1 = line1;
}

void DisplayInterface::setLine2(String line2){
    this->_line2 = line2;
}

String DisplayInterface::getLine1(){
    return this->_line1;
}

String DisplayInterface::getLine2(){
    return this->_line2;
}
