#include "pov-bicycle-arduino.h"

static bool on;

void setupBuiltinLED() {
  pinMode(LED_PIN, OUTPUT);
  turnOffLED();
}

void indicateProcessing() {
  turnOnLED();
  delay(250);
  turnOffLED();
  delay(750);
}

void indicateError() {
  while (true) {
    turnOnLED();
    delay(100);
    turnOffLED();
    delay(100);
  }
}

void flipLED() {
  on ? turnOnLED() : turnOffLED();
}

void turnOnLED() {
  on = true;
  digitalWrite(LED_PIN, HIGH);
}

void turnOffLED() {
  on = false;
  digitalWrite(LED_PIN, LOW);
}