#include "Arduino.h"

float v1, Rtest, Rrefer = 100000.0; //in Ohms
unsigned long tempo;

void setup() {
  Serial.begin(9600);
}
void loop() {
  tempo = millis()/1000.0;
  
  v1 = analogRead(A0);
  v1 = v1 * (4.95 / 1023.0);
  Rtest = (4.95 - v1) * Rrefer / v1;
  
  // Send a measurement from the first analog channel
  
  //Serial.println("Resistance: \n");
  Serial.println(Rtest);
  //Serial.println("\n");
  //Serial.println("Time: \n");
  //Serial.print(tempo);
  //Serial.println("\n");

  delay(100);
}
