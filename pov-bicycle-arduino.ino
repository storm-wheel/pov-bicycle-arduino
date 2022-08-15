#include "pov-bicycle-arduino.h"

void downloadImageFromSerial();

void setup() {
  Serial.begin(57600);

  setupBuiltinLED();
  if (Serial) {
    setupSerialFlash();
    downloadImageFromSerial();
    indicateError();
    return ;
  }
  setupLEDStrips();
  setupHallSensor();
}

void loop() {
  updatePeriod();
  printLEDStrips();
}