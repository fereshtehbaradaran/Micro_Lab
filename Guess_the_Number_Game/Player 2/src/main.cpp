#include <Arduino.h>

String input;
int output;
bool flag = true;
int high = 100;
int low = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0){
    input = Serial.readString();

    if (input == "Start"){
      output = (high + low) / 2;
      Serial.print(output);
    } 

    else if ((input == "Higher")){
      low = output;
      output = (high + low) / 2;
      Serial.print(output);
    }
    else if ((input == "Lower")){
      high = output;
      output = (high + low) / 2;
      Serial.print(output);
    }
  }

  delay(2000);
}