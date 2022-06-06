#include "Arduino.h"

int v1;
float Rtest, Rrefer = 1000000; //in Ohms
unsigned long tempo;

void setup() {
  Serial.begin(9600);
}
void loop() {
  tempo = millis();
  
  v1 = analogRead(A0);
  //v1 = v1 * (4.95 / 1023.0);
  Rtest = (4.95 - v1) * Rrefer / v1;
  
  // Send a measurement from the first analog channel
  
  //Serial.print(tempo);
  //Serial.print(" ");
  Serial.println(v1);
;


  //Serial.println("\n");

  delay(100);
}
