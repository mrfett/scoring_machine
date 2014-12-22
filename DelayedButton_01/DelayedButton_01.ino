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
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int instantLedPin =  13;      // the number of the LED pin
const int delayedLedPin = 8; // Should only fire after a 5sec button press
const int delayAmount = 3000; // Delay in milliseconds
const int debug = 0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int lastButtonState = 0;    // variable for catching a change in button state
long lastPress = 0;          // variable for catching the time of the button press

void setup() {
  // initialize the LED pins as outputs:
  pinMode(instantLedPin, OUTPUT);
  pinMode(delayedLedPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  if (debug) {
    Serial.begin(9600);
    Serial.println("Hello world");
    delay(2000);// Give reader a chance to see the output.
  }
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  if (buttonState == HIGH) {     
    digitalWrite(instantLedPin, HIGH); // turn instantLed on:    
    if (lastButtonState != buttonState) {
      lastPress = millis(); // First press, set the time
    } else {
      if (millis() - lastPress >= delayAmount) {
        digitalWrite(delayedLedPin, HIGH); // button pressed for > 5 sec, turn on delayed LED
        delay(3000);
        digitalWrite(delayedLedPin, LOW); // button pressed for > 5 sec, turn on delayed LED
        buttonState = 0;
        lastButtonState = 0;
        lastPress = 0;
      } 
    }
  } 
  else {
    digitalWrite(instantLedPin, LOW); // turn instantLed off
    if (lastButtonState != buttonState) {
      //button pressed for < 5 sec
    }
  }
  lastButtonState = buttonState;
  if (debug) {
    Serial.println(lastButtonState);
    Serial.println(lastPress);
    Serial.println(buttonState);
    delay(500);
  }
}
