#include "SoilSensor.h"
#include "Arduino.h"

int SoilSensor::GetMoistureReading() {
    soilMoistureVal = analogRead(dataPin);
    return soilMoistureVal;
}

int SoilSensor::GetMoisturePercent() {
    soilMoisturePercent = map(soilMoistureVal, airVal, waterVal, 0, 100);
    return soilMoisturePercent;
}
