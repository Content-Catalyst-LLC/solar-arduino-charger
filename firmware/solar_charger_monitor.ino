/*
  Solar Powered Arduino Charger Monitor
  -------------------------------------
  Features:
  - Reads battery voltage through a voltage divider
  - Averages multiple samples for more stable readings
  - Reports battery state: FULL, NORMAL, LOW, CRITICAL
  - Optional LED status indicators
  - Serial output for diagnostics

  Assumptions:
  - Arduino reference voltage is 5.0V
  - Voltage divider ratio is 2.0 (example: 100k + 100k)
  - Single Li-ion battery nominal range: ~3.2V to ~4.2V
*/

const int batteryPin = A0;

// Optional LED pins
const int ledFullPin = 4;
const int ledNormalPin = 5;
const int ledLowPin = 6;
const int ledCriticalPin = 7;

// Voltage calibration
const float referenceVoltage = 5.0;
const float voltageDividerRatio = 2.0;

// Battery thresholds for one Li-ion cell
const float batteryFull = 4.15;
const float batteryNormalMin = 3.70;
const float batteryLow = 3.40;
const float batteryCritical = 3.20;

// Number of samples for averaging
const int sampleCount = 20;

float readBatteryVoltage() {
  long total = 0;

  for (int i = 0; i < sampleCount; i++) {
    total += analogRead(batteryPin);
    delay(10);
  }

  float averageRaw = total / (float)sampleCount;
  float measuredVoltage = averageRaw * (referenceVoltage / 1023.0);
  float batteryVoltage = measuredVoltage * voltageDividerRatio;

  return batteryVoltage;
}

void clearLeds() {
  digitalWrite(ledFullPin, LOW);
  digitalWrite(ledNormalPin, LOW);
  digitalWrite(ledLowPin, LOW);
  digitalWrite(ledCriticalPin, LOW);
}

void setBatteryStatusLeds(float voltage) {
  clearLeds();

  if (voltage >= batteryFull) {
    digitalWrite(ledFullPin, HIGH);
  } else if (voltage >= batteryNormalMin) {
    digitalWrite(ledNormalPin, HIGH);
  } else if (voltage >= batteryLow) {
    digitalWrite(ledLowPin, HIGH);
  } else {
    digitalWrite(ledCriticalPin, HIGH);
  }
}

const char* batteryStatusLabel(float voltage) {
  if (voltage >= batteryFull) {
    return "FULL";
  } else if (voltage >= batteryNormalMin) {
    return "NORMAL";
  } else if (voltage >= batteryLow) {
    return "LOW";
  } else {
    return "CRITICAL";
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(ledFullPin, OUTPUT);
  pinMode(ledNormalPin, OUTPUT);
  pinMode(ledLowPin, OUTPUT);
  pinMode(ledCriticalPin, OUTPUT);

  clearLeds();

  Serial.println("Solar Powered Arduino Charger Monitor");
  Serial.println("------------------------------------");
  Serial.println("Reading battery voltage...");
}

void loop() {
  float batteryVoltage = readBatteryVoltage();
  const char* status = batteryStatusLabel(batteryVoltage);

  setBatteryStatusLeds(batteryVoltage);

  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage, 2);
  Serial.print(" V | Status: ");
  Serial.println(status);

  if (batteryVoltage >= batteryFull) {
    Serial.println("Battery is near full charge.");
  } else if (batteryVoltage >= batteryNormalMin) {
    Serial.println("Battery is in a healthy operating range.");
  } else if (batteryVoltage >= batteryLow) {
    Serial.println("Battery is getting low. Charging recommended.");
  } else {
    Serial.println("Battery is critical. Reduce load and recharge immediately.");
  }

  Serial.println();
  delay(5000);
}
