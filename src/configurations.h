
const float light_length = 2;             // Length light should show (in seconds)
const float buzzer_length = 0.5;          // Length buzzer should sound (in seconds) ** Must be less than light_length
const int debounce = 0;                   // Length of delay after grounded hit

bool mute = true;                        // Mute the buzzer

const int threshold_low = 121;                // When current is split 3 ways (weapon A + weapon B + ground)
const int threshold_medium = 317;             // When current is split 2 ways (weapon A + weapon B)
const int threshold_high = 706;               // When current is not split (weapon A)

// Epee Timing
const int epee_timeout_duration = 40;     // Stop registering touches after x milliseconds
float touch_time = 0;                     // Time of the last touch in milliseconds
