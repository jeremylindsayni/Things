
int digit1 = 11; //PWM Display pin 1
int digit2 = 9; //PWM Display pin 2
int digit3 = 5; //PWM Display pin 6
int digit4 = 10; //PWM Display pin 8

//Pin mapping from Arduino to the ATmega DIP28 if you need it
//http://www.arduino.cc/en/Hacking/PinMapping
int segF = A1; //Display pin 14
int segA = A0; //Display pin 16
int segB = A3; //Display pin 13
int segD = A2; //Display pin 3
int segG = A5; //Display pin 5
int segPoint = A4; //Display pin 15
int segC = 6; //Display pin 11
int segE = 7; //Display pin 15

long duration, cm, inches;
 
int trigPin = 12;    //Trig - blue Jumper
int echoPin = 13;    //Echo - green Jumper

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
 
void loop()
{
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
