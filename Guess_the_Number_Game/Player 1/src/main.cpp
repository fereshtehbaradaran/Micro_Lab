#include <Arduino.h>
#include <LiquidCrystal.h>


bool restart = true;
int randomNum;
int randRange = 101;
int input;

LiquidCrystal lcd(5, 4, 6, 3, 9, 8);

void setup() {
	Serial.begin(9600);
	lcd.begin(16, 2);
	randomSeed(analogRead(A0));
}

void loop() {
	if (restart){
		randomNum = random(randRange);
		restart = false;
		lcd.clear();
		lcd.print("Game started!");
		Serial.print("Start");
	}
	else{
		if (Serial.available() > 0){
			input = Serial.parseInt();

			lcd.clear();
			lcd.print(input);
			
			if (input == randomNum){
				lcd.print(", Correct!");
				Serial.print("Correct");
				restart = true;
			}
			else if (input > randomNum){
				lcd.print(", Guess lower!");
				Serial.print("Lower");
			}
			else if (input < randomNum){
				lcd.print(", Guess higher!");
				Serial.print("Higher");
			}
		}
	}
	delay(1000);
}