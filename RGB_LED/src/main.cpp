#include <Arduino.h>

#define INPUT_PIN_R A0
#define INPUT_PIN_G A1
#define INPUT_PIN_B A2

#define OUTPUT_PIN_R 9
#define OUTPUT_PIN_G 10
#define OUTPUT_PIN_B 11

void setup() {
  pinMode(INPUT_PIN_R, INPUT);
  pinMode(INPUT_PIN_G, INPUT);
  pinMode(INPUT_PIN_B, INPUT);

  pinMode(OUTPUT_PIN_R, OUTPUT);
  pinMode(OUTPUT_PIN_G, OUTPUT);
  pinMode(OUTPUT_PIN_B, OUTPUT);
}

void loop() {
  int value_R = analogRead(INPUT_PIN_R);
  value_R = map(value_R, 0, 1023, 0, 255);
  int value_G = analogRead(INPUT_PIN_G);
  value_G = map(value_G, 0, 1023, 0, 255);
  int value_B = analogRead(INPUT_PIN_B);
  value_B = map(value_B, 0, 1023, 0, 255);


  analogWrite(OUTPUT_PIN_R, value_R);
  analogWrite(OUTPUT_PIN_G, value_G);
  analogWrite(OUTPUT_PIN_B, value_B);
  
}