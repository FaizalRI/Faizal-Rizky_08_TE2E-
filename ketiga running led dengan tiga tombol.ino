const int ledPins[] = {2, 3, 4}; 
const int buttonPins[] = {5, 6, 7};

bool autoMoveLeft = false;
bool autoMoveRight = false;

int currentLed = 0;
unsigned long previousMillis = 0;
const long interval = 300; 

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  if (digitalRead(buttonPins[0]) == LOW) {
    autoMoveLeft = true;
    autoMoveRight = false;
  } else if (digitalRead(buttonPins[1]) == LOW) {
    autoMoveLeft = false;
    autoMoveRight = true;
  } else if (digitalRead(buttonPins[2]) == LOW) {
    autoMoveLeft = true;
    autoMoveRight = false;
  }

  if (autoMoveLeft) {
    moveLeft();
  } else if (autoMoveRight) {
    moveRight();
  }
}

void moveLeft() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digitalWrite(ledPins[currentLed], LOW); 

    currentLed--; 
    if (currentLed < 0) {
      currentLed = 2; 
    }
    digitalWrite(ledPins[currentLed], HIGH); 
  }
}

void moveRight() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digitalWrite(ledPins[currentLed], LOW); 

    currentLed++; 
    if (currentLed > 2) {
      currentLed = 0; 
    }
    digitalWrite(ledPins[currentLed], HIGH); 
  }
}
