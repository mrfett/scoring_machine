#include "Arduino.h"
#include "configurations.h"
#include "lines.h"

void hit_and_ground() {
   Serial.println("Hit and Ground");
   digitalWrite(onboard_led, HIGH);
   digitalWrite(fencer1_light, LOW);
   delay(debounce);
}

void ground_only() {
   Serial.println("Ground Only");
   digitalWrite(onboard_led, HIGH);
   digitalWrite(fencer1_light, LOW);
   delay(debounce);
}

void hit_only(int fencer) {
  int light = 0;
   if(fencer == 1) {
     light = fencer1_light;
   } else {
     light = fencer2_light;
   }
   Serial.println("Hit Only");
   digitalWrite(onboard_led, LOW);
   digitalWrite(light, HIGH);
   digitalWrite(buzzer, HIGH);
   delay(buzzer_length * 1000);
   digitalWrite(buzzer, LOW);
   delay((light_length * 1000) - (buzzer_length * 1000));
   digitalWrite(light, LOW);
}

void not_hit_or_ground() {
   //Serial.println("Neither Hit nor Ground");
   //digitalWrite(onboard_led, LOW);
   //digitalWrite(fencer1_light, LOW);
}

bool is_fencer1_grounded() {
  return digitalRead(fencer1_c) == HIGH;
}

bool is_fencer2_grounded() {
   return digitalRead(fencer2_c) == HIGH;
}

bool is_fencer1_hit() {
   return digitalRead(fencer1_b) == HIGH;
}

bool is_fencer2_hit() {
  return digitalRead(fencer2_b) == HIGH;
}

void loop() {
   //Serial.println("== Loop Start ==");

   bool fencer1_hit = is_fencer1_hit();
   bool fencer1_grounded = is_fencer1_grounded();

   bool fencer2_hit = is_fencer2_hit();
   bool fencer2_grounded = is_fencer2_grounded();

   if (fencer2_grounded && fencer1_hit) {
      hit_and_ground();
   } else if (fencer2_grounded) {
      ground_only();
   } else if (fencer1_hit) {
      hit_only(1);
   } else {
      not_hit_or_ground();
   }

   if (fencer1_grounded && fencer2_hit) {
     hit_and_ground();
   } else if (fencer1_grounded) {
     ground_only();
   } else if (fencer2_hit) {
     hit_only(2);
   } else {
     not_hit_or_ground();
   }
}
