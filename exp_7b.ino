#include <LiquidCrystal.h>

// Define LCD pin configuration
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Define potentiometer pin
const int potPin = A0;

void setup() {
  // Set up the LCD
  lcd.begin(16, 2);  // Adjust the numbers (16, 2) based on your LCD size

  // Set up the potentiometer pin
  pinMode(potPin, INPUT);
}

void loop() {
  // Read the potentiometer value
  int contrastValue = analogRead(potPin);

  // Map the potentiometer value to the contrast range
  int contrast = map(contrastValue, 0, 1023, 0, 255);

  // Set the contrast of the LCD
  lcd.setContrast(contrast);

  // Display "Hello, World!" on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");

  // Wait for a moment before updating the contrast again
  delay(500);
}