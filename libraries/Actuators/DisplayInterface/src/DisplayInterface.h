/*
  DisplayInterface.h - Library for automated station display interface.
  Created by Lucas Grippa Marques, August 17, 2017.
  Released into the public domain.
*/

#ifndef DisplayInterface_h
#define DisplayInterface_h

#include "Arduino.h"

class DisplayInterface
{
  public:
    DisplayInterface();
    void setLine1(String);
    void setLine2(String);
    String getLine1();
    String getLine2();
  private:
    String _line1;
    String _line2;
};

#endif