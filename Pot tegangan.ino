void setup() {
  
  Serial.begin(9600);
}

void loop() {
 
  int nilaiADC = analogRead(A0);
  
  float tegangan = (nilaiADC * 5.0) / 1023.0;
  Serial.print("Nilai ADC: ");
  Serial.print(nilaiADC);
  Serial.print(" - Tegangan: ");
  Serial.print(tegangan);
  Serial.println(" V");
  
  delay(100); 
}
