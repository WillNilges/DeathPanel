
#include <LiquidCrystal.h>
           // initialize the library with the numbers of the interface pins
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  Serial.begin(9600);
  Serial.println("<Slave ready>");
          // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
          // Print a message to the LCD.
  lcd.print("Hello");
}

void loop() {
  // Read serial data from master
  if (Serial.available() > 0){
    // Nuke the bottom row.
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    while(Serial.available() > 0){
      char chara = Serial.read();
      lcd.print(chara);
      Serial.print(chara);
    }
  }
  
  //print the number of seconds since reset:
  lcd.setCursor(0, 0);
  lcd.print("Runtime: ");
  lcd.print(millis() / 1000);
}
