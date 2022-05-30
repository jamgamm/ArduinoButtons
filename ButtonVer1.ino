/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

#include "Keyboard.h"

// constants won't change. They're used here to set pin numbers:
const int buttonPinRed = 1;     // the number of the pushbutton pin
const int ledPinRed =  13;      // the number of the LED pin

const int buttonPinGreen = 2;     
const int ledPinGreen = 12;      

const int buttonPinYellow = 3;     
const int ledPinYellow = 11;      

// variables will change:
int buttonStateRed = 0;         // variable for reading the pushbutton status
int buttonStateGreen = 0;
int buttonStateYellow = 0;
bool doneRed = false;           // variable for checking if an action has been performed
bool doneGreen = false;       
bool doneYellow = false;       
/* the purpose of the done variables is to prevent actions from being done multiple times
 if the button is having a long push down*/

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinRed, INPUT);
  pinMode(buttonPinGreen, INPUT);
  pinMode(buttonPinYellow, INPUT);
  Keyboard.begin();
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateRed = digitalRead(buttonPinRed);
  buttonStateGreen = digitalRead(buttonPinGreen);
  buttonStateYellow = digitalRead(buttonPinYellow);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateRed == HIGH && doneRed == false) {
    // change done status to true, this is to ensure the action is being executed only once per push
    doneRed = true;
    // turn LED on:
    digitalWrite(ledPinRed, HIGH);
    Serial.println(doneRed);
    // press ctrl + w for opening a new window
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('w');
    delay(100);
    // release the pressed keys
    Keyboard.releaseAll();
  }
  if (buttonStateRed == LOW) {
    // turn LED off:
    doneRed = false;
    digitalWrite(ledPinRed, LOW);
    Keyboard.releaseAll();
  }

  if (buttonStateGreen == HIGH && doneGreen == false) {
    // turn LED on:
    doneGreen = true;
    digitalWrite(ledPinGreen, HIGH);
    Serial.println(doneGreen);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('t');
    delay(100);
    Keyboard.releaseAll();
  }
  if (buttonStateGreen == LOW) {
    // turn LED off:
    doneGreen = false;
    digitalWrite(ledPinGreen, LOW);
    Keyboard.releaseAll();
  }

  if (buttonStateYellow == HIGH && doneYellow == false) {
    // turn LED on:
    doneYellow = true;
    digitalWrite(ledPinYellow, HIGH);
    Serial.println(doneYellow);
    Keyboard.print("slay");
    delay(100);
    Keyboard.releaseAll();
  }
  if (buttonStateYellow == LOW) {
    // turn LED off:
    doneYellow = false;
    digitalWrite(ledPinYellow, LOW);
    Keyboard.releaseAll();
  }

}
