#include <Arduino.h>
#include <Wire.h>

void receiveEvent(int n) {

  while(Wire.available() > 1) {
    char c = Wire.read();
    Serial.print(c); 
  }

  int x = Wire.read();
  Serial.println(x);
}


void setup() {

  Wire.begin(6); 
  Serial.begin(9600);                
  Wire.onReceive(receiveEvent); 

}


void loop() {
  delay(100);
}