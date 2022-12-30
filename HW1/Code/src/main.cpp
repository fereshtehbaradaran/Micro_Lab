#include <Arduino.h>

#define INPUT_PIN A0
#define OUTPUT_PIN 10

void setup() {
  pinMode(INPUT_PIN, INPUT);
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(INPUT_PIN);
  value = map(value, 0, 1023, 0, 255);
  analogWrite(OUTPUT_PIN, value);
}