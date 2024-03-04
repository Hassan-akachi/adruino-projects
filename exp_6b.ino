const int numLeds = 6;     // Number of LEDs
const int ledPins[numLeds] = {2, 3, 4, 5, 6, 7}; // Pins for each LED

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT); // Set each LED pin as an output
  }
}

void loop() {
  // Scroll LEDs to the right
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  // Turn on current LED
    delay(100);  // Adjust scrolling speed
    digitalWrite(ledPins[i], LOW);   // Turn off current LED
  }

  // Scroll LEDs to the left
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);  // Turn on current LED
    delay(100);  // Adjust scrolling speed
    digitalWrite(ledPins[i], LOW);   // Turn off current LED
  }
}