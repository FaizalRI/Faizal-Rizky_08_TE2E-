const int ledCount = 3;
const int ledPins[ledCount] = {2, 3, 4};

void setup() {
  // Mengatur semua pin LED sebagai output
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(500);
      digitalWrite(ledPins[i], LOW);
    } 
  
}