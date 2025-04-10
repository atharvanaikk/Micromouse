// Light sensor pin assignments
const int SENSOR_one = 32;
const int SENSOR_two = 35;
const int SENSOR_three = 34;
const int SENSOR_four = 39;
const int SENSOR_five = 36;

// Threshold for detecting wall presence (calibrate this)
const int WALL_THRESHOLD = 1500;

void setup() {
  Serial.begin(115200);
  // No pinMode needed for analogRead on ESP32
}

void loop() {
  // Read sensor values
  int valLeft = analogRead(SENSOR_one);
  int valFrontLeft = analogRead(SENSOR_two);
  int valCenter = analogRead(SENSOR_three);
  int valFrontRight = analogRead(SENSOR_four);
  int valRight = analogRead(SENSOR_five);

  // Wall detection logic
  bool wallLeft = valLeft > WALL_THRESHOLD;
  bool wallFrontLeft = valFrontLeft > WALL_THRESHOLD;
  bool wallFront = valCenter > WALL_THRESHOLD;
  bool wallFrontRight = valFrontRight > WALL_THRESHOLD;
  bool wallRight = valRight > WALL_THRESHOLD;

  // Print sensor readings (for debugging)
  Serial.print("L: "); Serial.print(valLeft);
  Serial.print(" FL: "); Serial.print(valFrontLeft);
  Serial.print(" C: "); Serial.print(valCenter);
  Serial.print(" FR: "); Serial.print(valFrontRight);
  Serial.print(" R: "); Serial.println(valRight);

  // Print wall detection status
  Serial.print("Wall Left: "); Serial.println(wallLeft ? "YES" : "NO");
  Serial.print("Wall Front-Left: "); Serial.println(wallFrontLeft ? "YES" : "NO");
  Serial.print("Wall Front: "); Serial.println(wallFront ? "YES" : "NO");
  Serial.print("Wall Front-Right: "); Serial.println(wallFrontRight ? "YES" : "NO");
  Serial.print("Wall Right: "); Serial.println(wallRight ? "YES" : "NO");

  delay(300); // Adjust refresh rate
}