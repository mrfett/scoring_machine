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

void debug_loop() {
  Serial.println("Debug Mode!");

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

  //Serial.end();

  return;
}

void foil_loop() {
  Serial.println("Foil Mode!");

  return;
}

void read_pins(int fencer1_values[], int fencer2_values[]) {
  fencer1_values[0] = analogRead(fencer1_a);
  fencer1_values[1] = analogRead(fencer1_b);
  fencer1_values[2] = analogRead(fencer1_c);

  fencer2_values[0] = analogRead(fencer2_a);
  fencer2_values[1] = analogRead(fencer2_b);
  fencer2_values[2] = analogRead(fencer2_c);
}

void epee_loop() {
  Serial.println("Epee Mode!");

  read_pins(fencer1_values, fencer2_values);

  /*
  int reading1_a = analogRead(fencer1_a);
  int reading1_b = analogRead(fencer1_b);
  int reading1_c = analogRead(fencer1_c);
  int reading2_a = analogRead(fencer2_a);
  int reading2_b = analogRead(fencer2_b);
  int reading2_c = analogRead(fencer2_c);
  */

  if (!fencer1_scored) {
     if (fencer1_values[1] > threshold_low && fencer2_values[2] < threshold_low) {
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
     if (fencer2_values[1] > threshold_low && fencer1_values[2] < threshold_low) {
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

  return;
}

int increment_mode(int current_mode) {
  int new_mode = current_mode + 1;

  if (new_mode >= total_modes) {
    new_mode = 0;
  }

  return new_mode;
}

void loop() {
  if (digitalRead(mode_button) == LOW) {
    digitalWrite(mode_button_led, LOW);
    Serial.println("Mode Change:");

    delay(500);
    mode = increment_mode(mode);
    digitalWrite(mode_button_led, HIGH);
  }

  if (mode == 1) {
    epee_loop();
  } else if (mode == 2) {
    foil_loop();
  } else if (mode == 0) {
    debug_loop();
  }

}
