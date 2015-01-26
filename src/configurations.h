
const float light_length = 2;             // Length light should show (in seconds)
const float buzzer_length = 0.5;          // Length buzzer should sound (in seconds) ** Must be less than light_length
const int debounce = 0;                   // Length of delay after grounded hit

bool mute = false;                        // Mute the buzzer

// Epee Timing
const int epee_timeout_duration = 40;     // Stop registering touches after x milliseconds
float touch_time = 0;                     // Time of the last touch in milliseconds
