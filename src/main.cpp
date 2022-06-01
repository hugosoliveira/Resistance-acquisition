#include "MegunoLink.h"
#include "CommandHandler.h"

float v1, Rtest, Rrefer = 100000; //in Ohms
unsigned long tempo;

void setup() {
  Serial.begin(9600);
}
void loop() {
  tempo = millis();
  
  v1 = analogRead(A0);
  v1 = v1 * (4.95 / 1023.0);
  Rtest = (4.95 - v1) * Rrefer / v1;
  
    // Create a plot variable
  TimePlot MyPlot;
 
  // Send a measurement from the first analog channel
  MyPlot.SendData("tempo",tempo);
  MyPlot.SendData("Rtest",Rtest);
  
  Serial.print(tempo);
  Serial.print("  ");
  Serial.print(Rtest);
  Serial.print("\\");

  delay(100);
}
