#include <Arduino.h>
#include <Wire.h>

void setup(){
    Wire.begin(8);
    Wire.onRequest(requestEvent);
}

void loop(){
    delay(500);
}

void requestEvent(){
    Wire.write("hello ");
}