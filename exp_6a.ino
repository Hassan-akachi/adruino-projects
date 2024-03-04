// Pin configuration
const int rs = 12;       // Register select pin
const int en = 11;       // Enable pin
const int d4 = 5;        // Data pin 4
const int d5 = 4;        // Data pin 5
const int d6 = 3;        // Data pin 6
const int d7 = 2;        // Data pin 7
const int contrastPin = A0; // Potentiometer connected to analog pin A0

void setup() {
  // Initialize the LCD
  pinMode(rs, OUTPUT);
  pinMode(en, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(d5, OUTPUT);
  pinMode(d6, OUTPUT);
  pinMode(d7, OUTPUT);
  
  // Display "Hello, World!"
  sendCommand(0b00111000); // Function set: 8-bit, 2-line, 5x8 dots
  sendCommand(0b00001100); // Display on, cursor off, blink off
  sendCommand(0b00000110); // Entry mode set: increment cursor, no shift
  sendCommand(0b10000000); // Set DD RAM address to 0

  printString("Hello, World!");
}

void loop() {
  // Read the potentiometer value
  int contrastValue = analogRead(contrastPin);
  
  // Adjust contrast based on potentiometer reading
  contrastValue = map(contrastValue, 0, 1023, 0, 63); // Map to LCD contrast range
  sendCommand(0b00111000 | contrastValue); // Update function set with contrast value
  
  delay(100); // Adjust the delay based on your needs
}

void sendCommand(byte value) {
  digitalWrite(rs, LOW);    // Set RS to command mode
  sendNibble(value >> 4);    // Send higher 4 bits
  sendNibble(value & 0x0F);  // Send lower 4 bits
  delayMicroseconds(50);     // Delay for stability
}

void sendData(byte value) {
  digitalWrite(rs, HIGH);   // Set RS to data mode
  sendNibble(value >> 4);    // Send higher 4 bits
  sendNibble(value & 0x0F);  // Send lower 4 bits
  delayMicroseconds(50);     // Delay for stability
}

void sendNibble(byte value) {
  digitalWrite(d4, value & 0x01);
  digitalWrite(d5, value & 0x02);
  digitalWrite(d6, value & 0x04);
  digitalWrite(d7, value & 0x08);
  pulseEnable();
}

void pulseEnable() {
  digitalWrite(en, HIGH);
  delayMicroseconds(1);
  digitalWrite(en, LOW);
  delayMicroseconds(1);
}

void printString(const char *str) {
  while (*str) {
    sendData(*str);
    str++;
  }
}