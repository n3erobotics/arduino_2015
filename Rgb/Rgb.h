/*
  Motor.h - Library for simple DC Motor usage.
  Created by Ruben Capitao, 2 March 2014.
*/
#ifndef RGB_h
#define RGB_h

#define FORWARD 0
#define BACKWARD 1

#include "Arduino.h"

#define OFF 0
#define RED 1
#define GREEN 2
#define BLUE 3

class RGB
{
  public:
    void attach(int pinR, int pinG, int pinB);
    void setColor(int color);
  private:
    int _pinR, _pinG, _pinB;
};

#endif
