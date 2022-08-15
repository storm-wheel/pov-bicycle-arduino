#include "pov-bicycle-arduino.h"

static uint8_t eepromId[5];

void setupSerialFlash() {
  if (SerialFlash.begin(EEPROM_CS_PIN) == false) {
    indicateError();
  }
  SerialFlash.readID(eepromId);
}

void checkSerialFlashCapacity(int capacity) {
  uint32_t eepromSize;

  eepromSize = SerialFlash.capacity(eepromId);
  if (capacity > eepromSize) {
    indicateError();
  }
}

void eraseSerialFlash() {
  SerialFlash.eraseAll();
  while (SerialFlash.ready() == false) {
    indicateProcessing();
  }
}