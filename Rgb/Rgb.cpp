/*
  Motor.cpp - Library for simple DC Motor usage.
  Created by Ruben Capitao, 2 March 2014.
*/

#include "Arduino.h"
#include "Rgb.h"

void RGB::attach(int pinR, int pinG, int pinB)
{
  _pinR = pinR;
  _pinG = pinG;
  _pinB = pinB;
}

void RGB::setColor(int color){
  if (color == OFF){
    analogWrite(_pinR,0);
    analogWrite(_pinG,0);
    analogWrite(_pinB,0);
  }else if(color == RED){
    analogWrite(_pinR,255);
    analogWrite(_pinG,0);
    analogWrite(_pinB,0);  
  }else if(color == GREEN){
    analogWrite(_pinR,0);
    analogWrite(_pinG,255);
    analogWrite(_pinB,0);
  }else if(color == BLUE){
    analogWrite(_pinR,0);
    analogWrite(_pinG,0);
    analogWrite(_pinB,255);
  }
}
