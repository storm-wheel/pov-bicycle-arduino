#include "pov-bicycle-arduino.h"

static bool lastHallSensor;
static uint32_t lastTimestamp;
static uint32_t currentTimestamp;

static uint32_t period;

static void initializePeriod();
static bool readHallSensor();

void setupHallSensor() {
  lastHallSensor = false;
  initializePeriod();
}

uint32_t getTimegap() {
  return millis() - currentTimestamp;
}

uint32_t getPeriod() {
  return period;
}

static void initializePeriod() {
  while (readHallSensor() == false);
  lastTimestamp = millis();
  while (readHallSensor() == true);
  while (readHallSensor() == false);
  currentTimestamp = millis();
  period = currentTimestamp - lastTimestamp;
}

static void updatePeriod() {
  bool currentHallSensor = readHallSensor();

  if (lastHallSensor != currentHallSensor) {
    lastHallSensor = currentHallSensor;
    if (currentHallSensor == true) {
      lastTimestamp = currentTimestamp;
      currentTimestamp = millis();
      period = currentTimestamp - lastTimestamp;
    }
  }
}

static bool readHallSensor() {
  return !digitalRead(HALL_OUTPUT_PIN);
}