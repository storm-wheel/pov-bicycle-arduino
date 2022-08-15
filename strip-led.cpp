#include "pov-bicycle-arduino.h"

Adafruit_NeoPixel strips[NUMBER_OF_STRIPS] = {
  Adafruit_NeoPixel(NUMBER_OF_PIXELS, STRIP_0_PIN, NEO_GRB + NEO_KHZ800),
  Adafruit_NeoPixel(NUMBER_OF_PIXELS, STRIP_1_PIN, NEO_GRB + NEO_KHZ800),
};

static bool hallSensor = false;

static void printLEDStrip(Adafruit_NeoPixel *strip, int piece);

void setupLEDStrips() {
  for (int i = 0; i < NUMBER_OF_STRIPS; i++) {
    strips[i].begin();
    strips[i].clear();
  }
}

void printLEDStrips() {
  uint8_t pieces[NUMBER_OF_STRIPS];

  pieces[0] = (getTimegap() * NUMBER_OF_PIECES / getPeriod()) % NUMBER_OF_PIECES;
  for (int i = 1; i < NUMBER_OF_STRIPS; i++) {
    pieces[i] = (pieces[i - 1] + NUMBER_OF_PIECES * i / NUMBER_OF_STRIPS) % NUMBER_OF_PIECES;
  }
  for (int i = 0; i < NUMBER_OF_STRIPS; i++) {
    printLEDStrip(strips + i, pieces[i]);
  }
}

static void printLEDStrip(Adafruit_NeoPixel *strip, int piece) {
  uint8_t pieceImage[NUMBER_OF_PIXELS * 3];

  SerialFlash.read(piece * NUMBER_OF_PIXELS * 3, pieceImage, NUMBER_OF_PIXELS * 3);
  for (int i = 0; i < NUMBER_OF_PIXELS; i++) {
    uint8_t red = pieceImage[i * 3 + 0];
    uint8_t green = pieceImage[i * 3 + 1];
    uint8_t blue = pieceImage[i * 3 + 2];
    uint32_t color = strip->Color(red, green, blue);
    strip->setPixelColor(i, color);
  }
  strip->show();
}
