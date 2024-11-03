#define LM35_PIN A0 // Pin analog untuk sensor LM35
#define LED_PIN 8    // Pin untuk LED
#define BUZZER_PIN 9  // Pin untuk Buzzer

void setup() {
  Serial.begin(9600); 
  pinMode(LED_PIN, OUTPUT); 
  pinMode(BUZZER_PIN, OUTPUT); 
}

void loop() {
  
  int sensorValue = analogRead(LM35_PIN);
  
 
  float voltage = sensorValue * (5.0 / 1023.0); 
  float temperature = voltage * 100; 

  
  Serial.print("Suhu: ");
  Serial.print(temperature);
  Serial.println(" *C");

  
  if (temperature >= 25) {
    digitalWrite(LED_PIN, HIGH); 
    digitalWrite(BUZZER_PIN, HIGH); 
  } else {
    digitalWrite(LED_PIN, LOW); 
    digitalWrite(BUZZER_PIN, LOW);
  }


  delay(1000);
}
