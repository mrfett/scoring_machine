#include "Arduino.h"
#include "lines.h"

void setup_pins() {
   // initialize buttons
   pinMode(fencer1_a, OUTPUT);
   digitalWrite(fencer1_a, HIGH);
   
   pinMode(fencer1_b, INPUT);
   
   pinMode(fencer2_c, INPUT);

   // initialize the lights:
   pinMode(fencer1_light, OUTPUT);
   
   pinMode(onboard_led, OUTPUT);
   
   // initialize the buzzer
   pinMode(buzzer, OUTPUT);
}
