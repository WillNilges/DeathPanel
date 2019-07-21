
#include <LiquidCrystal.h>
           // initialize the library with the numbers of the interface pins
const byte numChars = 32;
char receivedChars[numChars];
String lastReceive = "";
boolean newData = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  Serial.begin(9600);
  Serial.println("<Slave ready>");
          // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
          // Print a message to the LCD.
  lcd.print("Hello");
  pinMode(A1, OUTPUT); digitalWrite(A1, 1); // Power indicator™
}

void loop() {
  // Read serial data from master
  if (Serial.available() > 0){
    String newReceive = "";
    // Nuke the bottom row.
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    while(Serial.available() > 0){
      char chara = Serial.read();
      newReceive += chara;
      lcd.print(chara);
      Serial.print(chara);
    }
//    lcd.setCursor(0,8);
    lcd.print(" Last: ");
    lcd.print(lastReceive);
    lastReceive = newReceive;
  }
  
  //print the number of seconds since reset:
  lcd.setCursor(0, 0);
  lcd.print("Runtime: ");
  lcd.print(millis() / 1000);
  lcd.print("s");

  // Just totally screwing around at this point.
  if (lastReceive == "B10") lcd.print(" :3");
  else if (lastReceive == "B8") lcd.print(" >:(");
  else if (lastReceive == "B6") lcd.print(" :D");
  else if (lastReceive == "B4") lcd.print(" :O");
  else if (lastReceive == "B2") lcd.print(" :L");
  else lcd.print("    ");
}
