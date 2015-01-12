/*
  Grounding Test
 
   1. See if a button can be connected to two pins instead of ground without destroying the Arduino
   2. See if resistors will allow control over which path the current takes 
 
 created 2015
 by B.J. Self
 

 */

// constants won't change. They're used here to 
// set pin numbers:
const int fencer1_a = 2;         // A Line for Fencer 1
const int fencer1_b = 3;         // B Line for Fencer 1
//const int fencer1_c = 4;         // C Line for Fencer 1

//const int fencer2_a = 6;         // A Line for Fencer 2
//const int fencer2_b = 7;         // B Line for Fencer 2
const int fencer2_c = 8;         // C Line for Fencer 2

const int fencer1_touch = 10;         // LED when fencer1 Hits

const boolean debug = true;             // Set to 1 to use the serial debugger
const int onboard_led = 13;      // Onboard LED for testing


void setup() {
  
  // initialize buttons
  pinMode(fencer1_a, INPUT);
  digitalWrite(fencer1_a, HIGH);
  
  //pinMode(fencer1_b, INPUT_PULLUP);
  
  //pinMode(fencer2_c, INPUT_PULLUP);

  // initialize the lights:
  pinMode(fencer1_touch, OUTPUT);
  digitalWrite(fencer1_touch, LOW);
  
  pinMode(onboard_led, OUTPUT);
  digitalWrite(onboard_led, LOW);

  // Set up debugging
  if (debug) {
    Serial.begin(9600);
    Serial.println("Hello world");
    delay(5000);// Give reader a chance to see the output.
  }
  
  // Signal when setup is done
  for (int i=0; i < 5; i++) {
    digitalWrite(onboard_led, HIGH);
    delay(500);
    digitalWrite(onboard_led, LOW);
    delay(500);
  }
}

void loop(){
  // check if the pushbutton is pressed.
  if (digitalRead(fencer1_a == LOW)) {
    if(debug) {Serial.println('Button Pressed!');}
    digitalWrite(onboard_led, HIGH);
    /*
  
    if (digitalRead(fencer1_b) == HIGH) {
      if(debug) {Serial.println('No Ground');}
      digitalWrite(fencer1_touch, HIGH);
    } else {
      digitalWrite(fencer1_touch, LOW);
    }
    if (digitalRead(fencer2_c) == LOW) {
      if(debug) {Serial.println('***** GROUNDED!!!!');}
      digitalWrite(onboard_led, HIGH);
    } else {
      digitalWrite(onboard_led, LOW);
    }
    */
  } 
  else {
    if (debug) {Serial.println('No Press');}
    // Clear any lights that have been lit
    digitalWrite(fencer1_touch, LOW);
    digitalWrite(onboard_led, LOW);
  }
}
