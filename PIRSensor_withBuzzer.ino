#define PIR_PIN 2 // Replace with the actual pin number of your PIR sensor
#define BUZZER_PIN 3 // Replace with the actual pin number of your buzzer

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int sensorVal = digitalRead(PIR_PIN);

  if (sensorVal == HIGH) {
    // Movement detected
    digitalWrite(BUZZER_PIN, HIGH); // Sound the buzzer

    // Get current timestamp
    unsigned long timestamp = millis();

    // Convert timestamp to human-readable format
    String timeString = String(timestamp / 1000); // Convert to seconds

    // Log the timestamp to the Serial Monitor
    Serial.println("Movement detected at: " + timeString + " seconds");
  } else {
    digitalWrite(BUZZER_PIN, LOW); // Stop the buzzer
  }

  delay(100); // Adjust the delay as needed
}
