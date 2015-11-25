/*
  HCSR04.cpp - Library for the HC-SR04 distance sensor
  Created by Jeremy Lindsay, November 22, 2015.
  Inspired by code from Rui Santos, http://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
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

unsigned int HCSR04::distanceInCentimetres()
{
	int duration = echo();
	
	// Given the speed of sound in air is 332m/s = 3320cm/s = 0.0332cm/us).
	return (duration / 2) * 0.0332;
}