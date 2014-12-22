/*
Fencing Scoring Machine


*/

// Constants: Timimg

// Foil
const int foil_minimum_touch_duration = 14;         // Touch duration in milliseconds
const int foil_timeout_duration = 300;              // Stop registering touches after x milliseconds
const int foil_light_duration = 5000                // How long the LEDs are lit
const int foil_sound_duration = 2000                // How long the buzzer sounds

// Epee
const int epee_minimum_touch_duration = 0;          // Touch duration in milliseconds
const int epee_timeout_duration = 40;               // Stop registering touches after x milliseconds
const int epee_light_duration = 5000                // How long the LEDs are lit
const int epee_sound_duration = 2000                // How long the buzzer sounds

// Saber
const int saber_minimum_touch_duration = 0.1;       // Touch duration in milliseconds
const int saber_timeout_duration = 120;             // Stop registering touches after x milliseconds
const int saber_whipover_allowance = 4;             // Register touches that occur simultaniously with contact with the opponents weapon
const int saber_whipover_duration = 15;             // Do not register touches that occur right after contact with the opponents weapon
const int saber_whipover_interrupt_limit = 10;      // number of times the blades can lose contact to count as whipover
const int saber_light_duration = 5000               // How long the LEDs are lit
const int saber_sound_duration = 2000               // How long the buzzer sounds

// Debug
int debug = 0;

// Pin Setup: 

void setup() {

  if (debug) {
    Serial.begin(9600);
    Serial.println("Hello world");
    delay(2000);// Give reader a chance to see the output.
  }
  
    if (debug) {
    Serial.println('Setup Complete.');
  }
}

void loop(){
  if (debug) {
    Serial.println('Beginning loop...');
  }
}
