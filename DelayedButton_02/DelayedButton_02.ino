/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 modified 15 Dec 2014
 by B.J. Self
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin1 = 2;         // the number of the pushbutton pin
const int buttonPin2 = 3;         // the number of the pushbutton pin
const int instantLedPin =  13;   // the number of the LED pin that will light as soon as the button is pressed
const int delayedLedPin1 = 8;     // Should only fire after a N sec button press
const int delayedLedPin2 = 7;     // Should only fire after a N sec button press
const int delayAmount = 3000;    // Amount of time button needs to be pressed to light the second LED
const int debug = 0;             // Set to 1 to use the serial debugger

// variables will change:
int buttonState1 = 0;          // variable for reading the pushbutton status
int buttonState2 = 0;          // variable for reading the pushbutton status
int lastbuttonState1 = 0;      // variable for catching a change in button state
int lastbuttonState2 = 0;      // variable for catching a change in button state
long lastPress1 = 0;           // variable for catching the time of the button press
long lastPress2 = 0;           // variable for catching the time of the button press

void setup() {
  // initialize the LED pins as outputs:
  pinMode(instantLedPin, OUTPUT);
  pinMode(delayedLedPin1, OUTPUT);
  pinMode(delayedLedPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  if (debug) {
    Serial.begin(9600);
    Serial.println("Hello world");
    delay(2000);// Give reader a chance to see the output.
  }
}

void loop(){
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed.
  if (buttonState1 == HIGH) {     
    digitalWrite(instantLedPin, HIGH); // turn instantLed on:    
    if (lastbuttonState1 != buttonState1) {
      lastPress1 = millis(); // First press, set the time
    } else {
      if (millis() - lastPress1 >= delayAmount) {
        digitalWrite(delayedLedPin1, HIGH); // button pressed for > 5 sec, turn on delayed LED
        delay(3000);
        digitalWrite(delayedLedPin1, LOW); // button pressed for > 5 sec, turn on delayed LED
        buttonState1 = 0;
        lastbuttonState1 = 0;
        lastPress1 = 0;
      } 
    }
  } 
  else if (buttonState1 == LOW) {
    digitalWrite(instantLedPin, LOW); // turn instantLed off
    if (lastbuttonState1 != buttonState1) {
      //button pressed for < 5 sec
    }
  }
  lastbuttonState1 = buttonState1;
  if (debug) {
    Serial.println(lastbuttonState1);
    Serial.println(lastPress1);
    Serial.println(buttonState1);
    delay(500);
  }
  
  
  // Same thing for button 2
  if (buttonState2 == HIGH) {     
    digitalWrite(instantLedPin, HIGH); // turn instantLed on:    
    if (lastbuttonState2 != buttonState2) {
      lastPress2 = millis(); // First press, set the time
    } else {
      if (millis() - lastPress2 >= delayAmount) {
        digitalWrite(delayedLedPin2, HIGH); // button pressed for > 5 sec, turn on delayed LED
        delay(3000);
        digitalWrite(delayedLedPin2, LOW); // button pressed for > 5 sec, turn on delayed LED
        buttonState2 = 0;
        lastbuttonState2 = 0;
        lastPress2 = 0;
      } 
    }
  } 
  else if (buttonState2 == LOW) {
    digitalWrite(instantLedPin, LOW); // turn instantLed off
    if (lastbuttonState2 != buttonState2) {
      //button pressed for < 5 sec
    }
  }
  lastbuttonState2 = buttonState2;
  if (debug) {
    Serial.println(lastbuttonState2);
    Serial.println(lastPress2);
    Serial.println(buttonState2);
    delay(500);
  }
}
