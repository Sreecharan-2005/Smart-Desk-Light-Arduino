const int ldrPin = A0;
const int buttonPin = 2;
const int potPin = A1;
const int ledPin = 9;

bool manualMode = false;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long lastPrintTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  int potValue = analogRead(potPin);
  int buttonState = digitalRead(buttonPin);

  // Debounce logic
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
    lastButtonState = buttonState;
  }

  if ((millis() - lastDebounceTime) > 50 && buttonState == HIGH) {
    manualMode = !manualMode;
  }

  int brightness;
  if (manualMode) {
    brightness = map(potValue, 0, 1023, 0, 255);
  } else {
    brightness = map(ldrValue, 1023, 0, 0, 255); // dark → bright LED
  }

  analogWrite(ledPin, brightness);

  // Print data every 1 second
  if (millis() - lastPrintTime >= 1000) {
    Serial.print("LDR: "); Serial.print(ldrValue);
    Serial.print(" | Mode: "); Serial.print(manualMode ? "Manual" : "Auto");
    Serial.print(" | Brightness: "); Serial.println(brightness);
    lastPrintTime = millis();
  }
}

