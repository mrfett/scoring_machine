#include "Arduino.h"
#include "configurations.h"
#include "lines.h"

// Variables will change as the program runs
boolean fencer1_hit_state = false;      // State of the fencer1 B line
//boolean fencer2_hit_state = false;      // State of the fencer2 B line

//boolean fencer1_ground_state = false; // State of the fencer2 C line
boolean fencer2_ground_state = false; // State of the fencer1 C line

void run() {
   Serial.println("== Loop Start ==");
   
   // Check Hit and Ground States
   if (digitalRead(fencer1_b) == HIGH) {
      fencer1_hit_state = true;
   } else {
      fencer1_hit_state = false;
   }
   if (digitalRead(fencer2_c) == HIGH) {
      fencer2_ground_state = true;
   } else {
      fencer2_ground_state = false;
   }
   
   if (fencer2_ground_state && fencer1_hit_state) {
      Serial.println("Hit and Ground");
      digitalWrite(onboard_led, HIGH);
      digitalWrite(fencer1_light, LOW);
      delay(debounce);
   } else if (fencer2_ground_state) {
      Serial.println("Ground Only");
      digitalWrite(onboard_led, HIGH);
      digitalWrite(fencer1_light, LOW);
      delay(debounce);
   } else if (fencer1_hit_state) {
      Serial.println("Hit Only");
      digitalWrite(onboard_led, LOW);
      digitalWrite(fencer1_light, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(buzzer_length * 1000);
      digitalWrite(buzzer, LOW);
      delay((light_length * 1000) - (buzzer_length * 1000));
      digitalWrite(fencer1_light, LOW);
      
   } else {
      Serial.println("Neither Hit nor Ground");
      digitalWrite(onboard_led, LOW);
      digitalWrite(fencer1_light, LOW);
   }
}
