#define LDR_PIN A0
#define THRESHOLD 500 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 
bool receiveDataFlag = false;  
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(2, 0); 
  lcd.print("Hello World!");
  lcd.setCursor(2, 1); 
  lcd.print("Welcome");
  delay(1000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(LDR_PIN);

  if (sensorValue > THRESHOLD && !receiveDataFlag) {
    receiveDataFlag = true;
  }

  if (receiveDataFlag) {
    receive_data();
  }
}

void receive_data() {
 
  
  char received_sentence[32]; 

  for (int j = 0; j < 32; j++) { 
    char received_byte = 0;

    for (int i = 7; i >= 0; i--) {
      int bit_value = analogRead(LDR_PIN) > THRESHOLD;
      received_byte |= (!bit_value << i);
      delay(14);  
    }

    received_sentence[j] = received_byte;
  }

 
  lcd.setCursor(0, 0);
  lcd.print(received_sentence);

  lcd.setCursor(0, 1);
  lcd.print(received_sentence + 16);

  receiveDataFlag = false;
}
