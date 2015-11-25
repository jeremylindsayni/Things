/*
  WD03641A.h - Library for the 4 digit 7 segment display
  Created by Jeremy Lindsay, November 25, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "WD03641.h"

WD03641::WD03641(int digit1, int digit2, int digit3, int digit4, int a, int b, int c, int d, int e, int f, int g, int point)
{
	pinMode(digit1, OUTPUT);
	pinMode(digit2, OUTPUT);
	pinMode(digit3, OUTPUT);
	pinMode(digit4, OUTPUT);

	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);
	pinMode(c, OUTPUT);
	pinMode(d, OUTPUT);
	pinMode(e, OUTPUT);
	pinMode(f, OUTPUT);
	pinMode(g, OUTPUT);
	pinMode(point, OUTPUT);

	_digit1 = digit1;
	_digit2 = digit2;
	_digit3 = digit3;
	_digit4 = digit4;
	
	_a = a;
	_b = b;
	_c = c;
	_d = d;
	_e = e;
	_f = f;
	_g = g;
	_point = point;
}

void WD03641::displayNumber(int number)
{
	#define DISPLAY_BRIGHTNESS   50

	#define DIGIT_ON  LOW
	#define DIGIT_OFF  HIGH

	long beginTime = millis();

	for(int digit = 4 ; digit > 0 ; digit--) {

		//Turn on a digit for a short amount of time
		switch(digit) {
		case 1:
		  digitalWrite(_digit1, DIGIT_ON);
		  break;
		case 2:
		  digitalWrite(_digit2, DIGIT_ON);
		  break;
		case 3:
		  digitalWrite(_digit3, DIGIT_ON);
		  break;
		case 4:
		  digitalWrite(_digit4, DIGIT_ON);
		  break;
		}

		//Turn on the right segments for this digit
		lightNumber(number % 10);
		number /= 10;

		delayMicroseconds(DISPLAY_BRIGHTNESS); 
		//Display digit for fraction of a second (1us to 5000us, 500 is pretty good)

		//Turn off all segments
		lightNumber(10); 

		//Turn off all digits
		digitalWrite(_digit1, DIGIT_OFF);
		digitalWrite(_digit2, DIGIT_OFF);
		digitalWrite(_digit3, DIGIT_OFF);
		digitalWrite(_digit4, DIGIT_OFF);
	}

	while( (millis() - beginTime) < 10) ; 
}

void WD03641::lightDigit(int aStatus, int bStatus, int cStatus, int dStatus, int eStatus, int fStatus, int gStatus) {
	digitalWrite(_a, aStatus);
    digitalWrite(_b, bStatus);
    digitalWrite(_c, cStatus);
    digitalWrite(_d, dStatus);
    digitalWrite(_e, eStatus);
    digitalWrite(_f, fStatus);
    digitalWrite(_g, gStatus);
}

void WD03641::lightNumber(int numberToDisplay) {

#define SEGMENT_ON  HIGH
#define SEGMENT_OFF LOW

  switch (numberToDisplay){

  case 0:
	lightDigit(SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF);
    break;

  case 1:
	lightDigit(SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF);
    break;

  case 2:
	lightDigit(SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_ON);
    break;

  case 3:
	lightDigit(SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_ON);
    break;

  case 4:
	lightDigit(SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON);
    break;

  case 5:
	lightDigit(SEGMENT_ON, SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON);
    break;

  case 6:
	lightDigit(SEGMENT_ON, SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON);
    break;

  case 7:
	lightDigit(SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF);
    break;

  case 8:
	lightDigit(SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON);
    break;

  case 9:
	lightDigit(SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_ON, SEGMENT_OFF, SEGMENT_ON, SEGMENT_ON);
    break;

  case 10:
	lightDigit(SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF, SEGMENT_OFF);
    break;
  }
}