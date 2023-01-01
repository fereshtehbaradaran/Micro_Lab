#include <Arduino.h>
#include <Wire.h>


const char *message = "A Hard coded String"; 

void setup(){
  Wire.begin();
}


void loop(){

  Wire.beginTransmission(6);
  Wire.write(message);
  Wire.endTransmission();

  delay(5000);
}