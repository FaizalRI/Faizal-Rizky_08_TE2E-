void setup() {

  Serial.begin(9600);
}

void loop() {
  
  int nilaiADC = analogRead(A0);

  Serial.println(nilaiADC);

  delay(100); 
}
 