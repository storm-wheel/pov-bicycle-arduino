#include "pov-bicycle-arduino.h"

static void writeSize();
static void readImage();

void downloadImageFromSerial() {
  if (Serial == false) {
    indicateError();
  }
  
  checkSerialFlashCapacity(NUMBER_OF_PIECES * NUMBER_OF_PIXELS * 3);
  eraseSerialFlash();
  writeSize();
  readImage();
}

static void writeSize() {
  Serial.print(NUMBER_OF_PIECES);
  Serial.print(' ');
  Serial.print(NUMBER_OF_PIXELS);
  Serial.print('\n');
}

static void readImage() {
  for (int piece = 0; piece < NUMBER_OF_PIECES; piece++) {
    for (int pixel = 0; pixel < NUMBER_OF_PIXELS; pixel++) {
      uint8_t colors[3];

      colors[0] = Serial.parseInt();
      colors[1] = Serial.parseInt();
      colors[2] = Serial.parseInt();
      SerialFlash.write((piece * NUMBER_OF_PIXELS + pixel) * 3, colors, 3);
    }
    flipLED();
  }
  turnOffLED();
}