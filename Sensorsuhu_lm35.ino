#define LM35_PIN A0 

void setup() {
  Serial.begin(9600); 
}

void loop() {
 
  int sensorValue = analogRead(LM35_PIN);
  
  
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperature = voltage * 100; 

  
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" *C");

  
  delay(2000);
}
