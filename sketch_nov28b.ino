#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

#define BUTTON A0

const int ledPins[] = {LED1, LED2, LED3, LED4};
const int buttonPin = BUTTON;

int state = 0;
bool buttonPressed = false;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; ++i) {
    pinMode (ledPins[i], OUTPUT);
 
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin) == HIGH &&! buttonPressed) {
    buttonPressed = true;
    state = (state + 1) % 4;
    for (int i = 0; i < 4; ++i) {
      digitalWrite(ledPins[i], i == state ? HIGH : LOW);
    }
  }
  else if (digitalRead(buttonPin) == LOW) {
    buttonPressed = false;
  }
  delay(50);
}
