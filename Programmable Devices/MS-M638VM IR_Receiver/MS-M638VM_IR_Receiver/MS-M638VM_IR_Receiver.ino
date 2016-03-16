#include <IRremote.h>
#include <IRremoteInt.h>

int receiver = 11;

IRrecv irrecv(receiver);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("IR receiver button decode");
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results))
  {
    translateIR();
    irrecv.resume();
  }
}

void translateIR() {
  
    Serial.println(results.value, DEC);
    Serial.println(results.rawlen);
    Serial.println(results.bits);
    Serial.println(results.decode_type);

    for (int i = 1; i <= results.rawlen - 1; i++) {
        if (i % 2) {
        // Mark
        
        Serial.print(" m");
        Serial.print(results.rawbuf[i]), DEC;
      } 
      else {
        // Space
        Serial.print(" s");
        Serial.print(results.rawbuf[i], DEC);
      }
    }
    Serial.println();
}

