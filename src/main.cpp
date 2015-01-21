/*
   Grounding Test

    1. See if a button can be connected to two pins instead of ground without destroying the Arduino
    2. See if resistors will allow control over which path the current takes

 created 2015
 by B.J. Self


 */

// Constants won't change.
#include "Arduino.h"
#include "lines.h"
#include "pin_setup.h"

const boolean DEBUG = true;               // Set to true to use the serial debugger

void signal_setup_complete() {
   for (int i=0; i < 5; i++) {
      digitalWrite(onboard_led, HIGH);
      delay(250);
      digitalWrite(onboard_led, LOW);
      delay(250);
   }

   digitalWrite(buzzer, HIGH);
   delay(250);
   digitalWrite(buzzer, LOW);
}

void setup() {
   // Set up debugging
   if (DEBUG) {
      Serial.begin(9600);
      Serial.println("Debugging Started...");
   }

   setup_pins();

   signal_setup_complete();
}
