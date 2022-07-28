#ifndef SOIL_SENSOR_H
#define SOIL_SENSOR_H

class SoilSensor
{
private:
    int dataPin;
    int airVal;
    int waterVal;
    int soilMoistureVal;
    int soilMoisturePercent;
public:
    SoilSensor(int dp, int av, int wv): dataPin(dp), airVal(av), waterVal(wv), soilMoistureVal(0), soilMoisturePercent(0) {};
    ~SoilSensor() {};
    int GetMoistureReading();
    int GetMoisturePercent();
};

#endif
