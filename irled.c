#define IR_LED_PIN  25    // IR LED output
#define PHOTO_PIN   34    // Photodiode input (analog)
#define LED_PIN     2     // Indicator LED (optional)

#define THRESHOLD   2000  // Adjust based on your environment

void setup() {
    Serial.begin(115200);
    
    pinMode(IR_LED_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    
    digitalWrite(IR_LED_PIN, LOW); // Initially off
}

void loop() {
    // Turn on IR LED
    digitalWrite(IR_LED_PIN, HIGH);
    delay(10);  // Short delay to allow IR reflection
    
    // Read photodiode value
    int sensorValue = analogRead(PHOTO_PIN);
    Serial.print("IR Sensor Value: ");
    Serial.println(sensorValue);
    
    // Check for wall detection
    if (sensorValue > THRESHOLD) {
        Serial.println("⚠️ Wall detected!");
        digitalWrite(LED_PIN, HIGH);  // Turn on indicator LED
    } else {
        Serial.println("✅ No obstacle.");
        digitalWrite(LED_PIN, LOW);
    }

    // Turn off IR LED to save power
    digitalWrite(IR_LED_PIN, LOW);
    
    delay(500); // Wait before next reading
}
