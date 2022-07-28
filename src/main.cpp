#include <Arduino.h>
#include "SoilSensor.h"

const int moistureDataPin = 0;
const int AMBIENT_MOISTURE_LEVEL = 547; // device's reference for zero moisture 
const int WATER_MOISTURE_LEVEL = 214; // device's reference for full moisture
int moistureSensorReading = 0;
int soilMoisturePercent = 0;

SoilSensor soilSensor(moistureDataPin, AMBIENT_MOISTURE_LEVEL, WATER_MOISTURE_LEVEL);

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {

  moistureSensorReading = soilSensor.GetMoistureReading();
  soilMoisturePercent = soilSensor.GetMoisturePercent();

  if (soilMoisturePercent >= 100) {
    soilMoisturePercent = 100;
  }
  else if (soilMoisturePercent <= 0)
  {
    soilMoisturePercent = 0;
  }

  Serial.print("Soil Moisture Level: ");
  Serial.print(moistureSensorReading);
  Serial.print(" Saturation Percent: ");
  Serial.print(soilMoisturePercent);
  Serial.println("%");
}
