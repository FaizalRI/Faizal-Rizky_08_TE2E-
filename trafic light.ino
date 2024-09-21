const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;


void setup() {
  // Set pin sebagai output
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

}

void loop() {
  
  digitalWrite(redPin, HIGH);
  delay(3000);

  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(2000); 

  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(3000); 

  digitalWrite(greenPin, LOW);

}
