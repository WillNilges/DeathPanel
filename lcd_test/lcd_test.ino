
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
//  recvWithStartEndMarkers();
//  showNewData();
  if (Serial.available() > 0){
    Serial.readBytes(receivedChars, numChars);
    lcd.clear();
    lcd.setCursor(0,1);
    for (int i = 0; i < numChars; i++){
      if (receivedChars[i]){
        lcd.print(receivedChars[i]);
        Serial.print(receivedChars[i]);
        }
    }
    Serial.flush();
  }
       // set the cursor to column 0, line 1
         // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
         // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
//  if (Serial.available()){
////    Serial.print("Serial Available.");
//    char rc = Serial.read();
//    Serial.print(rc);
//    lcd.setCursor(0,1);
//    lcd.print(rc);
//  }//else Serial.print("Serial not available.");
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();
        lcd.setCursor(0,1);
        lcd.print("Recv");
        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
//    lcd.setCursor(0,1);
//    lcd.print("No serial.");
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
        lcd.setCursor(0, 1);
        lcd.print(receivedChars);
    }
}
