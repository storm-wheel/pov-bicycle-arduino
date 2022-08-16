#include "pov-bicycle-arduino.h"

static uint8_t eepromId[5];

void setupSerialFlash() {
  SPI.setMOSI(EEPROM_COPI_PIN);  // uncomment these if using the alternate pins
  SPI.setMISO(EEPROM_CIPO_PIN);
  SPI.setSCK(EEPROM_SCK_PIN);
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
