/*
  HCSR04.cpp - Library for the HC-SR04 distance sensor
  Created by Jeremy Lindsay, November 22, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "HCSR04.h"

HCSR04::HCSR04(int trigger, int echo)
{
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
	_trigger = trigger;
	_echo = echo;
}

unsigned int HCSR04::echo()
{
	digitalWrite(_trigger, LOW);
	delayMicroseconds(5);
	digitalWrite(_trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigger, LOW);  

	return pulseIn(_echo, HIGH);
}