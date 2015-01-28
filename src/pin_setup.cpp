#include "Arduino.h"
#include "lines.h"

void setup_pins() {
   // initialize buttons
   pinMode(fencer1_a, INPUT);
   digitalWrite(fencer1_a, HIGH);

   pinMode(fencer2_a, INPUT);
   digitalWrite(fencer2_a, HIGH);

   pinMode(fencer1_b, INPUT);
   pinMode(fencer2_b, INPUT);

   pinMode(fencer2_c, INPUT);
   pinMode(fencer1_c, INPUT);

   // initialize the lights:
   pinMode(fencer1_light, OUTPUT);
   pinMode(fencer2_light, OUTPUT);

   pinMode(onboard_led, OUTPUT);

   // initialize the buzzer
   pinMode(buzzer, OUTPUT);
}
