int red = 2; //vehicles
int yellow = 3;
int green = 4; //pedestrian
int red2 = 5;
int green2 = 6; // switch is on pin 12
int button = 8;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(red2, OUTPUT);
    pinMode(green2, OUTPUT);
    
    pinMode(button, INPUT);
}


void loop() {
    if (digitalRead(button) == HIGH){
        delay(15); // software debounce
        if (digitalRead(button) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            for(int i = 0; i < 3 ; i++) {
              changeLights();

            }
            // delay(15000); // wait for 15 seconds
        }
    }
}

void changeLights(){

// turn off yellow, then turn red on for 5 seconds, then 2nd green on
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red2, LOW);
    delay(4000);

    // green off, yellow on for 3 seconds
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(3000);

    
     // turn off red and yellow, then turn on green
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(green2, LOW);
    digitalWrite(red2, HIGH);
    delay(5000);


     digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(red2, LOW);

    // red and yellow on for 2 seconds (red is already on though)
    // digitalWrite(yellow, HIGH);
    // delay(2000);
}
