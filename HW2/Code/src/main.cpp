#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

#define BUT_PIN 2

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 8, 7};

LiquidCrystal lcd(5, 4, 6, 3, 1, 0);

Keypad keyPad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String password = "1234";
String visiblePassword = "";
String unvisiblePassword = "";

volatile bool showPassword = false;
volatile bool change = false;

void toggleLCD(void) {
    showPassword = !showPassword;
    change = true;
}


void showValueOnLCD(){
    lcd.clear();
    if (showPassword) {
        lcd.print(visiblePassword);
    } else {
        lcd.print(unvisiblePassword);
    }
}

void setup() {
    lcd.begin(16, 2);
    pinMode(BUT_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(BUT_PIN), toggleLCD, RISING);
}

void loop() {
    int value = keyPad.getKey();
    if(value) {
        if(value >= '0' && value <= '9') {
            visiblePassword += (value - '0');
            unvisiblePassword += "*";
            change = true;
        }
        else if (value == '*') {
            lcd.clear();
            if (visiblePassword == password){
                lcd.print("Correct Password");
            } else {
                lcd.print("Wrong Password");
            }
            delay(3000);
            lcd.clear();
            visiblePassword = "";
            unvisiblePassword = "";
        }
        else if (value == '#') {
            visiblePassword.remove(visiblePassword.length() - 1);
            unvisiblePassword.remove(unvisiblePassword.length() - 1);
            change = true;
        }
    }
    if(change) {
        showValueOnLCD();
        change = false;
    }
}