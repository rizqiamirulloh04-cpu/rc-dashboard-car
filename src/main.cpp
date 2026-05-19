#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("RC Dashboard Boot");
}

void loop() {
    Serial.println("Dashboard Running");
    delay(1000);
}