void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
/*
  int sensorValue = analogRead(A0);

  //Serial.print("sensorValue = ");
  //Serial.print(sensorValue);
  //Serial.println();

  float voltage =  sensorValue * (5.0 / 1023.0);

  //Serial.print("voltage = ");
  //Serial.print(voltage);
  //Serial.println();

  // 9.8mV/inch

  float distance = 2.54 * voltage/(0.0098);

  Serial.print("Distance (inches) = ");
  Serial.print(distance);
  Serial.println();
*/

/*
  digitalWrite(13, LOW);
  delayMicroseconds(5);
  digitalWrite(13, HIGH);
  delayMicroseconds(25);
  digitalWrite(13, LOW);

  long duration = pulseIn(12, HIGH);
  long inches = 2.54 * duration / 147;

  Serial.print("Distance (cm) = ");
  Serial.print(inches);
  Serial.println();

  delay(250);
*/
}
