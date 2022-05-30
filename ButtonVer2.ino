#include "Keyboard.h"

const int buttonPin[] = {1, 2, 3};   //array that holds the pin number connected to each button
const int ledPin[] = {13, 12, 11};     //array that holds the pin number connected to each LED
int buttonAmount = 3;             //variable that holds the total number of buttons
int buttonState[] = {0, 0, 0};       //array that holds the button statuses
bool done[] = {false, false, false};     //array that holds info about if an action has been performed
/* the purpose of the done variables is to prevent actions from being performed multiple times
 if the button is having a long push down*/


void setup() {

  //initialize the button puns as inputs
  for (int i = 0; i < buttonAmount; i++) {
    pinMode(buttonPin[i], INPUT);
  }
  //initialize the LED pins as outputs
  for (int i = 0; i < buttonAmount; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  Keyboard.begin();
}

// function for executing actions based on which button was pressed
int outputAction(int currentButton) {

    //button1 opens closes current tab using ctrl+w
    if (currentButton == 1) {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('w');
      delay(100);
    }

    //button2 opens new tab using ctrl+t
    if (currentButton == 2) {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('t');
      delay(100);
    }

    //button3 types "slay" into a text box
    if (currentButton == 3) {
      Keyboard.print("slay");
      delay(100);
    }
}

void loop() {
  
  for (int i = 0; i < buttonAmount; i++)      //cycle through the array
    {
       buttonState[i] = digitalRead(buttonPin[i]); //read the status of each button

      //if a button is being pressed the state is HIGH
       if (buttonState[i] == HIGH && done[i] == false){
        // change done status to true, this is to ensure the action is being executed only once per push
        done[i] = true;
        // turn LED off
        digitalWrite(ledPin[i], HIGH);
        Serial.println(done[i]);
        //send the corresponding pin to the outputAction function
        outputAction(buttonPin[i]);
        //make sure that keys pressed from the action are released
        Keyboard.releaseAll();
       }
  
       if(buttonState[i] == LOW){
        //reset done status if necessary, this is in the situtation that a button was pressed then released
        done[i] = false;
        // turn LED on
        digitalWrite(ledPin[i], LOW);
        Keyboard.releaseAll();
       }
    }
}
