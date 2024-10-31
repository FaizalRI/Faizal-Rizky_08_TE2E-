
const int redPin = 2;
const int yellowPin = 3;
const int greenPin = 4;

const int segA1 = 5;
const int segB1 = 6;
const int segC1 = 7;
const int segD1 = 8;
const int segE1 = 9;
const int segF1 = 10;
const int segG1 = 11;

const int segA2 = 12;
const int segB2 = A0;
const int segC2 = A1;
const int segD2 = A2;
const int segE2 = A3;
const int segF2 = A4;
const int segG2 = A5;

const int buttonPin = 13;

int buttonState = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  pinMode(segA1, OUTPUT);
  pinMode(segB1, OUTPUT);
  pinMode(segC1, OUTPUT);
  pinMode(segD1, OUTPUT);
  pinMode(segE1, OUTPUT);
  pinMode(segF1, OUTPUT);
  pinMode(segG1, OUTPUT);

  pinMode(segA2, OUTPUT);
  pinMode(segB2, OUTPUT);
  pinMode(segC2, OUTPUT);
  pinMode(segD2, OUTPUT);
  pinMode(segE2, OUTPUT);
  pinMode(segF2, OUTPUT);
  pinMode(segG2, OUTPUT);
  
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(redPin, HIGH);
    
    for (int i = 20; i >= 0; i--) {
      displayNumber(i); 
      delay(1000); 
    }
    
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    
    delay(10000); 
    
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    
    delay(2000);
  
    digitalWrite(yellowPin, LOW);
  }
}

void displayNumber(int num) {
  int tens = num / 10;
  int units = num % 10;

  displaySingleDigit(tens, segA1, segB1, segC1, segD1, segE1, segF1, segG1);
  
  displaySingleDigit(units, segA2, segB2, segC2, segD2, segE2, segF2, segG2);
}

void displaySingleDigit(int digit, int a, int b, int c, int d, int e, int f, int g) {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);

  switch(digit) {
    case 0: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); break;
    case 1: digitalWrite(b, HIGH); digitalWrite(c, HIGH); break;
    case 2: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(g, HIGH); break;
    case 3: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(g, HIGH); break;
    case 4: digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 5: digitalWrite(a, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 6: digitalWrite(a, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 7: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); break;
    case 8: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    case 9: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break;
    default: break; 
  }
}
