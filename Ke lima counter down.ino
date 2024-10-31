
const int a1 = 7;
const int b1 = 8;
const int c1 = 9;
const int d1 = 10;
const int e1 = 11;
const int f1 = 12;
const int g1 = 13;

const int a2 = 0;
const int b2 = 1;
const int c2 = 2;
const int d2 = 3;
const int e2 = 4;
const int f2 = 5;
const int g2 = 6;

int countdown = 20;  
unsigned long previousMillis = 0;
const long interval = 1000;  

int segments[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void displayDigit(int digit, int displayPins[7]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(displayPins[i], segments[digit][i]);
  }
}

void setup() {
  int display1Pins[] = {a1, b1, c1, d1, e1, f1, g1};
  int display2Pins[] = {a2, b2, c2, d2, e2, f2, g2};
  
  for (int i = 0; i < 7; i++) {
    pinMode(display1Pins[i], OUTPUT);
    pinMode(display2Pins[i], OUTPUT);
  }

  displayNumber(countdown);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (countdown > 0) {
      countdown--;
    }

    displayNumber(countdown);
  }
}

void displayNumber(int number) {
  int tens = number / 10;
  int ones = number % 10;

  int display1Pins[] = {a1, b1, c1, d1, e1, f1, g1};
  int display2Pins[] = {a2, b2, c2, d2, e2, f2, g2};

  displayDigit(tens, display1Pins);

  displayDigit(ones, display2Pins);
}
