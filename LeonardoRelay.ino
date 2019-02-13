#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int pinDeviceIn0 = 8;
const int pinDeviceOut0 = 6;
const int pinDeviceOut1 = 7;
 
int statusIn0 = LOW;             
int referenceStatusIn0 = LOW;
int statusOut0 = HIGH;      
int statusOut1 = LOW;

int switchedOut0 = 0;
int switchedOut1 = 0;

void setup() {
  pinMode(pinDeviceIn0, INPUT);
  pinMode(pinDeviceOut0, OUTPUT);
  pinMode(pinDeviceOut1, OUTPUT);

  digitalWrite(pinDeviceOut0, statusOut0);
  digitalWrite(pinDeviceOut1, statusOut1);

  statusIn0 = digitalRead(pinDeviceIn0);
  referenceStatusIn0 = statusIn0;
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Stables v2.1");
  lcd.setCursor(0, 1);
  lcd.print("Please wait...");
  delay(1000);
  lcd.clear();
}

void loop() {
  int reading1 = digitalRead(pinDeviceIn0);
  delay(500);
  int reading2 = digitalRead(pinDeviceIn0);
  delay(500);
  int reading3 = digitalRead(pinDeviceIn0);

  if (reading1 != referenceStatusIn0 && reading2 != referenceStatusIn0 && reading3 != referenceStatusIn0) {
    statusOut0 = !statusOut0;
    statusOut1 = !statusOut1;

    digitalWrite(pinDeviceOut0, statusOut0);
    digitalWrite(pinDeviceOut1, statusOut1);

    switchedOut0++;
    switchedOut1++;

    lcd.clear();
  }

  lcd.setCursor(0, 0);
  lcd.print("Relay1: ");
  lcd.print(statusOut0);
  lcd.print(" ");
  lcd.print(switchedOut0);
 
  lcd.setCursor(0, 1);
  lcd.print("Relay2: ");
  lcd.print(statusOut1);
  lcd.print(" ");
  lcd.print(switchedOut1);
}
