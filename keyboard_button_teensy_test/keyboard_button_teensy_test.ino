/* Buttons to USB Keyboard Example

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(13, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(14, 10);  // to rapid touch, you can
Bounce button7 = Bounce(15, 10);  // increase this time.
Bounce button8 = Bounce(16, 10);
Bounce button9 = Bounce(17, 10);
Bounce button10 = Bounce(18, 10);
Bounce button11 = Bounce(11, 10);

void setup() {
  Serial5.begin(9600);
  Serial5.println("<Master is ready>");
  
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();

  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) {
    Keyboard.println("B0 press");
    Serial5.print("B0");
  }
  if (button1.fallingEdge()) {
    Keyboard.println("B1 press");
    Serial5.print("B1");
  }
  if (button2.fallingEdge()) {
    Keyboard.println("B2 press");
    Serial5.print("B2");
  }
  if (button3.fallingEdge()) {
    Keyboard.println("B3 press");
    Serial5.print("B3");
  }
  if (button4.fallingEdge()) {
    Keyboard.println("B4 press");
    Serial5.print("B4");
  }
  if (button5.fallingEdge()) {
    Keyboard.println("B5 press");
    Serial5.print("B5");
  }
  if (button6.fallingEdge()) {
    Keyboard.println("B6 press");
    Serial5.print("B6");
  }
  if (button7.fallingEdge()) {
    Keyboard.println("B7 press");
    Serial5.print("B7");
  }
  if (button8.fallingEdge()) {
    Keyboard.println("B8 press");
    Serial5.print("B8");
  }
  if (button9.fallingEdge()) {
    Keyboard.println("B9 press");
    Serial5.print("B9");
  }
  if (button10.fallingEdge()) {
    Keyboard.println("B10 press");
    Serial5.print("B10");
  }
  if (button11.fallingEdge()) {
    Keyboard.println("B11 press");
    Serial5.print("B11");
  }

  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.risingEdge()) {
    Keyboard.println("B0 release");
  }
  if (button1.risingEdge()) {
    Keyboard.println("B1 release");
  }
  if (button2.risingEdge()) {
    Keyboard.println("B2 release");
  }
  if (button3.risingEdge()) {
    Keyboard.println("B3 release");
  }
  if (button4.risingEdge()) {
    Keyboard.println("B4 release");
  }
  if (button5.risingEdge()) {
    Keyboard.println("B5 release");
  }
  if (button6.risingEdge()) {
    Keyboard.println("B6 release");
  }
  if (button7.risingEdge()) {
    Keyboard.println("B7 release");
  }
  if (button8.risingEdge()) {
    Keyboard.println("B8 release");
  }
  if (button9.risingEdge()) {
    Keyboard.println("B9 release");
  }
}
