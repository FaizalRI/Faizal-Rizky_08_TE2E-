#include <Servo.h>
const int potensiometerPin = A0;  
Servo servo;                      
void setup() {
  servo.attach(9);               
}
void loop() {
  
  int nilaiPotensiometer = analogRead(potensiometerPin);
  int sudutServo = map(nilaiPotensiometer, 0, 1023, 0, 180);
  servo.write(sudutServo);

  delay(15); 
}
