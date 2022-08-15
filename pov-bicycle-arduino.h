#ifndef POV_BICYCLE_ARDUINO_H
#define POV_BICYCLE_ARDUINO_H

#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>
#include <SerialFlash.h>
#include <SPI.h>

#define NUMBER_OF_PIECES 30
#define NUMBER_OF_PIXELS 40
#define NUMBER_OF_STRIPS 2
#define STRIP_0_PIN 7
#define STRIP_1_PIN 8
#define EEPROM_CS_PIN 10
#define HALL_OUTPUT_PIN 13

void setupBuiltinLED();
void indicateProcessing();
void indicateError();
void flipLED();
void turnOnLED();
void turnOffLED();

void setupLEDStrips();
void printLEDStrips();

void setupSerialFlash();
void checkSerialFlashCapacity(int capacity);
void eraseSerialFlash();

void downloadImageFromSerial();

void setupHallSensor();
void updatePeriod();
uint32_t getTimegap();
uint32_t getPeriod();

#endif