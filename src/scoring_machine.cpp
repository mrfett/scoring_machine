#include "Arduino.h"
#include "configurations.h"
#include "lines.h"

void hit_and_ground() {
   Serial.println("Hit and Ground");
   digitalWrite(onboard_led, HIGH);
   digitalWrite(fencer1_light, LOW);
   digitalWrite(fencer2_light, LOW);
   delay(debounce);
}

void ground_only() {
   Serial.println("Ground Only");
   digitalWrite(onboard_led, HIGH);
   digitalWrite(fencer1_light, LOW);
   digitalWrite(fencer1_light, LOW);
   delay(debounce);
}

void hit_only(int fencer) {
  touch_time = millis();
  int light = 0;
   if(fencer == 1) {
     light = fencer1_light;
   } else {
     light = fencer2_light;
   }
   Serial.println("Hit Only");
   digitalWrite(onboard_led, LOW);
   digitalWrite(light, HIGH);
   if (!mute) {
     digitalWrite(buzzer, HIGH);
     delay(buzzer_length * 1000);
     digitalWrite(buzzer, LOW);
     delay((light_length * 1000) - (buzzer_length * 1000));
   } else {
     delay(light_length * 1000);
   }
   digitalWrite(light, LOW);
}

void not_hit_or_ground() {
   //Serial.println("Neither Hit nor Ground");
   digitalWrite(onboard_led, LOW);
   digitalWrite(fencer1_light, LOW);
   digitalWrite(fencer2_light, LOW);
}

bool is_fencer1_grounded() {
  if (threshold_medium > analogRead(fencer1_c) > threshold_low) {
    return true;
  } else {
    return false;
  }
  //return digitalRead(fencer1_c) == HIGH;
}

bool is_fencer2_grounded() {
  if (threshold_medium > analogRead(fencer2_c) > threshold_low) {
    return true;
  } else {
    return false;
  }
   //return digitalRead(fencer2_c) == HIGH;
}

bool is_fencer1_hit() {
  int reading = analogRead(fencer1_b);
  if (threshold_high > reading > threshold_medium) {
    return true;
    Serial.println("Is Fencer 1 Hit: True");
  } else {
    return false;
    Serial.println("Is Fencer 1 Hit: False");
  }
   //return digitalRead(fencer1_b) == HIGH;
}

bool is_fencer2_hit() {
  if (threshold_high > analogRead(fencer2_b) > threshold_medium) {
    return true;
  } else {
    return false;
  }
  //return digitalRead(fencer2_b) == HIGH;
}

void loop() {
   //Serial.println("== Loop Start ==");
   /*
   Serial.println("Fencer 1:");
   Serial.println(analogRead(fencer1_a));
   Serial.println(analogRead(fencer1_b));
   Serial.println(analogRead(fencer1_c));
   Serial.println("============");

   Serial.println("Fencer 2:");
   Serial.println(analogRead(fencer2_a));
   Serial.println(analogRead(fencer2_b));
   Serial.println(analogRead(fencer2_c));
   Serial.println("============");
   delay(1000);
   */

   int reading1_a = analogRead(fencer1_a);
   int reading1_b = analogRead(fencer1_b);
   int reading1_c = analogRead(fencer1_c);
   int reading2_a = analogRead(fencer2_a);
   int reading2_b = analogRead(fencer2_b);
   int reading2_c = analogRead(fencer2_c);

   if (threshold_low < reading1_b && reading1_b < threshold_medium) {
     hit_and_ground();
   }
   if (threshold_medium < reading1_b && reading1_b < threshold_high) {
     hit_only(1);
   }
   if (reading1_b < threshold_low) {
     not_hit_or_ground();
   }

   if (threshold_low < reading2_b && reading2_b < threshold_medium) {
     hit_and_ground();
   }
   if (threshold_medium < reading2_b && reading2_b < threshold_high) {
     hit_only(2);
   }
   if (reading2_b < threshold_low) {
     not_hit_or_ground();
   }
   /*
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
   */
}
