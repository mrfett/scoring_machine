#include "Arduino.h"
#include "configurations.h"
#include "lines.h"


bool fencer1_scored = false;
bool fencer2_scored = false;
float fencer1_scored_at = 0;
float fencer2_scored_at = 0;

float calculate_time_since_scoring() {
   float oldest_scoring_time;
   if (fencer1_scored_at == 0) {
      oldest_scoring_time = fencer2_scored_at;
   } else if (fencer2_scored_at == 0) {
      oldest_scoring_time = fencer1_scored_at;
   } else {
      if (fencer1_scored_at < fencer2_scored_at) {
         oldest_scoring_time = fencer1_scored_at;
      } else {
         oldest_scoring_time = fencer2_scored_at;
      }
   }
   return millis() - oldest_scoring_time;
}

void loop() {
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


   if (!fencer1_scored) {
      if (reading1_b > threshold_low && reading2_c < threshold_low) {
         if (fencer2_scored) {
            if (calculate_time_since_scoring() < epee_timeout_duration) {
               fencer1_scored = true;
               fencer1_scored_at = millis();
            }
         } else {
            fencer1_scored = true;
            fencer1_scored_at = millis();
         }
      }
   }

   if (!fencer2_scored) {
      if (reading2_b > threshold_low && reading1_c < threshold_low) {
         if (fencer1_scored) {
            if (calculate_time_since_scoring() < epee_timeout_duration) {
               fencer2_scored = true;
               fencer2_scored_at = millis();
            }
         } else {
            fencer2_scored = true;
            fencer2_scored_at = millis();
         }
      }
   }

   if (fencer1_scored || fencer2_scored) {
      float time_since_scoring = calculate_time_since_scoring();

      if (time_since_scoring > light_length) {
         fencer1_scored = false;
         fencer2_scored = false;

         fencer1_scored_at = 0;
         fencer2_scored_at = 0;
      }

      if (time_since_scoring < buzzer_length) {
         digitalWrite(buzzer, HIGH);
      } else {
         digitalWrite(buzzer, LOW);
      }
   }

   if (fencer1_scored) {
      digitalWrite(fencer1_light, HIGH);
   } else {
      digitalWrite(fencer1_light, LOW);
   }

   if (fencer2_scored) {
      digitalWrite(fencer2_light, HIGH);
   } else {
      digitalWrite(fencer2_light, LOW);
   }
}
