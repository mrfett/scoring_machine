
// Length light should show (in milliseconds)
const float light_length = 4000;
// Length buzzer should sound (in milliseconds) ** Must be less than light_length
const float buzzer_length = 1000;

// Mute the buzzer
bool mute = false;

// When current is split 3 ways (weapon A + weapon B + ground)
const int threshold_low = 125;
// When current is split 2 ways (weapon A + weapon B)
const int threshold_medium = 270;
// When current is not split (weapon A)
const int threshold_high = 400;

// Epee Timing
// Stop registering touches after x milliseconds
const int epee_timeout_duration = 40;
