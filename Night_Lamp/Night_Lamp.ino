// Define the pin connected to the sensor and RGB LED pins
#define SENSOR_PIN 13
#define RED_LED_PIN 12
#define GREEN_LED_PIN 14
#define BLUE_LED_PIN 27

// Variable to keep track of the previous sensor state
int previousSensorValue = HIGH;
// Variable to keep track of the current LED color
int currentLEDState = 0; // 0: Red, 1: Green, 2: Blue

void setup() {

  // Set the sensor pin as an input
  pinMode(SENSOR_PIN, INPUT);
  
  // Set RGB LED pins as outputs
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  
  // Initially turn off all the RGB LEDs
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(BLUE_LED_PIN, LOW);
}

void loop() {
  // Read the current sensor value
  int currentSensorValue = digitalRead(SENSOR_PIN);
  
  // Check if there was a change from high to low
  if (previousSensorValue == HIGH && currentSensorValue == LOW) {
    // Cycle through the LED colors
    if (currentLEDState == 0) {
      // Turn on red LED
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, LOW);
    } else if (currentLEDState == 1) {
      // Turn on green LED
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(BLUE_LED_PIN, LOW);
    } else if (currentLEDState == 2) {
      // Turn on blue LED
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, HIGH);
    }
    
    // Update the LED state
    currentLEDState = (currentLEDState + 1) % 3; // Cycle through 0, 1, 2
  }
  
  // Update the previous sensor value
  previousSensorValue = currentSensorValue;
  
  // Small delay to avoid rapid changes
  delay(50);
}
