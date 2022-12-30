#include <Arduino.h>

#define OUTPUT_PIN 4
#define INPUT_PIN A0

int dutyCycle = 0.1;
bool toggle = false;
int val;

ISR(TIMER1_COMPA_vect){
  if(toggle) {
    digitalWrite(OUTPUT_PIN, LOW);
    OCR1A = 1023 - val;
  } else {
    digitalWrite(OUTPUT_PIN, HIGH);
    OCR1A = val;
  }
  toggle = !toggle;
}

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 0;
  
  TCCR1A |= (1 << COM1A0) | (1 << COM1B0);
  TCCR1B |= (1 << WGM12) | (1 << CS01);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();

}

void loop() {
  val = map(analogRead(INPUT_PIN), 0, 1023, 1023 * dutyCycle, 1023 * (1 - dutyCycle));
}