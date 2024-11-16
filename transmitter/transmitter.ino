#define LED_PIN 8
#define PERIOD 14
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10};
byte colPins[COLS] = {9, 5, 7, 6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char Key = keypad.getKey();
  if (Key) {
  digitalWrite(LED_PIN, HIGH);
   if (Key == '1')
    {
       send_data("Welcome to LI-FI IT MY PROJECT");
    }
    else  if (Key == '2')
    {
       send_data("MY NAME IS MUQTADA");
    }
     else  if (Key == '3')
    {
       send_data("I AM COMPUTER ENGINEER");
    }
     else  if (Key == '4')
    {
       send_data("LI-FI USES LIGHT FOR DATA TRANSMISSION");
    }
  }

}

void send_data(const char *my_message) {
    char my_sentence[50];
  strcpy(my_sentence, my_message); 
  delay(PERIOD);

  for (int j = 0; j < strlen(my_sentence); j++) {
    for (int i = 7; i >= 0; i--) {
      
      digitalWrite(LED_PIN, bitRead(my_sentence[j], i) != 0);
      delay(PERIOD);
    }
  }

  
  digitalWrite(LED_PIN, HIGH);
  delay(100); 
}
