#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LM35_PIN A0      // Pin analog untuk sensor LM35
#define LED_PIN 8        // Pin untuk LED
#define BUZZER_PIN 9     // Pin untuk Buzzer

// Inisialisasi LCD dengan alamat I2C (ganti 0x27 jika alamat berbeda)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600); 
  lcd.begin(1,5);       
  lcd.backlight();    
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


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(temperature);
  lcd.print(" *C");

  
  if (temperature >= 25) {
    digitalWrite(LED_PIN, HIGH); 
    digitalWrite(BUZZER_PIN, HIGH); 
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW); 
  }

 
  delay(2000);
}
