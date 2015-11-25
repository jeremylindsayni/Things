/*
  WD03641A.h - Library for the 4 digit 7 segment display
  Created by Jeremy Lindsay, November 25, 2015.
  Released into the public domain.
*/
#ifndef WD03641_h
#define WD03641_h

#include "Arduino.h"

class WD03641
{
  public:
    WD03641(int digit1, int digit2, int digit3, int digit4, int a, int b, int c, int d, int e, int f, int g, int point);
	void displayNumber(int number);
  private:
    int _digit1;
    int _digit2;
    int _digit3;
    int _digit4;
    int _a;
    int _b;
    int _c;
    int _d;
    int _e;
    int _f;
    int _g;
    int _point;
	void lightNumber(int numberToDisplay);
	void lightDigit(int aStatus, int bStatus, int cStatus, int dStatus, int eStatus, int fStatus, int gStatus);
};

#endif