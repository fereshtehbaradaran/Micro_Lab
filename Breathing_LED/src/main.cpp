#include <Arduino.h>

#define OUTPUT_PIN 5
#define MAX_VOLTAGE 255

int value = 0;
bool isForward = true;

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (isForward) {

    if(value < MAX_VOLTAGE){
      value ++;

    }else{
      isForward = false;
    }

  }else{
    if(value > 0){
      value --;
      
    }else{
      isForward = true;
    }
  }

  analogWrite(OUTPUT_PIN, value);
  Serial.println(value);
  //delay(100);
  
}