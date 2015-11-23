/*
  HCSR04.h - Library for the HC-SR04 distance sensor
  Created by Jeremy Lindsay, November 22, 2015.
  Inspired by code from Rui Santos, http://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
  Released into the public domain.
*/
#ifndef HCSR04_h
#define HCSR04_h

#include "Arduino.h"

class HCSR04
{
  public:
    HCSR04(int trigger, int echo);
    unsigned int echo();
  private:
    int _trigger;
    int _echo;
};

#endif