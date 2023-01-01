#include <Arduino.h>
#include <Wire.h>


// String message = "A Hard coded String"; 

void setup(){
  Wire.begin();
}


void loop(){

  Wire.beginTransmission(6);
  Wire.write("A Hard coded String");
  Wire.endTransmission();

  delay(5000);
}