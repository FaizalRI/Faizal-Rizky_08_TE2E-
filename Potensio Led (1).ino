const int potensiometerPin = A0; 
const int ledPin = 9;             

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);      
}

void loop() {
  
  int nilaiPotensiometer = analogRead(potensiometerPin); 
  
  int nilaiPWM = map(nilaiPotensiometer, 0, 1023, 0, 255); 
  
  analogWrite(ledPin, nilaiPWM); 

  Serial.print("Nilai Potensiometer: ");
  Serial.print(nilaiPotensiometer);
  Serial.print(" - Nilai PWM: ");
  Serial.println(nilaiPWM);
  
  delay(100); 
}
