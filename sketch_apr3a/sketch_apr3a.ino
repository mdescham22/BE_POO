
int ledPin = 5;
int buttonPin = 13;
int temp = 0;

void setup() {
  // initialize GPIO 2 as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  temp = digitalRead(buttonPin);
     if (temp == HIGH) {
        digitalWrite(ledPin, HIGH);
        Serial.println("LED Turned ON");
        delay(1000);
       }
     else {
        digitalWrite(ledPin, LOW);
        Serial.println("LED Turned OFF");
        delay(1000);
       }
}