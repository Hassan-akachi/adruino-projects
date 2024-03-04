const int potPin = A0;  // Analog pin connected to the LDR
const int ledCount = 10;  // Number of LEDs
int ledPins[ledCount] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  // Digital pins connected to the LEDs

void setup() {


  Serial.begin(9600);
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {


  int sensorValue = analogRead(potPin);
  Serial.println(sensorValue);  // Print LDR value for calibration

  // Map the sensor value to the number of LEDs
  int numLEDs = map(sensorValue, 0, 1023, 0, ledCount);
  Serial.println(numLEDs);

  // Turn on/off LEDs based on the mapped value
  for (int i = 0; i < ledCount; i++) {
    if (i < numLEDs) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  delay(300);  // Adjust delay as needed for calibration
}
