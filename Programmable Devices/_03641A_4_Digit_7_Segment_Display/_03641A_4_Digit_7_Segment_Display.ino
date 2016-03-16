#include <WD03641.h>
#include <HCSR04.h>
#include <RunningAverage.h> // http://playground.arduino.cc/Main/RunningAverage

int echoPin = 12;
int triggerPin = 13;

int a = 8;
int b = 4;
int c = 0;
int d = A3;
int e = A2;
int f = 7;
int g = 2;
int dp = 1;

HCSR04 sonar(triggerPin, echoPin);
WD03641 segments(9, 6, 5, 3, a, b, c, d, e, f, g, dp);
RunningAverage runningAverage(10);

void setup() { 
}

void loop() {
  
  runningAverage.addValue(sonar.distanceInCentimetres());

  segments.displayNumber(runningAverage.getAverage());
  
  delay(10);

}
