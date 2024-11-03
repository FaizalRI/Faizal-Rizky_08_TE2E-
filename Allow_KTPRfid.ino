#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10   
#define RST_PIN 9   

MFRC522 rfid(SS_PIN, RST_PIN); 


const String validKTPUID = "5:8f:49:29:8e:a2:0"; 

void setup() {
  Serial.begin(9600); 
  SPI.begin();       
  rfid.PCD_Init();    
  Serial.println("Scan KTP atau tag RFID...");
}

void loop() {
  // Periksa apakah ada kartu yang terdeteksi
  if (rfid.PICC_IsNewCardPresent()) {
    if (rfid.PICC_ReadCardSerial()) {
      
      String uidString = "";
      for (byte i = 0; i < rfid.uid.size; i++) {
        uidString += String(rfid.uid.uidByte[i], HEX);
        if (i < rfid.uid.size - 1) {
          uidString += ":";
        }
      }

      Serial.print("UID kartu: ");
      Serial.println(uidString);

      
      if (uidString.equalsIgnoreCase(validKTPUID)) {
        Serial.println("ALLOW");
      } else {
        Serial.println("DENY");
      }


      
    }
  }
}
